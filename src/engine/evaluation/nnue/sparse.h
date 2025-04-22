#ifndef INTEGRAL_SPARSE_H
#define INTEGRAL_SPARSE_H

#include <fstream>

#include "../../../../shared/nnue/definitions.h"
#include "../../../chess/bitboard.h"
#include "../../../utils/types.h"
#include "nnue.h"

// #if BUILD_HAS_SIMD
namespace nnue::sparse {

// We store the number and index of each set bit for every possible U8 number
struct NnzEntry {
  std::array<U16, 8> indices;
};

[[nodiscard]] constexpr std::array<NnzEntry, 256> GenerateNnzTable() {
  std::array<NnzEntry, 256> table{};
  for (I16 i = 0; i < 256; i++) {
    // Save the index of every set bit
    int num_bits = 0;
    BitBoard bits = i;
    while (bits) {
      const int set_bit = bits.PopLsb();
      table[i].indices[num_bits++] = set_bit;
    }
  }
  return table;
}

constexpr auto nnz_table = GenerateNnzTable();

#ifdef SPARSE_PERMUTE
//  This is the array where we keep track of the number of pair-wise activated
//  neurons during a bench sequence, to be used for permuting the input and L1
//  weights for maximizing sparse efficiency
inline std::array<int, arch::kL1Size / 2> activations{};

static void CountActivations(
    const std::array<U8, arch::kL1Size>& feature_output) {
  for (int i = 0; i < arch::kL1Size; ++i) {
    activations[i % activations.size()] += feature_output[i] > 0;
  }
}

static void SavePermutedNetwork(std::string output) {
  auto permuted_network = std::make_unique<RawNetwork>();
  std::memcpy(permuted_network.get(), network, sizeof(RawNetwork));

  std::array<int, arch::kL1Size / 2> sorted_neurons;
  // Each neuron is at its own index initially (of course)
  for (int i = 0; i < sorted_neurons.size(); i++) {
    sorted_neurons[i] = i;
  }

  // Sort based on activations
  std::ranges::stable_sort(sorted_neurons, [&](const int& a, const int& b) {
    return activations[a] > activations[b];
  });

  // Permute all weight/biases for neuron pairs
  for (int i = 0; i < sorted_neurons.size(); i++) {
    const int idx = sorted_neurons[i];

    // Feature biases
    permuted_network->feature_biases[i] = network->feature_biases[idx];
    permuted_network->feature_biases[i + arch::kL1Size / 2] =
        network->feature_biases[idx + arch::kL1Size / 2];

    // Feature weights
    for (int bucket = 0; bucket < arch::kInputBucketCount; ++bucket) {
      for (int side = 0; side <= 1; ++side) {
        for (int piece = 0; piece < kNumPieceTypes; ++piece) {
          for (int square = 0; square < kSquareCount; ++square) {
            permuted_network->feature_weights[bucket][side][piece][square][i] =
                network->feature_weights[bucket][side][piece][square][idx];
            permuted_network->feature_weights[bucket][side][piece][square]
                                             [i + arch::kL1Size / 2] =
                network->feature_weights[bucket][side][piece][square]
                                        [idx + arch::kL1Size / 2];
          }
        }
      }
    }

    // L1 Weights
    for (int bucket = 0; bucket < arch::kOutputBucketCount; ++bucket) {
      for (int j = 0; j < arch::kL2Size; ++j) {
        permuted_network->l1_weights[bucket][j][i] =
            network->l1_weights[bucket][j][idx];
        permuted_network->l1_weights[bucket][j][i + arch::kL1Size / 2] =
            network->l1_weights[bucket][j][idx + arch::kL1Size / 2];
      }
    }
  }

  std::ofstream output_stream(output, std::ios::binary);
  output_stream.write(reinterpret_cast<char*>(permuted_network.get()),
                      sizeof(Network));
  output_stream.close();

  fmt::println("Permuted network written to {}", output);
}
#endif

}  // namespace nnue::sparse
// #endif

#endif  // INTEGRAL_SPARSE_H