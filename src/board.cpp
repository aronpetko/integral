#include "board.h"
#include "fen.h"
#include "move.h"
#include "move_gen.h"

Board::Board() : history_() {}

void Board::set_from_fen(const std::string &fen_str) {
  // reset history everytime we parse from fen, since they will be re-applied when the moves are made
  history_.clear();
  state_ = fen::string_to_board(fen_str);

  calculate_king_attacks();
}

bool Board::is_move_pseudo_legal(Move move) {
  const auto from = move.get_from(), to = move.get_to();
  const auto piece_type = state_.get_piece_type(from);

  const BitBoard &our_pieces = state_.occupied(state_.turn);
  if (!our_pieces.is_set(from) || our_pieces.is_set(to) ||
      move.get_promotion_type() != PromotionType::kNone && piece_type != PieceType::kPawn) {
    return false;
  }

  const BitBoard &their_pieces = state_.occupied(flip_color(state_.turn));
  const BitBoard occupied = our_pieces | their_pieces;

  BitBoard possible_moves;

  switch (piece_type) {
    case PieceType::kPawn: {
      const BitBoard en_passant_mask =
          state_.en_passant != Square::kNoSquare ? BitBoard::from_square(state_.en_passant) : BitBoard(0);
      possible_moves = move_gen::pawn_moves(from, state_) |
                       (move_gen::pawn_attacks(from, state_, state_.turn) & (their_pieces | en_passant_mask));
      break;
    }
    case PieceType::kKnight:
      possible_moves = move_gen::knight_moves(from);
      break;
    case PieceType::kBishop:
      possible_moves = move_gen::bishop_moves(from, occupied);
      break;
    case PieceType::kRook:
      possible_moves = move_gen::rook_moves(from, occupied);
      break;
    case PieceType::kQueen:
      possible_moves = move_gen::bishop_moves(from, occupied) | move_gen::rook_moves(from, occupied);
      break;
    case PieceType::kKing:
      possible_moves = move_gen::king_moves(from, state_);
      break;
    default:
      return false;
  }

  return possible_moves.is_set(to);
}

bool Board::is_move_legal(Move move) {
  const Color us = state_.turn, them = flip_color(us);
  const bool is_white = state_.turn == Color::kWhite;

  const auto from = Square(move.get_from());
  const auto to = Square(move.get_to());

  const BitBoard king_mask = state_.king(us);
  const auto king_square = Square(king_mask.get_lsb_pos());

  const auto piece_type = state_.get_piece_type(from);
  if (piece_type == PieceType::kKing) {
    const BitBoard their_pieces = state_.occupied(them);

    const int kKingsideCastleDist = -2;
    const int kQueensideCastleDist = 2;

    // note: the only way move_dist is ever 2 or -2 is from move_gen::castling_moves allowing it
    const int move_dist = static_cast<int>(from) - static_cast<int>(to);
    if (move_dist == kKingsideCastleDist) {
      return !move_gen::get_attackers_to(state_, is_white ? Square::kG1 : Square::kG8, them) &&
             !move_gen::get_attackers_to(state_, is_white ? Square::kF1 : Square::kF8, them);
    } else if (move_dist == kQueensideCastleDist) {
      return !move_gen::get_attackers_to(state_, is_white ? Square::kC1 : Square::kC8, them) &&
             !move_gen::get_attackers_to(state_, is_white ? Square::kD1 : Square::kD8, them);
    }

    const BitBoard occupied_kingless = state_.occupied() ^ state_.king(us);
    const BitBoard their_queens = state_.queens(them);

    // make sure the destination square isn't attacked
    // also, verify that the king isn't moving along the same ray it's being attacked on, since the threats bitboard
    // doesn't xray past pieces
    return !move_gen::get_attackers_to(state_, to, them) &&
           !(move_gen::bishop_moves(to, occupied_kingless) & (their_queens | state_.bishops(them))) &&
           !(move_gen::rook_moves(to, occupied_kingless) & (their_queens | state_.rooks(them)));
  } else if (piece_type == PieceType::kPawn && to == state_.en_passant) {
    // pawn must be directly behind/in front of the attack square
    const BitBoard en_passant_pawn_mask = BitBoard::from_square(is_white ? to - 8 : to + 8);
    // mask of the position after the en passant capture
    const BitBoard en_passant_occupied_mask =
        state_.occupied() ^ en_passant_pawn_mask ^ BitBoard::from_square(from) ^ BitBoard::from_square(to);
    // verify that no sliding piece is attacking the king after the en passant capture
    return !move_gen::get_sliding_attackers_to(state_, king_square, en_passant_occupied_mask, them);
  }

  // if the king is double-checked, it can only evade check with a king move, which should've been handled earlier
  if (state_.checkers.more_than_one()) {
    return false;
  }

  // if the piece being moved is pinned, verify that it's moving on the same diagonal
  if (state_.pinned.is_set(from) && !(move_gen::ray_intersecting(from, to) & king_mask)) {
    return false;
  }

  if (!state_.checkers) {
    return true;
  }

  // only legal move left is to either take the piece that's causing check or block its path
  const auto checking_piece = Square(state_.checkers.get_lsb_pos());
  return (move_gen::ray_between(king_square, checking_piece) | BitBoard::from_square(checking_piece)).is_set(to);
}

void Board::make_move(Move move) {
  // create new board state
  history_.push(state_);

  const bool is_white = state_.turn == Color::kWhite;
  const auto from = move.get_from(), to = move.get_to();
  const auto piece_type = state_.get_piece_type(from);

  int new_fifty_move_clock = state_.fifty_moves_clock + 1;

  // xor out the previous turn hash and moved piece
  state_.zobrist_key ^= zobrist::hash_square(from, state_, state_.turn, piece_type) ^ zobrist::hash_turn(state_.turn);

  const auto captured_piece = state_.get_piece_type(to);
  if (captured_piece != PieceType::kNone) {
    state_.zobrist_key ^= zobrist::hash_square(to, state_, flip_color(state_.turn), captured_piece);
    state_.remove_piece(to);

    // reset fifty moves clock since this move was a capture
    new_fifty_move_clock = 0;
  }

  // used for zobrist hashing later
  bool move_is_double_push = false;

  if (piece_type == PieceType::kPawn) {
    new_fifty_move_clock = 0;

    // check if this was an en passant capture
    if (to == state_.en_passant) {
      // pawn must be directly behind/in front of the attack square
      const auto en_passant_pawn_pos = Square(is_white ? to - 8 : to + 8);

      // xor out the en passant captured pawn
      state_.zobrist_key ^=
          zobrist::hash_square(en_passant_pawn_pos, state_, flip_color(state_.turn), PieceType::kPawn);
      state_.remove_piece(en_passant_pawn_pos);

      // xor out the en passant pos
      state_.zobrist_key ^= zobrist::hash_en_passant(state_);
      state_.en_passant = Square::kNoSquare;
    } else {
      // setting en passant target if pawn moved two squares
      const int kDoublePushDist = 16;
      if ((from ^ to) == kDoublePushDist) {
        // xor out previous en passant square (if it exists)
        // we will xor in new en passant square after the turn has been updated
        state_.zobrist_key ^= zobrist::hash_en_passant(state_);

        // pawn must be directly behind/in front of the attack square
        const U8 en_passant_pawn_pos = is_white ? to - 8 : to + 8;
        state_.en_passant = Square(en_passant_pawn_pos);

        // keep track if this was a move that caused en passant to be set (for zobrist hashing)
        move_is_double_push = true;
      }
      // this move wasn't a double pawn push, so if ep square was set from the previous move, we xor it out
      else if (state_.en_passant != Square::kNoSquare) {
        state_.zobrist_key ^= zobrist::hash_en_passant(state_);
        state_.en_passant = Square::kNoSquare;
      }
    }
  }
  // if ep square was set from the previous move, we xor it out
  else if (state_.en_passant != Square::kNoSquare) {
    state_.zobrist_key ^= zobrist::hash_en_passant(state_);
    state_.en_passant = Square::kNoSquare;
  }

  handle_castling(move);

  // move the piece
  state_.remove_piece(from);
  state_.place_piece(to, piece_type, state_.turn);

  const auto promotion_type = move.get_promotion_type();
  if (piece_type == PieceType::kPawn && promotion_type != PromotionType::kNone) {
    handle_promotions(move);

    // xor in the promoted piece
    state_.zobrist_key ^= zobrist::hash_square(to, state_, state_.turn, PieceType(promotion_type));
  } else {
    // xor in the moved piece
    state_.zobrist_key ^= zobrist::hash_square(to, state_, state_.turn, piece_type);
  }

  // xor in new turn
  state_.turn = flip_color(state_.turn);
  state_.zobrist_key ^= zobrist::hash_turn(state_.turn);

  // xor en passant in now that the turn's have been switched (should only happen if this move wasn't an ep capture)
  // this is important since hash_en_passant checks if the opponents pawn is next to the double-pushed pawn
  if (move_is_double_push) {
    state_.zobrist_key ^= zobrist::hash_en_passant(state_);
  }

  state_.fifty_moves_clock = new_fifty_move_clock;
  state_.move_played = move;

  calculate_king_attacks();
}

void Board::undo_move() {
  state_ = history_.pop_back();
}

void Board::make_null_move() {
  // create new board state
  history_.push(state_);

  // xor out the previous turn hash
  state_.zobrist_key ^= zobrist::hash_turn(state_.turn);

  // xor out en passant if it exists
  if (state_.en_passant != Square::kNoSquare) {
    state_.zobrist_key ^= zobrist::hash_en_passant(state_);
    state_.en_passant = Square::kNoSquare;
  }

  // switch turn and xor in the new turn hash
  state_.turn = flip_color(state_.turn);
  state_.zobrist_key ^= zobrist::hash_turn(state_.turn);

  state_.fifty_moves_clock++;
  state_.move_played = Move::null_move();

  calculate_king_attacks();
}

U64 Board::key_after(Move move) {
  U64 key = state_.zobrist_key;
  key ^= zobrist::hash_turn(state_.turn) ^ zobrist::hash_turn(flip_color(state_.turn));

  // just swap sides
  if (move.is_null()) {
    return key;
  }

  const auto from = move.get_from();
  const auto to = move.get_to();
  const auto piece = state_.get_piece_type(from);

  // xor out from position
  key ^= zobrist::hash_square(from, state_, state_.turn, piece);

  const auto captured_piece = state_.get_piece_type(to);
  if (captured_piece != PieceType::kNone) {
    // xor out the captured piece
    key ^= zobrist::hash_square(to, state_, flip_color(state_.turn), captured_piece);
  }

  const auto promotion_type = move.get_promotion_type();
  if (piece == PieceType::kPawn && promotion_type != PromotionType::kNone) {
    // xor in the promoted piece
    key ^= zobrist::hash_square(to, state_, state_.turn, PieceType(promotion_type));
  } else {
    // xor in the moved piece
    key ^= zobrist::hash_square(to, state_, state_.turn, piece);
  }

  return key;
}

bool Board::has_repeated(int ply) {
  const int max_dist = std::min<int>(state_.fifty_moves_clock, history_.size());

  bool hit_before_root = false;
  for (int i = 4; i <= max_dist; i += 2) {
    if (state_.zobrist_key == history_[history_.size() - i].zobrist_key) {
      if (ply >= i) return true;
      if (hit_before_root) return true;
      hit_before_root = true;
    }
  }

  return false;
}

bool Board::is_draw(int ply) {
  if (state_.fifty_moves_clock >= 100 || has_repeated(ply)) {
    return true;
  }

  // insufficient material detection
  const Color us = state_.turn, them = flip_color(us);

  // check for queens, rooks, or pawns on the board
  if (state_.queens() || state_.rooks() || state_.pawns()) {
    return false;
  }

  // lone kings
  if (!state_.kingless_occupied()) {
    return true;
  }

  const BitBoard our_knights = state_.knights(us), their_knights = state_.knights(them);
  const BitBoard our_bishops = state_.bishops(us), their_bishops = state_.bishops(them);
  
  const BitBoard their_minor_pieces = their_knights | their_bishops;
  const BitBoard our_minor_pieces = our_knights | our_bishops;

  // more than one minor piece on either side
  if (their_minor_pieces.more_than_one() || our_minor_pieces.more_than_one()) {
    return false;
  }

  // lone king on one side and one minor piece on the other
  if (their_minor_pieces != 0 && state_.kingless_occupied(us) == 0 ||
      our_minor_pieces != 0 && state_.kingless_occupied(them) == 0) {
    return true;
  }

  // any other combination of pieces not covered by the above is not a draw
  return false;
}

void Board::handle_castling(Move move) {
  const bool is_white = state_.turn == Color::kWhite;

  const auto from = move.get_from(), to = move.get_to();
  const auto piece_type = state_.get_piece_type(from);

  const auto old_castle_rights = state_.castle_rights;

  if (piece_type == PieceType::kKing) {
    if (state_.castle_rights.can_kingside_castle(state_.turn) ||
        state_.castle_rights.can_queenside_castle(state_.turn)) {
      const auto move_rook_for_castling = [this](const Square &rook_from, const Square &rook_to) {
        // xor out the rook's previous square
        state_.zobrist_key ^= zobrist::hash_square(rook_from, state_, state_.turn, PieceType::kRook);

        state_.remove_piece(rook_from);
        state_.place_piece(rook_to, PieceType::kRook, state_.turn);

        // xor in the rook's new square
        state_.zobrist_key ^= zobrist::hash_square(rook_to, state_, state_.turn, PieceType::kRook);
      };

      const int kKingsideCastleDist = -2;
      const int kQueensideCastleDist = 2;

      // note: the only way move_dist is ever 2 or -2 is from move_gen::castling_moves allowing it
      const int move_dist = static_cast<int>(from) - static_cast<int>(to);
      if (move_dist == kKingsideCastleDist) {
        move_rook_for_castling(is_white ? Square::kH1 : Square::kH8, is_white ? Square::kF1 : Square::kF8);
      } else if (move_dist == kQueensideCastleDist) {
        move_rook_for_castling(is_white ? Square::kA1 : Square::kA8, is_white ? Square::kD1 : Square::kD8);
      }

      state_.castle_rights.set_both_rights(state_.turn, false);
    }
  }
  // handle rook moves changing castle rights
  else if (piece_type == PieceType::kRook && state_.castle_rights.can_castle(state_.turn)) {
    if (is_white) {
      if (from == Square::kH1) {
        state_.castle_rights.set_can_kingside_castle(state_.turn, false);
      } else if (from == Square::kA1) {
        state_.castle_rights.set_can_queenside_castle(state_.turn, false);
      }
    } else {
      if (from == Square::kH8) {
        state_.castle_rights.set_can_kingside_castle(state_.turn, false);
      } else if (from == Square::kA8) {
        state_.castle_rights.set_can_queenside_castle(state_.turn, false);
      }
    }
  }

  // handle rook getting captured changing castle rights
  auto their_kingside_rook = state_.castle_rights.get_kingside_rook(flip_color(state_.turn));
  auto their_queenside_rook = state_.castle_rights.get_queenside_rook(flip_color(state_.turn));

  if (to == their_kingside_rook) {
    state_.castle_rights.set_can_kingside_castle(flip_color(state_.turn), false);
  } else if (to == their_queenside_rook) {
    state_.castle_rights.set_can_queenside_castle(flip_color(state_.turn), false);
  }

  if (state_.castle_rights != old_castle_rights) {
    state_.zobrist_key ^= zobrist::hash_castle_rights(old_castle_rights);
    state_.zobrist_key ^= zobrist::hash_castle_rights(state_.castle_rights);
  }
}

void Board::handle_promotions(Move move) {
  const bool is_white = state_.turn == Color::kWhite;

  const auto to = move.get_to();
  const auto to_rank = rank(to);

  if ((is_white && to_rank == kNumRanks - 1) || (!is_white && to_rank == 0)) {
    state_.remove_piece(to);

    switch (move.get_promotion_type()) {
      case PromotionType::kKnight: {
        state_.place_piece(to, PieceType::kKnight, state_.turn);
        break;
      }
      case PromotionType::kBishop: {
        state_.place_piece(to, PieceType::kBishop, state_.turn);
        break;
      }
      case PromotionType::kRook: {
        state_.place_piece(to, PieceType::kRook, state_.turn);
        break;
      }
      case PromotionType::kAny:  // just choose a queen
      case PromotionType::kQueen: {
        state_.place_piece(to, PieceType::kQueen, state_.turn);
        break;
      }
      default:
        break;
    }
  }
}

void Board::calculate_king_attacks() {
  const Color us = state_.turn;
  const Color them = flip_color(us);

  const BitBoard our_pieces = state_.occupied(us);
  const BitBoard their_pieces = state_.occupied(them);

  const auto king_square = Square(state_.king(us).get_lsb_pos());

  // calculate the pieces that are attacking the king
  state_.checkers = move_gen::knight_moves(king_square) & state_.knights() |
                    move_gen::pawn_attacks(king_square, state_, us) & state_.pawns();
  state_.checkers &= their_pieces;

  // calculate our potentially pinned pieces
  state_.pinned = 0;

  // calculate all the opponent's pieces that could reach our king
  BitBoard x_raying_pieces = move_gen::get_sliding_attackers_to(state_, king_square, their_pieces, them);
  while (x_raying_pieces) {
    const auto square = Square(x_raying_pieces.pop_lsb());

    const BitBoard pinned = our_pieces & move_gen::ray_between(king_square, square);
    const int num_blockers = pinned.pop_count();
    if (!num_blockers) {
      state_.checkers |= BitBoard::from_square(square);
    } else if (num_blockers == 1) {
      // a piece is pinned if it's the only piece within a xray of an opponents piece to our king
      state_.pinned |= pinned;
    }
  }
}

void Board::print_pieces() {
  for (int rank = kNumRanks - 1; rank >= 0; rank--) {
    std::cout << rank + 1 << ' ';
    for (int file = 0; file < kNumFiles; file++) {
      const auto square = rank_file_to_square(rank, file);
      std::cout << fen::get_piece_char(const_cast<BoardState &>(state_), square);
      if (file < kNumFiles - 1) std::cout << " ";  // space separator for clarity
    }
    std::cout << std::endl;
  }
  std::cout << "  ";
  for (int file = 0; file < kNumFiles; file++) std::cout << static_cast<char>('a' + file) << ' ';
  std::cout << std::endl;
}