# Ioniq 6 OEM rear-BSM probe

Finds whether we can keep the OEM rear blind-spot verdict (`0x1BA`,
`BLINDSPOTS_REAR_CORNERS`) alive while still silencing SCC (`0x1A0`) so openpilot
long takes over. If yes → from-behind, lane-filtered OEM BSM comes back for free
with a one-byte change to the ECU-disable command.

## What it does
Sweeps UDS CommunicationControl (`0x28`) control-type × message-type combos on the
ADAS DRV ECU (`0x730`, ECAN/bus 1). For each combo it samples the bus and reports
whether `0x1A0` (SCC) stopped and `0x1BA` (BSM) kept transmitting. Restores the ECU
after every combo and on exit.

## Preconditions (important)
1. Car in **IGN-ON, engine OFF, parked** (start button, NO brake). Same state that
   makes the normal ECU-disable succeed. Do **not** drive.
2. **Stop openpilot first** so it doesn't fight for the panda:
   ```
   sudo systemctl stop comma    # or: tmux kill-session -t comma   # or: pkill -f manager
   ```
3. The probe momentarily disables SCC/AEB per combo — safe because engine is off &
   parked, and it re-enables after each step.

## Run
```
cd /data/openpilot
python scripts/ioniq6_bsm_uds_probe.py
```
Watch the console and `/data/ioniq6_bsm_uds_probe.log`.

## Reading the result
- `*** WINNER: SCC off, BSM alive ***` on any combo → tell me which `0x28 CT MT`
  bytes won; we set the ECU-disable `communication_control` in
  `opendbc/car/hyundai/interface.py` to that message-type, and `0x1BA` (real rear
  BSM) will keep flowing under OP long.
- No winner → SCC and BSM share a message class on this ECU; UDS can't separate
  them. The remaining path is a hardware tap into the rear-corner-radar CAN branch.

## After running
Cycle the ignition (full off → on) to make sure the ECU is back to a clean state
before a normal drive. The script sets the panda back to SILENT on exit.
