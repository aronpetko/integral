#ifndef INTEGRAL_CORRECTION_HISTORY_H
#define INTEGRAL_CORRECTION_HISTORY_H

#include "../../../tuner/spsa.h"
#include "../../../utils/multi_array.h"
#include "../stack.h"

namespace history {

inline Tunable corr_history_size("corr_history_size", 16384, 8192, 32768, 1024);
inline Tunable corr_history_max_bonus(
    "corr_history_max_bonus", 128, 64, 256, 8);
inline Tunable corr_history_gravity("corr_history_gravity", 512, 256, 1024, 32);

class CorrectionHistory {
 public:
  explicit CorrectionHistory(const BoardState &state)
      : state_(state), table_({}) {}

  void UpdateScore(SearchStackEntry *stack,
                   Score search_score,
                   TranspositionTableEntry::Flag score_type,
                   int depth) {
    if (!StaticEvalWithinBounds(stack->static_eval, search_score, score_type)) {
      return;
    }

    const Score static_eval_error = search_score - stack->static_eval;
    const int bonus = std::clamp(static_eval_error * depth / 8,
                                 -static_cast<int>(corr_history_gravity) / 4,
                                 static_cast<int>(corr_history_gravity) / 4);

    // Apply a linear dampening to the bonus as the depth increases
    Score &score = table_[state_.turn][GetTableIndex()];
    score += ScaleBonus(score, bonus, corr_history_gravity);
  }

  [[nodiscard]] Score CorrectedStaticEval() const {
    const Score static_eval = eval::Evaluate(state_);
    const Score correction = table_[state_.turn][GetTableIndex()];
    const Score adjusted_score =
        static_eval + (correction * std::abs(correction)) / corr_history_size;

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
    return state_.pawn_key & (static_cast<int>(corr_history_size) - 1);
  }

 private:
  const BoardState &state_;
  MultiArray<Score, kNumColors, 16384>
      table_;  // Keep the size fixed for the MultiArray
};

}  // namespace history

#endif  // INTEGRAL_CORRECTION_HISTORY_H