#ifndef INTEGRAL_CAPTURE_HISTORY_H
#define INTEGRAL_CAPTURE_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class CaptureHistory {
 public:
  CaptureHistory() : table_({}) {}

  void UpdateScore(const BoardState &state,
                   Move move,
                   I16 depth,
                   StackEntry *stack) {
    const I16 bonus = HistoryBonus(depth);
    const auto from = move.GetFrom(), to = move.GetTo();
    const auto captured =
        move.IsEnPassant(state) ? kPawn : state.GetPieceType(to);
    // Apply a linear dampening to the bonus as the depth increases
    I16 &score = table_[state.turn][state.GetPieceType(from)][to][captured]
                       [stack->threats.IsSet(to)];
    score += ScaleBonus(score, bonus);
  }

  void Penalize(const BoardState &state,
                I16 depth,
                MoveList &captures,
                StackEntry *stack) {
    const I16 penalty = HistoryPenalty(depth);
    // Lower the score of the capture moves that failed to raise alpha
    for (I16 i = 0; i < captures.Size(); i++) {
      const Move bad_capture = captures[i];
      const auto from = bad_capture.GetFrom(), to = bad_capture.GetTo();
      const auto captured =
          bad_capture.IsEnPassant(state) ? kPawn : state.GetPieceType(to);
      // Apply a linear dampening to the penalty as the depth increases
      I16 &bad_capture_score = table_[state.turn][state.GetPieceType(from)][to]
                                     [captured][stack->threats.IsSet(to)];
      bad_capture_score += ScaleBonus(bad_capture_score, penalty);
    }
  }

  [[nodiscard]] I16 GetScore(const BoardState &state,
                             Move move,
                             StackEntry *stack) const {
    const auto from = move.GetFrom(), to = move.GetTo();
    const auto captured =
        move.IsEnPassant(state) ? kPawn : state.GetPieceType(to);
    return table_[state.turn][state.GetPieceType(from)][to][captured]
                 [stack->threats.IsSet(to)];
  }

 private:
  MultiArray<I16, kNumColors, kNumPieceTypes, kSquareCount, kNumPieceTypes, 2>
      table_;
};

}  // namespace search::history

#endif  // INTEGRAL_CAPTURE_HISTORY_H