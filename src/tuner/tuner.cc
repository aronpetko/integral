#include "tuner.h"

#include <fstream>
#include <sstream>

#include "../engine/eval.h"

using namespace eval;

void Tuner::LoadFromFile(std::string source_file) {
  std::ifstream file(source_file);
  std::cout << source_file << std::endl;

  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      std::cout << line << std::endl;
      const auto bracket_pos = line.find_last_of('[');
      if (bracket_pos != std::string::npos) {
        // Extract the FEN part of the line (everything before the last '[')
        const auto fen = line.substr(0, bracket_pos - 1);

        Board board;
        board.SetFromFen(fen);
        std::cout << fen << std::endl;

        // Extract the WDL marker (between the brackets)
        auto end_bracket_pos = line.find_last_of(']');
        if (end_bracket_pos != std::string::npos &&
            bracket_pos + 1 < end_bracket_pos) {
          const auto wdl =
              line.substr(bracket_pos + 1, end_bracket_pos - bracket_pos - 1);
          std::cout << wdl << std::endl;

          GameResult result;
          if (wdl == "0.0") {
            result = kBlackWon;
          } else if (wdl == "0.5") {
            result = kDrawn;
          } else if (wdl == "1.0") {
            result = kWhiteWon;
          }

          entries_.push_back(CreateEntry(board.GetState(), result));
          std::cout << "FEN: " << fen << " | WDL: " << wdl << std::endl;
        }
      }
    }
  } else {
    std::cout << "Unable to open file" << std::endl;
  }

  file.close();
}

void Tuner::InitBaseParameters() {
  Add2DArrayParameter<PieceType::kNumTypes, kSquareCount>(kPieceSquareTable);
  AddArrayParameter(kPieceValues);
  AddArrayParameter(kKnightMobility);
  AddArrayParameter(kBishopMobility);
  AddArrayParameter(kRookMobility);
  AddArrayParameter(kQueenMobility);
  AddArrayParameter(kPassedPawn);
  AddSingleParameter(kTempoBonus);
}

TunerEntry Tuner::CreateEntry(const BoardState& state, GameResult result) {
  TunerEntry entry;
  entry.phase = GetPhase(state);
  entry.result = result;

  std::cout << "1";
  // Save time by computing phase scalars now
  entry.p_factors[0] = 0 + entry.phase / 24.0;
  entry.p_factors[1] = 1 - entry.phase / 24.0;

  // Save a white POV static evaluation
  trace = EvalTrace{};
  entry.static_eval = Evaluate(state) * (state.turn == Color::kWhite ? 1 : -1);
  std::cout << "2";

  const auto coefficients = GetCoefficients();
  for (int i = 0; i < coefficients.size(); i++) {
    if (coefficients[i] != 0) {
      entry.coefficient_entries.push_back({i, coefficients[i]});
    }
  }
  std::cout << "3";

  // Save some of the evaluation modifiers
  entry.eval = trace.eval;
  entry.turn = state.turn;

  return entry;
}

std::vector<I16> Tuner::GetCoefficients() {
  std::vector<I16> coefficients;

#define GET_COEFFICIENT(term) \
  coefficients.push_back(trace.term[Color::kWhite] - trace.term[Color::kBlack])
#define GET_ARRAY_COEFFICIENTS(arr) \
  for (int j = 0; j < arr.size(); ++j) GET_COEFFICIENT(arr[j])
#define GET_2D_ARRAY_COEFFICIENTS(term) \
  for (int k = 0; k < term.size(); ++k) GET_ARRAY_COEFFICIENTS(term[k])

  GET_2D_ARRAY_COEFFICIENTS(kPieceSquareTable);
  GET_ARRAY_COEFFICIENTS(kPieceValues);
  GET_ARRAY_COEFFICIENTS(kKnightMobility);
  GET_ARRAY_COEFFICIENTS(kBishopMobility);
  GET_ARRAY_COEFFICIENTS(kRookMobility);
  GET_ARRAY_COEFFICIENTS(kQueenMobility);
  GET_ARRAY_COEFFICIENTS(kPassedPawn);
  GET_COEFFICIENT(kTempoBonus);

  return coefficients;
}

Score Tuner::ComputeEvaluation(TunerEntry& entry) const {
  ScorePair score_pair = kTempoBonus;
  for (const auto& coefficient : entry.coefficient_entries) {
    score_pair += parameters_[coefficient.index] * coefficient.value;
  }

  // Scaling factor to maintain precision in integer calculations
  constexpr int kScaleFactor = 1000;

  const int phase = std::min(entry.phase, kMaxPhase);
  const int phase_percent = 100 * (kMaxPhase - phase) / kMaxPhase;

  // Convert to a scale factor between 0 and kScaleFactor
  const int interpolation_factor = kScaleFactor * phase_percent / 100;

  // Interpolate between middle game and end game scores
  const int mid_score =
      score_pair.MiddleGame() * (kScaleFactor - interpolation_factor);
  const int end_score = score_pair.EndGame() * interpolation_factor;

  const Score tapered_eval = (mid_score + end_score) / kScaleFactor;
  return std::clamp(tapered_eval, -kMateScore + 1, kMateScore - 1);
}