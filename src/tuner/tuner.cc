#include "tuner.h"

#include <fmt/format.h>
#include <pthread.h>

#include <fstream>
#include <sstream>

#include "../engine/eval.h"

using namespace eval;

constexpr int kMaxEpochs = 10000;
constexpr double kMomentumCoeff = 0.9;
constexpr double kVelocityCoeff = 0.999;
constexpr double kLearningRate = 1.0;
constexpr double kLearningDropRate = 1.00;
constexpr int kLearningStepRate = 250;

static double Sigmoid(double K, double E) {
  return 1.0 / (1.0 + exp(-K * E / 400.0));
}

void Tuner::LoadFromFile(const std::string& source_file) {
  InitBaseParameters();

  fmt::println("Loading data source...");

  std::ifstream file(source_file);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      const auto bracket_pos = line.find_last_of('[');
      if (bracket_pos != std::string::npos) {
        // Extract the FEN part of the line (everything before the last '[')
        const auto fen = line.substr(0, bracket_pos - 1);

        Board board;
        board.SetFromFen(fen);

        // Extract the WDL marker (between the brackets)
        auto end_bracket_pos = line.find_last_of(']');
        if (end_bracket_pos != std::string::npos &&
            bracket_pos + 1 < end_bracket_pos) {
          const auto wdl =
              line.substr(bracket_pos + 1, end_bracket_pos - bracket_pos - 1);

          GameResult result;
          if (wdl == "0.0") {
            result = kBlackWon;
          } else if (wdl == "0.5") {
            result = kDrawn;
          } else if (wdl == "1.0") {
            result = kWhiteWon;
          }

          TunerEntry entry = CreateEntry(board.GetState(), result);
          entries_.push_back(entry);

          const Score computed_eval = ComputeEvaluation(entry);
          const Score deviation = abs(entry.static_eval - computed_eval);
          if (deviation > 1) {
            fmt::println("Tuner deviation detected: real {} coeff {}",
                         entry.static_eval,
                         computed_eval);
          }
        }
      }
    }
  } else {
    fmt::println("Unable to open file");
  }

  file.close();
  fmt::println("Finished loading data source...");
}

void Tuner::Tune() {
  VectorPair momentum, velocity;
  momentum.resize(num_terms_);
  velocity.resize(num_terms_);

  const std::size_t num_entries = entries_.size();
  fmt::println("Num Positions: {}", num_entries);

  const double K = ComputeOptimalK();
  fmt::println("Optimal K: {}", K);

  double rate = kLearningRate;
  double error;

  for (int epoch = 0; epoch < kMaxEpochs; epoch++) {
    auto epoch_gradient = ComputeGradient(K);
    for (int i = 0; i < num_terms_; i++) {
      double mg_grad = (-K / 400.0) * epoch_gradient[i][MG] / num_entries;
      double eg_grad = (-K / 400.0) * epoch_gradient[i][EG] / num_entries;

      momentum[i][MG] =
          kMomentumCoeff * momentum[i][MG] + (1.0 - kMomentumCoeff) * mg_grad;
      momentum[i][EG] =
          kMomentumCoeff * momentum[i][EG] + (1.0 - kMomentumCoeff) * eg_grad;

      velocity[i][MG] = kVelocityCoeff * velocity[i][MG] +
                        (1.0 - kVelocityCoeff) * pow(mg_grad, 2);
      velocity[i][EG] = kVelocityCoeff * velocity[i][EG] +
                        (1.0 - kVelocityCoeff) * pow(eg_grad, 2);

      const double mg_delta =
          rate * momentum[i][MG] / (1e-8 + sqrt(velocity[i][MG]));
      const double eg_delta =
          rate * momentum[i][EG] / (1e-8 + sqrt(velocity[i][EG]));
      parameters_[i][MG] -= mg_delta;
      parameters_[i][EG] -= eg_delta;
    }

    error = TunedEvaluationErrors(K);
    fmt::println("Epoch [{}] Error = [{}], Rate = [{}]", epoch, error, rate);

    // Pre-scheduled Learning Rate drops
    if (epoch % kLearningStepRate == 0) rate = rate / kLearningDropRate;
    if (epoch % 50 == 0) PrintParameters();
  }
}

void Tuner::InitBaseParameters() {
  AddArrayParameter(kPieceValues);
  Add2DArrayParameter<PieceType::kNumTypes, kSquareCount>(kPieceSquareTable);
  AddArrayParameter(kKnightMobility);
  AddArrayParameter(kBishopMobility);
  AddArrayParameter(kRookMobility);
  AddArrayParameter(kQueenMobility);
  AddArrayParameter(kPassedPawnBonus);
  AddArrayParameter(kPawnPhalanxBonus);
  AddArrayParameter(kDoubledPawnPenalty);
  AddArrayParameter(kRookOnOpenFileBonus);
  AddSingleParameter(kTempoBonus);
}

std::vector<I16> Tuner::GetCoefficients() const {
  std::vector<I16> coefficients(num_terms_);
  int idx = 0;

#define GET_COEFFICIENT(term) \
  coefficients[idx++] = trace.term[Color::kWhite] - trace.term[Color::kBlack]
#define GET_ARRAY_COEFFICIENTS(arr) \
  for (int j = 0; j < arr.size(); ++j) GET_COEFFICIENT(arr[j])
#define GET_2D_ARRAY_COEFFICIENTS(arr2d) \
  for (int k = 0; k < arr2d.size(); ++k) GET_ARRAY_COEFFICIENTS(arr2d[k])

  GET_ARRAY_COEFFICIENTS(kPieceValues);
  GET_2D_ARRAY_COEFFICIENTS(kPieceSquareTable);
  GET_ARRAY_COEFFICIENTS(kKnightMobility);
  GET_ARRAY_COEFFICIENTS(kBishopMobility);
  GET_ARRAY_COEFFICIENTS(kRookMobility);
  GET_ARRAY_COEFFICIENTS(kQueenMobility);
  GET_ARRAY_COEFFICIENTS(kPassedPawnBonus);
  GET_ARRAY_COEFFICIENTS(kPawnPhalanxBonus);
  GET_ARRAY_COEFFICIENTS(kDoubledPawnPenalty);
  GET_ARRAY_COEFFICIENTS(kRookOnOpenFileBonus);
  GET_COEFFICIENT(kTempoBonus);

  return coefficients;
}

TunerEntry Tuner::CreateEntry(const BoardState& state,
                              GameResult result) const {
  TunerEntry entry;
  entry.phase = GetPhase(state);
  entry.result = result;

  // Save time by computing phase scalars now
  entry.p_factors[0] = 0 + entry.phase / 24.0;
  entry.p_factors[1] = 1 - entry.phase / 24.0;

  // Save a white POV static evaluation
  trace = EvalTrace{};
  entry.static_eval = Evaluate(state) * (state.turn == Color::kWhite ? 1 : -1);

  const auto coefficients = GetCoefficients();
  entry.coefficient_entries.reserve(num_terms_);

  for (int i = 0; i < coefficients.size(); i++) {
    if (coefficients[i] != 0) {
      entry.coefficient_entries.push_back({i, coefficients[i]});
    }
  }

  // Save some of the evaluation modifiers
  entry.eval = trace.eval;
  entry.turn = state.turn;

  return entry;
}

double Tuner::ComputeEvaluation(const TunerEntry& entry) const {
  double mg_score = 0;
  double eg_score = 0;
  for (const auto& coefficient : entry.coefficient_entries) {
    mg_score += parameters_[coefficient.index][MG] * coefficient.value;
    eg_score += parameters_[coefficient.index][EG] * coefficient.value;
  }

  return (mg_score * entry.phase + eg_score * (24 - entry.phase)) / 24;
}

double Tuner::ComputeOptimalK() const {
  const double rate = 10, delta = 1e-5, deviation_goal = 1e-6;
  double K = 2.5, deviation = 1;

  while (fabs(deviation) > deviation_goal) {
    double up = StaticEvaluationErrors(K + delta);
    double down = StaticEvaluationErrors(K - delta);
    deviation = (up - down) / (2 * delta);
    K -= deviation * rate;
  }

  return K;
}

VectorPair Tuner::ComputeGradient(double K) const {
  VectorPair local_gradient;
  local_gradient.resize(num_terms_);

  VectorPair gradient;
  gradient.resize(num_terms_);

  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

#pragma omp parallel shared(local_gradient, mutex) num_threads(6)
  {
#pragma omp for schedule(static)
    for (const auto& entry : entries_) {
      double E = ComputeEvaluation(entry);
      double S = Sigmoid(K, E);
      double X = (entry.result - S) * S * (1 - S);

      double mg_base = X * (entry.phase / 24.0);
      double eg_base = X - mg_base;

      for (const auto& coeff_entry : entry.coefficient_entries) {
        const int idx = coeff_entry.index;
        local_gradient[idx][MG] += mg_base * coeff_entry.value;
        local_gradient[idx][EG] += eg_base * coeff_entry.value;
      }
    }

    pthread_mutex_lock(&mutex);

    for (int i = 0; i < num_terms_; i++) {
      gradient[i][MG] += local_gradient[i][MG];
      gradient[i][EG] += local_gradient[i][EG];
    }

    pthread_mutex_unlock(&mutex);
  }

  return gradient;
}

double Tuner::StaticEvaluationErrors(double K) const {
  double total = 0.0;
  for (const auto& entry : entries_) {
    total += pow(entry.result - Sigmoid(K, entry.static_eval), 2);
  }

  return total / (double)entries_.size();
}

double Tuner::TunedEvaluationErrors(double K) const {
  double total = 0.0;
#pragma omp parallel shared(total) num_threads(6)
  {
#pragma omp for schedule(static) reduction(+ : total)
    for (const auto& entry : entries_) {
      total += pow(entry.result - Sigmoid(K, ComputeEvaluation(entry)), 2);
    }
  }
  return total / (double)entries_.size();
}

inline Score Round(double value) {
  return static_cast<Score>(std::round(value));
}

void PrintTerm(int& index,
               const std::vector<TermPair>& parameters,
               bool in_array = false) {
  fmt::print("Pair({}, {}){}",
             Round(parameters[index][MG]),
             Round(parameters[index][EG]),
             in_array ? "" : ";\n");
  index++;
}

void PrintArray(int& index,
                int size,
                const std::vector<TermPair>& parameters,
                int padding = 2,
                bool in_2d_array = false) {
  fmt::print("{{");

  for (int i = 0; i < size; i++) {
    if (i % 8 == 0) {  // New row
      fmt::print("\n{}", std::string(padding, ' '));
    }
    PrintTerm(index, parameters, true);
    if (i < size - 1) {
      fmt::print(", ");
    }
  }

  fmt::print("\n{}}}{}", in_2d_array ? "  " : "", in_2d_array ? "" : ";\n\n");
}

void Print2DArray(int& index,
                  int rows,
                  int columns,
                  const std::vector<TermPair>& parameters) {
  fmt::println("{{{{");

  for (int i = 0; i < rows; i++) {
    fmt::print("  ");
    PrintArray(index, columns, parameters, 6, true);
    if (i < rows - 1) {
      fmt::println(",");
    }
  }

  fmt::println("\n}}}};\n");
}

void Tuner::PrintParameters() {
  int index = 0;

  fmt::print("constexpr PieceValueTable<ScorePair> kPieceValues = ");
  PrintArray(index, kPieceValues.size(), parameters_);

  fmt::print("constexpr PieceSquareTable<ScorePair> kPieceSquareTable = ");
  Print2DArray(index, PieceType::kNumTypes, Squares::kSquareCount, parameters_);

  fmt::print("constexpr KnightMobilityTable<ScorePair> kKnightMobility = ");
  PrintArray(index, kKnightMobility.size(), parameters_);

  fmt::print("constexpr BishopMobilityTable<ScorePair> kBishopMobility = ");
  PrintArray(index, kBishopMobility.size(), parameters_);

  fmt::print("constexpr RookMobilityTable<ScorePair> kRookMobility = ");
  PrintArray(index, kRookMobility.size(), parameters_);

  fmt::print("constexpr QueenMobilityTable<ScorePair> kQueenMobility = ");
  PrintArray(index, kQueenMobility.size(), parameters_);

  fmt::print("constexpr RankTable<ScorePair> kPassedPawnBonus = ");
  PrintArray(index, kPassedPawnBonus.size(), parameters_);

  fmt::print("constexpr RankTable<ScorePair> kPawnPhalanxBonus = ");
  PrintArray(index, kPawnPhalanxBonus.size(), parameters_);

  fmt::print("constexpr FileTable<ScorePair> kDoubledPawnPenalty = ");
  PrintArray(index, kDoubledPawnPenalty.size(), parameters_);

  fmt::print("constexpr FileTable<ScorePair> kRookOnOpenFileBonus = ");
  PrintArray(index, kRookOnOpenFileBonus.size(), parameters_);

  fmt::print("constexpr ScorePair kTempoBonus = ");
  PrintTerm(index, parameters_);

  if (index != parameters_.size()) {
    fmt::println("Failed to collect all eval terms: {} expected {}",
                 index,
                 parameters_.size());
  }
}