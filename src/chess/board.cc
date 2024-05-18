#include "board.h"

#include "fen.h"
#include "move.h"
#include "move_gen.h"

Board::Board() : history_({}) {}

void Board::SetFromFen(std::string_view fen_str) {
  // Reset history everytime we parse from fen, since they will be re-applied
  // when the moves are made
  history_.Clear();
  state_ = fen::StringToBoard(fen_str);

  CalculateKingThreats();
}

bool Board::IsMovePseudoLegal(Move move) {
  const auto from = move.GetFrom(), to = move.GetTo();
  const Color us = state_.turn;

  const BitBoard &our_pieces = state_.Occupied(us);
  if (!our_pieces.IsSet(from) || our_pieces.IsSet(to)) {
    return false;
  }

  const auto piece_type = state_.GetPieceType(from);
  const auto promotion_type = move.GetPromotionType();
  if (piece_type != PieceType::kPawn &&
      promotion_type != PromotionType::kNone) {
    return false;
  }

  const BitBoard &their_pieces = state_.Occupied(FlipColor(state_.turn));
  const BitBoard occupied = our_pieces | their_pieces;

  if (piece_type == PieceType::kKing) {
    const bool is_white = us == Color::kWhite;

    constexpr int kKingsideCastleDist = -2;
    constexpr int kQueensideCastleDist = 2;

    // Note: the only way move_dist is ever 2 or -2 is from
    // move_gen::CastlingMoves allowing it
    const int move_dist = static_cast<int>(from) - static_cast<int>(to);
    if (move_dist == kKingsideCastleDist) {
      return !state_.checkers && state_.castle_rights.CanKingsideCastle(us) &&
             !occupied.IsSet(is_white ? Square::kG1 : Square::kG8) &&
             !occupied.IsSet(is_white ? Square::kF1 : Square::kF8);
    } else if (move_dist == kQueensideCastleDist) {
      return !state_.checkers && state_.castle_rights.CanQueensideCastle(us) &&
             !occupied.IsSet(is_white ? Square::kC1 : Square::kC8) &&
             !occupied.IsSet(is_white ? Square::kD1 : Square::kD8) &&
             !occupied.IsSet(is_white ? Square::kB1 : Square::kB8);
    }
  }

  BitBoard possible_moves;
  switch (piece_type) {
    case PieceType::kPawn: {
      BitBoard en_passant_mask;
      if (state_.en_passant != Square::kNoSquare) {
        en_passant_mask = BitBoard::FromSquare(state_.en_passant);
      }
      const BitBoard pawn_attacks =
          (move_gen::PawnAttacks(from, state_, state_.turn) &
           (their_pieces | en_passant_mask));
      possible_moves = move_gen::PawnMoves(from, state_) | pawn_attacks;
      break;
    }
    case PieceType::kKnight:
      possible_moves = move_gen::KnightMoves(from);
      break;
    case PieceType::kBishop:
      possible_moves = move_gen::BishopMoves(from, occupied);
      break;
    case PieceType::kRook:
      possible_moves = move_gen::RookMoves(from, occupied);
      break;
    case PieceType::kQueen:
      possible_moves = move_gen::BishopMoves(from, occupied) |
                       move_gen::RookMoves(from, occupied);
      break;
    case PieceType::kKing:
      possible_moves = move_gen::KingAttacks(from);
      break;
    default:
      return false;
  }

  return possible_moves.IsSet(to);
}

bool Board::IsMoveLegal(Move move) {
  const Color us = state_.turn, them = FlipColor(us);
  const bool is_white = state_.turn == Color::kWhite;

  const auto from = Square(move.GetFrom());
  const auto to = Square(move.GetTo());

  const BitBoard king_mask = state_.King(us);
  const auto king_square = Square(king_mask.GetLSB());

  const auto piece_type = state_.GetPieceType(from);
  if (piece_type == PieceType::kKing) {
    constexpr int kKingsideCastleDist = -2;
    constexpr int kQueensideCastleDist = 2;

    // Note: the only way move_dist is ever 2 or -2 is from
    // move_gen::CastlingMoves allowing it
    const int move_dist = static_cast<int>(from) - static_cast<int>(to);
    if (move_dist == kKingsideCastleDist) {
      return !move_gen::GetAttackersTo(
                 state_, is_white ? Square::kG1 : Square::kG8, them) &&
             !move_gen::GetAttackersTo(
                 state_, is_white ? Square::kF1 : Square::kF8, them);
    } else if (move_dist == kQueensideCastleDist) {
      return !move_gen::GetAttackersTo(
                 state_, is_white ? Square::kC1 : Square::kC8, them) &&
             !move_gen::GetAttackersTo(
                 state_, is_white ? Square::kD1 : Square::kD8, them);
    }

    // Make sure the destination square isn't attacked
    // Also verify that the king isn't moving along the same ray it's being
    // attacked on, since the threats bitboard doesn't xray past pieces
    return !move_gen::GetAttackersTo(
        state_, to, state_.Occupied() ^ king_mask, them);
  } else if (piece_type == PieceType::kPawn && to == state_.en_passant) {
    // Pawn must be directly behind/in front of the attack square
    const BitBoard en_passant_pawn_mask =
        BitBoard::FromSquare(is_white ? to - 8 : to + 8);
    // Mask of the position after the en passant capture
    const BitBoard en_passant_occupied_mask =
        state_.Occupied() ^ en_passant_pawn_mask ^ BitBoard::FromSquare(from) ^
        BitBoard::FromSquare(to);
    // Verify that no sliding piece is attacking the king after the en passant
    // capture
    return !move_gen::GetSlidingAttackersTo(
        state_, king_square, en_passant_occupied_mask, them);
  }

  // If the king is double-checked, it can only evade check with a king move,
  // which should've been handled earlier
  if (state_.checkers.MoreThanOne()) {
    return false;
  }

  // If the piece being moved is pinned, verify that it's moving on the same
  // diagonal
  if (state_.pinned.IsSet(from) &&
      !(move_gen::RayIntersecting(from, to) & king_mask)) {
    return false;
  }

  // If not in check, or we can take the checking piece
  if (!state_.checkers || state_.checkers.IsSet(to)) {
    return true;
  }

  // Only legal move left is to either take the piece that's causing check or
  // block its path
  const auto checking_piece = Square(state_.checkers.GetLSB());
  return move_gen::RayBetween(king_square, checking_piece).IsSet(to);
}

void Board::MakeMove(Move move) {
  // Create new board state
  history_.Push(state_);

  const auto from = move.GetFrom(), to = move.GetTo();
  const auto piece_type = state_.GetPieceType(from);

  int new_fifty_move_clock = state_.fifty_moves_clock + 1;

  // Xor out the previous turn hash and moved piece
  state_.zobrist_key ^=
      zobrist::HashSquare(from, state_, state_.turn, piece_type) ^
      zobrist::HashTurn(state_.turn);

  const auto captured_piece = state_.GetPieceType(to);
  if (captured_piece != PieceType::kNone) {
    state_.zobrist_key ^=
        zobrist::HashSquare(to, state_, FlipColor(state_.turn), captured_piece);
    state_.RemovePiece(to);

    // Reset fifty moves clock since this move was a capture
    new_fifty_move_clock = 0;
  }

  const bool is_white = state_.turn == Color::kWhite;

  // Used for zobrist hashing later
  bool move_is_double_push = false;
  if (piece_type == PieceType::kPawn) {
    new_fifty_move_clock = 0;

    // Check if this was an en passant capture
    if (to == state_.en_passant) {
      // Pawn must be directly behind/in front of the attack square
      const auto en_passant_pawn_pos = Square(is_white ? to - 8 : to + 8);

      // Xor out the en passant captured pawn
      state_.zobrist_key ^= zobrist::HashSquare(en_passant_pawn_pos,
                                                state_,
                                                FlipColor(state_.turn),
                                                PieceType::kPawn);
      state_.RemovePiece(en_passant_pawn_pos);

      // Xor out the en passant pos
      state_.zobrist_key ^= zobrist::HashEnPassant(state_);
      state_.en_passant = Square::kNoSquare;
    } else {
      // Setting en passant target if pawn moved two squares
      constexpr int kDoublePushDist = 16;
      if ((from ^ to) == kDoublePushDist) {
        // Xor out previous en passant square (if it exists)
        // We will xor in new en passant square after the turn has been updated
        state_.zobrist_key ^= zobrist::HashEnPassant(state_);

        // Pawn must be directly behind/in front of the attack square
        const U8 en_passant_pawn_pos = is_white ? to - 8 : to + 8;
        state_.en_passant = Square(en_passant_pawn_pos);

        // Keep track if this was a move that caused en passant to be set (for
        // zobrist hashing)
        move_is_double_push = true;
      }
      // This move wasn't a double pawn push, so if ep square was set from the
      // previous move, we xor it out
      else if (state_.en_passant != Square::kNoSquare) {
        state_.zobrist_key ^= zobrist::HashEnPassant(state_);
        state_.en_passant = Square::kNoSquare;
      }
    }
  } else if (state_.en_passant != Square::kNoSquare) {
    // If ep square was set from the previous move, we xor it out
    state_.zobrist_key ^= zobrist::HashEnPassant(state_);
    state_.en_passant = Square::kNoSquare;
  }

  HandleCastling(move);

  // Move the piece
  state_.RemovePiece(from);
  state_.PlacePiece(to, piece_type, state_.turn);

  const auto promotion_type = move.GetPromotionType();
  if (piece_type == PieceType::kPawn &&
      promotion_type != PromotionType::kNone) {
    HandlePromotions(move);

    // Xor in the promoted piece
    state_.zobrist_key ^=
        zobrist::HashSquare(to, state_, state_.turn, PieceType(promotion_type));
  } else {
    // Xor in the moved piece
    state_.zobrist_key ^=
        zobrist::HashSquare(to, state_, state_.turn, piece_type);
  }

  // Xor in new turn
  state_.turn = FlipColor(state_.turn);
  state_.zobrist_key ^= zobrist::HashTurn(state_.turn);

  // Xor en passant in now that the turn's have been switched
  // This is important since HashEnPassant checks if the opponents pawn
  // is next to the double-pushed pawn
  if (move_is_double_push) {
    state_.zobrist_key ^= zobrist::HashEnPassant(state_);
  }

  state_.fifty_moves_clock = new_fifty_move_clock;

  CalculateKingThreats();
}

void Board::UndoMove() {
  state_ = history_.PopBack();
}

void Board::MakeNullMove() {
  history_.Push(state_);

  // Xor out the previous turn hash
  state_.zobrist_key ^= zobrist::HashTurn(state_.turn);

  // Xor out en passant if it exists
  if (state_.en_passant != Square::kNoSquare) {
    state_.zobrist_key ^= zobrist::HashEnPassant(state_);
    state_.en_passant = Square::kNoSquare;
  }

  // Switch turn and xor in the new turn hash
  state_.turn = FlipColor(state_.turn);
  state_.zobrist_key ^= zobrist::HashTurn(state_.turn);

  state_.fifty_moves_clock++;

  CalculateKingThreats();
}

U64 Board::PredictKeyAfter(Move move) {
  U64 key = state_.zobrist_key;
  key ^= zobrist::HashTurn(state_.turn) ^
         zobrist::HashTurn(FlipColor(state_.turn));

  // Just swap sides
  if (move.IsNull()) {
    return key;
  }

  const auto from = move.GetFrom();
  const auto to = move.GetTo();
  const auto piece = state_.GetPieceType(from);

  // Xor out from position
  key ^= zobrist::HashSquare(from, state_, state_.turn, piece);

  const auto captured_piece = state_.GetPieceType(to);
  if (captured_piece != PieceType::kNone) {
    // Xor out the captured piece
    key ^=
        zobrist::HashSquare(to, state_, FlipColor(state_.turn), captured_piece);
  }

  const auto promotion_type = move.GetPromotionType();
  if (piece == PieceType::kPawn && promotion_type != PromotionType::kNone) {
    // Xor in the promoted piece
    key ^=
        zobrist::HashSquare(to, state_, state_.turn, PieceType(promotion_type));
  } else {
    // Xor in the moved piece
    key ^= zobrist::HashSquare(to, state_, state_.turn, piece);
  }

  return key;
}

bool Board::HasRepeated(U16 ply) {
  const int max_dist = std::min<int>(state_.fifty_moves_clock, history_.Size());

  bool hit_before_root = false;
  for (int i = 4; i <= max_dist; i += 2) {
    if (state_.zobrist_key == history_[history_.Size() - i].zobrist_key) {
      if (ply >= i) return true;
      if (hit_before_root) return true;
      hit_before_root = true;
    }
  }

  return false;
}

bool Board::IsDraw(U16 ply) {
  if (state_.fifty_moves_clock >= 100 || HasRepeated(ply)) {
    return true;
  }

  // Insufficient material detection
  const Color us = state_.turn, them = FlipColor(us);

  // Check for queens, rooks, or pawns on the board
  if (state_.Queens() || state_.Rooks() || state_.Pawns()) {
    return false;
  }

  // Lone kings
  if (!state_.KinglessOccupied()) {
    return true;
  }

  const BitBoard our_knights = state_.Knights(us),
                 their_knights = state_.Knights(them);
  const BitBoard our_bishops = state_.Bishops(us),
                 their_bishops = state_.Bishops(them);

  const BitBoard their_minor_pieces = their_knights | their_bishops;
  const BitBoard our_minor_pieces = our_knights | our_bishops;

  // More than one minor piece on either side
  if (their_minor_pieces.MoreThanOne() || our_minor_pieces.MoreThanOne()) {
    return false;
  }

  // Lone king on one side and one minor piece on the other
  if (their_minor_pieces != 0 && state_.KinglessOccupied(us) == 0 ||
      our_minor_pieces != 0 && state_.KinglessOccupied(them) == 0) {
    return true;
  }

  // Any other combination of pieces not covered by the above is not a draw
  return false;
}

void Board::HandleCastling(Move move) {
  const bool is_white = state_.turn == Color::kWhite;

  const auto from = move.GetFrom(), to = move.GetTo();
  const auto piece_type = state_.GetPieceType(from);

  const auto old_castle_rights = state_.castle_rights;

  if (piece_type == PieceType::kKing) {
    if (state_.castle_rights.CanKingsideCastle(state_.turn) ||
        state_.castle_rights.CanQueensideCastle(state_.turn)) {
      const auto move_rook_for_castling = [this](const Square &rook_from,
                                                 const Square &rook_to) {
        // Xor out the rook's previous square
        state_.zobrist_key ^= zobrist::HashSquare(
            rook_from, state_, state_.turn, PieceType::kRook);

        state_.RemovePiece(rook_from);
        state_.PlacePiece(rook_to, PieceType::kRook, state_.turn);

        // Xor in the rook's new square
        state_.zobrist_key ^=
            zobrist::HashSquare(rook_to, state_, state_.turn, PieceType::kRook);
      };

      constexpr int kKingsideCastleDist = -2;
      constexpr int kQueensideCastleDist = 2;

      // Note: the only way move_dist is ever 2 or -2 is from
      // move_gen::CastlingMoves allowing it
      const int move_dist = static_cast<int>(from) - static_cast<int>(to);
      if (move_dist == kKingsideCastleDist) {
        move_rook_for_castling(is_white ? Square::kH1 : Square::kH8,
                               is_white ? Square::kF1 : Square::kF8);
      } else if (move_dist == kQueensideCastleDist) {
        move_rook_for_castling(is_white ? Square::kA1 : Square::kA8,
                               is_white ? Square::kD1 : Square::kD8);
      }

      state_.castle_rights.SetBothRights(state_.turn, false);
    }
  }
  // Handle rook moves changing castle rights
  else if (piece_type == PieceType::kRook &&
           state_.castle_rights.CanCastle(state_.turn)) {
    if (is_white) {
      if (from == Square::kH1) {
        state_.castle_rights.SetCanKingsideCastle(state_.turn, false);
      } else if (from == Square::kA1) {
        state_.castle_rights.SetCanQueensideCastle(state_.turn, false);
      }
    } else {
      if (from == Square::kH8) {
        state_.castle_rights.SetCanKingsideCastle(state_.turn, false);
      } else if (from == Square::kA8) {
        state_.castle_rights.SetCanQueensideCastle(state_.turn, false);
      }
    }
  }

  // Handle rook getting captured changing castle rights
  auto their_kingside_rook =
      state_.castle_rights.GetKingsideRook(FlipColor(state_.turn));
  auto their_queenside_rook =
      state_.castle_rights.GetQueensideRook(FlipColor(state_.turn));

  if (to == their_kingside_rook) {
    state_.castle_rights.SetCanKingsideCastle(FlipColor(state_.turn), false);
  } else if (to == their_queenside_rook) {
    state_.castle_rights.SetCanQueensideCastle(FlipColor(state_.turn), false);
  }

  if (state_.castle_rights != old_castle_rights) {
    state_.zobrist_key ^= zobrist::HashCastleRights(old_castle_rights);
    state_.zobrist_key ^= zobrist::HashCastleRights(state_.castle_rights);
  }
}

void Board::HandlePromotions(Move move) {
  const bool is_white = state_.turn == Color::kWhite;

  const auto to = move.GetTo();
  const auto to_rank = Rank(to);

  if (is_white && to_rank == kNumRanks - 1 || !is_white && to_rank == 0) {
    state_.RemovePiece(to);

    switch (move.GetPromotionType()) {
      case PromotionType::kKnight: {
        state_.PlacePiece(to, PieceType::kKnight, state_.turn);
        break;
      }
      case PromotionType::kBishop: {
        state_.PlacePiece(to, PieceType::kBishop, state_.turn);
        break;
      }
      case PromotionType::kRook: {
        state_.PlacePiece(to, PieceType::kRook, state_.turn);
        break;
      }
      case PromotionType::kAny:  // Just choose a queen
      case PromotionType::kQueen: {
        state_.PlacePiece(to, PieceType::kQueen, state_.turn);
        break;
      }
      default:
        break;
    }
  }
}

void Board::CalculateKingThreats() {
  const Color us = state_.turn;
  const Color them = FlipColor(us);

  const BitBoard our_pieces = state_.Occupied(us);
  const BitBoard their_pieces = state_.Occupied(them);

  const auto king_square = Square(state_.King(us).GetLSB());

  // Calculate the pieces that are attacking the king
  state_.checkers =
      move_gen::KnightMoves(king_square) & state_.Knights() |
      move_gen::PawnAttacks(king_square, state_, us) & state_.Pawns();
  state_.checkers &= their_pieces;

  // Calculate our potentially pinned pieces
  state_.pinned = 0;

  // Calculate all the opponent's pieces that could reach our king
  BitBoard x_raying_pieces =
      move_gen::GetSlidingAttackersTo(state_, king_square, their_pieces, them);
  while (x_raying_pieces) {
    const auto square = Square(x_raying_pieces.PopLsb());

    const BitBoard pinned =
        our_pieces & move_gen::RayBetween(king_square, square);
    const int num_blockers = pinned.PopCount();
    if (!num_blockers) {
      // This piece is directly attacking the king
      state_.checkers |= BitBoard::FromSquare(square);
    } else if (num_blockers == 1) {
      // A piece is pinned if it's the only piece within a xray of an opponents
      // piece to our king
      state_.pinned |= pinned;
    }
  }
}

void Board::PrintPieces() {
  for (int rank = kNumRanks - 1; rank >= 0; rank--) {
    std::cout << rank + 1 << ' ';
    for (int file = 0; file < kNumFiles; file++) {
      const auto square = RankFileToSquare(rank, file);
      std::cout << fen::GetPieceChar(const_cast<BoardState &>(state_), square);
      if (file < kNumFiles - 1)
        std::cout << " ";  // Space separator for clarity
    }
    std::cout << std::endl;
  }
  std::cout << "  ";
  for (int file = 0; file < kNumFiles; file++)
    std::cout << static_cast<char>('a' + file) << ' ';
  std::cout << std::endl;
}