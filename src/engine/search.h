#ifndef INTEGRAL_SEARCH_H_
#define INTEGRAL_SEARCH_H_

#include "../chess/board.h"
#include "eval.h"
#include "history.h"
#include "time_mgmt.h"

const int kMaxSearchDepth = 100;
const int kScoreNone = -eval::kInfiniteScore;

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
    for (int i = 0; i < pv.Length(); i++) {
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

struct SearchStack {
  // Number of ply from root
  int ply;
  // Evaluation of the position at this ply
  int static_eval;
  // Best moves following down this ply
  PVLine pv;
  // The move with the best score
  Move best_move;
  // Currently searched move at this ply
  Move move;
  // (Colored) piece that is currently being moved
  int moved_piece;

  SearchStack()
      : static_eval(kScoreNone),
        ply(0),
        best_move(Move::NullMove()),
        move(Move::NullMove()),
        moved_piece(PieceType::kNone) {}

  SearchStack *Ahead(int amount = 1) {
    return this + amount;
  }

  SearchStack *Behind(int amount = 1) {
    return this - amount;
  }
};
class Search {
 public:
  explicit Search(Board &board);

  void Start(TimeManagement::Config &time_config);

  void Stop();

  void Bench(int depth);

  const TimeManagement &GetTimeManagement();

  void NewGame();

 private:
  void SetTimeConfig(TimeManagement::Config &time_config);

  template <SearchType type>
  void IterativeDeepening();

  template <NodeType node_type>
  int QuiescentSearch(int ply, int alpha, int beta, SearchStack *stack);

  template <NodeType node_type>
  int PVSearch(int depth, int ply, int alpha, int beta, SearchStack *stack);

 private:
  Board &board_;
  TimeManagement time_mgmt_;
  MoveHistory move_history_;
  std::array<SearchStack, kMaxPlyFromRoot + 1> stack_;
  std::array<std::array<int, kMaxMoves>, kMaxSearchDepth + 1> lmr_table_;
  int sel_depth_;
  std::atomic_bool searching;
};

#endif  // INTEGRAL_SEARCH_H_