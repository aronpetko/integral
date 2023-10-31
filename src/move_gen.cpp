#include "move_gen.h"
#include "board.h"

// todo: make this function generate attacks regardless if there is a piece there and then handle if there is a piece in generate_pawn_moves. you must do this, aron, because rn move generation generates until a capture, which is not good if we're checking where the king can move
BitBoard generate_pawn_attacks(U8 pos, BoardState *state) {
  BitBoard moves, bb_pos(BitBoard(1ULL << pos));

  if (get_piece_color(pos, state->pieces) == Color::kWhite) {
    // immediate diagonal captures
    BitBoard up_left = shift<Direction::kNorthWest>(bb_pos);
    if (get_piece_color(up_left, state->pieces) == Color::kBlack)
      moves.set_bit(get_lsb_pos(up_left));

    BitBoard up_right = shift<Direction::kNorthEast>(bb_pos);
    if (get_piece_color(up_right, state->pieces) == Color::kBlack)
      moves.set_bit(get_lsb_pos(up_right));
  } else {
    // immediate diagonal captures
    BitBoard down_left = shift<Direction::kSouthWest>(bb_pos);
    if (get_piece_color(down_left, state->pieces) == Color::kWhite)
      moves.set_bit(get_lsb_pos(down_left));

    BitBoard down_right = shift<Direction::kSouthEast>(bb_pos);
    if (get_piece_color(down_right, state->pieces) == Color::kWhite)
      moves.set_bit(get_lsb_pos(down_right));
  }

  return moves;
}

// todo: handle promotion
BitBoard generate_pawn_moves(U8 pos, BoardState *state) {
  BitBoard moves, bb_pos(BitBoard(1ULL << pos)), occupied = state->pieces[kAllPieces];

  if (get_piece_color(pos, state->pieces) == Color::kWhite) {
    BitBoard up = shift<Direction::kNorth>(bb_pos);
    if (get_piece_color(up, state->pieces) == Color::kNone && !occupied.is_set(get_lsb_pos(up)))
      moves.set_bit(get_lsb_pos(up));

    // pawns can move up two squares on their first move
    if ((bb_pos & RankMasks::kRank2).as_int()) {
      BitBoard up_up = shift<Direction::kNorth>(up);
      if (get_piece_color(up_up, state->pieces) == Color::kNone && !occupied.is_set(get_lsb_pos(up_up)))
        moves.set_bit(get_lsb_pos(up_up));
    }
  } else {
    BitBoard down = shift<Direction::kSouth>(bb_pos);
    if (get_piece_color(down, state->pieces) == Color::kNone && !occupied.is_set(get_lsb_pos(down)))
      moves.set_bit(get_lsb_pos(down));

    // pawns can move down two squares on their first move
    if ((bb_pos & RankMasks::kRank7).as_int()) {
      BitBoard down_down = shift<Direction::kSouth>(down);
      if (get_piece_color(down_down, state->pieces) == Color::kNone && !occupied.is_set(get_lsb_pos(down_down)))
        moves.set_bit(get_lsb_pos(down_down));
    }
  }

  return moves | generate_pawn_attacks(pos, state);
}

BitBoard generate_knight_moves(U8 pos, BoardState *state) {
  BitBoard moves, occupied = state->pieces[kAllPieces];

  const int kKnightOffsets[] = {6, 10, 15, 17, -6, -10, -15, -17};
  for (const int &offset : kKnightOffsets) {
    U8 new_pos = pos + offset;

    // if the move collides with another piece and that piece is not a king (for check validation)
    if (occupied.is_set(new_pos) && !(state->pieces[kWhiteKing].is_set(new_pos) || state->pieces[kBlackKing].is_set(new_pos))) {
      // if it's an opponent's piece, we can capture it but not move past it
      if (!state->pieces[state->turn_to_move == Color::kWhite ? kWhitePieces : kBlackPieces].is_set(new_pos))
        moves.set_bit(new_pos);
      continue;
    }

    moves.set_bit(new_pos);
  }

  return moves;
}

BitBoard generate_bishop_moves(U8 pos, BoardState *state) {
  BitBoard moves, occupied = state->pieces[kAllPieces];

  auto generate_moves_in_direction = [&](auto &shift_fn) {
    U8 current = pos;
    while (true) {
      BitBoard shifted = shift_fn(BitBoard(1ULL << current));
      // check if move is outside board
      if (shifted.as_int() == 0)
        break;

      U8 new_pos = get_lsb_pos(shifted.as_int());

      // if the move collides with another piece and that piece is not a king (for check validation)
      if (occupied.is_set(new_pos) && !(state->pieces[kWhiteKing].is_set(new_pos) || state->pieces[kBlackKing].is_set(new_pos))) {
        // if it's an opponent's piece, we can capture it but not move past it
        if (!state->pieces[state->turn_to_move == Color::kWhite ? kWhitePieces : kBlackPieces].is_set(new_pos))
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

// todo: handle castling rights
BitBoard generate_rook_moves(U8 pos, BoardState *state) {
  BitBoard moves, occupied = state->pieces[kAllPieces];

  auto generate_moves_in_direction = [&](auto &shift_fn) {
    U8 current = pos;
    while (true) {
      BitBoard shifted = shift_fn(BitBoard(1ULL << current));
      // check if move is outside board
      if (shifted.as_int() == 0)
        break;

      U8 new_pos = get_lsb_pos(shifted.as_int());

      // if the move collides with another piece and that piece is not a king (for check validation)
      if (occupied.is_set(new_pos) && !(state->pieces[kWhiteKing].is_set(new_pos) || state->pieces[kBlackKing].is_set(new_pos))) {
        // if it's an opponent's piece, we can capture it but not move past it
        if (!state->pieces[state->turn_to_move == Color::kWhite ? kWhitePieces : kBlackPieces].is_set(new_pos))
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

// todo: handle castling, in-check moves
BitBoard generate_king_moves(U8 pos, BoardState *state) {
  BitBoard moves, occupied = state->pieces[kAllPieces], attacked = get_attacked_squares(state, false);

  auto generate_moves_in_direction = [&](auto &shift_fn) {
    BitBoard shifted = shift_fn(BitBoard(1ULL << pos));
    U8 new_pos = get_lsb_pos(shifted);

    // king would move into check, which is illegal
    if (attacked.is_set(new_pos))
      return;

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

  return moves;
}

BitBoard generate_king_attacks(U8 pos) {
  BitBoard attacks;

  auto generate_attack_in_direction = [&](auto &shift_fn) {
    BitBoard shifted = shift_fn(BitBoard(1ULL << pos));
    U8 new_pos = get_lsb_pos(shifted);
    attacks.set_bit(new_pos);
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

BitBoard get_attacked_squares(BoardState *state, bool include_king_attacks) {
  BitBoard attacked;

  // offset for white and black pieces
  int offset = (state->turn_to_move == Color::kBlack) ? 0 : 7;

  // pawns
  BitBoard pawns = state->pieces[offset + 0];
  while (pawns.as_int()) {
    U8 from_square = pop_lsb(pawns);
    attacked |= generate_pawn_attacks(from_square, state);
  }

  // knights
  BitBoard knights = state->pieces[offset + 1];
  while (knights.as_int()) {
    U8 from_square = pop_lsb(knights);
    attacked |= generate_knight_moves(from_square, state);
  }

  // bishops
  BitBoard bishops = state->pieces[offset + 2];
  while (bishops.as_int()) {
    U8 from_square = pop_lsb(bishops);
    attacked |= generate_bishop_moves(from_square, state);
  }

  // rooks
  BitBoard rooks = state->pieces[offset + 3];
  while (rooks.as_int()) {
    U8 from_square = pop_lsb(rooks);
    attacked |= generate_rook_moves(from_square, state);
  }

  // queens
  BitBoard queens = state->pieces[offset + 4];
  while (queens.as_int()) {
    U8 from_square = pop_lsb(queens);
    attacked |= generate_rook_moves(from_square, state) | generate_bishop_moves(from_square, state);
  }

  if (include_king_attacks) {
    // king
    BitBoard king = state->pieces[offset + 5];
    U8 king_square = get_lsb_pos(king); // king is only in one position
    attacked |= generate_king_attacks(king_square);
  }

  print_bb(attacked);

  return attacked;
}

bool king_in_check(BoardState *state) {
  BitBoard king_bb = state->turn_to_move == Color::kWhite ? state->pieces[kWhiteKing] : state->pieces[kBlackKing];
  return get_attacked_squares(state).is_set(get_lsb_pos(king_bb));
}