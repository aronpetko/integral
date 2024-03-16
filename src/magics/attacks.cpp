#include "attacks.h"
#include "magic_finder.h"
#include "precomputed.h"

namespace magics::attacks {

std::array<std::array<BitBoard, kBishopBlockerCombinations>, Square::kSquareCount> bishop_attacks{};

std::array<std::array<BitBoard, kRookBlockerCombinations>, Square::kSquareCount> rook_attacks{};

template<Direction Dir>
int distance_to_edge(int square) {
  switch (Dir) {
    case Direction::kEast:
      return 7 - file(square);
    case Direction::kNorth:
      return 7 - rank(square);
    case Direction::kWest:
      return file(square);
    case Direction::kSouth:
      return rank(square);
    case Direction::kNorthEast:
      return std::min(7 - rank(square), 7 - file(square));
    case Direction::kNorthWest:
      return std::min(7 - rank(square), file(square));
    case Direction::kSouthEast:
      return std::min(rank(square), 7 - file(square));
    case Direction::kSouthWest:
      return std::min(rank(square), file(square));
    default:
      throw std::invalid_argument("unexpected direction");
  }
}

template<Direction Dir>
BitBoard sliding_attacks(U8 from, const BitBoard &occupied) {
  BitBoard attacks;
  BitBoard current = BitBoard::from_square(from);

  for (int i = 0; i < distance_to_edge<Dir>(from); i++) {
    current = shift<Dir>(current);
    attacks |= current;

    if (occupied & current)
      break;
  }

  return attacks;
}

template<Direction Dir>
BitBoard sliding_occupancies(U8 from) {
  BitBoard attacks;
  BitBoard current = BitBoard::from_square(from);

  for (int i = 1; i < distance_to_edge<Dir>(from); i++) {
    current = shift<Dir>(current);
    attacks |= current;
  }

  return attacks;
}

std::vector<BitBoard> create_blockers(BitBoard moves) {
  std::vector<U8> set_bits;
  set_bits.reserve(moves.pop_count());

  // store the indices (from the LSB) of each set bit in the moves bitboard
  for (U8 square = 0; square < Square::kSquareCount; square++) {
    if (moves.is_set(square)) {
      set_bits.push_back(square);
    }
  }

  std::vector<BitBoard> blockers;
  BitBoard subset = moves;

  const U64 num_permutations = 1ULL << set_bits.size();
  for (int i = 0; i <= num_permutations; i++) {
    BitBoard blocker;
    for (const U8 &set_bit : set_bits) {
      // check if the bit is set in subset, not in the index
      if (subset.is_set(set_bit)) {
        blocker.set_bit(set_bit);
      }
    }

    blockers.push_back(blocker);

    // carey-ripley method to get next blocker subset
    subset = (subset - 1) & moves;
  }

  return blockers;
}

BitBoard generate_bishop_mask(U8 pos) {
  return sliding_occupancies<Direction::kNorthWest>(pos) | sliding_occupancies<Direction::kNorthEast>(pos)
      | sliding_occupancies<Direction::kSouthWest>(pos) | sliding_occupancies<Direction::kSouthEast>(pos);
}

BitBoard generate_rook_mask(U8 pos) {
  return sliding_occupancies<Direction::kNorth>(pos) | sliding_occupancies<Direction::kEast>(pos)
      | sliding_occupancies<Direction::kSouth>(pos) | sliding_occupancies<Direction::kWest>(pos);
}

BitBoard generate_bishop_moves(U8 pos, const BitBoard &occupied) {
  return sliding_attacks<Direction::kNorthWest>(pos, occupied) | sliding_attacks<Direction::kNorthEast>(pos, occupied)
      | sliding_attacks<Direction::kSouthWest>(pos, occupied) | sliding_attacks<Direction::kSouthEast>(pos, occupied);
}

BitBoard generate_rook_moves(U8 pos, const BitBoard &occupied) {
  return sliding_attacks<Direction::kNorth>(pos, occupied) | sliding_attacks<Direction::kEast>(pos, occupied)
      | sliding_attacks<Direction::kSouth>(pos, occupied) | sliding_attacks<Direction::kWest>(pos, occupied);
}

void initialize() {
  // initialize the mask + blocker combinations for bishops and rooks
  for (int square = 0; square < Square::kSquareCount; square++) {
    // bishops
    auto entry = kBishopMagics[square];
    auto blockers = attacks::create_blockers(entry.mask);

    std::array<BitBoard, kBishopBlockerCombinations> square_bishop_attacks{};

    for (const auto &occupied : blockers) {
      const U64 magic_index = ((entry.mask & occupied.as_u64()) * entry.magic) >> entry.shift;
      square_bishop_attacks[magic_index] = attacks::generate_bishop_moves(square, occupied);
    }

    bishop_attacks[square] = square_bishop_attacks;

    // rooks
    entry = kRookMagics[square];
    blockers = attacks::create_blockers(entry.mask);

    std::array<BitBoard, kRookBlockerCombinations> square_rook_attacks{};

    for (const auto &occupied : blockers) {
      const U64 magic_index = ((entry.mask & occupied.as_u64()) * entry.magic) >> entry.shift;
      square_rook_attacks[magic_index] = attacks::generate_rook_moves(square, occupied);
    }

    rook_attacks[square] = square_rook_attacks;
  }

  finder::generate_magics();
}

}