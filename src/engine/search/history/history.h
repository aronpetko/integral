#ifndef INTEGRAL_HISTORY_H
#define INTEGRAL_HISTORY_H

#include "../../../chess/board.h"
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
  }

 public:
  std::unique_ptr<QuietHistory> quiet_history;
  std::unique_ptr<ContinuationHistory> continuation_history;
  std::unique_ptr<CorrectionHistory> correction_history;

 private:
  const BoardState &state_;
};

}  // namespace history

#endif  // INTEGRAL_HISTORY_H