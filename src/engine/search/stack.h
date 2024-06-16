#ifndef INTEGRAL_STACK_H
#define INTEGRAL_STACK_H

#include "../../chess/move_gen.h"
#include "../../utils/types.h"

struct SearchStackEntry {
  // Number of ply from root
  U16 ply;
  // Evaluation of the position at this ply
  Score static_eval;
  // Best moves following down this ply
  MoveList pv;
  // The move with the best score
  Move best_move;
  // Currently searched move at this ply
  Move move;
  // Continuation history entry for this move
  void *continuation_entry;
  // Moves that caused a beta cutoff at this ply
  std::array<Move, 2> killer_moves;

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
        killer_moves({}),
        continuation_entry(nullptr) {
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
    for (std::size_t i = 0; i < stack_.size(); i++) {
      stack_[i] = SearchStackEntry(std::max<std::size_t>(0, i - kPadding));
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