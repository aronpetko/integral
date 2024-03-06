#include "board.h"
#include "move_gen.h"

bool Board::is_legal_move(const Move &move) {
  const U8 from = move.get_from(), to = move.get_to();
  const bool is_white = state_.turn == Color::kWhite;

  // check if the moved piece belongs to the current move's player
  if (!state_.pieces[is_white ? kWhitePieces : kBlackPieces].is_set(from)) {
    std::cerr << "this piece doesn't belong to you" << std::endl;
    return false;
  }

  BitBoard &our_pieces = state_.pieces[is_white ? kWhitePieces : kBlackPieces];
  BitBoard &their_pieces = state_.pieces[is_white ? kBlackPieces : kWhitePieces];
  BitBoard possible_moves;

  switch (move.get_piece_type()) {
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
    bool in_check = king_in_check(Color(!state_.turn), state_);
    undo_move();

    //if (in_check)
    //  std::cerr << "this move places you in check" << std::endl;
    return !in_check;
  }

  std::cerr << "this piece cant move here" << std::endl;
  return false;
}

void Board::make_move(const Move &move, bool perft, int perft_depth) {
  BoardState new_state = state_;

  const bool is_white = new_state.turn == Color::kWhite;

  const U8 from = move.get_from(), to = move.get_to();
  const auto piece_type = move.get_piece_type();

  // xor out the previous turn hash and moved piece
  new_state.zobrist_key ^= zobrist::hash_square(from, new_state);
  new_state.zobrist_key ^= zobrist::hash_turn(new_state);

  BitBoard &our_pieces = new_state.pieces[is_white ? kWhitePieces : kBlackPieces];
  BitBoard &their_pieces = new_state.pieces[is_white ? kBlackPieces : kWhitePieces];
  BitBoard &all_pieces = new_state.pieces[kAllPieces];

  // perform a capture if possible
  const int opponent_start_bb = is_white ? kBlackPawns : kWhitePawns;
  const int opponent_end_bb = is_white ? kBlackKing : kWhiteKing;

  // find which bitboards the captured piece belong to and clear it
  for (int bb_idx = opponent_start_bb; bb_idx <= opponent_end_bb; bb_idx++) {
    BitBoard &captured_piece_bb = new_state.pieces[bb_idx];
    if (captured_piece_bb.is_set(to)) {
      // perft debugging
      if (perft && perft_depth == 1) {
        ++captures;
      }

      // xor out this piece
      new_state.zobrist_key ^= zobrist::hash_square(to, new_state);

      captured_piece_bb.clear_bit(to);
      their_pieces.clear_bit(to);
      all_pieces.clear_bit(to);
      break;
    }
  }

  // en passant capture
  if (piece_type == PieceType::kPawn && to == new_state.en_passant) {
    // pawn must be directly behind/in front of the attack square
    const U8 en_passant_pawn_pos = is_white ? to - 8 : to + 8;

    BitBoard &opposing_pawns = is_white ? new_state.pieces[kBlackPawns] : new_state.pieces[kWhitePawns];
    BitBoard &opposing_pieces = is_white ? new_state.pieces[kBlackPieces] : new_state.pieces[kWhitePieces];

    if (opposing_pawns.is_set(en_passant_pawn_pos)) {
      // xor out the en passant captured pawn
      new_state.zobrist_key ^= zobrist::hash_square(en_passant_pawn_pos, new_state);

      opposing_pawns.clear_bit(en_passant_pawn_pos);
      opposing_pieces.clear_bit(en_passant_pawn_pos);
      all_pieces.clear_bit(en_passant_pawn_pos);

      // xor out the en passant pos
      new_state.zobrist_key ^= zobrist::hash_en_passant(new_state);
      new_state.en_passant.reset();

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

  const int from_rank = from / kBoardRanks;
  const int to_rank = to / kBoardRanks;

  // setting en passant target if pawn moved two squares
  const int kDoublePushDist = 2;
  bool move_is_double_push = false;
  if (move.get_piece_type() == PieceType::kPawn && abs(from_rank - to_rank) == kDoublePushDist) {
    // xor out previous en passant square (if it exists)
    // we will xor in new en passant square after the turn has been updated
    new_state.zobrist_key ^= zobrist::hash_en_passant(new_state);
    new_state.en_passant = Square(rank_file_to_pos(to_rank + ((from_rank - to_rank) > 0 ? 1 : -1), to % kBoardFiles));

    // keep track if this was a move that caused en passant to be set (for zobrist hashing)
    move_is_double_push = true;
  }
  // this move wasn't a double pawn push, so if ep square was set from the previous move, we xor it out
  else if (new_state.en_passant.has_value()) {
    new_state.zobrist_key ^= zobrist::hash_en_passant(new_state);
    new_state.en_passant.reset();
  }

  BitBoard &piece_bb = new_state.pieces[is_white ? static_cast<int>(piece_type) - 1 : static_cast<int>(piece_type) - 1 + kBlackPawns];
  piece_bb.move(from, to);
  our_pieces.move(from, to);
  all_pieces.move(from, to);

  // xor in the moved piece
  new_state.zobrist_key ^= zobrist::hash_square(to, new_state);

  handle_castling(move, new_state, perft, perft_depth);
  handle_promotions(move, new_state, perft, perft_depth);

  // set the new board state data
  new_state.pieces[kAllPieces] = new_state.pieces[kWhitePieces] | new_state.pieces[kBlackPieces];

  new_state.turn = Color(!new_state.turn);
  // auto correct_zobrist = zobrist::generate_key(new_state);

  new_state.zobrist_key ^= zobrist::hash_turn(new_state);

  // xor en passant in now that the turn's have been switched (should only happen this move wasn't an ep capture)
  // this is important since hash_en_passant checks if the opponents pawn is next to the double-pushed pawn
  if (move_is_double_push) {
    new_state.zobrist_key ^= zobrist::hash_en_passant(new_state);
  }

  // perft debugging
  //if (perft && perft_depth == 1 && king_in_check(new_state.turn, new_state)) {
  //  ++checks;
  //}

  if (++new_state.half_moves % 2 == 0)
    new_state.full_moves++;

  // save this updated board state
  history_.push_back(state_);
  state_ = new_state;
}

void Board::make_null_move() {
  BoardState new_state = state_;

  // xor out the previous turn hash
  new_state.zobrist_key ^= zobrist::hash_turn(new_state);

  // xor out en passant if it exists
  if (new_state.en_passant.has_value()) {
    new_state.zobrist_key ^= zobrist::hash_en_passant(new_state);
    new_state.en_passant.reset();
  }

  if (++new_state.half_moves % 2 == 0)
    new_state.full_moves++;

  // switch turn and xor in the new turn hash
  new_state.turn = Color(!new_state.turn);
  new_state.zobrist_key ^= zobrist::hash_turn(new_state);

  // save this updated board state
  history_.push_back(state_);
  state_ = new_state;
}

void Board::undo_move() {
  if (!history_.empty()) {
    state_ = history_.back();
    history_.pop_back();
  } else {
    std::cerr << "no moves to undo" << std::endl;
  }
}

void Board::handle_castling(const Move &move, BoardState &state, bool perft, int perft_depth) {
  // xor out previous castle rights
  state.zobrist_key ^= zobrist::hash_castle_rights(state);

  const U8 from = move.get_from(), to = move.get_to();
  const bool is_white = state.turn == Color::kWhite;
  const auto piece_type = move.get_piece_type();

  if (piece_type == PieceType::kKing) {
    const auto move_rook_for_castling = [&state, &is_white](Square rook_from, Square rook_to) {
      BitBoard &rooks_bb = state.pieces[is_white ? kWhiteRooks : kBlackRooks];
      BitBoard &pieces_bb = state.pieces[is_white ? kWhitePieces : kBlackPieces];
      BitBoard &all_pieces_bb = state.pieces[kAllPieces];

      // xor out the rook's previous square, xor in the rook's new square
      state.zobrist_key ^= zobrist::hash_square(rook_from, state);
      rooks_bb.move(rook_from, rook_to);
      pieces_bb.move(rook_from, rook_to);
      all_pieces_bb.move(rook_from, rook_to);
      state.zobrist_key ^= zobrist::hash_square(rook_to, state);
    };

    const int kKingsideCastleDist = -2;
    const int kQueensideCastleDist = 2;

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

    state.castle.set_can_kingside_castle(state.turn, false);
    state.castle.set_can_queenside_castle(state.turn, false);
  }
  // handle rook moves changing castle rights
  else if (piece_type == PieceType::kRook) {
    if (is_white) {
      if (from == Square::kH1) {
        state.castle.set_can_kingside_castle(state.turn, false);
      } else if (from == Square::kA1) {
        state.castle.set_can_queenside_castle(state.turn, false);
      }
    } else {
      if (from == Square::kH8) {
        state.castle.set_can_kingside_castle(state.turn, false);
      } else if (from == Square::kA8) {
        state.castle.set_can_queenside_castle(state.turn, false);
      }
    }
  }
  // handle rook getting captured changing castle rights
  else {
    auto their_kingside_rook = state.castle.get_kingside_rook(Color(!state.turn));
    auto their_queenside_rook = state.castle.get_queenside_rook(Color(!state.turn));

    if (to == their_kingside_rook) {
      state.castle.set_can_kingside_castle(Color(!state.turn), false);
    } else if (to == their_queenside_rook) {
      state.castle.set_can_queenside_castle(Color(!state.turn), false);
    }
  }

  // xor out previous castle rights
  state.zobrist_key ^= zobrist::hash_castle_rights(state);
}

void Board::handle_promotions(const Move &move, BoardState &state, bool perft, int perft_depth) {
  const bool is_white = state.turn == Color::kWhite;

  const auto piece_type = move.get_piece_type();
  if (piece_type != PieceType::kPawn)
    return;

  const U8 to = move.get_to();
  const U32 to_rank = to / kBoardRanks;

  if (is_white) {
    if (to_rank == kBoardRanks - 1) {
      switch (move.get_promotion_type()) {
        case PromotionType::kKnight:state.pieces[kWhiteKnights].set_bit(to);
          break;
        case PromotionType::kBishop:state.pieces[kWhiteBishops].set_bit(to);
          break;
        case PromotionType::kRook:state.pieces[kWhiteRooks].set_bit(to);
          break;
        case PromotionType::kAny: // just choose a queen
        case PromotionType::kQueen:state.pieces[kWhiteQueens].set_bit(to);
          break;
        default:
          break;
      }

      if (perft && perft_depth == 1)
        ++promotions;

      // xor out the promoted pawn
      state.zobrist_key ^= zobrist::hash_square(to, state);

      state.pieces[kWhitePawns].clear_bit(to);
      state.pieces[kWhitePieces].clear_bit(to);
      state.pieces[kWhitePieces].set_bit(to);

      // xor in the promoted piece
      state.zobrist_key ^= zobrist::hash_square(to, state);
    }
  } else {
    if (to_rank == 0) {
      switch (move.get_promotion_type()) {
        case PromotionType::kKnight:state.pieces[kBlackKnights].set_bit(to);
          break;
        case PromotionType::kBishop:state.pieces[kBlackBishops].set_bit(to);
          break;
        case PromotionType::kRook:state.pieces[kBlackRooks].set_bit(to);
          break;
        case PromotionType::kAny: // just choose a queen
        case PromotionType::kQueen:state.pieces[kBlackQueens].set_bit(to);
          break;
        default:std::cerr << "invalid promotion type" << std::endl;
          return;
      }

      if (perft && perft_depth == 1)
        ++promotions;

      // xor out the promoted pawn
      state.zobrist_key ^= zobrist::hash_square(to, state);

      state.pieces[kBlackPawns].clear_bit(to);
      state.pieces[kBlackPieces].clear_bit(to);
      state.pieces[kBlackPieces].set_bit(to);

      // xor in the promoted piece
      state.zobrist_key ^= zobrist::hash_square(to, state);
    }
  }
}