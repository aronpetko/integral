#ifndef INTEGRAL_SYZYGY_H
#define INTEGRAL_SYZYGY_H

#include <atomic>

#include "../../../chess/board.h"

namespace syzygy {

inline bool enabled = false;
inline U32 probe_depth = 0;

enum class ProbeResult {
  kFailed,
  kWin,
  kDraw,
  kLoss
};

void SetPath(std::string_view path);

void Free();

[[nodiscard]] ProbeResult ProbePosition(const BoardState &state);

[[nodiscard]] U32 MaximumPieces();

}  // namespace syzygy

#endif  // INTEGRAL_SYZYGY_H