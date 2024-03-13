#include "move_gen.h"
#include "board.h"

std::array<std::array<BitBoard, 64>, 8> ray_attacks;
std::array<BitBoard, 64> knight_attacks;

void initialize_attacks() {
  const auto generate_moves_in_direction = [](auto &shift_fn, U8 from) {
    BitBoard moves;
    BitBoard current = BitBoard::from_square(from);

    while (current) {
      current = shift_fn(current);
      moves |= current;
    }

    return moves;
  };

  for (int square = 0; square < Square::kSquareCount; square++) {
    // ray attacks (i.e. bishop, rooks, and queens)
    ray_attacks[Direction::kNorth][square] = generate_moves_in_direction(shift<Direction::kNorth>, square);
    ray_attacks[Direction::kEast][square] = generate_moves_in_direction(shift<Direction::kEast>, square);
    ray_attacks[Direction::kSouth][square] = generate_moves_in_direction(shift<Direction::kSouth>, square);
    ray_attacks[Direction::kWest][square] = generate_moves_in_direction(shift<Direction::kWest>, square);
    ray_attacks[Direction::kNorthEast][square] = generate_moves_in_direction(shift<Direction::kNorthEast>, square);
    ray_attacks[Direction::kNorthWest][square] = generate_moves_in_direction(shift<Direction::kNorthWest>, square);
    ray_attacks[Direction::kSouthEast][square] = generate_moves_in_direction(shift<Direction::kSouthEast>, square);
    ray_attacks[Direction::kSouthWest][square] = generate_moves_in_direction(shift<Direction::kSouthWest>, square);
    
    // knight attacks
    BitBoard bb_pos = BitBoard::from_square(square);

    knight_attacks[square] |= (bb_pos & ~FileMask::kFileH) << 17;
    knight_attacks[square] |= (bb_pos & ~(FileMask::kFileH | FileMask::kFileG)) << 10;
    knight_attacks[square] |= (bb_pos & ~(FileMask::kFileH | FileMask::kFileG)) >> 6;
    knight_attacks[square] |= (bb_pos & ~FileMask::kFileH) >> 15;
    knight_attacks[square] |= (bb_pos & ~FileMask::kFileA) << 15;
    knight_attacks[square] |= (bb_pos & ~(FileMask::kFileA | FileMask::kFileB)) << 6;
    knight_attacks[square] |= (bb_pos & ~(FileMask::kFileA | FileMask::kFileB)) >> 10;
    knight_attacks[square] |= (bb_pos & ~FileMask::kFileA) >> 17;
  }
}

inline BitBoard get_positive_ray_attacks(BitBoard occupied, Direction dir, U8 square) {
  BitBoard attacks = ray_attacks[dir][square];
  BitBoard blocker = attacks & occupied;
  square = std::countr_zero((blocker | U64(0x8000000000000000ULL)).as_u64());
  return attacks ^ ray_attacks[dir][square];
}

inline BitBoard get_negative_ray_attacks(BitBoard occupied, Direction dir, U8 square) {
  BitBoard attacks = ray_attacks[dir][square];
  BitBoard blocker = attacks & occupied;
  square = (Square::kSquareCount - 1) - std::countl_zero((blocker | 1).as_u64());
  return attacks ^ ray_attacks[dir][square];
}

BitBoard generate_pawn_attacks(U8 pos, const BoardState &state) {
  BitBoard moves, bb_pos = BitBoard::from_square(pos);

  const auto color = state.get_piece_color(pos);
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
  if (state.en_passant.has_value() && moves.is_set(state.en_passant.value()))
    moves.set_bit(state.en_passant.value());

  return moves;
}

BitBoard generate_pawn_moves(U8 pos, const BoardState &state) {
  BitBoard moves, bb_pos = BitBoard::from_square(pos), occupied = state.pieces[kAllPieces];

  const auto color = state.get_piece_color(pos);
  if (color == Color::kWhite) {
    BitBoard up = shift<Direction::kNorth>(bb_pos) & ~occupied;
    moves |= up;

    if (bb_pos & RankMask::kRank2) {
      BitBoard up_up = shift<Direction::kNorth>(up) & ~occupied;
      moves |= up_up;
    }
  } else {
    BitBoard down = shift<Direction::kSouth>(bb_pos) & ~occupied;
    moves |= down;

    if (bb_pos & RankMask::kRank7) {
      BitBoard down_down = shift<Direction::kSouth>(down) & ~occupied;
      moves |= down_down;
    }
  }

  return moves;
}

BitBoard generate_knight_moves(U8 pos, const BoardState &state) {
  return knight_attacks[pos];
}

BitBoard generate_bishop_moves(U8 pos, const BoardState &state) {
  const BitBoard &occupied = state.pieces[kAllPieces];
  return get_positive_ray_attacks(occupied, Direction::kNorthEast, pos) |
      get_positive_ray_attacks(occupied, Direction::kNorthWest, pos) |
      get_negative_ray_attacks(occupied, Direction::kSouthEast, pos) |
      get_negative_ray_attacks(occupied, Direction::kSouthWest, pos);
}

BitBoard generate_rook_moves(U8 pos, const BoardState &state) {
  const BitBoard &occupied = state.pieces[kAllPieces];
  return get_positive_ray_attacks(occupied, Direction::kNorth, pos) |
      get_negative_ray_attacks(occupied, Direction::kSouth, pos) |
      get_positive_ray_attacks(occupied, Direction::kEast, pos) |
      get_negative_ray_attacks(occupied, Direction::kWest, pos);
}

BitBoard generate_king_moves(U8 pos, const BoardState &state, bool include_castling) {
  BitBoard moves = generate_king_attacks(pos, state);

  if (include_castling) {
    const auto color = state.get_piece_color(pos);
    if ((state.castle.can_queenside_castle(color) || state.castle.can_kingside_castle(color)) && !king_in_check(color, state))
      moves |= generate_castling_moves(state, color);
  }

  return moves;
}

BitBoard generate_king_attacks(U8 pos, const BoardState &state) {
  BitBoard attacks, bb_pos = BitBoard::from_square(pos);

  attacks |= shift<Direction::kNorth>(bb_pos);
  attacks |= shift<Direction::kSouth>(bb_pos);
  attacks |= shift<Direction::kEast>(bb_pos);
  attacks |= shift<Direction::kWest>(bb_pos);
  attacks |= shift<Direction::kNorthEast>(bb_pos);
  attacks |= shift<Direction::kNorthWest>(bb_pos);
  attacks |= shift<Direction::kSouthEast>(bb_pos);
  attacks |= shift<Direction::kSouthWest>(bb_pos);

  return attacks;
}

BitBoard generate_castling_moves(const BoardState &state, Color which) {
  BitBoard moves, attacked = get_attacked_squares(state, Color(!which), true), occupied = state.pieces[kAllPieces];

  if (which == Color::kWhite) {
    if (state.castle.can_kingside_castle(Color::kWhite)) {
      if (!attacked.is_set(Square::kF1) && !occupied.is_set(Square::kF1) &&
          !attacked.is_set(Square::kG1) && !occupied.is_set(Square::kG1))
        moves.set_bit(Square::kG1);
    }

    if (state.castle.can_queenside_castle(Color::kWhite)) {
      if (!attacked.is_set(Square::kD1) && !occupied.is_set(Square::kD1) &&
          !attacked.is_set(Square::kC1) && !occupied.is_set(Square::kC1) &&
          !occupied.is_set(Square::kB1))
        moves.set_bit(Square::kC1);
    }
  } else {
    if (state.castle.can_kingside_castle(Color::kBlack)) {
      if (!attacked.is_set(Square::kF8) && !occupied.is_set(Square::kF8) &&
          !attacked.is_set(Square::kG8) && !occupied.is_set(Square::kG8))
        moves.set_bit(Square::kG8);
    }

    if (state.castle.can_queenside_castle(Color::kBlack)) {
      if (!attacked.is_set(Square::kD8) && !occupied.is_set(Square::kD8) &&
          !attacked.is_set(Square::kC8) && !occupied.is_set(Square::kC8) &&
          !occupied.is_set(Square::kB8))
        moves.set_bit(Square::kC8);
    }
  }

  return moves;
}

BitBoard get_attacked_squares(const BoardState &state, Color attacker, bool include_king_attacks) {
  BitBoard attacked;

  // offset for white and black pieces
  const int offset = attacker == Color::kBlack ? kBlackPawns : kWhitePawns;

  BitBoard pawns = state.pieces[offset + 0];
  while (pawns) {
    U8 from_square = pawns.pop_lsb();
    attacked |= generate_pawn_attacks(from_square, state);
  }

  BitBoard knights = state.pieces[offset + 1];
  while (knights) {
    U8 from_square = knights.pop_lsb();
    attacked |= generate_knight_moves(from_square, state);
  }

  BitBoard bishops = state.pieces[offset + 2];
  while (bishops) {
    U8 from_square = bishops.pop_lsb();
    attacked |= generate_bishop_moves(from_square, state);
  }

  BitBoard rooks = state.pieces[offset + 3];
  while (rooks) {
    U8 from_square = rooks.pop_lsb();
    attacked |= generate_rook_moves(from_square, state);
  }

  BitBoard queens = state.pieces[offset + 4];
  while (queens) {
    U8 from_square = queens.pop_lsb();
    attacked |= generate_rook_moves(from_square, state) | generate_bishop_moves(from_square, state);
  }

  if (include_king_attacks) {
    BitBoard king = state.pieces[offset + 5];
    if (king) {
      U8 king_square = king.pop_lsb(); // king is only in one position
      attacked |= generate_king_attacks(king_square, state);
    }
  }

  return attacked;
}

bool is_square_attacked_sliding_pieces(U8 pos, Color attacker, const BoardState &state) {
  BitBoard rook_attacks = generate_rook_moves(pos, state);
  BitBoard bishop_attacks = generate_bishop_moves(pos, state);

  const BitBoard &attacker_rooks = state.pieces[attacker == Color::kWhite ? kWhiteRooks : kBlackRooks];
  const BitBoard &attacker_bishops = state.pieces[attacker == Color::kWhite ? kWhiteBishops : kBlackBishops];
  const BitBoard &attacker_queens = state.pieces[attacker == Color::kWhite ? kWhiteQueens : kBlackQueens];

  return (attacker_queens & (rook_attacks | bishop_attacks)) != 0 ||
      (attacker_rooks & rook_attacks) != 0 ||
      (attacker_bishops & bishop_attacks) != 0;
}

bool is_square_attacked_non_sliding_pieces(U8 pos, Color attacker, const BoardState &state) {
  BitBoard pawn_attacks = generate_pawn_attacks(pos, state);
  BitBoard knight_attacks = generate_knight_moves(pos, state);
  BitBoard king_attacks = generate_king_attacks(pos, state);

  const BitBoard &attacker_pawns = state.pieces[attacker == Color::kWhite ? kWhitePawns : kBlackPawns];
  const BitBoard &attacker_knights = state.pieces[attacker == Color::kWhite ? kWhiteKnights : kBlackKnights];
  const BitBoard &attacker_king = state.pieces[attacker == Color::kWhite ? kWhiteKing : kBlackKing];

  return (attacker_pawns & pawn_attacks) != 0 ||
      (attacker_knights & knight_attacks) != 0 ||
      (attacker_king & king_attacks) != 0;
}

bool is_square_attacked(U8 pos, Color attacker, const BoardState &state) {
  return is_square_attacked_sliding_pieces(pos, attacker, state) || is_square_attacked_non_sliding_pieces(pos, attacker, state);
}

bool king_in_check(Color color, const BoardState &state) {
  const BitBoard &king_bb = color == Color::kWhite ? state.pieces[kWhiteKing] : state.pieces[kBlackKing];
  const U8 king_pos = king_bb.get_lsb_pos();

  return is_square_attacked_non_sliding_pieces(king_pos, flip_color(color), state)
      || is_square_attacked_sliding_pieces(king_pos, flip_color(color), state);
}

MoveList generate_moves(Board &board) {
  MoveList move_list;

  auto &state = board.get_state();
  const bool is_white = state.turn == Color::kWhite;

  BitBoard pawns;
  BitBoard knights;
  BitBoard bishops;
  BitBoard rooks;
  BitBoard queens;
  BitBoard king;

  if (is_white) {
    pawns = state.pieces[kWhitePawns];
    knights = state.pieces[kWhiteKnights];
    bishops = state.pieces[kWhiteBishops];
    rooks = state.pieces[kWhiteRooks];
    queens = state.pieces[kWhiteQueens];
    king = state.pieces[kWhiteKing];
  } else  {
    pawns = state.pieces[kBlackPawns];
    knights = state.pieces[kBlackKnights];
    bishops = state.pieces[kBlackBishops];
    rooks = state.pieces[kBlackRooks];
    queens = state.pieces[kBlackQueens];
    king = state.pieces[kBlackKing];
  }

  BitBoard &our_pieces = state.pieces[is_white ? kWhitePieces : kBlackPieces];
  BitBoard &their_pieces = state.pieces[is_white ? kBlackPieces : kWhitePieces];

  while (pawns) {
    U8 from = pawns.pop_lsb();

    const BitBoard en_passant_mask = state.en_passant.has_value() ? BitBoard::from_square(state.en_passant.value()) : BitBoard(0);
    auto possible_moves = generate_pawn_moves(from, state) | (generate_pawn_attacks(from, state) & (their_pieces | en_passant_mask));

    const bool en_passant_set = state.en_passant.has_value() && possible_moves.is_set(state.en_passant.value());
    possible_moves &= ~our_pieces;
    if (en_passant_set) possible_moves.set_bit(state.en_passant.value());

    while (possible_moves) {
      const auto to = possible_moves.pop_lsb();
      const auto to_rank = to / kBoardRanks;

      // add the different promotion moves if possible
      if (((state.turn == Color::kWhite && to_rank == kBoardRanks - 1)
          || (state.turn == Color::kBlack && to_rank == 0))) {
        move_list.push({from, to, PieceType::kPawn, PromotionType::kQueen});
        move_list.push({from, to, PieceType::kPawn, PromotionType::kRook});
        move_list.push({from, to, PieceType::kPawn, PromotionType::kKnight});
        move_list.push({from, to, PieceType::kPawn, PromotionType::kBishop});
        continue;
      } else {
        move_list.push({from, to, PieceType::kPawn});
      }
    }
  }

  while (knights) {
    U8 from = knights.pop_lsb();

    auto possible_moves = generate_knight_moves(from, state);
    possible_moves &= ~our_pieces;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push({from, to, PieceType::kKnight});
    }
  }

  while (bishops) {
    U8 from = bishops.pop_lsb();

    auto possible_moves = generate_bishop_moves(from, state);
    possible_moves &= ~our_pieces;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push({from, to, PieceType::kBishop});
    }
  }

  while (rooks) {
    U8 from = rooks.pop_lsb();

    auto possible_moves = generate_rook_moves(from, state);
    possible_moves &= ~our_pieces;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push({from, to, PieceType::kRook});
    }
  }

  while (queens) {
    U8 from = queens.pop_lsb();

    auto possible_moves = generate_rook_moves(from, state) | generate_bishop_moves(from, state);
    possible_moves &= ~our_pieces;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push({from, to, PieceType::kQueen});
    }
  }

  while (king) {
    U8 from = king.pop_lsb();

    auto possible_moves = generate_king_moves(from, state);
    possible_moves &= ~our_pieces;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push({from, to, PieceType::kKing});
    }
  }

  return move_list;
}

MoveList generate_legal_moves(Board &board) {
  auto &state = board.get_state();

  const auto is_legal_move = [&board, &state](const Move &move) {
    board.make_move(move);
    const bool in_check = king_in_check(flip_color(state.turn), state);
    board.undo_move();
    return !in_check;
  };

  MoveList pseudo_legal_moves = generate_moves(board), legal_moves;

  for (int i = 0; i < pseudo_legal_moves.size(); i++) {
    if (is_legal_move(pseudo_legal_moves[i])) {
      legal_moves.push(pseudo_legal_moves[i]);
    }
  }

  return legal_moves;
}

MoveList generate_capture_moves(Board &board) {
  MoveList move_list;

  auto &state = board.get_state();
  const bool is_white = state.turn == Color::kWhite;

  BitBoard pawns;
  BitBoard knights;
  BitBoard bishops;
  BitBoard rooks;
  BitBoard queens;
  BitBoard king;

  if (is_white) {
    pawns = state.pieces[kWhitePawns];
    knights = state.pieces[kWhiteKnights];
    bishops = state.pieces[kWhiteBishops];
    rooks = state.pieces[kWhiteRooks];
    queens = state.pieces[kWhiteQueens];
    king = state.pieces[kWhiteKing];
  } else  {
    pawns = state.pieces[kBlackPawns];
    knights = state.pieces[kBlackKnights];
    bishops = state.pieces[kBlackBishops];
    rooks = state.pieces[kBlackRooks];
    queens = state.pieces[kBlackQueens];
    king = state.pieces[kBlackKing];
  }

  BitBoard &our_pieces = state.pieces[is_white ? kWhitePieces : kBlackPieces];
  BitBoard &their_pieces = state.pieces[is_white ? kBlackPieces : kWhitePieces];
  BitBoard &their_king = state.pieces[is_white ? kBlackKing : kWhiteKing];

  while (pawns) {
    U8 from = pawns.pop_lsb();

    const BitBoard en_passant_mask = state.en_passant.has_value() ? BitBoard::from_square(state.en_passant.value()) : BitBoard(0);
    auto possible_moves = generate_pawn_moves(from, state) | (generate_pawn_attacks(from, state) & (their_pieces | en_passant_mask));

    const bool en_passant_set = state.en_passant.has_value() && possible_moves.is_set(state.en_passant.value());
    possible_moves &= ~our_pieces & their_pieces & ~their_king;
    if (en_passant_set) possible_moves.set_bit(state.en_passant.value());

    while (possible_moves) {
      const auto to = possible_moves.pop_lsb();
      const auto to_rank = to / kBoardRanks;

      // add the different promotion moves if possible
      if (((state.turn == Color::kWhite && to_rank == kBoardRanks - 1)
          || (state.turn == Color::kBlack && to_rank == 0))) {
        move_list.push({from, to, PieceType::kPawn, PromotionType::kQueen});
        move_list.push({from, to, PieceType::kPawn, PromotionType::kRook});
        move_list.push({from, to, PieceType::kPawn, PromotionType::kKnight});
        move_list.push({from, to, PieceType::kPawn, PromotionType::kBishop});
        continue;
      } else {
        move_list.push({from, to, PieceType::kPawn});
      }
    }
  }

  while (knights) {
    U8 from = knights.pop_lsb();

    auto possible_moves = generate_knight_moves(from, state);
    possible_moves &= ~our_pieces & their_pieces & ~their_king;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push({from, to, PieceType::kKnight});
    }
  }

  while (bishops) {
    U8 from = bishops.pop_lsb();

    auto possible_moves = generate_bishop_moves(from, state);
    possible_moves &= ~our_pieces & their_pieces & ~their_king;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push({from, to, PieceType::kBishop});
    }
  }

  while (rooks) {
    U8 from = rooks.pop_lsb();

    auto possible_moves = generate_rook_moves(from, state);
    possible_moves &= ~our_pieces & their_pieces;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push({from, to, PieceType::kRook});
    }
  }

  while (queens) {
    U8 from = queens.pop_lsb();

    auto possible_moves = generate_rook_moves(from, state) | generate_bishop_moves(from, state);
    possible_moves &= ~our_pieces & their_pieces & ~their_king;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push({from, to, PieceType::kQueen});
    }
  }

  while (king) {
    U8 from = king.pop_lsb();

    auto possible_moves = generate_king_moves(from, state);
    possible_moves &= ~our_pieces & their_pieces & ~their_king;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push({from, to, PieceType::kKing});
    }
  }

  return move_list;
}

MoveList filter_moves(MoveList &moves, MoveType type, Board &board) {
  if (type == MoveType::kAll)
    return moves;

  auto &state = board.get_state();

  const auto causes_check = [&board, &state](const Move &move) {
    board.make_move(move);
    const bool in_check = king_in_check(state.turn, state);
    board.undo_move();
    return in_check;
  };

  const BitBoard &all_pieces = state.pieces[kAllPieces];

  MoveList filtered;

  for (int i = 0; i < moves.size(); i++) {
    auto &move = moves[i];

    const bool is_capture = all_pieces.is_set(move.get_to()) || (state.en_passant.has_value() && state.en_passant == move.get_to());

    if (type == MoveType::kCaptures) {
      if (is_capture) {
        filtered.push(move);
      }
    } else if (type == MoveType::kQuiet) {
      if (!is_capture && !causes_check(move)
          && move.get_promotion_type() == PromotionType::kNone) {
        filtered.push(move);
      }
    }
  }

  return filtered;
}