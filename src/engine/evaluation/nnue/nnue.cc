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

[[nodiscard]] I32 SCReLU(I16 value) {
  const auto clipped = std::clamp<I32>(value, 0, arch::kQA);
  return clipped * clipped;
}

[[nodiscard]] float CReLU(float value) {
  return std::clamp(value, 0.0f, 1.0f);
}

void LoadFromIncBin() {
  // Load raw network from binary data
  network = reinterpret_cast<Network *>(const_cast<unsigned char *>(gEVALData));
}

Score Evaluate(Board &board) {
  auto &state = board.GetState();
  auto &accumulator = *board.GetAccumulator();

  accumulator.ApplyChanges();
  const auto bucket = accumulator.GetOutputBucket(state);

  Score eval = 0;
  for (int i = 0; i < arch::kL1Size; i++) {
    const Score our_value = SCReLU(accumulator[state.turn][i]) *
                            network->output_weights[bucket][0][i];
    const Score their_value = SCReLU(accumulator[FlipColor(state.turn)][i]) *
                              network->output_weights[bucket][1][i];
    eval += our_value + their_value;
  }

  // De-quantize the evaluation because of our squared activation function
  eval /= arch::kQA;

  // Add final output bias
  eval += network->output_biases[bucket];

  // Scale the evaluation
  eval *= arch::kEvalScale;

  // De-quantize again
  eval /= arch::kQA * arch::kQB;

  return eval;
}

}  // namespace nnue