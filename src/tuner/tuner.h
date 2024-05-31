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
  double scale;
  std::array<double, 2> p_factors;
  std::vector<CoefficientEntry> coefficient_entries;
};

class Tuner {
 public:
  Tuner() {}

  void LoadFromFile(std::string source_file);

  void Tune();

 private:
  void InitBaseParameters();

  TunerEntry CreateEntry(const BoardState& state, GameResult result);

  std::vector<I16> GetCoefficients();

  Score ComputeEvaluation(TunerEntry& entry) const;

  void AddSingleParameter(const ScorePair& parameter) {
    parameters_.emplace_back(parameter);
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
  std::vector<ScorePair> parameters_;
  std::vector<TunerEntry> entries_;
};

#endif  // INTEGRAL_TUNER_H