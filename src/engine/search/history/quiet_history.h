#ifndef INTEGRAL_QUIET_HISTORY_H
#define INTEGRAL_QUIET_HISTORY_H

#include "../../../../shared/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

struct QuietHistoryEntry {
  I16 factorizer_score = 0;
  MultiArray<I16, 2, 2> threat_buckets = {};
};

TUNABLE(kQuietHistFactorizerBonusGravity, 3720, 8192, 32768, false);
TUNABLE(kQuietHistBucketBonusGravity, 7441, 8192, 32768, false);

class QuietHistory {
 public:
  QuietHistory() : table_({}) {}

  void UpdateMoveScore(Color turn, Move move, BitBoard threats, I16 bonus) {
    const auto from = move.GetFrom(), to = move.GetTo();
    auto &entry = table_[turn][from][to];

    // Apply a linear dampening to the bonus as the depth increases
    I16 &score = entry.factorizer_score;
    score += ScaleBonus(score, bonus, kQuietHistFactorizerBonusGravity);

    // Also update the appropriate threat bucket
    I16 &bucket = entry.threat_buckets[threats.IsSet(from)][threats.IsSet(to)];
    bucket += ScaleBonus(bucket, bonus, kQuietHistBucketBonusGravity);
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
    const auto from = move.GetFrom(), to = move.GetTo();
    const auto &entry = table_[state.turn][from][to];
    return entry.factorizer_score + entry.threat_buckets[threats.IsSet(from)][threats.IsSet(to)];
  }

 private:
  MultiArray<QuietHistoryEntry, kNumColors, kSquareCount, kSquareCount> table_;
};

}  // namespace search::history

#endif  // INTEGRAL_QUIET_HISTORY_H
