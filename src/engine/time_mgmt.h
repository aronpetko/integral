#ifndef INTEGRAL_TIME_MGMT_H_
#define INTEGRAL_TIME_MGMT_H_

#include <array>
#include <chrono>
#include <condition_variable>

using std::chrono::duration_cast;

#include "../chess/board.h"
#include "../utils/types.h"

struct TimeConfig {
  bool infinite = false;
  int depth = 0;
  int move_time = 0;
  int time_left = 0;
  int increment = 0;
};

using SteadyClock = std::chrono::steady_clock;
using TimeStamp = U32;

static U64 GetCurrentTime() {
  const auto duration = SteadyClock::now().time_since_epoch();
  return duration_cast<std::chrono::milliseconds>(duration).count();
}

enum class TimeType {
  // Search in accordance with the time parameters passed
  kTimed,
  // Search up to a certain depth
  kDepth,
  // Search until a "stop" command
  kInfinite
};

class TimeManagement {
 public:
  explicit TimeManagement(const TimeConfig &config);

  TimeManagement() = default;

  void Start();

  void Stop();

  // Determines if the search should end if we are confident that this move
  // shouldn't be searched further (soft limit)
  [[nodiscard]] bool ShouldStop(Move best_move, U32 nodes_searched);

  // Determine if the search must give up now to avoid losing
  [[nodiscard]] bool TimesUp() const;

  [[nodiscard]] int GetSearchDepth() const;

  [[nodiscard]] U32 &NodesSpent(Move move);

  [[nodiscard]] U64 TimeElapsed() const;

 private:
  [[nodiscard]] U64 GetHardLimit() const;

  [[nodiscard]] U64 GetSoftLimit(Move best_move, U32 nodes_searched);

 private:
  TimeConfig config_;
  TimeType type_;
  TimeStamp start_time_, end_time_;
  // Table that keeps track of how many nodes were spent searching a particular
  // move
  std::array<U32, 4096> nodes_spent_;
};

#endif  // INTEGRAL_TIME_MGMT_H_