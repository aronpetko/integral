#ifndef INTEGRAL_MOVE_GEN_H_
#define INTEGRAL_MOVE_GEN_H_

#include "../utils/types.h"
#include "bitboard.h"
#include "board.h"

const int kMaxMoves = 256;

namespace move_gen {

// initializes piece attack lookups and magics
void initialize_attacks();

BitBoard &pawn_attacks(Square square, const BoardState &state, Color side);

BitBoard pawn_moves(Square square, const BoardState &state);

BitBoard &knight_moves(Square square);

BitBoard &bishop_moves(Square square, const BitBoard &occupied);

BitBoard &rook_moves(Square square, const BitBoard &occupied);

BitBoard king_moves(Square square, const BoardState &state);

BitBoard &king_attacks(Square square);

BitBoard castling_moves(Color which, const BoardState &state);

BitBoard get_attacked_squares(const BoardState &state, Color attacker);

BitBoard get_attackers_to(const BoardState &state, Square square, Color attacker);

BitBoard get_sliding_attackers_to(const BoardState &state, Square square, const BitBoard &occupied, Color attacker);

BitBoard get_attackers_to(const BoardState &state, Square square, const BitBoard &occupied, Color attacker);

// returns a bitboard with the set bits being sliding attacks between the two squares
BitBoard &ray_between(Square first, Square second);

// returns a bitboard with the set bits being the ray that the two squares lie on
BitBoard &ray_intersecting(Square first, Square second);

List<Move, kMaxMoves> generate_moves(MoveType move_type, Board &board);

List<Move, kMaxMoves> filter_moves(List<Move, kMaxMoves> &moves, MoveType type, Board &board);

}

#endif // INTEGRAL_MOVE_GEN_H_