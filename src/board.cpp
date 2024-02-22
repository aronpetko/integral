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

void Board::handle_capturing(const Move &move, const std::unique_ptr<BoardState> &new_state) {
  const U8 to = move.get_to();

  const int opponent_start_bb = new_state->turn_to_move == Color::kWhite ? kBlackPawns : kWhitePawns;
  const int opponent_end_bb = new_state->turn_to_move == Color::kWhite ? kBlackPieces : kWhitePieces;

  // find which bitboard the captured piece belongs to and clear it
  for (int bb_idx = opponent_start_bb; bb_idx <= opponent_end_bb; bb_idx++) {
    BitBoard &piece_bb = new_state->pieces[bb_idx];

    if (piece_bb.is_set(to)) {
      piece_bb.clear_bit(to);
      break;
    }
  }
}

void Board::handle_castling(const Move &move, const std::unique_ptr<BoardState> &new_state) {
  const U8 from = move.get_from(), to = move.get_to();
  const auto piece_type = move.get_piece_type();

  // perform the castle
  if (piece_type == PieceType::kKing) {
    const int kKingsideCastleDist = -2;
    const int kQueensideCastleDist = 2;

    const auto move_rook_for_castling = [&new_state](Square rook_from, Square rook_to) {
      BitBoard &rooks_bb = new_state->pieces[new_state->turn_to_move == Color::kWhite ? kWhiteRooks : kBlackRooks];
      BitBoard &pieces_bb = new_state->pieces[new_state->turn_to_move == Color::kWhite ? kWhitePieces : kBlackPieces];

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
    new_state->castle_state &=
        new_state->turn_to_move == Color::kWhite ? ~CastleRights::kWhiteBothSides : ~CastleRights::kBlackBothSides;
  }
  // handle rook moves changing castle rights
  else if (piece_type == PieceType::kRook) {
    if (new_state->turn_to_move == Color::kWhite) {
      if (from == Square::kH1) {
        new_state->castle_state &= ~CastleRights::kWhiteKingside;
      } else if (from == Square::kA1) {
        new_state->castle_state &= ~CastleRights::kWhiteQueenside;
      }
    } else {
      if (from == Square::kH8) {
        new_state->castle_state &= ~CastleRights::kBlackKingside;
      } else if (from == Square::kA8) {
        new_state->castle_state &= ~CastleRights::kBlackQueenside;
      }
    }
  }
}

void Board::make_move(const Move &move, bool check_valid) {
  if (check_valid && !is_legal_move(move))
    return;

  const U8 from = move.get_from(), to = move.get_to();

  // create a new board state for history
  auto new_state = std::make_unique<BoardState>(*state_);

  // moving the piece
  const int start_bb = new_state->turn_to_move == Color::kWhite ? kWhitePawns : kBlackPawns;
  const int end_bb = new_state->turn_to_move == Color::kWhite ? kWhitePieces : kBlackPieces;

  for (int bb_idx = start_bb; bb_idx <= end_bb; bb_idx++) {
    BitBoard &piece_bb = new_state->pieces[bb_idx];

    // there should be only one piece on this square, so this should be safe
    if (piece_bb.is_set(from)) {
      piece_bb.clear_bit(from);
      piece_bb.set_bit(to);
    }
  }

  handle_capturing(move, new_state);
  handle_castling(move, new_state);

  // set the new board state data
  new_state->pieces[kAllPieces] = new_state->pieces[kWhitePieces] | new_state->pieces[kBlackPieces];

  new_state->turn_to_move = Color(!static_cast<bool>(new_state->turn_to_move));

  if (++new_state->half_moves % 2 == 0)
    new_state->full_moves++;

  new_state->prev_state = std::move(state_);
  state_ = std::move(new_state);
}

void Board::undo_move() {
  if (state_ && state_->prev_state) {
    state_ = std::move(state_->prev_state);
  } else {
    std::cerr << "no moves to undo" << std::endl;
  }
}