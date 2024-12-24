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

[[nodiscard]] float CReLU(float value) {
  return std::clamp<float>(value, 0.0, 1.0f);
}

[[nodiscard]] I32 SCReLU(I16 value) {
  const I32 clipped = std::clamp<I32>(value, 0, 255);
  return clipped * clipped;
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
}

Score Evaluate(Board &board) {
  auto &state = board.GetState();
  auto &accumulator = *board.GetAccumulator();

  accumulator.ApplyChanges();

  const auto turn = state.turn;
  const auto bucket = accumulator.GetOutputBucket(state);

  // Activate the feature layer via pair-wise CReLU multiplication
  std::array<I32, arch::kL1Size> feature_output{};
  for (int i = 0; i < arch::kL1Size / 2; i++) {
    const I32 our_value = SCReLU(accumulator[turn][i]) *
                          SCReLU(accumulator[turn][i + arch::kL1Size / 2]);
    feature_output[i] = our_value;

    const I32 their_value = SCReLU(accumulator[!turn][i]) *
                            SCReLU(accumulator[!turn][i + arch::kL1Size / 2]);
    feature_output[i + arch::kL1Size / 2] = their_value;
  }

  // Forward the feature layer neurons to the 2nd layer
  std::array<float, arch::kL2Size> l1_output{};
  for (int i = 0; i < arch::kL1Size; i++) {
    float dequantized_feature = feature_output[i] / 255.0f; // Dequantize feature output
    for (int j = 0; j < arch::kL2Size; j++) {
      l1_output[j] += dequantized_feature * network->l1_weights[bucket][i][j];
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
      l2_output[j] += l1_output[i] * network->l2_weights[bucket][i][j];
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
}

}  // namespace nnue