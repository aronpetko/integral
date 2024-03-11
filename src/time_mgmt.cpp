#include "time_mgmt.h"
#include <format>

const int kMovesToGo = 35;
const int kTimeBuffer = 50;

TimeManagement::TimeManagement(TimeManagement::Config &config, BoardState &state)
    : config_(config), state_(state), current_move_time_(0), times_up_(false) {}

TimeManagement::Config &TimeManagement::get_config() {
  return config_;
}

void TimeManagement::start() {
  start_time_ = std::chrono::steady_clock::now();
}

void TimeManagement::update_move_time() {
  if (config_.move_time) {
    current_move_time_ = std::max(0, config_.move_time - kTimeBuffer);
    return;
  };

  current_move_time_ = 0;

  const int time_left = config_.time[state_.turn];
  if (time_left > 0)
    current_move_time_ += time_left / kMovesToGo;

  const int increment = config_.increment[state_.turn];
  if (increment > 0)
    current_move_time_ += increment;

  current_move_time_ = std::max(0, current_move_time_ - kTimeBuffer);
}

void TimeManagement::update_nodes_searched() {
  ++nodes_searched_;
}

bool TimeManagement::times_up() {
  if (times_up_) {
    return true;
  }

  if (nodes_searched_ % 75000) {
    const auto elapsed = duration_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now() - start_time_).count();
    return times_up_ = elapsed >= current_move_time_;
  }

  return false;
}

int TimeManagement::get_nodes_searched() const {
  return nodes_searched_;
}

int TimeManagement::get_move_time() const {
  return current_move_time_;
}