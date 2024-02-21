#include "board.h"
#include "move_gen.h"

static Color get_piece_color(BoardState *state, U8 pos) {
  if (!state)
    return {};

  return state->pieces[kWhitePieces].is_set(pos) ? Color::kWhite : Color::kBlack;
}

// todo: check if a move takes the king out of check
bool Board::is_valid_move(Move move) {
  U8 from = move.get_from(), to = move.get_to();

  // does a piece exist here?
  if (!state_->pieces[kAllPieces].is_set(from))
    return false;

  // check if the moved piece belongs to the current move's player
  if (!state_->pieces[state_->turn_to_move == Color::kWhite ? kWhitePieces : kBlackPieces].is_set(from))
    return false;

  BitBoard possible_moves;

  // pawns
  if (state_->pieces[kWhitePawns].is_set(from) || state_->pieces[kBlackPawns].is_set(from))
    possible_moves = generate_pawn_moves(from, state_);
  // knights
  else if (state_->pieces[kWhiteKnights].is_set(from) || state_->pieces[kBlackKnights].is_set(from))
    possible_moves = generate_knight_moves(from, state_);
  // bishops
  else if (state_->pieces[kWhiteBishops].is_set(from) || state_->pieces[kBlackBishops].is_set(from))
    possible_moves = generate_bishop_moves(from, state_);
  // rooks
  else if (state_->pieces[kWhiteRooks].is_set(from) || state_->pieces[kBlackRooks].is_set(from)) {
    possible_moves = generate_rook_moves(from, state_);

    /* switch (from) {
      case Square::kA1:state_->castle_state &= ~CastleBits::kWhiteQueenside;
        break;
      case Square::kH1:state_->castle_state &= ~CastleBits::kWhiteKingside;
        break;
      case Square::kA8:state_->castle_state &= ~CastleBits::kBlackQueenside;
        break;
      case Square::kH8:state_->castle_state &= ~CastleBits::kBlackKingside;
        break;
      default:break;
    } */
  }
  // queens
  else if (state_->pieces[kWhiteQueens].is_set(from) || state_->pieces[kBlackQueens].is_set(from))
    possible_moves = generate_bishop_moves(from, state_) | generate_rook_moves(from, state_);
  // king
  else if (state_->pieces[kWhiteKing].is_set(from) || state_->pieces[kBlackKing].is_set(from)) {
    possible_moves = generate_king_moves(from, state_);
    /*switch (from) {
      case Square::kE1:state_->castle_state &= ~(CastleBits::kWhiteKingside | CastleBits::kWhiteQueenside);
        break;
      case Square::kE8:state_->castle_state &= ~(CastleBits::kBlackKingside | CastleBits::kBlackQueenside);
        break;
      default:break;
    }*/
  }

  // does this move place/keep us in check?
  if (possible_moves.is_set(to)) {
    // now that we have made the move, the turn to move has flipped to the other side, so we flip it back to see if that king is in check
    make_move(move, false);
    bool in_check = king_in_check(Color(!static_cast<bool>(state_->turn_to_move)), state_);
    undo_move();

    return !in_check;
  }

  return false;
}

void Board::make_move(Move move, bool check_valid) {
  if (check_valid && !is_valid_move(move)) {
    std::cerr << "invalid move" << std::endl;
    return;
  }

  U8 from = move.get_from(), to = move.get_to();

  // create a new board state (for history)
  auto new_state = new BoardState;
  std::memcpy(new_state, state_, sizeof(BoardState));

  // moving the piece
  int start_bb = new_state->turn_to_move == Color::kWhite ? kWhitePawns : kBlackPawns;
  int end_bb = new_state->turn_to_move == Color::kWhite ? kWhitePieces : kBlackPieces;

  for (int bb_idx = start_bb; bb_idx <= end_bb; bb_idx++) {
    BitBoard &piece_bb = new_state->pieces[bb_idx];

    // there should be only one piece on this square, so this is kind of safe
    if (piece_bb.is_set(from)) {
      piece_bb.clear_bit(from);
      piece_bb.set_bit(to);
    }
  }

  // handle piece capture if it happened
  int opponent_start_bb = new_state->turn_to_move == Color::kWhite ? kBlackPawns : kWhitePawns;
  int opponent_end_bb = new_state->turn_to_move == Color::kWhite ? kBlackPieces : kWhitePieces;

  for (int bb_idx = opponent_start_bb; bb_idx <= opponent_end_bb; bb_idx++) {
    BitBoard &piece_bb = new_state->pieces[bb_idx];

    if (piece_bb.is_set(to))
      piece_bb.clear_bit(to);
  }

  // set all the new BoardState data
  new_state->pieces[kAllPieces] = new_state->pieces[kWhitePieces] | new_state->pieces[kBlackPieces];
  new_state->turn_to_move = Color(!static_cast<bool>(new_state->turn_to_move));

  new_state->half_moves++;
  if (new_state->half_moves % 2 == 0)
    new_state->full_moves++;

  // simple linked list
  new_state->prev_state = state_;
  state_ = new_state;
}

void Board::undo_move() {
  if (state_ && state_->prev_state) {
    auto temp = state_;
    state_ = state_->prev_state;
    delete temp;
  } else {
    std::cerr << "no moves to undo" << std::endl;
  }
}