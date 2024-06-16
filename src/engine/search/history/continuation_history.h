#ifndef INTEGRAL_CONTINUATION_HISTORY_H
#define INTEGRAL_CONTINUATION_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"
#include "bonus.h"

namespace history {

using ContinuationEntry = MultiArray<I32, kNumColors, kNumTypes, kSquareCount>;

class ContinuationHistory {
 public:
  explicit ContinuationHistory(const BoardState &state)
      : state_(state), table_({}) {}

  void UpdateScore(SearchStackEntry *stack, int depth, MoveList &quiets) {
    const Color turn = state_.turn;
    const Move move = stack->move;

    const auto update_cont_entry = [this, &turn, &stack](
                                       Move move, int plies_ago, int bonus) {
      const int piece = state_.GetPieceType(move.GetFrom());
      const int to = move.GetTo();

      // Ensure the continuation history table exists for this move
      if ((stack - plies_ago)->continuation_entry) {
        auto &entry = *reinterpret_cast<ContinuationEntry *>(
            (stack - plies_ago)->continuation_entry);

        I32 &score = entry[turn][piece][to];
        score += ScaleBonus(score, bonus);
      }
    };

    const int bonus = HistoryBonus(depth);
    update_cont_entry(move, 1, bonus);
    update_cont_entry(move, 2, bonus);

    // Lower the score of the quiet moves that failed to raise alpha
    for (int i = 0; i < quiets.Size(); i++) {
      // Apply a linear dampening to the penalty as the depth increases
      update_cont_entry(quiets[i], 1, -bonus);
      update_cont_entry(quiets[i], 2, -bonus);
    }
  }

  [[nodiscard]] ContinuationEntry *GetEntry(Move move) {
    const auto from = move.GetFrom(), to = move.GetTo();
    return &table_[state_.turn][state_.GetPieceType(from)][to];
  }

  [[nodiscard]] I32 GetScore(Move move, SearchStackEntry *stack) {
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
  const BoardState &state_;
  MultiArray<ContinuationEntry, kNumColors, kNumTypes, kSquareCount> table_;
};

}  // namespace history

#endif  // INTEGRAL_CONTINUATION_HISTORY_H