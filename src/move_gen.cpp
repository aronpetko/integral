#include "move_gen.h"

#include "board.h"
#include "magics/attacks.h"
#include "magics/precomputed.h"

namespace move_gen {

inline std::array<BitBoard, 64> knight_masks;
inline std::array<BitBoard, 64> king_masks;
inline std::array<std::array<BitBoard, 64>, 2> pawn_attack_masks;

void initialize_attacks() {
  for (int square = 0; square < Square::kSquareCount; square++) {
    const BitBoard bb_pos = BitBoard::from_square(square);

    knight_masks[square] |= (bb_pos & ~FileMask::kFileH) << 17;
    knight_masks[square] |= (bb_pos & ~(FileMask::kFileH | FileMask::kFileG)) << 10;
    knight_masks[square] |= (bb_pos & ~(FileMask::kFileH | FileMask::kFileG)) >> 6;
    knight_masks[square] |= (bb_pos & ~FileMask::kFileH) >> 15;
    knight_masks[square] |= (bb_pos & ~FileMask::kFileA) << 15;
    knight_masks[square] |= (bb_pos & ~(FileMask::kFileA | FileMask::kFileB)) << 6;
    knight_masks[square] |= (bb_pos & ~(FileMask::kFileA | FileMask::kFileB)) >> 10;
    knight_masks[square] |= (bb_pos & ~FileMask::kFileA) >> 17;

    king_masks[square] |= shift<Direction::kNorth>(bb_pos);
    king_masks[square] |= shift<Direction::kSouth>(bb_pos);
    king_masks[square] |= shift<Direction::kEast>(bb_pos);
    king_masks[square] |= shift<Direction::kWest>(bb_pos);
    king_masks[square] |= shift<Direction::kNorthEast>(bb_pos);
    king_masks[square] |= shift<Direction::kNorthWest>(bb_pos);
    king_masks[square] |= shift<Direction::kSouthEast>(bb_pos);
    king_masks[square] |= shift<Direction::kSouthWest>(bb_pos);

    pawn_attack_masks[Color::kWhite][square] |= shift<Direction::kNorthEast>(bb_pos);
    pawn_attack_masks[Color::kWhite][square] |= shift<Direction::kNorthWest>(bb_pos);
    pawn_attack_masks[Color::kBlack][square] |= shift<Direction::kSouthEast>(bb_pos);
    pawn_attack_masks[Color::kBlack][square] |= shift<Direction::kSouthWest>(bb_pos);
  }

  magics::attacks::initialize();
}

inline bool is_square_attacked_sliding_pieces(U8 pos, Color attacker, const BoardState &state) {
  const BitBoard occupied = state.occupied();
  const BitBoard queens = state.queens(attacker);

  const BitBoard bishop_attacks = bishop_moves(pos, occupied);
  if ((queens | state.bishops(attacker)) & bishop_attacks) {
    return true;
  }

  const BitBoard rook_attacks = rook_moves(pos, occupied);
  if ((queens | state.rooks(attacker)) & rook_attacks) {
    return true;
  }

  return false;
}

inline bool is_square_attacked_non_sliding_pieces(U8 pos, Color attacker, const BoardState &state) {
  return (state.knights(attacker) & knight_moves(pos)) != 0 ||
         (state.pawns(attacker) & pawn_attacks(pos, state, flip_color(attacker))) != 0 ||
         (state.king(attacker) & king_attacks(pos)) != 0;
}

inline bool is_square_attacked(U8 pos, Color attacker, const BoardState &state) {
  return is_square_attacked_non_sliding_pieces(pos, attacker, state) ||
         is_square_attacked_sliding_pieces(pos, attacker, state);
}

BitBoard pawn_attacks(U8 pos, const BoardState &state, Color which, bool en_passant) {
  BitBoard attacks = pawn_attack_masks[which == Color::kNoColor ? state.get_piece_color(pos) : which][pos];
  if (en_passant && state.en_passant != Square::kNoSquare && attacks.is_set(state.en_passant)) {
    attacks.set_bit(state.en_passant);
  }

  return attacks;
}

BitBoard pawn_moves(U8 pos, const BoardState &state) {
  BitBoard moves, bb_pos = BitBoard::from_square(pos), occupied = state.occupied();

  const auto color = state.get_piece_color(pos);
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

BitBoard knight_moves(U8 pos) {
  return knight_masks[pos];
}

BitBoard bishop_moves(U8 pos, const BitBoard &occupied) {
  const auto &entry = magics::kBishopMagics[pos];
  const auto magic_index = ((occupied & entry.mask) * entry.magic) >> entry.shift;
  return magics::attacks::bishop_attacks[pos][magic_index.as_u64()];
}

BitBoard rook_moves(U8 pos, const BitBoard &occupied) {
  const auto &entry = magics::kRookMagics[pos];
  const auto magic_index = ((occupied & entry.mask) * entry.magic) >> entry.shift;
  return magics::attacks::rook_attacks[pos][magic_index.as_u64()];
}

BitBoard king_moves(U8 pos, const BoardState &state) {
  BitBoard moves = king_attacks(pos);

  const auto color = state.get_piece_color(pos);
  if (state.castle_rights.can_castle(state.turn) && !king_in_check(color, state))
    moves |= castling_moves(color, state);

  return moves;
}

BitBoard king_attacks(U8 pos) {
  return king_masks[pos];
}

BitBoard castling_moves(Color which, const BoardState &state) {
  BitBoard moves, occupied = state.occupied();

  if (which == Color::kWhite) {
    const Color attacker = flip_color(which);

    if (state.castle_rights.can_kingside_castle(Color::kWhite)) {
      if (!is_square_attacked(Square::kF1, attacker, state) && !occupied.is_set(Square::kF1) &&
          !is_square_attacked(Square::kG1, attacker, state) && !occupied.is_set(Square::kG1)) {
        moves.set_bit(Square::kG1);
      }
    }

    if (state.castle_rights.can_queenside_castle(Color::kWhite)) {
      if (!is_square_attacked(Square::kD1, attacker, state) && !occupied.is_set(Square::kD1) &&
          !is_square_attacked(Square::kC1, attacker, state) && !occupied.is_set(Square::kC1) &&
          !occupied.is_set(Square::kB1))
        moves.set_bit(Square::kC1);
    }
  } else {
    const Color attacker = flip_color(which);

    if (state.castle_rights.can_kingside_castle(Color::kBlack)) {
      if (!is_square_attacked(Square::kF8, attacker, state) && !occupied.is_set(Square::kF8) &&
          !is_square_attacked(Square::kG8, attacker, state) && !occupied.is_set(Square::kG8))
        moves.set_bit(Square::kG8);
    }

    if (state.castle_rights.can_queenside_castle(Color::kBlack)) {
      if (!is_square_attacked(Square::kD8, attacker, state) && !occupied.is_set(Square::kD8) &&
          !is_square_attacked(Square::kC8, attacker, state) && !occupied.is_set(Square::kC8) &&
          !occupied.is_set(Square::kB8))
        moves.set_bit(Square::kC8);
    }
  }

  return moves;
}

BitBoard get_attacked_squares(const BoardState &state, Color attacker, bool include_king_attacks) {
  BitBoard attacked, occupied = state.occupied();

  BitBoard pawns = state.pawns(attacker);
  while (pawns) {
    attacked |= pawn_attacks(pawns.pop_lsb(), state);
  }

  BitBoard knights = state.knights(attacker);
  while (knights) {
    attacked |= knight_moves(knights.pop_lsb());
  }

  BitBoard bishops = state.bishops(attacker);
  while (bishops) {
    attacked |= bishop_moves(bishops.pop_lsb(), occupied);
  }

  BitBoard rooks = state.rooks(attacker);
  while (rooks) {
    attacked |= rook_moves(rooks.pop_lsb(), occupied);
  }

  BitBoard queens = state.queens(attacker);
  while (queens) {
    const U8 square = queens.pop_lsb();
    attacked |= rook_moves(square, occupied) | bishop_moves(square, occupied);
  }

  if (include_king_attacks) {
    BitBoard king = state.king(attacker);
    if (king) {
      // king is only in one position
      attacked |= king_attacks(king.pop_lsb());
    }
  }

  return attacked;
}

bool king_in_check(Color color, const BoardState &state) {
  return is_square_attacked(state.king(color).get_lsb_pos(), flip_color(color), state);
}

List<Move> moves(MoveType move_type, Board &board) {
  List<Move> move_list;

  auto &state = board.get_state();

  const BitBoard &our_pieces = state.occupied(state.turn);
  const BitBoard &their_pieces = state.occupied(flip_color(state.turn));
  const BitBoard occupied = state.occupied();
  const BitBoard en_passant_mask = state.en_passant != Square::kNoSquare ? BitBoard::from_square(state.en_passant) : 0;

  BitBoard targets = 0;
  if (move_type & MoveType::kQuiet) {
    targets |= ~occupied;
  }
  if (move_type & MoveType::kCaptures) {
    targets |= their_pieces;
  }

  BitBoard pawns = state.pawns(state.turn);
  while (pawns) {
    const U8 from = pawns.pop_lsb();

    auto possible_moves = pawn_moves(from, state) & targets;
    possible_moves |= pawn_attacks(from, state) & (their_pieces | en_passant_mask);

    while (possible_moves) {
      const auto to = possible_moves.pop_lsb();
      const auto to_rank = rank(to);

      // add the different promotion moves if possible
      if (to_rank == kBoardRanks - 1 || to_rank == 0) {
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

  BitBoard knights = state.knights(state.turn);
  while (knights) {
    const U8 from = knights.pop_lsb();

    auto possible_moves = knight_moves(from) & targets;
    while (possible_moves) {
      const U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  BitBoard bishops = state.bishops(state.turn);
  while (bishops) {
    const U8 from = bishops.pop_lsb();

    auto possible_moves = bishop_moves(from, occupied) & targets;
    while (possible_moves) {
      const U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  BitBoard rooks = state.rooks(state.turn);
  while (rooks) {
    const U8 from = rooks.pop_lsb();

    auto possible_moves = rook_moves(from, occupied) & targets;
    while (possible_moves) {
      const U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  BitBoard queens = state.queens(state.turn);
  while (queens) {
    const U8 from = queens.pop_lsb();

    auto possible_moves = (rook_moves(from, occupied) | bishop_moves(from, occupied)) & targets;
    while (possible_moves) {
      const U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  BitBoard king = state.king(state.turn);
  if (king) {
    const U8 from = king.get_lsb_pos();

    auto possible_moves = king_moves(from, state) & targets;
    while (possible_moves) {
      const U8 to = possible_moves.pop_lsb();
      move_list.push(Move(from, to));
    }
  }

  return move_list;
}

List<Move> filter_moves(List<Move> &moves, MoveType type, Board &board) {
  if (type == MoveType::kAll) return moves;

  auto &state = board.get_state();

  const auto causes_check = [&board, &state](const Move &move) {
    board.make_move(move);
    const bool in_check = king_in_check(state.turn, state);
    board.undo_move();
    return in_check;
  };

  List<Move> filtered;
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

}