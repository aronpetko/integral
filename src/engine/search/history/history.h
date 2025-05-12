#ifndef INTEGRAL_HISTORY_H
#define INTEGRAL_HISTORY_H

#include "../../../chess/board.h"
#include "capture_history.h"
#include "continuation_history.h"
#include "correction_history.h"
#include "pawn_history.h"
#include "quiet_history.h"

namespace search::history {

class History {
 public:
  History() {
    Initialize();
  }

  void Initialize() {
    quiet_history = std::make_unique<QuietHistory>();
    continuation_history = std::make_unique<ContinuationHistory>();
    correction_history = std::make_unique<CorrectionHistory>();
    capture_history = std::make_unique<CaptureHistory>();
    pawn_history = std::make_unique<PawnHistory>();
  }

  // Reinitialize the history objects for quicker clearing
  void Clear() {
    Initialize();
  }

  [[nodiscard]] I32 GetMoveScore(const BoardState &state,
                                 Move move,
                                 StackEntry *stack) {
    return move.IsCapture(state) ? GetCaptureMoveScore(state, move)
                                 : GetQuietMoveScore(state, move, stack);
  }

  [[nodiscard]] I32 GetQuietMoveScore(const BoardState &state,
                                      Move move,
                                      StackEntry *stack) const {
    return quiet_history->GetScore(state, move, stack->threats) +
           continuation_history->GetScore(state, move, stack - 1) +
           continuation_history->GetScore(state, move, stack - 2) +
           continuation_history->GetScore(state, move, stack - 4) +
           pawn_history->GetScore(state, move);
  }

  [[nodiscard]] I32 GetCaptureMoveScore(const BoardState &state,
                                        Move move) const {
    return capture_history->GetScore(state, move);
  }

 public:
  std::unique_ptr<QuietHistory> quiet_history;
  std::unique_ptr<CaptureHistory> capture_history;
  std::unique_ptr<PawnHistory> pawn_history;
  std::unique_ptr<ContinuationHistory> continuation_history;
  std::unique_ptr<CorrectionHistory> correction_history;
};

}  // namespace search::history

#endif  // INTEGRAL_HISTORY_H
