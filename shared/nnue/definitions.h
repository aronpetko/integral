#ifndef INTEGRAL_ARCH_H
#define INTEGRAL_ARCH_H

#include <cstdint>

#include "../multi_array.h"
#include "../simd.h"

namespace nnue {

namespace arch {

constexpr std::size_t kL1Size = 1536;
constexpr std::size_t kL2Size = 16;
constexpr std::size_t kL3Size = 32;
constexpr std::size_t kInputBucketCount = 12;
constexpr std::size_t kOutputBucketCount = 8;

constexpr std::int32_t kFtQuantization = 255;
constexpr std::int32_t kL1Quantization = 128;

constexpr std::int32_t kEvalScale = 189;

}  // namespace arch

// clang-format off
struct RawNetwork {
  MultiArray<I16, arch::kInputBucketCount, 2, PieceType::kNumPieceTypes, Squares::kSquareCount, arch::kL1Size> feature_weights;
  MultiArray<I16, arch::kL1Size> feature_biases;
  MultiArray<I8, arch::kOutputBucketCount, arch::kL2Size, arch::kL1Size> l1_weights;
  MultiArray<float, arch::kOutputBucketCount, arch::kL2Size> l1_biases;
  MultiArray<float, arch::kOutputBucketCount, arch::kL3Size, arch::kL2Size> l2_weights;
  MultiArray<float, arch::kOutputBucketCount, arch::kL3Size> l2_biases;
  MultiArray<float, arch::kOutputBucketCount, arch::kL3Size> l3_weights;
  MultiArray<float, arch::kOutputBucketCount> l3_biases;
};

struct alignas(simd::kAlignment) Network {
  alignas(simd::kAlignment) MultiArray<I16, arch::kInputBucketCount, 2, PieceType::kNumPieceTypes, Squares::kSquareCount, arch::kL1Size> feature_weights;
  alignas(simd::kAlignment) MultiArray<I16, arch::kL1Size> feature_biases;
  union {
    alignas(simd::kAlignment) MultiArray<I8, arch::kOutputBucketCount, arch::kL1Size, arch::kL2Size> l1_weights;
    alignas(simd::kAlignment) MultiArray<I8, arch::kOutputBucketCount, arch::kL1Size * arch::kL2Size> l1_weights_alt;
  };
  alignas(simd::kAlignment) MultiArray<float, arch::kOutputBucketCount, arch::kL2Size> l1_biases;
  alignas(simd::kAlignment) MultiArray<float, arch::kOutputBucketCount, arch::kL2Size, arch::kL3Size> l2_weights;
  alignas(simd::kAlignment) MultiArray<float, arch::kOutputBucketCount, arch::kL3Size> l2_biases;
  alignas(simd::kAlignment) MultiArray<float, arch::kOutputBucketCount, arch::kL3Size> l3_weights;
  alignas(simd::kAlignment) MultiArray<float, arch::kOutputBucketCount> l3_biases;
};
// clang-format on

};  // namespace nnue

#endif  // INTEGRAL_ARCH_H