#ifndef INTEGRAL_POLICY_FEATURES_H
#define INTEGRAL_POLICY_FEATURES_H

#include "../../../../../shared/multi_array.h"
#include "../../../../../shared/nnue/definitions.h"
#include "../../../../chess/move_gen.h"
#include "../../../../magics/attacks.h"
#include "../../../../utils/types.h"

namespace nnue::policy::features {

inline constexpr auto kPieceDestinations = [] {
  MultiArray<BitBoard, Squares::kSquareCount, PieceType::kNumPieceTypes>
      destinations{};
  for (int square = 0; square < Squares::kSquareCount; ++square) {
    destinations[square][PieceType::kPawn] =
        move_gen::kPawnAttackMasks[Color::kWhite][square];
    if (square + 8 < Squares::kSquareCount) {
      destinations[square][PieceType::kPawn] |=
          BitBoard::FromSquare(square + 8);
    }
    destinations[square][PieceType::kKnight] = move_gen::kKnightMasks[square];
    destinations[square][PieceType::kBishop] =
        magics::attacks::GenerateBishopMoves(square, 0);
    destinations[square][PieceType::kRook] =
        magics::attacks::GenerateRookMoves(square, 0);
    destinations[square][PieceType::kQueen] =
        destinations[square][PieceType::kBishop] |
        destinations[square][PieceType::kRook];
    destinations[square][PieceType::kKing] = move_gen::kKingMasks[square];
  }
  return destinations;
}();

inline constexpr auto kPieceOffsets = [] {
  MultiArray<U16, PieceType::kNumPieceTypes, Squares::kSquareCount + 1>
      offsets{};
  U16 current_offset = 0;
  for (int piece = PieceType::kPawn; piece <= PieceType::kKing; ++piece) {
    for (int square = 0; square < Squares::kSquareCount; ++square) {
      offsets[piece][square] = current_offset;
      current_offset += kPieceDestinations[square][piece].PopCount();
    }
    offsets[piece][Squares::kSquareCount] = current_offset;
  }
  return offsets;
}();

// [4 x 22 promotions][2 castles][8 double pushes]
constexpr std::size_t kPromotionStride = 22;
constexpr std::size_t kDoublePushOffset = arch::policy::kOutputSize - 8;
constexpr std::size_t kCastleOffset = kDoublePushOffset - 2;
constexpr std::size_t kPromotionOffset = kCastleOffset - kPromotionStride * 4;

static_assert(kPieceOffsets[PieceType::kKing][Squares::kSquareCount] ==
              kPromotionOffset);

[[nodiscard]] inline std::size_t GetMoveOutputIndex(Move move,
                                                    PieceType moving_piece,
                                                    int flip,
                                                    bool mirror) {
  const Square from = move.GetFrom() ^ flip;
  const Square to = move.GetTo() ^ flip;

  switch (move.GetType()) {
    case MoveType::kPromotion: {
      const int promotion_id = 2 * from.File() + to.File();
      const int type = static_cast<int>(move.GetPromotionType());
      return kPromotionOffset + type * kPromotionStride + promotion_id;
    }
    case MoveType::kCastle: {
      // Matches the trainer, which flips the side when *not* mirrored
      const bool is_kingside = move.GetFrom() < move.GetTo();
      return kCastleOffset + (is_kingside ^ !mirror);
    }
    default:
      if (moving_piece == PieceType::kPawn && (from ^ to) == 16) {
        return kDoublePushOffset + from.File();
      }
      const BitBoard below = kPieceDestinations[from][moving_piece] &
                             (BitBoard::FromSquare(to) - 1);
      return kPieceOffsets[moving_piece][from] + below.PopCount();
  }
}

}  // namespace nnue::policy::features

#endif  // INTEGRAL_POLICY_FEATURES_H
