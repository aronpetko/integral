#ifndef INTEGRAL_HISTORY_H
#define INTEGRAL_HISTORY_H

#include "../../../chess/board.h"
#include "capture_history.h"
#include "continuation_history.h"
#include "correction_history.h"
#include "quiet_history.h"

namespace history {

class SearchHistory {
 public:
  explicit SearchHistory(const BoardState &state) : state_(state) {
    Clear();
  }

  void Clear() {
    // Reinitialize the history objects for quicker clearing
    quiet_history = std::make_unique<QuietHistory>(state_);
    continuation_history = std::make_unique<ContinuationHistory>(state_);
    correction_history = std::make_unique<CorrectionHistory>(state_);
    capture_history = std::make_unique<CaptureHistory>(state_);
  }

  [[nodiscard]] int GetQuietMoveScore(Move move,
                                      SearchStackEntry *stack) const {
    return quiet_history->GetScore(move) +
           continuation_history->GetScore(move, stack - 1) +
           continuation_history->GetScore(move, stack - 2);
  }

  [[nodiscard]] int GetCaptureMoveScore(Move move) const {
    return capture_history->GetScore(move);
  }

 public:
  std::unique_ptr<QuietHistory> quiet_history;
  std::unique_ptr<CaptureHistory> capture_history;
  std::unique_ptr<ContinuationHistory> continuation_history;
  std::unique_ptr<CorrectionHistory> correction_history;

 private:
  const BoardState &state_;
};

}  // namespace history

#endif  // INTEGRAL_HISTORY_H