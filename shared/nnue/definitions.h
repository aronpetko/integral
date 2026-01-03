#ifndef INTEGRAL_ARCH_H
#define INTEGRAL_ARCH_H

#include <cstdint>

#include "../multi_array.h"
#include "../simd.h"

namespace nnue {

namespace arch {

constexpr std::size_t kL1Size = 256;
constexpr std::size_t kOutputBucketCount = 8;

constexpr std::int32_t kQA = 255;
constexpr std::int32_t kQB = 64;

constexpr std::int32_t kEvalScale = 285;

}  // namespace arch

// clang-format off
struct RawNetwork {
  MultiArray<I16, 2, PieceType::kNumPieceTypes, Squares::kSquareCount, arch::kL1Size> feature_weights;
  MultiArray<I16, arch::kL1Size> feature_biases;
  MultiArray<I16, arch::kOutputBucketCount, 2, arch::kL1Size> output_weights;
  MultiArray<I16, arch::kOutputBucketCount> output_biases;
};

struct alignas(simd::kAlignment) Network {
  alignas(simd::kAlignment) MultiArray<I16, 2, PieceType::kNumPieceTypes, Squares::kSquareCount, arch::kL1Size> feature_weights;
  alignas(simd::kAlignment) MultiArray<I16, arch::kL1Size> feature_biases;
  alignas(simd::kAlignment) MultiArray<I16, arch::kOutputBucketCount, 2, arch::kL1Size> output_weights;
  alignas(simd::kAlignment) MultiArray<I16, arch::kOutputBucketCount> output_biases;
};
// clang-format on

};  // namespace nnue

#endif  // INTEGRAL_ARCH_H