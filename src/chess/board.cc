#include "board.h"

#include "fen.h"
#include "move.h"
#include "move_gen.h"

// clang-format off
constexpr std::array<U8, 64> kCastlingRights = {
  7, 15, 15, 15,  3, 15, 15, 11,
  15, 15, 15, 15, 15, 15, 15, 15,
  15, 15, 15, 15, 15, 15, 15, 15,
  15, 15, 15, 15, 15, 15, 15, 15,
  15, 15, 15, 15, 15, 15, 15, 15,
  15, 15, 15, 15, 15, 15, 15, 15,
  15, 15, 15, 15, 15, 15, 15, 15,
  13, 15, 15, 15, 12, 15, 15, 14
};
// clang-format on

Board::Board() : history_({}) {}

void Board::SetFromFen(std::string_view fen_str) {
  key_history_.Clear();
  state_ = fen::StringToBoard(fen_str);
  CalculateThreats();
}

bool Board::IsMovePseudoLegal(Move move) {
  const auto from = move.GetFrom(), to = move.GetTo();
  const Color us = state_.turn;

  const BitBoard &our_pieces = state_.Occupied(us);
  if (!our_pieces.IsSet(from) || our_pieces.IsSet(to)) {
    return false;
  }

  const auto piece_type = state_.GetPieceType(from);
  if (piece_type != PieceType::kPawn &&
      move.GetType() == MoveType::kPromotion) {
    return false;
  }

  const BitBoard &their_pieces = state_.Occupied(FlipColor(state_.turn));
  const BitBoard occupied = our_pieces | their_pieces;

  if (piece_type == PieceType::kKing) {
    constexpr int kKingsideCastleDist = -2;
    constexpr int kQueensideCastleDist = 2;
    constexpr BitBoard kWhiteKingsideOccupancy = 0x60;
    constexpr BitBoard kWhiteQueensideOccupancy = 0xe;
    constexpr BitBoard kBlackKingsideOccupancy = 0x6000000000000000;
    constexpr BitBoard kBlackQueensideOccupancy = 0xe00000000000000;

    // Note: the only way move_dist is ever 2 or -2 is from
    // move_gen::CastlingMoves allowing it
    const int move_dist = static_cast<int>(from) - static_cast<int>(to);
    if (move_dist == kKingsideCastleDist) {
      return !state_.checkers && state_.castle_rights.CanKingsideCastle(us) &&
             !(occupied & (us == Color::kWhite ? kWhiteKingsideOccupancy
                                               : kBlackKingsideOccupancy));
    } else if (move_dist == kQueensideCastleDist) {
      return !state_.checkers && state_.castle_rights.CanQueensideCastle(us) &&
             !(occupied & (us == Color::kWhite ? kWhiteQueensideOccupancy
                                               : kBlackQueensideOccupancy));
    }
  }

  BitBoard possible_moves;
  switch (piece_type) {
    case PieceType::kPawn: {
      BitBoard en_passant_mask;
      if (state_.en_passant != Squares::kNoSquare) {
        en_passant_mask = BitBoard::FromSquare(state_.en_passant);
      }
      const BitBoard pawn_attacks = (move_gen::PawnAttacks(from, state_.turn) &
                                     (their_pieces | en_passant_mask));
      possible_moves = move_gen::PawnPushMoves(from, state_) | pawn_attacks;
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
      possible_moves = move_gen::QueenMoves(from, occupied);
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

  const auto from = move.GetFrom();
  const auto to = move.GetTo();

  const BitBoard king_mask = state_.King(us);
  const auto king_square = king_mask.GetLsb();

  const auto piece_type = state_.GetPieceType(from);
  if (piece_type == PieceType::kKing) {
    constexpr int kKingsideCastleDist = -2;
    constexpr int kQueensideCastleDist = 2;

    // Note: the only way move_dist is ever 2 or -2 is from
    // move_gen::CastlingMoves allowing it
    const int move_dist = static_cast<int>(from) - static_cast<int>(to);
    if (move_dist == kKingsideCastleDist) {
      return !move_gen::GetAttackersTo(
                 state_, is_white ? Squares::kG1 : Squares::kG8, them) &&
             !move_gen::GetAttackersTo(
                 state_, is_white ? Squares::kF1 : Squares::kF8, them);
    } else if (move_dist == kQueensideCastleDist) {
      return !move_gen::GetAttackersTo(
                 state_, is_white ? Squares::kC1 : Squares::kC8, them) &&
             !move_gen::GetAttackersTo(
                 state_, is_white ? Squares::kD1 : Squares::kD8, them);
    }

    // Make sure the destination square isn't attacked
    // Also verify that the king isn't moving along the same ray it's being
    // attacked on, since the threats bitboard doesn't xray past pieces
    return !move_gen::GetAttackersTo(
        state_, to, state_.Occupied() ^ king_mask, them);
  } else if (piece_type == PieceType::kPawn &&
             state_.en_passant != Squares::kNoSquare &&
             to == state_.en_passant) {
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
  const auto checking_piece = state_.checkers.GetLsb();
  return move_gen::RayBetween(king_square, checking_piece).IsSet(to);
}

template void Board::MakeMove<false>(Move move);
template void Board::MakeMove<true>(Move move);

template <bool keep_history>
void Board::MakeMove(Move move) {
  if constexpr (keep_history) {
    history_.Push(state_);
  }

  key_history_.Push(state_.zobrist_key);

  const Color us = state_.turn, them = FlipColor(us);

  const auto from = move.GetFrom(), to = move.GetTo();
  const auto piece = state_.GetPieceType(from),
             captured = state_.GetPieceType(to);
  const auto move_type = move.GetType();

  int new_fifty_move_clock =
      piece == PieceType::kPawn ? 0 : state_.fifty_moves_clock + 1;

  if (move_type == MoveType::kEnPassant) {
    const Square pawn_square =
        state_.en_passant - (us == Color::kWhite ? 8 : -8);
    state_.RemovePiece(pawn_square, them);
  } else if (captured != PieceType::kNone) {
    state_.RemovePiece(to, them);
    new_fifty_move_clock = 0;
  }

  // Xor out en passant if it exists
  if (state_.en_passant != Squares::kNoSquare) {
    state_.zobrist_key ^= zobrist::en_passant[state_.en_passant.File()];
    state_.en_passant = Squares::kNoSquare;
  }

  if (piece == PieceType::kPawn && std::abs(to.Rank() - from.Rank()) == 2) {
    state_.en_passant = to - (us == Color::kWhite ? 8 : -8);
    state_.zobrist_key ^= zobrist::en_passant[state_.en_passant.File()];
  }

  // Move the piece
  state_.RemovePiece(from, state_.turn);
  auto new_piece = piece;

  if (move_type == MoveType::kCastle) {
    HandleCastling(move);
  } else if (move_type == MoveType::kPromotion) {
    new_piece = PieceType(static_cast<int>(move.GetPromotionType()) + 1);
  }

  state_.PlacePiece(to, new_piece, state_.turn);

  // Update the castling rights depending on the piece that moved
  state_.zobrist_key ^= zobrist::castle_rights[state_.castle_rights.AsU8()];
  state_.castle_rights &= kCastlingRights[from] & kCastlingRights[to];
  state_.zobrist_key ^= zobrist::castle_rights[state_.castle_rights.AsU8()];

  state_.turn = FlipColor(state_.turn);
  state_.zobrist_key ^= zobrist::turn;

  state_.fifty_moves_clock = new_fifty_move_clock;

  CalculateThreats();
}

void Board::UndoMove() {
  state_ = history_.PopBack();
  key_history_.PopBack();
}

void Board::MakeNullMove() {
  history_.Push(state_);
  key_history_.Push(state_.zobrist_key);

  // Xor out en passant if it exists
  if (state_.en_passant != Squares::kNoSquare) {
    state_.zobrist_key ^= zobrist::en_passant[state_.en_passant.File()];
    state_.en_passant = Squares::kNoSquare;
  }

  state_.turn = FlipColor(state_.turn);
  state_.zobrist_key ^= zobrist::turn;

  state_.fifty_moves_clock++;

  CalculateThreats();
}

U64 Board::PredictKeyAfter(Move move) {
  auto key = state_.zobrist_key ^ zobrist::turn;

  const auto from = move.GetFrom();
  const auto to = move.GetTo();
  const auto move_type = move.GetType();
  const auto piece = state_.GetPieceType(from);

  // Xor out from position
  const int colored_piece = piece * 2 + state_.turn;
  key ^= zobrist::pieces[colored_piece][from];

  const auto captured_piece = state_.GetPieceType(to);
  if (captured_piece != PieceType::kNone) {
    const int colored_captured_piece =
        captured_piece * 2 + FlipColor(state_.turn);
    key ^= zobrist::pieces[colored_captured_piece][to];
  }

  auto new_piece = piece;
  if (move_type == MoveType::kPromotion) {
    new_piece = PieceType(static_cast<int>(move.GetPromotionType()) + 1);
  }

  if (move_type == MoveType::kEnPassant) {
    const Square pawn_square =
        state_.en_passant - (state_.turn == Color::kWhite ? 8 : -8);
    key ^= zobrist::pieces[PieceType::kPawn * 2 + FlipColor(state_.turn)]
                          [pawn_square];
  }

  if (state_.en_passant != Squares::kNoSquare) {
    key ^= zobrist::en_passant[state_.en_passant.File()];
  }

  if (piece == PieceType::kPawn && std::abs(to.Rank() - from.Rank()) == 2) {
    key ^= zobrist::en_passant[from.File()];
  }

  const int colored_new_piece = new_piece * 2 + state_.turn;
  key ^= zobrist::pieces[colored_new_piece][to];

  return key;
}

bool Board::HasRepeated(U16 ply) {
  const int max_dist = std::min<int>(state_.fifty_moves_clock, key_history_.Size());

  bool hit_before_root = false;
  for (int i = 4; i <= max_dist; i += 2) {
    if (state_.zobrist_key == key_history_[history_.Size() - i]) {
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
  if ((their_minor_pieces != 0 && state_.KinglessOccupied(us) == 0) ||
      (our_minor_pieces != 0 && state_.KinglessOccupied(them) == 0)) {
    return true;
  }

  // Any other combination of pieces not covered by the above is not a draw
  return false;
}

void Board::HandleCastling(Move move) {
  const bool is_white = state_.turn == Color::kWhite;

  const auto from = move.GetFrom(), to = move.GetTo();
  const auto move_rook_for_castling = [this](Square rook_from, Square rook_to) {
    state_.RemovePiece(rook_from, state_.turn);
    state_.PlacePiece(rook_to, PieceType::kRook, state_.turn);
  };

  constexpr int kKingsideCastleDist = -2;
  constexpr int kQueensideCastleDist = 2;

  // Note: the only way move_dist is ever 2 or -2 is from
  // move_gen::CastlingMoves allowing it
  const int move_dist = static_cast<int>(from) - static_cast<int>(to);
  if (move_dist == kKingsideCastleDist) {
    move_rook_for_castling(is_white ? Squares::kH1 : Squares::kH8,
                           is_white ? Squares::kF1 : Squares::kF8);
  } else if (move_dist == kQueensideCastleDist) {
    move_rook_for_castling(is_white ? Squares::kA1 : Squares::kA8,
                           is_white ? Squares::kD1 : Squares::kD8);
  }
}

void Board::CalculateThreats() {
  const Color them = FlipColor(state_.turn);

  state_.threats = move_gen::PawnAttacks(state_.Pawns(them), them);

  for (Square square : state_.Knights(them)) {
    state_.threats |= move_gen::KnightMoves(square);
  }

  const BitBoard queens = state_.Queens(them);
  const BitBoard occupied = state_.Occupied();

  for (Square square : state_.Bishops(them) | queens) {
    state_.threats |= move_gen::BishopMoves(square, occupied);
  }

  for (Square square : state_.Rooks(them) | queens) {
    state_.threats |= move_gen::RookMoves(square, occupied);
  }

  state_.threats |= move_gen::KingAttacks(state_.King(them).GetLsb());

  CalculateKingThreats();
}

void Board::CalculateKingThreats() {
  const Color us = state_.turn;
  const Color them = FlipColor(us);

  const BitBoard our_pieces = state_.Occupied(us);
  const BitBoard their_pieces = state_.Occupied(them);

  const Square king_square = state_.King(us).GetLsb();

  // Calculate the pieces that are attacking the king
  state_.checkers = (move_gen::KnightMoves(king_square) & state_.Knights()) |
                    (move_gen::PawnAttacks(king_square, us) & state_.Pawns());
  state_.checkers &= their_pieces;

  // Calculate our potentially pinned pieces
  state_.pinned = 0;

  // Calculate all the opponent's pieces that could reach our king
  BitBoard x_raying_pieces =
      move_gen::GetSlidingAttackersTo(state_, king_square, their_pieces, them);
  while (x_raying_pieces) {
    const Square square = x_raying_pieces.PopLsb();

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
    fmt::print("{} ", rank + 1);
    for (int file = 0; file < kNumFiles; file++) {
      const auto square = Square::FromRankFile(rank, file);
      fmt::print("{}",
                 fen::GetPieceChar(const_cast<BoardState &>(state_), square));
      if (file < kNumFiles - 1) fmt::print(" ");  // Space separator for clarity
    }
    fmt::print("\n");
  }
  fmt::print("  ");
  for (int file = 0; file < kNumFiles; file++)
    fmt::print("{} ", static_cast<char>('a' + file));
  fmt::print("\n");
}