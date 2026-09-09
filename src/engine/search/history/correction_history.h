#ifndef INTEGRAL_CORRECTION_HISTORY_H
#define INTEGRAL_CORRECTION_HISTORY_H

#include <atomic>
#include <bit>
#include <memory>

#include "../../../../shared/multi_array.h"
#include "../../../tuner/spsa.h"
#include "../stack.h"

namespace search::history {

TUNABLE_STEP(kPawnCorrectionWeight, 42, 0, 125, false, 3);
TUNABLE_STEP(kNonPawnCorrectionWeight, 40, 0, 125, false, 3);
TUNABLE_STEP(kMajorCorrectionWeight, 37, 0, 125, false, 3);
TUNABLE_STEP(kContinuationCorrectionWeight, 52, 0, 125, false, 3);

class CorrectionHistory {
  constexpr static U16 kDefaultHashSize = 16384;

 public:
  explicit CorrectionHistory(U16 num_threads) {
    Resize(num_threads);
  }

  void Resize(U16 num_threads) {
    // Round up to the next power of two so keys can be masked
    hash_size_ =
        std::bit_ceil<U64>(kDefaultHashSize * std::max<U16>(1, num_threads));

    pawn_table_ = std::make_unique<std::atomic_int16_t[]>(PawnTableEntries());
    major_table_ = std::make_unique<std::atomic_int16_t[]>(MajorTableEntries());
    non_pawn_table_ =
        std::make_unique<std::atomic_int16_t[]>(NonPawnTableEntries());

    ClearContinuationTable();
  }

  void Clear() {
    ClearTable(pawn_table_.get(), PawnTableEntries());
    ClearTable(major_table_.get(), MajorTableEntries());
    ClearTable(non_pawn_table_.get(), NonPawnTableEntries());
    ClearContinuationTable();
  }

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
    UpdateTableScore(pawn_table_[GetPawnTableIndex(state)], bonus);

    // Update major piece table score
    UpdateTableScore(major_table_[GetMajorTableIndex(state)], bonus);

    // Update non-pawn table scores for both colors
    for (Color color : {Color::kWhite, Color::kBlack}) {
      UpdateTableScore(non_pawn_table_[GetNonPawnTableIndex(state, color)],
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
        pawn_table_[GetPawnTableIndex(state)] * kPawnCorrectionWeight;
    const I32 non_pawn_white_correction =
        non_pawn_table_[GetNonPawnTableIndex(state, Color::kWhite)] *
        kNonPawnCorrectionWeight;
    const I32 non_pawn_black_correction =
        non_pawn_table_[GetNonPawnTableIndex(state, Color::kBlack)] *
        kNonPawnCorrectionWeight;
    const I32 major_correction =
        major_table_[GetMajorTableIndex(state)] * kMajorCorrectionWeight;
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
  [[nodiscard]] U64 PawnTableEntries() const {
    return hash_size_ * kNumColors;
  }

  [[nodiscard]] U64 MajorTableEntries() const {
    return hash_size_ * kNumColors;
  }

  [[nodiscard]] U64 NonPawnTableEntries() const {
    return hash_size_ * kNumColors * kNumColors;
  }

  static void ClearTable(std::atomic_int16_t *table, U64 entries) {
    for (U64 i = 0; i < entries; i++) {
      table[i].store(0, std::memory_order_relaxed);
    }
  }

  void ClearContinuationTable() {
    for (auto &by_color : continuation_table_) {
      for (auto &by_piece : by_color) {
        for (auto &entry : by_piece) {
          entry.fill(I16{0});
        }
      }
    }
  }

  [[nodiscard]] I16 CalculateBonus(Score static_eval,
                                   Score search_score,
                                   int depth) {
    return std::clamp((search_score - static_eval) * depth / 8, -256, 256);
  }

  void UpdateTableScore(std::atomic_int16_t &entry, Score bonus) {
    const I16 cur = entry.load(std::memory_order_relaxed);
    entry.store(cur + ScaleBonus(cur, bonus, 1024), std::memory_order_relaxed);
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

  [[nodiscard]] U64 GetPawnTableIndex(const BoardState &state) const {
    return (state.pawn_key & (hash_size_ - 1ULL)) * kNumColors + state.turn;
  }

  [[nodiscard]] U64 GetMajorTableIndex(const BoardState &state) const {
    return (state.major_key & (hash_size_ - 1ULL)) * kNumColors + state.turn;
  }

  [[nodiscard]] U64 GetNonPawnTableIndex(const BoardState &state,
                                         Color color) const {
    const U64 hash_index = state.non_pawn_keys[color] & (hash_size_ - 1ULL);
    return (hash_index * kNumColors + state.turn) * kNumColors + color;
  }

 private:
  U64 hash_size_;
  std::unique_ptr<std::atomic_int16_t[]> pawn_table_;
  std::unique_ptr<std::atomic_int16_t[]> non_pawn_table_;
  std::unique_ptr<std::atomic_int16_t[]> major_table_;
  MultiArray<ContinuationCorrectionEntry, kNumColors, kNumPieceTypes, 64>
      continuation_table_;
};

}  // namespace search::history

#endif  // INTEGRAL_CORRECTION_HISTORY_H