#ifndef INTEGRAL_PAWN_HISTORY_H
#define INTEGRAL_PAWN_HISTORY_H

#include "../../../../shared/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

TUNABLE(kPawnHistFill, -967, -3000, 0, false);

class PawnHistory {
 public:
  PawnHistory() {
    Clear();
  }

  void Clear() {
    table_.fill(static_cast<I16>(kPawnHistFill));
  }

  void Update(const BoardState &state, Move move, I16 bonus) {
    I16 &score = table_[GetIndex(state)][state.turn]
                       [state.GetPieceType(move.GetFrom())][move.GetTo()];
    score += ScaleBonus(score, bonus);
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
