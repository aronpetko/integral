#include "pawn_pair_features.h"

namespace nnue::pawn_pair {

[[nodiscard]] PawnId GetPawnId(Square pawn_square,
                               Color pawn_color,
                               Color perspective) {
  const std::size_t enemy_offset =
      kTotalPawnSquares * (pawn_color != perspective);
  return enemy_offset + pawn_square - kFirstPawnSquare;
}

[[nodiscard]] U16 GetPawnIndex(PawnId first_pawn, PawnId second_pawn) {
  const PawnId high = std::max(first_pawn, second_pawn);
  const PawnId low = std::min(first_pawn, second_pawn);
  return high * (high - 1) / 2 + low;
}

[[nodiscard]] U16 GetPawnPairIndex(Square first_pawn_square,
                                   Color first_pawn_color,
                                   Square second_pawn_square,
                                   Color second_pawn_color,
                                   Color perspective,
                                   Square king_square) {
  // Horizontal mirroring
  const U8 square_flip =
      (0b111000 * perspective) | (0b111 * (king_square.File() >= kFileE));
  const PawnId first_pawn_id =
      GetPawnId(first_pawn_square ^ square_flip, first_pawn_color, perspective);
  const PawnId second_pawn_id = GetPawnId(
      second_pawn_square ^ square_flip, second_pawn_color, perspective);
  return GetPawnIndex(first_pawn_id, second_pawn_id);
}

}  // namespace nnue::pawn_pair