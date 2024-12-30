#include "nnue.h"

#include "../../../utils/simd.h"
#include "accumulator.h"
#include "arch.h"

#ifdef _MSC_VER
#define SP_MSVC
#pragma push_macro("_MSC_VER")
#undef _MSC_VER
#endif

#include "../../../third-party/incbin/incbin.h"

#ifdef SP_MSVC
#pragma pop_macro("_MSC_VER")
#undef SP_MSVC
#endif

INCBIN(EVAL, EVALFILE);

namespace nnue {

#if !BUILD_HAS_SIMD
I32 SquaredCReLU(I16 value) {
  const I32 clipped = std::clamp<I32>(
      static_cast<I32>(value), 0, arch::kHiddenLayerQuantization);
  return clipped * clipped;
}
#endif

[[nodiscard]] I32 CReLU(I16 value) {
  return std::clamp<I32>(value, 0, arch::kFtQuantization);
}

[[nodiscard]] float CReLU(float value) {
  return std::clamp<float>(value, 0.0f, 1.0f);
}

void TransposeWeightsForPackus(std::unique_ptr<AlignedNetwork> &network) {
  constexpr int weightsPerBlock = sizeof(__m128i) / sizeof(int16_t);
  constexpr int NumRegs = sizeof(simd::Vepi8) / sizeof(__m128i);
  __m128i regs[NumRegs];

  // Process feature weights
  __m128i *weights =
      reinterpret_cast<__m128i *>(network->feature_weights.data());
  for (int i = 0;
       i < arch::kInputBucketCount * 2 * PieceType::kNumPieceTypes *
               Squares::kSquareCount * arch::kL1Size / weightsPerBlock;
       i += NumRegs) {
    for (int j = 0; j < NumRegs; j++) regs[j] = weights[i + j];

    for (int j = 0; j < NumRegs; j++)
      weights[i + j] = regs[simd::kPackusOrder[j]];
  }

  // Process feature biases
  __m128i *biases = reinterpret_cast<__m128i *>(network->feature_biases.data());
  for (int i = 0; i < arch::kL1Size / weightsPerBlock; i += NumRegs) {
    for (int j = 0; j < NumRegs; j++) regs[j] = biases[i + j];

    for (int j = 0; j < NumRegs; j++)
      biases[i + j] = regs[simd::kPackusOrder[j]];
  }
}

void LoadFromIncBin() {
  auto raw_network = std::make_unique<RawNetwork>();
  std::memcpy(raw_network.get(), gEVALData, sizeof(RawNetwork));

  network = std::make_unique<AlignedNetwork>();
  network->feature_weights = raw_network->feature_weights;
  network->feature_biases = raw_network->feature_biases;
  network->l1_weights = raw_network->l1_weights;
  network->l1_biases = raw_network->l1_biases;
  network->l2_weights = raw_network->l2_weights;
  network->l2_biases = raw_network->l2_biases;
  network->l3_weights = raw_network->l3_weights;
  network->l3_biases = raw_network->l3_biases;

  TransposeWeightsForPackus(network);
}

Score Evaluate(Board &board) {
  auto &state = board.GetState();
  auto &accumulator = *board.GetAccumulator();

  accumulator.ApplyChanges();

  const auto bucket = accumulator.GetOutputBucket(state);

#ifdef BUILD_HAS_SIMD
  constexpr int kI32ChunkSize = sizeof(simd::Vepi16) / sizeof(I32);
  constexpr int kI16ChunkSize = sizeof(simd::Vepi16) / sizeof(I16);
  constexpr int kI8ChunkSize = sizeof(simd::Vepi16) / sizeof(I8);
  constexpr int kF32ChunkSize = sizeof(simd::Vepi16) / sizeof(float);
  constexpr int kFtShift = 9;

  const auto quantise_vector = simd::SetEpi16(arch::kL1Quantization);

  int counter = 0;
  alignas(simd::kAlignment) std::array<U8, arch::kL1Size> feature_output{};
  for (int them = 0; them <= 1; them++) {
    const auto &stm_accumulator = accumulator[state.turn ^ them];
    for (int i = 0; i < arch::kL1Size / 2; i += kI8ChunkSize) {
      // Clip first accumulator values
      const auto accumulator_value = simd::LoadEpi16(&stm_accumulator[i]);
      const auto pair_accumulator_value =
          simd::LoadEpi16(&stm_accumulator[i + arch::kL1Size / 2]);
      const auto clipped_value =
          simd::Clip(accumulator_value, arch::kL1Quantization);
      const auto clipped_pair_value =
          simd::Min(pair_accumulator_value, quantise_vector);

      // Clip second accumulator values
      const auto accumulator_value1 =
          simd::LoadEpi16(&stm_accumulator[i + kI16ChunkSize]);
      const auto pair_accumulator_value1 = simd::LoadEpi16(
          &stm_accumulator[i + arch::kL1Size / 2 + kI16ChunkSize]);
      const auto clipped_value1 =
          simd::Clip(accumulator_value1, arch::kL1Quantization);
      const auto clipped_pair_value1 =
          simd::Min(pair_accumulator_value1, quantise_vector);

      // Perform a left-shift on them and multiply the products using the
      // higher 16 bits
      const auto first_product = simd::MulhiEpi16(
          simd::SlliEpi16(clipped_value, 16 - kFtShift), clipped_pair_value);
      const auto second_product = simd::MulhiEpi16(
          simd::SlliEpi16(clipped_value1, 16 - kFtShift), clipped_pair_value1);

      // Pack the two I16 vectors into an I8 vector, which will clamp negative
      // values to 0 because of unsigned saturation. This is why we didn't clamp
      // the pair values to 0 earlier, effectively saving us an operation.
      auto &features = *reinterpret_cast<simd::Vepi8 *>(
          &feature_output[i + them * arch::kL1Size / 2]);
      features = simd::PackusEpi16(first_product, second_product);
    }
  }

  // Forward the feature layer neurons to the 2nd layer
  alignas(simd::kAlignment) std::array<I32, arch::kL2Size> l1_sums{};
  for (int i = 0; i < arch::kL1Size; i += sizeof(I32) / sizeof(U8)) {
    const auto feature_vector =
        simd::SetEpi32(*std::bit_cast<U32 *>(&feature_output[i]));
    for (int j = 0; j < arch::kL2Size; j += kF32ChunkSize) {
      const auto weight_vector =
          *reinterpret_cast<simd::Vepi32 *>(&network->l1_weights[bucket][j][i]);
      auto &features = *reinterpret_cast<simd::Vepi32 *>(&l1_sums[j]);
      features = simd::DpbusdEpi32(features, feature_vector, weight_vector);
    }
  }

  // Quantisation constants to convert to float
  constexpr float kL1Multiplier =
      1.0f /
      (arch::kFtQuantization * arch::kFtQuantization * arch::kL1Quantization >>
       kFtShift);
  const auto l1_multiplier_vector = simd::SetPs(kL1Multiplier);
  const auto zero_float_vector = simd::ZeroPs(),
             one_float_vector = simd::SetPs(1.0f);

  alignas(simd::kAlignment) std::array<float, arch::kL2Size> l1_output{};
  for (int i = 0; i < arch::kL2Size; i += kF32ChunkSize) {
    const auto bias_vector =
        *reinterpret_cast<simd::Vepf32 *>(&network->l1_biases[bucket][i]);
    const auto float_vector =
        simd::ConvertEpi32ToPs(*reinterpret_cast<simd::Vepi32 *>(&l1_sums[i]));
    const auto casted_sum =
        simd::MultiplyAddPs(float_vector, l1_multiplier_vector, bias_vector);
    auto &features = *reinterpret_cast<simd::Vepf32 *>(&l1_output[i]);
    features = simd::MinPs(simd::MaxPs(casted_sum, zero_float_vector),
                           one_float_vector);
  }

  // Forward the feature layer neurons to the 2nd layer
  alignas(simd::kAlignment) std::array<float, arch::kL3Size> l2_sums{};
  std::memcpy(
      l2_sums.data(), network->l2_biases[bucket].data(), sizeof(l2_sums));

  for (int i = 0; i < arch::kL2Size; i++) {
    const auto l1_vector = simd::SetPs(l1_output[i]);
    for (int j = 0; j < arch::kL3Size; j += kF32ChunkSize) {
      const auto weight_vector =
          *reinterpret_cast<simd::Vepf32 *>(&network->l2_weights[bucket][j][i]);
      auto &features = *reinterpret_cast<simd::Vepf32 *>(&l2_sums[j]);
      features = simd::MultiplyAddPs(weight_vector, l1_vector, features);
    }
  }

  std::array<float, arch::kL3Size> l2_output{};
  for (int i = 0; i < arch::kL3Size; i += kF32ChunkSize) {
    const auto &sum_vector = *reinterpret_cast<simd::Vepf32 *>(&l2_sums[i]);
    auto &features = *reinterpret_cast<simd::Vepf32 *>(&l2_output[i]);
    features = simd::MinPs(simd::MaxPs(sum_vector, zero_float_vector),
                           one_float_vector);
  }

  auto l3_sum = simd::SetPs(0.0f);
  for (int i = 0; i < arch::kL3Size; i += kF32ChunkSize) {
    const auto weight_vector =
        *reinterpret_cast<simd::Vepf32 *>(&network->l3_weights[bucket][i]);
    const auto &l2_vector = *reinterpret_cast<simd::Vepf32 *>(&l2_output[i]);
    l3_sum = simd::MultiplyAddPs(l2_vector, weight_vector, l3_sum);
  }

  const auto l3_output = simd::ReduceAddPs(l3_sum) + network->l3_biases[bucket];

  return l3_output * arch::kEvalScale;

#else
  // Activate the feature layer via pair-wise CReLU multiplication
  std::array<float, arch::kL1Size> feature_output{};
  for (int i = 0; i < arch::kL1Size / 2; i++) {
    const I32 our_value = CReLU(accumulator[turn][i]) *
                          CReLU(accumulator[turn][i + arch::kL1Size / 2]);
    feature_output[i] = our_value / (255.0f * 255.0f);

    const I32 their_value = CReLU(accumulator[!turn][i]) *
                            CReLU(accumulator[!turn][i + arch::kL1Size / 2]);
    feature_output[i + arch::kL1Size / 2] = their_value / (255.0f * 255.0f);
  }

  // Forward the feature layer neurons to the 2nd layer
  std::array<float, arch::kL2Size> l1_output{};
  for (int i = 0; i < arch::kL1Size; i++) {
    for (int j = 0; j < arch::kL2Size; j++) {
      l1_output[j] += feature_output[i] * network->l1_weights[bucket][j][i];
    }
  }

  // Activate 2nd layer neurons
  for (int i = 0; i < arch::kL2Size; i++) {
    l1_output[i] = CReLU(l1_output[i] + network->l1_biases[bucket][i]);
  }

  // Forward the 2nd layer neurons to the 3rd layer
  std::array<float, arch::kL3Size> l2_output{};
  for (int i = 0; i < arch::kL2Size; i++) {
    for (int j = 0; j < arch::kL3Size; j++) {
      l2_output[j] += l1_output[i] * network->l2_weights[bucket][j][i];
    }
  }

  // Activate 3rd layer neurons
  for (int i = 0; i < arch::kL3Size; i++) {
    l2_output[i] = CReLU(l2_output[i] + network->l2_biases[bucket][i]);
  }

  // Forward 3rd layer neurons to output layer
  float l3_output = network->l3_biases[bucket];
  for (int i = 0; i < arch::kL3Size; i++) {
    l3_output += l2_output[i] * network->l3_weights[bucket][i];
  }

  // Scale output
  return static_cast<Score>(l3_output * arch::kEvalScale);
#endif
}

}  // namespace nnue