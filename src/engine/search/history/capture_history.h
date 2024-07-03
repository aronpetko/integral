#ifndef INTEGRAL_CAPTURE_HISTORY_H
#define INTEGRAL_CAPTURE_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace history {

class CaptureHistory {
 public:
  explicit CaptureHistory(const BoardState &state)
      : state_(state), table_({}) {}

  void UpdateScore(SearchStackEntry *stack, int depth) {
    const int bonus = HistoryBonus(depth);
    // Apply a linear dampening to the bonus as the depth increases
    int &score =
        table_[state_.turn][stack->move.GetFrom()][stack->move.GetTo()];
    score += ScaleBonus(score, bonus);
  }

  void Penalize(int depth, MoveList &captures) {
    const int bonus = HistoryBonus(depth);
    // Lower the score of the capture moves that failed to raise alpha
    for (int i = 0; i < captures.Size(); i++) {
      const Move bad_capture = captures[i];
      // Apply a linear dampening to the penalty as the depth increases
      int &bad_capture_score =
          table_[state_.turn][bad_capture.GetFrom()][bad_capture.GetTo()];
      bad_capture_score += ScaleBonus(bad_capture_score, -bonus);
    }
  }

  [[nodiscard]] int GetScore(Move move) const {
    return table_[state_.turn][move.GetFrom()][move.GetTo()];
  }

 private:
  const BoardState &state_;
  MultiArray<int, kNumColors, kSquareCount, kSquareCount> table_;
};

}  // namespace history

#endif  // INTEGRAL_CAPTURE_HISTORY_H