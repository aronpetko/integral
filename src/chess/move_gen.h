#ifndef INTEGRAL_MOVE_GEN_H_
#define INTEGRAL_MOVE_GEN_H_

#include "../utils/types.h"
#include "bitboard.h"
#include "board.h"

namespace move_gen {

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

[[nodiscard]] BitBoard KingMoves(Square square, const BoardState &state);

[[nodiscard]] BitBoard KingAttacks(Square square);

[[nodiscard]] BitBoard CastlingMoves(Color which, const BoardState &state);

[[nodiscard]] BitBoard GetAttackedSquares(const BoardState &state,
                                          Color attacker);

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