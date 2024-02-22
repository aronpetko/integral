#include "move_gen.h"
#include "board.h"

BitBoard generate_pawn_attacks(U8 pos, const std::unique_ptr<BoardState> &state) {
  BitBoard moves, bb_pos(BitBoard(1ULL << pos));

  if (get_piece_color(pos, state->pieces) == Color::kWhite) {
    // immediate diagonal captures
    BitBoard up_left = shift<Direction::kNorthWest>(bb_pos);
    if (up_left.as_int())
      moves |= up_left;

    BitBoard up_right = shift<Direction::kNorthEast>(bb_pos);
    if (up_right.as_int())
      moves |= up_right;
  } else {
    // immediate diagonal captures
    BitBoard down_left = shift<Direction::kSouthWest>(bb_pos);
    if (down_left.as_int())
      moves |= down_left;

    BitBoard down_right = shift<Direction::kSouthEast>(bb_pos);
    if (down_right.as_int())
      moves |= down_right;
  }

  return moves;
}

// todo: handle promotion
BitBoard generate_pawn_moves(U8 pos, const std::unique_ptr<BoardState> &state) {
  BitBoard moves, bb_pos(BitBoard(1ULL << pos)), occupied = state->pieces[kAllPieces], attacks = generate_pawn_attacks(pos, state);

  if (get_piece_color(pos, state->pieces) == Color::kWhite) {
    BitBoard up = shift<Direction::kNorth>(bb_pos);
    if (get_piece_color(up, state->pieces) == Color::kNone && !occupied.is_set(get_lsb_pos(up)))
      moves |= up;

    // pawns can move up two squares on their first move
    if ((bb_pos & RankMasks::kRank2).as_int()) {
      BitBoard up_up = shift<Direction::kNorth>(up);
      if (get_piece_color(up_up, state->pieces) == Color::kNone && !occupied.is_set(get_lsb_pos(up_up)))
        moves |= up_up;
    }

    // check if attacks can actually capture a piece
    U8 attack_pos = pop_lsb(attacks);
    //if (state->pieces[kBlackPieces].is_set(attack_pos))
    moves.set_bit(attack_pos);
    attack_pos = pop_lsb(attacks);
    //if (state->pieces[kBlackPieces].is_set(attack_pos))
    moves.set_bit(attack_pos);
  } else {
    BitBoard down = shift<Direction::kSouth>(bb_pos);
    if (get_piece_color(down, state->pieces) == Color::kNone && !occupied.is_set(get_lsb_pos(down)))
      moves |= down;

    // pawns can move down two squares on their first move
    if ((bb_pos & RankMasks::kRank7).as_int()) {
      BitBoard down_down = shift<Direction::kSouth>(down);
      if (get_piece_color(down_down, state->pieces) == Color::kNone && !occupied.is_set(get_lsb_pos(down_down)))
        moves |= down_down;
    }

    // check if attacks can actually capture a piece
    U8 attack_pos = pop_lsb(attacks);
    //if (state->pieces[kWhitePieces].is_set(attack_pos))
    moves.set_bit(attack_pos);
    attack_pos = pop_lsb(attacks);
    //if (state->pieces[kWhitePieces].is_set(attack_pos))
    moves.set_bit(attack_pos);
  }

  return moves;
}

BitBoard generate_knight_moves(U8 pos, const std::unique_ptr<BoardState> &state) {
  BitBoard moves, occupied = state->pieces[kAllPieces];

  const int original_row = pos / 8;
  const int original_col = pos % 8;

  const int kKnightOffsets[] = {6, 10, 15, 17, -6, -10, -15, -17};
  for (const int &offset : kKnightOffsets) {
    // check if the potential move is within  bounds
    const int new_row = (pos + offset) / 8;
    const int new_col = (pos + offset) % 8;
    if (abs(new_row - original_row) > 2 || abs(new_col - original_col) > 2)
      continue;

    U8 new_pos = pos + offset;
    if (new_pos >= 64)
      continue;

    // if the move collides with another piece
    if (occupied.is_set(new_pos)) {
      // if it's an opponent's piece, we can capture it but not move past it
      // if (!state->pieces[state->turn_to_move == Color::kWhite ? kWhitePieces : kBlackPieces].is_set(new_pos))
      moves.set_bit(new_pos);
      continue;
    }

    moves.set_bit(new_pos);
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
      if (shifted.as_int() == 0)
        break;

      U8 new_pos = get_lsb_pos(shifted.as_int());

      // if the move collides with another piece
      if (occupied.is_set(new_pos)) {
        // if it's an opponent's piece, we can capture it but not move past it
        //if (!state->pieces[state->turn_to_move == Color::kWhite ? kWhitePieces : kBlackPieces].is_set(new_pos))
        moves.set_bit(new_pos);
        break;
      }

      moves.set_bit(new_pos);
      current = new_pos;
    }
  };

  // generate moves for each diagonal direction
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
      if (shifted.as_int() == 0)
        break;

      U8 new_pos = get_lsb_pos(shifted.as_int());

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
    if (!shifted.as_int())
      return;

    U8 new_pos = get_lsb_pos(shifted);

    // if the move collides with another piece
    if (occupied.is_set(new_pos)) {
      // if it's an opponent's piece, we can capture it but not move past it
      if (!state->pieces[state->turn_to_move == Color::kWhite ? kWhitePieces : kBlackPieces].is_set(new_pos))
        moves.set_bit(new_pos);
      return;
    }

    moves.set_bit(new_pos);
  };

  // generate moves for each  direction
  generate_moves_in_direction(shift<Direction::kNorth>);
  generate_moves_in_direction(shift<Direction::kSouth>);
  generate_moves_in_direction(shift<Direction::kEast>);
  generate_moves_in_direction(shift<Direction::kWest>);
  generate_moves_in_direction(shift<Direction::kNorthEast>);
  generate_moves_in_direction(shift<Direction::kNorthWest>);
  generate_moves_in_direction(shift<Direction::kSouthEast>);
  generate_moves_in_direction(shift<Direction::kSouthWest>);

  if (!king_in_check(state->turn_to_move, state))
    moves |= generate_castling_moves(state);

  return moves;
}

BitBoard generate_king_attacks(U8 pos) {
  BitBoard attacks;

  auto generate_attack_in_direction = [&attacks, &pos](auto &shift_fn) {
    BitBoard shifted = shift_fn(BitBoard(1ULL << pos));
    if (!shifted.as_int())
      return;

    attacks.set_bit(get_lsb_pos(shifted));
  };

  // Generate attacks for each direction
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

  if (state->turn_to_move == Color::kWhite) {
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
  int offset = (state->turn_to_move == Color::kBlack) ? (self ? 7 : 0) : (self ? 0 : 7);

  BitBoard pawns = state->pieces[offset + 0];
  while (pawns.as_int()) {
    U8 from_square = pop_lsb(pawns);
    attacked |= generate_pawn_attacks(from_square, state);
  }

  BitBoard knights = state->pieces[offset + 1];
  while (knights.as_int()) {
    U8 from_square = pop_lsb(knights);
    attacked |= generate_knight_moves(from_square, state);
  }

  BitBoard bishops = state->pieces[offset + 2];
  while (bishops.as_int()) {
    U8 from_square = pop_lsb(bishops);
    attacked |= generate_bishop_moves(from_square, state);
  }

  BitBoard rooks = state->pieces[offset + 3];
  while (rooks.as_int()) {
    U8 from_square = pop_lsb(rooks);
    attacked |= generate_rook_moves(from_square, state);
  }

  BitBoard queens = state->pieces[offset + 4];
  while (queens.as_int()) {
    U8 from_square = pop_lsb(queens);
    attacked |= generate_rook_moves(from_square, state) | generate_bishop_moves(from_square, state);
  }

  if (include_king_attacks) {
    BitBoard king = state->pieces[offset + 5];
    if (king.as_int()) {
      U8 king_square = get_lsb_pos(king); // king is only in one position
      attacked |= generate_king_attacks(king_square);
    }
  }

  return attacked;
}

bool king_in_check(Color color, const std::unique_ptr<BoardState> &state) {
  BitBoard king_bb = color == Color::kWhite ? state->pieces[kWhiteKing] : state->pieces[kBlackKing];
  return get_attacked_squares(state, color != state->turn_to_move, true).is_set(get_lsb_pos(king_bb));
}