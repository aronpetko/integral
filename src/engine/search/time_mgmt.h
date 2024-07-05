#ifndef INTEGRAL_TIME_MGMT_H_
#define INTEGRAL_TIME_MGMT_H_

#include <array>
#include <chrono>
#include <condition_variable>

using std::chrono::duration_cast;

#include "../../chess/board.h"
#include "../../utils/types.h"

struct TimeConfig {
  bool infinite = false;
  int depth = 0;
  int move_time = 0;
  int time_left = 0;
  int increment = 0;

  [[nodiscard]] bool HasBeenModified() const {
    static const TimeConfig default_config;
    return !(*this == default_config);
  }

  bool operator==(const TimeConfig &other) const {
    return infinite == other.infinite && depth == other.depth &&
           move_time == other.move_time && time_left == other.time_left &&
           increment == other.increment;
  }
};

using SteadyClock = std::chrono::steady_clock;
using TimeStamp = U64;

[[maybe_unused]] static U64 GetCurrentTime() {
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
  [[maybe_unused]] explicit TimeManagement(const TimeConfig &config);

  TimeManagement() = default;

  void Start();

  void Stop();

  void SetConfig(const TimeConfig &config);

  // Determines if the search should end if we are confident that this move
  // shouldn't be searched further (soft limit)
  [[nodiscard]] bool ShouldStop(Move best_move, int depth, U32 nodes_searched);

  // Determine if the search must give up now to avoid losing
  [[nodiscard]] bool TimesUp();

  [[nodiscard]] int GetSearchDepth() const;

  [[nodiscard]] U32 &NodesSpent(Move move);

  [[nodiscard]] U64 TimeElapsed();

 private:
  TimeConfig config_;
  TimeType type_;
  std::atomic<TimeStamp> start_time_, end_time_;
  std::atomic<TimeStamp> hard_limit_, soft_limit_;
  // Table that keeps track of how many nodes were spent searching a particular
  // move
  std::array<U32, 4096> nodes_spent_;
  Move previous_best_move_;
  int best_move_stability_;
};

#endif  // INTEGRAL_TIME_MGMT_H_