#ifndef INTEGRAL_MAGICS_ATTACKS_H_
#define INTEGRAL_MAGICS_ATTACKS_H_

#include "../chess/bitboard.h"

namespace magics::attacks {

const int kBishopBlockerCombinations = 512;
const int kRookBlockerCombinations = 4096;

extern std::array<std::array<BitBoard, kBishopBlockerCombinations>, Square::kSquareCount> bishop_attacks;
extern std::array<std::array<BitBoard, kRookBlockerCombinations>, Square::kSquareCount> rook_attacks;

BitBoard generate_bishop_mask(Square square);

BitBoard generate_rook_mask(Square square);

BitBoard generate_bishop_moves(Square square, const BitBoard &occupied);

BitBoard generate_rook_moves(Square square, const BitBoard &occupied);

std::vector<BitBoard> create_blockers(BitBoard moves);

void initialize();

}

#endif // INTEGRAL_MAGICS_ATTACKS_H_