#include "move_gen.h"
#include "board.h"

BitBoard generate_pawn_moves(U8 pos, const BitBoard &occupied, BoardState* state) {
  BitBoard moves, bb_pos(BitBoard(1ULL << pos));

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
    
    // immediate diagonal captures
    BitBoard up_left = shift<Direction::kNorthWest>(bb_pos);
    if (get_piece_color(up_left, state->pieces) == Color::kBlack)
      moves.set_bit(get_lsb_pos(up_left));
    
    BitBoard up_right = shift<Direction::kNorthEast>(bb_pos);
    if (get_piece_color(up_right, state->pieces) == Color::kBlack)
      moves.set_bit(get_lsb_pos(up_right));
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

BitBoard generate_knight_moves(U8 pos, const BitBoard &occupied, BoardState* state) {
  BitBoard moves;

  const int kKnightOffsets[] = {6, 10, 15, 17, -6, -10, -15, -17};
  for (const int &offset : kKnightOffsets) {
    U8 new_pos = pos + offset;

    // if the move collides with another piece
    if (occupied.is_set(new_pos)) {
      // if it's an opponent's piece, we can capture it but not move past it
      if (!state->pieces[state->turn_to_move == Color::kWhite ? kWhitePieces : kBlackPieces].is_set(new_pos))
        moves.set_bit(new_pos);
      continue;
    }

    moves.set_bit(new_pos);
  }

  return moves;
}

BitBoard generate_bishop_moves(U8 pos, const BitBoard& occupied, BoardState* state) {
  BitBoard moves;

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
BitBoard generate_rook_moves(U8 pos, const BitBoard &occupied, BoardState* state) {
  BitBoard moves;

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
BitBoard generate_king_moves(U8 pos, const BitBoard &occupied, BoardState* state) {
  BitBoard moves;

  auto generate_moves_in_direction = [&](auto &shift_fn) {
    BitBoard shifted = shift_fn(BitBoard(1ULL << pos));
    Color piece_color = get_piece_color(shifted, state->pieces);

    if (piece_color == Color::kNone || piece_color == Color(!static_cast<bool>(piece_color)))
      moves.set_bit(get_lsb_pos(shifted));
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