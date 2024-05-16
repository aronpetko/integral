#include "magic_finder.h"

#include <cassert>
#include <format>
#include <random>

#include "attacks.h"

namespace magics::finder {

// Test if a magic number causes index collisions in a possible attack table
bool TryMagic(const U64 &magic,
              int shift,
              int size,
              const std::vector<BitBoard> &blockers,
              const std::vector<BitBoard> &moves) {
  std::vector<BitBoard> move_table(1ULL << size);

  for (std::size_t i = 0; i < moves.size(); i++) {
    const U64 magic_index = (blockers[i].AsU64() * magic) >> shift;
    // Collision: an attack has already been set at this magic index
    if (move_table[magic_index] != 0ULL && move_table[magic_index] != moves[i])
      return false;

    move_table[magic_index] = moves[i];
  }

  return true;
}

MagicEntry FindMagic(PieceType piece_type, Square square) {
  assert(piece_type == PieceType::kRook || piece_type == PieceType::kBishop);

  const bool is_rook = piece_type == PieceType::kRook;

  const auto move_mask = is_rook ? attacks::GenerateRookMask(square)
                                 : attacks::GenerateBishopMask(square);
  const auto blockers = attacks::CreateBlockers(move_mask);

  // Generate all possible move mask + blocker attacks
  std::vector<BitBoard> piece_attacks(blockers.size());
  for (int i = 0; i < piece_attacks.size(); i++) {
    const BitBoard &occupied = blockers[i];
    piece_attacks[i] = is_rook ? attacks::GenerateRookMoves(square, occupied)
                               : attacks::GenerateBishopMoves(square, occupied);
  }

  std::mt19937_64 rng(123456789);
  const auto random_magic_number = [&rng]() {
    std::uniform_int_distribution<U64> dist;
    return dist(rng);
  };

  const int relevant_bits = move_mask.PopCount();

  for (std::size_t i = 0; i < 1000000; i++) {
    const auto candidate =
        random_magic_number() & random_magic_number() & random_magic_number();
    const auto shift = Square::kSquareCount - relevant_bits;

    if (TryMagic(candidate, shift, relevant_bits, blockers, piece_attacks)) {
      return {move_mask.AsU64(), candidate, shift};
    }
  }

  return {};
}

void GenerateMagics() {
  std::cout
      << "constexpr std::array<MagicEntry, Square::kSquareCount> kRookMagics = {"
      << std::endl;

  for (int square = 0; square < Square::kSquareCount; square++) {
    const auto magic_entry = FindMagic(PieceType::kRook, Square(square));
    std::cout << "  "
              << std::format("MagicEntry{{0x{:016x}ULL, 0x{:016x}ULL, {}}}",
                             magic_entry.mask,
                             magic_entry.magic,
                             magic_entry.shift);

    if (square < Square::kSquareCount - 1) {
      std::cout << ",";
    }

    std::cout << std::endl;
  }

  std::cout << "};" << std::endl << std::endl;

  std::cout
      << "constexpr std::array<MagicEntry, Square::kSquareCount> kBishopMagics = {"
      << std::endl;

  for (int square = 0; square < Square::kSquareCount; square++) {
    const auto magic_entry = FindMagic(PieceType::kBishop, Square(square));
    std::cout << "  "
              << std::format("MagicEntry{{0x{:016x}ULL, 0x{:016x}ULL, {}}}",
                             magic_entry.mask,
                             magic_entry.magic,
                             magic_entry.shift);

    if (square < Square::kSquareCount - 1) {
      std::cout << ",";
    }

    std::cout << std::endl;
  }

  std::cout << "};" << std::endl;
}

}  // namespace magics::finder