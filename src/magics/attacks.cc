#include "attacks.h"
#include "precomputed.h"

namespace magics::attacks {

template<Direction Dir>
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
    return 0; // This line will never be reached, it's just to satisfy the compiler
  }
}

// Helper type trait for the static_assert
template<Direction>
bool always_false = false;

template<Direction dir>
constexpr BitBoard SlidingAttacks(U8 from, const BitBoard &occupied) {
  BitBoard attacks;
  BitBoard current = BitBoard::FromSquare(from);

  for (int i = 0; i < DistanceToEdge<dir>(from); i++) {
    current = Shift<dir>(current);
    attacks |= current;

    if (occupied & current)
      break;
  }

  return attacks;
}

template<Direction dir>
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
  return SlidingOccupancies<Direction::kNorthWest>(square) | SlidingOccupancies<Direction::kNorthEast>(square)
      | SlidingOccupancies<Direction::kSouthWest>(square) | SlidingOccupancies<Direction::kSouthEast>(square);
}

BitBoard GenerateRookMask(Square square) {
  return SlidingOccupancies<Direction::kNorth>(square) | SlidingOccupancies<Direction::kEast>(square)
      | SlidingOccupancies<Direction::kSouth>(square) | SlidingOccupancies<Direction::kWest>(square);
}

BitBoard GenerateBishopMoves(Square square, const BitBoard &occupied) {
  return SlidingAttacks<Direction::kNorthWest>(square, occupied) | SlidingAttacks<Direction::kNorthEast>(square, occupied)
      | SlidingAttacks<Direction::kSouthWest>(square, occupied) | SlidingAttacks<Direction::kSouthEast>(square, occupied);
}

BitBoard GenerateRookMoves(Square square, const BitBoard &occupied) {
  return SlidingAttacks<Direction::kNorth>(square, occupied) | SlidingAttacks<Direction::kEast>(square, occupied)
      | SlidingAttacks<Direction::kSouth>(square, occupied) | SlidingAttacks<Direction::kWest>(square, occupied);
}

BishopAttacksTable GenerateBishopAttacks() {
  BishopAttacksTable bishop_attacks{};

  for (int square = 0; square < kSquareCount; square++) {
    // Compute the attack and blocker combinations for bishops
    auto entry = kBishopMagics[square];
    auto blockers = attacks::CreateBlockers(entry.mask);

    std::array<BitBoard, kBishopBlockerCombinations> square_bishop_attacks{};

    for (const auto &occupied : blockers) {
      const U64 magic_index = ((entry.mask & occupied.AsU64()) * entry.magic) >> entry.shift;
      square_bishop_attacks[magic_index] = attacks::GenerateBishopMoves(Square(square), occupied);
    }

    bishop_attacks[square] = square_bishop_attacks;
  }

  return bishop_attacks;
}

RookAttacksTable GenerateRookAttacks() {
  RookAttacksTable rook_attacks{};

  for (int square = 0; square < kSquareCount; square++) {
    // Compute the attack and blocker combinations for rooks
    auto entry = kRookMagics[square];
    auto blockers = attacks::CreateBlockers(entry.mask);

    std::array<BitBoard, kRookBlockerCombinations> square_rook_attacks{};

    for (const auto &occupied : blockers) {
      const U64 magic_index = ((entry.mask & occupied.AsU64()) * entry.magic) >> entry.shift;
      square_rook_attacks[magic_index] = attacks::GenerateRookMoves(Square(square), occupied);
    }

    rook_attacks[square] = square_rook_attacks;
  }

  return rook_attacks;
}

BishopAttacksTable kBishopAttacks = GenerateBishopAttacks();
RookAttacksTable kRookAttacks = GenerateRookAttacks();

} // namespace magic::attacks