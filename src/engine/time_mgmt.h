#ifndef INTEGRAL_TIME_MGMT_H_
#define INTEGRAL_TIME_MGMT_H_

#include <array>
#include <chrono>
#include <condition_variable>

#include "../chess/board.h"
#include "../utils/types.h"

constexpr int kMaxSearchDepth = 100;

struct TimeConfig {
  int depth;
  int move_time;
  std::array<int, 2> time;
  std::array<int, 2> increment;

  TimeConfig() : depth(kMaxSearchDepth), move_time(0), time({}), increment({}) {}
};

class TimeManagement {
 public:
  explicit TimeManagement(const TimeConfig &config);

  TimeManagement() = default;

  const TimeConfig &GetConfig();

  void SetConfig(const TimeConfig &config);

  void Start();

  void Stop();

  void UpdateNodesSearched();

  void UpdateNodesSpentTable(Move move, const U64 &nodes_spent);

  [[nodiscard]] bool SoftTimesUp(Move pv_move);

  [[nodiscard]] bool TimesUp() const;

  [[nodiscard]] U64 NodesPerSecond() const;

  [[nodiscard]] U64 GetNodesSearched() const;

  [[nodiscard]] U64 GetMoveTime() const;

  [[nodiscard]] U64 TimeElapsed() const;

  [[nodiscard]] U64 CalculateHardLimit(Color turn) const;

  [[nodiscard]] U64 CalculateSoftLimit(Color turn, Move pv_move) const;

 private:
  [[nodiscard]] int NodeTableIndex(Move move) const;

 private:
  TimeConfig config_;
  std::chrono::steady_clock::time_point start_time_, end_time_;
  U64 current_move_time_;
  U64 nodes_searched_;
  bool times_up_;
  std::array<U64, 4096> nodes_spent_table_;
};

#endif  // INTEGRAL_TIME_MGMT_H_