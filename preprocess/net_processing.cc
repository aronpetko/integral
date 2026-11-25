#include <fmt/format.h>

#include <fstream>

#include "../shared/nnue/definitions.h"

template <typename T>
void PermuteForPackus(void* data, std::size_t bytes) {
  using Block = simd::Vector<T, 8>;
  constexpr std::size_t kBlocksPerGroup = 8;

  auto blocks = static_cast<Block*>(data);
  for (std::size_t i = 0; i < bytes / sizeof(Block); i += kBlocksPerGroup) {
    std::array<Block, kBlocksPerGroup> group{};
    std::copy_n(blocks + i, kBlocksPerGroup, group.begin());

    for (std::size_t j = 0; j < kBlocksPerGroup; j++) {
      blocks[i + j] = group[simd::kAVX512PackusOrder[j]];
    }
  }
}

std::unique_ptr<nnue::Network> ProcessNetwork(
    const std::unique_ptr<nnue::RawNetwork>& raw_network) {
  auto network = std::make_unique<nnue::Network>();

  // Copy over arrays that don't need transposing
  network->pst_weights = raw_network->pst_weights;
  for (int h = 0; h < nnue::arch::kHmcBucketCount; ++h) {
    network->hmc_weights[h] = raw_network->hmc_weights[h];
  }
  network->pst_biases = raw_network->pst_biases;
  network->threat_weights = raw_network->threat_weights;

#if BUILD_HAS_SIMD and !defined(SPARSE_PERMUTE)
  PermuteForPackus<I16>(&network->pst_weights, sizeof(network->pst_weights));
  PermuteForPackus<I16>(&network->pst_biases, sizeof(network->pst_biases));
  PermuteForPackus<I16>(&network->hmc_weights, sizeof(network->hmc_weights));
  PermuteForPackus<I8>(&network->threat_weights,
                       sizeof(network->threat_weights));
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
    for (int l2 = 0; l2 < nnue::arch::kL2Size; l2++) {
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

  std::ifstream input_stream(input_path, std::ios::binary | std::ios::ate);
  if (!input_stream) {
    fmt::println("Failed to open network: {}", input_path);
    return 1;
  }

  constexpr std::size_t raw_size = sizeof(nnue::RawNetwork);
  constexpr std::size_t padded_size = (raw_size + 63) / 64 * 64;

  const auto input_size = input_stream.tellg();
  if (input_size != static_cast<std::streamoff>(raw_size) &&
      input_size != static_cast<std::streamoff>(padded_size)) {
    fmt::println(
        "Invalid network size: {} bytes; expected {} or {} (Bullet padding)",
        static_cast<long long>(input_size),
        raw_size,
        padded_size);
    return EXIT_FAILURE;
  }

  input_stream.seekg(0);
  input_stream.read(reinterpret_cast<char*>(raw_network.get()),
                    sizeof(nnue::RawNetwork));
  if (!input_stream) {
    fmt::println("Failed to read complete network: {}", input_path);
    return EXIT_FAILURE;
  }

  const auto processed_network = ProcessNetwork(raw_network);

  std::ofstream output_stream(output_path, std::ios::binary | std::ios::ate);
  output_stream.write(reinterpret_cast<char*>(processed_network.get()),
                      sizeof(nnue::Network));

  output_stream.close();
  if (!output_stream) {
    fmt::println("Failed to write processed network");
    return 1;
  } else {
    fmt::println("Successfully wrote processed network to {}", output_path);
  }

  return 0;
}