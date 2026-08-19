#ifndef INTEGRAL_MOVE_GEN_H_
#define INTEGRAL_MOVE_GEN_H_

#include "../utils/types.h"
#include "bitboard.h"
#include "board.h"

namespace move_gen {

bool IsSquareAttacked(Square square, Color attacker, const BoardState &state);

BitBoard PawnAttacks(BitBoard pawns, Color side);

BitBoard PawnAttacks(Square square, Color side);

BitBoard PawnPushes(BitBoard pawns, Color side);

BitBoard PawnPushMoves(Square square, const BoardState &state);

BitBoard KnightMoves(Square square);

BitBoard BishopMoves(Square square, const BitBoard &occupied);

BitBoard RookMoves(Square square, const BitBoard &occupied);

BitBoard QueenMoves(Square square, const BitBoard &occupied);

BitBoard KingMoves(Square square, const BoardState &state);

BitBoard KingAttacks(Square square);

BitBoard CastlingMoves(Color which, const BoardState &state);

BitBoard GetAttackersTo(const BoardState &state, Square square, Color attacker);

BitBoard GetAttackersTo(const BoardState &state,
                        Square square,
                        const BitBoard &occupied,
                        Color attacker);

BitBoard GetSlidingAttackersTo(const BoardState &state,
                               Square square,
                               const BitBoard &occupied,
                               Color attacker);

// Returns a bitboard with the set bits being sliding attacks between the two
// squares
BitBoard RayBetween(Square first, Square second);

// Returns a bitboard with the set bits being sliding attacks between the two
// squares, including the source squares
BitBoard RayIncluding(Square first, Square second);

// Returns a bitboard with the set bits being the ray that the two squares lie
// on
BitBoard RayIntersecting(Square first, Square second);

template <MoveGenType move_type>
MoveList GenerateMoves(const Board &board);

}  // namespace move_gen

#endif  // INTEGRAL_MOVE_GEN_H_