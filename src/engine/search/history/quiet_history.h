#ifndef INTEGRAL_QUIET_HISTORY_H
#define INTEGRAL_QUIET_HISTORY_H

#include "../../../../shared/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

class QuietHistory {
 public:
  QuietHistory() : table_({}) {}

  void Clear() {
    table_.fill(I16{0});
  }

  void UpdateMoveScore(const BoardState &state, Move move, I16 bonus) {
    // Apply a linear dampening to the bonus as the depth increases
    I16 &score = table_[ThreatIndex(state, move)][state.turn][move.GetFrom()]
                       [move.GetTo()];
    score += ScaleBonus(score, bonus);
  }

  void UpdateScore(const BoardState &state,
                   StackEntry *stack,
                   I16 depth,
                   MoveList &quiets) {
    const I16 bonus = HistoryBonus(depth);

    // Apply a linear dampening to the bonus as the depth increases
    UpdateMoveScore(state, stack->move, bonus);

    // Lower the score of the quiet moves that failed to raise alpha (gravity)
    const I16 penalty = HistoryPenalty(depth);
    for (int i = 0; i < quiets.Size(); i++) {
      UpdateMoveScore(state, quiets[i], penalty);
    }
  }

  [[nodiscard]] int GetScore(const BoardState &state, Move move) const {
    return table_[ThreatIndex(state, move)][state.turn][move.GetFrom()]
                 [move.GetTo()];
  }

 private:
  [[nodiscard]] static U8 ThreatIndex(const BoardState &state, Move move) {
    // Whether the move leaves or enters an attacked square
    const U8 move_mask = state.threats.IsSet(move.GetFrom()) << 1 |
                         state.threats.IsSet(move.GetTo());

    return state.threatened_piece_types << 2 | move_mask;
  }

  static constexpr std::size_t kNumThreatBuckets = 128;

 private:
  MultiArray<I16, kNumThreatBuckets, kNumColors, kSquareCount, kSquareCount>
      table_;
};

}  // namespace search::history

#endif  // INTEGRAL_QUIET_HISTORY_H