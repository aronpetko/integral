#include "board.h"
#include "move_gen.h"

bool Board::is_legal_move(const Move &move) {
  U8 from = move.get_from(), to = move.get_to();

  // check if the moved piece belongs to the current move's player
  if (!state_->pieces[state_->turn_to_move == Color::kWhite ? kWhitePieces : kBlackPieces].is_set(from)) {
    std::cerr << "this piece doesn't belong to you" << std::endl;
    return false;
  }

  BitBoard possible_moves;
  auto type = move.get_piece_type();

  if (type == PieceType::kPawn)
    possible_moves = generate_pawn_moves(from, state_);
  else if (type == PieceType::kKnight)
    possible_moves = generate_knight_moves(from, state_);
  else if (type == PieceType::kBishop)
    possible_moves = generate_bishop_moves(from, state_);
  else if (type == PieceType::kRook)
    possible_moves = generate_rook_moves(from, state_);
  else if (type == PieceType::kQueen)
    possible_moves = generate_bishop_moves(from, state_) | generate_rook_moves(from, state_);
  else if (type == PieceType::kKing)
    possible_moves = generate_king_moves(from, state_);


  // capturing your own pieces is illegal
  possible_moves &= ~state_->pieces[state_->turn_to_move == Color::kWhite ? kWhitePieces : kBlackPieces].as_u64();
  print_bb(possible_moves);

  if (possible_moves.is_set(to)) {
    // check if this move puts the king in check
    // now that we have made the move, the turn to move has flipped to the other side, so we flip it back to see if that king is in check
    make_move(move, false);
    bool in_check = king_in_check(Color(!static_cast<bool>(state_->turn_to_move)), state_);
    undo_move();

    if (in_check)
      std::cerr << "this move places you in check" << std::endl;
    return !in_check;
  }

  std::cerr << "this piece cant move here" << std::endl;
  return false;
}

void Board::handle_capturing(const Move &move) {
  const U8 to = move.get_to();

  const int opponent_start_bb = state_->turn_to_move == Color::kWhite ? kBlackPawns : kWhitePawns;
  const int opponent_end_bb = state_->turn_to_move == Color::kWhite ? kBlackPieces : kWhitePieces;

  // find which bitboards the captured piece belong to and clear it
  for (int bb_idx = opponent_start_bb; bb_idx <= opponent_end_bb; bb_idx++) {
    BitBoard &piece_bb = state_->pieces[bb_idx];
    if (piece_bb.is_set(to))
      piece_bb.clear_bit(to);
  }
}

void Board::handle_castling(const Move &move) {
  const U8 from = move.get_from(), to = move.get_to();
  const auto piece_type = move.get_piece_type();

  // perform the castle
  if (piece_type == PieceType::kKing) {
    const int kKingsideCastleDist = -2;
    const int kQueensideCastleDist = 2;

    const auto move_rook_for_castling = [this](Square rook_from, Square rook_to) {
      BitBoard &rooks_bb = state_->pieces[state_->turn_to_move == Color::kWhite ? kWhiteRooks : kBlackRooks];
      BitBoard &pieces_bb = state_->pieces[state_->turn_to_move == Color::kWhite ? kWhitePieces : kBlackPieces];

      rooks_bb.move(rook_from, rook_to);
      pieces_bb.move(rook_from, rook_to);
    };

    // note: the only way move_dist is ever 2 or -2 is from generate_castling_moves allowing it
    const int move_dist = static_cast<int>(from) - static_cast<int>(to);
    if (move_dist == kKingsideCastleDist) {
      move_rook_for_castling(state_->turn_to_move == Color::kWhite ? Square::kH1 : Square::kH8,
                             state_->turn_to_move == Color::kWhite ? Square::kF1 : Square::kF8);
    } else if (move_dist == kQueensideCastleDist) {
      move_rook_for_castling(state_->turn_to_move == Color::kWhite ? Square::kA1 : Square::kA8,
                             state_->turn_to_move == Color::kWhite ? Square::kD1 : Square::kD8);
    }

    // remove castling rights
    state_->castle_state &=
        state_->turn_to_move == Color::kWhite ? ~CastleRights::kWhiteBothSides : ~CastleRights::kBlackBothSides;
  }
  // handle rook moves changing castle rights
  else if (piece_type == PieceType::kRook) {
    if (state_->turn_to_move == Color::kWhite) {
      if (from == Square::kH1) {
        state_->castle_state &= ~CastleRights::kWhiteKingside;
      } else if (from == Square::kA1) {
        state_->castle_state &= ~CastleRights::kWhiteQueenside;
      }
    } else {
      if (from == Square::kH8) {
        state_->castle_state &= ~CastleRights::kBlackKingside;
      } else if (from == Square::kA8) {
        state_->castle_state &= ~CastleRights::kBlackQueenside;
      }
    }
  }
}

void Board::handle_promotions(const Move &move) {
  const auto piece_type = move.get_piece_type();
  if (piece_type != PieceType::kPawn)
    return;

  const U8 to = move.get_to();
  const U32 to_rank = to / 8;
  
  if (state_->turn_to_move == Color::kWhite) {
    if (to_rank == kBoardRanks - 1) {
      switch (move.get_promotion_type()) {
        case PromotionType::kKnight:
          state_->pieces[kWhiteKnights].set_bit(to);
          break;
        case PromotionType::kBishop:
          state_->pieces[kWhiteBishops].set_bit(to);
          break;
        case PromotionType::kRook:
          state_->pieces[kWhiteKnights].set_bit(to);
          break;
        case PromotionType::kQueen:
          state_->pieces[kWhiteQueens].set_bit(to);
          break;
        default:
          std::cerr << "invalid promotion type" << std::endl;
          return;
      }

      state_->pieces[kWhitePawns].clear_bit(to);
      state_->pieces[kWhitePieces].clear_bit(to);
      state_->pieces[kWhitePieces].set_bit(to);
    }
  } else {
    if (to_rank == 0) {
      switch (move.get_promotion_type()) {
        case PromotionType::kKnight:
          state_->pieces[kBlackKnights].set_bit(to);
          break;
        case PromotionType::kBishop:
          state_->pieces[kBlackBishops].set_bit(to);
          break;
        case PromotionType::kRook:
          state_->pieces[kBlackKnights].set_bit(to);
          break;
        case PromotionType::kQueen:
          state_->pieces[kBlackQueens].set_bit(to);
          break;
        default:
          std::cerr << "invalid promotion type" << std::endl;
          return;
      }

      state_->pieces[kBlackPawns].clear_bit(to);
      state_->pieces[kBlackPieces].clear_bit(to);
      state_->pieces[kBlackPieces].set_bit(to);
    }
  }
}

void Board::make_move(const Move &move, bool check_valid) {
  if (check_valid && !is_legal_move(move))
    return;

  const U8 from = move.get_from(), to = move.get_to();

  // save current state before making changes
  history_.push_back(std::make_unique<BoardState>(*state_));

  // moving the piece
  const int start_bb = state_->turn_to_move == Color::kWhite ? kWhitePawns : kBlackPawns;
  const int end_bb = state_->turn_to_move == Color::kWhite ? kWhitePieces : kBlackPieces;

  for (int bb_idx = start_bb; bb_idx <= end_bb; bb_idx++) {
    BitBoard &piece_bb = state_->pieces[bb_idx];
    if (piece_bb.is_set(from))
      piece_bb.move(from, to);
  }

  handle_capturing(move);
  handle_castling(move);
  handle_promotions(move);

  // set the new board state data
  state_->pieces[kAllPieces] = state_->pieces[kWhitePieces] | state_->pieces[kBlackPieces];

  state_->turn_to_move = Color(!static_cast<bool>(state_->turn_to_move));

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