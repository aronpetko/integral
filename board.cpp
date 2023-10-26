#include "board.h"

void Board::make_move(Move move) {
  auto new_state = std::make_shared<BoardState>();
  std::memcpy(new_state.get(), state_.get(), sizeof(BoardState));

  U8 from = move.get_from(), to = move.get_to();

  int start_bb = new_state->turn_to_move == Color::kWhite ? kWhitePawns : kBlackPawns,
      end_bb = new_state->turn_to_move == Color::kWhite ? kWhitePieces : kBlackPieces;

  for (int bb_idx = start_bb; bb_idx < end_bb; bb_idx++) {
    BitBoard &piece_bb = new_state->pieces[bb_idx];

    // there should be only one piece on this square, so this is kind of safe
    if (piece_bb.is_set(from)) {
      piece_bb.clear_bit(from);
      piece_bb.set_bit(to);
      break;
    }
  }

  // update bitboards that track all of their pieces
  new_state->pieces[end_bb].move(from, to);
  new_state->pieces[kAllPieces].move(from, to);

  new_state->turn_to_move = Color(static_cast<bool>(new_state->turn_to_move));

  // simple linked list
  new_state->prev_state = state_;
  state_ = new_state;
}

void Board::undo_move() {
  state_ = state_->prev_state;
}