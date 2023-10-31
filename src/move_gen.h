#ifndef INTEGRAL_MOVE_GEN_H_
#define INTEGRAL_MOVE_GEN_H_

#include "bitboard.h"
#include "board.h"
#include "types.h"

BitBoard generate_pawn_moves(U8 pos, const BitBoard &occupied, BoardState* state);

BitBoard generate_knight_moves(U8 pos, const BitBoard &occupied, BoardState* state);

BitBoard generate_bishop_moves(U8 pos, const BitBoard &occupied, BoardState* state);

BitBoard generate_rook_moves(U8 pos, const BitBoard &occupied, BoardState* state);

BitBoard generate_king_moves(U8 pos, const BitBoard &occupied, BoardState* state);

#endif // INTEGRAL_SMOVE_GEN_H_