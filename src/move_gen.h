#ifndef INTEGRAL_MOVE_GEN_H_
#define INTEGRAL_MOVE_GEN_H_

#include "bitboard.h"
#include "board.h"
#include "types.h"

BitBoard generate_pawn_attacks(U8 pos, BoardState *state);

BitBoard generate_pawn_moves(U8 pos, BoardState *state);

BitBoard generate_knight_moves(U8 pos, BoardState *state);

BitBoard generate_bishop_moves(U8 pos, BoardState *state);

BitBoard generate_rook_moves(U8 pos, BoardState *state);

BitBoard generate_king_moves(U8 pos, BoardState *state);

BitBoard generate_king_attacks(U8 pos);

BitBoard get_attacked_squares(BoardState *state, bool include_king_attacks = true);

bool king_in_check(BoardState *state);

#endif // INTEGRAL_SMOVE_GEN_H_