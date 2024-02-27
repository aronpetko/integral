#ifndef INTEGRAL_EVAL_H_
#define INTEGRAL_EVAL_H_

#include "board.h"

namespace eval {

const int kBestScore = 1e5;
const int kEvenScore = 0;
const int kWorstScore = -1e5;

const std::vector<int> kPieceValues = {
    100, // pawn
    300, // knight
    315, // bishop
    500, // rook
    900, // queen
    900000, // king
};

int evaluate(const std::unique_ptr<BoardState> &state);

}

#endif // INTEGRAL_EVAL_H_