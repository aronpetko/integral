#include "time_mgmt.h"
#include <format>

const int kTimeBuffer = 100;

TimeManagement::TimeManagement(const TimeManagement::Config &config, Board &board)
    : config_(config), board_(board), current_move_time_(0), times_up_(false), nodes_searched_(0), node_spent_table_({}) {}

const TimeManagement::Config &TimeManagement::get_config() {
  return config_;
}

void TimeManagement::start() {
  start_time_ = std::chrono::steady_clock::now();
  std::fill(node_spent_table_.begin(), node_spent_table_.end(), 0);
}

void TimeManagement::update_move_time(const Move &pv_move) {
  const auto &state = board_.get_state();

  if (config_.move_time) {
    current_move_time_ = config_.move_time;
    return;
  }

  const int hard_limit = config_.time[state.turn] / 20 + config_.increment[state.turn]  / 2;
  current_move_time_ = hard_limit;

  if (!pv_move.is_null()) {
    // taken from chessatron
    const auto best_move_fraction =
        static_cast<double>(node_spent_table_[pv_move.get_data() & 0xFFF]) / nodes_searched_;
    const int soft_limit = hard_limit / 10 * 3 * (1.6 - best_move_fraction) * 1.5;
    current_move_time_ = std::min(hard_limit, soft_limit);
  }
}

void TimeManagement::update_nodes_searched() {
  ++nodes_searched_;
}

void TimeManagement::update_node_spent_table(const Move &move, int prev_nodes_searched) {
  const int nodes_spent = nodes_searched_ - prev_nodes_searched;
  node_spent_table_[move.get_data() & 0x0FFF] += nodes_spent;
}

bool TimeManagement::times_up() {
  if (times_up_)
    return true;
  if (nodes_searched_ % 75000)
    return times_up_ = time_elapsed() >= current_move_time_;
  return false;
}

int TimeManagement::get_nodes_searched() const {
  return nodes_searched_;
}

int TimeManagement::get_move_time() const {
  return current_move_time_;
}

long long TimeManagement::time_elapsed() const {
  return duration_cast<std::chrono::milliseconds>(
      std::chrono::steady_clock::now() - start_time_).count();
}