#ifndef INTEGRAL_EVAL_H_
#define INTEGRAL_EVAL_H_

#include "board.h"

namespace eval {

const int kDrawScore = 0;
const int kMateScore = 1e8;
const int kInfiniteScore = 1e8 + 1;

const std::array<int, PieceType::kNumTypes + 1> kSEEPieceScores = {
    100, // pawn
    300, // knight
    300, // bishop
    500, // rook
    900, // queen
    0, // king
    0, // none
};

bool is_mate_score(int evaluation);

int mate_in(int evaluation);

bool static_exchange(Move move, int threshold, const BoardState &state);

int evaluate(const BoardState &state);

}

#endif // INTEGRAL_EVAL_H_