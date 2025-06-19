#include "attacks.h"

#include "precomputed.h"

#ifdef USE_PEXT
#include <immintrin.h>
#endif

namespace magics::attacks {

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

std::vector<BitBoard> CreateBlockers(BitBoard moves) {
  std::vector<U8> SetBits;
  SetBits.reserve(moves.PopCount());

  // Store the indices (from the LSB) of each set bit in the moves bitboard
  for (int square = 0; square < kSquareCount; square++) {
    if (moves.IsSet(square)) {
      SetBits.push_back(square);
    }
  }

  std::vector<BitBoard> blockers;
  BitBoard subset = moves;

  const U64 num_permutations = 1ULL << SetBits.size();
  for (U64 i = 0; i <= num_permutations; i++) {
    BitBoard blocker;
    for (U8 bit : SetBits) {
      // Check if the bit is set in subset, not in the index
      if (subset.IsSet(bit)) {
        blocker.SetBit(bit);
      }
    }

    blockers.push_back(blocker);

    // Carey-Ripley method to get next blocker subset
    subset = (subset - 1) & moves;
  }

  return blockers;
}

BitBoard GenerateBishopMask(Square square) {
  return SlidingOccupancies<Direction::kNorthWest>(square) |
         SlidingOccupancies<Direction::kNorthEast>(square) |
         SlidingOccupancies<Direction::kSouthWest>(square) |
         SlidingOccupancies<Direction::kSouthEast>(square);
}

BitBoard GenerateRookMask(Square square) {
  return SlidingOccupancies<Direction::kNorth>(square) |
         SlidingOccupancies<Direction::kEast>(square) |
         SlidingOccupancies<Direction::kSouth>(square) |
         SlidingOccupancies<Direction::kWest>(square);
}

BitBoard GenerateBishopMoves(Square square, const BitBoard& occupied) {
  return SlidingAttacks<Direction::kNorthWest>(square, occupied) |
         SlidingAttacks<Direction::kNorthEast>(square, occupied) |
         SlidingAttacks<Direction::kSouthWest>(square, occupied) |
         SlidingAttacks<Direction::kSouthEast>(square, occupied);
}

BitBoard GenerateRookMoves(Square square, const BitBoard& occupied) {
  return SlidingAttacks<Direction::kNorth>(square, occupied) |
         SlidingAttacks<Direction::kEast>(square, occupied) |
         SlidingAttacks<Direction::kSouth>(square, occupied) |
         SlidingAttacks<Direction::kWest>(square, occupied);
}

U64 GetBishopAttackIndex(Square square, const BitBoard& occupied) {
#ifdef USE_PEXT
  return _pext_u64(occupied.AsU64(), kBishopMagics[square].mask);
#else
  const auto& entry = kBishopMagics[square];
  return ((occupied.AsU64() & entry.mask) * entry.magic) >> entry.shift;
#endif
}

U64 GetRookAttackIndex(Square square, const BitBoard& occupied) {
#ifdef USE_PEXT
  return _pext_u64(occupied.AsU64(), kRookMagics[square].mask);
#else
  const auto& entry = kRookMagics[square];
  return ((occupied.AsU64() & entry.mask) * entry.magic) >> entry.shift;
#endif
}

// Generic attack table generation function
template <typename AttacksTable,
          typename MagicEntry,
          size_t kBlockerCombinations>
AttacksTable GenerateAttacks(
    const std::array<MagicEntry, kSquareCount>& magics,
    const std::function<BitBoard(Square, const BitBoard&)>& generate_moves,
    const std::function<U64(Square, const BitBoard&)>& get_index) {
  AttacksTable attacks{};

  for (int square = 0; square < kSquareCount; square++) {
    auto blockers = attacks::CreateBlockers(magics[square].mask);
    std::array<BitBoard, kBlockerCombinations> square_attacks{};

    for (const auto& occupied : blockers) {
      const U64 index = get_index(Square(square), occupied);
      square_attacks[index] = generate_moves(Square(square), occupied);
    }

    attacks[square] = square_attacks;
  }

  return attacks;
}

BishopAttacksTable GenerateBishopAttacks() {
  return GenerateAttacks<BishopAttacksTable,
                         decltype(kBishopMagics)::value_type,
                         kBishopBlockerCombinations>(
      kBishopMagics, attacks::GenerateBishopMoves, GetBishopAttackIndex);
}

RookAttacksTable GenerateRookAttacks() {
  return GenerateAttacks<RookAttacksTable,
                         decltype(kRookMagics)::value_type,
                         kRookBlockerCombinations>(
      kRookMagics, attacks::GenerateRookMoves, GetRookAttackIndex);
}

BishopAttacksTable kBishopAttacks = GenerateBishopAttacks();
RookAttacksTable kRookAttacks = GenerateRookAttacks();

}  // namespace magics::attacks