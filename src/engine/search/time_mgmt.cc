#include "time_mgmt.h"

#include "../../tuner/spsa.h"
#include "search.h"

namespace search {

TUNABLE(kBaseTimeScale, 0.055, 0, 0.10, false);
TUNABLE(kIncrementScale, 0.91, 0, 1.00, false);
TUNABLE(kPercentLimit, 0.77, 0, 1.00, false);
TUNABLE(kHardLimitScale, 3.25, 1.00, 4.50, false);
TUNABLE(kSoftLimitScale, 0.83, 0, 1.50, false);
TUNABLE(kNodeFractionBase, 1.49, 0.50, 2.50, false);
TUNABLE(kNodeFractionScale, 1.56, 0.50, 2.50, false);
TUNABLE(kMoveStabilityScale1, 2.32, 1.5, 3.0, false);
TUNABLE(kMoveStabilityScale2, 1.22, 0.5, 2.0, false);
TUNABLE(kMoveStabilityScale3, 1.07, 0.5, 2.0, false);
TUNABLE(kMoveStabilityScale4, 0.79, 0.2, 1.5, false);
TUNABLE(kMoveStabilityScale5, 0.68, 0.2, 1.5, false);
// clang-format off
inline std::array<Tunable<double>, 5> kMoveStabilityScale = {
    kMoveStabilityScale1,
    kMoveStabilityScale2,
    kMoveStabilityScale3,
    kMoveStabilityScale4,
    kMoveStabilityScale5
};
// clang-format on

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

void DepthLimiter::Update(const TimeConfig& config) {
  max_depth_ = config.depth;
}

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

void NodeLimiter::Update(const TimeConfig& config) {
  max_nodes_ = config.nodes;
  soft_max_nodes_ = config.soft_nodes;
}

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
      (kNodeFractionBase - percent_searched) * kNodeFractionScale;
  const double stability_scale = kMoveStabilityScale[best_move_stability_];
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

U64 TimedLimiter::TimeElapsed() const {
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
      time_left_ * kBaseTimeScale + increment_ * kIncrementScale - overhead;
  const int maximum_time = kPercentLimit * time_left_;

  const int scaled_hard_limit =
      std::min(static_cast<int>(kHardLimitScale * base_time), maximum_time);
  const int scaled_soft_limit =
      std::min(static_cast<int>(kSoftLimitScale * base_time), maximum_time);

  hard_limit_ = std::max(5, scaled_hard_limit);
  soft_limit_ = std::max(1, scaled_soft_limit);
}

void TimedLimiter::Update(const TimeConfig& config) {
  time_left_ = config.time_left;
  increment_ = config.increment;
  move_time_ = config.move_time;
  CalculateLimits();
}

// TimeManagement implementation
TimeManagement::TimeManagement() = default;

TimeManagement::TimeManagement(const TimeConfig& config) {
  SetConfig(config);
}

void TimeManagement::SetConfig(const TimeConfig& config) {
  config_ = config;
  ConfigureLimiters(config);
}

void TimeManagement::ConfigureLimiters(const TimeConfig& config) {
  limiters_.clear();

  if (config.infinite) {
    return;
  }

  if (config.depth > 0) {
    limiters_.push_back(std::make_unique<DepthLimiter>(config.depth));
  }

  if (config.nodes > 0 || config.soft_nodes > 0) {
    limiters_.push_back(
        std::make_unique<NodeLimiter>(config.nodes, config.soft_nodes));
  }

  if (config.move_time > 0 || config.time_left > 0) {
    limiters_.push_back(std::make_unique<TimedLimiter>(
        config.time_left, config.increment, config.move_time));
  }
}

TimedLimiter* TimeManagement::GetTimedLimiter() {
  for (const auto& limiter : limiters_) {
    if (auto timed_limiter = dynamic_cast<TimedLimiter*>(limiter.get())) {
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
  for (const auto& limiter : limiters_) {
    limiter->Start();
  }
}

void TimeManagement::Stop() {
  end_time_ = GetCurrentTime();
  for (const auto& limiter : limiters_) {
    limiter->Stop();
  }
}

bool TimeManagement::ShouldStop(Move best_move, int depth, U32 nodes_searched) {
  for (const auto& limiter : limiters_) {
    if (limiter->ShouldStop(best_move, depth, nodes_searched)) {
      return true;
    }
  }
  return false;
}

bool TimeManagement::TimesUp(U32 nodes_searched) {
  for (const auto& limiter : limiters_) {
    if (limiter->TimesUp(nodes_searched)) {
      return true;
    }
  }
  return false;
}

}  // namespace search