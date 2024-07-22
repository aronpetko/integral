#ifndef INTEGRAL_QUIET_HISTORY_H
#define INTEGRAL_QUIET_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace history {

class QuietHistory {
 public:
  explicit QuietHistory(const BoardState &state) : state_(state), table_({}) {}

  void UpdateScore(SearchStackEntry *stack, int depth, MoveList &quiets) {
    const Color turn = state_.turn;
    const Move move = stack->move;

    const int bonus = HistoryBonus(depth);

    // Apply a linear dampening to the bonus as the depth increases
    int &score = table_[turn][move.GetFrom()][move.GetTo()][IsThreatened(move)];
    score += ScaleBonus(score, bonus);

    // Lower the score of the quiet moves that failed to raise alpha (gravity)
    for (int i = 0; i < quiets.Size(); i++) {
      const Move bad_quiet = quiets[i];
      // Apply a linear dampening to the penalty as the depth increases
      int &bad_quiet_score = table_[turn][bad_quiet.GetFrom()]
                                   [bad_quiet.GetTo()][IsThreatened(bad_quiet)];
      bad_quiet_score += ScaleBonus(bad_quiet_score, -bonus);
    }
  }

  [[nodiscard]] int GetScore(Move move) const {
    return table_[state_.turn][move.GetFrom()][move.GetTo()]
                 [IsThreatened(move)];
  }

 private:
  [[nodiscard]] bool IsThreatened(Move move) const {
    return state_.threats.IsSet(move.GetFrom());
  }

 private:
  const BoardState &state_;
  MultiArray<int, kNumColors, kSquareCount, kSquareCount, 2> table_;
};

}  // namespace history

#endif  // INTEGRAL_QUIET_HISTORY_H