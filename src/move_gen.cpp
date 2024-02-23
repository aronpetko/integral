#include "move_gen.h"
#include "board.h"

BitBoard generate_pawn_attacks(U8 pos, const std::unique_ptr<BoardState> &state) {
  BitBoard moves, bb_pos(1ULL << pos);

  if (get_piece_color(pos, state->pieces) == Color::kWhite) {
    BitBoard up_left = shift<Direction::kNorthWest>(bb_pos);
    BitBoard up_right = shift<Direction::kNorthEast>(bb_pos);
    moves |= up_left | up_right;
  } else {
    BitBoard down_left = shift<Direction::kSouthWest>(bb_pos);
    BitBoard down_right = shift<Direction::kSouthEast>(bb_pos);
    moves |= down_left | down_right;
  }

  return moves;
}

BitBoard generate_pawn_moves(U8 pos, const std::unique_ptr<BoardState> &state) {
  BitBoard moves, bb_pos(1ULL << pos), occupied = state->pieces[kAllPieces], attacks = generate_pawn_attacks(pos, state);

  if (get_piece_color(pos, state->pieces) == Color::kWhite) {
    BitBoard up = shift<Direction::kNorth>(bb_pos);
    if (!occupied.is_set(up.get_lsb_pos()))
      moves |= up;

    // pawns can two squares on their first move
    if (up.as_u64() && (bb_pos & RankMasks::kRank2).as_u64()) {
      BitBoard up_up = shift<Direction::kNorth>(up);
      if (!occupied.is_set(up_up.get_lsb_pos()))
        moves |= up_up;
    }
  } else {
    BitBoard down = shift<Direction::kSouth>(bb_pos);
    if (!occupied.is_set(down.get_lsb_pos()))
      moves |= down;

    // pawns can two squares on their first move
    if (down.as_u64() && (bb_pos & RankMasks::kRank7).as_u64()) {
      BitBoard down_down = shift<Direction::kSouth>(down);
      if (!occupied.is_set(down_down.get_lsb_pos()))
        moves |= down_down;
    }
  }

  // allow attacks that can actually capture an opposing piece
  BitBoard &opposing_pieces = state->pieces[state->turn == Color::kWhite ? kBlackPieces : kWhitePieces];
  attacks &= opposing_pieces;

  // and en passant too
  if (state->en_passant.has_value()) {
    std::cout << state->en_passant.value() << std::endl;
    attacks.set_bit(state->en_passant.value());
  }

  return moves | attacks;
}

BitBoard generate_knight_moves(U8 pos, const std::unique_ptr<BoardState> &state) {
  BitBoard moves, occupied = state->pieces[kAllPieces];

  // Knight's move patterns in terms of rank and file offsets
  const int kKnightMovePatterns[][2] = {
      {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
      {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
  };

  int original_rank = pos / 8;
  int original_file = pos % 8;

  for (const auto &pattern : kKnightMovePatterns) {
    int new_rank = original_rank + pattern[0];
    int new_file = original_file + pattern[1];

    // check if the new position is within the bounds of the board
    if (new_rank >= 0 && new_rank < 8 && new_file >= 0 && new_file < 8) {
      U8 new_pos = new_rank * 8 + new_file;  // Convert board coordinates back to position

      // check if the move is to an occupied square and add it to the moves bitboard
      if (!occupied.is_set(new_pos))
        moves.set_bit(new_pos);
    }
  }

  return moves;
}

BitBoard generate_bishop_moves(U8 pos, const std::unique_ptr<BoardState> &state) {
  BitBoard moves, occupied = state->pieces[kAllPieces];

  auto generate_moves_in_direction = [&](auto &shift_fn) {
    U8 current = pos;
    while (true) {
      BitBoard shifted = shift_fn(BitBoard(1ULL << current));
      // check if move is outside board
      if (!shifted.as_u64())
        break;

      U8 new_pos = shifted.get_lsb_pos();

      // if the move collides with another piece
      if (occupied.is_set(new_pos)) {
        moves.set_bit(new_pos);
        break;
      }

      moves.set_bit(new_pos);
      current = new_pos;
    }
  };

  generate_moves_in_direction(shift<Direction::kNorthEast>);
  generate_moves_in_direction(shift<Direction::kNorthWest>);
  generate_moves_in_direction(shift<Direction::kSouthEast>);
  generate_moves_in_direction(shift<Direction::kSouthWest>);

  return moves;
}

BitBoard generate_rook_moves(U8 pos, const std::unique_ptr<BoardState> &state) {
  BitBoard moves, occupied = state->pieces[kAllPieces];

  auto generate_moves_in_direction = [&](auto &shift_fn) {
    U8 current = pos;
    while (true) {
      BitBoard shifted = shift_fn(BitBoard(1ULL << current));
      // check if move is outside board
      if (!shifted.as_u64())
        break;

      U8 new_pos = shifted.get_lsb_pos();

      // if the move collides with another piece
      if (occupied.is_set(new_pos)) {
        moves.set_bit(new_pos);
        break;
      }

      moves.set_bit(new_pos);
      current = new_pos;
    }
  };

  // generate moves for each diagonal direction
  generate_moves_in_direction(shift<Direction::kNorth>);
  generate_moves_in_direction(shift<Direction::kSouth>);
  generate_moves_in_direction(shift<Direction::kEast>);
  generate_moves_in_direction(shift<Direction::kWest>);

  return moves;
}

BitBoard generate_king_moves(U8 pos, const std::unique_ptr<BoardState> &state) {
  BitBoard moves, occupied = state->pieces[kAllPieces];

  auto generate_moves_in_direction = [&](auto &shift_fn) {
    BitBoard shifted = shift_fn(BitBoard(1ULL << pos));
    // check if move is outside board
    if (!shifted.as_u64())
      return;

    U8 new_pos = shifted.get_lsb_pos();

    // if the move collides with another piece
    if (occupied.is_set(new_pos)) {
      moves.set_bit(new_pos);
      return;
    }

    moves.set_bit(new_pos);
  };

  generate_moves_in_direction(shift<Direction::kNorth>);
  generate_moves_in_direction(shift<Direction::kSouth>);
  generate_moves_in_direction(shift<Direction::kEast>);
  generate_moves_in_direction(shift<Direction::kWest>);
  generate_moves_in_direction(shift<Direction::kNorthEast>);
  generate_moves_in_direction(shift<Direction::kNorthWest>);
  generate_moves_in_direction(shift<Direction::kSouthEast>);
  generate_moves_in_direction(shift<Direction::kSouthWest>);

  if (!king_in_check(state->turn, state))
    moves |= generate_castling_moves(state);

  return moves;
}

BitBoard generate_king_attacks(U8 pos) {
  BitBoard attacks;

  auto generate_attack_in_direction = [&attacks, &pos](auto &shift_fn) {
    BitBoard shifted = shift_fn(BitBoard(1ULL << pos));
    // check if move is outside board
    if (!shifted.as_u64())
      return;

    attacks.set_bit(shifted.get_lsb_pos());
  };

  generate_attack_in_direction(shift<Direction::kNorth>);
  generate_attack_in_direction(shift<Direction::kSouth>);
  generate_attack_in_direction(shift<Direction::kEast>);
  generate_attack_in_direction(shift<Direction::kWest>);
  generate_attack_in_direction(shift<Direction::kNorthEast>);
  generate_attack_in_direction(shift<Direction::kNorthWest>);
  generate_attack_in_direction(shift<Direction::kSouthEast>);
  generate_attack_in_direction(shift<Direction::kSouthWest>);

  return attacks;
}

BitBoard generate_castling_moves(const std::unique_ptr<BoardState> &state) {
  BitBoard moves, attacked = get_attacked_squares(state, false, true), occupied = state->pieces[kAllPieces];

  if (state->turn == Color::kWhite) {
    if (state->castle_state & CastleRights::kWhiteKingside) {
      if (!attacked.is_set(Square::kF1) && !occupied.is_set(Square::kF1) &&
          !attacked.is_set(Square::kG1) && !occupied.is_set(Square::kG1))
        moves.set_bit(Square::kG1);
    }

    if (state->castle_state & CastleRights::kWhiteQueenside) {
      if (!attacked.is_set(Square::kD1) && !occupied.is_set(Square::kD1) &&
          !attacked.is_set(Square::kC1) && !occupied.is_set(Square::kC1))
        moves.set_bit(Square::kC1);
    }
  } else {
    if (state->castle_state & CastleRights::kBlackKingside) {
      if (!attacked.is_set(Square::kF8) && !occupied.is_set(Square::kF8) &&
          !attacked.is_set(Square::kG8) && !occupied.is_set(Square::kG8))
        moves.set_bit(Square::kG8);
    }

    if (state->castle_state & CastleRights::kBlackQueenside) {
      if (!attacked.is_set(Square::kD8) && !occupied.is_set(Square::kD8) &&
          !attacked.is_set(Square::kC8) && !occupied.is_set(Square::kC8))
        moves.set_bit(Square::kC8);
    }
  }

  return moves;
}

BitBoard get_attacked_squares(const std::unique_ptr<BoardState> &state, bool self, bool include_king_attacks) {
  BitBoard attacked;

  // offset for white and black pieces
  int offset = (state->turn == Color::kBlack) ? (self ? 7 : 0) : (self ? 0 : 7);

  BitBoard pawns = state->pieces[offset + 0];
  while (pawns.as_u64()) {
    U8 from_square = pawns.pop_lsb();
    attacked |= generate_pawn_attacks(from_square, state);
  }

  BitBoard knights = state->pieces[offset + 1];
  while (knights.as_u64()) {
    U8 from_square = knights.pop_lsb();
    attacked |= generate_knight_moves(from_square, state);
  }

  BitBoard bishops = state->pieces[offset + 2];
  while (bishops.as_u64()) {
    U8 from_square = bishops.pop_lsb();
    attacked |= generate_bishop_moves(from_square, state);
  }

  BitBoard rooks = state->pieces[offset + 3];
  while (rooks.as_u64()) {
    U8 from_square = rooks.pop_lsb();
    attacked |= generate_rook_moves(from_square, state);
  }

  BitBoard queens = state->pieces[offset + 4];
  while (queens.as_u64()) {
    U8 from_square = queens.pop_lsb();
    attacked |= generate_rook_moves(from_square, state) | generate_bishop_moves(from_square, state);
  }

  if (include_king_attacks) {
    BitBoard king = state->pieces[offset + 5];
    if (king.as_u64()) {
      U8 king_square = king.pop_lsb(); // king is only in one position
      attacked |= generate_king_attacks(king_square);
    }
  }

  return attacked;
}

bool king_in_check(Color color, const std::unique_ptr<BoardState> &state) {
  BitBoard king_bb = color == Color::kWhite ? state->pieces[kWhiteKing] : state->pieces[kBlackKing];
  return get_attacked_squares(state, color != state->turn, true).is_set(king_bb.get_lsb_pos());
}