#ifndef INTEGRAL_SEARCH_H_
#define INTEGRAL_SEARCH_H_

#include "../../chess/move_gen.h"
#include "../evaluation/evaluation.h"
#include "history/history.h"
#include "time_mgmt.h"
#include "stack.h"

constexpr int kMaxSearchDepth = 100;

enum class NodeType {
  kRoot,
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

  void Start(TimeConfig &time_config);

  void Stop();

  void WaitUntilFinished() const;

  void Bench(int depth);

  TimeManagement &GetTimeManagement();

  void NewGame();

  [[nodiscard]] U64 GetNodesSearched() const;

 private:
  template <SearchType type>
  void IterativeDeepening();

  template <NodeType node_type>
  Score QuiescentSearch(Score alpha, Score beta, SearchStackEntry *stack);

  template <NodeType node_type>
  Score PVSearch(int depth, Score alpha, Score beta, SearchStackEntry *stack, bool cut_node);

  [[nodiscard]] bool ShouldQuit();

 private:
  Board &board_;
  TimeManagement time_mgmt_;
  history::SearchHistory history_;
  SearchStack search_stack_;
  std::array<std::array<int, kMaxMoves>, kMaxSearchDepth + 1> lmr_table_;
  U16 sel_depth_;
  std::atomic_uint64_t nodes_searched_;
  std::atomic_bool searching_;
};

#endif  // INTEGRAL_SEARCH_H_