#ifndef INTEGRAL_RANDOM_H
#define INTEGRAL_RANDOM_H

#include <random>

#include "types.h"

constexpr int kRandomSeed = 0x1333317;

static U64 RandomU64() {
  static std::mt19937_64 mt_generator(kRandomSeed);
  return mt_generator();
}

#endif  // INTEGRAL_RANDOM_H