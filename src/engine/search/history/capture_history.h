#ifndef INTEGRAL_CAPTURE_HISTORY_H
#define INTEGRAL_CAPTURE_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class CaptureHistory {
 public:
  CaptureHistory() : table_({}) {}

  void UpdateScore(const BoardState &state, StackEntry *stack, int depth) {
    const int bonus = HistoryBonus(depth);
    // Apply a linear dampening to the bonus as the depth increases
    int &score = table_[state.turn][stack->move.GetFrom()][stack->move.GetTo()];
    score += ScaleBonus(score, bonus);
  }

  void Penalize(const BoardState &state, int depth, MoveList &captures) {
    const int bonus = HistoryBonus(depth);
    // Lower the score of the capture moves that failed to raise alpha
    for (int i = 0; i < captures.Size(); i++) {
      const Move bad_capture = captures[i];
      // Apply a linear dampening to the penalty as the depth increases
      int &bad_capture_score =
          table_[state.turn][bad_capture.GetFrom()][bad_capture.GetTo()];
      bad_capture_score += ScaleBonus(bad_capture_score, -bonus);
    }
  }

  [[nodiscard]] int GetScore(const BoardState &state, Move move) const {
    return table_[state.turn][move.GetFrom()][move.GetTo()];
  }

 private:
  MultiArray<int, kNumColors, kSquareCount, kSquareCount> table_;
};

}  // namespace search::history

#endif  // INTEGRAL_CAPTURE_HISTORY_H