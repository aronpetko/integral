#include "time_mgmt.h"

#include "../../tuner/spsa.h"
#include "search.h"

namespace search {

TUNABLE(kBaseTimeScale, 0.05733820228980802, 0, 0.10, false);
TUNABLE(kIncrementScale, 0.9760856856329947, 0, 1.00, false);
TUNABLE(kPercentLimit, 0.8276195006604234, 0, 1.00, false);
TUNABLE(kHardLimitScale, 3.393784908696118, 1.00, 4.50, false);
TUNABLE(kSoftLimitScale, 0.8237969047606986, 0, 1.50, false);
TUNABLE(kNodeFractionBase, 1.4523797051230019, 0.50, 2.50, false);
TUNABLE(kNodeFractionScale, 1.5525960191419124, 0.50, 2.50, false);
TUNABLE(kMoveStabilityScale1, 2.4030366505287315, 1.5, 3.0, false);
TUNABLE(kMoveStabilityScale2, 1.30317921803015, 0.5, 2.0, false);
TUNABLE(kMoveStabilityScale3, 1.0659706093407642, 0.5, 2.0, false);
TUNABLE(kMoveStabilityScale4, 0.7862126398768999, 0.2, 1.5, false);
TUNABLE(kMoveStabilityScale5, 0.6949568477601432, 0.2, 1.5, false);
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

bool DepthLimiter::ShouldStop(Move best_move, int depth, Thread& thread) {
  return depth >= max_depth_;
}

bool DepthLimiter::TimesUp(U64 nodes_searched) {
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

bool NodeLimiter::ShouldStop(Move best_move, int depth, Thread& thread) {
  return soft_max_nodes_ != 0 && thread.nodes_searched >= soft_max_nodes_ ||
         max_nodes_ != 0 && TimesUp(thread.nodes_searched);
}

bool NodeLimiter::TimesUp(U64 nodes_searched) {
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
  if (time_left) {
    CalculateLimits();
  }
}

int TimedLimiter::GetSearchDepth() const {
  return search::kMaxSearchDepth;
}

U64& TimedLimiter::NodesSpent(Move move) {
  return nodes_spent_[move.GetData() & 4095];
}

bool TimedLimiter::ShouldStop(Move best_move, int depth, Thread& thread) {
  if (move_time_ != 0) {
    return TimesUp(thread.nodes_searched);
  }

  if (depth <= 5) {
    return TimeElapsed() >= hard_limit_;
  }

  // Keep track of how many times this move has been the best move
  if (previous_best_move_ != best_move) {
    previous_best_move_ = best_move;
    best_move_stability_ = 0;
  } else if (best_move_stability_ < 10) {
    best_move_stability_++;
  }

  const double stability_factor = 1.3110 - 0.0533 * best_move_stability_;

  const Score best_score = thread.scores[depth];
  Score search_score_diff = thread.scores[depth - 3] - best_score;
  Score previous_score_diff = thread.previous_score - thread.scores[depth];

  // If this was the first search of the game, we just use the search score
  // difference
  if (thread.previous_score == kScoreNone) {
    search_score_diff *= 2, previous_score_diff = 0;
  }

  double score_change_factor =
      0.1127 + 0.0262 * search_score_diff * (search_score_diff > 0) +
      0.0261 * previous_score_diff * (previous_score_diff > 0);
  score_change_factor = std::max(0.5028, std::min(1.6561, score_change_factor));

  const auto best_move_nodes = NodesSpent(best_move);
  const auto percent_nodes_not_best =
      1.0 - static_cast<double>(best_move_nodes) / thread.nodes_searched;
  const double node_count_factor =
      std::max(0.5630, percent_nodes_not_best * 2.2669 + 0.4499);

  return TimeElapsed() >= allocated_time_ * stability_factor *
                              score_change_factor * node_count_factor;
}

bool TimedLimiter::TimesUp(U64 nodes_searched) {
  return (nodes_searched & 4095) == 0 && TimeElapsed() >= hard_limit_;
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
    return;
  }

  const int total_time =
      std::max(1, time_left_ + 50 * increment_ - 50 * overhead);
  allocated_time_ = std::min(time_left_ * 0.4193, total_time * 0.0575);
  hard_limit_ = time_left_ * 0.8 - overhead;
}

void TimedLimiter::Update(const TimeConfig& config) {
  time_left_ = config.time_left;
  increment_ = config.increment;
  move_time_ = config.move_time;
  CalculateLimits();
}

// TimeManagement implementation
TimeManagement::TimeManagement() {
  // Pre-allocate all limiter types
  cached_depth_limiter_ = std::make_unique<DepthLimiter>(1);
  cached_node_limiter_ = std::make_unique<NodeLimiter>(0, 0);
  cached_timed_limiter_ = std::make_unique<TimedLimiter>(0, 0, 0);
  active_limiters_.reserve(3);
}

TimeManagement::TimeManagement(const TimeConfig& config) {
  SetConfig(config);
}

void TimeManagement::SetConfig(const TimeConfig& config) {
  config_ = config;
  ConfigureLimiters(config);
}

void TimeManagement::ConfigureLimiters(const TimeConfig& config) {
  active_limiters_.clear();

  if (config.infinite) {
    return;
  }

  if (config.depth > 0) {
    cached_depth_limiter_->Update(config);
    active_limiters_.push_back(cached_depth_limiter_.get());
  }

  if (config.nodes > 0 || config.soft_nodes > 0) {
    cached_node_limiter_->Update(config);
    active_limiters_.push_back(cached_node_limiter_.get());
  }

  if (config.move_time > 0 || config.time_left > 0) {
    cached_timed_limiter_->Update(config);
    active_limiters_.push_back(cached_timed_limiter_.get());
  }
}

TimedLimiter* TimeManagement::GetTimedLimiter() {
  return cached_timed_limiter_.get();
}

U64 TimeManagement::TimeElapsed() const {
  return std::max<U64>(1, GetCurrentTime() - start_time_);
}

int TimeManagement::GetSearchDepth() const {
  int min_depth = search::kMaxSearchDepth;
  for (const auto* limiter : active_limiters_) {
    min_depth = std::min(min_depth, limiter->GetSearchDepth());
  }
  return min_depth;
}

bool TimeManagement::IsInfinite() const {
  return config_.infinite;
}

void TimeManagement::Start() {
  start_time_ = GetCurrentTime();
  for (auto* limiter : active_limiters_) {
    limiter->Start();
  }
}

void TimeManagement::Stop() {
  end_time_ = GetCurrentTime();
  for (auto* limiter : active_limiters_) {
    limiter->Stop();
  }
}

bool TimeManagement::ShouldStop(Move best_move, int depth, Thread& thread) {
  for (auto* limiter : active_limiters_) {
    if (limiter->ShouldStop(best_move, depth, thread)) {
      return true;
    }
  }
  return false;
}

bool TimeManagement::TimesUp(U64 nodes_searched) {
  for (auto* limiter : active_limiters_) {
    if (limiter->TimesUp(nodes_searched)) {
      return true;
    }
  }
  return false;
}

}  // namespace search