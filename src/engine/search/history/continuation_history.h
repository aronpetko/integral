#ifndef INTEGRAL_CONTINUATION_HISTORY_H
#define INTEGRAL_CONTINUATION_HISTORY_H

#include "../../../../shared/multi_array.h"
#include "../stack.h"
#include "bonus.h"
#include "continuation_entries.h"
#include "quiet_history.h"

namespace search::history {

class ContinuationHistory {
 public:
  ContinuationHistory() : table_({}) {}

  void UpdateScore(const BoardState &state,
                   StackEntry *stack,
                   I16 depth,
                   QuietHistory *quiet_history,
                   MoveList &quiets) {
    const int bonus = HistoryBonus(depth);
    UpdateMoveScore(state,
                    stack->move,
                    bonus,
                    quiet_history->GetScore(state, stack->move, stack->threats),
                    stack);

    // Lower the score of the quiet moves that failed to raise alpha
    const I16 penalty = HistoryPenalty(depth);
    for (int i = 0; i < quiets.Size(); i++) {
      // Apply a linear dampening to the penalty as the depth increases
      UpdateMoveScore(state,
                      quiets[i],
                      penalty,
                      quiet_history->GetScore(state, quiets[i], stack->threats),
                      stack);
    }
  }

  void UpdateMoveScore(const BoardState &state,
                       Move move,
                       I16 bonus,
                       I32 quiet_history_score,
                       StackEntry *stack) {
    const auto total_score =
        GetScore(state, move, stack - 1) + GetScore(state, move, stack - 2) +
        GetScore(state, move, stack - 4) + GetScore(state, move, stack - 6) +
        quiet_history_score / 8;

    UpdateIndividualScore(state, move, bonus, total_score, stack - 1);
    UpdateIndividualScore(state, move, bonus, total_score, stack - 2);
    UpdateIndividualScore(state, move, bonus, total_score, stack - 4);
    UpdateIndividualScore(state, move, bonus, total_score, stack - 6);
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

    auto &entry = *stack->continuation_entry;
    return entry[state.turn][piece][to];
  }

 private:
  void UpdateIndividualScore(const BoardState &state,
                             Move move,
                             int bonus,
                             int total_score,
                             StackEntry *stack) {
    if (!stack->continuation_entry) {
      return;
    }

    const int piece = state.GetPieceType(move.GetFrom());
    const int to = move.GetTo();

    auto &entry = *stack->continuation_entry;

    I16 &score = entry[state.turn][piece][to];
    score += ScaleBonus(total_score, bonus);
  }

 private:
  MultiArray<ContinuationEntry, kNumColors, kNumPieceTypes, kSquareCount>
      table_;
};

}  // namespace search::history

#endif  // INTEGRAL_CONTINUATION_HISTORY_H