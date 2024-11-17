#ifndef INTEGRAL_SEARCH_H_
#define INTEGRAL_SEARCH_H_

#include <thread>

#include "../../chess/move_gen.h"
#include "../../utils/barrier.h"
#include "../evaluation/evaluation.h"
#include "../evaluation/nnue/accumulator.h"
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

struct RootMove {
  Move move;
  Score score;
  PVLine pv;

  RootMove(Move move, Score score) : move(move), score(score), pv({}) {}
  RootMove() = default;
};

class RootMoveList {
 public:
  explicit RootMoveList(Board &board) {
    auto move_list = move_gen::GenerateMoves(MoveGenType::kAll, board);
    for (int i = 0; i < move_list.Size(); i++) {
      const auto move = move_list[i];
      if (board.IsMoveLegal(move)) {
        list_.Push({move, 0});
      }
    }
  }

  RootMoveList() = default;

  void SortNextMove(int idx) {
    for (int i = idx; i < Size(); ++i) {
      int best_idx = i;

      for (int j = i + 1; j < Size(); ++j) {
        if (list_[j].score > list_[best_idx].score) {
          best_idx = j;
        }
      }

      std::swap(list_[best_idx], list_[i]);
    }
  }

  [[nodiscard]] bool MoveExists(Move move, int pv_move_idx) const {
    for (int i = pv_move_idx; i < Size(); ++i) {
      if (list_[i].move == move) {
        return true;
      }
    }
    return false;
  }

  [[nodiscard]] RootMove *FindRootMove(Move move) {
    for (int i = 0; i < Size(); ++i) {
      if (list_[i].move == move) {
        return &list_[i];
      }
    }
    return nullptr;
  }

  inline RootMove &operator[](int i) {
    assert(i >= 0 && i < count_);
    return list_[i];
  }

  [[nodiscard]] inline int Size() const {
    return list_.Size();
  }

 private:
  List<RootMove, 256> list_;
};

struct Thread {
  explicit Thread(U32 id)
      : id(id),
        stack({}),
        previous_score(kScoreNone),
        nodes_searched(0),
        sel_depth(0),
        tb_hits(0) {
    NewGame();
  }

  void NewGame() {
    history.Clear();
    stack.Reset();
    previous_score = kScoreNone;
  }

  [[nodiscard]] bool IsMainThread() const {
    return id == 0;
  }

  void SetBoard(Board &new_board) {
    board = new_board;
    board.GetAccumulator()->SetFromState(board.GetState());
  }

  void Reset() {
    stack.Reset();
    scores.fill(kScoreNone);

    // Reset info data
    nodes_searched = 0;
    sel_depth = 0;
    tb_hits = 0;
  }

  std::thread raw_thread;
  U32 id;
  Board board;
  history::History history;
  Stack stack;
  U64 nodes_searched;
  std::array<Score, kMaxSearchDepth + 1> scores;
  Score previous_score;
  U16 root_depth, sel_depth;
  U64 tb_hits;
  int pv_move_idx;
  RootMoveList root_moves;
};

class Search {
 public:
  explicit Search(Board &board);

  ~Search();

  void Start(TimeConfig time_config);

  std::pair<Score, Move> DataGenStart(std::unique_ptr<Thread> &thread,
                                      TimeConfig time_config);

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