#ifndef INTEGRAL_PAWN_HISTORY_H
#define INTEGRAL_PAWN_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class PawnHistory {
 public:
  PawnHistory() : table_({}) {
    table_.fill(-1000);
  }

  void UpdateMoveScore(const BoardState &state, Move move, I16 bonus) {
    // Apply a linear dampening to the bonus as the depth increases
    I16 &score = table_[GetIndex(state)][state.turn]
                       [state.GetPieceType(move.GetFrom())][move.GetTo()];
    score += ScaleBonus(score, bonus);
  }

  void UpdateScore(const BoardState &state,
                   StackEntry *stack,
                   I16 depth,
                   MoveList &quiets) {
    const I16 bonus = HistoryBonus(depth);

    // Apply a linear dampening to the bonus as the depth increases
    UpdateMoveScore(state, stack->move, bonus);

    // Lower the score of the quiet moves that failed to raise alpha (gravity)
    const I16 penalty = HistoryPenalty(depth);
    for (int i = 0; i < quiets.Size(); i++) {
      UpdateMoveScore(state, quiets[i], penalty);
    }
  }

  [[nodiscard]] int GetScore(const BoardState &state, Move move) const {
    return table_[GetIndex(state)][state.turn]
                 [state.GetPieceType(move.GetFrom())][move.GetTo()];
  }

 private:
  [[nodiscard]] int GetIndex(const BoardState &state) const {
    return state.pawn_key & 16383;
  }

 private:
  MultiArray<I16, 16384, kNumColors, kNumPieceTypes, kSquareCount> table_;
};

}  // namespace search::history

#endif  // INTEGRAL_PAWN_HISTORY_H
