#ifndef INTEGRAL_SYZYGY_H
#define INTEGRAL_SYZYGY_H

#include <atomic>

#include "../../../chess/board.h"

namespace syzygy {

inline std::atomic<int> max_pieces = 0;
inline std::atomic<int> piece_probe_limit = 32;

inline std::atomic<bool> enabled = false;
inline std::atomic<int> probe_depth = 0;

enum class ProbeResult {
  kFailed,
  kWin,
  kDraw,
  kLoss
};

void SetPath(std::string_view path);

void Free();

ProbeResult ProbePosition(const BoardState &state);

}  // namespace syzygy

#endif  // INTEGRAL_SYZYGY_H