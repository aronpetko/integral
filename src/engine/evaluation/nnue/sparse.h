#ifndef INTEGRAL_SPARSE_H
#define INTEGRAL_SPARSE_H

#include <algorithm>
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

alignas(simd::kAlignment) constexpr auto nnz_table = GenerateNnzTable();

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

// Moves neuron pair `order[i]` to slot `i` within one L1-wide row. The same
// mapping works for the FT (where the halves are the two sides of each pair)
// and for L1's inputs (where the halves are the stm and ntm pair outputs)
template <typename T>
static void PermuteRow(const T* src,
                       T* dst,
                       const std::array<int, arch::kL1Size / 2>& order) {
  constexpr int kHalf = arch::kL1Size / 2;
  for (int i = 0; i < kHalf; ++i) {
    dst[i] = src[order[i]];
    dst[i + kHalf] = src[order[i] + kHalf];
  }
}

// In SPARSE_PERMUTE builds the preprocessor skips all SIMD reordering, so the
// embedded network is in plain layout and the raw trainer layout can be
// recovered from it by undoing the transposes. The output is a raw network, so
// it can be passed back in as EVALFILE for a regular build
static void SavePermutedNetwork(const std::string& output) {
  auto permuted_network = std::make_unique<RawNetwork>();

  std::array<int, arch::kL1Size / 2> sorted_neurons;
  // Each neuron is at its own index initially (of course)
  for (int i = 0; i < sorted_neurons.size(); i++) {
    sorted_neurons[i] = i;
  }

  // Sort based on activations
  std::ranges::stable_sort(sorted_neurons, [&](const int& a, const int& b) {
    return activations[a] > activations[b];
  });

  // Feature weights and biases
  constexpr std::size_t kFeatureRows = arch::kInputBucketCount * 768;
  const auto* feature_weights =
      reinterpret_cast<const I16*>(&network->feature_weights);
  auto* permuted_feature_weights =
      reinterpret_cast<I16*>(&permuted_network->feature_weights);
  for (std::size_t row = 0; row < kFeatureRows; ++row) {
    PermuteRow(feature_weights + row * arch::kL1Size,
               permuted_feature_weights + row * arch::kL1Size,
               sorted_neurons);
  }

  PermuteRow(network->feature_biases.data(),
             permuted_network->feature_biases.data(),
             sorted_neurons);

  // HMC weights, dropping the all-zero row the runtime network carries
  for (int bucket = 0; bucket < arch::kInputBucketCount; ++bucket) {
    for (int hmc = 0; hmc < arch::kHmcBucketCount; ++hmc) {
      PermuteRow(network->hmc_weights[bucket][hmc].data(),
                 permuted_network->hmc_weights[bucket][hmc].data(),
                 sorted_neurons);
    }
  }

  // Threat weights
  const auto* threat_weights =
      reinterpret_cast<const I8*>(&network->threat_weights);
  auto* permuted_threat_weights =
      reinterpret_cast<I8*>(&permuted_network->threat_weights);
  for (std::size_t row = 0; row < arch::kThreatFeatureCount; ++row) {
    PermuteRow(threat_weights + row * arch::kL1Size,
               permuted_threat_weights + row * arch::kL1Size,
               sorted_neurons);
  }

  // L1 weights, transposed back from [b][l1][l2] to [b][l2][l1]
  for (int bucket = 0; bucket < arch::kOutputBucketCount; ++bucket) {
    for (int j = 0; j < arch::kL2Size; ++j) {
      std::array<I8, arch::kL1Size> column;
      for (int i = 0; i < arch::kL1Size; ++i) {
        column[i] = network->l1_weights[bucket][i][j];
      }
      PermuteRow(column.data(),
                 permuted_network->l1_weights[bucket][j].data(),
                 sorted_neurons);
    }
  }

  // Everything past L1 is unaffected by the permutation
  permuted_network->l1_biases = network->l1_biases;
  permuted_network->l2_biases = network->l2_biases;
  permuted_network->l3_weights = network->l3_weights;
  permuted_network->l3_biases = network->l3_biases;

  // L2 weights, transposed back from [b][l2][l3] to [b][l3][l2]
  for (int bucket = 0; bucket < arch::kOutputBucketCount; ++bucket) {
    for (int i = 0; i < arch::kL2Size; ++i) {
      for (int j = 0; j < arch::kL3Size; ++j) {
        permuted_network->l2_weights[bucket][j][i] =
            network->l2_weights[bucket][i][j];
      }
    }
  }

  std::ofstream output_stream(output, std::ios::binary);
  output_stream.write(reinterpret_cast<char*>(permuted_network.get()),
                      sizeof(RawNetwork));
  output_stream.close();

  fmt::println("Permuted network written to {}", output);
}
#endif

}  // namespace nnue::sparse
// #endif

#endif  // INTEGRAL_SPARSE_H