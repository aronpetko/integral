#ifndef INTEGRAL_MAGICS_ATTACKS_H_
#define INTEGRAL_MAGICS_ATTACKS_H_

#include "../chess/bitboard.h"

namespace magics::attacks {

constexpr int kBishopBlockerCombinations = 512;
constexpr int kRookBlockerCombinations = 4096;

extern std::array<std::array<BitBoard, kBishopBlockerCombinations>, Square::kSquareCount> bishop_attacks;
extern std::array<std::array<BitBoard, kRookBlockerCombinations>, Square::kSquareCount> rook_attacks;

BitBoard GenerateBishopMask(Square square);

BitBoard GenerateRookMask(Square square);

BitBoard GenerateBishopMoves(Square square, const BitBoard &occupied);

BitBoard GenerateRookMoves(Square square, const BitBoard &occupied);

std::vector<BitBoard> CreateBlockers(BitBoard moves);

void Initialize();

}

#endif // INTEGRAL_MAGICS_ATTACKS_H_