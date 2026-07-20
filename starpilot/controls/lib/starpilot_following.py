#!/usr/bin/env python3
import numpy as np

from cereal import log
from openpilot.common.constants import CV
from openpilot.common.realtime import DT_MDL
from openpilot.selfdrive.controls.lib.lead_behavior import should_disable_far_lead_throttle
from openpilot.selfdrive.controls.lib.longitudinal_mpc_lib.long_mpc import COMFORT_BRAKE, LEAD_DANGER_FACTOR, desired_follow_distance, get_jerk_factor, get_T_FOLLOW

from openpilot.starpilot.common.starpilot_variables import CITY_SPEED_LIMIT, MAX_T_FOLLOW

TRAFFIC_MODE_BP = [0., CITY_SPEED_LIMIT]
PERSONALITY_BP = [45. * CV.MPH_TO_MS, 70. * CV.MPH_TO_MS]

LaneChangeState = log.LaneChangeState
LaneChangeDirection = log.LaneChangeDirection

# Lane-change close-gap transition: while signalling out of the lane, temporarily
# shorten the follow gap so openpilot flows out instead of braking behind a lead
# it is about to leave. Rate-limited in, snaps back out when the safety gate trips.
LANE_CHANGE_MIN_T_FOLLOW = 0.9              # hard floor on the reduced gap (s)
LANE_CHANGE_GAP_RAMP_IN_RATE = 1.2         # factor units per second toward the reduction
LANE_CHANGE_GAP_RAMP_OUT_RATE = 8.0        # factor units per second back to full gap (fast restore)
LANE_CHANGE_ABORT_LEAD_BRAKE = 0.8         # lead decel that aborts the reduction (m/s^2)
LANE_CHANGE_ABORT_CLOSING_SPEED = 2.5      # closing speed that aborts the reduction (m/s)

LANE_CHANGE_ACTIVE_STATES = (
  LaneChangeState.preLaneChange,
  LaneChangeState.laneChangeStarting,
  LaneChangeState.laneChangeFinishing,
)


def get_longitudinal_personality(sm):
  return sm["selfdriveState"].personality

class StarPilotFollowing:
  def __init__(self, StarPilotPlanner):
    self.starpilot_planner = StarPilotPlanner

    self.disable_throttle = False
    self.following_lead = False
    self.slower_lead = False

    self.acceleration_jerk = 0
    self.danger_jerk = 0
    self.desired_follow_distance = 0
    self.speed_jerk = 0
    self.t_follow = 0

    # Rate-limited lane-change close-gap factor (1.0 = full gap, <1.0 = shortened).
    self.lane_change_gap_factor = 1.0

  def update(self, long_control_active, v_ego, sm, starpilot_toggles):
    personality = get_longitudinal_personality(sm)

    if long_control_active and sm["starpilotCarState"].trafficModeEnabled:
      if sm["carState"].aEgo >= 0:
        self.base_acceleration_jerk = np.interp(v_ego, TRAFFIC_MODE_BP, starpilot_toggles.traffic_mode_jerk_acceleration)
        self.base_speed_jerk = np.interp(v_ego, TRAFFIC_MODE_BP, starpilot_toggles.traffic_mode_jerk_speed)
      else:
        self.base_acceleration_jerk = np.interp(v_ego, TRAFFIC_MODE_BP, starpilot_toggles.traffic_mode_jerk_deceleration)
        self.base_speed_jerk = np.interp(v_ego, TRAFFIC_MODE_BP, starpilot_toggles.traffic_mode_jerk_speed_decrease)

      self.base_danger_jerk = np.interp(v_ego, TRAFFIC_MODE_BP, starpilot_toggles.traffic_mode_jerk_danger)
      self.t_follow = np.interp(v_ego, TRAFFIC_MODE_BP, starpilot_toggles.traffic_mode_follow)
    elif long_control_active:
      if sm["carState"].aEgo >= 0:
        self.base_acceleration_jerk, self.base_danger_jerk, self.base_speed_jerk = get_jerk_factor(
          starpilot_toggles.aggressive_jerk_acceleration, starpilot_toggles.aggressive_jerk_danger, starpilot_toggles.aggressive_jerk_speed,
          starpilot_toggles.standard_jerk_acceleration, starpilot_toggles.standard_jerk_danger, starpilot_toggles.standard_jerk_speed,
          starpilot_toggles.relaxed_jerk_acceleration, starpilot_toggles.relaxed_jerk_danger, starpilot_toggles.relaxed_jerk_speed,
          starpilot_toggles.custom_personalities, personality
        )
      else:
        self.base_acceleration_jerk, self.base_danger_jerk, self.base_speed_jerk = get_jerk_factor(
          starpilot_toggles.aggressive_jerk_deceleration, starpilot_toggles.aggressive_jerk_danger, starpilot_toggles.aggressive_jerk_speed_decrease,
          starpilot_toggles.standard_jerk_deceleration, starpilot_toggles.standard_jerk_danger, starpilot_toggles.standard_jerk_speed_decrease,
          starpilot_toggles.relaxed_jerk_deceleration, starpilot_toggles.relaxed_jerk_danger, starpilot_toggles.relaxed_jerk_speed_decrease,
          starpilot_toggles.custom_personalities, personality
        )

      self.t_follow = get_T_FOLLOW(
        starpilot_toggles.aggressive_follow,
        starpilot_toggles.standard_follow,
        starpilot_toggles.relaxed_follow,
        starpilot_toggles.custom_personalities, personality
      )
      if isinstance(self.t_follow, (list, tuple)):
        self.t_follow = float(np.interp(v_ego, PERSONALITY_BP, self.t_follow))
      else:
        self.t_follow = float(self.t_follow)
    else:
      self.base_acceleration_jerk = 0
      self.base_danger_jerk = 0
      self.base_speed_jerk = 0
      self.t_follow = 0

    self.acceleration_jerk = self.base_acceleration_jerk
    self.danger_factor = LEAD_DANGER_FACTOR
    self.danger_jerk = self.base_danger_jerk
    self.speed_jerk = self.base_speed_jerk

    self.following_lead = self.starpilot_planner.tracking_lead and self.starpilot_planner.lead_one.dRel < (self.t_follow * 2) * v_ego
    self.slower_lead = False

    if self.starpilot_planner.starpilot_weather.weather_id != 0:
      self.t_follow = min(self.t_follow + self.starpilot_planner.starpilot_weather.increase_following_distance, MAX_T_FOLLOW)

    self.update_lane_change_gap(long_control_active, v_ego, sm, starpilot_toggles)

    self.disable_throttle = False
    if self.starpilot_planner.tracking_lead and self.starpilot_planner.lead_one.status:
      lead_distance = self.starpilot_planner.lead_one.dRel
      v_lead = self.starpilot_planner.lead_one.vLead
      closing_speed = max(0.0, v_ego - v_lead)
      desired_gap = float(desired_follow_distance(v_ego, v_lead, self.t_follow))
      self.disable_throttle = should_disable_far_lead_throttle(v_ego, lead_distance, desired_gap, closing_speed, self.following_lead)

    if long_control_active and self.starpilot_planner.tracking_lead:
      self.update_follow_values(self.starpilot_planner.lead_one.dRel, v_ego, self.starpilot_planner.lead_one.vLead, starpilot_toggles)
      self.desired_follow_distance = int(desired_follow_distance(v_ego, self.starpilot_planner.lead_one.vLead, self.t_follow))
    else:
      self.desired_follow_distance = 0

  def update_lane_change_gap(self, long_control_active, v_ego, sm, starpilot_toggles):
    # Shorten the follow gap while signalling out of the lane so openpilot flows out
    # smoothly instead of braking behind a lead it is about to leave. The reduction
    # ramps in slowly and snaps back to full gap the instant the safety gate trips.
    target_factor = 1.0

    if long_control_active and getattr(starpilot_toggles, "lane_change_close_gap", False):
      meta = sm["modelV2"].meta
      lane_change_active = meta.laneChangeState in LANE_CHANGE_ACTIVE_STATES
      direction = meta.laneChangeDirection

      if lane_change_active and self.lane_change_gap_safe(v_ego, sm, direction, starpilot_toggles):
        target_factor = float(np.clip(starpilot_toggles.lane_change_close_gap_factor, 0.5, 1.0))

    rate = LANE_CHANGE_GAP_RAMP_IN_RATE if target_factor < self.lane_change_gap_factor else LANE_CHANGE_GAP_RAMP_OUT_RATE
    step = rate * DT_MDL
    self.lane_change_gap_factor = float(np.clip(target_factor,
                                                self.lane_change_gap_factor - step,
                                                self.lane_change_gap_factor + step))

    if long_control_active and self.lane_change_gap_factor < 1.0:
      # Never let the floor push t_follow up (e.g. an already-tight traffic-mode gap):
      # only ever shorten it, clamped to the safety floor.
      reduced = max(LANE_CHANGE_MIN_T_FOLLOW, self.t_follow * self.lane_change_gap_factor)
      self.t_follow = min(self.t_follow, reduced)

  def lane_change_gap_safe(self, v_ego, sm, direction, starpilot_toggles):
    CS = sm["carState"]
    if CS.standstill or v_ego < starpilot_toggles.minimum_lane_change_speed:
      return False

    # Do not close the gap toward an occupied blindspot on the lane-change side.
    if (direction == LaneChangeDirection.left and CS.leftBlindspot) or \
       (direction == LaneChangeDirection.right and CS.rightBlindspot):
      return False

    lead = self.starpilot_planner.lead_one
    if self.starpilot_planner.tracking_lead and lead.status:
      lead_brake = max(0.0, -float(lead.aLeadK))
      closing_speed = max(0.0, v_ego - float(lead.vLead))
      if lead_brake >= LANE_CHANGE_ABORT_LEAD_BRAKE or closing_speed >= LANE_CHANGE_ABORT_CLOSING_SPEED:
        return False

    return True

  def update_follow_values(self, lead_distance, v_ego, v_lead, starpilot_toggles):
    if starpilot_toggles.conditional_slower_lead and v_lead < v_ego:
      distance_factor = max(lead_distance - (v_lead * self.t_follow), 1)
      braking_offset = float(np.clip(min(v_ego - v_lead, v_lead) - COMFORT_BRAKE, 1, distance_factor))
      self.slower_lead = braking_offset > 1
