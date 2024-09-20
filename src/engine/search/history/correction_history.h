#ifndef INTEGRAL_CORRECTION_HISTORY_H
#define INTEGRAL_CORRECTION_HISTORY_H

#include "../../../tuner/spsa.h"
#include "../../../utils/multi_array.h"
#include "../stack.h"

namespace search::history {

inline Tunable corr_history_scale("corr_history_scale", 256, 100, 500, 15);
inline Tunable max_corr_hist("max_corr_hist", 64, 16, 128, 6);

class CorrectionHistory {
 public:
  CorrectionHistory()
      : non_pawn_table_({}),
        pawn_table_({}),
        minor_table_({}),
        major_table_({}) {}

  void UpdateScore(const BoardState &state,
                   StackEntry *stack,
                   Score search_score,
                   TranspositionTableEntry::Flag score_type,
                   int depth) {
    if (!IsStaticEvalWithinBounds(
            stack->static_eval, search_score, score_type)) {
      return;
    }

    const int weight = CalculateWeight(depth);
    const Score scaled_bonus =
        CalculateScaledBonus(stack->static_eval, search_score);

    // Update pawn table score
    auto &pawn_table_score = pawn_table_[state.turn][GetPawnTableIndex(state)];
    pawn_table_score = UpdateTableScore(pawn_table_score, weight, scaled_bonus);

    // Update minor piece table score
    auto &minor_table_score =
        minor_table_[state.turn][GetMinorTableIndex(state)];
    minor_table_score =
        UpdateTableScore(minor_table_score, weight, scaled_bonus);

    // Update major piece table score
    auto &major_table_score =
        major_table_[state.turn][GetMajorTableIndex(state)];
    major_table_score =
        UpdateTableScore(major_table_score, weight, scaled_bonus);

    // Update non-pawn table scores for both colors
    for (Color color : {Color::kWhite, Color::kBlack}) {
      auto &non_pawn_table_score =
          non_pawn_table_[state.turn][color]
                         [GetNonPawnTableIndex(state, color)];
      non_pawn_table_score =
          UpdateTableScore(non_pawn_table_score, weight, scaled_bonus);
    }
  }

  [[nodiscard]] Score CorrectStaticEval(const BoardState &state,
                                        Score static_eval) const {
    const Score pawn_correction =
        pawn_table_[state.turn][GetPawnTableIndex(state)];
    const I32 non_pawn_white_correction =
        non_pawn_table_[state.turn][Color::kWhite]
                       [GetNonPawnTableIndex(state, Color::kWhite)];
    const I32 non_pawn_black_correction =
        non_pawn_table_[state.turn][Color::kBlack]
                       [GetNonPawnTableIndex(state, Color::kBlack)];
    const I32 minor_correction =
        minor_table_[state.turn][GetMinorTableIndex(state)];
    const I32 major_correction =
        major_table_[state.turn][GetMajorTableIndex(state)];
    const I32 correction =
        pawn_correction +
        (non_pawn_white_correction + non_pawn_black_correction) / 2 +
        (minor_correction + major_correction) / 2;
    const I32 adjusted_score =
        static_cast<I32>(static_eval) +
        correction / static_cast<int>(corr_history_scale);
    // Ensure no static evaluations are mate scores
    return std::clamp(
        adjusted_score, -kMateInMaxPlyScore + 1, kMateInMaxPlyScore - 1);
  }

 private:
  [[nodiscard]] int CalculateWeight(int depth) {
    return std::min(1 + depth, 16);
  }

  [[nodiscard]] Score CalculateScaledBonus(Score static_eval,
                                           Score search_score) {
    return (search_score - static_eval) * static_cast<int>(corr_history_scale);
  }

  [[nodiscard]] Score UpdateTableScore(Score current_score,
                                       int weight,
                                       Score scaled_bonus) {
    const Score new_score = (current_score * (corr_history_scale - weight) +
                             scaled_bonus * weight) /
                            corr_history_scale;
    return std::clamp<Score>(new_score,
                             corr_history_scale * -max_corr_hist,
                             corr_history_scale * max_corr_hist);
  }

  [[nodiscard]] bool IsStaticEvalWithinBounds(
      Score static_eval,
      Score search_score,
      TranspositionTableEntry::Flag score_type) const {
    const bool failed_high = score_type == TranspositionTableEntry::kLowerBound;
    const bool failed_low = score_type == TranspositionTableEntry::kUpperBound;
    return !(failed_high && static_eval >= search_score) &&
           !(failed_low && static_eval < search_score);
  }

  [[nodiscard]] int GetPawnTableIndex(const BoardState &state) const {
    return state.pawn_key & 16383;
  }

  [[nodiscard]] int GetMinorTableIndex(const BoardState &state) const {
    return state.minor_key & 16383;
  }

  [[nodiscard]] int GetMajorTableIndex(const BoardState &state) const {
    return state.major_key & 16383;
  }

  [[nodiscard]] int GetNonPawnTableIndex(const BoardState &state,
                                         Color color) const {
    return state.non_pawn_keys[color] & 16383;
  }

 private:
  MultiArray<Score, kNumColors, 16384> pawn_table_;
  MultiArray<Score, kNumColors, 16384> minor_table_;
  MultiArray<Score, kNumColors, 16384> major_table_;
  MultiArray<Score, kNumColors, kNumColors, 16384> non_pawn_table_;
};

}  // namespace search::history

#endif  // INTEGRAL_CORRECTION_HISTORY_H