#ifndef INTEGRAL_TUNER_H
#define INTEGRAL_TUNER_H

#include "../chess/board.h"
#include "../engine/eval_terms.h"
#include "../utils/string.h"
#include "../utils/types.h"

struct CoefficientEntry {
  int index;
  I16 value;
};

using GameResult = double;

constexpr GameResult kBlackWon = 0.0;
constexpr GameResult kDrawn = 0.5;
constexpr GameResult kWhiteWon = 1.0;

struct TunerEntry {
  int phase;
  Score static_eval;
  Score eval;
  Color turn;
  GameResult result;
  std::array<double, 2> p_factors;
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
  eval::PieceValueTable<TraceTerm> kPieceValues{};
  eval::PieceSquareTable<TraceTerm> kPieceSquareTable{};
  eval::KnightMobilityTable<TraceTerm> kKnightMobility{};
  eval::BishopMobilityTable<TraceTerm> kBishopMobility{};
  eval::RookMobilityTable<TraceTerm> kRookMobility{};
  eval::QueenMobilityTable<TraceTerm> kQueenMobility{};
  eval::RankTable<TraceTerm> kPassedPawnBonus{};
  eval::RankTable<TraceTerm> kPawnPhalanxBonus{};
  eval::FileTable<TraceTerm> kDoubledPawnPenalty{};
  eval::FileTable<TraceTerm> kIsolatedPawnPenalty{};
  std::array<eval::FileTable<TraceTerm>, 2> kRookOnFileBonus{};
  std::array<TraceTerm, 12> kPawnShelterTable{};
  std::array<TraceTerm, 21> kPawnStormTable{};
  TraceTerm kTempoBonus{};
  Score eval{};
};

inline EvalTrace trace;

#define TUNE

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
  Tuner() : num_terms_(0) {}

  void LoadFromFile(const std::string& source_file);

  void Tune();

 private:
  void InitBaseParameters();

  void PrintParameters();

  [[nodiscard]] TunerEntry CreateEntry(const BoardState& state,
                                       GameResult result) const;

  [[nodiscard]] std::vector<I16> GetCoefficients() const;

  [[nodiscard]] double ComputeEvaluation(const TunerEntry& entry) const;

  [[nodiscard]] double ComputeOptimalK() const;

  [[nodiscard]] VectorPair ComputeGradient(double K) const;

  [[nodiscard]] double StaticEvaluationErrors(double K) const;

  [[nodiscard]] double TunedEvaluationErrors(double K) const;

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

 private:
  int num_terms_;
  std::vector<TermPair> parameters_;
  std::vector<TunerEntry> entries_;
  VectorPair gradients_;
};

#endif  // INTEGRAL_TUNER_H