#ifndef INTEGRAL_TUNER_H
#define INTEGRAL_TUNER_H

#include <fstream>
#include <mio.hpp>

#include "../chess/board.h"
#include "../engine/evaluation/terms.h"
#include "../utils/string.h"
#include "../utils/types.h"

// #define TUNE

struct CoefficientEntry {
  U32 index;
  int value;
};

using GameResult = double;

constexpr GameResult kBlackWon = 10.0;
constexpr GameResult kDrawn = 0.5;
constexpr GameResult kWhiteWon = 1.0;

struct TunerEntry {
  int phase;
  Score static_eval;
  Color turn;
  GameResult result, score;
  std::array<double, 2> phase_factors;
  std::vector<CoefficientEntry> coefficient_entries;
};

using TermPair = std::array<double, 2>;
using VectorPair = std::vector<TermPair>;

enum Phase {
  MG,
  EG
};

using TraceTerm = std::array<I16, 2>;

// A struct that counts the amount of times each term is used and by which side
struct EvalTrace {
  // The names, though they are not constant, must match the above names (for
  // ease of use with the tuner)
  eval::PieceTable<TraceTerm> kPieceValues{};
  eval::PieceRelativePSQT<TraceTerm> kKingPieceSquareTable{};
  eval::PieceRelativePSQT<TraceTerm> kPawnPieceSquareTable{};
  eval::KnightMobilityTable<TraceTerm> kKnightMobility{};
  eval::BishopMobilityTable<TraceTerm> kBishopMobility{};
  eval::RookMobilityTable<TraceTerm> kRookMobility{};
  eval::QueenMobilityTable<TraceTerm> kQueenMobility{};
  TraceTerm kTempoBonus{};
  Score eval{};
};

inline EvalTrace trace;

#ifdef TUNE

#define TRACE_ADD(term, count, color) trace.term[color] += count
#define TRACE_INCREMENT(term, color) trace.term[color]++
#define TRACE_SCALE(s) trace.scale = s
#define TRACE_EVAL(e) trace.eval = e
#else
#define TRACE_ADD(term, count, color)
#define TRACE_INCREMENT(term, color)
#define TRACE_SCALE(s)
#define TRACE_EVAL(e)
#endif

class Tuner {
 public:
  Tuner() : num_terms_(0), batch_count_(1) {}

  void LoadAndTune(const std::string& source_file);

 private:
  void InitBaseParameters();

  void PrintParameters();

  [[nodiscard]] TunerEntry CreateEntry(const BoardState& state,
                                       GameResult result,
                                       Score score) const;

  [[nodiscard]] std::vector<I16> GetCoefficients() const;

  [[nodiscard]] double ComputeEvaluation(const TunerEntry& entry) const;

  [[nodiscard]] double ComputeOptimalK() const;

  [[nodiscard]] VectorPair ComputeGradient(double K, int start, int end) const;

  [[nodiscard]] double StaticEvaluationErrors(double K) const;

  [[nodiscard]] double TunedEvaluationErrors(double K) const;

  [[nodiscard]] bool LoadNextBatch();

  void TuneBatch();

  void AddSingleParameter(const ScorePair& parameter) {
    parameters_.push_back({static_cast<double>(parameter.MiddleGame()),
                           static_cast<double>(parameter.EndGame())});
    num_terms_++;
  }

  template <size_t N>
  void AddArrayParameter(const std::array<ScorePair, N>& parameter) {
    for (const auto& single : parameter) {
      AddSingleParameter(single);
    }
  }

  template <std::size_t N, std::size_t M>
  void Add2DArrayParameter(
      const std::array<std::array<ScorePair, M>, N>& parameter) {
    for (const auto& array : parameter) {
      AddArrayParameter(array);
    }
  }

  template <std::size_t N, std::size_t M, std::size_t L>
  void Add3DArrayParameter(
      const std::array<std::array<std::array<ScorePair, L>, M>, N>& parameter) {
    for (const auto& array : parameter) {
      Add2DArrayParameter(array);
    }
  }

  template <std::size_t N, std::size_t M, std::size_t L, std::size_t K>
  void Add4DArrayParameter(
      const std::array<std::array<std::array<std::array<ScorePair, K>, L>, M>,
                       N>& parameter) {
    for (const auto& array : parameter) {
      Add3DArrayParameter(array);
    }
  }

  void NormalizePSQTs();

  void WriteCheckpoint(const std::string& filename);

  void WriteArray(std::ofstream& file,
                  const std::string& name,
                  int size,
                  int row_length,
                  size_t& index);
  void Write2DArray(std::ofstream& file,
                    const std::string& name,
                    int rows,
                    int columns,
                    int row_length,
                    size_t& index);
  void Write3DArray(std::ofstream& file,
                    const std::string& name,
                    int dim1,
                    int dim2,
                    int dim3,
                    size_t& index);
  void Write4DArray(std::ofstream& file,
                    const std::string& name,
                    int dim1,
                    int dim2,
                    int dim3,
                    int dim4,
                    size_t& index);

 private:
  int num_terms_;
  std::vector<TermPair> parameters_;
  std::vector<TunerEntry> entries_;
  mio::mmap_source mmap_;
  std::size_t current_position_ = 0;
  bool end_of_file_reached_ = false;
  bool marlin_format_ = false;
  VectorPair gradients_, momentum_, velocity_;
  int batch_count_;
};

#endif  // INTEGRAL_TUNER_H