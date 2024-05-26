#ifndef INTEGRAL_EVAL_H_
#define INTEGRAL_EVAL_H_

#include "../chess/board.h"

namespace eval {

constexpr std::array<Score, PieceType::kNumTypes + 1> kSEEPieceScores = {
    100,  // Pawn
    300,  // Knight
    300,  // Bishop
    500,  // Rook
    900,  // Queen
    0,    // King
    0,    // None
};

static bool IsMateScore(int evaluation) {
  return kMateScore - std::abs(evaluation) <= kMaxPlyFromRoot;
}

static int MateIn(int evaluation) {
  if (evaluation > 0 && evaluation <= kMateScore) {  // Mate in favor
    return (kMateScore - evaluation + 1) / 2;
  } else if (evaluation < 0 && evaluation >= -kMateScore) {  // Mate against
    return -(kMateScore + evaluation) / 2;
  }
  // not a mate score
  return evaluation;
}

bool StaticExchange(Move move, int threshold, const BoardState &state);

Score Evaluate(const BoardState &state);

}  // namespace eval

#endif  // INTEGRAL_EVAL_H_