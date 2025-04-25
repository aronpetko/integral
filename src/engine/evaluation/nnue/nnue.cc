#include "nnue.h"

#include "../../../../shared/nnue/definitions.h"
#include "../../../../shared/simd.h"
#include "accumulator.h"

#ifdef _MSC_VER
#define SP_MSVC
#pragma push_macro("_MSC_VER")
#undef _MSC_VER
#endif

#include "../../../third-party/incbin/incbin.h"
#include "sparse.h"

#ifdef SP_MSVC
#pragma pop_macro("_MSC_VER")
#undef SP_MSVC
#endif

INCBIN(EVAL, EVALFILE);

namespace nnue {

[[nodiscard]] I32 CReLU(I16 value) {
  return std::clamp<I32>(value, 0, arch::kFtQuantization);
}

[[nodiscard]] float CReLU(float value) {
  return std::clamp(value, 0.0f, 1.0f);
}

void LoadFromIncBin() {
  // Load raw network from binary data
  network = reinterpret_cast<Network*>(const_cast<unsigned char*>(gEVALData));
}

Score Evaluate(Board &board) {
  auto &state = board.GetState();
  auto &accumulator = *board.GetAccumulator();

  accumulator.ApplyChanges();
  const auto bucket = accumulator.GetOutputBucket(state);

  constexpr int kFtShift = 9;

#if BUILD_HAS_SIMD and !defined(SPARSE_PERMUTE)
  constexpr int kI32ChunkSize = sizeof(simd::Vepi16) / sizeof(I32);
  constexpr int kI16ChunkSize = sizeof(simd::Vepi16) / sizeof(I16);
  constexpr int kI8ChunkSize = sizeof(simd::Vepi16) / sizeof(I8);
  constexpr int kF32ChunkSize = sizeof(simd::Vepi16) / sizeof(float);

  const auto quantise_vector = simd::SetEpi16(arch::kFtQuantization);

  std::array<U16, arch::kL1Size / 4> nnz_indices{};
  int nnz_count = 0;
  auto nnz_base = _mm_setzero_si128();
  const auto lookup_increment = _mm_set1_epi16(8);

  // Activate the feature layer neurons
  alignas(simd::kAlignment) std::array<U8, arch::kL1Size> feature_output{};
  for (int them = 0; them <= 1; them++) {
    const auto &stm_accumulator = accumulator[state.turn ^ them];
    for (int i = 0; i < arch::kL1Size / 2; i += kI8ChunkSize) {
      // Clip first accumulator values
      const auto accumulator_value = simd::LoadEpi16(&stm_accumulator[i]);
      const auto pair_accumulator_value =
          simd::LoadEpi16(&stm_accumulator[i + arch::kL1Size / 2]);
      const auto clipped_value =
          simd::Clip(accumulator_value, arch::kFtQuantization);
      const auto clipped_pair_value =
          simd::Min(pair_accumulator_value, quantise_vector);

      // Clip second accumulator values
      const auto accumulator_value1 =
          simd::LoadEpi16(&stm_accumulator[i + kI16ChunkSize]);
      const auto pair_accumulator_value1 = simd::LoadEpi16(
          &stm_accumulator[i + arch::kL1Size / 2 + kI16ChunkSize]);
      const auto clipped_value1 =
          simd::Clip(accumulator_value1, arch::kFtQuantization);
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
      // the pair values to 0 earlier, effectively saving us an operation
      auto &features = *reinterpret_cast<simd::Vepi8 *>(
          &feature_output[i + them * arch::kL1Size / 2]);
      features = simd::PackusEpi16(first_product, second_product);

      // Sparse Processing, or NNZ (Number of Non-Zero), is an optimization we
      // perform to minimize the amount of computation done by only mat-mulling
      // the positive, non-zero activated features with the next layer's weights
      // -----------------------------------------------------------------------
      // Get a mask of all positive, non-zero elements
      // Each bit in `nnz_mask` corresponds to whether a specific feature is
      // positive (1) or zero (0)
      const auto nnz_mask = simd::GetNnzMask(features);
      // Loop through 8-bit (U8) slices of this 16-bit mask
      for (int chunk = 0; chunk < kI32ChunkSize; chunk += 8) {
        // Extract the 8-bit slice from the mask
        const U8 slice = (nnz_mask >> chunk) & 0xFF;
        // Lookup the relative indices for each set bit in the mask, essentially
        // retrieving the indices for each positive element as an 8-element
        // vector of I16s
        const auto indices = _mm_loadu_si128(reinterpret_cast<const __m128i *>(
            &sparse::nnz_table[slice].indices));
        // Store these absolute indices into our table. We account for the fact
        // that they are relative indices (to this slice) by adding `nnz_base`,
        // which will reflect the position each element is in the entire table
        _mm_storeu_si128(reinterpret_cast<__m128i *>(&nnz_indices[nnz_count]),
                         _mm_add_epi16(nnz_base, indices));
        // Update to reflect the total number of non-zero features processed
        nnz_count += BitBoard(slice).PopCount();
        // Increment to reflect the starting index of the next slice
        nnz_base = _mm_add_epi16(nnz_base, lookup_increment);
      }
    }
  }

#ifdef SPARSE_PERMUTE
  sparse::CountActivations(feature_output);
#endif

  // Forward the feature layer neurons to the 2nd layer
  alignas(simd::kAlignment) std::array<I32, arch::kL2Size> l1_sums{};
  {
    int i = 0;
    for (; i < nnz_count - 1; i += 2) {
      const int idx = nnz_indices[i] * 4, idx_two = nnz_indices[i + 1] * 4;
      const auto feature_vector =
          simd::SetEpi32(*reinterpret_cast<I32 *>(&feature_output[idx]));
      const auto feature_vector_two =
          simd::SetEpi32(*reinterpret_cast<I32 *>(&feature_output[idx_two]));
      for (int j = 0; j < arch::kL2Size; j += kI32ChunkSize) {
        const auto weight_vector = *reinterpret_cast<simd::Vepi8 *>(
            &network->l1_weights[bucket][idx + j / 4]);
        const auto weight_vector_two = *reinterpret_cast<simd::Vepi8 *>(
            &network->l1_weights[bucket][idx_two + j / 4]);
        auto &features = *reinterpret_cast<simd::Vepi32 *>(&l1_sums[j]);
        features = simd::DpbusdEpi32x2(features,
                                       feature_vector,
                                       weight_vector,
                                       feature_vector_two,
                                       weight_vector_two);
      }
    }

    // Handle the remaining features
    for (; i < nnz_count; i++) {
      const int idx = nnz_indices[i] * 4;
      const auto feature_vector =
          simd::SetEpi32(*reinterpret_cast<I32 *>(&feature_output[idx]));
      for (int j = 0; j < arch::kL2Size; j += kI32ChunkSize) {
        const auto weight_vector = *reinterpret_cast<simd::Vepi8 *>(
            &network->l1_weights[bucket][idx + j / 4]);
        auto &features = *reinterpret_cast<simd::Vepi32 *>(&l1_sums[j]);
        features = simd::DpbusdEpi32(features, feature_vector, weight_vector);
      }
    }
  }

  // Quantisation constants to convert to float
  constexpr float kL1Normalization =
      static_cast<float>(1 << kFtShift) /
      static_cast<float>(arch::kFtQuantization * arch::kFtQuantization *
                         arch::kL1Quantization);
  const auto l1_multiplier_vector = simd::SetPs(kL1Normalization);
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
  alignas(simd::kAlignment) std::array<float, arch::kL3Size> l2_sums;
  std::memcpy(
      l2_sums.data(), network->l2_biases[bucket].data(), sizeof(l2_sums));

  for (int i = 0; i < arch::kL2Size; i++) {
    const auto l1_vector = simd::SetPs(l1_output[i]);
    for (int j = 0; j < arch::kL3Size; j += kF32ChunkSize) {
      const auto weight_vector =
          *reinterpret_cast<simd::Vepf32 *>(&network->l2_weights[bucket][i][j]);
      auto &features = *reinterpret_cast<simd::Vepf32 *>(&l2_sums[j]);
      features = simd::MultiplyAddPs(weight_vector, l1_vector, features);
    }
  }

  alignas(simd::kAlignment) std::array<float, arch::kL3Size> l2_output{};
  for (int i = 0; i < arch::kL3Size; i += kF32ChunkSize) {
    const auto &sum_vector = *reinterpret_cast<simd::Vepf32 *>(&l2_sums[i]);
    auto &features = *reinterpret_cast<simd::Vepf32 *>(&l2_output[i]);
    features = simd::MinPs(simd::MaxPs(sum_vector, zero_float_vector),
                           one_float_vector);
  }

  // Forward the feature layer neurons to the 3rd (final) layer
  constexpr int kResultChunks = 64 / sizeof(simd::Vepf32);
  const auto zero_ps = simd::SetPs(0.0f);

  alignas(simd::kAlignment) std::array<simd::Vepf32, kResultChunks> result_sums;
  result_sums.fill(zero_ps);

  for (int i = 0; i < arch::kL3Size / kF32ChunkSize; i += kResultChunks) {
    for (int chunk = 0; chunk < kResultChunks; chunk++) {
      const auto weight_vector = *reinterpret_cast<simd::Vepf32 *>(
          &network->l3_weights[bucket][(i + chunk) * kF32ChunkSize]);
      const auto &l2_vector = *reinterpret_cast<simd::Vepf32 *>(
          &l2_output[(i + chunk) * kF32ChunkSize]);
      result_sums[chunk] =
          simd::MultiplyAddPs(l2_vector, weight_vector, result_sums[chunk]);
    }
  }

  const auto l3_output =
      simd::ReduceAddPs(result_sums.data()) + network->l3_biases[bucket];

  return static_cast<Score>(l3_output * arch::kEvalScale);
#else
  // Activate the feature layer via pair-wise CReLU multiplication
  std::array<U8, arch::kL1Size> feature_output{};
  for (int them = 0; them <= 1; them++) {
    const auto &stm_accumulator = accumulator[state.turn ^ them];
    for (int i = 0; i < arch::kL1Size / 2; i++) {
      const auto first_val = CReLU(stm_accumulator[i]);
      const auto second_val = CReLU(stm_accumulator[i + arch::kL1Size / 2]);

      const auto product = (first_val * second_val) >> 9;
      feature_output[i + them * arch::kL1Size / 2] = static_cast<U8>(product);
    }
  }

#ifdef SPARSE_PERMUTE
  //sparse::CountActivations(feature_output);
  sparse::CountSparsity(feature_output);
#endif

  const float kL1Normalization =
      static_cast<float>(1 << kFtShift) /
      static_cast<float>(arch::kFtQuantization * arch::kFtQuantization *
                         arch::kL1Quantization);

  // Forward the feature layer neurons to the 2nd layer
  std::array<I32, arch::kL2Size> l1_sums{};
  for (int i = 0; i < arch::kL1Size; i++) {
    if (!feature_output[i]) continue;

    for (int j = 0; j < arch::kL2Size; j++) {
      l1_sums[j] += feature_output[i] * network->l1_weights[bucket][i][j];
    }
  }

  // Activate 2nd layer neurons
  std::array<float, arch::kL2Size> l1_output{};
  for (int i = 0; i < arch::kL2Size; i++) {
    l1_output[i] = CReLU(static_cast<float>(l1_sums[i]) * kL1Normalization +
                         network->l1_biases[bucket][i]);
  }

  // Forward the 2nd layer neurons to the 3rd layer
  std::array<float, arch::kL3Size> l2_output{};
  std::memcpy(
      l2_output.data(), network->l2_biases[bucket].data(), sizeof(l2_output));
  for (int i = 0; i < arch::kL2Size; i++) {
    for (int j = 0; j < arch::kL3Size; j++) {
      l2_output[j] = std::fma(
          l1_output[i], network->l2_weights[bucket][i][j], l2_output[j]);
    }
  }

  // Forward 3rd layer neurons to output layer
  constexpr int kResultChunks = 64 / sizeof(float);
  std::array<float, kResultChunks> result_sums{};

  for (int i = 0; i < arch::kL3Size; i += kResultChunks) {
    for (int chunk = 0; chunk < kResultChunks; chunk++) {
      const float activated = CReLU(l2_output[i + chunk]);
      result_sums[chunk] = std::fma(activated,
                                    network->l3_weights[bucket][i + chunk],
                                    result_sums[chunk]);
    }
  }

  const float l3_output =
      network->l3_biases[bucket] +
      simd::ReduceAddPsRecursive(result_sums.data(), kResultChunks);

  // Scale output
  return static_cast<Score>(l3_output * arch::kEvalScale);
#endif
}

}  // namespace nnue