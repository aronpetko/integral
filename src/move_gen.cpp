#include "move_gen.h"

#include "board.h"
#include "magics/attacks.h"
#include "magics/precomputed.h"

namespace move_gen {

inline std::array<BitBoard, 64> knight_masks;
inline std::array<BitBoard, 64> king_masks;
inline std::array<std::array<BitBoard, 64>, 2> pawn_attack_masks;
inline std::array<std::array<BitBoard, 64>, 64> ray_between_masks;
inline std::array<std::array<BitBoard, 64>, 64> ray_intersecting_masks;

void initialize_attacks() {
  magics::attacks::initialize();

  for (int square = 0; square < Square::kSquareCount; square++) {
    const BitBoard src_mask = BitBoard::from_square(square);

    knight_masks[square] |= (src_mask & ~FileMask::kFileH) << 17;
    knight_masks[square] |= (src_mask & ~(FileMask::kFileH | FileMask::kFileG)) << 10;
    knight_masks[square] |= (src_mask & ~(FileMask::kFileH | FileMask::kFileG)) >> 6;
    knight_masks[square] |= (src_mask & ~FileMask::kFileH) >> 15;
    knight_masks[square] |= (src_mask & ~FileMask::kFileA) << 15;
    knight_masks[square] |= (src_mask & ~(FileMask::kFileA | FileMask::kFileB)) << 6;
    knight_masks[square] |= (src_mask & ~(FileMask::kFileA | FileMask::kFileB)) >> 10;
    knight_masks[square] |= (src_mask & ~FileMask::kFileA) >> 17;

    king_masks[square] |= shift<Direction::kNorth>(src_mask);
    king_masks[square] |= shift<Direction::kSouth>(src_mask);
    king_masks[square] |= shift<Direction::kEast>(src_mask);
    king_masks[square] |= shift<Direction::kWest>(src_mask);
    king_masks[square] |= shift<Direction::kNorthEast>(src_mask);
    king_masks[square] |= shift<Direction::kNorthWest>(src_mask);
    king_masks[square] |= shift<Direction::kSouthEast>(src_mask);
    king_masks[square] |= shift<Direction::kSouthWest>(src_mask);

    pawn_attack_masks[Color::kWhite][square] |= shift<Direction::kNorthEast>(src_mask);
    pawn_attack_masks[Color::kWhite][square] |= shift<Direction::kNorthWest>(src_mask);
    pawn_attack_masks[Color::kBlack][square] |= shift<Direction::kSouthEast>(src_mask);
    pawn_attack_masks[Color::kBlack][square] |= shift<Direction::kSouthWest>(src_mask);

    const BitBoard src_bishop_rays = magics::attacks::generate_bishop_moves(Square(square), 0ULL);
    const BitBoard src_rook_rays = magics::attacks::generate_rook_moves(Square(square), 0ULL);

    for (int other_square = 0; other_square < Square::kSquareCount; other_square++) {
      if (square == other_square) {
        continue;
      }

      const BitBoard dest_mask = BitBoard::from_square(other_square);

      if (src_bishop_rays & dest_mask) {
        // calculate the rays that intersect square and other_square
        ray_intersecting_masks[square][other_square] =
            (src_mask | src_bishop_rays) &
            (dest_mask | magics::attacks::generate_bishop_moves(Square(other_square), 0ULL));

        // calculate the rays between square and other_square
        ray_between_masks[square][other_square] =
            magics::attacks::generate_bishop_moves(Square(square), dest_mask) &
            magics::attacks::generate_bishop_moves(Square(other_square), src_mask);
      } else if (src_rook_rays & dest_mask) {
        // calculate the rays that intersect square and other_square
        ray_intersecting_masks[square][other_square] =
            (src_mask | src_rook_rays) & (dest_mask | magics::attacks::generate_rook_moves(Square(other_square), 0ULL));

        // calculate the rays between square and other_square
        ray_between_masks[square][other_square] =
            magics::attacks::generate_rook_moves(Square(square), dest_mask) &
            magics::attacks::generate_rook_moves(Square(other_square), src_mask);
      }
    }
  }
}

inline bool is_square_attacked_sliding_pieces(Square square, Color attacker, const BoardState &state) {
  const BitBoard occupied = state.occupied();
  const BitBoard queens = state.queens(attacker);

  const BitBoard bishop_attacks = bishop_moves(square, occupied);
  if ((queens | state.bishops(attacker)) & bishop_attacks) {
    return true;
  }

  const BitBoard rook_attacks = rook_moves(square, occupied);
  if ((queens | state.rooks(attacker)) & rook_attacks) {
    return true;
  }

  return false;
}

inline bool is_square_attacked_non_sliding_pieces(Square square, Color attacker, const BoardState &state) {
  return (state.knights(attacker) & knight_moves(square)) != 0 ||
         (state.pawns(attacker) & pawn_attacks(square, state, flip_color(attacker))) != 0 ||
         (state.king(attacker) & king_attacks(square)) != 0;
}

inline bool is_square_attacked(Square square, Color attacker, const BoardState &state) {
  return is_square_attacked_non_sliding_pieces(square, attacker, state) ||
         is_square_attacked_sliding_pieces(square, attacker, state);
}

BitBoard pawn_attacks(Square square, const BoardState &state, Color which) {
  return pawn_attack_masks[which == Color::kNoColor ? state.get_piece_color(square) : which][square];
}

BitBoard pawn_moves(Square square, const BoardState &state) {
  BitBoard moves, bb_pos = BitBoard::from_square(square), occupied = state.occupied();

  const auto color = state.get_piece_color(square);
  if (color == Color::kWhite) {
    BitBoard up = shift<Direction::kNorth>(bb_pos) & ~occupied;
    moves |= up;

    if (up && (bb_pos & RankMask::kRank2)) {
      BitBoard up_up = shift<Direction::kNorth>(up) & ~occupied;
      moves |= up_up;
    }
  } else {
    BitBoard down = shift<Direction::kSouth>(bb_pos) & ~occupied;
    moves |= down;

    if (down && (bb_pos & RankMask::kRank7)) {
      BitBoard down_down = shift<Direction::kSouth>(down) & ~occupied;
      moves |= down_down;
    }
  }

  return moves;
}

BitBoard knight_moves(Square square) {
  return knight_masks[square];
}

BitBoard bishop_moves(Square square, const BitBoard &occupied) {
  const auto &entry = magics::kBishopMagics[square];
  const auto magic_index = (occupied & entry.mask) * entry.magic >> entry.shift;
  return magics::attacks::bishop_attacks[square][magic_index.as_u64()];
}

BitBoard rook_moves(Square square, const BitBoard &occupied) {
  const auto &entry = magics::kRookMagics[square];
  const auto magic_index = (occupied & entry.mask) * entry.magic >> entry.shift;
  return magics::attacks::rook_attacks[square][magic_index.as_u64()];
}

BitBoard king_moves(Square square, const BoardState &state) {
  BitBoard moves = king_attacks(square);

  const auto color = state.get_piece_color(square);
  if (state.castle_rights.can_castle(state.turn) && !state.checkers) moves |= castling_moves(color, state);

  return moves;
}

BitBoard king_attacks(Square square) {
  return king_masks[square];
}

BitBoard castling_moves(Color which, const BoardState &state) {
  BitBoard moves, occupied = state.occupied();

  if (which == Color::kWhite) {
    if (state.castle_rights.can_kingside_castle(Color::kWhite)) {
      if (!occupied.is_set(Square::kF1) &&
          !occupied.is_set(Square::kG1)) {
        moves.set_bit(Square::kG1);
      }
    }

    if (state.castle_rights.can_queenside_castle(Color::kWhite)) {
      if (!occupied.is_set(Square::kD1) &&
          !occupied.is_set(Square::kC1) &&
          !occupied.is_set(Square::kB1))
        moves.set_bit(Square::kC1);
    }
  } else {
    if (state.castle_rights.can_kingside_castle(Color::kBlack)) {
      if (!occupied.is_set(Square::kF8) &&
          !occupied.is_set(Square::kG8))
        moves.set_bit(Square::kG8);
    }

    if (state.castle_rights.can_queenside_castle(Color::kBlack)) {
      if (!occupied.is_set(Square::kD8) &&
          !occupied.is_set(Square::kC8) &&
          !occupied.is_set(Square::kB8))
        moves.set_bit(Square::kC8);
    }
  }

  return moves;
}

BitBoard get_attacked_squares(const BoardState &state, Color attacker) {
  BitBoard attacked, occupied = state.occupied();

  BitBoard pawns = state.pawns(attacker);
  while (pawns) {
    attacked |= pawn_attacks(Square(pawns.pop_lsb()), state, attacker);
  }

  BitBoard knights = state.knights(attacker);
  while (knights) {
    attacked |= knight_moves(Square(knights.pop_lsb()));
  }

  BitBoard queens = state.queens(attacker);

  BitBoard bishops = state.bishops(attacker) | queens;
  while (bishops) {
    attacked |= bishop_moves(Square(bishops.pop_lsb()), occupied);
  }

  BitBoard rooks = state.rooks(attacker) | queens;
  while (rooks) {
    attacked |= rook_moves(Square(rooks.pop_lsb()), occupied);
  }

  BitBoard king = state.king(attacker);
  if (king) {
    // king is only in one position
    attacked |= king_attacks(Square(king.pop_lsb()));
  }

  return attacked;
}

BitBoard get_attackers_to(const BoardState &state, Square square, Color attacker, bool include_king_attacks) {
  const BitBoard occupied = state.occupied();
  const BitBoard queens = state.queens();

  BitBoard attackers;
  attackers |= pawn_attacks(square, state, flip_color(attacker)) & state.pawns();
  attackers |= knight_moves(square) & state.knights();
  attackers |= bishop_moves(square, occupied) & (state.bishops() | queens);
  attackers |= rook_moves(square, occupied) & (state.rooks() | queens);

  if (include_king_attacks) {
    attackers |= king_attacks(square) & state.kings();
  }

  return attackers & state.occupied(attacker);
}

BitBoard get_sliding_attackers_to(const BoardState &state, Square square, const BitBoard &occupied, Color attacker) {
  const BitBoard queens = state.queens();

  BitBoard attackers;
  attackers |= bishop_moves(square, occupied) & (state.bishops() | queens);
  attackers |= rook_moves(square, occupied) & (state.rooks() | queens);

  return attackers & state.occupied(attacker);
}

BitBoard ray_between(Square first, Square second) {
  return ray_between_masks[first][second];
}

BitBoard ray_intersecting(Square first, Square second) {
  return ray_intersecting_masks[first][second];
}

bool king_in_check(Color color, const BoardState &state) {
  return is_square_attacked(Square(state.king(color).get_lsb_pos()), flip_color(color), state);
}

List<Move, kMaxMoves> moves(MoveType move_type, Board &board) {
  List<Move, kMaxMoves> move_list;

  auto &state = board.get_state();

  const BitBoard occupied = state.occupied();
  const BitBoard &their_pieces = state.occupied(flip_color(state.turn));
  const BitBoard en_passant_mask = state.en_passant != Square::kNoSquare ? BitBoard::from_square(state.en_passant) : 0;

  BitBoard targets = 0;
  if (move_type & MoveType::kQuiet) targets |= ~occupied;
  if (move_type & MoveType::kCaptures) targets |= their_pieces;

  BitBoard pawns = state.pawns(state.turn);
  while (pawns) {
    const auto from = Square(pawns.pop_lsb());

    BitBoard pawn_targets = targets;
    if (move_type & MoveType::kTactical) {
      pawn_targets |= RankMask::kRank1 | RankMask::kRank8;
    }

    auto possible_moves = pawn_moves(from, state) & pawn_targets;
    if (move_type & MoveType::kCaptures) {
      possible_moves |= pawn_attacks(from, state) & (their_pieces | en_passant_mask);
    }

    while (possible_moves) {
      const auto to = possible_moves.pop_lsb();
      const auto to_rank = rank(to);

      if (to_rank == kNumRanks - 1 || to_rank == 0) {
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

  BitBoard knights = state.knights(state.turn) & ~state.pinned;
  while (knights) {
    const auto from = Square(knights.pop_lsb());

    auto possible_moves = knight_moves(from) & targets;
    while (possible_moves) {
      const U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  BitBoard bishops = state.bishops(state.turn);
  while (bishops) {
    const auto from = Square(bishops.pop_lsb());

    auto possible_moves = bishop_moves(from, occupied) & targets;
    while (possible_moves) {
      const U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  BitBoard rooks = state.rooks(state.turn);
  while (rooks) {
    const auto from = Square(rooks.pop_lsb());

    auto possible_moves = rook_moves(from, occupied) & targets;
    while (possible_moves) {
      const U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  BitBoard queens = state.queens(state.turn);
  while (queens) {
    const auto from = Square(queens.pop_lsb());

    auto possible_moves = (rook_moves(from, occupied) | bishop_moves(from, occupied)) & targets;
    while (possible_moves) {
      const U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  BitBoard king = state.king(state.turn);
  if (king) {
    const auto from = Square(king.get_lsb_pos());

    auto possible_moves = king_moves(from, state) & targets;
    while (possible_moves) {
      const U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  return move_list;
}

List<Move, kMaxMoves> filter_moves(List<Move, kMaxMoves> &moves, MoveType type, Board &board) {
  if (type == MoveType::kAll) return moves;

  auto &state = board.get_state();

  const auto causes_check = [&board, &state](const Move &move) {
    board.make_move(move);
    const bool in_check = state.checkers != 0;
    board.undo_move();
    return in_check;
  };

  List<Move, kMaxMoves> filtered;
  for (int i = 0; i < moves.size(); i++) {
    auto &move = moves[i];
    const bool is_capture = move.is_capture(state);

    if (type == MoveType::kCaptures) {
      if (is_capture) {
        filtered.push(move);
      }
    } else if (type == MoveType::kQuiet) {
      if (!is_capture && !causes_check(move) && move.get_promotion_type() == PromotionType::kNone) {
        filtered.push(move);
      }
    }
  }

  return filtered;
}

}  // namespace move_gen