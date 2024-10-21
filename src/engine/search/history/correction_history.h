#ifndef INTEGRAL_CORRECTION_HISTORY_H
#define INTEGRAL_CORRECTION_HISTORY_H

#include "../../../tuner/spsa.h"
#include "../../../utils/multi_array.h"
#include "../stack.h"

namespace search::history {

TUNABLE(kPawnCorrectionWeight, 53, 0, 300, false);
TUNABLE(kNonPawnCorrectionWeight, 53, 0, 300, false);
TUNABLE(kMinorCorrectionWeight, 53, 0, 300, false);
TUNABLE(kMajorCorrectionWeight, 53, 0, 300, false);
TUNABLE(kContinuationCorrectionWeight, 53, 0, 300, false);
TUNABLE(kCorrectionHistoryGravity, 1024, 512, 8192, false);

class CorrectionHistory {
 public:
  CorrectionHistory()
      : non_pawn_table_({}),
        pawn_table_({}),
        minor_table_({}),
        major_table_({}),
        continuation_table_({}) {}

  void UpdateScore(const BoardState &state,
                   StackEntry *stack,
                   Score search_score,
                   Score raw_static_eval,
                   TranspositionTableEntry::Flag score_type,
                   int depth) {
    if (!IsStaticEvalWithinBounds(raw_static_eval, search_score, score_type)) {
      return;
    }

    const auto bonus =
        std::clamp((search_score - raw_static_eval) * depth / 8, -256, 256);

    // Update pawn table score
    auto &pawn_table_score = pawn_table_[state.turn][GetPawnTableIndex(state)];
    pawn_table_score = UpdateTableScore(pawn_table_score, bonus);

    // Update minor piece table score
    auto &minor_table_score =
        minor_table_[state.turn][GetMinorTableIndex(state)];
    minor_table_score = UpdateTableScore(minor_table_score, bonus);

    // Update major piece table score
    auto &major_table_score =
        major_table_[state.turn][GetMajorTableIndex(state)];
    major_table_score = UpdateTableScore(major_table_score, bonus);

    // Update non-pawn table scores for both colors
    for (Color color : {Color::kWhite, Color::kBlack}) {
      auto &non_pawn_table_score =
          non_pawn_table_[state.turn][color]
                         [GetNonPawnTableIndex(state, color)];
      non_pawn_table_score = UpdateTableScore(non_pawn_table_score, bonus);
    }

    // Update continuation table scores
    if (stack->ply >= 2 && (stack - 1)->move && (stack - 2)->move) {
      auto &continuation_table_score =
          continuation_table_[state.turn][(stack - 2)->moved_piece]
                             [(stack - 2)->move.GetTo()]
                             [(stack - 1)->moved_piece]
                             [(stack - 1)->move.GetTo()];
      continuation_table_score =
          UpdateTableScore(continuation_table_score, bonus);
    }
  }

  [[nodiscard]] Score CorrectStaticEval(const BoardState &state,
                                        StackEntry *stack,
                                        Score static_eval) const {
    const Score pawn_correction =
        kPawnCorrectionWeight *
        pawn_table_[state.turn][GetPawnTableIndex(state)];
    const I32 non_pawn_correction =
        kNonPawnCorrectionWeight *
        (non_pawn_table_[state.turn][Color::kWhite]
                        [GetNonPawnTableIndex(state, Color::kWhite)] +
         non_pawn_table_[state.turn][Color::kBlack]
                        [GetNonPawnTableIndex(state, Color::kBlack)]) /
        2;
    const I32 minor_correction =
        kMinorCorrectionWeight *
        minor_table_[state.turn][GetMinorTableIndex(state)];
    const I32 major_correction =
        kMajorCorrectionWeight *
        major_table_[state.turn][GetMajorTableIndex(state)];
    const I32 continuation_correction = [&]() -> I32 {
      if (stack->ply >= 2 && (stack - 1)->move && (stack - 2)->move) {
        return kContinuationCorrectionWeight *
               continuation_table_[state.turn][(stack - 2)->moved_piece]
                                  [(stack - 2)->move.GetTo()]
                                  [(stack - 1)->moved_piece]
                                  [(stack - 1)->move.GetTo()];
      }
      return 0;
    }();
    const I32 correction = pawn_correction + non_pawn_correction +
                           minor_correction + major_correction +
                           continuation_correction;
    const I32 adjusted_score = static_cast<I32>(static_eval) + correction / 1024;
    // Ensure no static evaluations are mate scores
    return std::clamp(
        adjusted_score, -kMateInMaxPlyScore + 1, kMateInMaxPlyScore - 1);
  }

 private:
  [[nodiscard]] static Score UpdateTableScore(Score current_score,
                                              Score bonus) {
    return current_score +
           history::ScaleBonus(current_score, bonus, kCorrectionHistoryGravity);
  }

  [[nodiscard]] static bool IsStaticEvalWithinBounds(
      Score static_eval,
      Score search_score,
      TranspositionTableEntry::Flag score_type) {
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
  MultiArray<Score, 2, kNumPieceTypes, 64, kNumPieceTypes, 64>
      continuation_table_;
};

}  // namespace search::history

#endif  // INTEGRAL_CORRECTION_HISTORY_H