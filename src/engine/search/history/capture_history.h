#ifndef I16EGRAL_CAPTURE_HISTORY_H
#define I16EGRAL_CAPTURE_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class CaptureHistory {
 public:
  CaptureHistory() : table_({}) {}

  void UpdateScore(const BoardState &state, StackEntry *stack, I16 depth) {
    const I16 bonus = HistoryBonus(depth);
    // Apply a linear dampening to the bonus as the depth increases
    I16 &score = table_[stack->move.GetFrom()][stack->move.GetTo()]
                       [state.GetPieceAndColor(stack->move.GetTo())]
                       [stack->threats.IsSet(stack->move.GetTo())];
    score += ScaleBonus(score, bonus);
  }

  void Penalize(const BoardState &state,
                BitBoard threats,
                I16 depth,
                MoveList &captures) {
    const I16 penalty = HistoryPenalty(depth);
    // Lower the score of the capture moves that failed to raise alpha
    for (I16 i = 0; i < captures.Size(); i++) {
      const Move bad_capture = captures[i];
      // Apply a linear dampening to the penalty as the depth increases
      I16 &bad_capture_score =
          table_[bad_capture.GetFrom()][bad_capture.GetTo()]
                [state.GetPieceAndColor(bad_capture.GetTo())]
                [threats.IsSet(bad_capture.GetTo())];
      bad_capture_score += ScaleBonus(bad_capture_score, penalty);
    }
  }

  [[nodiscard]] I16 GetScore(const BoardState &state,
                             Move move,
                             BitBoard threats) const {
    return table_[move.GetFrom()][move.GetTo()][state.GetPieceAndColor(
        move.GetTo())][threats.IsSet(move.GetTo())];
  }

 private:
  MultiArray<I16, kSquareCount, kSquareCount, kNumPieceTypes * 2, 2> table_;
};

}  // namespace search::history

#endif  // I16EGRAL_CAPTURE_HISTORY_H