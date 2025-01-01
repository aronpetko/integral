#ifndef INTEGRAL_ARCH_H
#define INTEGRAL_ARCH_H

#include <cstdint>

namespace nnue::arch {

constexpr std::size_t kL1Size = 1280;
constexpr std::size_t kL2Size = 16;
constexpr std::size_t kL3Size = 32;
constexpr std::size_t kInputBucketCount = 12;
constexpr std::size_t kOutputBucketCount = 8;

constexpr std::int32_t kFtQuantization = 255;
constexpr std::int32_t kL1Quantization = 128;

constexpr std::int32_t kEvalScale = 200;

};  // namespace nnue::arch

#endif  // INTEGRAL_ARCH_H