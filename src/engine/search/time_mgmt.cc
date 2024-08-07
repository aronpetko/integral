#include "time_mgmt.h"

#include "../../tuner/spsa.h"
#include "search.h"

namespace search {

Tunable base_time_scale("base_time_scale", 0.055, 0, 0.10, 0.003);
Tunable increment_scale("increment_scale", 0.91, 0, 1.00, 0.04);
Tunable percent_limit("percent_limit", 0.77, 0, 1.00, 0.03);
Tunable hard_limit_scale("hard_limit_scale", 3.25, 1.00, 4.50, 0.08);
Tunable soft_limit_scale("soft_limit_scale", 0.83, 0, 1.50, 0.08);
Tunable node_fraction_base("node_fraction_base", 1.49, 0.50, 2.50, 0.08);
Tunable node_fraction_scale("node_fraction_scale", 1.56, 0.50, 2.50, 0.08);
std::array<Tunable, 5> move_stability_scale = {
    Tunable("mss_1", 2.32, 0.0, 5.0, 0.07),
    Tunable("mss_2", 1.22, 0.0, 5.0, 0.07),
    Tunable("mss_3", 1.07, 0.0, 5.0, 0.07),
    Tunable("mss_4", 0.79, 0.0, 5.0, 0.07),
    Tunable("mss_5", 0.68, 0.0, 5.0, 0.07),
};

[[maybe_unused]] TimeManagement::TimeManagement(const TimeConfig &config)
    : nodes_spent_({}) {
  SetConfig(config);
}

void TimeManagement::Start() {
  start_time_.store(GetCurrentTime());
  nodes_spent_.fill(0);
  const int overhead = uci::listener.GetOption("MoveOverhead").GetValue<int>();

  if (config_.move_time != 0) {
    hard_limit_.store(config_.move_time - overhead);
    soft_limit_.store(hard_limit_);
    return;
  }

  previous_best_move_ = Move::NullMove();

  const int base_time = config_.time_left * base_time_scale +
                        config_.increment * increment_scale - overhead;
  const int maximum_time = percent_limit * config_.time_left;

  const int scaled_hard_limit =
      std::min(static_cast<int>(hard_limit_scale * base_time), maximum_time);
  const int scaled_soft_limit =
      std::min(static_cast<int>(soft_limit_scale * base_time), maximum_time);

  hard_limit_.store(std::max(5, scaled_hard_limit));
  soft_limit_.store(std::max(1, scaled_soft_limit));
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
  } else if (config.nodes != 0) {
    type_ = TimeType::kNodes;
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
    case TimeType::kNodes:
      [[fallthrough]];
    case TimeType::kTimed:
      return kMaxSearchDepth;
    default:
      // Silence compiler warnings
      return 0;
  }
}

bool TimeManagement::TimesUp(U32 nodes_searched) {
  if (type_ == TimeType::kNodes) {
    return nodes_searched >= config_.nodes;
  } else if (type_ != TimeType::kTimed) {
    return false;
  }
  if (config_.move_time != 0 && TimeElapsed() >= config_.move_time) {
    fmt::println("{}", config_.move_time);
  }
  return nodes_searched & 4096 && TimeElapsed() >= hard_limit_;
}

bool TimeManagement::ShouldStop(Move best_move, int depth, U32 nodes_searched) {
  if (type_ == TimeType::kNodes) return nodes_searched >= config_.nodes;
  if (type_ != TimeType::kTimed) return false;
  if (config_.move_time != 0) return TimesUp(nodes_searched);

  if (depth < 7) {
    return TimeElapsed() >= soft_limit_;
  }

  // Keep track of how many times this move has been the best move
  if (previous_best_move_ != best_move) {
    previous_best_move_ = best_move;
    best_move_stability_ = 0;
  } else if (best_move_stability_ < 4) {
    best_move_stability_++;
  }

  const auto percent_searched =
      NodesSpent(best_move) / std::max<double>(1, nodes_searched);
  const double percent_scale_factor =
      (node_fraction_base - percent_searched) * node_fraction_scale;
  const double stability_scale = move_stability_scale[best_move_stability_];
  const U32 optimal_limit = std::min<U32>(
      soft_limit_ * percent_scale_factor * stability_scale, hard_limit_);

  return TimeElapsed() >= optimal_limit;
}

U32 &TimeManagement::NodesSpent(Move move) {
  return nodes_spent_[move.GetData() & 4095];
}

U64 TimeManagement::TimeElapsed() const {
  return std::max<U64>(1, GetCurrentTime() - start_time_.load());
}

TimeType TimeManagement::GetType() const {
  return type_;
}

}  // namespace search