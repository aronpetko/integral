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

U64 GetCurrentTime() {
  const auto duration = std::chrono::steady_clock::now().time_since_epoch();
  return std::chrono::duration_cast<std::chrono::milliseconds>(duration)
      .count();
}

bool TimeConfig::HasBeenModified() const {
  static const TimeConfig default_config;
  return !(*this == default_config);
}

bool TimeConfig::operator==(const TimeConfig& other) const {
  return infinite == other.infinite && depth == other.depth &&
         move_time == other.move_time && time_left == other.time_left &&
         increment == other.increment && nodes == other.nodes &&
         soft_nodes == other.soft_nodes;
}

// DepthLimiter implementation
DepthLimiter::DepthLimiter(int max_depth) : max_depth_(max_depth) {}

int DepthLimiter::GetSearchDepth() const {
  return max_depth_;
}

bool DepthLimiter::ShouldStop(Move best_move, int depth, U32 nodes_searched) {
  return depth >= max_depth_;
}

bool DepthLimiter::TimesUp(U32 nodes_searched) {
  return false;
}

void DepthLimiter::Start() {}
void DepthLimiter::Stop() {}

// NodeLimiter implementation
NodeLimiter::NodeLimiter(U64 max_nodes, U64 soft_max_nodes)
    : max_nodes_(max_nodes), soft_max_nodes_(soft_max_nodes) {}

int NodeLimiter::GetSearchDepth() const {
  return search::kMaxSearchDepth;
}

bool NodeLimiter::ShouldStop(Move best_move, int depth, U32 nodes_searched) {
  return soft_max_nodes_ != 0 && nodes_searched >= soft_max_nodes_;
}

bool NodeLimiter::TimesUp(U32 nodes_searched) {
  return max_nodes_ != 0 && nodes_searched >= max_nodes_;
}

void NodeLimiter::Start() {}
void NodeLimiter::Stop() {}

// TimedLimiter implementation
TimedLimiter::TimedLimiter(int time_left, int increment, int move_time)
    : time_left_(time_left),
      increment_(increment),
      move_time_(move_time),
      previous_best_move_(Move::NullMove()),
      best_move_stability_(0) {
  CalculateLimits();
}

int TimedLimiter::GetSearchDepth() const {
  return search::kMaxSearchDepth;
}

U64& TimedLimiter::NodesSpent(Move move) {
  return nodes_spent_[move.GetData() & 4095];
}

bool TimedLimiter::ShouldStop(Move best_move, int depth, U32 nodes_searched) {
  if (move_time_ != 0) {
    return TimesUp(nodes_searched);
  }

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

bool TimedLimiter::TimesUp(U32 nodes_searched) {
  return nodes_searched & 4096 && TimeElapsed() >= hard_limit_;
}

void TimedLimiter::Start() {
  start_time_ = GetCurrentTime();
  nodes_spent_.fill(0);
}

void TimedLimiter::Stop() {
  end_time_ = GetCurrentTime();
}

[[nodiscard]] U64 TimedLimiter::TimeElapsed() const {
  return std::max<U64>(1, GetCurrentTime() - start_time_);
}

void TimedLimiter::CalculateLimits() {
  const int overhead = uci::listener.GetOption("MoveOverhead").GetValue<int>();

  if (move_time_ != 0) {
    hard_limit_ = move_time_ - overhead;
    soft_limit_ = hard_limit_;
    return;
  }

  previous_best_move_ = Move::NullMove();

  const int base_time =
      time_left_ * base_time_scale + increment_ * increment_scale - overhead;
  const int maximum_time = percent_limit * time_left_;

  const int scaled_hard_limit =
      std::min(static_cast<int>(hard_limit_scale * base_time), maximum_time);
  const int scaled_soft_limit =
      std::min(static_cast<int>(soft_limit_scale * base_time), maximum_time);

  hard_limit_ = std::max(5, scaled_hard_limit);
  soft_limit_ = std::max(1, scaled_soft_limit);
}

// TimeManagement implementation
TimeManagement::TimeManagement(const TimeConfig& config) {
  SetConfig(config);
}

void TimeManagement::SetConfig(const TimeConfig& config) {
  limiters_.clear();
  config_ = config;
  ConfigureLimiters(config);
}

void TimeManagement::ConfigureLimiters(const TimeConfig& config) {
  if (config.infinite) {
    // No limiters for infinite search
    return;
  }

  if (config.depth > 0) {
    AddLimiter(std::make_unique<DepthLimiter>(config.depth));
  }

  if (config.nodes > 0 || config.soft_nodes > 0) {
    AddLimiter(std::make_unique<NodeLimiter>(config.nodes, config.soft_nodes));
  }

  if (config.move_time > 0 || config.time_left > 0) {
    AddLimiter(std::make_unique<TimedLimiter>(
        config.time_left, config.increment, config.move_time));
  }
}

void TimeManagement::AddLimiter(std::unique_ptr<TimeLimiter> limiter) {
  limiters_.push_back(std::move(limiter));
}

TimedLimiter* TimeManagement::GetTimedLimiter() {
  for (auto& limiter : limiters_) {
    if (auto* timed_limiter = dynamic_cast<TimedLimiter*>(limiter.get())) {
      return timed_limiter;
    }
  }
  return nullptr;
}

U64 TimeManagement::TimeElapsed() const {
  return std::max<U64>(1, GetCurrentTime() - start_time_);
}

int TimeManagement::GetSearchDepth() const {
  int min_depth = search::kMaxSearchDepth;
  for (const auto& limiter : limiters_) {
    min_depth = std::min(min_depth, limiter->GetSearchDepth());
  }
  return min_depth;
}

bool TimeManagement::IsInfinite() const {
  return config_.infinite;
}

void TimeManagement::Start() {
  start_time_ = GetCurrentTime();
  for (auto& limiter : limiters_) {
    limiter->Start();
  }
}

void TimeManagement::Stop() {
  end_time_ = GetCurrentTime();
  for (auto& limiter : limiters_) {
    limiter->Stop();
  }
}

bool TimeManagement::ShouldStop(Move best_move, int depth, U32 nodes_searched) {
  for (auto& limiter : limiters_) {
    if (limiter->ShouldStop(best_move, depth, nodes_searched)) {
      return true;
    }
  }
  return false;
}

bool TimeManagement::TimesUp(U32 nodes_searched) {
  for (auto& limiter : limiters_) {
    if (limiter->TimesUp(nodes_searched)) {
      return true;
    }
  }
  return false;
}

}  // namespace search