#include "nnue.h"

#include "accumulator.h"
#include "arch.h"

#define SIMD

#if defined(SIMD)
#include "../../../utils/simd.h"
#endif

// This macro invocation will declare the following three variables
//     const unsigned char        gEVALData[];  // a pointer to the embedded
//     data const unsigned char *const gEVALEnd;     // a marker to the end
//     const unsigned int         gEVALSize;    // the size of the embedded file
// Note that this does not work in Microsoft Visual Studio.
#if !defined(_MSC_VER)
INCBIN(EVAL, EVALFILE);
#else
const unsigned char gEVALData[1] = {};
const unsigned char *const gEVALEnd = &gEVALData[1];
const unsigned int gEVALSize = 1;
#endif

namespace nnue {

#if defined(SIMD)
I32 HorizontalSum(vepi32 vector) {
  auto high128 = _mm256_extracti128_si256(vector, 1);
  auto low128 = _mm256_castsi256_si128(vector);

  auto sum128 = _mm_add_epi32(high128, low128);
  // copies the highest 64 bits twice into a 128 vector
  auto high64 = _mm_unpackhi_epi64(sum128, sum128);

  // we sum together the 64 least significant bits because those are the ones
  // that matter bottom 64 bits store the 2 important numbers
  auto sum64 = _mm_add_epi32(sum128, high64);

  // take the highest 32 bits and places thin into the least significant 32 bits
  // in a 128 vector the shuffle operation does this
  const auto high32 = _mm_shuffle_epi32(sum64, _MM_SHUFFLE(2, 3, 0, 1));

  // adds the two important numbers up
  const auto sum32 = _mm_add_epi32(sum64, high32);

  // extracts the sum
  return _mm_cvtsi128_si32(sum32);
}
#else
I16 SquaredCReLU(I16 value) {
  const I16 clipped = std::clamp<I16>(
      static_cast<I16>(value), 0, arch::kHiddenLayerQuantization);
  return clipped * clipped;
}
#endif

void LoadFromIncBin() {
  RawNetwork raw_network;
  std::memcpy(&raw_network, gEVALData, sizeof(raw_network));

  network.feature_weights = raw_network.feature_weights;
  network.feature_biases = raw_network.feature_biases;

  // We transpose the output weights from Bullet since we get better cache hits
  // with this layout
  MultiArray<I16, arch::kOutputBucketCount, 2, arch::kHiddenLayerSize>
      transposed_output_weights;
  for (int bucket = 0; bucket < arch::kOutputBucketCount; bucket++) {
    for (Color perspective : {Color::kBlack, Color::kWhite}) {
      for (int weight = 0; weight < arch::kHiddenLayerSize; weight++) {
        transposed_output_weights[bucket][perspective][weight] =
            raw_network.output_weights[perspective][weight][bucket];
      }
    }
  }

  network.output_weights = transposed_output_weights;
  network.output_biases = raw_network.output_biases;
}

Score Evaluate(std::shared_ptr<Accumulator> &accumulator) {
  const auto turn = accumulator->GetTurn();
  const auto bucket = accumulator->GetOutputBucket();

  Score eval;

#if defined(SIMD)
  constexpr int kChunkSize = sizeof(__m256i) / sizeof(I16);

  auto sum = zero_epi32();

  // Compute evaluation from our perspective
  for (int i = 0; i < arch::kHiddenLayerSize; i += kChunkSize) {
    const auto accumulator_value = load_epi16(&(*accumulator)[turn][i]);
    const auto weight_value = load_epi16(&network.output_weights[bucket][0][i]);

    // Clip the accumulator values
    const auto clipped =
        clip(accumulator_value, arch::kHiddenLayerQuantization);

    // Multiply weights by clipped values (still in i16, no overflow)
    const auto product = multiply_epi16(clipped, weight_value);

    // Perform the second multiplication with widening to i32, accumulating the
    // result
    const auto result = multiply_add_epi16(product, clipped);

    // Accumulate the results in 32-bit integers
    sum = add_epi32(sum, result);
  }

  // Compute evaluation from their perspective
  for (int i = 0; i < arch::kHiddenLayerSize; i += kChunkSize) {
    const auto accumulator_value = load_epi16(&(*accumulator)[!turn][i]);
    const auto weight_value = load_epi16(&network.output_weights[bucket][1][i]);

    // Clip the accumulator values
    const auto clipped =
        clip(accumulator_value, arch::kHiddenLayerQuantization);

    // Multiply weights by clipped values (still in i16, no overflow)
    const auto product = multiply_epi16(clipped, weight_value);

    // Perform the second multiplication with widening to i32, accumulating the
    // result
    const auto result = multiply_add_epi16(product, clipped);

    // Accumulate the results in 32-bit integers
    sum = add_epi32(sum, result);
  }

  // Perform a horizontal sum to get the final result
  eval = HorizontalSum(sum);
#else
  eval = 0;
  for (int i = 0; i < arch::kHiddenLayerSize; i++) {
    const Score our_value = SquaredCReLU((*accumulator)[turn][i]) *
                            network.output_weights[bucket][0][i];
    const Score their_value = SquaredCReLU((*accumulator)[!turn][i]) *
                              network.output_weights[bucket][1][i];
    eval += our_value + their_value;
  }
#endif

  // De-quantize the evaluation because of our squared activation function
  eval /= arch::kHiddenLayerQuantization;

  // Add final output bias
  eval += network.output_biases[bucket];

  // Scale the evaluation
  eval *= arch::kEvalScale;

  // De-quantize again
  eval /= arch::kHiddenLayerQuantization * arch::kOutputQuantization;

  return eval;
}

}  // namespace nnue