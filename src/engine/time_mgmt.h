#ifndef INTEGRAL_TIME_MGMT_H_
#define INTEGRAL_TIME_MGMT_H_

#include <array>
#include <chrono>
#include <condition_variable>
#include <thread>

#include "../chess/board.h"
#include "../utils/types.h"

class TimeManagement {
 public:
  struct Config {
    int depth;
    int move_time;
    std::array<int, 2> time;
    std::array<int, 2> increment;
    Color turn;

    Config() : depth(0), move_time(0), time({}), increment({}) {}
  };

  explicit TimeManagement(const Config &config);

  TimeManagement() = default;

  const Config &GetConfig();

  void SetConfig(const Config &config);

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
  Config config_;
  std::chrono::steady_clock::time_point start_time_, end_time_;
  U64 current_move_time_;
  U64 nodes_searched_;
  bool times_up_;
  std::array<U64, 4096> nodes_spent_table_;
};

#endif  // INTEGRAL_TIME_MGMT_H_