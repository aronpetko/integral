#ifndef INTEGRAL_CORRECTION_HISTORY_H
#define INTEGRAL_CORRECTION_HISTORY_H

#include "../../../utils/multi_array.h"
#include "../stack.h"

namespace history {

class CorrectionHistory {
 public:
  explicit CorrectionHistory(const BoardState &state) : state_(state) {}

  void UpdateScore(SearchStackEntry *stack, MoveList &quiets);

 private:
  const BoardState &state_;
};

}  // namespace history

#endif  // INTEGRAL_CORRECTION_HISTORY_H