#ifndef INTEGRAL_PAWN_PAIR_FEATURES_H
#define INTEGRAL_PAWN_PAIR_FEATURES_H

#include "../../../../../shared/multi_array.h"
#include "../../../../../shared/nnue/definitions.h"
#include "../../../../chess/bitboard.h"
#include "../../../../utils/types.h"

namespace nnue::pawn_pair {

// The first and last square a pawn can stand on
constexpr Square kFirstPawnSquare = Squares::kA2;
constexpr Square kLastPawnSquare = Squares::kH7;
// The total number of possible squares a pawn can stand on
constexpr std::size_t kTotalPawnSquares =
    kLastPawnSquare - kFirstPawnSquare + 1;
// Pawn Square x Pawn Color
constexpr std::size_t kPawnIds = kTotalPawnSquares * Color::kNumColors;

constexpr std::array<BitBoard, 64> kAdjacentFileMasks = []() {
  std::array<BitBoard, 64> masks{};
  for (Square sq = kFirstPawnSquare; sq <= kLastPawnSquare; ++sq) {
    const auto file = sq.File();
    BitBoard mask = kFileMasks[file];
    // Adjacent left file
    if (file > File::kFileA) {
      mask |= kFileMasks[file - 1];
    }
    // Adjacent right file
    if (file < File::kFileH) {
      mask |= kFileMasks[file + 1];
    }
    masks[sq] = mask;
  }
  return masks;
}();

using PawnId = U8;

[[nodiscard]] PawnId GetPawnId(Square pawn_square,
                               Color pawn_color,
                               Color perspective);

[[nodiscard]] U16 GetPawnIndex(PawnId first_pawn, PawnId second_pawn);

[[nodiscard]] U16 GetPawnPairIndex(Square first_pawn_square,
                                           Color first_pawn_color,
                                           Square second_pawn_square,
                                           Color second_pawn_color,
                                           Color perspective,
                                           Square king_square);

}  // namespace nnue::pawn_pair

#endif  // INTEGRAL_PAWN_PAIR_FEATURES_H
