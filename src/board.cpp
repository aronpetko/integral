#include "board.h"
#include "move.h"
#include "move_gen.h"
#include "fen.h"
#include "eval.h"

Board::Board(std::size_t transpo_table_size)
    : transpo_table_(transpo_table_size),
      history_count_(0),
      key_history_count_(0),
      history_({}),
      key_history_({}) {}

Board::Board() : key_history_count_(0), history_count_(0), history_({}), key_history_({}), initialized_(false) {}

void Board::set_from_fen(const std::string &fen_str) {
  // reset history everytime we parse from fen, since they will be re-applied when the moves are made
  key_history_count_ = 0;
  history_count_ = 0;

  key_history_.fill(0);
  history_.fill(BoardState{});

  state_ = fen::string_to_board(fen_str);
  initialized_ = true;
}

bool Board::is_legal_move(const Move &move) {
  const auto from = move.get_from(), to = move.get_to();

  BitBoard our_pieces = state_.occupied(state_.turn);
  BitBoard their_pieces = state_.occupied(flip_color(state_.turn));

  // check if the moved piece belongs to the current move's player
  if (!our_pieces.is_set(from)) {
    std::cerr << "this piece doesn't belong to you" << std::endl;
    return false;
  }

  BitBoard possible_moves;

  switch (state_.get_piece_type(from)) {
    case PieceType::kPawn: {
      const BitBoard en_passant_mask = state_.en_passant != Square::kNoSquare ? BitBoard::from_square(state_.en_passant) : BitBoard(0);
      possible_moves = generate_pawn_moves(from, state_) | (generate_pawn_attacks(from, state_) & (their_pieces | en_passant_mask));
      break;
    }
    case PieceType::kKnight: possible_moves = generate_knight_moves(from, state_);
      break;
    case PieceType::kBishop: possible_moves = generate_bishop_moves(from, state_);
      break;
    case PieceType::kRook: possible_moves = generate_rook_moves(from, state_);
      break;
    case PieceType::kQueen: possible_moves = generate_bishop_moves(from, state_) | generate_rook_moves(from, state_);
      break;
    case PieceType::kKing: possible_moves = generate_king_moves(from, state_, true);
      break;
    default: std::cerr << "this piece doesn't exist" << std::endl;
      return false;
  }

  const bool en_passant_set = state_.en_passant != Square::kNoSquare && possible_moves.is_set(state_.en_passant);
  possible_moves &= ~our_pieces;
  if (en_passant_set) possible_moves.set_bit(state_.en_passant);

  if (possible_moves.is_set(to)) {
    // check if this move puts the king in check
    // now that we have made the move, the turn to move has flipped to the other side, so we flip it back to see if that king is in check
    make_move(move);
    bool in_check = king_in_check(flip_color(state_.turn), state_);
    undo_move();

    if (in_check)
      std::cerr << "this move places you in check" << std::endl;
    return !in_check;
  }

  std::cerr << "this piece cant move here" << std::endl;
  return false;
}

void Board::make_move(const Move &move) {
  // save previous board state
  history_[history_count_++] = state_;

  // update key history for repetition check
  key_history_[key_history_count_++] = state_.zobrist_key;

  const bool is_white = state_.turn == Color::kWhite;
  const auto from = move.get_from(), to = move.get_to();
  const auto piece_type = state_.get_piece_type(from);

  int new_fifty_move_clock = state_.fifty_moves_clock + 1;

  // xor out the previous turn hash and moved piece
  state_.zobrist_key ^= zobrist::hash_square(from, state_, state_.turn, piece_type) ^ zobrist::hash_turn(state_);

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

  if (piece_type == PieceType::kPawn && move.get_promotion_type() != PromotionType::kNone) {
    handle_promotions(move);
  }

  // xor in the moved piece
  state_.zobrist_key ^= zobrist::hash_square(to, state_, state_.turn, piece_type);

  // xor in new turn
  state_.turn = flip_color(state_.turn);
  state_.zobrist_key ^= zobrist::hash_turn(state_);

  // xor en passant in now that the turn's have been switched (should only happen if this move wasn't an ep capture)
  // this is important since hash_en_passant checks if the opponents pawn is next to the double-pushed pawn
  if (move_is_double_push)
    state_.zobrist_key ^= zobrist::hash_en_passant(state_);

  state_.fifty_moves_clock = new_fifty_move_clock;
}

void Board::undo_move() {
  state_ = history_[--history_count_];
  key_history_count_--;
}

void Board::make_null_move() {
  // save previous board state
  history_[history_count_++] = state_;

  // save previous board state
  key_history_[key_history_count_++] = state_.zobrist_key;

  // xor out the previous turn hash
  state_.zobrist_key ^= zobrist::hash_turn(state_);

  // xor out en passant if it exists
  if (state_.en_passant != Square::kNoSquare) {
    state_.zobrist_key ^= zobrist::hash_en_passant(state_);
    state_.en_passant = Square::kNoSquare;
  }

  // switch turn and xor in the new turn hash
  state_.turn = flip_color(state_.turn);
  state_.zobrist_key ^= zobrist::hash_turn(state_);
}

bool Board::has_repeated(U8 times) const {
  // we know that the position can be repeated if no moves were captured, hence we only search until the fifty moves clock was reset
  for (int i = key_history_count_ - 1; i >= key_history_count_ - state_.fifty_moves_clock && i >= 0; i--) {
    if (key_history_[i] == state_.zobrist_key && --times == 0) {
      return true;
    }
  }
  return false;
}

bool Board::is_draw() const {
  if (state_.fifty_moves_clock >= 100 || has_repeated(1)) {
    return true;
  }

  // insufficient material
  const int white_pawns = state_.pawns(Color::kWhite).pop_count();
  const int white_knights = state_.knights(Color::kWhite).pop_count();
  const int white_bishops = state_.bishops(Color::kWhite).pop_count();
  const int white_rooks = state_.rooks(Color::kWhite).pop_count();
  const int white_queens = state_.queens(Color::kWhite).pop_count();

  const int black_pawns = state_.pawns(Color::kBlack).pop_count();
  const int black_knights = state_.knights(Color::kBlack).pop_count();
  const int black_bishops = state_.bishops(Color::kBlack).pop_count();
  const int black_rooks = state_.rooks(Color::kBlack).pop_count();
  const int black_queens = state_.queens(Color::kBlack).pop_count();

  bool white_insufficient = false;
  if (white_pawns == 0 && white_rooks == 0 && white_queens == 0) {
    if ((white_bishops == 0 && white_knights <= 1) ||
        (white_knights == 0 && white_bishops <= 1)) {
      white_insufficient = true;
    }
  }

  bool black_insufficient = false;
  if (black_pawns == 0 && black_rooks == 0 && black_queens == 0) {
    if ((black_bishops == 0 && black_knights <= 1) ||
        (black_knights == 0 && black_bishops <= 1)) {
      black_insufficient = true;
    }
  }

  return white_insufficient && black_insufficient;
}

void Board::handle_castling(const Move &move) {
  const bool is_white = state_.turn == Color::kWhite;

  const auto from = move.get_from(), to = move.get_to();
  const auto piece_type = state_.get_piece_type(from);

  const auto &old_rights = state_.castle_rights;

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

      // note: the only way move_dist is ever 2 or -2 is from generate_castling_moves allowing it
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
  else if (piece_type == PieceType::kRook) {
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

  if (old_rights != state_.castle_rights) {
    state_.zobrist_key ^= zobrist::hash_castle_rights(old_rights);
    state_.zobrist_key ^= zobrist::hash_castle_rights(state_.castle_rights);
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