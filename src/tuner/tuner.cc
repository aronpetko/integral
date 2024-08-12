#include "tuner.h"

#include <fmt/format.h>
// #include <pthread.h>

#include <filesystem>
#include <fstream>
#include <iomanip>
#include <sstream>

#include "../data_gen/format/binpack.h"
#include "../engine/evaluation/evaluation.h"
#include "../engine/search/time_mgmt.h"

using namespace eval;

constexpr int kMaxEpochs = 2000;
constexpr double kMomentumCoeff = 0.9;
constexpr double kVelocityCoeff = 0.999;
constexpr double kStartLearningRate = 0.1;
constexpr double kEndLearningRate = 0.1;
constexpr double kLearningDropRate = 1.00;
constexpr int kLearningStepRate = 250;
constexpr double kLambda = 0.40;

double decay =
    pow(kEndLearningRate / kStartLearningRate, 1.0 / float(kMaxEpochs * 3));
double rate = kStartLearningRate;

// New constant for batch size
constexpr int kBatchSize = 10'000'000;

inline double Sigmoid(double K, double E) {
  return 1.0 / (1.0 + exp(-K * E / 400.0));
}

bool Tuner::LoadNextBatch() {
  if (end_of_file_reached_) {
    return false;
  }

  entries_.clear();
  entries_.shrink_to_fit();
  entries_.reserve(kBatchSize);

  fmt::println("Loading next batch of {} positions ", kBatchSize);

  std::string line;
  int loaded_entries = 0;
  int last_percentage = 0;

  while (loaded_entries < kBatchSize) {
    if (file_.eof() || !file_.good()) {
      end_of_file_reached_ = true;
      file_.close();
      break;
    }

    Board board;
    GameResult result = -1, score = result;

    if (marlin_format_) {
      data_gen::format::MarlinChessBoard marlin_board;
      file_.read(reinterpret_cast<char*>(&marlin_board), sizeof(marlin_board));

      auto& state = board.GetState();
      state = BoardState{};

      int i = 0;
      for (Square square : BitBoard(marlin_board.occupied)) {
        const U8 piece_data = marlin_board.pieces[i];
        const auto color = (piece_data & 0x8) ? Color::kBlack : Color::kWhite;

        auto piece_type = static_cast<PieceType>(piece_data & 0x7);

        // Handle unmoved rook
        if (piece_type == 6) {
          if (square == Squares::kA1 || square == Squares::kH1) {
            state.castle_rights.SetCanCastle(Color::kWhite,
                                             square == Squares::kA1);
          } else if (square == Squares::kA8 || square == Squares::kH8) {
            state.castle_rights.SetCanCastle(Color::kBlack,
                                             square == Squares::kA8);
          }
          piece_type = PieceType::kRook;
        }

        state.PlacePiece(square, piece_type, color);
        ++i;
      }

      state.turn = (marlin_board.turn_and_en_passant & (1 << 7))
                     ? Color::kBlack
                     : Color::kWhite;

      U8 en_passant_relative = marlin_board.turn_and_en_passant & 0x7F;
      if (en_passant_relative != Squares::kNoSquare) {
        state.en_passant =
            Square(en_passant_relative).RelativeTo(FlipColor(state.turn));
      } else {
        state.en_passant = Squares::kNoSquare;
      }

      state.fifty_moves_clock = marlin_board.half_move_clock;
      state.half_moves = (marlin_board.full_move_number - 1) * 2 +
                         (state.turn == Color::kBlack ? 1 : 0);

      result = marlin_board.wdl_outcome / 2.0;
      score = marlin_board.evaluation;
    } else if (std::getline(file_, line)) {
      const auto bracket_pos = line.find_last_of('[');
      if (bracket_pos != std::string::npos) {
        // Extract the FEN part of the line (everything before the last '[')
        const auto fen = line.substr(0, bracket_pos - 1);
        board.SetFromFen(fen);

        // Extract the WDL marker (between the brackets)
        auto end_bracket_pos = line.find_last_of(']');
        if (end_bracket_pos != std::string::npos &&
            bracket_pos + 1 < end_bracket_pos) {
          const auto wdl =
              line.substr(bracket_pos + 1, end_bracket_pos - bracket_pos - 1);

          if (wdl == "0.0") {
            result = kBlackWon;
          } else if (wdl == "0.5") {
            result = kDrawn;
          } else if (wdl == "1.0") {
            result = kWhiteWon;
          }

          score = result;
        }
      }
    }

    if (result != -1) {
      auto entry = CreateEntry(board.GetState(), result, score);
      entries_.push_back(entry);

      if (batch_count_ == 1) {
        const Score computed_eval = ComputeEvaluation(entry);
        const Score deviation = abs(entry.static_eval - computed_eval);
        if (deviation > 1) {
          fmt::println("Tuner deviation detected: real {} coeff {}",
                       entry.static_eval,
                       computed_eval);
          fmt::println("{}", loaded_entries);
        }
      }

      loaded_entries++;

      // Update percentage counter every 5%
      int current_percentage = (loaded_entries * 100) / kBatchSize;
      if (current_percentage >= last_percentage + 5) {
        fmt::print("\rLoading progress: {}%", current_percentage);
        std::cout.flush();
        last_percentage = current_percentage;
      }
    } else {
      break;
    }

    if (file_.eof() || !file_.good()) {
      end_of_file_reached_ = true;
      file_.close();
    }
  }

  fmt::println("\nLoaded {} positions in this batch", entries_.size());

  if (loaded_entries < kBatchSize) {
    fmt::println(
        "Warning: Loaded fewer positions than batch size. This may be the last "
        "batch.");
  }

  return !entries_.empty();
}

void Tuner::TuneBatch() {
  const std::size_t num_entries = entries_.size();

  const double K = ComputeOptimalK();
  fmt::println("Optimal K: {}", K);

  double error;

  for (int epoch = 0; epoch <= kMaxEpochs; epoch++) {
    const auto start_time = search::GetCurrentTime();
    auto epoch_gradient = ComputeGradient(K, 0, num_entries);
    for (int i = 0; i < num_terms_; i++) {
      double mg_grad = (-K / 200.0) * epoch_gradient[i][MG] / num_entries;
      double eg_grad = (-K / 200.0) * epoch_gradient[i][EG] / num_entries;

      momentum_[i][MG] =
          kMomentumCoeff * momentum_[i][MG] + (1.0 - kMomentumCoeff) * mg_grad;
      momentum_[i][EG] =
          kMomentumCoeff * momentum_[i][EG] + (1.0 - kMomentumCoeff) * eg_grad;

      velocity_[i][MG] = kVelocityCoeff * velocity_[i][MG] +
                         (1.0 - kVelocityCoeff) * pow(mg_grad, 2);
      velocity_[i][EG] = kVelocityCoeff * velocity_[i][EG] +
                         (1.0 - kVelocityCoeff) * pow(eg_grad, 2);

      const double mg_delta =
          rate * momentum_[i][MG] / (1e-8 + sqrt(velocity_[i][MG]));
      const double eg_delta =
          rate * momentum_[i][EG] / (1e-8 + sqrt(velocity_[i][EG]));
      parameters_[i][MG] -= mg_delta;
      parameters_[i][EG] -= eg_delta;
    }

    const auto time_delta =
        static_cast<double>(search::GetCurrentTime() - start_time) / 1000.0;

    error = TunedEvaluationErrors(K);
    fmt::println(
        "Epoch [{}] Error = [{}] LR = [{:.3f}] Speed = [{:.0f} pos/sec]",
        epoch,
        error,
        rate,
        num_entries / time_delta);

    if (epoch % 50 == 0) {
      PrintParameters();
    }

    // Pre-scheduled Learning Rate drops
    rate *= decay;
  }
}

void Tuner::LoadAndTune(const std::string& source_file) {
  InitBaseParameters();

  fmt::println("Opening data source...");

  marlin_format_ = std::filesystem::path(source_file).extension() == ".mf";
  file_.open(source_file, marlin_format_ ? std::ios::binary : std::ios::in);

  if (!file_.is_open()) {
    fmt::println("Unable to open file");
    return;
  }

  fmt::println("File opened successfully. Starting batch processing.");

  momentum_.resize(num_terms_);
  velocity_.resize(num_terms_);

  while (LoadNextBatch()) {
    fmt::println("Processing batch {}", batch_count_);
    TuneBatch();
    batch_count_++;
  }

  fmt::println("Finished processing all batches. Total batches: {}",
               batch_count_);
}

void Tuner::InitBaseParameters() {
  AddArrayParameter(kPieceValues);
  Add2DArrayParameter(kPieceSquareTable);
  AddArrayParameter(kKnightMobility);
  AddArrayParameter(kBishopMobility);
  AddArrayParameter(kRookMobility);
  AddArrayParameter(kQueenMobility);
  AddArrayParameter(kPassedPawnBonus);
  AddArrayParameter(kPawnPhalanxBonus);
  AddArrayParameter(kDefendedPawnBonus);
  AddArrayParameter(kDoubledPawnPenalty);
  AddArrayParameter(kIsolatedPawnPenalty);
  Add2DArrayParameter(kRookOnFileBonus);
  AddArrayParameter(kPawnShelterTable);
  AddArrayParameter(kPawnStormTable);
  AddArrayParameter(kKingPPDistanceTable);
  AddArrayParameter(kEnemyKingPPDistanceTable);
  AddSingleParameter(kKingCantReachPPBonus);
  Add2DArrayParameter(kKingOnFilePenalty);
  Add2DArrayParameter(kAttackPower);
  AddArrayParameter(kSafeCheckBonus);
  Add2DArrayParameter(kThreatenedByPawnPenalty);
  AddArrayParameter(kPawnPushThreat);
  Add2DArrayParameter(kThreatenedByKnightPenalty);
  Add2DArrayParameter(kThreatenedByBishopPenalty);
  Add2DArrayParameter(kThreatenedByRookPenalty);
  AddArrayParameter(kKnightOutpostTable);
  AddArrayParameter(kBishopOutpostTable);
  AddSingleParameter(kBishopPairBonus);
  AddSingleParameter(kTempoBonus);
}

std::vector<I16> Tuner::GetCoefficients() const {
  std::vector<I16> coefficients(num_terms_);
  int idx = 0;

#define GET_COEFFICIENT(term) \
  coefficients[idx++] = trace.term[Color::kWhite] - trace.term[Color::kBlack]
#define GET_ARRAY_COEFFICIENTS(arr) \
  for (std::size_t j = 0; j < arr.size(); ++j) GET_COEFFICIENT(arr[j])
#define GET_2D_ARRAY_COEFFICIENTS(arr2d)         \
  for (std::size_t k = 0; k < arr2d.size(); ++k) \
  GET_ARRAY_COEFFICIENTS(arr2d[k])
#define GET_3D_ARRAY_COEFFICIENTS(arr3d)         \
  for (std::size_t l = 0; l < arr3d.size(); ++l) \
  GET_2D_ARRAY_COEFFICIENTS(arr3d[l])
#define GET_4D_ARRAY_COEFFICIENTS(arr4d)         \
  for (std::size_t z = 0; z < arr4d.size(); ++z) \
  GET_3D_ARRAY_COEFFICIENTS(arr4d[z])

  GET_ARRAY_COEFFICIENTS(kPieceValues);
  GET_2D_ARRAY_COEFFICIENTS(kPieceSquareTable);
  GET_ARRAY_COEFFICIENTS(kKnightMobility);
  GET_ARRAY_COEFFICIENTS(kBishopMobility);
  GET_ARRAY_COEFFICIENTS(kRookMobility);
  GET_ARRAY_COEFFICIENTS(kQueenMobility);
  GET_ARRAY_COEFFICIENTS(kPassedPawnBonus);
  GET_ARRAY_COEFFICIENTS(kPawnPhalanxBonus);
  GET_ARRAY_COEFFICIENTS(kDefendedPawnBonus);
  GET_ARRAY_COEFFICIENTS(kDoubledPawnPenalty);
  GET_ARRAY_COEFFICIENTS(kIsolatedPawnPenalty);
  GET_2D_ARRAY_COEFFICIENTS(kRookOnFileBonus);
  GET_ARRAY_COEFFICIENTS(kPawnShelterTable);
  GET_ARRAY_COEFFICIENTS(kPawnStormTable);
  GET_ARRAY_COEFFICIENTS(kKingPPDistanceTable);
  GET_ARRAY_COEFFICIENTS(kEnemyKingPPDistanceTable);
  GET_COEFFICIENT(kKingCantReachPPBonus);
  GET_2D_ARRAY_COEFFICIENTS(kKingOnFilePenalty);
  GET_2D_ARRAY_COEFFICIENTS(kAttackPower);
  GET_ARRAY_COEFFICIENTS(kSafeCheckBonus);
  GET_2D_ARRAY_COEFFICIENTS(kThreatenedByPawnPenalty);
  GET_ARRAY_COEFFICIENTS(kPawnPushThreat);
  GET_2D_ARRAY_COEFFICIENTS(kThreatenedByKnightPenalty);
  GET_2D_ARRAY_COEFFICIENTS(kThreatenedByBishopPenalty);
  GET_2D_ARRAY_COEFFICIENTS(kThreatenedByRookPenalty);
  GET_ARRAY_COEFFICIENTS(kKnightOutpostTable);
  GET_ARRAY_COEFFICIENTS(kBishopOutpostTable);
  GET_COEFFICIENT(kBishopPairBonus);
  GET_COEFFICIENT(kTempoBonus);

  return coefficients;
}

TunerEntry Tuner::CreateEntry(const BoardState& state,
                              GameResult result,
                              Score score) const {
  TunerEntry entry;
  entry.phase = std::min(state.phase, kMaxPhase);
  entry.result = result;
  entry.score = score;

  // Save time by computing phase scalars now
  entry.phase_factors[0] = 0 + entry.phase / 24.0;
  entry.phase_factors[1] = 1 - entry.phase / 24.0;

  // Save a white POV static evaluation
  trace = EvalTrace{};
  entry.static_eval = Evaluate(state) * (state.turn == Color::kWhite ? 1 : -1);

  const auto coefficients = GetCoefficients();
  entry.coefficient_entries.reserve(num_terms_);

  for (int i = 0; i < coefficients.size(); i++) {
    if (coefficients[i] != 0) {
      entry.coefficient_entries.push_back(
          {static_cast<U32>(i), coefficients[i]});
    }
  }

  // Save some of the evaluation modifiers
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

VectorPair Tuner::ComputeGradient(double K, int start, int end) const {
  VectorPair local_gradient;
  local_gradient.resize(num_terms_);

  VectorPair gradient;
  gradient.resize(num_terms_);

  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

#pragma omp parallel shared(local_gradient, mutex) num_threads(24)
  {
#pragma omp for schedule(static)
    for (int i = start; i < end; ++i) {
      const auto& entry = entries_[i];
      double E = ComputeEvaluation(entry);
      double S = Sigmoid(K, E);

      // Apply sigmoid to the score
      double score_sigmoid = Sigmoid(K, entry.score);
      double target = std::lerp(score_sigmoid, static_cast<double>(entry.result), kLambda);

      double X = (target - S) * S * (1 - S);

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
#pragma omp parallel shared(total) num_threads(24)
  {
#pragma omp for schedule(static) reduction(+ : total)
    for (const auto& entry : entries_) {
      total += pow(entry.result - Sigmoid(K, entry.static_eval), 2);
    }
  }
  return total / (double)entries_.size();
}

double Tuner::TunedEvaluationErrors(double K) const {
  double total = 0.0;
#pragma omp parallel shared(total) num_threads(24)
  {
#pragma omp for schedule(static) reduction(+ : total)
    for (const auto& entry : entries_) {
      double evaluation = Sigmoid(K, ComputeEvaluation(entry));

      // Interpolate between result and sigmoid-ed score
      double score_sigmoid = Sigmoid(K, entry.score);
      double target = std::lerp(score_sigmoid, entry.result, kLambda);

      total += pow(target - evaluation, 2);
    }
  }
  return total / (double)entries_.size();
}

inline Score Round(double value) {
  return static_cast<Score>(std::round(value));
}

void PrintTerm(std::size_t& index,
               const std::vector<TermPair>& parameters,
               bool in_array = false) {
  fmt::print("Pair({}, {}){}",
             Round(parameters[index][MG]),
             Round(parameters[index][EG]),
             in_array ? "" : ";\n");
  index++;
}

void PrintArray(std::size_t& index,
                int size,
                const std::vector<TermPair>& parameters,
                int row_length = 8,
                int padding = 2,
                bool in_2d_array = false) {
  fmt::print("{{");

  for (int i = 0; i < size; i++) {
    if (i % row_length == 0) {  // New row
      fmt::print("\n{}", std::string(padding, ' '));
    }
    PrintTerm(index, parameters, true);
    if (i < size - 1) {
      fmt::print(", ");
    }
  }

  fmt::print("\n{}}}{}", in_2d_array ? "  " : "", in_2d_array ? "" : ";\n\n");
}

void Print2DArray(std::size_t& index,
                  int rows,
                  int columns,
                  const std::vector<TermPair>& parameters,
                  int row_length = 8) {
  fmt::println("{{{{");

  for (int i = 0; i < rows; i++) {
    fmt::print("  ");
    PrintArray(index, columns, parameters, row_length, 6, true);
    if (i < rows - 1) {
      fmt::println(",");
    }
  }

  fmt::println("\n}}}};\n");
}

#include <cmath>

void Print3DArray(std::size_t& index,
                  int buckets,
                  int pieces,
                  int squares,
                  const std::vector<TermPair>& parameters) {
  std::cout << "{\n";

  for (int b = 0; b < buckets; ++b) {
    std::cout << "  { // Bucket " << b << "\n";
    for (int p = 0; p < pieces; ++p) {
      std::cout << "    { // Piece " << p << "\n      ";

      for (int s = 0; s < squares; ++s) {
        if (index < parameters.size()) {
          const auto& param = parameters[index++];
          int mg = static_cast<int>(std::round(param[MG]));
          int eg = static_cast<int>(std::round(param[EG]));
          std::cout << "Pair(" << mg << ", " << eg << ")";
        } else {
          std::cout << "Pair(0, 0)";
        }

        if (s < squares - 1) std::cout << ", ";
        if ((s + 1) % 8 == 0 && s < squares - 1) std::cout << "\n      ";
      }

      std::cout << "\n    }";
      if (p < pieces - 1) std::cout << ",";
      std::cout << "\n";
    }
    std::cout << "  }";
    if (b < buckets - 1) std::cout << ",";
    std::cout << "\n";
  }

  std::cout << "}";
}

void Print4DArray(std::size_t& index,
                  int dimensions,
                  int buckets,
                  int pieces,
                  int squares,
                  const std::vector<TermPair>& parameters) {
  std::cout << "{{\n";

  for (int d = 0; d < dimensions; ++d) {
    std::cout << "  {{ // Bucket " << d << "\n";
    for (int b = 0; b < buckets; ++b) {
      std::cout << "    {{ // Bucket " << b << "\n";
      for (int p = 0; p < pieces; ++p) {
        std::cout << "      { // Piece " << p << "\n        ";

        for (int s = 0; s < squares; ++s) {
          if (index < parameters.size()) {
            const auto& param = parameters[index++];
            int mg = static_cast<int>(std::round(param[MG]));
            int eg = static_cast<int>(std::round(param[EG]));
            std::cout << "Pair(" << mg << ", " << eg << ")";
          } else {
            std::cout << "Pair(0, 0)";
          }

          if (s < squares - 1) std::cout << ", ";
          if ((s + 1) % 8 == 0 && s < squares - 1) std::cout << "\n        ";
        }

        std::cout << "\n      }";
        if (p < pieces - 1) std::cout << ",";
        std::cout << "\n";
      }
      std::cout << "    }}";
      if (b < buckets - 1) std::cout << ",";
      std::cout << "\n";
    }
    std::cout << "  }}";
    if (d < dimensions - 1) std::cout << ",";
    std::cout << "\n";
  }

  std::cout << "}};\n\n";
}

void Tuner::NormalizePSQTs() {
  const auto offset = kPieceValues.size();
  for (int piece = 0; piece < kNumPieceTypes; piece++) {
    if (piece == kKing) continue;

    double average_mg = 0, average_eg = 0;
    double total_active_squares = 0;

    for (int square = 0; square < kSquareCount; square++) {
      const int idx = piece * kSquareCount + square + offset;
      average_mg += parameters_[idx][MG];
      average_eg += parameters_[idx][EG];

      if (!(piece == kPawn && (square <= Squares::kH1 || square >= kA8)))
        ++total_active_squares;
    }

    average_mg /= total_active_squares;
    average_eg /= total_active_squares;

    for (int square = 0; square < kSquareCount; square++) {
      const int idx = piece * kSquareCount + square + offset;

      if (!(piece == kPawn && (square <= Squares::kH1 || square >= kA8))) {
        parameters_[idx][MG] -= average_mg;
        parameters_[idx][EG] -= average_eg;
      }
    }

    parameters_[piece][MG] += average_mg;
    parameters_[piece][EG] += average_eg;
  }
}

void Tuner::PrintParameters() {
  // NormalizePSQTs();
  std::size_t index = 0;

  fmt::print("constexpr PieceTable<ScorePair> kPieceValues = ");
  PrintArray(index, kPieceValues.size(), parameters_);

  fmt::print("constexpr PieceSquareTable<ScorePair> kPieceSquareTable = ");
  Print2DArray(index, kNumPieceTypes, kSquareCount, parameters_);

  fmt::print("constexpr KnightMobilityTable<ScorePair> kKnightMobility = ");
  PrintArray(index, kKnightMobility.size(), parameters_);

  fmt::print("constexpr BishopMobilityTable<ScorePair> kBishopMobility = ");
  PrintArray(index, kBishopMobility.size(), parameters_);

  fmt::print("constexpr RookMobilityTable<ScorePair> kRookMobility = ");
  PrintArray(index, kRookMobility.size(), parameters_);

  fmt::print("constexpr QueenMobilityTable<ScorePair> kQueenMobility = ");
  PrintArray(index, kQueenMobility.size(), parameters_);

  fmt::print("constexpr RankTable<ScorePair> kPassedPawnBonus = ");
  PrintArray(index, kNumRanks, parameters_);

  fmt::print("constexpr RankTable<ScorePair> kPawnPhalanxBonus = ");
  PrintArray(index, kNumRanks, parameters_);

  fmt::print("constexpr RankTable<ScorePair> kDefendedPawnBonus = ");
  PrintArray(index, kNumRanks, parameters_);

  fmt::print("constexpr FileTable<ScorePair> kDoubledPawnPenalty = ");
  PrintArray(index, kNumFiles, parameters_);

  fmt::print("constexpr FileTable<ScorePair> kIsolatedPawnPenalty = ");
  PrintArray(index, kNumFiles, parameters_);

  fmt::print(
      "constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = ");
  Print2DArray(index, 2, kNumFiles, parameters_);

  fmt::print("constexpr std::array<ScorePair, 12> kPawnShelterTable = ");
  PrintArray(index, kPawnShelterTable.size(), parameters_, 3);

  fmt::print("constexpr std::array<ScorePair, 21> kPawnStormTable = ");
  PrintArray(index, kPawnStormTable.size(), parameters_, 3);

  fmt::print("constexpr std::array<ScorePair, 8> kKingPPDistanceTable = ");
  PrintArray(index, kKingPPDistanceTable.size(), parameters_);

  fmt::print(
      "constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable "
      "= ");
  PrintArray(index, kEnemyKingPPDistanceTable.size(), parameters_);

  fmt::print("constexpr ScorePair kKingCantReachPPBonus = ");
  PrintTerm(index, parameters_);

  fmt::println("");

  fmt::print(
      "constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = ");
  Print2DArray(index, 2, kNumFiles, parameters_);

  fmt::print("constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = ");
  Print2DArray(index, kNumPieceTypes, 8, parameters_);

  fmt::print("constexpr PieceTable<ScorePair> kSafeCheckBonus = ");
  PrintArray(index, kNumPieceTypes, parameters_);

  fmt::print(
      "constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty "
      "= ");
  Print2DArray(index, kNumPieceTypes, 2, parameters_);

  fmt::print("constexpr PieceTable<ScorePair> kPawnPushThreat = ");
  PrintArray(index, kNumPieceTypes, parameters_);

  fmt::print(
      "constexpr PieceTable<std::array<ScorePair, 2>> "
      "kThreatenedByKnightPenalty = ");
  Print2DArray(index, kNumPieceTypes, 2, parameters_);

  fmt::print(
      "constexpr PieceTable<std::array<ScorePair, 2>> "
      "kThreatenedByBishopPenalty = ");
  Print2DArray(index, kNumPieceTypes, 2, parameters_);

  fmt::print(
      "constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty "
      "= ");
  Print2DArray(index, kNumPieceTypes, 2, parameters_);

  fmt::print("constexpr OutpostTable<ScorePair> kKnightOutpostTable = ");
  PrintArray(index, kKnightOutpostTable.size(), parameters_);
  fmt::print("constexpr OutpostTable<ScorePair> kBishopOutpostTable = ");
  PrintArray(index, kKnightOutpostTable.size(), parameters_);

  fmt::print("constexpr ScorePair kBishopPairBonus = ");
  PrintTerm(index, parameters_);

  fmt::println("");

  fmt::print("constexpr ScorePair kTempoBonus = ");
  PrintTerm(index, parameters_);

  if (index != parameters_.size()) {
    fmt::println("Failed to collect all eval terms: {} expected {}",
                 index,
                 parameters_.size());
  }
}
