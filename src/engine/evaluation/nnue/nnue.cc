#include "nnue.h"

#include "accumulator.h"
#include "arch.h"

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

I32 SquaredReLU(I16 value) {
  const I32 clipped = std::clamp<I32>(
      static_cast<I32>(value), 0, arch::kHiddenLayerQuantization);
  return clipped * clipped;
}

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
            raw_network.output_weights[perspective][bucket][weight];
      }
    }
  }

  network.output_biases = raw_network.output_biases;
}

Score Evaluate(std::shared_ptr<Accumulator> &accumulator) {
  const Color turn = accumulator->GetTurn();
  const int bucket = accumulator->GetOutputBucket();

  Score eval = 0;
  for (int i = 0; i < arch::kHiddenLayerSize; i++) {
    const Score our_value = SquaredReLU((*accumulator)[turn][i]) *
                            network.output_weights[bucket][0][i];
    const Score their_value = SquaredReLU((*accumulator)[!turn][i]) *
                              network.output_weights[bucket][1][i];
    eval += our_value + their_value;
  }

  // De-quantize the evaluation because of our squared activation function
  eval /= arch::kHiddenLayerQuantization;

  // Add final output bias
  eval += network.output_biases[bucket];

  // Scale the evaluation
  eval *= arch::kEvalScale;

  // De-quantize again
  eval /= arch::kHiddenLayerQuantization * arch::kOutputQuantization;

  return eval / 2;
}

}  // namespace nnue