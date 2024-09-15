#ifndef INTEGRAL_ROOT_HISTORY_H
#define INTEGRAL_ROOT_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class RootHistory {
 public:
  RootHistory() : table_({}) {}

  void UpdateScore(Color turn, Move move) {
    const int bonus = HistoryBonus(move);
    // Apply a linear dampening to the bonus as the depth increases
    int &score = table_[turn][move.GetFrom()][move.GetTo()];
    score += ScaleBonus(score, bonus);
  }

  [[nodiscard]] int GetScore(const BoardState &state, Move move) const {
    return table_[state.turn][move.GetFrom()][move.GetTo()];
  }

 private:
 private:
  MultiArray<int, kNumColors, kSquareCount, kSquareCount> table_;
};

}  // namespace search::history

#endif  // INTEGRAL_ROOT_HISTORY_H