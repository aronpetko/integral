#include <fstream>

#include "../shared/nnue/definitions.h"
#include <fmt/format.h>

std::unique_ptr<nnue::Network> ProcessNetwork(
    const std::unique_ptr<nnue::RawNetwork>& raw_network) {
  auto network = std::make_unique<nnue::Network>();

  // Copy over arrays that don't need transposing
  network->feature_weights = raw_network->feature_weights;
  network->feature_biases = raw_network->feature_biases;

#if BUILD_HAS_SIMD and !defined(SPARSE_PERMUTE)
  constexpr int kWeightsPerBlock = sizeof(__m128i) / sizeof(int16_t);
  constexpr int kNumRegs = sizeof(simd::Vepi16) / 8;
  std::array<__m128i, kNumRegs> regs;

  auto weights = reinterpret_cast<__m128i*>(&network->feature_weights);
  auto biases = reinterpret_cast<__m128i*>(&network->feature_biases);

  for (int i = 0; i < nnue::arch::kInputBucketCount * 768 *
                          nnue::arch::kL1Size / kWeightsPerBlock;
       i += kNumRegs) {
    for (int j = 0; j < kNumRegs; j++) regs[j] = weights[i + j];

    for (int j = 0; j < kNumRegs; j++)
      weights[i + j] = regs[simd::kPackusOrder[j]];
  }

  for (int i = 0; i < nnue::arch::kL1Size / kWeightsPerBlock; i += kNumRegs) {
    for (int j = 0; j < kNumRegs; j++) regs[j] = biases[i + j];

    for (int j = 0; j < kNumRegs; j++)
      biases[i + j] = regs[simd::kPackusOrder[j]];
  }
#endif

  network->l1_biases = raw_network->l1_biases;
  network->l2_biases = raw_network->l2_biases;
  network->l3_weights = raw_network->l3_weights;
  network->l3_biases = raw_network->l3_biases;

  // Transpose l1_weights from [b][l2][l1] to [b][l1][l2]
  for (int b = 0; b < nnue::arch::kOutputBucketCount; b++) {
    for (int l1 = 0; l1 < nnue::arch::kL1Size; l1++) {
      for (int l2 = 0; l2 < nnue::arch::kL2Size; l2++) {
        network->l1_weights[b][l1][l2] = raw_network->l1_weights[b][l2][l1];
      }
    }
  }

#if BUILD_HAS_SIMD and !defined(SPARSE_PERMUTE)
  // Weight permutation for DpbusdEpi32
  {
    const auto tmp = std::make_shared<nnue::Network>(*network);
    for (int bucket = 0; bucket < nnue::arch::kOutputBucketCount; bucket++) {
      for (int i = 0; i < nnue::arch::kL1Size; i += 4) {
        for (int j = 0; j < nnue::arch::kL2Size; ++j) {
          for (int k = 0; k < 4; k++) {
            network
                ->l1_weights_alt[bucket][i * nnue::arch::kL2Size + j * 4 + k] =
                tmp->l1_weights[bucket][i + k][j];
          }
        }
      }
    }
  }
#endif

  // Transpose l2_weights from [b][l3][l2] to [b][l2][l3]
  for (int b = 0; b < nnue::arch::kOutputBucketCount; b++) {
    for (int l2 = 0; l2 < nnue::arch::kL2Size * 2; l2++) {
      for (int l3 = 0; l3 < nnue::arch::kL3Size; l3++) {
        network->l2_weights[b][l2][l3] = raw_network->l2_weights[b][l3][l2];
      }
    }
  }

  return network;
}

int main(int argc, char* argv[]) {
  if (argc < 3) {
    fmt::println("Usage: preprocess <input.nnue> <output.nnue>");
    return 1;
  }

  std::string input_path = argv[1];
  std::string output_path = argv[2];

  fmt::println("Preprocessing {}", input_path);

  auto raw_network = std::make_unique<nnue::RawNetwork>();

  std::ifstream input_stream(input_path, std::ios::binary);
  input_stream.read(reinterpret_cast<char*>(raw_network.get()),
                    sizeof(nnue::RawNetwork));

  const auto processed_network = ProcessNetwork(raw_network);

  std::ofstream output_stream(output_path, std::ios::binary | std::ios::ate);
  output_stream.write(reinterpret_cast<char*>(processed_network.get()),
                      sizeof(nnue::Network));

  if (output_stream.bad()) {
    fmt::println("Failed to write processed network");
  } else {
    fmt::println("Successfully wrote processed network to {}", output_path);
  }

  return 0;
}