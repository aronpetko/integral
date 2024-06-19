#include "time_mgmt.h"

#include "../../tuner/spsa.h"
#include "../uci/uci.h"
#include "search.h"

Tunable base_time_scale("base_time_scale", 0.054, 0, 0.10);
Tunable increment_scale("increment_scale", 0.85, 0, 1.00);
Tunable percent_limit("percent_limit", 0.76, 0, 1.00);
Tunable hard_limit_scale("hard_limit_scale", 3.04, 1.00, 4.50);
Tunable soft_limit_scale("soft_limit_scale", 0.76, 0, 1.50);
Tunable node_fraction_base("node_fraction_base", 1.52, 0.50, 2.50);
Tunable node_fraction_scale("node_fraction_scale", 1.74, 0.50, 2.50);

[[maybe_unused]] TimeManagement::TimeManagement(const TimeConfig &config)
    : nodes_spent_({}) {
  SetConfig(config);
}

void TimeManagement::Start() {
  const int base_time = config_.time_left * base_time_scale +
                        config_.increment * increment_scale -
                        uci::GetOption("Move Overhead").GetValue<int>();
  const auto maximum_time = percent_limit * config_.time_left;

  hard_limit_.store(std::min(hard_limit_scale * base_time, maximum_time));
  soft_limit_.store(std::min(soft_limit_scale * base_time, maximum_time));

  start_time_.store(GetCurrentTime());
  nodes_spent_.fill(0);
}

void TimeManagement::Stop() {
  end_time_.store(GetCurrentTime());
}

void TimeManagement::SetConfig(const TimeConfig &config) {
  config_ = config;
  // Determine the structure of the time management from the config
  if (config.infinite) {
    type_ = TimeType::kInfinite;
  } else if (config.depth != 0) {
    type_ = TimeType::kDepth;
  } else {
    type_ = TimeType::kTimed;
  }
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

bool TimeManagement::TimesUp() {
  if (type_ != TimeType::kTimed) {
    return false;
  }

  return TimeElapsed() >= hard_limit_;
}

bool TimeManagement::ShouldStop(Move best_move, U32 nodes_searched) {
  if (type_ != TimeType::kTimed) {
    return false;
  }

  if (config_.move_time != 0) {
    return TimesUp();
  }

  const auto percent_searched =
      NodesSpent(best_move) / std::max<double>(1, nodes_searched);
  const double percent_scale_factor =
      (node_fraction_base - percent_searched) * node_fraction_scale;
  const U32 optimal_limit =
      std::min<U32>(soft_limit_ * percent_scale_factor, hard_limit_);

  return TimeElapsed() >= optimal_limit;
}

U32 &TimeManagement::NodesSpent(Move move) {
  return nodes_spent_[move.GetData() & 4095];
}

U64 TimeManagement::TimeElapsed() {
  return std::max<U64>(1, GetCurrentTime() - start_time_.load());
}