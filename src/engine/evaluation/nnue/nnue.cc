#include "nnue.h"

#include <immintrin.h>

#include "accumulator.h"
#include "arch.h"

#define SIMD

#if defined(SIMD)
#include <immintrin.h>
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
I16 HorizontalSum(__m256i v) {
  // Sum 16-bit integers into 32-bit integers
  __m256i sum = _mm256_madd_epi16(v, _mm256_set1_epi16(1));

  // Sum 32-bit integers
  __m128i sum_128 = _mm_add_epi32(_mm256_castsi256_si128(sum), _mm256_extracti128_si256(sum, 1));
  sum_128 = _mm_add_epi32(sum_128, _mm_shuffle_epi32(sum_128, _MM_SHUFFLE(1, 0, 3, 2)));
  sum_128 = _mm_add_epi32(sum_128, _mm_shuffle_epi32(sum_128, _MM_SHUFFLE(0, 1, 0, 1)));

  // Extract the final sum
  return static_cast<I16>(_mm_cvtsi128_si32(sum_128));
}

__m256i SquaredReLU(__m256i value) {
  const __m256i zero = _mm256_setzero_si256();
  const __m256i max_value = _mm256_set1_epi16(arch::kHiddenLayerQuantization);

  // Clip the value between 0 and max_value
  const __m256i clipped =
      _mm256_min_epi16(_mm256_max_epi16(value, zero), max_value);

  // Square the clipped values
  // Since we're working with 16-bit integers, we need to be careful about
  // overflow We'll use _mm256_mullo_epi16 which does element-wise
  // multiplication of 16-bit integers and stores the lower 16 bits of the
  // 32-bit results
  return _mm256_mullo_epi16(clipped, clipped);
}
#else
I16 SquaredReLU(I16 value) {
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
  const Color turn = accumulator->GetTurn();
  const int bucket = accumulator->GetOutputBucket();

  Score eval;

#if defined(SIMD)
  constexpr int kChunkSize = sizeof(__m256i) / sizeof(I16);

  auto vector_eval = _mm256_setzero_si256();
  // Compute evaluation from our perspective
  for (int i = 0; i < arch::kHiddenLayerSize; i += kChunkSize) {
    const __m256i accumulator_value =
        _mm256_loadu_epi16(&(*accumulator)[turn][i]);
    const __m256i weight_value =
        _mm256_loadu_epi16(&network.output_weights[bucket][0][i]);
    vector_eval = _mm256_add_epi16(
        vector_eval, _mm256_mullo_epi16(accumulator_value, weight_value));
  }

  // Compute evaluation from their perspective
  for (int i = 0; i < arch::kHiddenLayerSize; i += kChunkSize) {
    const __m256i accumulator_value =
        _mm256_loadu_epi16(&(*accumulator)[!turn][i]);
    const __m256i weight_value =
        _mm256_loadu_epi16(&network.output_weights[bucket][1][i]);
    vector_eval = _mm256_add_epi16(
        vector_eval, _mm256_mullo_epi16(accumulator_value, weight_value));
  }

  eval = HorizontalSum(vector_eval);
#else
  eval = 0;
  for (int i = 0; i < arch::kHiddenLayerSize; i++) {
    const Score our_value = SquaredReLU((*accumulator)[turn][i]) *
                            network.output_weights[bucket][0][i];
    const Score their_value = SquaredReLU((*accumulator)[!turn][i]) *
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