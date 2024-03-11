#ifndef INTEGRAL_EVAL_H_
#define INTEGRAL_EVAL_H_

#include "board.h"

namespace eval {

const int kDrawScore = 0;
const int kMateScore = 1e9;

const std::vector<int> kPieceValues = {
    0, // none
    100, // pawn
    310, // knight
    325, // bishop
    500, // rook
    900, // queen
    20000, // king
};

bool is_end_game(BoardState &state);

int evaluate(BoardState &state);

}

#endif // INTEGRAL_EVAL_H_