#include "time_mgmt.h"

#include <thread>

TimeManagement::TimeManagement(const TimeManagement::Config &config)
    : config_(config), current_move_time_(0), nodes_searched_(0), nodes_spent_table_({}) {}

const TimeManagement::Config &TimeManagement::get_config() {
  return config_;
}

void TimeManagement::set_config(const TimeManagement::Config &config) {
  config_ = config;
}

void TimeManagement::start() {
  times_up_ = false;
  start_time_ = std::chrono::steady_clock::now();
  nodes_spent_table_.fill(0ULL);
}

void TimeManagement::stop() {
  times_up_ = true;
  end_time_ = std::chrono::steady_clock::now();
}

[[nodiscard]] U64 TimeManagement::calculate_hard_limit(Color turn) const {
  return config_.move_time ? config_.move_time : config_.time[turn] / 20 + config_.increment[turn] / 2;
}

[[nodiscard]] U64 TimeManagement::calculate_soft_limit(Color turn, Move pv_move) const {
  if (config_.move_time) return config_.move_time;

  // taken from chessatron
  const auto best_move_fraction =
      static_cast<double>(nodes_spent_table_[node_table_index(pv_move)]) / std::max(1ULL, nodes_searched_);
  const auto hard_limit = calculate_hard_limit(turn);
  return ((hard_limit / 10) * 3) * (1.6 - best_move_fraction) * 1.5;
}

int TimeManagement::node_table_index(Move move) const {
  return move.get_data() & (nodes_spent_table_.size() - 1);
}

void TimeManagement::update_nodes_searched() {
  nodes_searched_++;
}

void TimeManagement::update_nodes_spent_table(Move move, const U64 &nodes_spent) {
  nodes_spent_table_[node_table_index(move)] += nodes_spent;
}

bool TimeManagement::times_up() const {
  if (times_up_) return true;
  if (config_.depth) return false;
  const int kElapsedCheckInterval = 2047;
  if (nodes_searched_ & kElapsedCheckInterval) return time_elapsed() >= calculate_hard_limit(config_.turn);
  return false;
}

bool TimeManagement::soft_times_up(Move pv_move) {
  if (!pv_move) return times_up();
  return config_.depth == 0 && time_elapsed() >= calculate_soft_limit(config_.turn, pv_move);
}

U64 TimeManagement::nodes_per_second() const {
  const U64 elapsed = times_up_ && config_.depth == 0
                      ? duration_cast<std::chrono::milliseconds>(end_time_ - start_time_).count()
                      : time_elapsed();
  return nodes_searched_ * 1000.0 / std::max(elapsed, 1ULL);
}

U64 TimeManagement::get_nodes_searched() const {
  return nodes_searched_;
}

U64 TimeManagement::get_move_time() const {
  return current_move_time_;
}

U64 TimeManagement::time_elapsed() const {
  return duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time_).count();
}