#include "board.h"
#include "move_gen.h"

bool Board::is_legal_move(const Move &move) {
  const U8 from = move.get_from(), to = move.get_to();
  const bool is_white = state_->turn == Color::kWhite;

  // check if the moved piece belongs to the current move's player
  if (!state_->pieces[is_white ? kWhitePieces : kBlackPieces].is_set(from)) {
    std::cerr << "this piece doesn't belong to you" << std::endl;
    return false;
  }

  BitBoard &our_pieces = state_->pieces[is_white ? kWhitePieces : kBlackPieces];
  BitBoard &their_pieces = state_->pieces[is_white ? kBlackPieces : kWhitePieces];
  BitBoard possible_moves;

  switch (move.get_piece_type()) {
    case PieceType::kPawn: {
      const BitBoard en_passant_mask = state_->en_passant.has_value() ? BitBoard::from_square(state_->en_passant.value()) : BitBoard(0);
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
    case PieceType::kKing: possible_moves = generate_king_moves(from, state_);
      break;
    default:std::cerr << "this piece doesn't exist" << std::endl;
      return false;
  }

  const bool en_passant_set = state_->en_passant.has_value() && possible_moves.is_set(state_->en_passant.value());
  possible_moves &= ~our_pieces;
  if (en_passant_set) possible_moves.set_bit(state_->en_passant.value());

  if (possible_moves.is_set(to)) {
    // check if this move puts the king in check
    // now that we have made the move, the turn to move has flipped to the other side, so we flip it back to see if that king is in check
    make_move(move);
    bool in_check = king_in_check(Color(!state_->turn), state_);
    undo_move();

    if (in_check)
      std::cerr << "this move places you in check" << std::endl;
    return !in_check;
  }

  std::cerr << "this piece cant move here" << std::endl;
  return false;
}

void Board::make_move(const Move &move, bool perft, int perft_depth) {
  const U8 from = move.get_from(), to = move.get_to();
  const int from_rank = from / kBoardRanks, to_rank = to / kBoardRanks;

  // save current state before making changes
  history_.push_back(std::make_unique<BoardState>(*state_));

  // updating current move and piece position
  state_->move = move;

  const bool is_white = state_->turn == Color::kWhite;

  const int start_bb = is_white ? kWhitePawns : kBlackPawns;
  const int end_bb = is_white ? kWhitePieces : kBlackPieces;

  for (int bb_idx = start_bb; bb_idx <= end_bb; bb_idx++) {
    BitBoard &piece_bb = state_->pieces[bb_idx];
    if (piece_bb.is_set(from))
      piece_bb.move(from, to);
  }

  // perform a capture if possible
  const int opponent_start_bb = is_white ? kBlackPawns : kWhitePawns;
  const int opponent_end_bb = is_white ? kBlackPieces : kWhitePieces;

  // find which bitboards the captured piece belong to and clear it
  for (int bb_idx = opponent_start_bb; bb_idx <= opponent_end_bb; bb_idx++) {
    BitBoard &piece_bb = state_->pieces[bb_idx];
    if (piece_bb.is_set(to)) {
      // perft debugging
      if (perft && perft_depth == 1 && bb_idx != opponent_end_bb) {
        ++captures;
      }

      piece_bb.clear_bit(to);
    }
  }

  // en passant capture
  if (move.get_piece_type() == PieceType::kPawn && to == state_->en_passant) {
    // pawn must be directly behind/in front of the attack square
    const U8 en_passant_pawn_pos = is_white ? to - kBoardRanks : to + kBoardRanks;

    BitBoard &opposing_pawns = is_white ? state_->pieces[kBlackPawns] : state_->pieces[kWhitePawns];
    BitBoard &opposing_pieces = is_white ? state_->pieces[kBlackPieces] : state_->pieces[kWhitePieces];

    if (opposing_pawns.is_set(en_passant_pawn_pos)) {
      opposing_pawns.clear_bit(en_passant_pawn_pos);
      opposing_pieces.clear_bit(en_passant_pawn_pos);

      // perft debugging
      if (perft && perft_depth == 1) {
        ++en_passant_captures;
        ++captures;
      }
    } else {
      std::cerr << "en passant pawn does not exist" << std::endl;
      return;
    }
  }

  // setting en passant target if pawn moved two squares
  const int kEnPassantMoveDist = 2;
  if (move.get_piece_type() == PieceType::kPawn && abs(from_rank - to_rank) == kEnPassantMoveDist) {
    state_->en_passant = Square(rank_file_to_pos(to_rank + ((from_rank - to_rank) > 0 ? 1 : -1), to % kBoardFiles));
  } else {
    state_->en_passant = std::nullopt;
  }

  handle_castling(move, perft, perft_depth);
  handle_promotions(move, perft, perft_depth);

  // set the new board state data
  state_->pieces[kAllPieces] = state_->pieces[kWhitePieces] | state_->pieces[kBlackPieces];

  state_->turn = Color(!state_->turn);

  // perft debugging
  if (perft && perft_depth == 1 && king_in_check(state_->turn, state_)) {
    ++checks;
  }

  if (++state_->half_moves % 2 == 0)
    state_->full_moves++;
}

void Board::undo_move() {
  if (!history_.empty()) {
    state_ = std::move(history_.back());
    history_.pop_back();
  } else {
    std::cerr << "no moves to undo" << std::endl;
  }
}

void Board::handle_castling(const Move &move, bool perft, int perft_depth) {
  const U8 from = move.get_from(), to = move.get_to();
  const auto piece_type = move.get_piece_type();
  const bool is_white = state_->turn == Color::kWhite;

  // perform the castle
  if (piece_type == PieceType::kKing) {
    const int kKingsideCastleDist = -2;
    const int kQueensideCastleDist = 2;

    const auto move_rook_for_castling = [this, &is_white](Square rook_from, Square rook_to) {
      BitBoard &rooks_bb = state_->pieces[is_white ? kWhiteRooks : kBlackRooks];
      BitBoard &pieces_bb = state_->pieces[is_white ? kWhitePieces : kBlackPieces];

      rooks_bb.move(rook_from, rook_to);
      pieces_bb.move(rook_from, rook_to);
    };

    // note: the only way move_dist is ever 2 or -2 is from generate_castling_moves allowing it
    const int move_dist = static_cast<int>(from) - static_cast<int>(to);
    if (move_dist == kKingsideCastleDist) {
      move_rook_for_castling(is_white ? Square::kH1 : Square::kH8,
                             is_white ? Square::kF1 : Square::kF8);

      if (perft && perft_depth == 1)
        ++castles;
    } else if (move_dist == kQueensideCastleDist) {
      move_rook_for_castling(is_white ? Square::kA1 : Square::kA8,
                             is_white ? Square::kD1 : Square::kD8);

      if (perft && perft_depth == 1)
        ++castles;
    }

    state_->castle.set_can_kingside_castle(state_->turn, false);
    state_->castle.set_can_queenside_castle(state_->turn, false);
  }
    // handle rook moves changing castle rights
  else if (piece_type == PieceType::kRook) {
    if (is_white) {
      if (from == Square::kH1) {
        state_->castle.set_can_kingside_castle(state_->turn, false);
      } else if (from == Square::kA1) {
        state_->castle.set_can_queenside_castle(state_->turn, false);
      }
    } else {
      if (from == Square::kH8) {
        state_->castle.set_can_kingside_castle(state_->turn, false);
      } else if (from == Square::kA8) {
        state_->castle.set_can_queenside_castle(state_->turn, false);
      }
    }
  }
    // handle rook getting captured changing castle rights
  else {
    auto their_kingside_rook = state_->castle.get_kingside_rook(Color(!state_->turn));
    auto their_queenside_rook = state_->castle.get_queenside_rook(Color(!state_->turn));

    if (to == their_kingside_rook) {
      state_->castle.set_can_kingside_castle(Color(!state_->turn), false);
    } else if (to == their_queenside_rook) {
      state_->castle.set_can_queenside_castle(Color(!state_->turn), false);
    }
  }
}

void Board::handle_promotions(const Move &move, bool perft, int perft_depth) {
  const bool is_white = state_->turn == Color::kWhite;

  const auto piece_type = move.get_piece_type();
  if (piece_type != PieceType::kPawn)
    return;

  const U8 to = move.get_to();
  const U32 to_rank = to / 8;

  if (is_white) {
    if (to_rank == kBoardRanks - 1) {
      switch (move.get_promotion_type()) {
        case PromotionType::kKnight:state_->pieces[kWhiteKnights].set_bit(to);
          break;
        case PromotionType::kBishop:state_->pieces[kWhiteBishops].set_bit(to);
          break;
        case PromotionType::kRook:state_->pieces[kWhiteRooks].set_bit(to);
          break;
        case PromotionType::kAny: // just choose a queen
        case PromotionType::kQueen:state_->pieces[kWhiteQueens].set_bit(to);
          break;
        default:std::cerr << "invalid promotion type" << std::endl;
          return;
      }

      if (perft && perft_depth == 1)
        ++promotions;

      state_->pieces[kWhitePawns].clear_bit(to);
      state_->pieces[kWhitePieces].clear_bit(to);
      state_->pieces[kWhitePieces].set_bit(to);
    }
  } else {
    if (to_rank == 0) {
      switch (move.get_promotion_type()) {
        case PromotionType::kKnight:state_->pieces[kBlackKnights].set_bit(to);
          break;
        case PromotionType::kBishop:state_->pieces[kBlackBishops].set_bit(to);
          break;
        case PromotionType::kRook:state_->pieces[kBlackRooks].set_bit(to);
          break;
        case PromotionType::kAny: // just choose a queen
        case PromotionType::kQueen:state_->pieces[kBlackQueens].set_bit(to);
          break;
        default:std::cerr << "invalid promotion type" << std::endl;
          return;
      }

      if (perft && perft_depth == 1)
        ++promotions;

      state_->pieces[kBlackPawns].clear_bit(to);
      state_->pieces[kBlackPieces].clear_bit(to);
      state_->pieces[kBlackPieces].set_bit(to);
    }
  }
}