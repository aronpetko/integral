#include "time_mgmt.h"

#include "search.h"

TimeManagement::TimeManagement(const TimeConfig &config)
    : config_(config), nodes_spent_({}) {
  // Determine the structure of the time management from the config
  if (config.infinite) {
    type_ = TimeType::kInfinite;
  } else if (config.depth != 0) {
    type_ = TimeType::kDepth;
  } else {
    type_ = TimeType::kTimed;
  }
}

void TimeManagement::Start() {
  start_time_ = GetCurrentTime();
  nodes_spent_.fill(0);
}

void TimeManagement::Stop() {
  end_time_ = GetCurrentTime();
}

int TimeManagement::GetSearchDepth() const {
  switch (type_) {
    case TimeType::kInfinite:
      return std::numeric_limits<int>::max();
    case TimeType::kDepth:
      return config_.depth;
    case TimeType::kTimed:
      return kMaxSearchDepth;
    default:
      // Silence compiler warnings
      return 0;
  }
}

bool TimeManagement::TimesUp() const {
  if (type_ != TimeType::kTimed) {
    return false;
  }

  return TimeElapsed() >= GetHardLimit();
}

bool TimeManagement::ShouldStop(Move best_move, U32 nodes_searched) {
  if (type_ != TimeType::kTimed) {
    return false;
  }

  if (config_.move_time != 0) {
    return TimesUp();
  }

  return TimeElapsed() >= GetSoftLimit(best_move, nodes_searched);
}

U32 &TimeManagement::NodesSpent(Move move) {
  return nodes_spent_[move.GetData() & 4095];
}

U64 TimeManagement::TimeElapsed() const {
  return std::max<U64>(1, GetCurrentTime() - start_time_);
}

U64 TimeManagement::GetHardLimit() const {
  assert(type_ == TimeType::kTimed);

  if (config_.move_time != 0) {
    return config_.move_time;
  }

  return config_.time_left / 20 + config_.increment / 2;
}

U64 TimeManagement::GetSoftLimit(Move best_move, U32 nodes_searched) {
  const auto percentage_spent =
      NodesSpent(best_move) / std::max<double>(1, nodes_searched);
  return GetHardLimit() * 0.3 * (1.6 - percentage_spent) * 1.5;
}