#ifndef INTEGRAL_CONTINUATION_HISTORY_H
#define INTEGRAL_CONTINUATION_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace history {

using ContinuationEntry = MultiArray<I32, kNumColors, kNumPieceTypes, kSquareCount>;

class ContinuationHistory {
 public:
  explicit ContinuationHistory(const BoardState &state)
      : state_(state), table_({}) {}

  void UpdateScore(SearchStackEntry *stack, int depth, MoveList &quiets) {
    const Move move = stack->move;

    const int bonus = HistoryBonus(depth);
    UpdateIndividualScore(move, bonus, stack - 1);
    UpdateIndividualScore(move, bonus, stack - 2);

    // Lower the score of the quiet moves that failed to raise alpha
    for (int i = 0; i < quiets.Size(); i++) {
      // Apply a linear dampening to the penalty as the depth increases
      UpdateIndividualScore(quiets[i], -bonus, stack - 1);
      UpdateIndividualScore(quiets[i], -bonus, stack - 2);
    }
  }

  [[nodiscard]] ContinuationEntry *GetEntry(Move move) {
    const auto from = move.GetFrom(), to = move.GetTo();
    return &table_[state_.turn][state_.GetPieceType(from)][to];
  }

  [[nodiscard]] int GetScore(Move move, SearchStackEntry *stack) {
    if (!stack->continuation_entry) {
      return 0;
    }

    const int piece = state_.GetPieceType(move.GetFrom());
    const int to = move.GetTo();

    auto &entry =
        *reinterpret_cast<ContinuationEntry *>(stack->continuation_entry);
    return entry[state_.turn][piece][to];
  }

 private:
  void UpdateIndividualScore(Move move, int bonus, SearchStackEntry *stack) {
    if (!stack->continuation_entry) {
      return;
    }

    const int piece = state_.GetPieceType(move.GetFrom());
    const int to = move.GetTo();

    auto &entry =
        *reinterpret_cast<ContinuationEntry *>(stack->continuation_entry);

    int &score = entry[state_.turn][piece][to];
    score += ScaleBonus(score, bonus);
  }

 private:
  const BoardState &state_;
  MultiArray<ContinuationEntry, kNumColors, kNumPieceTypes, kSquareCount> table_;
};

}  // namespace history

#endif  // INTEGRAL_CONTINUATION_HISTORY_H