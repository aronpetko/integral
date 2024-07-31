#ifndef INTEGRAL_CONTINUATION_HISTORY_H
#define INTEGRAL_CONTINUATION_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace search::history {

using ContinuationEntry =
    MultiArray<I32, kNumColors, kNumPieceTypes, kSquareCount>;

class ContinuationHistory {
 public:
  ContinuationHistory() : table_({}) {}

  void UpdateScore(const BoardState &state,
                   StackEntry *stack,
                   int depth,
                   MoveList &quiets) {
    const Move move = stack->move;

    const int bonus = HistoryBonus(depth);
    UpdateIndividualScore(state, move, bonus, stack - 1);
    UpdateIndividualScore(state, move, bonus, stack - 2);
    UpdateIndividualScore(state, move, bonus, stack - 4);

    // Lower the score of the quiet moves that failed to raise alpha
    for (int i = 0; i < quiets.Size(); i++) {
      // Apply a linear dampening to the penalty as the depth increases
      UpdateIndividualScore(state, quiets[i], -bonus, stack - 1);
      UpdateIndividualScore(state, quiets[i], -bonus, stack - 2);
      UpdateIndividualScore(state, quiets[i], -bonus, stack - 4);
    }
  }

  [[nodiscard]] ContinuationEntry *GetEntry(const BoardState &state,
                                            Move move) {
    const auto from = move.GetFrom(), to = move.GetTo();
    return &table_[state.turn][state.GetPieceType(from)][to];
  }

  [[nodiscard]] int GetScore(const BoardState &state,
                             Move move,
                             StackEntry *stack) {
    if (!stack->continuation_entry) {
      return 0;
    }

    const int piece = state.GetPieceType(move.GetFrom());
    const int to = move.GetTo();

    auto &entry =
        *reinterpret_cast<ContinuationEntry *>(stack->continuation_entry);
    return entry[state.turn][piece][to];
  }

 private:
  void UpdateIndividualScore(const BoardState &state,
                             Move move,
                             int bonus,
                             StackEntry *stack) {
    if (!stack->continuation_entry) {
      return;
    }

    const int piece = state.GetPieceType(move.GetFrom());
    const int to = move.GetTo();

    auto &entry =
        *reinterpret_cast<ContinuationEntry *>(stack->continuation_entry);

    int &score = entry[state.turn][piece][to];
    score += ScaleBonus(score, bonus);
  }

 private:
  MultiArray<ContinuationEntry, kNumColors, kNumPieceTypes, kSquareCount>
      table_;
};

}  // namespace search::history

#endif  // INTEGRAL_CONTINUATION_HISTORY_H