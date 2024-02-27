#ifndef INTEGRAL_MOVE_GEN_H_
#define INTEGRAL_MOVE_GEN_H_

#include "bitboard.h"
#include "board.h"
#include "types.h"

BitBoard generate_pawn_attacks(U8 pos, const std::unique_ptr<BoardState> &state);

BitBoard generate_pawn_moves(U8 pos, const std::unique_ptr<BoardState> &state);

BitBoard generate_knight_moves(U8 pos, const std::unique_ptr<BoardState> &state);

BitBoard generate_bishop_moves(U8 pos, const std::unique_ptr<BoardState> &state);

BitBoard generate_rook_moves(U8 pos, const std::unique_ptr<BoardState> &state);

BitBoard generate_king_moves(U8 pos, const std::unique_ptr<BoardState> &state);

BitBoard generate_king_attacks(U8 pos, const std::unique_ptr<BoardState> &state);

BitBoard generate_castling_moves(const std::unique_ptr<BoardState> &state, Color which);

BitBoard get_attacked_squares(const std::unique_ptr<BoardState> &state, Color attacker, bool include_king_attacks = true);

bool is_square_attacked(U8 pos, Color attacker, const std::unique_ptr<BoardState> &state);

bool king_in_check(Color color, const std::unique_ptr<BoardState> &state);

MoveList generate_moves(const std::unique_ptr<BoardState> &state);

MoveList generate_legal_moves(Board &board);

#endif // INTEGRAL_MOVE_GEN_H_