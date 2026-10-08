#include <fmt/format.h>

#include <fstream>

#include "../shared/nnue/definitions.h"

// Pawnocchio stores neuron n at this position so its packus produces the
// natural order, which is undone here before applying our own permutation
constexpr std::size_t PawnocchioPosition(std::size_t neuron) {
  const std::size_t chunk = neuron % 64;
  const std::size_t lane = chunk / 16;
  const std::size_t half = chunk % 16 / 8;
  return neuron - chunk + half * 32 + lane * 8 + chunk % 8;
}

template <typename Row>
void RestoreNeuronOrder(Row& dst, const Row& src) {
  for (std::size_t n = 0; n < nnue::arch::kL1Size; ++n) {
    dst[n] = src[PawnocchioPosition(n)];
  }
}

std::unique_ptr<nnue::Network> ProcessNetwork(
    const std::unique_ptr<nnue::RawNetwork>& raw_network) {
  auto network = std::make_unique<nnue::Network>();

  for (std::size_t b = 0; b < nnue::arch::kInputBucketCount; ++b) {
    for (std::size_t f = 0; f < nnue::arch::kPsqFeatureCount; ++f) {
      RestoreNeuronOrder(network->feature_weights[b][f],
                         raw_network->feature_weights[b][f]);
    }
  }
  for (std::size_t f = 0; f < nnue::arch::kThreatPawnPairFeatureCount; ++f) {
    RestoreNeuronOrder(network->threat_weights[f],
                       raw_network->threat_weights[f]);
  }
  RestoreNeuronOrder(network->feature_biases, raw_network->feature_biases);

  network->l1_weights = raw_network->l1_weights;
  network->l1_biases = raw_network->l1_biases;
  network->l2_weights = raw_network->l2_weights;
  network->l2_biases = raw_network->l2_biases;
  network->l3_weights = raw_network->l3_weights;
  network->l3_biases = raw_network->l3_biases;

#if BUILD_HAS_SIMD and !defined(SPARSE_PERMUTE)
  constexpr int kWeightsPerBlock = sizeof(__m128i) / sizeof(int16_t);
  constexpr int kNumRegs = sizeof(simd::Vepi16) / 8;
  std::array<__m128i, kNumRegs> regs;

  auto weights = reinterpret_cast<__m128i*>(&network->feature_weights);
  auto biases = reinterpret_cast<__m128i*>(&network->feature_biases);

  for (std::size_t i = 0; i < nnue::arch::kInputBucketCount *
                                  nnue::arch::kPsqFeatureCount *
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

  // Same 8-element granularity as the FT weights, but I8 rows -> 8-byte blocks.
  auto threats = reinterpret_cast<U64*>(&network->threat_weights);
  std::array<U64, kNumRegs> threat_regs;
  for (std::size_t i = 0; i < nnue::arch::kThreatPawnPairFeatureCount *
                                  nnue::arch::kL1Size / kWeightsPerBlock;
       i += kNumRegs) {
    for (int j = 0; j < kNumRegs; j++) threat_regs[j] = threats[i + j];
    for (int j = 0; j < kNumRegs; j++)
      threats[i + j] = threat_regs[simd::kPackusOrder[j]];
  }
#endif

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
    fmt::println("Invalid network size: {} bytes; expected {} or {} (Bullet padding)",
                 static_cast<long long>(input_size), raw_size, padded_size);
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