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

enum class ThreadSignal {
  kNone,
  kQuit,
  kSearch,
  kBench,
};

struct Thread {
  explicit Thread(U32 id, Board &board)
      : id(id),
        board(board),
        stack({}),
        nodes_searched(0),
        sel_depth(0),
        tb_hits(0) {
    NewGame();
  }

  void NewGame() {
    history.Clear();
    stack.Reset();
  }

  void StartSearching(Board &new_board) {
    board.CopyFrom(new_board);
    nodes_searched = 0;
    sel_depth = 0;
    tb_hits = 0;
    searching.store(true, std::memory_order_seq_cst);
  }

  [[nodiscard]] bool IsMainThread() const {
    return id == 0;
  }

  std::thread raw_thread;
  std::atomic_bool searching;
  U32 id;
  Board board;
  history::History history;
  SearchStack stack;
  U64 nodes_searched;
  U16 sel_depth;
  U64 tb_hits;
};

class Search {
 public:
  explicit Search(Board &board);

  ~Search();

  void Start(TimeConfig &time_config);

  U64 Bench(int depth);

  void Stop();

  void SetThreadCount(U16 count);

  [[nodiscard]] bool Searching() const;

  void Wait();

  TimeManagement &GetTimeManagement();

  void NewGame();

  [[nodiscard]] U64 GetNodesSearched() const;

 private:
  void Run(Thread &thread);

  void QuitThreads();

  template <SearchType type>
  void IterativeDeepening(Thread &thread);

  template <NodeType node_type>
  Score QuiescentSearch(Thread &thread,
                        Score alpha,
                        Score beta,
                        SearchStackEntry *stack);

  template <NodeType node_type>
  Score PVSearch(Thread &thread,
                 int depth,
                 Score alpha,
                 Score beta,
                 SearchStackEntry *stack,
                 bool cut_node);

  [[nodiscard]] bool ShouldQuit();

 private:
  Board &board_;
  TimeManagement time_mgmt_;
  std::atomic_bool searching_, benching_, stopped_, quit_;
  int next_thread_id_;
  std::vector<std::unique_ptr<Thread>> threads_;
  std::mutex search_mutex_{}, stop_mutex_{};
  std::condition_variable stop_signal_{};
  std::atomic_int running_threads_;
  Barrier start_barrier_, stop_barrier_, search_end_barrier_;
};

}  // namespace search

#endif  // INTEGRAL_SEARCH_H_