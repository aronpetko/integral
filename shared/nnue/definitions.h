#ifndef INTEGRAL_ARCH_H
#define INTEGRAL_ARCH_H

#include <cstdint>

#include "../multi_array.h"
#include "../simd.h"

namespace nnue {

namespace arch {

constexpr std::size_t kPawnPairFeatureCount = 4560;
constexpr std::size_t kThreatFeatureCount = 59808;
constexpr std::size_t kThreatPawnPairFeatureCount =
    kThreatFeatureCount + kPawnPairFeatureCount;
// Both kings share one set of piece-square features
constexpr std::size_t kPsqFeatureCount = 11 * 64;
constexpr std::size_t kL1Size = 1024;
constexpr std::size_t kL2Size = 32;
constexpr std::size_t kL3Size = 32;

constexpr std::size_t kInputBucketCount = 32;
constexpr std::size_t kOutputBucketCount = 8;

constexpr std::int32_t kFtQuantization = 255;
constexpr std::int32_t kL1Quantization = 128;
constexpr std::int32_t kQuantization = 64;

// The network was trained with a scale of 400, which is halved to match the
// scale the search was tuned for
constexpr std::int64_t kEvalScale = 200;

}  // namespace arch

// clang-format off

// The network file's layout, which matches Pawnocchio's weights struct
struct RawNetwork {
  alignas(64) MultiArray<I16, arch::kInputBucketCount, arch::kPsqFeatureCount, arch::kL1Size> feature_weights;
  alignas(64) MultiArray<I8, arch::kThreatPawnPairFeatureCount, arch::kL1Size> threat_weights;
  alignas(64) MultiArray<I16, arch::kL1Size> feature_biases;
  alignas(64) MultiArray<I8, arch::kOutputBucketCount, arch::kL1Size * arch::kL2Size> l1_weights;
  alignas(64) MultiArray<I32, arch::kOutputBucketCount, arch::kL2Size> l1_biases;
  alignas(64) MultiArray<I32, arch::kOutputBucketCount, 2 * arch::kL2Size, arch::kL3Size> l2_weights;
  alignas(64) MultiArray<I32, arch::kOutputBucketCount, arch::kL3Size> l2_biases;
  alignas(64) MultiArray<I32, arch::kOutputBucketCount, arch::kL3Size> l3_weights;
  alignas(64) MultiArray<I32, arch::kOutputBucketCount> l3_biases;
};

struct alignas(simd::kAlignment) Network {
  alignas(simd::kAlignment) MultiArray<I16, arch::kInputBucketCount, arch::kPsqFeatureCount, arch::kL1Size> feature_weights;
  alignas(simd::kAlignment) MultiArray<I8, arch::kThreatPawnPairFeatureCount, arch::kL1Size> threat_weights;
  alignas(simd::kAlignment) MultiArray<I16, arch::kL1Size> feature_biases;
  alignas(simd::kAlignment) MultiArray<I8, arch::kOutputBucketCount, arch::kL1Size * arch::kL2Size> l1_weights;
  alignas(simd::kAlignment) MultiArray<I32, arch::kOutputBucketCount, arch::kL2Size> l1_biases;
  alignas(simd::kAlignment) MultiArray<I32, arch::kOutputBucketCount, 2 * arch::kL2Size, arch::kL3Size> l2_weights;
  alignas(simd::kAlignment) MultiArray<I32, arch::kOutputBucketCount, arch::kL3Size> l2_biases;
  alignas(simd::kAlignment) MultiArray<I32, arch::kOutputBucketCount, arch::kL3Size> l3_weights;
  alignas(simd::kAlignment) MultiArray<I32, arch::kOutputBucketCount> l3_biases;
};
// clang-format on

};  // namespace nnue

#endif  // INTEGRAL_ARCH_H