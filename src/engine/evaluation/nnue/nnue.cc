#include "nnue.h"

#include "accumulator.h"
#include "arch.h"

#if defined(SIMD)
#include "../../../utils/simd.h"
#endif

// This macro invocation will declare the following three variables
//     const unsigned char        gEVALData[];   // a pointer to the embedded
//     data const unsigned char *const gEVALEnd; // a marker to the end
//     const unsigned int         gEVALSize;     // the size of the embedded file
// Note that this does not work in Microsoft Visual Studio.
#if !defined(_MSC_VER)
INCBIN(EVAL, EVALFILE);
#else
const unsigned char gEVALData[1] = {};
const unsigned char* const gEVALEnd = &gEVALData[1];
const unsigned int gEVALSize = 1;
#endif

namespace nnue {

#if !defined(SIMD)
I32 SquaredCReLU(I16 value) {
  const I32 clipped = std::clamp<I32>(
      static_cast<I32>(value), 0, arch::kHiddenLayerQuantization);
  return clipped * clipped;
}
#endif

void LoadFromIncBin() {
  auto raw_network = std::make_unique<RawNetwork>();
  std::memcpy(raw_network.get(), gEVALData, sizeof(RawNetwork));

  network = std::make_unique<TransposedNetwork>();
  network->feature_weights = raw_network->feature_weights;
  network->feature_biases = raw_network->feature_biases;

  // We transpose the output weights from Bullet since we get better cache hits
  // with this layout
  MultiArray<I16, arch::kOutputBucketCount, 2, arch::kHiddenLayerSize>
      transposed_output_weights;
  for (int bucket = 0; bucket < arch::kOutputBucketCount; bucket++) {
    for (Color perspective : {Color::kBlack, Color::kWhite}) {
      for (int weight = 0; weight < arch::kHiddenLayerSize; weight++) {
        transposed_output_weights[bucket][perspective][weight] =
            raw_network->output_weights[perspective][weight][bucket];
      }
    }
  }

  network->output_weights = transposed_output_weights;
  network->output_biases = raw_network->output_biases;
}

Score Evaluate(const BoardState& state,
               std::shared_ptr<Accumulator>& accumulator) {
  const auto turn = state.turn;
  const auto bucket = accumulator->GetOutputBucket(state);

  Score eval;

#if defined(SIMD)
  constexpr int kChunkSize = sizeof(simd::Vepi16) / sizeof(I16);

  auto sum = simd::ZeroEpi32();

  // Compute evaluation from our perspective
  for (int i = 0; i < arch::kHiddenLayerSize; i += kChunkSize) {
    const auto accumulator_value = simd::LoadEpi16(&(*accumulator)[turn][i]);
    const auto weight_value =
        simd::LoadEpi16(&network->output_weights[bucket][0][i]);

    // Clip the accumulator values
    const auto clipped =
        simd::Clip(accumulator_value, arch::kHiddenLayerQuantization);

    // Multiply weights by clipped values (still in i16, no overflow)
    const auto product = simd::MultiplyEpi16(clipped, weight_value);

    // Perform the second multiplication with widening to i32, accumulating the
    // result
    const auto result = simd::MultiplyAddEpi16(product, clipped);

    // Accumulate the results in 32-bit integers
    sum = simd::AddEpi32(sum, result);
  }

  // Compute evaluation from their perspective
  for (int i = 0; i < arch::kHiddenLayerSize; i += kChunkSize) {
    const auto accumulator_value = simd::LoadEpi16(&(*accumulator)[!turn][i]);
    const auto weight_value =
        simd::LoadEpi16(&network->output_weights[bucket][1][i]);

    // Clip the accumulator values
    const auto clipped =
        simd::Clip(accumulator_value, arch::kHiddenLayerQuantization);

    // Multiply weights by clipped values (still in i16, no overflow)
    const auto product = simd::MultiplyEpi16(clipped, weight_value);

    // Perform the second multiplication with widening to i32, accumulating the
    // result
    const auto result = simd::MultiplyAddEpi16(product, clipped);

    // Accumulate the results in 32-bit integers
    sum = simd::AddEpi32(sum, result);
  }

  // Perform a horizontal sum to get the final result
  eval = simd::ReduceAddEpi32(sum);
#else
  eval = 0;
  for (int i = 0; i < arch::kHiddenLayerSize; i++) {
    const Score our_value = SquaredCReLU((*accumulator)[turn][i]) *
                            network->output_weights[bucket][0][i];
    const Score their_value = SquaredCReLU((*accumulator)[!turn][i]) *
                              network->output_weights[bucket][1][i];
    eval += our_value + their_value;
  }
#endif

  // De-quantize the evaluation because of our squared activation function
  eval /= arch::kHiddenLayerQuantization;

  // Add final output bias
  eval += network->output_biases[bucket];

  // Scale the evaluation
  eval *= arch::kEvalScale;

  // De-quantize again
  eval /= arch::kHiddenLayerQuantization * arch::kOutputQuantization;

  return eval;
}

}  // namespace nnue