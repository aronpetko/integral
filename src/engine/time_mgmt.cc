#include "time_mgmt.h"

#include <thread>

TimeManagement::TimeManagement(const TimeConfig &config)
    : config_(config),
      current_move_time_(0),
      nodes_searched_(0),
      nodes_spent_table_({}) {}

const TimeConfig &TimeManagement::GetConfig() {
  return config_;
}

void TimeManagement::SetConfig(const TimeConfig &config) {
  config_ = config;
}

void TimeManagement::Start() {
  times_up_ = false;
  start_time_ = std::chrono::steady_clock::now();
  nodes_spent_table_.fill(0ULL);
}

void TimeManagement::Stop() {
  times_up_ = true;
  end_time_ = std::chrono::steady_clock::now();
}

[[nodiscard]] U64 TimeManagement::CalculateHardLimit(Color turn) const {
  return config_.move_time
             ? config_.move_time
             : config_.time[turn] / 20 + config_.increment[turn] / 2;
}

[[nodiscard]] U64 TimeManagement::CalculateSoftLimit(Color turn,
                                                     Move pv_move) const {
  if (config_.move_time) return config_.move_time;

  // Taken from chessatron
  const auto best_move_fraction =
      static_cast<double>(nodes_spent_table_[NodeTableIndex(pv_move)]) /
      std::max(1ULL, nodes_searched_);
  const auto hard_limit = CalculateHardLimit(turn);
  return ((hard_limit / 10) * 3) * (1.6 - best_move_fraction) * 1.5;
}

int TimeManagement::NodeTableIndex(Move move) const {
  return move.GetData() & (nodes_spent_table_.size() - 1);
}

void TimeManagement::UpdateNodesSearched() {
  nodes_searched_++;
}

void TimeManagement::UpdateNodesSpentTable(Move move, const U64 &nodes_spent) {
  nodes_spent_table_[NodeTableIndex(move)] += nodes_spent;
}

bool TimeManagement::TimesUp() const {
  if (times_up_) return true;
  if (config_.depth) return false;
  constexpr int kElapsedCheckInterval = 2047;
  if (nodes_searched_ & kElapsedCheckInterval)
    return TimeElapsed() >= CalculateHardLimit(config_.turn);
  return false;
}

bool TimeManagement::SoftTimesUp(Move pv_move) {
  if (!pv_move) return TimesUp();
  return config_.depth == 0 &&
         TimeElapsed() >= CalculateSoftLimit(config_.turn, pv_move);
}

U64 TimeManagement::NodesPerSecond() const {
  const U64 elapsed =
      times_up_ && config_.depth == 0
          ? duration_cast<std::chrono::milliseconds>(end_time_ - start_time_)
                .count()
          : TimeElapsed();
  return nodes_searched_ * 1000.0 / std::max(elapsed, 1ULL);
}

U64 TimeManagement::GetNodesSearched() const {
  return nodes_searched_;
}

U64 TimeManagement::GetMoveTime() const {
  return current_move_time_;
}

U64 TimeManagement::TimeElapsed() const {
  return duration_cast<std::chrono::milliseconds>(
             std::chrono::steady_clock::now() - start_time_)
      .count();
}