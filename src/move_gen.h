#ifndef INTEGRAL_MOVE_GEN_H_
#define INTEGRAL_MOVE_GEN_H_

#include "bitboard.h"
#include "board.h"
#include "types.h"

const int kMaxMoves = 256;

namespace move_gen {

// initializes piece attack lookups and magics
void initialize_attacks();

BitBoard pawn_attacks(U8 pos, const BoardState &state, Color which = Color::kNoColor, bool en_passant = true);

BitBoard pawn_moves(U8 pos, const BoardState &state);

BitBoard knight_moves(U8 pos);

BitBoard bishop_moves(U8 pos, const BitBoard &occupied);

BitBoard rook_moves(U8 pos, const BitBoard &occupied);

BitBoard king_moves(U8 pos, const BoardState &state);

BitBoard king_attacks(U8 pos);

BitBoard castling_moves(Color which, const BoardState &state);

BitBoard get_attacked_squares(const BoardState &state, Color attacker, bool include_king_attacks = true);

bool king_in_check(Color color, const BoardState &state);

List<Move, kMaxMoves> moves(MoveType move_type, Board &board);

List<Move, kMaxMoves> filter_moves(List<Move, kMaxMoves> &moves, MoveType type, Board &board);

}

#endif // INTEGRAL_MOVE_GEN_H_