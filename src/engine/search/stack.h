#ifndef INTEGRAL_STACK_H
#define INTEGRAL_STACK_H

#include "../../chess/move_gen.h"
#include "../../utils/types.h"

struct PVLine {
 public:
  PVLine() : moves_({}) {
    Clear();
  }

  Move &operator[](std::size_t i) {
    return moves_[i];
  }

  void Clear() {
    moves_.Clear();
  }

  void Push(const Move &move) {
    moves_.Push(move);
  }

  void AppendPV(PVLine &pv) {
    for (std::size_t i = 0; i < pv.Length(); i++) {
      Push(pv[i]);
    }
  }

  [[nodiscard]] std::size_t Length() const {
    return moves_.Size();
  }

  [[nodiscard]] std::string UCIFormat() {
    std::string str;
    for (int i = 0; i < moves_.Size(); i++) {
      str += moves_[i].ToString();
      if (i < moves_.Size() - 1) str += ' ';
    }
    return str;
  }

  friend std::ostream &operator<<(std::ostream &stream, PVLine &pv_line) {
    return stream << pv_line.UCIFormat();
  }

 private:
  List<Move, kMaxPlyFromRoot> moves_;
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
  // The excluded TT move when performing singular extensions
  Move excluded_tt_move;
  // Continuation history entry for this move
  void *continuation_entry;
  // Moves that caused a beta cutoff at this ply
  std::array<Move, 2> killer_moves;
  // Overall improving rate from the last couple plies
  double improving_rate;

  void AddKillerMove(Move killer_move) {
    // Ensure we don't have duplicate killer moves
    if (killer_move != killer_moves.front()) {
      killer_moves[1] = killer_moves[0];
      killer_moves[0] = killer_move;
    }
  }

  void ClearKillerMoves() {
    killer_moves.fill(Move::NullMove());
  }

  explicit SearchStackEntry(U16 ply)
      : ply(ply),
        static_eval(kScoreNone),
        best_move(Move::NullMove()),
        move(Move::NullMove()),
        excluded_tt_move(Move::NullMove()),
        killer_moves({}),
        continuation_entry(nullptr),
        improving_rate(kScoreNone) {
    ClearKillerMoves();
  }

  SearchStackEntry() : SearchStackEntry(0) {}
};

class SearchStack {
 public:
  static constexpr int kPadding = 4;

  SearchStack() {
    Reset();
  }

  void Reset() {
    for (int i = 0; i < stack_.size(); i++) {
      stack_[i] = SearchStackEntry(i - kPadding);
    }
  }

  [[nodiscard]] SearchStackEntry &Front() {
    return stack_[kPadding];
  }

  [[nodiscard]] SearchStackEntry &operator[](int idx) {
    return stack_[idx + kPadding];
  }

 private:
  std::array<SearchStackEntry, kMaxPlyFromRoot + kPadding> stack_;
};

#endif  // INTEGRAL_STACK_H