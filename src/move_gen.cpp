#include "move_gen.h"
#include "board.h"
#include "magics/precomputed.h"
#include "magics/attacks.h"

inline std::array<BitBoard, 64> knight_attacks;
inline std::array<BitBoard, 64> king_attacks;
inline std::array<std::array<BitBoard, 64>, 2> pawn_attacks;

void initialize_attacks() {
  for (int square = 0; square < Square::kSquareCount; square++) {
    const BitBoard bb_pos = BitBoard::from_square(square);
    
    knight_attacks[square] |= (bb_pos & ~FileMask::kFileH) << 17;
    knight_attacks[square] |= (bb_pos & ~(FileMask::kFileH | FileMask::kFileG)) << 10;
    knight_attacks[square] |= (bb_pos & ~(FileMask::kFileH | FileMask::kFileG)) >> 6;
    knight_attacks[square] |= (bb_pos & ~FileMask::kFileH) >> 15;
    knight_attacks[square] |= (bb_pos & ~FileMask::kFileA) << 15;
    knight_attacks[square] |= (bb_pos & ~(FileMask::kFileA | FileMask::kFileB)) << 6;
    knight_attacks[square] |= (bb_pos & ~(FileMask::kFileA | FileMask::kFileB)) >> 10;
    knight_attacks[square] |= (bb_pos & ~FileMask::kFileA) >> 17;
    
    king_attacks[square] |= shift<Direction::kNorth>(bb_pos);
    king_attacks[square] |= shift<Direction::kSouth>(bb_pos);
    king_attacks[square] |= shift<Direction::kEast>(bb_pos);
    king_attacks[square] |= shift<Direction::kWest>(bb_pos);
    king_attacks[square] |= shift<Direction::kNorthEast>(bb_pos);
    king_attacks[square] |= shift<Direction::kNorthWest>(bb_pos);
    king_attacks[square] |= shift<Direction::kSouthEast>(bb_pos);
    king_attacks[square] |= shift<Direction::kSouthWest>(bb_pos);

    pawn_attacks[Color::kWhite][square] |= shift<Direction::kNorthEast>(bb_pos);
    pawn_attacks[Color::kWhite][square] |= shift<Direction::kNorthWest>(bb_pos);
    pawn_attacks[Color::kBlack][square] |= shift<Direction::kSouthEast>(bb_pos);
    pawn_attacks[Color::kBlack][square] |= shift<Direction::kSouthWest>(bb_pos);
  }

  magics::attacks::initialize();
}

inline bool is_square_attacked_sliding_pieces(U8 pos, Color attacker, const BoardState &state) {
  const BitBoard rook_attacks = generate_rook_moves(pos, state);
  const BitBoard bishop_attacks = generate_bishop_moves(pos, state);

  const BitBoard &attacker_rooks = state.pieces[attacker][kRooks];
  const BitBoard &attacker_bishops = state.pieces[attacker][kBishops];
  const BitBoard &attacker_queens = state.pieces[attacker][kQueens];

  return (attacker_queens & (rook_attacks | bishop_attacks)) != 0 ||
      (attacker_rooks & rook_attacks) != 0 ||
      (attacker_bishops & bishop_attacks) != 0;
}

inline bool is_square_attacked_non_sliding_pieces(U8 pos, Color attacker, const BoardState &state) {
  const BitBoard &attacker_pawns = state.pieces[attacker][kPawns];
  const BitBoard &attacker_knights = state.pieces[attacker][kKnights];
  const BitBoard &attacker_king = state.pieces[attacker][kKings];

  return (attacker_pawns & generate_pawn_attacks(pos, state)) != 0 ||
      (attacker_knights & generate_knight_moves(pos, state)) != 0 ||
      (attacker_king & generate_king_attacks(pos, state)) != 0;
}

inline bool is_square_attacked(U8 pos, Color attacker, const BoardState &state) {
  return is_square_attacked_non_sliding_pieces(pos, attacker, state) || is_square_attacked_sliding_pieces(pos, attacker, state);
}

BitBoard generate_pawn_attacks(U8 pos, const BoardState &state) {
  BitBoard attacks = pawn_attacks[state.get_piece_color(pos)][pos];

  // allow en passant attack
  if (state.en_passant.has_value() && attacks.is_set(state.en_passant.value()))
    attacks.set_bit(state.en_passant.value());

  return attacks;
}

BitBoard generate_pawn_moves(U8 pos, const BoardState &state) {
  BitBoard moves, bb_pos = BitBoard::from_square(pos), occupied = state.occupied();

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
  const auto &entry = magics::kBishopMagics[pos];
  const U64 magic_index = ((entry.mask & state.occupied().as_u64()) * entry.magic) >> entry.shift;
  return magics::attacks::bishop_attacks[pos][magic_index];
}

BitBoard generate_rook_moves(U8 pos, const BoardState &state) {
  const auto &entry = magics::kRookMagics[pos];
  const U64 magic_index = ((entry.mask & state.occupied().as_u64()) * entry.magic) >> entry.shift;
  return magics::attacks::rook_attacks[pos][magic_index];
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
  return king_attacks[pos];
}

BitBoard generate_castling_moves(const BoardState &state, Color which) {
  BitBoard moves, occupied = state.occupied();

  const Color attacker = flip_color(which);
  if (which == Color::kWhite) {
    if (state.castle.can_kingside_castle(Color::kWhite)) {
      if (!is_square_attacked(Square::kF1, attacker, state) && !occupied.is_set(Square::kF1) &&
          !is_square_attacked(Square::kG1, attacker, state) && !occupied.is_set(Square::kG1))
        moves.set_bit(Square::kG1);
    }

    if (state.castle.can_queenside_castle(Color::kWhite)) {
      if (!is_square_attacked(Square::kD1, attacker, state) && !occupied.is_set(Square::kD1) &&
          !is_square_attacked(Square::kC1, attacker, state) && !occupied.is_set(Square::kC1) &&
          !occupied.is_set(Square::kB1))
        moves.set_bit(Square::kC1);
    }
  } else {
    if (state.castle.can_kingside_castle(Color::kBlack)) {
      if (!is_square_attacked(Square::kF8, attacker, state) && !occupied.is_set(Square::kF8) &&
          !is_square_attacked(Square::kG8, attacker, state) && !occupied.is_set(Square::kG8))
        moves.set_bit(Square::kG8);
    }

    if (state.castle.can_queenside_castle(Color::kBlack)) {
      if (!is_square_attacked(Square::kD8, attacker, state) && !occupied.is_set(Square::kD8) &&
          !is_square_attacked(Square::kC8, attacker, state) && !occupied.is_set(Square::kC8) &&
          !occupied.is_set(Square::kB8))
        moves.set_bit(Square::kC8);
    }
  }

  return moves;
}

BitBoard get_attacked_squares(const BoardState &state, Color attacker, bool include_king_attacks) {
  BitBoard attacked;

  BitBoard pawns = state.pieces[attacker][kPawns];
  while (pawns) {
    U8 from_square = pawns.pop_lsb();
    attacked |= generate_pawn_attacks(from_square, state);
  }

  BitBoard knights = state.pieces[attacker][kKnights];
  while (knights) {
    U8 from_square = knights.pop_lsb();
    attacked |= generate_knight_moves(from_square, state);
  }

  BitBoard bishops = state.pieces[attacker][kBishops];
  while (bishops) {
    U8 from_square = bishops.pop_lsb();
    attacked |= generate_bishop_moves(from_square, state);
  }

  BitBoard rooks = state.pieces[attacker][kRooks];
  while (rooks) {
    U8 from_square = rooks.pop_lsb();
    attacked |= generate_rook_moves(from_square, state);
  }

  BitBoard queens = state.pieces[attacker][kQueens];
  while (queens) {
    U8 from_square = queens.pop_lsb();
    attacked |= generate_rook_moves(from_square, state) | generate_bishop_moves(from_square, state);
  }

  if (include_king_attacks) {
    BitBoard king = state.pieces[attacker][kKings];
    if (king) {
      U8 king_square = king.pop_lsb(); // king is only in one position
      attacked |= generate_king_attacks(king_square, state);
    }
  }

  return attacked;
}

bool king_in_check(Color color, const BoardState &state) {
  const auto &king_bb = state.pieces[color][kKings];
  return is_square_attacked(king_bb.get_lsb_pos(), flip_color(color), state);
}

MoveList generate_moves(Board &board) {
  MoveList move_list;

  auto &state = board.get_state();

  BitBoard pawns = state.pieces[state.turn][kPawns];
  BitBoard knights = state.pieces[state.turn][kKnights];
  BitBoard bishops = state.pieces[state.turn][kBishops];
  BitBoard rooks = state.pieces[state.turn][kRooks];
  BitBoard queens = state.pieces[state.turn][kQueens];
  BitBoard king = state.pieces[state.turn][kKings];

  BitBoard &our_pieces = state.pieces[state.turn][kAllPieces];
  BitBoard &their_pieces = state.pieces[flip_color(state.turn)][kAllPieces];

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
        move_list.push(Move(from, to, PromotionType::kQueen));
        move_list.push(Move(from, to, PromotionType::kRook));
        move_list.push(Move(from, to, PromotionType::kKnight));
        move_list.push(Move(from, to, PromotionType::kBishop));
        continue;
      } else {
        move_list.push(Move(from, to));
      }
    }
  }

  while (knights) {
    U8 from = knights.pop_lsb();

    auto possible_moves = generate_knight_moves(from, state);
    possible_moves &= ~our_pieces;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  while (bishops) {
    U8 from = bishops.pop_lsb();

    auto possible_moves = generate_bishop_moves(from, state);
    possible_moves &= ~our_pieces;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  while (rooks) {
    U8 from = rooks.pop_lsb();

    auto possible_moves = generate_rook_moves(from, state);
    possible_moves &= ~our_pieces;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  while (queens) {
    U8 from = queens.pop_lsb();

    auto possible_moves = generate_rook_moves(from, state) | generate_bishop_moves(from, state);
    possible_moves &= ~our_pieces;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  while (king) {
    U8 from = king.pop_lsb();

    auto possible_moves = generate_king_moves(from, state);
    possible_moves &= ~our_pieces;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
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

  BitBoard pawns = state.pieces[state.turn][kPawns];
  BitBoard knights = state.pieces[state.turn][kKnights];
  BitBoard bishops = state.pieces[state.turn][kBishops];
  BitBoard rooks = state.pieces[state.turn][kRooks];
  BitBoard queens = state.pieces[state.turn][kQueens];
  BitBoard king = state.pieces[state.turn][kKings];

  BitBoard &our_pieces = state.pieces[state.turn][kAllPieces];
  BitBoard &their_pieces = state.pieces[flip_color(state.turn)][kAllPieces];
  BitBoard &their_king = state.pieces[flip_color(state.turn)][kKings];

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
        move_list.push(Move(from, to, PromotionType::kQueen));
        move_list.push(Move(from, to, PromotionType::kRook));
        move_list.push(Move(from, to, PromotionType::kKnight));
        move_list.push(Move(from, to, PromotionType::kBishop));
        continue;
      } else {
        move_list.push(Move(from, to));
      }
    }
  }

  while (knights) {
    U8 from = knights.pop_lsb();

    auto possible_moves = generate_knight_moves(from, state);
    possible_moves &= ~our_pieces & their_pieces & ~their_king;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  while (bishops) {
    U8 from = bishops.pop_lsb();

    auto possible_moves = generate_bishop_moves(from, state);
    possible_moves &= ~our_pieces & their_pieces & ~their_king;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  while (rooks) {
    U8 from = rooks.pop_lsb();

    auto possible_moves = generate_rook_moves(from, state);
    possible_moves &= ~our_pieces & their_pieces;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  while (queens) {
    U8 from = queens.pop_lsb();

    auto possible_moves = generate_rook_moves(from, state) | generate_bishop_moves(from, state);
    possible_moves &= ~our_pieces & their_pieces & ~their_king;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  while (king) {
    U8 from = king.pop_lsb();

    auto possible_moves = generate_king_moves(from, state);
    possible_moves &= ~our_pieces & their_pieces & ~their_king;

    while (possible_moves) {
      U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
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

  MoveList filtered;
  for (int i = 0; i < moves.size(); i++) {
    auto &move = moves[i];
    const bool is_capture = move.is_capture(state);

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