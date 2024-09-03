#include "tuner.h"

#include <fmt/format.h>
// #include <pthread.h>

#ifdef _WIN32
#include <windows.h>
#include <fcntl.h>
#endif

#include <filesystem>
#include <fstream>
#include <iomanip>
#include <sstream>

#include "../data_gen/format/binpack.h"
#include "../engine/evaluation/evaluation.h"
#include "../engine/search/time_mgmt.h"

using namespace eval;

constexpr int kMaxEpochs = 350;
constexpr double kMomentumCoeff = 0.9;
constexpr double kVelocityCoeff = 0.999;
constexpr double kStartLearningRate = 1.0;
constexpr double kEndLearningRate = 0.1;
constexpr double kLearningDropRate = 1.00;
constexpr int kLearningStepRate = 250;
constexpr double kLambda = 1.0;

double decay =
    pow(kEndLearningRate / kStartLearningRate, 1.0 / float(kMaxEpochs * 3));
double rate = kStartLearningRate;

// New constant for batch size
constexpr int kBatchSize = 10'000'000;

inline double Sigmoid(double K, double E) {
  return 1.0 / (1.0 + exp(-K * E / 400.0));
}

bool Tuner::LoadNextBatch() {
  constexpr size_t kBufferSize = 32 * 1024; // 8192 bytes, multiple of 32 and > 4KB
  std::vector<char> buffer(kBufferSize);

  if (current_position_ >= mmap_.size()) {
    return false;
  }

  entries_.clear();
  entries_.reserve(kBatchSize);

  fmt::println("Loading next batch of {} positions ", kBatchSize);

  int loaded_entries = 0;
  int last_percentage = 0;

  while (loaded_entries < kBatchSize && current_position_ < mmap_.size()) {
    size_t bytes_to_read = std::min(kBufferSize, mmap_.size() - current_position_);
    std::memcpy(buffer.data(), mmap_.data() + current_position_, bytes_to_read);
    size_t buffer_pos = 0;

    while (buffer_pos < bytes_to_read && loaded_entries < kBatchSize) {
      Board board;
      GameResult result = -1, score = result;

      if (marlin_format_) {
        if (buffer_pos + sizeof(data_gen::format::MarlinChessBoard) > bytes_to_read) {
          // Not enough data in the buffer, move to the next chunk
          break;
        }

        const data_gen::format::MarlinChessBoard* marlin_board =
            reinterpret_cast<const data_gen::format::MarlinChessBoard*>(buffer.data() + buffer_pos);
        buffer_pos += sizeof(data_gen::format::MarlinChessBoard);

        auto& state = board.GetState();
        state = BoardState{};

        int i = 0;
        for (Square square : BitBoard(marlin_board->occupied)) {
          const U8 piece_data = marlin_board->pieces[i];
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

        state.turn = (marlin_board->turn_and_en_passant & (1 << 7))
                       ? Color::kBlack
                       : Color::kWhite;

        state.en_passant = marlin_board->turn_and_en_passant & 0x7F;
        state.fifty_moves_clock = marlin_board->half_move_clock;
        state.half_moves = (marlin_board->full_move_number - 1) * 2 +
                           (state.turn == Color::kBlack ? 1 : 0);

        result = marlin_board->wdl_outcome / 2.0;
        score = marlin_board->evaluation;
      } else {
        std::string line;
        while (buffer_pos < bytes_to_read && buffer[buffer_pos] != '\n') {
          line += buffer[buffer_pos++];
        }
        if (buffer_pos < bytes_to_read) {
          buffer_pos++; // Skip the newline
        }

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
            entries_.pop_back();
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
      }
    }

    current_position_ += bytes_to_read;
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
      std::string checkpoint_filename = fmt::format("checkpoint_batch{}_epoch{}.txt", batch_count_, epoch);
      WriteCheckpoint(checkpoint_filename);
    }

    // Pre-scheduled Learning Rate drops
    rate *= decay;
  }
}


void Tuner::LoadAndTune(const std::string& source_file) {
  try {
    InitBaseParameters();

    fmt::println("Opening data source: {}", source_file);

    std::filesystem::path file_path(source_file);
    marlin_format_ = file_path.extension() == ".mf";

    if (!std::filesystem::exists(file_path)) {
      throw std::runtime_error(fmt::format("File does not exist: {}", source_file));
    }

    fmt::println("File exists. Absolute path: {}", std::filesystem::absolute(file_path).string());

    // Open the file
    mio::file_handle_type file_handle;
#ifdef _WIN32
    file_handle = CreateFileW(
        file_path.wstring().c_str(),
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    if (file_handle == INVALID_HANDLE_VALUE) {
      throw std::system_error(GetLastError(), std::system_category(), "Error opening file");
    }
#else
    file_handle = open(file_path.c_str(), O_RDONLY);
    if (file_handle == -1) {
      throw std::system_error(errno, std::system_category(), "Error opening file");
    }
#endif

    fmt::println("File opened successfully.");

    // Get file size
    uint64_t file_size;
#ifdef _WIN32
    LARGE_INTEGER size;
    if (!GetFileSizeEx(file_handle, &size)) {
      CloseHandle(file_handle);
      throw std::system_error(GetLastError(), std::system_category(), "Error getting file size");
    }
    file_size = size.QuadPart;
#else
    file_size = lseek(file_handle, 0, SEEK_END);
    lseek(file_handle, 0, SEEK_SET);  // Reset file pointer to beginning
    if (file_size == static_cast<uint64_t>(-1)) {
      close(file_handle);
      throw std::system_error(errno, std::system_category(), "Error getting file size");
    }
#endif

    // Create mmap
    std::error_code error;
#ifdef _WIN32
    mmap_ = mio::make_mmap_source(file_handle, error);
#else
    mmap_ = mio::make_mmap_source(file_handle, 0, file_size, error);
#endif

    if (error) {
#ifdef _WIN32
      CloseHandle(file_handle);
#else
      close(file_handle);
#endif
      throw std::system_error(error, "Error mapping file");
    }

    fmt::println("File mapped successfully. Size: {} bytes", mmap_.size());

    momentum_.resize(num_terms_);
    velocity_.resize(num_terms_);

    while (LoadNextBatch()) {
      fmt::println("Processing batch {}", batch_count_);
      TuneBatch();
      batch_count_++;
    }

    std::string final_checkpoint_filename = fmt::format("final_checkpoint_batch{}.txt", batch_count_);
    WriteCheckpoint(final_checkpoint_filename);

    // The mmap_ object will automatically unmap when it goes out of scope

#ifdef _WIN32
    CloseHandle(file_handle);
#else
    close(file_handle);
#endif

    fmt::println("Finished processing all batches. Total batches: {}", batch_count_);
  } catch (const std::exception& e) {
    fmt::println(stderr, "Error in LoadAndTune: {}", e.what());
    // You might want to add additional error handling or rethrow the exception depending on your needs
  }
}

void Tuner::InitBaseParameters() {
  AddArrayParameter(kPieceValues);
  Add4DArrayParameter(kPawnPieceSquareTable);
  Add4DArrayParameter(kKingPieceSquareTable);
  AddArrayParameter(kKnightMobility);
  AddArrayParameter(kBishopMobility);
  AddArrayParameter(kRookMobility);
  AddArrayParameter(kQueenMobility);
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
  GET_4D_ARRAY_COEFFICIENTS(kPawnPieceSquareTable);
  GET_4D_ARRAY_COEFFICIENTS(kKingPieceSquareTable);
  GET_ARRAY_COEFFICIENTS(kKnightMobility);
  GET_ARRAY_COEFFICIENTS(kBishopMobility);
  GET_ARRAY_COEFFICIENTS(kRookMobility);
  GET_ARRAY_COEFFICIENTS(kQueenMobility);
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
      double target =
          std::lerp(score_sigmoid, static_cast<double>(entry.result), kLambda);

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
}

void Tuner::WriteCheckpoint(const std::string& filename) {
  std::ofstream file(filename);
  if (!file.is_open()) {
    fmt::print(stderr, "Failed to open checkpoint file: {}\n", filename);
    return;
  }

  file << std::fixed << std::setprecision(2);

  size_t index = 0;

  WriteArray(file, "constexpr PieceTable<ScorePair> kPieceValues", kPieceValues.size(), 8, index);
  Write4DArray(file, "constexpr PieceRelativePSQT<ScorePair> kPawnPieceSquareTable", 2, kSquareCount, kNumPieceTypes, kSquareCount, index);
  Write4DArray(file, "constexpr PieceRelativePSQT<ScorePair> kKingPieceSquareTable", 2, kSquareCount, kNumPieceTypes, kSquareCount, index);
  WriteArray(file, "constexpr KnightMobilityTable<ScorePair> kKnightMobility", kKnightMobility.size(), 8, index);
  WriteArray(file, "constexpr BishopMobilityTable<ScorePair> kBishopMobility", kBishopMobility.size(), 8, index);
  WriteArray(file, "constexpr RookMobilityTable<ScorePair> kRookMobility", kRookMobility.size(), 8, index);
  WriteArray(file, "constexpr QueenMobilityTable<ScorePair> kQueenMobility", kQueenMobility.size(), 8, index);
  file << "constexpr ScorePair kTempoBonus = Pair(" << Round(parameters_[index][MG]) << ", " << Round(parameters_[index][EG]) << ");\n";
  index++;

  if (index != parameters_.size()) {
    fmt::print(stderr, "Failed to write all eval terms: {} written, {} expected\n", index, parameters_.size());
  }

  file.close();
  fmt::print("Checkpoint written to: {}\n", filename);
}

void Tuner::WriteArray(std::ofstream& file, const std::string& name, int size, int row_length, size_t& index) {
  file << name << " = {\n";
  for (int i = 0; i < size; i++) {
    if (i % row_length == 0) file << "  ";
    file << "Pair(" << Round(parameters_[index][MG]) << ", " << Round(parameters_[index][EG]) << ")";
    if (i < size - 1) file << ", ";
    if ((i + 1) % row_length == 0 || i == size - 1) file << "\n";
    index++;
  }
  file << "};\n\n";
}

void Tuner::Write2DArray(std::ofstream& file, const std::string& name, int rows, int columns, int row_length, size_t& index) {
  file << name << " = {\n";
  for (int i = 0; i < rows; i++) {
    file << "  {\n";
    for (int j = 0; j < columns; j++) {
      if (j % row_length == 0) file << "    ";
      file << "Pair(" << Round(parameters_[index][MG]) << ", " << Round(parameters_[index][EG]) << ")";
      if (j < columns - 1) file << ", ";
      if ((j + 1) % row_length == 0 || j == columns - 1) file << "\n";
      index++;
    }
    file << "  }";
    if (i < rows - 1) file << ",";
    file << "\n";
  }
  file << "};\n\n";
}

void Tuner::Write3DArray(std::ofstream& file, const std::string& name, int dim1, int dim2, int dim3, size_t& index) {
  file << name << " = {\n";
  for (int i = 0; i < dim1; i++) {
    file << "  {\n";
    for (int j = 0; j < dim2; j++) {
      file << "    {";
      for (int k = 0; k < dim3; k++) {
        file << "Pair(" << Round(parameters_[index][MG]) << ", " << Round(parameters_[index][EG]) << ")";
        if (k < dim3 - 1) file << ", ";
        index++;
      }
      file << "}";
      if (j < dim2 - 1) file << ",";
      file << "\n";
    }
    file << "  }";
    if (i < dim1 - 1) file << ",";
    file << "\n";
  }
  file << "};\n\n";
}

void Tuner::Write4DArray(std::ofstream& file, const std::string& name, int dim1, int dim2, int dim3, int dim4, size_t& index) {
  file << name << " = {{\n";
  for (int d1 = 0; d1 < dim1; d1++) {
    file << "  {{ // Bucket " << d1 << "\n";
    for (int d2 = 0; d2 < dim2; d2++) {
      file << "    {{ // Bucket " << d2 << "\n";
      for (int d3 = 0; d3 < dim3; d3++) {
        file << "      { // Piece " << d3 << "\n        ";
        for (int d4 = 0; d4 < dim4; d4++) {
          file << "Pair(" << Round(parameters_[index][MG]) << ", " << Round(parameters_[index][EG]) << ")";
          if (d4 < dim4 - 1) file << ", ";
          if ((d4 + 1) % 8 == 0 && d4 < dim4 - 1) file << "\n        ";
          index++;
        }
        file << "\n      }";
        if (d3 < dim3 - 1) file << ",";
        file << "\n";
      }
      file << "    }}";
      if (d2 < dim2 - 1) file << ",";
      file << "\n";
    }
    file << "  }}";
    if (d1 < dim1 - 1) file << ",";
    file << "\n";
  }
  file << "}};\n\n";
}