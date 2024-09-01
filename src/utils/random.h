#ifndef INTEGRAL_RANDOM_H
#define INTEGRAL_RANDOM_H

#include <random>

#include "types.h"

constexpr int kRandomSeed = 0x1333317;
static thread_local std::mt19937_64 mt_generator(kRandomSeed);

template <typename... Args>
static void RandomSeed(U64 base_seed, Args... additional_seeds) {
  std::random_device rd;
  std::vector<unsigned> seed_data{static_cast<unsigned>(rd()),
                                  static_cast<unsigned>(rd()),
                                  static_cast<unsigned>(rd()),
                                  static_cast<unsigned>(rd()),
                                  static_cast<unsigned>(base_seed),
                                  static_cast<unsigned>(additional_seeds)...};
  std::seed_seq seed(seed_data.begin(), seed_data.end());
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