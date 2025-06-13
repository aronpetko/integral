#ifndef INTEGRAL_HISTORY_H
#define INTEGRAL_HISTORY_H

#include "../../../chess/board.h"
#include "capture_history.h"
#include "continuation_history.h"
#include "correction_history.h"
#include "pawn_history.h"
#include "quiet_history.h"

namespace search::history {

TUNABLE(kQuietHistoryWeight, 995, 0, 2048, false);
TUNABLE(kFirstContinuationHistoryWeight,  1114, 0, 2048, false);
TUNABLE(kSecondContinuationHistoryWeight, 1036, 0, 2048, false);
TUNABLE(kFourthContinuationHistoryWeight, 973, 0, 2048, false);
TUNABLE(kPawnHistoryWeight, 1084, 0, 2048, false);

constexpr int kHistoryWeightScale = 1024;

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
    I32 move_score = 0;
    move_score += quiet_history->GetScore(state, move, stack->threats) *
                  kQuietHistoryWeight;
    move_score += continuation_history->GetScore(state, move, stack - 1) *
                  kFirstContinuationHistoryWeight;
    move_score += continuation_history->GetScore(state, move, stack - 2) *
                  kSecondContinuationHistoryWeight;
    move_score += continuation_history->GetScore(state, move, stack - 4) *
                  kFourthContinuationHistoryWeight;
    move_score += pawn_history->GetScore(state, move) * kPawnHistoryWeight;

    return move_score / kHistoryWeightScale;
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
