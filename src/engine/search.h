#ifndef INTEGRAL_SEARCH_H_
#define INTEGRAL_SEARCH_H_

#include "../chess/board.h"
#include "eval.h"
#include "history.h"
#include "time_mgmt.h"

constexpr int kMaxSearchDepth = 100;

struct PVLine {
 public:
  PVLine() : moves_({}) {
    Clear();
  }

  Move &operator[](int i) {
    return moves_[i];
  }

  void Clear() {
    moves_.Clear();
  }

  void Push(const Move &move) {
    moves_.Push(move);
  }

  void CopyOver(PVLine &pv) {
    for (std::size_t i = 0; i < pv.Length(); i++) {
      Push(pv[i]);
    }
  }

  [[nodiscard]] std::size_t Length() const {
    return moves_.Size();
  }

  [[nodiscard]] std::string ToString() {
    std::string str;
    for (int i = 0; i < moves_.Size(); i++) {
      str += moves_[i].ToString();
      if (i < moves_.Size() - 1) str += ' ';
    }
    return str;
  }

  friend std::ostream &operator<<(std::ostream &stream, PVLine &pv_line) {
    return stream << pv_line.ToString();
  }

 private:
  List<Move, kMaxPlyFromRoot> moves_;
};

enum class NodeType {
  kPV,
  kNonPV
};

enum class SearchType {
  kRegular,
  kBench
};

struct SearchStackEntry {
  // Number of ply from root
  U16 ply;
  // Evaluation of the position at this ply
  Score static_eval;
  // Best moves following down this ply
  PVLine pv;
  // The move with the best score
  Move best_move;
  // Currently searched move at this ply
  Move move;
  // Continuation history entry of the current move
  ContinuationEntry *cont_entry;

  SearchStackEntry() : SearchStackEntry(0) {}

  explicit SearchStackEntry(U16 ply)
      : ply(ply),
        static_eval(kScoreNone),
        best_move(Move::NullMove()),
        move(Move::NullMove()),
        cont_entry(nullptr) {}
};

class SearchStack {
 public:
  static constexpr int kPadding = 4;

  SearchStack() {
    Reset();
  }

  void Reset() {
    for (std::size_t i = 0; i < stack_.size(); i++) {
      stack_[i] = SearchStackEntry(std::max<std::size_t>(0, i - kPadding));
    }
  }

  SearchStackEntry &Front() {
    return stack_[kPadding];
  }

  constexpr SearchStackEntry &operator[](int idx) {
    return stack_[idx + kPadding];
  }

 private:
  std::array<SearchStackEntry, kMaxPlyFromRoot + 4> stack_;
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
  [[nodiscard]] bool ShouldQuit();

  template <SearchType type>
  void IterativeDeepening();

  template <NodeType node_type>
  Score QuiescentSearch(Score alpha, Score beta, SearchStackEntry *stack);

  template <NodeType node_type>
  Score PVSearch(int depth, Score alpha, Score beta, SearchStackEntry *stack);

 private:
  Board &board_;
  TimeManagement time_mgmt_;
  MoveHistory move_history_;
  SearchStack search_stack_;
  std::array<std::array<int, kMaxMoves>, kMaxSearchDepth + 1> lmr_table_;
  U16 sel_depth_;
  U64 nodes_searched_;
  std::atomic_bool searching_;
};

#endif  // INTEGRAL_SEARCH_H_