#include "move_gen.h"
#include "board.h"

BitBoard generate_pawn_attacks(U8 pos, const std::unique_ptr<BoardState> &state) {
  const auto color = get_piece_color(pos, state->pieces);

  BitBoard moves, bb_pos(1ULL << pos);

  if (color == Color::kWhite) {
    BitBoard up_left = shift<Direction::kNorthWest>(bb_pos);
    BitBoard up_right = shift<Direction::kNorthEast>(bb_pos);
    moves |= up_left | up_right;
  } else {
    BitBoard down_left = shift<Direction::kSouthWest>(bb_pos);
    BitBoard down_right = shift<Direction::kSouthEast>(bb_pos);
    moves |= down_left | down_right;
  }

  // allow en passant attack
  if (state->en_passant.has_value() && moves.is_set(state->en_passant.value()))
    moves.set_bit(state->en_passant.value());

  return moves;
}

BitBoard generate_pawn_moves(U8 pos, const std::unique_ptr<BoardState> &state) {
  const auto color = get_piece_color(pos, state->pieces);

  BitBoard moves, bb_pos(1ULL << pos), occupied = state->pieces[kAllPieces];

  if (color == Color::kWhite) {
    BitBoard up = shift<Direction::kNorth>(bb_pos);
    if (!occupied.is_set(up.get_lsb_pos()))
      moves |= up;

    // pawns can move two squares on their first move
    if (!occupied.is_set(up.get_lsb_pos()) && (bb_pos & RankMasks::kRank2).as_u64()) {
      BitBoard up_up = shift<Direction::kNorth>(up);
      if (!occupied.is_set(up_up.get_lsb_pos()))
        moves |= up_up;
    }
  } else {
    BitBoard down = shift<Direction::kSouth>(bb_pos);
    if (!occupied.is_set(down.get_lsb_pos()))
      moves |= down;

    // pawns can move two squares on their first move
    if (!occupied.is_set(down.get_lsb_pos()) && (bb_pos & RankMasks::kRank7).as_u64()) {
      BitBoard down_down = shift<Direction::kSouth>(down);
      if (!occupied.is_set(down_down.get_lsb_pos()))
        moves |= down_down;
    }
  }

  return moves;
}

BitBoard generate_knight_moves(U8 pos, const std::unique_ptr<BoardState> &state) {
  BitBoard moves;

  // knight's move patterns in terms of rank and file offsets
  const int kKnightMovePatterns[][2] = {
      {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
      {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
  };

  int original_rank = pos / 8;
  int original_file = pos % kBoardFiles;

  for (const auto &pattern : kKnightMovePatterns) {
    int new_rank = original_rank + pattern[0];
    int new_file = original_file + pattern[1];

    // check if the new position is within the bounds of the board
    if (new_rank >= 0 && new_rank < 8 && new_file >= 0 && new_file < 8) {
      U8 new_pos = new_rank * 8 + new_file;
      moves.set_bit(new_pos);
    }
  }

  return moves;
}

BitBoard generate_bishop_moves(U8 pos, const std::unique_ptr<BoardState> &state) {
  const auto color = get_piece_color(pos, state->pieces);

  BitBoard moves;
  BitBoard &our_pieces = color == Color::kWhite ? state->pieces[kWhitePieces] : state->pieces[kBlackPieces],
      their_pieces = color == Color::kWhite ? state->pieces[kBlackPieces] : state->pieces[kWhitePieces];

  auto generate_moves_in_direction = [&](auto &shift_fn) {
    BitBoard current(1ULL << pos);
    while (true) {
      BitBoard shifted = shift_fn(current);
      // check if move is outside board
      if (!shifted.as_u64())
        break;

      U8 new_pos = shifted.get_lsb_pos();
      moves.set_bit(new_pos);

      // if the move collides with a piece it can't move any further
      if (our_pieces.is_set(new_pos) || their_pieces.is_set(new_pos))
        break;

      // update the piece's position
      current = shifted;
    }
  };

  generate_moves_in_direction(shift<Direction::kNorthEast>);
  generate_moves_in_direction(shift<Direction::kNorthWest>);
  generate_moves_in_direction(shift<Direction::kSouthEast>);
  generate_moves_in_direction(shift<Direction::kSouthWest>);

  return moves;
}

BitBoard generate_rook_moves(U8 pos, const std::unique_ptr<BoardState> &state) {
  const auto color = get_piece_color(pos, state->pieces);

  BitBoard moves;
  BitBoard &our_pieces = color == Color::kWhite ? state->pieces[kWhitePieces] : state->pieces[kBlackPieces],
      &their_pieces = color == Color::kWhite ? state->pieces[kBlackPieces] : state->pieces[kWhitePieces];

  auto generate_moves_in_direction = [&](auto &shift_fn) {
    BitBoard current(1ULL << pos);
    while (true) {
      BitBoard shifted = shift_fn(current);
      // check if move is outside board
      if (!shifted.as_u64())
        break;

      U8 new_pos = shifted.get_lsb_pos();
      moves.set_bit(new_pos);

      // if the move collides with a piece it can't move any further
      if (our_pieces.is_set(new_pos) || their_pieces.is_set(new_pos))
        break;

      // update the piece's position
      current = shifted;
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
  const auto color = get_piece_color(pos, state->pieces);

  BitBoard moves;
  BitBoard pos_bb(1ULL << pos);

  auto generate_moves_in_direction = [&moves, &pos_bb](auto &shift_fn) {
    BitBoard shifted = shift_fn(pos_bb);
    // check if move is outside board
    if (!shifted.as_u64())
      return;

    U8 new_pos = shifted.get_lsb_pos();
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

  if (!king_in_check(color.value(), state))
    moves |= generate_castling_moves(state, color.value());

  return moves;
}

BitBoard generate_king_attacks(U8 pos, const std::unique_ptr<BoardState> &state) {
  BitBoard attacks;
  BitBoard pos_bb(1ULL << pos);

  auto generate_attack_in_direction = [&attacks, &pos_bb](auto &shift_fn) {
    BitBoard shifted = shift_fn(pos_bb);
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

BitBoard generate_castling_moves(const std::unique_ptr<BoardState> &state, Color which) {
  BitBoard moves, attacked = get_attacked_squares(state, Color(!which), true), occupied = state->pieces[kAllPieces];

  if (which == Color::kWhite) {
    if (state->castle.can_kingside_castle(Color::kWhite)) {
      if (!attacked.is_set(Square::kF1) && !occupied.is_set(Square::kF1) &&
          !attacked.is_set(Square::kG1) && !occupied.is_set(Square::kG1))
        moves.set_bit(Square::kG1);
    }

    if (state->castle.can_queenside_castle(Color::kWhite)) {
      if (!attacked.is_set(Square::kD1) && !occupied.is_set(Square::kD1) &&
          !attacked.is_set(Square::kC1) && !occupied.is_set(Square::kC1) &&
          !occupied.is_set(Square::kB1))
        moves.set_bit(Square::kC1);
    }
  } else {
    if (state->castle.can_kingside_castle(Color::kBlack)) {
      if (!attacked.is_set(Square::kF8) && !occupied.is_set(Square::kF8) &&
          !attacked.is_set(Square::kG8) && !occupied.is_set(Square::kG8))
        moves.set_bit(Square::kG8);
    }

    if (state->castle.can_queenside_castle(Color::kBlack)) {
      if (!attacked.is_set(Square::kD8) && !occupied.is_set(Square::kD8) &&
          !attacked.is_set(Square::kC8) && !occupied.is_set(Square::kC8) &&
          !occupied.is_set(Square::kB8))
        moves.set_bit(Square::kC8);
    }
  }

  return moves;
}

BitBoard get_attacked_squares(const std::unique_ptr<BoardState> &state, Color attacker, bool include_king_attacks) {
  BitBoard attacked;

  // offset for white and black pieces
  const int offset = attacker == Color::kBlack ? kBlackPawns : kWhitePawns;

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
      attacked |= generate_king_attacks(king_square, state);
    }
  }

  return attacked;
}

bool is_square_attacked(U8 pos, Color attacker, const std::unique_ptr<BoardState> &state) {
  // offset for white and black pieces
  const int offset = attacker == Color::kBlack ? kBlackPawns : kWhitePawns;

  BitBoard queens = state->pieces[offset + 4];
  while (queens.as_u64()) {
    U8 from_square = queens.pop_lsb();
    if ((generate_rook_moves(from_square, state) | generate_bishop_moves(from_square, state)).is_set(pos))
      return true;
  }

  BitBoard rooks = state->pieces[offset + 3];
  while (rooks.as_u64()) {
    U8 from_square = rooks.pop_lsb();
    if (generate_rook_moves(from_square, state).is_set(pos))
      return true;
  }

  BitBoard bishops = state->pieces[offset + 2];
  while (bishops.as_u64()) {
    U8 from_square = bishops.pop_lsb();
    if (generate_bishop_moves(from_square, state).is_set(pos))
      return true;
  }

  BitBoard knights = state->pieces[offset + 1];
  while (knights.as_u64()) {
    U8 from_square = knights.pop_lsb();
    if (generate_knight_moves(from_square, state).is_set(pos))
      return true;
  }

  BitBoard pawns = state->pieces[offset + 0];
  while (pawns.as_u64()) {
    U8 from_square = pawns.pop_lsb();
    if (generate_pawn_attacks(from_square, state).is_set(pos))
      return true;
  }

  BitBoard king = state->pieces[offset + 5];
  if (king.as_u64()) {
    U8 king_square = king.pop_lsb(); // king is only in one position
    if (generate_king_attacks(king_square, state).is_set(pos))
      return true;
  }

  return false;
}

bool king_in_check(Color color, const std::unique_ptr<BoardState> &state) {
  BitBoard king_bb = color == Color::kWhite ? state->pieces[kWhiteKing] : state->pieces[kBlackKing];
  return is_square_attacked(king_bb.get_lsb_pos(), Color(!color), state);
}

MoveList generate_moves(const std::unique_ptr<BoardState> &state) {
  MoveList moves;

  for (U8 rank = 0; rank < kBoardRanks; rank++) {
    for (U8 file = 0; file < kBoardFiles; file++) {
      const U8 from = rank_file_to_pos(rank, file);

      const auto piece_type = get_piece_type(from, state->pieces);
      if (piece_type == PieceType::kNone)
        continue;

      const auto piece_color = get_piece_color(from, state->pieces);
      if (piece_color != state->turn)
        continue;

      BitBoard &our_pieces = state->pieces[state->turn == Color::kWhite ? kWhitePieces : kBlackPieces];
      BitBoard &their_pieces = state->pieces[state->turn == Color::kWhite ? kBlackPieces : kWhitePieces];

      BitBoard possible_moves;
      switch (piece_type) {
        case PieceType::kPawn: {
          const BitBoard en_passant_mask = state->en_passant.has_value() ? BitBoard(1ULL << state ->en_passant.value()) : BitBoard(0);
          possible_moves = generate_pawn_moves(from, state) | (generate_pawn_attacks(from, state) & (their_pieces | en_passant_mask));
          break;
        }
        case PieceType::kKnight:possible_moves = generate_knight_moves(from, state);
          break;
        case PieceType::kBishop:possible_moves = generate_bishop_moves(from, state);
          break;
        case PieceType::kRook:possible_moves = generate_rook_moves(from, state);
          break;
        case PieceType::kQueen:possible_moves = generate_bishop_moves(from, state) | generate_rook_moves(from, state);
          break;
        case PieceType::kKing:possible_moves = generate_king_moves(from, state);
          break;
        default:break;
      }

      const bool en_passant_set = state->en_passant.has_value() && possible_moves.is_set(state->en_passant.value());
      possible_moves &= ~our_pieces;
      if (en_passant_set) possible_moves.set_bit(state->en_passant.value());

      while (possible_moves.as_u64()) {
        const U8 to = possible_moves.pop_lsb();
        const U8 to_rank = to / 8;

        // add the different promotion moves if possible
        if (piece_type == PieceType::kPawn) {
          if ((state->turn == Color::kWhite && to_rank == kBoardRanks - 1)
              || (state->turn == Color::kBlack && to_rank == 0)) {
            moves.emplace_back(from, to, piece_type, PromotionType::kKnight);
            moves.emplace_back(from, to, piece_type, PromotionType::kBishop);
            moves.emplace_back(from, to, piece_type, PromotionType::kRook);
            moves.emplace_back(from, to, piece_type, PromotionType::kQueen);
            continue;
          }
        }

        moves.emplace_back(from, to, piece_type);
      }
    }
  }

  return moves;
}

MoveList generate_legal_moves(Board &board) {
  const auto &state = board.get_state();

  auto quick_is_legal_move = [&board, &state](const Move &move) {
    board.make_move(move);
    const bool in_check = king_in_check(Color(!state->turn), state);
    board.undo_move();
    return !in_check;
  };

  MoveList moves = generate_moves(state);
  MoveList legal_moves;

  for (const auto &move : moves) {
    if (quick_is_legal_move(move))
      legal_moves.push_back(move);
  }

  return legal_moves;
}

MoveList generate_capture_moves(Board &board) {
  const auto &state = board.get_state();

  auto quick_is_legal_move = [&board, &state](const Move &move) {
    board.make_move(move);
    const bool in_check = king_in_check(Color(!state->turn), state);
    board.undo_move();
    return !in_check;
  };

  MoveList moves;

  for (U8 rank = 0; rank < kBoardRanks; rank++) {
    for (U8 file = 0; file < kBoardFiles; file++) {
      const U8 from = rank_file_to_pos(rank, file);

      const auto piece_type = get_piece_type(from, state->pieces);
      if (piece_type == PieceType::kNone)
        continue;

      const auto piece_color = get_piece_color(from, state->pieces);
      if (piece_color != state->turn)
        continue;

      BitBoard &our_pieces = state->pieces[state->turn == Color::kWhite ? kWhitePieces : kBlackPieces];
      BitBoard &their_pieces = state->pieces[state->turn == Color::kWhite ? kBlackPieces : kWhitePieces];

      BitBoard possible_moves;
      switch (piece_type) {
        case PieceType::kPawn: {
          const BitBoard en_passant_mask = state->en_passant.has_value() ? BitBoard(1ULL << state ->en_passant.value()) : BitBoard(0);
          possible_moves = generate_pawn_moves(from, state) | (generate_pawn_attacks(from, state) & (their_pieces | en_passant_mask));
          break;
        }
        case PieceType::kKnight: possible_moves = generate_knight_moves(from, state);
          break;
        case PieceType::kBishop: possible_moves = generate_bishop_moves(from, state);
          break;
        case PieceType::kRook: possible_moves = generate_rook_moves(from, state);
          break;
        case PieceType::kQueen: possible_moves = generate_bishop_moves(from, state) | generate_rook_moves(from, state);
          break;
        case PieceType::kKing: possible_moves = generate_king_moves(from, state);
          break;
        default:break;
      }

      const bool en_passant_set = state->en_passant.has_value() && possible_moves.is_set(state->en_passant.value());
      possible_moves &= ~our_pieces;
      possible_moves &= their_pieces;
      if (en_passant_set) possible_moves.set_bit(state->en_passant.value());

      while (possible_moves.as_u64()) {
        const U8 to = possible_moves.pop_lsb();
        const U8 to_rank = to / 8;

        // add the different promotion moves if possible
        if (piece_type == PieceType::kPawn) {
          if ((state->turn == Color::kWhite && to_rank == kBoardRanks - 1)
              || (state->turn == Color::kBlack && to_rank == 0)) {
            moves.emplace_back(from, to, piece_type, PromotionType::kKnight);
            moves.emplace_back(from, to, piece_type, PromotionType::kBishop);
            moves.emplace_back(from, to, piece_type, PromotionType::kRook);
            moves.emplace_back(from, to, piece_type, PromotionType::kQueen);
            continue;
          }
        }

        if (quick_is_legal_move({from, to, piece_type, PromotionType::kAny}))
          moves.emplace_back(from, to, piece_type);
      }
    }
  }

  return moves;
}