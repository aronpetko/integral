#include "board.h"
#include "move.h"
#include "move_gen.h"

Board::Board(BoardState state, std::size_t transpo_table_size)
    : state_(std::move(state)),
      transpo_table_(transpo_table_size),
      history_count_(0),
      history_({}),
      key_history_({}),
      initialized_(true) {}

Board::Board() : history_count_(0), history_({}), key_history_({}), initialized_(false) {}

bool Board::is_legal_move(const Move &move) {
  const auto from = move.get_from(), to = move.get_to();

  BitBoard &our_pieces = state_.pieces[state_.turn][kAllPieces];
  BitBoard &their_pieces = state_.pieces[flip_color(state_.turn)][kAllPieces];

  // check if the moved piece belongs to the current move's player
  if (!our_pieces.is_set(from)) {
    std::cerr << "this piece doesn't belong to you" << std::endl;
    return false;
  }

  BitBoard possible_moves;

  switch (state_.piece_types[from]) {
    case PieceType::kPawn: {
      const BitBoard en_passant_mask = state_.en_passant.has_value() ? BitBoard::from_square(state_.en_passant.value()) : BitBoard(0);
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

  const bool en_passant_set = state_.en_passant.has_value() && possible_moves.is_set(state_.en_passant.value());
  possible_moves &= ~our_pieces;
  if (en_passant_set) possible_moves.set_bit(state_.en_passant.value());

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

  const bool is_white = state_.turn == Color::kWhite;
  const Color other_side = flip_color(state_.turn);

  const auto from = move.get_from(), to = move.get_to();
  const auto piece_type = state_.piece_types[from];

  // xor out the previous turn hash and moved piece
  state_.zobrist_key ^= zobrist::hash_square(from, state_) ^ zobrist::hash_turn(state_);

  BitBoard &our_pieces = state_.pieces[state_.turn][kAllPieces];
  BitBoard &their_pieces = state_.pieces[other_side][kAllPieces];

  if (state_.get_piece_type(to) != PieceType::kNone) {
    // capture handling
    state_.zobrist_key ^= zobrist::hash_square(to, state_);

    state_.pieces[other_side][kPawns].clear_bit(to);
    state_.pieces[other_side][kKnights].clear_bit(to);
    state_.pieces[other_side][kBishops].clear_bit(to);
    state_.pieces[other_side][kRooks].clear_bit(to);
    state_.pieces[other_side][kQueens].clear_bit(to);

    their_pieces.clear_bit(to);
    state_.piece_types[to] = PieceType::kNone;

    // reset fifty moves clock since this move was a capture
    state_.fifty_moves_clock = 0;
  }

  // used for zobrist hashing later
  bool move_is_double_push = false;

  if (piece_type == PieceType::kPawn) {
    // check if this was an en passant capture
    if (to == state_.en_passant) {
      // pawn must be directly behind/in front of the attack square
      const U8 en_passant_pawn_pos = is_white ? to - 8 : to + 8;

      BitBoard &opposing_pawns = state_.pieces[other_side][kPawns];
      if (opposing_pawns.is_set(en_passant_pawn_pos)) {
        // xor out the en passant captured pawn
        state_.zobrist_key ^= zobrist::hash_square(en_passant_pawn_pos, state_);

        opposing_pawns.clear_bit(en_passant_pawn_pos);
        their_pieces.clear_bit(en_passant_pawn_pos);
        state_.piece_types[en_passant_pawn_pos] = PieceType::kNone;

        // xor out the en passant pos
        state_.zobrist_key ^= zobrist::hash_en_passant(state_);
        state_.en_passant.reset();

        // reset fifty moves clock since this move was a capture
        state_.fifty_moves_clock = 0;
      } else {
        std::cout << move.to_string() << std::endl;
        print_pieces(state_.pieces);
        std::cerr << "en passant pawn does not exist" << std::endl;
        return;
      }
    } else {
      const int from_rank = rank(from);
      const int to_rank = rank(to);

      // setting en passant target if pawn moved two squares
      const int kDoublePushDist = 2;

      if (abs(from_rank - to_rank) == kDoublePushDist) {
        // xor out previous en passant square (if it exists)
        // we will xor in new en passant square after the turn has been updated
        state_.zobrist_key ^= zobrist::hash_en_passant(state_);
        state_.en_passant = Square(rank_file_to_pos(to_rank + ((from_rank - to_rank) > 0 ? 1 : -1), file(to)));

        // keep track if this was a move that caused en passant to be set (for zobrist hashing)
        move_is_double_push = true;
      }
      // this move wasn't a double pawn push, so if ep square was set from the previous move, we xor it out
      else if (state_.en_passant.has_value()) {
        state_.zobrist_key ^= zobrist::hash_en_passant(state_);
        state_.en_passant.reset();
      }
    }
  }
  // if ep square was set from the previous move, we xor it out
  else if (state_.en_passant.has_value()) {
    state_.zobrist_key ^= zobrist::hash_en_passant(state_);
    state_.en_passant.reset();
  }

  // move the piece
  BitBoard &piece_bb = state_.pieces[state_.turn][piece_type - 1];
  piece_bb.move(from, to);
  our_pieces.move(from, to);

  handle_castling(move);

  state_.piece_types[from] = PieceType::kNone;
  state_.piece_types[to] = piece_type;

  if (piece_type == PieceType::kPawn)
    handle_promotions(move);

  // xor in the moved piece
  state_.zobrist_key ^= zobrist::hash_square(to, state_);

  // xor in new turn
  state_.turn = flip_color(state_.turn);
  state_.zobrist_key ^= zobrist::hash_turn(state_);

  // xor en passant in now that the turn's have been switched (should only happen if this move wasn't an ep capture)
  // this is important since hash_en_passant checks if the opponents pawn is next to the double-pushed pawn
  if (move_is_double_push)
    state_.zobrist_key ^= zobrist::hash_en_passant(state_);

  ++state_.half_moves;
  ++state_.fifty_moves_clock;

  // update key history for repetition check
  key_history_[state_.half_moves] = state_.zobrist_key;
}

void Board::make_null_move() {
  // save previous board state
  history_[history_count_++] = state_;

  // xor out the previous turn hash
  state_.zobrist_key ^= zobrist::hash_turn(state_);

  // xor out en passant if it exists
  if (state_.en_passant.has_value()) {
    state_.zobrist_key ^= zobrist::hash_en_passant(state_);
    state_.en_passant.reset();
  }

  // switch turn and xor in the new turn hash
  state_.turn = Color(!state_.turn);
  state_.zobrist_key ^= zobrist::hash_turn(state_);
}

void Board::undo_move() {
  state_ = history_[--history_count_];
  key_history_[state_.half_moves] = 0;
}

bool Board::has_repeated(U8 times) const {
  // we know that the position can be repeated if no moves were captured, hence we only search until the fifty moves clock was reset
  for (int i = state_.half_moves - 1; i >= state_.half_moves - state_.fifty_moves_clock && i >= 0; i--) {
    if (key_history_[i] == state_.zobrist_key && --times == 0) {
      return true;
    }
  }
  return false;
}

void Board::handle_castling(const Move &move) {
  // xor out old castle rights
  state_.zobrist_key ^= zobrist::hash_castle_rights(state_);

  const bool is_white = state_.turn == Color::kWhite;

  const auto from = move.get_from(), to = move.get_to();
  const auto piece_type = state_.piece_types[from];

  if (piece_type == PieceType::kKing) {
    if (state_.castle.can_kingside_castle(state_.turn) || state_.castle.can_queenside_castle(state_.turn)) {
      const auto move_rook_for_castling = [this](Square rook_from, Square rook_to) {
        BitBoard &rooks_bb = state_.pieces[state_.turn][kRooks];
        BitBoard &pieces_bb = state_.pieces[state_.turn][kAllPieces];

        // xor out the rook's previous square
        state_.zobrist_key ^= zobrist::hash_square(rook_from, state_);

        rooks_bb.move(rook_from, rook_to);
        pieces_bb.move(rook_from, rook_to);
        state_.piece_types[rook_from] = PieceType::kNone;
        state_.piece_types[rook_to] = PieceType::kRook;

        // xor in the rook's new square
        state_.zobrist_key ^= zobrist::hash_square(rook_to, state_);
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

      state_.castle.set_can_kingside_castle(state_.turn, false);
      state_.castle.set_can_queenside_castle(state_.turn, false);
    }
  }
  // handle rook moves changing castle rights
  else if (piece_type == PieceType::kRook) {
    if (is_white) {
      if (from == Square::kH1) {
        state_.castle.set_can_kingside_castle(state_.turn, false);
      } else if (from == Square::kA1) {
        state_.castle.set_can_queenside_castle(state_.turn, false);
      }
    } else {
      if (from == Square::kH8) {
        state_.castle.set_can_kingside_castle(state_.turn, false);
      } else if (from == Square::kA8) {
        state_.castle.set_can_queenside_castle(state_.turn, false);
      }
    }
  }
  // handle rook getting captured changing castle rights
  else {
    auto their_kingside_rook = state_.castle.get_kingside_rook(flip_color(state_.turn));
    auto their_queenside_rook = state_.castle.get_queenside_rook(flip_color(state_.turn));

    if (to == their_kingside_rook) {
      state_.castle.set_can_kingside_castle(flip_color(state_.turn), false);
    } else if (to == their_queenside_rook) {
      state_.castle.set_can_queenside_castle(flip_color(state_.turn), false);
    }
  }

  // xor in new castle rights
  state_.zobrist_key ^= zobrist::hash_castle_rights(state_);
}

void Board::handle_promotions(const Move &move) {
  const bool is_white = state_.turn == Color::kWhite;

  const auto to = move.get_to();
  const auto to_rank = rank(to);

  if ((is_white && to_rank == kBoardRanks - 1) || (!is_white && to_rank == 0)) {
    switch (move.get_promotion_type()) {
      case PromotionType::kKnight: {
        state_.pieces[state_.turn][kKnights].set_bit(to);
        state_.piece_types[to] = PieceType::kKnight;
        break;
      }
      case PromotionType::kBishop: {
        state_.pieces[state_.turn][kBishops].set_bit(to);
        state_.piece_types[to] = PieceType::kBishop;
        break;
      }
      case PromotionType::kRook: {
        state_.pieces[state_.turn][kRooks].set_bit(to);
        state_.piece_types[to] = PieceType::kRook;
        break;
      }
      case PromotionType::kAny: // just choose a queen
      case PromotionType::kQueen: {
        state_.pieces[state_.turn][kQueens].set_bit(to);
        state_.piece_types[to] = PieceType::kQueen;
        break;
      }
      default:
        break;
    }

    // xor out the promoted pawn
    state_.zobrist_key ^= zobrist::hash_square(to, state_);

    state_.pieces[state_.turn][kPawns].clear_bit(to);
    state_.pieces[state_.turn][kAllPieces].set_bit(to);

    // xor in the promoted piece
    state_.zobrist_key ^= zobrist::hash_square(to, state_);
  }
}