#ifndef INTEGRAL_MAGICS_ATTACKS_H_
#define INTEGRAL_MAGICS_ATTACKS_H_

#include "../../shared/multi_array.h"
#include "../chess/bitboard.h"

namespace magics::attacks {

constexpr int kBishopBlockerCombinations = 512;
constexpr int kRookBlockerCombinations = 4096;

using BishopAttacksTable =
    MultiArray<BitBoard, kSquareCount, kBishopBlockerCombinations>;
using RookAttacksTable =
    MultiArray<BitBoard, kSquareCount, kRookBlockerCombinations>;

extern BishopAttacksTable kBishopAttacks;
extern RookAttacksTable kRookAttacks;

U64 GetBishopAttackIndex(Square square, const BitBoard& occupied);

U64 GetRookAttackIndex(Square square, const BitBoard& occupied);

BitBoard GenerateBishopMask(Square square);

BitBoard GenerateRookMask(Square square);

BitBoard GenerateBishopMoves(Square square, const BitBoard &occupied);

BitBoard GenerateRookMoves(Square square, const BitBoard &occupied);

std::vector<BitBoard> CreateBlockers(BitBoard moves);

}  // namespace magics::attacks

#endif  // INTEGRAL_MAGICS_ATTACKS_H_