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

// Output index of every regular move by [piece][from][to]
inline constexpr auto kNormalMoveIndices = [] {
  MultiArray<U16,
             PieceType::kNumPieceTypes,
             Squares::kSquareCount,
             Squares::kSquareCount>
      indices{};
  for (int piece = PieceType::kPawn; piece <= PieceType::kKing; ++piece) {
    for (int from = 0; from < Squares::kSquareCount; ++from) {
      const BitBoard destinations = kPieceDestinations[from][piece];
      for (int to = 0; to < Squares::kSquareCount; ++to) {
        if (!destinations.IsSet(to)) continue;
        const BitBoard below = destinations & (BitBoard::FromSquare(to) - 1);
        indices[piece][from][to] =
            kPieceOffsets[piece][from] + below.PopCount();
      }
    }
  }
  for (int from = Squares::kA2; from <= Squares::kH2; ++from) {
    indices[PieceType::kPawn][from][from + 16] =
        kDoublePushOffset + Square(from).File();
  }
  return indices;
}();

[[nodiscard]] inline std::size_t GetMoveOutputIndex(Move move,
                                                    PieceType moving_piece,
                                                    int flip,
                                                    bool mirror) {
  const Square from = move.GetFrom() ^ flip;
  const Square to = move.GetTo() ^ flip;

  if (move.GetType() == MoveType::kCastle) [[unlikely]] {
    const bool is_kingside = move.GetFrom() < move.GetTo();
    return kCastleOffset + (is_kingside ^ !mirror);
  }
  if (move.GetType() == MoveType::kPromotion) [[unlikely]] {
    const int promotion_id = 2 * from.File() + to.File();
    const int type = static_cast<int>(move.GetPromotionType());
    return kPromotionOffset + type * kPromotionStride + promotion_id;
  }

  // Regular moves and en passant
  return kNormalMoveIndices[moving_piece][from][to];
}

}  // namespace nnue::policy::features

#endif  // INTEGRAL_POLICY_FEATURES_H
