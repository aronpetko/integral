#include "magic_finder.h"
#include "attacks.h"

#include <cassert>
#include <random>
#include <format>

namespace magics::finder {

bool try_magic(const U64 &magic, int shift, int size, const std::vector<BitBoard> &blockers, const std::vector<BitBoard> &moves) {
  std::vector<BitBoard> move_table(1ULL << size);

  for (std::size_t i = 0; i < moves.size(); i++) {
    const U64 magic_index = (blockers[i].as_u64() * magic) >> shift;
    if (move_table[magic_index] != 0ULL && move_table[magic_index] != moves[i]) {
      return false;
    }

    move_table[magic_index] = moves[i];
  }

  return true;
}

MagicEntry find_magic(PieceType piece_type, U8 square) {
  assert(piece_type == PieceType::kRook || piece_type == PieceType::kBishop);

  const bool is_rook = piece_type == PieceType::kRook;

  const auto move_mask = is_rook ? attacks::generate_rook_mask(square) : attacks::generate_bishop_mask(square);
  const auto blockers = attacks::create_blockers(move_mask);

  std::vector<BitBoard> piece_attacks(blockers.size());

  for (int i = 0; i < piece_attacks.size(); i++) {
    const BitBoard &occupied = blockers[i];
    piece_attacks[i] = is_rook ? attacks::generate_rook_moves(square, occupied) :
        attacks::generate_bishop_moves(square, occupied);
  }

  std::mt19937_64 rng(123456789);
  const auto random_magic_number = [&rng]() {
    std::uniform_int_distribution<U64> dist;
    return dist(rng);
  };

  const int relevant_bits = move_mask.pop_count();

  for (std::size_t i = 0; i < 1000000; i++) {
    const auto candidate = random_magic_number() & random_magic_number() & random_magic_number();
    const auto shift = Square::kSquareCount - relevant_bits;

    if (try_magic(candidate, shift, relevant_bits, blockers, piece_attacks)) {
      return {move_mask.as_u64(), candidate, shift};
    }
  }

  return {};
}

void generate_magics() {
  std::cout << "const std::array<MagicEntry, Square::kSquareCount> kRookMagics = {{" << std::endl;

  for (U8 square = 0; square < Square::kSquareCount; square++) {
    const auto magic_entry = find_magic(PieceType::kRook, square);
    std::cout << "  " << std::format("{{0x{:016x}ULL, 0x{:016x}ULL, {}}}", magic_entry.mask, magic_entry.magic, magic_entry.shift);

    if (square < Square::kSquareCount - 1) {
      std::cout << ",";
    }

    std::cout << std::endl;
  }

  std::cout << "}};" << std::endl << std::endl;

  std::cout << "const std::array<MagicEntry, Square::kSquareCount> kBishopMagics = {{" << std::endl;

  for (U8 square = 0; square < Square::kSquareCount; square++) {
    const auto magic_entry = find_magic(PieceType::kBishop, square);
    std::cout << "  " << std::format("{{0x{:016x}ULL, 0x{:016x}ULL, {}}}", magic_entry.mask, magic_entry.magic, magic_entry.shift);

    if (square < Square::kSquareCount - 1) {
      std::cout << ",";
    }

    std::cout << std::endl;
  }

  std::cout << "}};" << std::endl;
}

}