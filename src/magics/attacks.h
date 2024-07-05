#ifndef INTEGRAL_MAGICS_ATTACKS_H_
#define INTEGRAL_MAGICS_ATTACKS_H_

#include "../chess/bitboard.h"
#include "../utils/multi_array.h"

namespace magics::attacks {

constexpr int kBishopBlockerCombinations = 512;
constexpr int kRookBlockerCombinations = 4096;

using BishopAttacksTable = MultiArray<BitBoard, kSquareCount, kBishopBlockerCombinations>;
using RookAttacksTable = MultiArray<BitBoard, kSquareCount, kRookBlockerCombinations>;

extern BishopAttacksTable kBishopAttacks;
extern RookAttacksTable kRookAttacks;

BitBoard GenerateBishopMask(Square square);

BitBoard GenerateRookMask(Square square);

BitBoard GenerateBishopMoves(Square square, const BitBoard &occupied);

BitBoard GenerateRookMoves(Square square, const BitBoard &occupied);

std::vector<BitBoard> CreateBlockers(BitBoard moves);


}

#endif // INTEGRAL_MAGICS_ATTACKS_H_