#ifndef INTEGRAL_TIME_MGMT_H_
#define INTEGRAL_TIME_MGMT_H_

#include <array>
#include <memory>
#include <optional>
#include <vector>

#include "../../chess/board.h"
#include "../../utils/time.h"
#include "../../utils/types.h"

namespace search {

class Thread;

struct TimeConfig {
  bool infinite = false;
  int depth = 0;
  U64 nodes = 0, soft_nodes = 0;
  int move_time = 0;
  int time_left = 0;
  int increment = 0;

  [[nodiscard]] bool HasBeenModified() const;
  bool operator==(const TimeConfig& other) const;
};

class TimeLimiter {
 public:
  virtual ~TimeLimiter() = default;

  virtual bool ShouldStop(Move best_move, int depth, Thread& thread) = 0;

  virtual bool TimesUp(U64 nodes_searched) = 0;

  virtual void Start() = 0;

  virtual void Stop() = 0;

  [[nodiscard]] virtual int GetSearchDepth() const = 0;

  virtual void Update(const TimeConfig& config) = 0;
};

class DepthLimiter : public TimeLimiter {
 public:
  explicit DepthLimiter(int max_depth);

  bool ShouldStop(Move best_move, int depth, Thread& thread) override;

  bool TimesUp(U64 nodes_searched) override;

  void Start() override;

  void Stop() override;

  [[nodiscard]] int GetSearchDepth() const override;

  void Update(const TimeConfig& config) override;

 private:
  int max_depth_;
};

class NodeLimiter : public TimeLimiter {
 public:
  NodeLimiter(U64 max_nodes, U64 soft_max_nodes);

  bool ShouldStop(Move best_move, int depth, Thread& thread) override;

  bool TimesUp(U64 nodes_searched) override;

  void Start() override;

  void Stop() override;

  [[nodiscard]] int GetSearchDepth() const override;

  void Update(const TimeConfig& config) override;

 private:
  U64 max_nodes_;
  U64 soft_max_nodes_;
};

class TimedLimiter : public TimeLimiter {
 public:
  TimedLimiter(int time_left, int increment, int move_time);

  bool ShouldStop(Move best_move, int depth, Thread& thread) override;

  bool TimesUp(U64 nodes_searched) override;

  void Start() override;

  void Stop() override;

  [[nodiscard]] U64& NodesSpent(Move move);

  [[nodiscard]] U64 TimeElapsed() const;

  [[nodiscard]] int GetSearchDepth() const override;

  void Update(const TimeConfig& config) override;

 private:
  void CalculateLimits();

 private:
  int time_left_;
  int increment_;
  int move_time_;
  TimeStamp allocated_time_;
  TimeStamp hard_limit_;
  TimeStamp soft_limit_;
  TimeStamp start_time_, end_time_;
  Move previous_best_move_;
  int best_move_stability_;
  std::array<U64, 4096> nodes_spent_;
};

class TimeManagement {
 public:
  TimeManagement();

  explicit TimeManagement(const TimeConfig& config);

  void SetConfig(const TimeConfig& config);

  void Start();

  void Stop();

  bool ShouldStop(Move best_move, int depth, Thread& thread);

  bool TimesUp(U64 nodes_searched);

  TimedLimiter* GetTimedLimiter();

  [[nodiscard]] U64 TimeElapsed() const;

  [[nodiscard]] int GetSearchDepth() const;

  [[nodiscard]] bool IsInfinite() const;

 private:
  void ConfigureLimiters(const TimeConfig& config);

 private:
  TimeConfig config_;
  TimeStamp start_time_ = 0;
  TimeStamp end_time_ = 0;
  std::unique_ptr<DepthLimiter> cached_depth_limiter_ = nullptr;
  std::unique_ptr<NodeLimiter> cached_node_limiter_ = nullptr;
  std::unique_ptr<TimedLimiter> cached_timed_limiter_ = nullptr;
  std::vector<TimeLimiter*> active_limiters_;
};

}  // namespace search

#endif  // INTEGRAL_TIME_MGMT_H_