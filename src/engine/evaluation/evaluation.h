#ifndef INTEGRAL_EVAL_H_
#define INTEGRAL_EVAL_H_

#include "../../chess/board.h"
#include "../../tuner/spsa.h"

namespace eval {

TUNABLE(kSeePawnScore, 109, 50, 150, false);
TUNABLE(kSeeKnightScore, 370, 200, 400, false);
TUNABLE(kSeeBishopScore, 390, 200, 400, false);
TUNABLE(kSeeRookScore, 600, 400, 600, false);
TUNABLE(kSeeQueenScore, 1200, 700, 1100, false);
TUNABLE(kSeeKingScore, 0, 0, 0, true);  // Always 0
TUNABLE(kSeeNoneScore, 0, 0, 0, true);  // Always 0

// clang-format off
inline std::array kSeePieceScores = {
    &kSeePawnScore,
    &kSeeKnightScore,
    &kSeeBishopScore,
    &kSeeRookScore,
    &kSeeQueenScore,
    &kSeeKingScore,
    &kSeeNoneScore
};
// clang-format on

// Constants derived from WDL_model
constexpr std::array kAs = {
    86.66506958, -259.82299819, 205.33735813, 127.53923650};

[[nodiscard]] static Score NormalizeScore(Score score, int material_count) {
  if (score == 0 || std::abs(score) >= kTBWinInMaxPlyScore) return score;

  const auto material_constant =
      static_cast<double>(std::clamp(material_count, 17, 78)) / 58.0;
  const auto wdl_param =
      ((kAs[0] * material_constant + kAs[1]) * material_constant + kAs[2]) *
          material_constant +
      kAs[3];
  return static_cast<Score>(
      std::round(100.0 * static_cast<double>(score) / wdl_param));
}

[[nodiscard]] static bool IsMateScore(int evaluation) {
  return kMateScore - std::abs(evaluation) <= kMaxPlyFromRoot;
}

[[nodiscard]] static int MateIn(int evaluation) {
  if (evaluation > 0 && evaluation <= kMateScore) {  // Mate in favor
    return (kMateScore - evaluation + 1) / 2;
  } else if (evaluation < 0 && evaluation >= -kMateScore) {  // Mate against
    return -(kMateScore + evaluation) / 2;
  }
  // Not a mate score
  return evaluation;
}

bool StaticExchange(Move move, int threshold, const BoardState &state);

Score Evaluate(Board &board);

}  // namespace eval

#endif  // INTEGRAL_EVAL_H_