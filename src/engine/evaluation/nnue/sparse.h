#ifndef INTEGRAL_SPARSE_H
#define INTEGRAL_SPARSE_H

#include <fstream>

#include "../../../chess/bitboard.h"
#include "../../../utils/types.h"
#include "arch.h"
#include "nnue.h"

#define SPARSE_PERMUTE

// #if BUILD_HAS_SIMD
namespace nnue::sparse {

// We store the number and index of each set bit for every possible U8 number
struct NnzEntry {
  std::array<U16, 8> indices;
  int count;
};

[[nodiscard]] constexpr std::array<NnzEntry, 256> GenerateNnzTable() {
  std::array<NnzEntry, 256> table{};
  for (I16 i = 0; i < 256; i++) {
    // Count the number of set bits for this number
    table[i].count = BitBoard(i).PopCount();

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
#include <fmt/core.h>

#include <algorithm>
#include <array>
#include <cstring>
#include <fstream>
#include <memory>
#include <numeric>
#include <vector>

constexpr int group_size = 4;
constexpr int num_neurons = arch::kL1Size;
constexpr int num_groups = num_neurons / group_size;

// Arrays to track total activations and conditional co-activations
inline std::array<int, num_neurons> total_activations{};
inline std::array<std::array<int, num_neurons>, num_neurons> conditional_activations{};

// Function to count total activations and conditional co-activations
static void CountActivations(
    const std::array<U8, num_neurons>& feature_output) {
  for (int i = 0; i < num_neurons; ++i) {
    if (feature_output[i] > 0) {
      total_activations[i]++;
      for (int j = 0; j < num_neurons; ++j) {
        if (i != j && feature_output[j] > 0) {
          conditional_activations[i][j]++;
        }
      }
    }
  }
}

// Function to compute conditional probabilities and form groups of 4 neurons
static std::vector<std::vector<int>> FormGroups() {
  // Compute conditional probabilities
  std::vector<std::vector<double>> conditional_probabilities(
      num_neurons, std::vector<double>(num_neurons, 0.0));
  for (int i = 0; i < num_neurons; ++i) {
    if (total_activations[i] > 0) {
      for (int j = 0; j < num_neurons; ++j) {
        conditional_probabilities[i][j] =
            static_cast<double>(conditional_activations[i][j]) /
            total_activations[i];
      }
    }
  }

  // Track whether a neuron has been grouped
  std::vector<bool> grouped(num_neurons, false);
  std::vector<std::vector<int>> groups;

  // Form groups of 4 neurons
  for (int i = 0; i < num_neurons; ++i) {
    if (grouped[i]) continue;

    // Start a new group with the current neuron
    std::vector<int> group = {i};
    grouped[i] = true;

    // Find the 3 neurons with the highest conditional probability relative to
    // neuron i
    std::vector<std::pair<int, double>> candidates;
    for (int j = 0; j < num_neurons; ++j) {
      if (!grouped[j] && i != j) {
        candidates.emplace_back(j, conditional_probabilities[i][j]);
      }
    }

    // Sort candidates by descending conditional probability
    std::sort(
        candidates.begin(),
        candidates.end(),
        [](const std::pair<int, double>& a, const std::pair<int, double>& b) {
          return a.second > b.second;
        });

    // Add up to 3 of the highest probability neurons to the group
    for (int k = 0;
         k < std::min(group_size - 1, static_cast<int>(candidates.size()));
         ++k) {
      group.push_back(candidates[k].first);
      grouped[candidates[k].first] = true;
    }

    groups.push_back(group);
  }

  return groups;
}

// Function to permute and save the network based on the sorted groups
static void SavePermutedNetwork(std::string output) {
  auto permuted_network = std::make_unique<RawNetwork>();
  std::memcpy(permuted_network.get(), raw_network.get(), sizeof(RawNetwork));

  // Form the groups of 4 neurons
  auto groups = FormGroups();

  // Permute weights/biases based on the order of neurons in the formed groups
  int permuted_index = 0;
  for (const auto& group : groups) {
    for (int neuron_idx : group) {
      // Feature biases
      permuted_network->feature_biases[permuted_index] =
          raw_network->feature_biases[neuron_idx];
      permuted_network->feature_biases[permuted_index + arch::kL1Size / 2] =
          raw_network->feature_biases[neuron_idx + arch::kL1Size / 2];

      // Feature weights
      for (int bucket = 0; bucket < arch::kInputBucketCount; ++bucket) {
        for (int side = 0; side <= 1; ++side) {
          for (int piece = 0; piece < kNumPieceTypes; ++piece) {
            for (int square = 0; square < kSquareCount; ++square) {
              permuted_network->feature_weights[bucket][side][piece][square]
                                               [permuted_index] =
                  raw_network->feature_weights[bucket][side][piece][square]
                                              [neuron_idx];
              permuted_network
                  ->feature_weights[bucket][side][piece][square]
                                   [permuted_index + arch::kL1Size / 2] =
                  raw_network->feature_weights[bucket][side][piece][square]
                                              [neuron_idx + arch::kL1Size / 2];
            }
          }
        }
      }

      // L1 Weights
      for (int bucket = 0; bucket < arch::kOutputBucketCount; ++bucket) {
        for (int j = 0; j < arch::kL2Size; ++j) {
          permuted_network->l1_weights[bucket][j][permuted_index] =
              raw_network->l1_weights[bucket][j][neuron_idx];
          permuted_network
              ->l1_weights[bucket][j][permuted_index + arch::kL1Size / 2] =
              raw_network
                  ->l1_weights[bucket][j][neuron_idx + arch::kL1Size / 2];
        }
      }

      permuted_index++;
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