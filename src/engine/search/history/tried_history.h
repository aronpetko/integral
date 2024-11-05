#ifndef INTEGRAL_TRIED_HISTORY_H
#define INTEGRAL_TRIED_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class TriedHistory {
 public:
  TriedHistory() : table_({}) {}

  void SetTriedScore(Color turn, Move move, int num_tried) {
    table_[turn][move.GetFrom()][move.GetTo()] = num_tried;
  }

  [[nodiscard]] int GetScore(const BoardState &state, Move move) const {
    return table_[state.turn][move.GetFrom()][move.GetTo()];
  }

 private:
  MultiArray<int, kNumColors, kSquareCount, kSquareCount> table_;
};

}  // namespace search::history

#endif  // INTEGRAL_TRIED_HISTORY_H