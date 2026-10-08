#include "attacks.h"

#include "precomputed.h"

#ifdef USE_PEXT
#include <immintrin.h>
#endif

namespace magics::attacks {

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