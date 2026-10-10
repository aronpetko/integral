#ifndef INTEGRAL_ARCH_H
#define INTEGRAL_ARCH_H

#include <cstdint>

#include "../multi_array.h"
#include "../simd.h"

namespace nnue {

namespace arch::value {

constexpr std::size_t kPawnPairFeatureCount = 4560;
constexpr std::size_t kThreatFeatureCount = 59808;
constexpr std::size_t kThreatPawnPairFeatureCount =
    kThreatFeatureCount + kPawnPairFeatureCount;
constexpr std::size_t kL1Size = 768;
constexpr std::size_t kL2Size = 16;
constexpr std::size_t kL3Size = 32;

constexpr std::size_t kHmcBucketsStart = 14;
constexpr std::size_t kHmcBucketsStep = 8;
constexpr std::size_t kHmcBucketCount =
    (100 - kHmcBucketsStart + kHmcBucketsStep - 1) / kHmcBucketsStep;
// The runtime network carries one extra, all-zero row that a bucket-0 HMC maps
// to, so looking up the row is a table index with no branch
constexpr std::size_t kHmcRowCount = kHmcBucketCount + 1;
constexpr std::size_t kInputBucketCount = 16;
constexpr std::size_t kOutputBucketCount = 8;

constexpr std::int32_t kFtQuantization = 255;
constexpr std::int32_t kL1Quantization = 128;

constexpr std::int32_t kEvalScale = 200;

}  // namespace arch

// clang-format off

struct RawValueNetwork {
  MultiArray<I16, arch::value::kInputBucketCount, 2, PieceType::kNumPieceTypes, Squares::kSquareCount, arch::value::kL1Size> feature_weights;
  MultiArray<I16, arch::value::kHmcBucketCount, arch::value::kL1Size> hmc_weights;
  MultiArray<I8, arch::value::kThreatPawnPairFeatureCount, arch::value::kL1Size> threat_weights;
  MultiArray<I16, arch::value::kL1Size> feature_biases;
  MultiArray<I8, arch::value::kOutputBucketCount, arch::value::kL2Size, arch::value::kL1Size> l1_weights;
  MultiArray<float, arch::value::kOutputBucketCount, arch::value::kL2Size> l1_biases;
  MultiArray<float, arch::value::kOutputBucketCount, arch::value::kL3Size, arch::value::kL2Size> l2_weights;
  MultiArray<float, arch::value::kOutputBucketCount, arch::value::kL3Size> l2_biases;
  MultiArray<float, arch::value::kOutputBucketCount, arch::value::kL3Size> l3_weights;
  MultiArray<float, arch::value::kOutputBucketCount> l3_biases;
};

struct alignas(simd::kAlignment) ValueNetwork {
  alignas(simd::kAlignment) MultiArray<I16, arch::value::kInputBucketCount, 2, PieceType::kNumPieceTypes, Squares::kSquareCount, arch::value::kL1Size> feature_weights;
  alignas(simd::kAlignment) MultiArray<I16, arch::value::kHmcRowCount, arch::value::kL1Size> hmc_weights;
  alignas(simd::kAlignment) MultiArray<I8, arch::value::kThreatPawnPairFeatureCount, arch::value::kL1Size> threat_weights;
  alignas(simd::kAlignment) MultiArray<I16, arch::value::kL1Size> feature_biases;
  union {
    alignas(simd::kAlignment) MultiArray<I8, arch::value::kOutputBucketCount, arch::value::kL1Size, arch::value::kL2Size> l1_weights;
    alignas(simd::kAlignment) MultiArray<I8, arch::value::kOutputBucketCount, arch::value::kL1Size * arch::value::kL2Size> l1_weights_alt;
  };
  alignas(simd::kAlignment) MultiArray<float, arch::value::kOutputBucketCount, arch::value::kL2Size> l1_biases;
  alignas(simd::kAlignment) MultiArray<float, arch::value::kOutputBucketCount, arch::value::kL2Size, arch::value::kL3Size> l2_weights;
  alignas(simd::kAlignment) MultiArray<float, arch::value::kOutputBucketCount, arch::value::kL3Size> l2_biases;
  alignas(simd::kAlignment) MultiArray<float, arch::value::kOutputBucketCount, arch::value::kL3Size> l3_weights;
  alignas(simd::kAlignment) MultiArray<float, arch::value::kOutputBucketCount> l3_biases;
};
// clang-format on

namespace arch::policy {

constexpr std::size_t kL1Size = 128;
constexpr std::size_t kOutputSize = 3920;

constexpr std::int32_t kQuantisation = 128;

}  // namespace arch

// clang-format off
struct PolicyNetwork {
  MultiArray<I8, 2, 2, 2, PieceType::kNumPieceTypes, Squares::kSquareCount, arch::policy::kL1Size> feature_weights;
  MultiArray<I8, arch::policy::kL1Size> feature_biases;
  MultiArray<I8, arch::policy::kOutputSize, arch::policy::kL1Size / 2> l1_weights;
  MultiArray<I8, arch::policy::kOutputSize> l1_biases;
};
// clang-format on

};  // namespace nnue

#endif  // INTEGRAL_ARCH_H