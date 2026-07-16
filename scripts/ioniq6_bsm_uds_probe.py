#!/usr/bin/env python3
"""
Ioniq 6 ADAS-DRV BSM/SCC message-class probe.

GOAL: find a CommunicationControl (UDS 0x28) variant that silences the ADAS DRV
ECU's SCC actuation (0x1A0) so openpilot long can take over, while LEAVING the
rear-radar BSM verdict (0x1BA, BLINDSPOTS_REAR_CORNERS) still transmitting — which
would give us OEM-grade, from-behind, lane-filtered blind-spot monitoring for free.

Background (from on-car UDS work, not LLM guesswork):
  - ADAS DRV ECU phys addr 0x730 on ECAN (bus 1), rx resp 0x738. Ioniq 6 is
    LKA-steering so ECAN = bus 1 (confirmed: hyundaicanfd.CanBus, disable_ecu path).
  - Today's disable sends 0x28 with message-type NORMAL (0x01), which takes down
    ALL normal-class TX at once: SCC 0x1A0 *and* BSM 0x1BA together.
  - The ECU rejects with 7F 28 22 (conditionsNotCorrect), NOT 7F 27 -> it's a
    STATE/SEQUENCE gate, not a SecurityAccess key. So this must run in IGN-ON,
    engine OFF, BEFORE the car enters READY (same precondition as the working
    disable). See Disable-ECU notes.

WHAT THIS DOES (read-mostly, reversible):
  For each candidate CommunicationControl (control-type x message-type) combo:
    1. Snapshot which of {0x1A0, 0x1BA} are live on the bus (baseline).
    2. Enter extended diagnostic session (10 03).
    3. Send the CommunicationControl combo, log the raw response.
    4. Sample the bus ~2 s; report whether 0x1A0 and 0x1BA are still transmitting.
    5. RESTORE: send ENABLE_RX_ENABLE_TX so nothing stays disabled between combos.
  The winning combo is one where 0x1A0 stops but 0x1BA keeps flowing.

SAFETY / PRECONDITIONS:
  * Car in IGN-ON (start button, NO brake), engine off, PARKED. Do not drive.
  * Stop openpilot first so it doesn't fight for the panda:  (on device)
        tmux kill-session -t comma   ||  sudo systemctl stop comma  ||  pkill -f manager
  * This talks straight to the panda; on exit it restores the ECU and sets the
    panda back to SILENT so it won't transmit on its own.
  * It DOES momentarily disable SCC/AEB during each combo. Engine off + parked =
    no motion risk. Everything is re-enabled after each step and on exit.

USAGE (on the comma device over SSH):
    cd /data/openpilot && python scripts/ioniq6_bsm_uds_probe.py
Logs to stdout and to /data/ioniq6_bsm_uds_probe.log
"""
import os
import sys
import time
import datetime

# ---- config ---------------------------------------------------------------
ECAN_BUS = 1              # Ioniq 6 (LKA steering) ECAN
DRV_TX = 0x730           # ADAS DRV physical request addr
DRV_RX = 0x738           # response addr (tx + 8)
SCC_ADDR = 0x1A0         # SCC actuation the CCU consumes (must go silent for OP long)
BSM_ADDR = 0x1BA         # BLINDSPOTS_REAR_CORNERS (the OEM rear BSM we want to keep)
FRONT_BSM_ADDR = 0x36A   # front-corner side-detect, for reference
SAMPLE_S = 2.0           # bus sample window after each command
LOGFILE = "/data/ioniq6_bsm_uds_probe.log"

# UDS bytes
EXT_DIAG = bytes([0x10, 0x03])
COMM_CONTROL = 0x28
# control types (ISO 14229 §CommunicationControl subfunction)
CT_ENABLE_RX_ENABLE_TX = 0x00
CT_ENABLE_RX_DISABLE_TX = 0x01
CT_DISABLE_RX_ENABLE_TX = 0x02
CT_DISABLE_RX_DISABLE_TX = 0x03
# message types (communicationType byte, bit0=normal, bit1=network-management)
MT_NORMAL = 0x01
MT_NM = 0x02
MT_NM_AND_NORMAL = 0x03

# Combos to sweep. Each: (label, control_type, message_type).
# The interesting hypothesis is that BSM (0x1BA) rides a different class than SCC,
# so disabling only NORMAL tx (what we do today) vs NM vs both changes what dies.
COMBOS = [
    ("disable TX, NORMAL      (current)", CT_ENABLE_RX_DISABLE_TX, MT_NORMAL),
    ("disable TX, NM only",               CT_ENABLE_RX_DISABLE_TX, MT_NM),
    ("disable TX, NM+NORMAL",             CT_ENABLE_RX_DISABLE_TX, MT_NM_AND_NORMAL),
    ("disable RX+TX, NORMAL",             CT_DISABLE_RX_DISABLE_TX, MT_NORMAL),
    ("disable RX+TX, NM only",            CT_DISABLE_RX_DISABLE_TX, MT_NM),
]


def log(msg):
    line = f"[{datetime.datetime.now().strftime('%H:%M:%S.%f')[:-3]}] {msg}"
    print(line, flush=True)
    try:
        with open(LOGFILE, "a") as f:
            f.write(line + "\n")
    except Exception:
        pass


def isotp_single_frame(payload: bytes) -> bytes:
    """Build a classic ISO-TP single frame (fits all our short requests).
    MUST be exactly 8 bytes: the panda's ELM327 tx hook rejects any diagnostic
    frame where len != 8 (opendbc/safety/modes/elm327.h), so all requests are
    padded to 8. All our UDS requests are <= 3 bytes, so a single frame is enough
    and no multi-frame/flow-control handling is needed."""
    assert len(payload) <= 7, "request too long for a single frame"
    return bytes([len(payload)]) + payload + b"\x00" * (7 - len(payload))


def parse_isotp_response(dat: bytes) -> bytes:
    """Strip the ISO-TP single-frame length byte; return the UDS payload."""
    if not dat:
        return b""
    n = dat[0] & 0x0F
    return bytes(dat[1:1 + n])


def sample_bus(panda, want_addrs, duration):
    """Sample the bus for `duration` s; return set of addrs seen on ECAN and a
    per-addr frame count."""
    seen = {a: 0 for a in want_addrs}
    panda.can_clear(0xFFFF)
    t_end = time.monotonic() + duration
    while time.monotonic() < t_end:
        for addr, dat, src in panda.can_recv():
            if src == ECAN_BUS and addr in seen:
                seen[addr] += 1
    return seen


def send_uds(panda, payload, wait=0.3):
    """Send one UDS request as an ISO-TP single frame on ECAN, wait for a response
    from DRV_RX. Returns the decoded UDS payload bytes (b'' if none)."""
    panda.can_clear(0xFFFF)
    frame = isotp_single_frame(payload)
    # ECAN is CAN-FD; send as FD frame
    panda.can_send(DRV_TX, frame, ECAN_BUS, fd=True)
    t_end = time.monotonic() + wait
    while time.monotonic() < t_end:
        for addr, dat, src in panda.can_recv():
            if src == ECAN_BUS and addr == DRV_RX:
                return parse_isotp_response(bytes(dat))
    return b""


def describe_resp(resp: bytes) -> str:
    if not resp:
        return "no response"
    if resp[0] == 0x7F and len(resp) >= 3:
        nrc = resp[2]
        names = {0x12: "subFunctionNotSupported", 0x13: "invalidFormat",
                 0x22: "conditionsNotCorrect (need IGN-ON, not READY)",
                 0x31: "requestOutOfRange", 0x33: "securityAccessDenied"}
        return f"NEGATIVE 7F {resp[1]:02X} {nrc:02X} = {names.get(nrc, 'unknown')}"
    if resp[0] == 0x68:
        return f"POSITIVE 68 {resp[1]:02X} (CommunicationControl accepted)"
    if resp[0] == 0x50:
        return f"POSITIVE 50 {resp[1]:02X} (diag session)"
    return "0x" + resp.hex()


def enter_session(panda) -> bool:
    resp = send_uds(panda, EXT_DIAG)
    log(f"  diag session (10 03) -> {describe_resp(resp)}")
    return bool(resp) and resp[0] == 0x50


def comm_control(panda, control_type, message_type):
    return send_uds(panda, bytes([COMM_CONTROL, control_type, message_type]))


def restore(panda):
    """Best-effort: re-enable all comms on the DRV ECU."""
    enter_session(panda)
    resp = comm_control(panda, CT_ENABLE_RX_ENABLE_TX, MT_NM_AND_NORMAL)
    log(f"  RESTORE enable rx+tx -> {describe_resp(resp)}")


def main():
    try:
        from panda import Panda
    except ImportError:
        # device path
        sys.path.insert(0, "/data/openpilot")
        from panda import Panda
    from opendbc.car.structs import CarParams

    SAFETY_ELM327 = int(CarParams.SafetyModel.elm327)  # 3
    SAFETY_SILENT = int(CarParams.SafetyModel.silent)  # 0

    log("=" * 70)
    log("Ioniq 6 BSM/SCC message-class probe starting")
    log("PRECONDITION: IGN-ON, engine OFF, parked, openpilot stopped.")
    log("=" * 70)

    panda = Panda()
    # ELM327 with param=1 is exactly the mode openpilot uses for fingerprint/UDS
    # diagnostic traffic (see selfdrive/pandad/panda_safety.cc). It permits our
    # diagnostic tx on the requested bus without letting the panda emit car control.
    panda.set_safety_mode(SAFETY_ELM327, 1)
    log(f"panda connected: {panda.get_serial()[0]}, safety=ELM327")

    # tester-present keepalive is not needed for the short window per combo; each
    # combo re-enters the session fresh.
    results = []
    try:
        base = sample_bus(panda, [SCC_ADDR, BSM_ADDR, FRONT_BSM_ADDR], SAMPLE_S)
        log(f"BASELINE (nothing disabled): SCC 0x1A0={base[SCC_ADDR]}  "
            f"BSM 0x1BA={base[BSM_ADDR]}  frontSD 0x36A={base[FRONT_BSM_ADDR]} frames/{SAMPLE_S:.0f}s")
        if base[SCC_ADDR] == 0 and base[BSM_ADDR] == 0:
            log("WARNING: neither SCC nor BSM seen at baseline. Wrong bus, or car not "
                "in IGN-ON, or openpilot still running and already disabled the ECU.")

        for label, ct, mt in COMBOS:
            log("-" * 70)
            log(f"COMBO: {label}   (0x28 {ct:02X} {mt:02X})")
            if not enter_session(panda):
                log("  could not enter diag session; skipping combo")
                restore(panda)
                continue
            time.sleep(0.05)
            resp = comm_control(panda, ct, mt)
            log(f"  comm control -> {describe_resp(resp)}")
            after = sample_bus(panda, [SCC_ADDR, BSM_ADDR, FRONT_BSM_ADDR], SAMPLE_S)
            scc_off = after[SCC_ADDR] == 0
            bsm_on = after[BSM_ADDR] > 0
            verdict = "*** WINNER: SCC off, BSM alive ***" if (scc_off and bsm_on) else (
                "SCC off, BSM also off" if scc_off else "SCC still transmitting")
            log(f"  AFTER: SCC 0x1A0={after[SCC_ADDR]}  BSM 0x1BA={after[BSM_ADDR]}  "
                f"frontSD 0x36A={after[FRONT_BSM_ADDR]}   -> {verdict}")
            results.append((label, ct, mt, after[SCC_ADDR], after[BSM_ADDR], scc_off and bsm_on))
            restore(panda)
            time.sleep(0.3)

        log("=" * 70)
        log("SUMMARY")
        for label, ct, mt, scc, bsm, win in results:
            flag = "WIN" if win else "   "
            log(f"  {flag}  {label:34s} 0x28 {ct:02X} {mt:02X}  ->  SCC={scc:4d}  BSM={bsm:4d}")
        winners = [r for r in results if r[5]]
        if winners:
            log("A winning combo exists: set the disable message-type to it in interface.py "
                "and 0x1BA (real rear BSM) will keep flowing with OP long.")
        else:
            log("No combo kept BSM alive while killing SCC. SCC and BSM share a class on this "
                "ECU -> OEM rear BSM via UDS is not separable; hardware rear-radar tap is the "
                "remaining path.")
    finally:
        restore(panda)
        panda.set_safety_mode(SAFETY_SILENT)
        log("panda set back to SILENT. Probe done. Reboot the car ign to fully reset the ECU.")


if __name__ == "__main__":
    main()
