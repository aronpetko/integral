#ifndef INTEGRAL_EVAL_H_
#define INTEGRAL_EVAL_H_

#include "../../chess/board.h"
#include "../../tuner/spsa.h"
#include "pawn_structure_cache.h"
#include "terms.h"

namespace eval {

inline Tunable see_pawn_score("see_pawn_score", 98, 50, 150, 10);
inline Tunable see_knight_score("see_knight_score", 299, 200, 400, 25);
inline Tunable see_bishop_score("see_bishop_score", 300, 200, 400, 25);
inline Tunable see_rook_score("see_rook_score", 533, 400, 600, 25);
inline Tunable see_queen_score("see_queen_score", 921, 700, 1100, 50);
inline Tunable see_king_score("see_king_score", 0, 0, 0, 1);  // Always 0
inline Tunable see_none_score("see_none_score", 0, 0, 0, 1);  // Always 0

// clang-format off
inline std::array<Tunable, kNumPieceTypes + 1> kSEEPieceScores = {
    see_pawn_score,
    see_knight_score,
    see_bishop_score,
    see_rook_score,
    see_queen_score,
    see_king_score,
    see_none_score
};
// clang-format on

constexpr int kMaxPhase = 24;

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