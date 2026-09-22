#ifndef INTEGRAL_PAWN_HISTORY_H
#define INTEGRAL_PAWN_HISTORY_H

#include "../../../../shared/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

TUNABLE(kPawnHistFill, -967, -3000, 0, false);

class PawnHistory {
 public:
  PawnHistory() : table_({}), continuation_table_({}) {
    table_.fill(kPawnHistFill);
  }

  void UpdateMoveScore(const BoardState &state,
                       Move move,
                       I16 bonus,
                       const StackEntry *stack) {
    const auto piece = state.GetPieceType(move.GetFrom());
    const auto to = move.GetTo();

    I16 &score = table_[GetIndex(state)][state.turn][piece][to];
    score += ScaleBonus(score, bonus);

    const auto *previous = stack - 1;
    if (!previous->move) {
      return;
    }

    const int index = GetContinuationIndex(state, *previous);
    I16 &continuation_score =
        continuation_table_[index][state.turn][piece][to];

    continuation_score += ScaleBonus(continuation_score, bonus);
  }

  void UpdateScore(const BoardState &state,
                   StackEntry *stack,
                   I16 depth,
                   MoveList &quiets) {
    const I16 bonus = HistoryBonus(depth);

    UpdateMoveScore(state, stack->move, bonus, stack);

    const I16 penalty = HistoryPenalty(depth);
    for (int i = 0; i < quiets.Size(); i++) {
      UpdateMoveScore(state, quiets[i], penalty, stack);
    }
  }

  [[nodiscard]] int GetScore(const BoardState &state,
                             Move move,
                             const StackEntry *stack) const {
    const auto piece = state.GetPieceType(move.GetFrom());
    const auto to = move.GetTo();

    int score = table_[GetIndex(state)][state.turn][piece][to];

    const auto *previous = stack - 1;
    if (previous->move) {
      const int index = GetContinuationIndex(state, *previous);
      score += continuation_table_[index][state.turn][piece][to];
    }

    return score;
  }

 private:
  [[nodiscard]] int GetIndex(const BoardState &state) const {
    return state.pawn_key & (kBucketCount - 1);
  }

  [[nodiscard]] int GetContinuationIndex(const BoardState &state,
                                         const StackEntry &previous) const {
    const U64 context =
        static_cast<U64>(previous.moved_piece) * kSquareCount +
        previous.move.GetTo();
    return (state.pawn_key ^ ((context + 1) * 0x9e3779b97f4a7c15ULL)) &
           (kBucketCount - 1);
  }

 private:
  static constexpr int kBucketCount = 16384;
  MultiArray<I16, kBucketCount, kNumColors, kNumPieceTypes, kSquareCount> table_;
  MultiArray<I16, kBucketCount, kNumColors, kNumPieceTypes, kSquareCount>
      continuation_table_;
};

}  // namespace search::history

#endif  // INTEGRAL_PAWN_HISTORY_H
