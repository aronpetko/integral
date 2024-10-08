#ifndef INTEGRAL_PRUNE_HISTORY_H
#define INTEGRAL_PRUNE_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class PruneHistory {
 public:
  PruneHistory() : table_({}) {}

  void UpdateMoveScore(const BoardState &state,
                       Color turn,
                       Move move,
                       int bonus) {
    // Apply a linear dampening to the bonus as the depth increases
    int &score =
        table_[turn][move.IsCapture(state)][move.GetFrom()][move.GetTo()];
    score += ScaleBonus(score, bonus);
  }

  [[nodiscard]] int GetScore(const BoardState &state, Move move) const {
    return table_[state.turn][move.IsCapture(state)][move.GetFrom()]
                 [move.GetTo()];
  }

 private:
  MultiArray<int, kNumColors, 2, kSquareCount, kSquareCount> table_;
};

}  // namespace search::history

#endif  // INTEGRAL_PRUNE_HISTORY_H