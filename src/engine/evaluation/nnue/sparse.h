#ifndef INTEGRAL_SPARSE_H
#define INTEGRAL_SPARSE_H

#include <bitset>
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

// #ifdef SPARSE_PERMUTE
constexpr int kHalfL1 = arch::kL1Size / 2;
inline MultiArray<int, kHalfL1, kHalfL1> activations{};

//  This is the array where we keep track of the number of pair-wise activated
//  neurons during a bench sequence, to be used for permuting the input and L1
//  weights for maximizing sparse efficiency
static void CountActivations(
    const std::array<U8, arch::kL1Size>& feature_output) {
  for (int i = 0; i < arch::kL1Size; ++i) {
    for (int j = 0; j < arch::kL1Size; ++j) {
      if (feature_output[i] > 0 && feature_output[j] > 0) {
        activations[i % kHalfL1][j % kHalfL1]++;
      }
    }
  }
}

static int GroupScore(const std::vector<int>& group) {
  int score = 0;
  for (int i = 0; i < group.size(); ++i) {
    for (int j = i + 1; j < group.size(); ++j) {
      score += activations[group[i]][group[j]];
      score += activations[group[j]][group[i]];
    }
  }
  return score;
}

static void RefineGroups(std::vector<std::vector<int>>& groups) {
  bool improved = true;

  while (improved) {
    improved = false;

    for (int g1 = 0; g1 < groups.size(); ++g1) {
      for (int g2 = g1 + 1; g2 < groups.size(); ++g2) {
        for (int i = 0; i < 4; ++i) {
          for (int j = 0; j < 4; ++j) {
            auto g1_copy = groups[g1];
            auto g2_copy = groups[g2];
            std::swap(g1_copy[i], g2_copy[j]);

            int old_score = GroupScore(groups[g1]) + GroupScore(groups[g2]);
            int new_score = GroupScore(g1_copy) + GroupScore(g2_copy);

            if (new_score > old_score) {
              groups[g1] = std::move(g1_copy);
              groups[g2] = std::move(g2_copy);
              improved = true;
            }
          }
        }
      }
    }
  }
}

static std::vector<int> GroupNeuronsByCoactivation() {
  constexpr int kGroupSize = 4;
  constexpr int num_groups = kHalfL1 / kGroupSize;
  std::vector<bool> used(kHalfL1, false);
  std::vector<std::vector<int>> groups;

  for (int g = 0; g < num_groups; ++g) {
    std::vector<int> group;
    int seed = -1;
    int max_sum = -1;

    for (int i = 0; i < kHalfL1; ++i) {
      if (used[i]) continue;
      int sum = 0;
      for (int j = 0; j < kHalfL1; ++j)
        if (!used[j]) sum += activations[i][j];
      if (sum > max_sum) {
        max_sum = sum;
        seed = i;
      }
    }

    if (seed == -1) break;

    used[seed] = true;
    group.push_back(seed);

    for (int k = 0; k < kGroupSize - 1; ++k) {
      int best = -1;
      int best_score = -1;
      for (int j = 0; j < kHalfL1; ++j) {
        if (used[j]) continue;
        int score = 0;
        for (int m : group) score += activations[m][j];
        if (score > best_score) {
          best_score = score;
          best = j;
        }
      }
      if (best != -1) {
        used[best] = true;
        group.push_back(best);
      }
    }

    groups.push_back(std::move(group));
  }

  RefineGroups(groups);

  // Flatten the refined groups into a sorted neuron list
  std::vector<int> result;
  for (const auto& group : groups)
    result.insert(result.end(), group.begin(), group.end());

  return result;
}

static void SavePermutedNetwork(std::string output) {
  auto permuted_network = std::make_unique<RawNetwork>();
  std::memset(permuted_network.get(), 0, sizeof(RawNetwork));

  const auto sorted_neurons = GroupNeuronsByCoactivation();

  // Fill permuted L1 neurons (half-size)
  for (int i = 0; i < sorted_neurons.size(); ++i) {
    const int idx = sorted_neurons[i];

    // Copy L1 biases
    permuted_network->feature_biases[i] = network->feature_biases[idx];
    permuted_network->feature_biases[i + arch::kL1Size / 2] =
        network->feature_biases[idx + arch::kL1Size / 2];

    // Copy feature weights
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

    // Copy L1 weights with transpose
    for (int bucket = 0; bucket < arch::kOutputBucketCount; ++bucket) {
      for (int j = 0; j < arch::kL2Size; ++j) {
        permuted_network->l1_weights[bucket][j][i] =
            network->l1_weights[bucket][idx][j];
        permuted_network->l1_weights[bucket][j][i + arch::kL1Size / 2] =
            network->l1_weights[bucket][idx + arch::kL1Size / 2][j];
      }
    }
  }

  // Copy L1 biases (not dependent on L1 neuron permutation)
  for (int bucket = 0; bucket < arch::kOutputBucketCount; ++bucket) {
    for (int i = 0; i < arch::kL2Size; ++i) {
      permuted_network->l1_biases[bucket][i] = network->l1_biases[bucket][i];
    }
  }

  // Copy L2 weights/biases directly
  for (int bucket = 0; bucket < arch::kOutputBucketCount; ++bucket) {
    for (int i = 0; i < arch::kL3Size; ++i) {
      permuted_network->l2_biases[bucket][i] = network->l2_biases[bucket][i];
      for (int j = 0; j < arch::kL2Size; ++j) {
        permuted_network->l2_weights[bucket][i][j] =
            network->l2_weights[bucket][j][i];
      }
    }
  }

  // Copy L3 weights/biases directly
  for (int bucket = 0; bucket < arch::kOutputBucketCount; ++bucket) {
    for (int i = 0; i < arch::kL3Size; ++i) {
      permuted_network->l3_weights[bucket][i] = network->l3_weights[bucket][i];
    }
    permuted_network->l3_biases[bucket] = network->l3_biases[bucket];
  }

  std::ofstream output_stream(output, std::ios::binary);
  output_stream.write(reinterpret_cast<char*>(permuted_network.get()),
                      sizeof(RawNetwork));
  output_stream.close();

  fmt::println("Permuted network written to {}", output);
}

inline U32 average_sparsity = 0, num_counts = 0;

static void CountSparsity(std::array<U8, arch::kL1Size>& l1_input,
                          int chunk_size = 4) {
  for (int i = 0; i < arch::kL1Size / chunk_size; ++i) {
    bool any_active = false;
    for (int j = 0; j < chunk_size; ++j) {
      any_active |= l1_input[i * chunk_size + j] > 0;
    }
    average_sparsity += any_active;
  }
  ++num_counts;
}

static void PrintSparsityData() {
  fmt::println("Number of active groups: {}", average_sparsity / num_counts);
}

// #endif

}  // namespace nnue::sparse
// #endif

#endif  // INTEGRAL_SPARSE_H