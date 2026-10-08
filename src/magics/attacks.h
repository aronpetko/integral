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

template <Direction Dir>
constexpr int DistanceToEdge(Square square) {
  if constexpr (Dir == Direction::kEast) {
    return 7 - square.File();
  } else if constexpr (Dir == Direction::kNorth) {
    return 7 - square.Rank();
  } else if constexpr (Dir == Direction::kWest) {
    return square.File();
  } else if constexpr (Dir == Direction::kSouth) {
    return square.Rank();
  } else if constexpr (Dir == Direction::kNorthEast) {
    return std::min(7 - square.Rank(), 7 - square.File());
  } else if constexpr (Dir == Direction::kNorthWest) {
    return std::min(7 - square.Rank(), square.File());
  } else if constexpr (Dir == Direction::kSouthEast) {
    return std::min(square.Rank(), 7 - square.File());
  } else if constexpr (Dir == Direction::kSouthWest) {
    return std::min(square.Rank(), square.File());
  } else {
    return 0;  // This line will never be reached, it's just to satisfy the
               // compiler
  }
}

template <Direction dir>
constexpr BitBoard SlidingAttacks(U8 from, const BitBoard& occupied) {
  BitBoard attacks;
  BitBoard current = BitBoard::FromSquare(from);

  for (int i = 0; i < DistanceToEdge<dir>(from); i++) {
    current = Shift<dir>(current);
    attacks |= current;

    if (occupied & current) break;
  }

  return attacks;
}

template <Direction dir>
constexpr BitBoard SlidingOccupancies(U8 from) {
  BitBoard attacks;
  BitBoard current = BitBoard::FromSquare(from);

  for (int i = 1; i < DistanceToEdge<dir>(from); i++) {
    current = Shift<dir>(current);
    attacks |= current;
  }

  return attacks;
}

constexpr BitBoard GenerateBishopMask(Square square) {
  return SlidingOccupancies<Direction::kNorthWest>(square) |
         SlidingOccupancies<Direction::kNorthEast>(square) |
         SlidingOccupancies<Direction::kSouthWest>(square) |
         SlidingOccupancies<Direction::kSouthEast>(square);
}

constexpr BitBoard GenerateRookMask(Square square) {
  return SlidingOccupancies<Direction::kNorth>(square) |
         SlidingOccupancies<Direction::kEast>(square) |
         SlidingOccupancies<Direction::kSouth>(square) |
         SlidingOccupancies<Direction::kWest>(square);
}

constexpr BitBoard GenerateBishopMoves(Square square,
                                       const BitBoard& occupied) {
  return SlidingAttacks<Direction::kNorthWest>(square, occupied) |
         SlidingAttacks<Direction::kNorthEast>(square, occupied) |
         SlidingAttacks<Direction::kSouthWest>(square, occupied) |
         SlidingAttacks<Direction::kSouthEast>(square, occupied);
}

constexpr BitBoard GenerateRookMoves(Square square, const BitBoard& occupied) {
  return SlidingAttacks<Direction::kNorth>(square, occupied) |
         SlidingAttacks<Direction::kEast>(square, occupied) |
         SlidingAttacks<Direction::kSouth>(square, occupied) |
         SlidingAttacks<Direction::kWest>(square, occupied);
}

std::vector<BitBoard> CreateBlockers(BitBoard moves);

}  // namespace magics::attacks

#endif  // INTEGRAL_MAGICS_ATTACKS_H_