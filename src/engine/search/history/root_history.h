#ifndef INTEGRAL_ROOT_HISTORY_H
#define INTEGRAL_ROOT_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class RootHistory {
 public:
  RootHistory() : table_({}) {}

  void Clear() {
    table_ = {};
  }

  void UpdateMoveScore(Color turn, Move move, int bonus) {
    // Apply a linear dampening to the bonus as the depth increases
    int &score = table_[turn][move.GetFrom()][move.GetTo()];
    score += ScaleBonus(score, bonus);
  }

  void UpdateScore(const BoardState &state,
                   StackEntry *stack,
                   int depth,
                   MoveList &quiets) {
    const int bonus = HistoryBonus(depth);

    // Apply a linear dampening to the bonus as the depth increases
    UpdateMoveScore(state.turn, stack->move, bonus);

    // Lower the score of the quiet moves that failed to raise alpha (gravity)
    for (int i = 0; i < quiets.Size(); i++) {
      UpdateMoveScore(state.turn, quiets[i], -bonus);
    }
  }

  [[nodiscard]] int GetScore(const BoardState &state, Move move) const {
    return table_[state.turn][move.GetFrom()][move.GetTo()];
  }

 private:
  MultiArray<int, kNumColors, kSquareCount, kSquareCount> table_;
};

}  // namespace search::history

#endif  // INTEGRAL_ROOT_HISTORY_H