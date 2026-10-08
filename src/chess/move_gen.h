#ifndef INTEGRAL_MOVE_GEN_H_
#define INTEGRAL_MOVE_GEN_H_

#include "../utils/types.h"
#include "bitboard.h"
#include "board.h"

namespace move_gen {

constexpr std::array<BitBoard, 64> GenerateKnightMasks() {
  std::array<BitBoard, 64> masks{};
  for (int square = 0; square < kSquareCount; square++) {
    const BitBoard src_mask = BitBoard::FromSquare(square);
    masks[square] |= (src_mask & ~kFileMasks[kFileH]) << 17;
    masks[square] |= (src_mask & ~(kFileMasks[kFileH] | kFileMasks[kFileG]))
                  << 10;
    masks[square] |=
        (src_mask & ~(kFileMasks[kFileH] | kFileMasks[kFileG])) >> 6;
    masks[square] |= (src_mask & ~kFileMasks[kFileH]) >> 15;
    masks[square] |= (src_mask & ~kFileMasks[kFileA]) << 15;
    masks[square] |= (src_mask & ~(kFileMasks[kFileA] | kFileMasks[kFileB]))
                  << 6;
    masks[square] |=
        (src_mask & ~(kFileMasks[kFileA] | kFileMasks[kFileB])) >> 10;
    masks[square] |= (src_mask & ~kFileMasks[kFileA]) >> 17;
  }
  return masks;
}

constexpr std::array<BitBoard, 64> GenerateKingMasks() {
  std::array<BitBoard, 64> masks{};
  for (int square = 0; square < kSquareCount; square++) {
    const BitBoard src_mask = BitBoard::FromSquare(square);

    masks[square] |= Shift<Direction::kNorth>(src_mask);
    masks[square] |= Shift<Direction::kSouth>(src_mask);
    masks[square] |= Shift<Direction::kEast>(src_mask);
    masks[square] |= Shift<Direction::kWest>(src_mask);
    masks[square] |= Shift<Direction::kNorthEast>(src_mask);
    masks[square] |= Shift<Direction::kNorthWest>(src_mask);
    masks[square] |= Shift<Direction::kSouthEast>(src_mask);
    masks[square] |= Shift<Direction::kSouthWest>(src_mask);
  }
  return masks;
}

constexpr std::array<std::array<BitBoard, 64>, 2> GeneratePawnAttackMasks() {
  std::array<std::array<BitBoard, 64>, 2> masks{};
  for (int square = 0; square < kSquareCount; square++) {
    const BitBoard src_mask = BitBoard::FromSquare(square);

    masks[Color::kWhite][square] |= Shift<Direction::kNorthEast>(src_mask);
    masks[Color::kWhite][square] |= Shift<Direction::kNorthWest>(src_mask);
    masks[Color::kBlack][square] |= Shift<Direction::kSouthEast>(src_mask);
    masks[Color::kBlack][square] |= Shift<Direction::kSouthWest>(src_mask);
  }
  return masks;
}

inline constexpr auto kKnightMasks = GenerateKnightMasks();
inline constexpr auto kKingMasks = GenerateKingMasks();
inline constexpr auto kPawnAttackMasks = GeneratePawnAttackMasks();

[[nodiscard]] bool IsSquareAttacked(Square square,
                                    Color attacker,
                                    const BoardState &state);

[[nodiscard]] BitBoard PawnAttacks(BitBoard pawns, Color side);

[[nodiscard]] BitBoard PawnAttacks(Square square, Color side);

[[nodiscard]] BitBoard PawnPushes(BitBoard pawns, Color side);

[[nodiscard]] BitBoard PawnPushMoves(Square square, const BoardState &state);

[[nodiscard]] BitBoard KnightMoves(Square square);

[[nodiscard]] BitBoard BishopMoves(Square square, const BitBoard &occupied);

[[nodiscard]] BitBoard RookMoves(Square square, const BitBoard &occupied);

[[nodiscard]] BitBoard QueenMoves(Square square, const BitBoard &occupied);

[[nodiscard]] BitBoard KingAttacks(Square square);

[[nodiscard]] BitBoard CastlingMoves(Color which, const BoardState &state);

[[nodiscard]] BitBoard CastlePath(Square from, Square to);

[[nodiscard]] BitBoard GetAttackersTo(const BoardState &state,
                                      Square square,
                                      Color attacker);

[[nodiscard]] BitBoard GetAttackersTo(const BoardState &state,
                                      Square square,
                                      const BitBoard &occupied,
                                      Color attacker);

[[nodiscard]] BitBoard GetSlidingAttackersTo(const BoardState &state,
                                             Square square,
                                             const BitBoard &occupied,
                                             Color attacker);

[[nodiscard]] BitBoard GetPieceAttacks(Square square,
                                       PieceType piece_type,
                                       Color side,
                                       BitBoard occupied);

// Returns a bitboard with the set bits being sliding attacks between the two
// squares
[[nodiscard]] BitBoard RayBetween(Square first, Square second);

// Returns a bitboard with the set bits being the ray that the two squares lie
// on
[[nodiscard]] BitBoard RayIntersecting(Square first, Square second);

template <MoveGenType move_type>
[[nodiscard]] MoveList GenerateMoves(const Board &board);

}  // namespace move_gen

#endif  // INTEGRAL_MOVE_GEN_H_