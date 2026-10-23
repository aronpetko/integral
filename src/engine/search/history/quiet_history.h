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

  void UpdateMoveScore(Color turn, Move move, BitBoard threats, I16 bonus) {
    // Apply a linear dampening to the bonus as the depth increases
    I16 &score =
        table_[ThreatIndex(threats)][turn][move.GetFrom()][move.GetTo()];
    score += ScaleBonus(score, bonus);
  }

  void UpdateScore(const BoardState &state,
                   StackEntry *stack,
                   I16 depth,
                   BitBoard threats,
                   MoveList &quiets) {
    const I16 bonus = HistoryBonus(depth);

    // Apply a linear dampening to the bonus as the depth increases
    UpdateMoveScore(state.turn, stack->move, threats, bonus);

    // Lower the score of the quiet moves that failed to raise alpha (gravity)
    const I16 penalty = HistoryPenalty(depth);
    for (int i = 0; i < quiets.Size(); i++) {
      UpdateMoveScore(state.turn, quiets[i], threats, penalty);
    }
  }

  [[nodiscard]] int GetScore(const BoardState &state,
                             Move move,
                             BitBoard threats) const {
    return table_[ThreatIndex(threats)][state.turn][move.GetFrom()]
                 [move.GetTo()];
  }

 private:
  static constexpr std::size_t kNumThreatBuckets = 4096;

  [[nodiscard]] U16 ThreatIndex(BitBoard threats) const {
    return threats.AsU64() & (kNumThreatBuckets - 1);
  }

 private:
  MultiArray<I16, kNumThreatBuckets, kNumColors, kSquareCount, kSquareCount>
      table_;
};

}  // namespace search::history

#endif  // INTEGRAL_QUIET_HISTORY_H