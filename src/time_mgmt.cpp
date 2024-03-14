#include "time_mgmt.h"
#include <format>

const int kMovesToGo = 24;
const int kTimeBuffer = 50;

TimeManagement::TimeManagement(TimeManagement::Config &config, Board &board)
    : config_(config), board_(board), current_move_time_(0), times_up_(false), nodes_searched_(0) {}

TimeManagement::Config &TimeManagement::get_config() {
  return config_;
}

void TimeManagement::start() {
  start_time_ = std::chrono::steady_clock::now();
}

void TimeManagement::update_move_time() {
  if (config_.move_time) {
    current_move_time_ = config_.move_time;
    return;
  };

  current_move_time_ = 0;
  
  const auto &state = board_.get_state();

  const int moves_played = state.half_moves;
  int expected_moves;

  if (moves_played <= 10) {
    expected_moves = 50;
  } else if (moves_played <= 30) {
    expected_moves = 60;
  } else if (moves_played <= 40) {
    expected_moves = 70;
  } else if (moves_played <= 50) {
    expected_moves = 80;
  } else if (moves_played <= 70) {
    expected_moves = 100;
  } else if (moves_played <= 100) {
    expected_moves = 120;
  } else {
    expected_moves = moves_played + 40;
  }

  const int time_left = config_.time[state.turn];
  if (time_left > 0) {
    // the division by 2 here converts plies into moves
    const int moves_to_go = (expected_moves - moves_played) / 2;
    current_move_time_ += time_left / moves_to_go;
  }

  //const int increment = config_.increment[state.turn];
  //if (increment > 0)
  //  current_move_time_ += increment / 2;

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