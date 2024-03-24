#ifndef INTEGRAL_EVAL_H_
#define INTEGRAL_EVAL_H_

#include "board.h"

namespace eval {

const int kDrawScore = 0;
const int kMateScore = 1e8;

const std::array<int, PieceType::kNumPieceTypes> kPieceValues = {
    100, // pawn
    305, // knight
    315, // bishop
    500, // rook
    900, // queen
    20000, // king
};

bool is_mate_score(int evaluation);

int mate_in(int evaluation);

bool is_end_game(const BoardState &state);

int evaluate(const BoardState &state);

}

#endif // INTEGRAL_EVAL_H_