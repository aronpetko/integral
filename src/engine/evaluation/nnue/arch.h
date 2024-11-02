#ifndef INTEGRAL_ARCH_H
#define INTEGRAL_ARCH_H

#include <cstdint>

namespace nnue::arch {

constexpr std::size_t kHiddenLayerSize = 1536;
constexpr std::size_t kInputBucketCount = 9;
constexpr std::size_t kOutputBucketCount = 8;

constexpr std::int32_t kHiddenLayerQuantization = 255;
constexpr std::int32_t kOutputQuantization = 64;

constexpr std::int32_t kEvalScale = 200;

};  // namespace nnue::arch

#endif  // INTEGRAL_ARCH_H