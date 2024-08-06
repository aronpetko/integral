#ifndef INTEGRAL_SEARCH_H_
#define INTEGRAL_SEARCH_H_

#include <thread>

#include "../../chess/move_gen.h"
#include "../../utils/barrier.h"
#include "../evaluation/evaluation.h"
#include "history/history.h"
#include "stack.h"
#include "time_mgmt.h"

namespace search {

constexpr int kMaxSearchDepth = 100;

enum class NodeType {
  kPV,
  kNonPV
};

enum class SearchType {
  kRegular,
  kBench
};

struct Thread {
  explicit Thread(U32 id)
      : id(id), stack({}), nodes_searched(0), sel_depth(0), tb_hits(0) {
    NewGame();
  }

  void NewGame() {
    history.Clear();
    stack.Reset();
  }

  [[nodiscard]] bool IsMainThread() const {
    return id == 0;
  }

  void Reset(Board &new_board) {
    board = new_board;
    stack.Reset();

    // Reset info data
    nodes_searched.store(0, std::memory_order_seq_cst);
    sel_depth = 0;
    tb_hits = 0;
  }

  std::thread raw_thread;
  U32 id;
  Board board;
  history::History history;
  Stack stack;
  std::atomic<U64> nodes_searched;
  U16 sel_depth;
  U64 tb_hits;
};

class Search {
 public:
  explicit Search(Board &board);

  ~Search();

  void Start(TimeConfig time_config);

  std::pair<Score, Move> DataGenStart(TimeConfig time_config);

  U64 Bench(int depth);

  void Stop();

  void SetThreadCount(U16 count);

  void QuitThreads();

  void NewGame(bool clear_tables = true);

  const TimeManagement &GetTimeManagement() const;

  [[nodiscard]] U64 GetNodesSearched() const;

  void ResizeHash(U64 size);

 private:
  void Run(Thread &thread);

  void WaitForThreads();

  template <SearchType type>
  void IterativeDeepening(Thread &thread);

  template <NodeType node_type>
  Score QuiescentSearch(Thread &thread,
                        Score alpha,
                        Score beta,
                        StackEntry *stack);

  template <NodeType node_type>
  Score PVSearch(Thread &thread,
                 int depth,
                 Score alpha,
                 Score beta,
                 StackEntry *stack,
                 bool cut_node);

  [[nodiscard]] bool ShouldQuit(Thread &thread);

 private:
  Board &board_;
  TimeManagement time_mgmt_;
  std::atomic_bool stop_, quit_;
  Barrier stop_barrier_, start_barrier_, search_end_barrier_;
  std::mutex stop_mutex_, thread_stopped_mutex_;
  std::atomic_int searching_threads_, next_thread_id_;
  std::condition_variable thread_stopped_signal_;
  std::vector<std::unique_ptr<Thread>> threads_;
  TranspositionTable transposition_table_;
};

}  // namespace search

#endif  // INTEGRAL_SEARCH_H_