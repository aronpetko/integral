#ifndef INTEGRAL_MOVE_GEN_H_
#define INTEGRAL_MOVE_GEN_H_

#include "bitboard.h"
#include "board.h"
#include "types.h"

using MoveList = std::vector<Move>;

void initialize_ray_attacks();

BitBoard generate_pawn_attacks(U8 pos, BoardState &state);

BitBoard generate_pawn_moves(U8 pos, BoardState &state);

BitBoard generate_knight_moves(U8 pos, BoardState &state);

BitBoard generate_bishop_moves(U8 pos, BoardState &state);

BitBoard generate_rook_moves(U8 pos, BoardState &state);

BitBoard generate_king_moves(U8 pos, BoardState &state, bool include_castling = true);

BitBoard generate_king_attacks(U8 pos, BoardState &state);

BitBoard generate_castling_moves(BoardState &state, Color which);

BitBoard get_attacked_squares(BoardState &state, Color attacker, bool include_king_attacks = true);

bool is_square_attacked(U8 pos, Color attacker, BoardState &state);

bool king_in_check(Color color, BoardState &state);

MoveList generate_moves(Board &board);

MoveList generate_legal_moves(Board &board);

MoveList generate_capture_moves(Board &board);

#endif // INTEGRAL_MOVE_GEN_H_