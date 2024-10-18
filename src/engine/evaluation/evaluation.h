#ifndef INTEGRAL_EVAL_H_
#define INTEGRAL_EVAL_H_

#include "../../chess/board.h"
#include "../../tuner/spsa.h"
#include "pawn_structure_cache.h"
#include "terms.h"

namespace eval {

TUNABLE(kSeePawnScore, 101, 50, 150, false);
TUNABLE(kSeeKnightScore, 294, 200, 400, false);
TUNABLE(kSeeBishopScore, 295, 200, 400, false);
TUNABLE(kSeeRookScore, 528, 400, 600, false);
TUNABLE(kSeeQueenScore, 916, 700, 1100, false);
TUNABLE(kSeeKingScore, 0, 0, 0, true);  // Always 0
TUNABLE(kSeeNoneScore, 0, 0, 0, true);  // Always 0

// clang-format off
inline std::array<Tunable<int>, kNumPieceTypes + 1> kSeePieceScores = {
    kSeePawnScore,
    kSeeKnightScore,
    kSeeBishopScore,
    kSeeRookScore,
    kSeeQueenScore,
    kSeeKingScore,
    kSeeNoneScore
};
// clang-format on

[[maybe_unused]] static bool IsMateScore(int evaluation) {
  return kMateScore - std::abs(evaluation) <= kMaxPlyFromRoot;
}

[[maybe_unused]] static int MateIn(int evaluation) {
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