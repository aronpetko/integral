#ifndef INTEGRAL_CORRECTION_HISTORY_H
#define INTEGRAL_CORRECTION_HISTORY_H

#include "../../../../shared/multi_array.h"
#include "../../../tuner/spsa.h"
#include "../stack.h"

namespace search::history {

TUNABLE_STEP(kPawnCorrectionWeight, 41, 0, 125, false, 3);
TUNABLE_STEP(kNonPawnCorrectionWeight, 38, 0, 125, false, 3);
TUNABLE_STEP(kMajorCorrectionWeight, 41, 0, 125, false, 3);
TUNABLE_STEP(kContinuationCorrectionWeight, 52, 0, 125, false, 3);

class CorrectionHistory {
 public:
  CorrectionHistory()
      : non_pawn_table_({}),
        pawn_table_({}),
        major_table_({}),
        continuation_table_({}) {}

  void UpdateScore(const BoardState &state,
                   StackEntry *stack,
                   Score search_score,
                   TranspositionTableEntry::Flag score_type,
                   int depth) {
    if (!IsStaticEvalWithinBounds(
            stack->static_eval, search_score, score_type)) {
      return;
    }

    const I16 bonus = CalculateBonus(stack->static_eval, search_score, depth);

    // Update pawn table score
    UpdateTableScore(pawn_table_[GetPawnTableIndex(state)][state.turn], bonus);

    // Update major piece table score
    UpdateTableScore(major_table_[GetMajorTableIndex(state)][state.turn],
                     bonus);

    // Update non-pawn table scores for both colors
    for (Color color : {Color::kWhite, Color::kBlack}) {
      UpdateTableScore(non_pawn_table_[GetNonPawnTableIndex(state, color)]
                                      [state.turn][color],
                       bonus);
    }

    // Update continuation table scores
    for (int ply_ago : {2, 3}) {
      if (stack->ply >= ply_ago && (stack - ply_ago)->move &&
          (stack - 1)->move) {
        auto &table = *(stack - ply_ago)->continuation_correction_entry;
        UpdateTableScore(table[FlipColor(state.turn)][(stack - 1)->moved_piece]
                              [(stack - 1)->move.GetTo()],
                         bonus);
      }
    }
  }

  [[nodiscard]] Score CorrectStaticEval(const BoardState &state,
                                        StackEntry *stack,
                                        Score static_eval) const {
    const Score pawn_correction =
        pawn_table_[GetPawnTableIndex(state)][state.turn] *
        kPawnCorrectionWeight;
    const I32 non_pawn_white_correction =
        non_pawn_table_[GetNonPawnTableIndex(state, Color::kWhite)][state.turn]
                       [Color::kWhite] *
        kNonPawnCorrectionWeight;
    const I32 non_pawn_black_correction =
        non_pawn_table_[GetNonPawnTableIndex(state, Color::kBlack)][state.turn]
                       [Color::kBlack] *
        kNonPawnCorrectionWeight;
    const I32 major_correction =
        major_table_[GetMajorTableIndex(state)][state.turn] *
        kMajorCorrectionWeight;
    const I32 continuation_correction = [&]() -> I32 {
      Score total = 0;

      for (int ply_ago : {2, 3}) {
        if (stack->ply >= ply_ago && (stack - ply_ago)->move &&
            (stack - 1)->move) {
          auto &table = *(stack - ply_ago)->continuation_correction_entry;
          total += table[FlipColor(state.turn)][(stack - 1)->moved_piece]
                        [(stack - 1)->move.GetTo()] *
                   kContinuationCorrectionWeight;
        }
      }

      return total;
    }();
    const I32 correction = pawn_correction + non_pawn_white_correction +
                           non_pawn_black_correction + major_correction +
                           continuation_correction;
    const I32 adjusted_score = static_cast<I32>(static_eval) + correction / 512;
    // Ensure no static evaluations are mate scores
    return std::clamp(
        adjusted_score, -kTBWinInMaxPlyScore + 1, kTBWinInMaxPlyScore - 1);
  }

  [[nodiscard]] ContinuationCorrectionEntry *GetContEntry(
      const BoardState &state, Move move) {
    const auto from = move.GetFrom(), to = move.GetTo();
    return &continuation_table_[state.turn][state.GetPieceType(from)][to];
  }

 private:
  [[nodiscard]] I16 CalculateBonus(Score static_eval,
                                   Score search_score,
                                   int depth) {
    return std::clamp((search_score - static_eval) * depth / 8, -256, 256);
  }

  void UpdateTableScore(I16 &current_score, Score bonus) {
    current_score += ScaleBonus(current_score, bonus, 1024);
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

  [[nodiscard]] int GetMajorTableIndex(const BoardState &state) const {
    return state.major_key & 16383;
  }

  [[nodiscard]] int GetNonPawnTableIndex(const BoardState &state,
                                         Color color) const {
    return state.non_pawn_keys[color] & 16383;
  }

 private:
  MultiArray<I16, 16384, kNumColors> pawn_table_;
  MultiArray<I16, 16384, kNumColors> major_table_;
  MultiArray<I16, 16384, kNumColors, kNumColors> non_pawn_table_;
  MultiArray<ContinuationCorrectionEntry, kNumColors, kNumPieceTypes, 64>
      continuation_table_;
};

}  // namespace search::history

#endif  // INTEGRAL_CORRECTION_HISTORY_H