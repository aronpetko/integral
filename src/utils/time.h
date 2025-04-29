#ifndef INTEGRAL_TIME_H
#define INTEGRAL_TIME_H

#include <chrono>

#include "types.h"

using TimeStamp = I64;

[[nodiscard]] static U64 GetCurrentTime() {
  const auto duration = std::chrono::high_resolution_clock ::now().time_since_epoch();
  return std::chrono::duration_cast<std::chrono::milliseconds>(duration)
      .count();
}

#endif  // INTEGRAL_TIME_H