#include "attacks.h"
#include "precomputed.h"

namespace magics::attacks {

std::array<std::array<BitBoard, kBishopBlockerCombinations>, Square::kSquareCount> bishop_attacks{};
std::array<std::array<BitBoard, kRookBlockerCombinations>, Square::kSquareCount> rook_attacks{};

template<Direction Dir>
int DistanceToEdge(int square) {
  switch (Dir) {
    case Direction::kEast:
      return 7 - File(square);
    case Direction::kNorth:
      return 7 - Rank(square);
    case Direction::kWest:
      return File(square);
    case Direction::kSouth:
      return Rank(square);
    case Direction::kNorthEast:
      return std::min(7 - Rank(square), 7 - File(square));
    case Direction::kNorthWest:
      return std::min(7 - Rank(square), File(square));
    case Direction::kSouthEast:
      return std::min(Rank(square), 7 - File(square));
    case Direction::kSouthWest:
      return std::min(Rank(square), File(square));
    default:
      throw std::invalid_argument("unexpected direction");
  }
}

template<Direction dir>
BitBoard SlidingAttacks(U8 from, const BitBoard &occupied) {
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
BitBoard SlidingOccupancies(U8 from) {
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
  for (int square = 0; square < Square::kSquareCount; square++) {
    if (moves.IsSet(square)) {
      SetBits.push_back(square);
    }
  }

  std::vector<BitBoard> blockers;
  BitBoard subset = moves;

  const U64 num_permutations = 1ULL << SetBits.size();
  for (int i = 0; i <= num_permutations; i++) {
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

void Initialize() {
  // Initialize the mask + blocker combinations for bishops and rooks
  for (int square = 0; square < Square::kSquareCount; square++) {
    // Compute the attack and blocker combinations for bishops
    auto entry = kBishopMagics[square];
    auto blockers = attacks::CreateBlockers(entry.mask);

    std::array<BitBoard, kBishopBlockerCombinations> square_bishop_attacks{};

    for (const auto &occupied : blockers) {
      const U64 magic_index = ((entry.mask & occupied.AsU64()) * entry.magic) >> entry.shift;
      square_bishop_attacks[magic_index] = attacks::GenerateBishopMoves(Square(square), occupied);
    }

    bishop_attacks[square] = square_bishop_attacks;

    // Compute the attack and blocker combinations for rooks
    entry = kRookMagics[square];
    blockers = attacks::CreateBlockers(entry.mask);

    std::array<BitBoard, kRookBlockerCombinations> square_rook_attacks{};

    for (const auto &occupied : blockers) {
      const U64 magic_index = ((entry.mask & occupied.AsU64()) * entry.magic) >> entry.shift;
      square_rook_attacks[magic_index] = attacks::GenerateRookMoves(Square(square), occupied);
    }

    rook_attacks[square] = square_rook_attacks;
  }
}

} // namespace magic::attacks