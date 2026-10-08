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

// Fixed-point layout of the integer layers after the feature transform
constexpr int kQBits = 6;
constexpr int kPrecisionMargin = 6;
constexpr int kL1Shift = 8;
constexpr I32 kL1One = 1 << (kL1Shift + kQBits);
constexpr I32 kL2One = 1 << (3 * kQBits);
constexpr I64 kOutputDivisor = static_cast<I64>(arch::kQuantization) *
                               arch::kQuantization * arch::kQuantization *
                               arch::kQuantization;

[[nodiscard]] Score Propagate(const std::array<I32, arch::kL2Size> &l1_sums,
                              int bucket) {
  // Each neuron is activated by both a clipped ReLU and a clipped square
  std::array<I32, 2 * arch::kL2Size> l1_output;
  for (int i = 0; i < arch::kL2Size; ++i) {
    const I32 biased = l1_sums[i] + network->l1_biases[bucket][i];
    const I32 clipped = std::clamp(biased, -kL1One, kL1One);
    l1_output[i] = std::clamp(biased, 0, kL1One)
                << (kQBits + kPrecisionMargin - kL1Shift);
    l1_output[i + arch::kL2Size] =
        (clipped * clipped) >> (2 * kL1Shift - kPrecisionMargin);
  }

  std::array<I32, arch::kL3Size> l2_sums{};
  for (int i = 0; i < 2 * arch::kL2Size; ++i) {
    for (int j = 0; j < arch::kL3Size; ++j) {
      l2_sums[j] += l1_output[i] * network->l2_weights[bucket][i][j];
    }
  }

  I32 l3_sum = 0;
  for (int j = 0; j < arch::kL3Size; ++j) {
    const I32 activated = std::clamp(
        (l2_sums[j] >> kPrecisionMargin) + network->l2_biases[bucket][j],
        0,
        kL2One);
    l3_sum += activated * network->l3_weights[bucket][j];
  }

  const I64 output =
      static_cast<I64>(l3_sum + network->l3_biases[bucket]) * arch::kEvalScale;
  return static_cast<Score>(std::clamp<I64>(output / kOutputDivisor,
                                            -kTBWinInMaxPlyScore + 1,
                                            kTBWinInMaxPlyScore - 1));
}

void LoadFromIncBin() {
  if (gEVALSize != sizeof(Network)) {
    fmt::println("Invalid embedded network size: {} bytes; expected {}",
                 gEVALSize,
                 sizeof(Network));
    std::abort();
  }
  // Load the preprocessed network from embedded binary data
  network = reinterpret_cast<Network *>(const_cast<unsigned char *>(gEVALData));
}

Score Evaluate(Board &board) {
  auto &state = board.GetState();
  auto &accumulator = *board.GetAccumulator();

  accumulator.ApplyChanges(state);
  const auto bucket = accumulator.GetOutputBucket(state);

  constexpr int kFtShift = 9;

  alignas(simd::kAlignment) std::array<I32, arch::kL2Size> l1_sums{};
  const I8 *l1_weights = network->l1_weights[bucket].data();

#if BUILD_HAS_SIMD and !defined(SPARSE_PERMUTE)
  constexpr int kI32Lanes = simd::kNativeLanes<I32>;
  constexpr int kI16Lanes = simd::kNativeLanes<I16>;
  constexpr int kI8Lanes = simd::kNativeLanes<I8>;

  const auto quantise_vector = simd::Set<I16>(arch::kFtQuantization);

  std::array<U16, arch::kL1Size / 4> nnz_indices;
  int nnz_count = 0;
  auto nnz_base = simd::Zero<U16, 8>();
  const auto lookup_increment = simd::Set<U16, 8>(8);

  // Activate the feature layer neurons
  alignas(simd::kAlignment) std::array<U8, arch::kL1Size> feature_output;
  for (int them = 0; them <= 1; them++) {
    const auto perspective = static_cast<Color>(state.turn ^ them);
    const auto &stm_accumulator = accumulator[perspective];

    const auto load_neurons = [&](int idx) {
      return simd::Load<I16>(&stm_accumulator.psqt[idx]) +
             simd::Load<I16>(&stm_accumulator.threat[idx]);
    };

    for (int i = 0; i < arch::kL1Size / 2; i += kI8Lanes) {
      // Clip first accumulator values
      const auto accumulator_value = load_neurons(i);
      const auto pair_accumulator_value = load_neurons(i + arch::kL1Size / 2);

      const auto clipped_value =
          simd::Clip(accumulator_value, arch::kFtQuantization);
      const auto clipped_pair_value =
          simd::Min(pair_accumulator_value, quantise_vector);

      // Clip second accumulator values
      const auto accumulator_value1 = load_neurons(i + kI16Lanes);
      const auto pair_accumulator_value1 =
          load_neurons(i + arch::kL1Size / 2 + kI16Lanes);
      const auto clipped_value1 =
          simd::Clip(accumulator_value1, arch::kFtQuantization);
      const auto clipped_pair_value1 =
          simd::Min(pair_accumulator_value1, quantise_vector);

      // Perform a left-shift on them and multiply the products using the
      // higher 16 bits
      const auto first_product = simd::MulhiEpi16(
          clipped_value << (16 - kFtShift), clipped_pair_value);
      const auto second_product = simd::MulhiEpi16(
          clipped_value1 << (16 - kFtShift), clipped_pair_value1);

      // Pack the two I16 vectors into a U8 vector, which will clamp negative
      // values to 0 because of unsigned saturation. This is why we didn't
      // clamp the pair values to 0 earlier, effectively saving us an
      // operation
      auto &features =
          simd::AsVector<U8>(&feature_output[i + them * arch::kL1Size / 2]);
      features = simd::PackusEpi16(first_product, second_product);

      // Sparse Processing, or NNZ (Number of Non-Zero), is an optimization we
      // perform to minimize the amount of computation done by only
      // mat-mulling the positive, non-zero activated features with the next
      // layer's weights
      // -----------------------------------------------------------------------
      // Get a mask of all positive, non-zero elements
      // Each bit in `nnz_mask` corresponds to whether a specific feature is
      // positive (1) or zero (0)
      const auto nnz_mask = simd::NonZeroMask(simd::Cast<I32>(features));
      // Loop through 8-bit (U8) slices of this 16-bit mask
      for (int chunk = 0; chunk < kI32Lanes; chunk += 8) {
        // Extract the 8-bit slice from the mask
        const U8 slice = (nnz_mask >> chunk) & 0b11111111;
        // Lookup the relative indices for each set bit in the mask,
        // essentially retrieving the indices for each positive element as an
        // 8-element vector of I16s
        const auto indices =
            simd::Load<U16, 8>(sparse::nnz_table[slice].indices.data());
        // Store these absolute indices into our table. We account for the
        // fact that they are relative indices (to this slice) by adding
        // `nnz_base`, which will reflect the position each element is in the
        // entire table
        simd::Store<U16, 8>(&nnz_indices[nnz_count], nnz_base + indices);
        // Update to reflect the total number of non-zero features processed
        nnz_count += BitBoard(slice).PopCount();
        // Increment to reflect the starting index of the next slice
        nnz_base += lookup_increment;
      }
    }
  }

  // Forward the feature layer neurons to the 2nd layer. The weights of each
  // group of 4 inputs are laid out as kL2Size outputs of 4 bytes each
  {
    int i = 0;
    for (; i < nnz_count - 1; i += 2) {
      const int idx = nnz_indices[i] * 4, idx_two = nnz_indices[i + 1] * 4;
      const auto feature_vector = simd::Cast<U8>(
          simd::Set(*reinterpret_cast<I32 *>(&feature_output[idx])));
      const auto feature_vector_two = simd::Cast<U8>(
          simd::Set(*reinterpret_cast<I32 *>(&feature_output[idx_two])));
      for (int j = 0; j < arch::kL2Size; j += kI32Lanes) {
        const auto weight_vector =
            simd::Load<I8>(&l1_weights[idx * arch::kL2Size + j * 4]);
        const auto weight_vector_two =
            simd::Load<I8>(&l1_weights[idx_two * arch::kL2Size + j * 4]);
        auto &features = simd::AsVector<I32>(&l1_sums[j]);
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
      const auto feature_vector = simd::Cast<U8>(
          simd::Set(*reinterpret_cast<I32 *>(&feature_output[idx])));
      for (int j = 0; j < arch::kL2Size; j += kI32Lanes) {
        const auto weight_vector =
            simd::Load<I8>(&l1_weights[idx * arch::kL2Size + j * 4]);
        auto &features = simd::AsVector<I32>(&l1_sums[j]);
        features = simd::DpbusdEpi32(features, feature_vector, weight_vector);
      }
    }
  }
#else
  // Activate the feature layer via pair-wise CReLU multiplication
  std::array<U8, arch::kL1Size> feature_output{};
  for (int them = 0; them <= 1; them++) {
    const auto perspective = static_cast<Color>(state.turn ^ them);
    const auto &stm_accumulator = accumulator[perspective];
    for (int i = 0; i < arch::kL1Size / 2; i++) {
      const auto first_val = CReLU(
          static_cast<I16>(stm_accumulator.psqt[i] + stm_accumulator.threat[i]));
      const auto second_val =
          CReLU(static_cast<I16>(stm_accumulator.psqt[i + arch::kL1Size / 2] +
                                 stm_accumulator.threat[i + arch::kL1Size / 2]));

      const auto product = (first_val * second_val) >> kFtShift;
      feature_output[i + them * arch::kL1Size / 2] = static_cast<U8>(product);
    }
  }

#ifdef SPARSE_PERMUTE
  sparse::CountActivations(feature_output);
#endif

  // Forward the feature layer neurons to the 2nd layer
  for (int i = 0; i < arch::kL1Size; i++) {
    if (!feature_output[i]) continue;

    for (int j = 0; j < arch::kL2Size; j++) {
      l1_sums[j] += feature_output[i] *
                    l1_weights[i / 4 * 4 * arch::kL2Size + j * 4 + i % 4];
    }
  }
#endif

  return Propagate(l1_sums, bucket);
}

}  // namespace nnue