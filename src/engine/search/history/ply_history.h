#ifndef INTEGRAL_PLY_HISTORY_H
#define INTEGRAL_PLY_HISTORY_H

#include "../../../utils/types.h"

namespace search::history {

class PlyHistory {
  static constexpr int kPlyWindow = 8;

 public:
  PlyHistory() : table_({}) {}

  void Clear() {
    table_.fill(0);
  }

  void UpdateMoveScore(Move move, int ply, I16 bonus) {
    // Apply a linear dampening to the bonus as the depth increases
    I16 &score = table_[ply / kPlyWindow][move.GetFrom()][move.GetTo()];
    score += ScaleBonus(score, bonus);
  }

  void UpdateScore(const BoardState &state,
                   StackEntry *stack,
                   I16 depth,
                   MoveList &quiets) {
    const I16 bonus = HistoryBonus(depth);

    // Apply a linear dampening to the bonus as the depth increases
    UpdateMoveScore(stack->move, stack->ply, bonus);

    // Lower the score of the quiet moves that failed to raise alpha (gravity)
    const I16 penalty = HistoryPenalty(depth);
    for (int i = 0; i < quiets.Size(); i++) {
      UpdateMoveScore(quiets[i], stack->ply, penalty);
    }
  }

  [[nodiscard]] int GetScore(const BoardState &state,
                             Move move,
                             int ply) const {
    return table_[ply / kPlyWindow][move.GetFrom()][move.GetTo()];
  }

 private:
  MultiArray<I16, kMaxGamePly / kPlyWindow, kSquareCount, kSquareCount> table_;
};

}  // namespace search::history

#endif  // INTEGRAL_PLY_HISTORY_H
