#ifndef INTEGRAL_SEARCH_H_
#define INTEGRAL_SEARCH_H_

#include <thread>

#include "../../chess/move_gen.h"
#include "../../utils/barrier.h"
#include "../evaluation/evaluation.h"
#include "history/history.h"
#include "stack.h"
#include "time_mgmt.h"

constexpr int kMaxSearchDepth = 100;

enum class NodeType {
  kPV,
  kNonPV
};

enum class SearchType {
  kRegular,
  kBench
};

class Search {
 public:
  explicit Search(Board &board);

  ~Search();

  void Start(TimeConfig &time_config);

  void Stop();

  void QuitThreads();

  void Bench(int depth);

  TimeManagement &GetTimeManagement();

  void NewGame();

  [[nodiscard]] U64 GetNodesSearched() const;

 private:
  void Run();

  template <SearchType type>
  void IterativeDeepening();

  template <NodeType node_type>
  Score QuiescentSearch(Score alpha, Score beta, SearchStackEntry *stack);

  template <NodeType node_type>
  Score PVSearch(int depth,
                 Score alpha,
                 Score beta,
                 SearchStackEntry *stack,
                 bool cut_node);

  [[nodiscard]] bool ShouldQuit();

 private:
  Board &board_;
  TimeManagement time_mgmt_;
  history::SearchHistory history_;
  SearchStack search_stack_;
  U16 sel_depth_;
  std::atomic<U64> nodes_searched_, tb_hits_;
  std::atomic_bool stop_, quit_;
  Barrier stop_barrier_, start_barrier_, search_end_barrier_;
  std::mutex thread_stopped_mutex_;
  std::atomic_int searching_threads_;
  std::condition_variable thread_stopped_signal_;
  std::vector<std::thread> threads_;
};

#endif  // INTEGRAL_SEARCH_H_