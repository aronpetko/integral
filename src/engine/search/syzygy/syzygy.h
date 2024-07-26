#ifndef INTEGRAL_SYZYGY_H
#define INTEGRAL_SYZYGY_H

#include <atomic>

#include "../../../chess/board.h"

namespace syzygy {

inline std::atomic<bool> enabled = false;

enum class ProbeResult {
  kFailed,
  kWin,
  kDraw,
  kLoss
};

ProbeResult ProbePosition(const BoardState &state);

}  // namespace syzygy

#endif  // INTEGRAL_SYZYGY_H