#ifndef INTEGRAL_TUNER_H
#define INTEGRAL_TUNER_H

#include "../chess/board.h"
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

class Tuner {
 public:
  Tuner() {}

  void LoadFromFile(const std::string& source_file);

  void Tune();

 private:
  void InitBaseParameters();

  void PrintParameters();

  [[nodiscard]] TunerEntry CreateEntry(const BoardState& state, GameResult result) const;

  [[nodiscard]] std::vector<I16> GetCoefficients() const;

  [[nodiscard]] double ComputeEvaluation(const TunerEntry& entry, Score base) const;

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