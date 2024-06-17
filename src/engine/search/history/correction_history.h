#ifndef INTEGRAL_CORRECTION_HISTORY_H
#define INTEGRAL_CORRECTION_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"

namespace history {

class CorrectionHistory {
 public:
  explicit CorrectionHistory(const BoardState &state)
      : state_(state), table_({}) {}

  static constexpr int kHistorySize = 16384;
  static constexpr int kHistoryMaxBonus = 128;
  static constexpr int kHistoryGravity = 512;

  void UpdateScore(SearchStackEntry *stack,
                   Score search_score,
                   TranspositionTableEntry::Flag score_type,
                   int depth) {
    if (!StaticEvalWithinBounds(stack->static_eval, search_score, score_type)) {
      return;
    }

    const Score static_eval_error = search_score - stack->static_eval;
    const int bonus = std::clamp(static_eval_error * depth / 8,
                                 -kHistoryGravity / 4,
                                 kHistoryGravity / 4);

    // Apply a linear dampening to the bonus as the depth increases
    Score &score = table_[state_.turn][GetTableIndex()];
    score += ScaleBonus(score, bonus, kHistoryGravity);
  }

  [[nodiscard]] Score CorrectedStaticEval() const {
    const Score static_eval = eval::Evaluate(state_);
    const Score correction = table_[state_.turn][GetTableIndex()];
    const Score adjusted_score =
        static_eval + (correction * std::abs(correction)) / kHistorySize;

    // Ensure no static evaluations are mate scores
    return std::clamp(adjusted_score,
                      -kMateScore + kMaxPlyFromRoot + 1,
                      kMateScore - kMaxPlyFromRoot - 1);
  }

 private:
  [[nodiscard]] bool StaticEvalWithinBounds(
      Score static_eval,
      Score search_score,
      TranspositionTableEntry::Flag score_type) const {
    const bool failed_high = score_type == TranspositionTableEntry::kLowerBound;
    const bool failed_low = score_type == TranspositionTableEntry::kUpperBound;
    return !(failed_high && static_eval >= search_score) &&
           !(failed_low && static_eval < search_score);
  }

  [[nodiscard]] int GetTableIndex() const {
    return state_.pawn_key & (kHistorySize - 1);
  }

 private:
  const BoardState &state_;
  MultiArray<Score, kNumColors, kHistorySize> table_;
};

}  // namespace history

#endif  // INTEGRAL_CORRECTION_HISTORY_H