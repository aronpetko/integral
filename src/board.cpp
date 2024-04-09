#include "board.h"
#include "move.h"
#include "move_gen.h"
#include "fen.h"
#include "eval.h"

Board::Board(std::size_t transpo_table_size)
    : transpo_table_(transpo_table_size),
      history_count_(0),
      history_({}) {}

Board::Board() : history_count_(0), history_({}), initialized_(false) {}

void Board::set_from_fen(const std::string &fen_str) {
  // reset history everytime we parse from fen, since they will be re-applied when the moves are made
  history_count_ = 0;

  state_ = fen::string_to_board(fen_str);
  initialized_ = true;
}

bool Board::is_move_pseudo_legal(const Move &move) {
  const auto from = move.get_from(), to = move.get_to();

  const BitBoard &our_pieces = state_.occupied(state_.turn);
  if (!our_pieces.is_set(from)) {
    return false;
  }

  const BitBoard &their_pieces = state_.occupied(flip_color(state_.turn));
  const BitBoard occupied = our_pieces | their_pieces;

  BitBoard possible_moves;

  switch (state_.get_piece_type(from)) {
    case PieceType::kPawn: {
      const BitBoard en_passant_mask = state_.en_passant != Square::kNoSquare ? BitBoard::from_square(state_.en_passant) : BitBoard(0);
      possible_moves = move_gen::pawn_moves(from, state_) | (move_gen::pawn_attacks(from, state_) & (their_pieces | en_passant_mask));
      break;
    }
    case PieceType::kKnight: possible_moves = move_gen::knight_moves(from);
      break;
    case PieceType::kBishop: possible_moves = move_gen::bishop_moves(from, occupied);
      break;
    case PieceType::kRook: possible_moves = move_gen::rook_moves(from, occupied);
      break;
    case PieceType::kQueen: possible_moves = move_gen::bishop_moves(from, occupied) | move_gen::rook_moves(from, occupied);
      break;
    case PieceType::kKing: possible_moves = move_gen::king_moves(from, state_);
      break;
    default:
      return false;
  }

  const bool en_passant_set = state_.en_passant != Square::kNoSquare && possible_moves.is_set(state_.en_passant);
  possible_moves &= ~our_pieces;
  if (en_passant_set) possible_moves.set_bit(state_.en_passant);

  return possible_moves.is_set(to);
}

void Board::make_move(const Move &move) {
  // save previous board state
  history_[history_count_++] = state_;

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
      const U8 en_passant_pawn_pos = is_white ? to - 8 : to + 8;

      // xor out the en passant captured pawn
      state_.zobrist_key ^= zobrist::hash_square(en_passant_pawn_pos, state_, flip_color(state_.turn), PieceType::kPawn);
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
}

void Board::undo_move() {
  state_ = history_[--history_count_];
}

void Board::make_null_move() {
  // save previous board state
  history_[history_count_++] = state_;

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
}

U64 Board::key_after(const Move &move) const {
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
    key ^= zobrist::hash_square(to, state_, state_.turn, captured_piece);
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

bool Board::has_repeated(U8 times) const {
  // we know that the position can be repeated if no moves were captured, hence we only search until the fifty moves clock was reset
  for (int i = history_count_ - 2; i >= history_count_ - state_.fifty_moves_clock && i >= 0; i -= 2) {
    if (history_[i].zobrist_key == state_.zobrist_key && --times == 0) {
      return true;
    }
  }
  return false;
}

bool Board::is_draw() const {
  if (state_.fifty_moves_clock >= 100 || has_repeated(2)) {
    return true;
  }

  // insufficient material checks
  return !((state_.pawns() | state_.rooks() | state_.queens()) ||
      (state_.occupied(Color::kWhite).pop_count() > 1 && state_.occupied(Color::kBlack).pop_count() > 1) ||
      ((state_.knights() | state_.bishops()).pop_count() > 1) ||
      (state_.bishops() == 0) ||
      (state_.knights().pop_count() < 3));
}

void Board::handle_castling(const Move &move) {
  const bool is_white = state_.turn == Color::kWhite;

  const auto from = move.get_from(), to = move.get_to();
  const auto piece_type = state_.get_piece_type(from);

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
        move_rook_for_castling(is_white ? Square::kH1 : Square::kH8,
                               is_white ? Square::kF1 : Square::kF8);
      } else if (move_dist == kQueensideCastleDist) {
        move_rook_for_castling(is_white ? Square::kA1 : Square::kA8,
                               is_white ? Square::kD1 : Square::kD8);
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
}

void Board::handle_promotions(const Move &move) {
  const bool is_white = state_.turn == Color::kWhite;

  const auto to = move.get_to();
  const auto to_rank = rank(to);

  if ((is_white && to_rank == kBoardRanks - 1) || (!is_white && to_rank == 0)) {
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
      case PromotionType::kAny: // just choose a queen
      case PromotionType::kQueen: {
        state_.place_piece(to, PieceType::kQueen, state_.turn);
        break;
      }
      default:
        break;
    }
  }
}

void Board::print_pieces() const {
  for (int rank = kBoardRanks - 1; rank >= 0; rank--) {
    std::cout << rank + 1 << ' ';
    for (int file = 0; file < kBoardFiles; file++) {
      U8 square = rank_file_to_pos(rank, file);
      std::cout << fen::get_piece_char(const_cast<BoardState&>(state_), square);
      if (file < kBoardFiles - 1)
        std::cout << " ";  // space separator for clarity
    }
    std::cout << std::endl;
  }
  std::cout << "  ";
  for (int file = 0; file < kBoardFiles; file++)
    std::cout << static_cast<char>('a' + file) << ' ';
  std::cout << std::endl;
}