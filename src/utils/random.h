#ifndef INTEGRAL_RANDOM_H
#define INTEGRAL_RANDOM_H

#include <random>

#include "types.h"

constexpr int kRandomSeed = 0x1333317;
static thread_local std::mt19937_64 mt_generator(kRandomSeed);

static void RandomSeed(U64 seed) {
  mt_generator.seed(seed);
}

static U64 RandomU64() {
  return mt_generator();
}

static U64 RandomU64(U64 min, U64 max) {
  std::uniform_int_distribution<U64> dist(min, max);
  return dist(mt_generator);
}

#endif  // INTEGRAL_RANDOM_H