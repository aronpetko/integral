#include "nnue.h"

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

void LoadFromFile(std::string_view path) {}

void LoadFromIncBin() {
  std::memcpy(&network, gEVALData, sizeof(network));
}

Score Evaluate(const BoardState &state) {
  // Initialize accumulator for both perspectives (White and Black)
  MultiArray<I32, 2, arch::kHiddenLayerSize> accumulator;
  for (int perspective = Color::kWhite; perspective <= Color::kBlack;
       perspective++) {
    for (int i = 0; i < arch::kHiddenLayerSize; i++) {
      // Initialize with feature biases
      accumulator[perspective][i] = network.feature_biases[i];
    }
  }

  for (int piece = PieceType::kPawn; piece <= PieceType::kKing; piece++) {
    // Loop through all pieces that belong to this color
    for (Square square : state.piece_bbs[piece]) {
      const auto piece_color = state.GetPieceColor(square);
      for (int perspective = Color::kWhite; perspective <= Color::kBlack;
           perspective++) {
        // Update accumulator for the current perspective
        for (int i = 0; i < arch::kHiddenLayerSize; i++) {
          const int index =
              GetFeatureIndex(square, piece, piece_color, perspective);
          accumulator[perspective][i] += network.feature_weights[index][i];
        }
      }
    }
  }

  Score eval = 0;
  for (int i = 0; i < arch::kHiddenLayerSize; i++) {
    const Score our_value =
        SquaredReLU(accumulator[state.turn][i]) * network.output_weights[0][i];
    const Score their_value =
        SquaredReLU(accumulator[!state.turn][i]) * network.output_weights[1][i];
    eval += our_value + their_value;
  }

  // De-quantize the evaluation because of our squared activation function
  eval /= arch::kHiddenLayerQuantization;

  // Add final output bias
  eval += network.output_bias;

  // Scale the evaluation
  eval *= arch::kEvalScale;

  // De-quantize again
  eval /= arch::kHiddenLayerQuantization * arch::kOutputQuantization;

  return eval / 2;
}

}  // namespace nnue