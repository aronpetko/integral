#include "board.h"

#include "../engine/evaluation/nnue/accumulator.h"
#include "../engine/search/cuckoo.h"
#include "fen.h"
#include "move.h"
#include "move_gen.h"

#include <bit>

constexpr std::array<Square, 4> kRookEndSquares = {
    Square(kD8), Square(kF8), Square(kD1), Square(kF1)};
constexpr std::array<Square, 4> kKingEndSquares = {
    Square(kC8), Square(kG8), Square(kC1), Square(kG1)};

Board::Board() : history_({}) {}

Board::Board(const BoardState &state) : history_({}), state_(state) {}

Board::Board(const Board &other)
    : state_(other.state_), history_(other.history_) {}

Board &Board::operator=(const Board &other) {
  if (this == &other) {
    return *this;
  }

  state_ = other.state_;
  history_ = other.history_;
  accumulator_ = std::make_shared<nnue::Accumulator>();
  return *this;
}

void Board::SetFromFen(std::string_view fen_str) {
  state_ = fen::StringToBoard(fen_str);

  accumulator_ = std::make_shared<nnue::Accumulator>();
  accumulator_->SetFromState(state_);

  history_.Clear();

  CalculateThreats();
}

bool Board::IsMovePseudoLegal(Move move) const {
  if (move.IsNull()) return false;

  const auto from = move.GetFrom(), to = move.GetTo();
  const Color us = state_.turn;

  const BitBoard &our_pieces = state_.Occupied(us);
  if (!our_pieces.IsSet(from) ||
      (our_pieces.IsSet(to) && move.GetType() != MoveType::kCastle)) {
    return false;
  }

  const auto move_type = move.GetType();
  const auto piece_type = state_.GetPieceType(from);
  if (piece_type != PieceType::kPawn && move_type == MoveType::kPromotion) {
    return false;
  }

  const BitBoard &their_pieces = state_.Occupied(FlipColor(state_.turn));
  const BitBoard occupied = our_pieces | their_pieces;

  if (move_type == MoveType::kCastle) {
    if (piece_type != PieceType::kKing) return false;

    if (state_.GetPieceType(to) != PieceType::kRook) return false;

    if (to > from)
      return state_.castle_rights.CastleSquare(state_.turn, CastleRights::kKingside) == to;
    return state_.castle_rights.CastleSquare(state_.turn, CastleRights::kQueenside) == to;
  }

  if (move_type == MoveType::kEnPassant) {
    return piece_type == PieceType::kPawn && to == state_.en_passant;
  }

  BitBoard possible_moves;
  switch (piece_type) {
    case PieceType::kPawn: {
      possible_moves =
          move_gen::PawnPushMoves(from, state_) |
          (move_gen::PawnAttacks(from, state_.turn) & their_pieces);
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

bool Board::IsMoveLegal(Move move) const {
  const Color us = state_.turn, them = FlipColor(us);
  const bool is_white = state_.turn == Color::kWhite;

  const auto from = move.GetFrom();
  const auto to = move.GetTo();

  const BitBoard king_mask = state_.King(us);
  const auto king_square = king_mask.GetLsb();

  const auto piece_type = state_.GetPieceType(from);
  if (piece_type == PieceType::kKing) {
    if (move.GetType() == MoveType::kCastle) {
      if (state_.InCheck()) return false;

      const bool is_kingside = to > from;

      if (state_.pinned[state_.turn].IsSet(to)) return false;

      const Square king_sq = move.GetFrom();
      const Square rook_sq = move.GetTo();

      const Square king_to = kKingEndSquares[CastleRights::CastleIndex(
          us,
          king_sq > rook_sq ? CastleRights::kQueenside
                            : CastleRights::kKingside)];
      const Square rook_to = kRookEndSquares[CastleRights::CastleIndex(
          us,
          king_sq > rook_sq ? CastleRights::kQueenside
                            : CastleRights::kKingside)];

      BitBoard between_bb = move_gen::RayIncluding(king_sq, king_to) |
                            move_gen::RayIncluding(rook_sq, rook_to);
      between_bb.ClearBit(king_sq);
      between_bb.ClearBit(rook_sq);

      if (between_bb & state_.Occupied()) return false;

      between_bb = move_gen::RayIncluding(king_sq, king_to);
      between_bb.ClearBit(king_sq);

      while (between_bb)
        if (state_.threats.IsSet(between_bb.PopLsb())) return false;

      return true;
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
  if (state_.pinned[us].IsSet(from) &&
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

void Board::MakeMove(Move move) {
  history_.Push(state_);

  const Color us = state_.turn, them = FlipColor(us);

  const auto from = move.GetFrom(), to = move.GetTo();
  const auto piece = state_.GetPieceType(from),
             captured = move.GetType() == MoveType::kCastle ? PieceType::kNone : state_.GetPieceType(to);
  const auto move_type = move.GetType();

  // Initialize accumulator change
  nnue::AccumulatorChange accum_change{};
  accum_change.sub_0 = {from, piece, us};
  if (move_type != MoveType::kCastle)
    accum_change.add_0 = {to, piece, us};
  else
    accum_change.add_0 = {kKingEndSquares[CastleRights::CastleIndex(us, to > from ? CastleRights::kKingside : CastleRights::kQueenside)], piece, us};

  int new_fifty_move_clock =
      piece == PieceType::kPawn ? 0 : state_.fifty_moves_clock + 1;

  if (move_type == MoveType::kEnPassant) {
    const Square pawn_square =
        state_.en_passant - (us == Color::kWhite ? 8 : -8);
    state_.RemovePiece(pawn_square, them);
    accum_change.type = nnue::AccumulatorChange::kCapture;
    accum_change.sub_1 = {pawn_square, PieceType::kPawn, them};
  } else if (captured != PieceType::kNone) {
    state_.RemovePiece(to, them);
    new_fifty_move_clock = 0;
    accum_change.type = nnue::AccumulatorChange::kCapture;
    accum_change.sub_1 = {to, captured, them};
  } else {
    accum_change.type = nnue::AccumulatorChange::kNormal;
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
    accum_change.type = nnue::AccumulatorChange::kCastle;
    const Square rook_from = to;
    const Square rook_to = kRookEndSquares[CastleRights::CastleIndex(us, from > to ? CastleRights::kQueenside : CastleRights::kKingside)];
    accum_change.add_1 = {rook_to, PieceType::kRook, us};
    accum_change.sub_1 = {rook_from, PieceType::kRook, us};
  } else if (move_type == MoveType::kPromotion) {
    new_piece = PieceType(static_cast<int>(move.GetPromotionType()) + 1);
    accum_change.add_0.piece = new_piece;
  }

  if (move_type != MoveType::kCastle)
    state_.PlacePiece(to, new_piece, state_.turn);

  // Update the castling rights depending on the piece that moved
  state_.zobrist_key ^= zobrist::castle_rights[state_.castle_rights.AsU8()];

  if (piece == kRook) {
    const auto side = from > state_.King(us).GetLsb() ? CastleRights::kKingside : CastleRights::kQueenside;

    const Square sq = state_.castle_rights.CastleSquare(us, side);

    if (from == sq)
      state_.castle_rights.SetCastlingRights(us, side, kNoSquare);

  } else if (piece == kKing)
    state_.castle_rights.UnsetCastlingRights(us);
  if (state_.GetPieceType(to)) {
    const auto side = to > state_.King(them).GetLsb() ? CastleRights::kKingside : CastleRights::kQueenside;

    const Square sq = state_.castle_rights.CastleSquare(them, side);

    if (to == sq)
      state_.castle_rights.SetCastlingRights(them, side, kNoSquare);
  }

  state_.zobrist_key ^= zobrist::castle_rights[state_.castle_rights.AsU8()];

  state_.turn = FlipColor(state_.turn);
  state_.zobrist_key ^= zobrist::turn;

  state_.fifty_moves_clock = new_fifty_move_clock;
  ++state_.half_moves;

  CalculateThreats();

  // Push the accumulator change
  accumulator_->PushChanges(state_, accum_change);
}

void Board::UndoMove() {
  state_ = history_.PopBack();
  accumulator_->UndoMove();
}

void Board::UndoNullMove() {
  state_ = history_.PopBack();
}

void Board::MakeNullMove() {
  history_.Push(state_);

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

U64 Board::PredictKeyAfter(Move move) const {
  auto key = state_.zobrist_key ^ zobrist::turn;
  if (move == Move::NullMove()) {
    return key ^ zobrist::fifty_move[state_.fifty_moves_clock + 1];
  }

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

  const int new_fifty_moves_clock =
      (move.IsCapture(state_) || piece == kPawn ? 0
                                                : state_.fifty_moves_clock + 1);
  key ^= zobrist::fifty_move[new_fifty_moves_clock];

  return key;
}

bool Board::HasUpcomingRepetition(U16 ply) const {
  const int max_dist = std::min<int>(state_.fifty_moves_clock, history_.Size());
  if (max_dist < 3) {
    return false;
  }

  const auto keys_back = [this](int dist) {
    return history_[history_.Size() - dist].zobrist_key;
  };

  const auto occupied = state_.Occupied();

  for (int dist = 3; dist <= max_dist; dist += 2) {
    const auto move_key = keys_back(dist);
    const auto key_diff = state_.zobrist_key ^ move_key;

    U32 slot = search::cuckoo::H1(key_diff);
    if (key_diff != search::cuckoo::keys[slot]) {
      slot = search::cuckoo::H2(key_diff);
    }

    if (key_diff != search::cuckoo::keys[slot]) {
      continue;
    }

    const auto move = search::cuckoo::moves[slot];
    if ((occupied & move_gen::RayBetween(move.GetFrom(), move.GetTo())) == 0) {
      if (ply > dist) {
        return true;
      }

      auto square = move.GetFrom();
      if (state_.GetPieceType(square) == kNone) {
        square = move.GetTo();
      }

      if (state_.GetPieceColor(square) != state_.turn) {
        continue;
      }

      for (int j = dist + 4; j <= max_dist; j += 2) {
        if (keys_back(j) == keys_back(dist)) {
          return true;
        }
      }
    }
  }

  return false;
}

bool Board::IsRepetition(U16 ply) const {
  if (state_.fifty_moves_clock >= 100 &&
      (!state_.InCheck() || !GetLegalMoves().Empty())) {
    return true;
  }

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

bool Board::IsInsufficientMaterial() const {
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

  return false;
}

void Board::HandleCastling(Move move) {
  const Color us = state_.turn;

  const Square king_sq = move.GetFrom();
  const Square rook_sq = move.GetTo();

  const Square king_to = kKingEndSquares[CastleRights::CastleIndex(
      us, king_sq > rook_sq ? CastleRights::kQueenside : CastleRights::kKingside)];
  const Square rook_to = kRookEndSquares[CastleRights::CastleIndex(
      us, king_sq > rook_sq ? CastleRights::kQueenside : CastleRights::kKingside)];

  state_.RemovePiece(rook_sq, us);
  state_.PlacePiece(king_to, PieceType::kKing, us);
  state_.PlacePiece(rook_to, PieceType::kRook, us);
}

void Board::CalculateThreats() {
  const Color them = FlipColor(state_.turn);

  state_.threatened_by[kPawn] = move_gen::PawnAttacks(state_.Pawns(them), them);

  state_.threatened_by[kKnight] = 0;
  for (Square square : state_.Knights(them)) {
    state_.threatened_by[kKnight] |= move_gen::KnightMoves(square);
  }

  const BitBoard queens = state_.Queens(them);
  const BitBoard occupied = state_.Occupied();

  state_.threatened_by[kBishop] = 0;
  state_.threatened_by[kQueen] = 0;
  state_.threatened_by[kRook] = 0;

  for (Square square : state_.Bishops(them) | queens) {
    state_.threatened_by[(queens.IsSet(square) ? kQueen : kBishop)] |=
        move_gen::BishopMoves(square, occupied);
  }

  for (Square square : state_.Rooks(them) | queens) {
    state_.threatened_by[(queens.IsSet(square) ? kQueen : kRook)] |=
        move_gen::RookMoves(square, occupied);
  }

  state_.threatened_by[kKing] =
      move_gen::KingAttacks(state_.King(them).GetLsb());

  state_.threats = state_.threatened_by[kPawn] | state_.threatened_by[kKnight] |
                   state_.threatened_by[kBishop] | state_.threatened_by[kRook] |
                   state_.threatened_by[kQueen] | state_.threatened_by[kKing];

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
  state_.pinned[us] = 0;

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
      state_.pinned[us] |= pinned;
    }
  }
}

BitBoard Board::GetOpponentWinningCaptures() const {
  const Color us = state_.turn;

  const BitBoard queens = state_.Queens(us);
  const BitBoard rooks = queens | state_.Rooks(us);
  const BitBoard minors = rooks | state_.Knights(us) | state_.Bishops(us);

  const BitBoard pawn_threats = state_.threatened_by[kPawn];
  const BitBoard minor_threats = pawn_threats | state_.threatened_by[kKnight] |
                                 state_.threatened_by[kBishop];
  const BitBoard rook_threats = minor_threats | state_.threatened_by[kRook];

  return (queens & rook_threats) | (rooks & minor_threats) |
         (minors & pawn_threats);
}

MoveList Board::GetLegalMoves() const {
  auto move_list = move_gen::GenerateMoves<MoveGenType::kAll>(*this);
  auto legal_move_list = MoveList{};

  for (int i = 0; i < move_list.Size(); i++) {
    const auto move = move_list[i];
    if (IsMoveLegal(move)) {
      legal_move_list.Push(move);
    }
  }

  return legal_move_list;
}

void Board::PrintPieces() {
  for (int rank = kNumRanks - 1; rank >= 0; rank--) {
    fmt::print("{} ", rank + 1);
    for (int file = 0; file < kNumFiles; file++) {
      const auto square = Square::FromRankFile(rank, file);
      fmt::print("{}", fen::GetPieceChar(state_, square));
      if (file < kNumFiles - 1) fmt::print(" ");  // Space separator for clarity
    }
    fmt::print("\n");
  }
  fmt::print("  ");
  for (int file = 0; file < kNumFiles; file++)
    fmt::print("{} ", static_cast<char>('a' + file));
  fmt::print("\n");
}