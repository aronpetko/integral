#include "eval.h"

#include "../chess/move_gen.h"

namespace eval {

bool StaticExchange(Move move, int threshold, const BoardState &state) {
  const auto from = move.GetFrom();
  const auto to = move.GetTo();

  const PieceType &from_piece = state.GetPieceType(from);
  if (from_piece == PieceType::kPawn &&
          to == state.en_passant ||  // Ignore en passant captures
      from_piece == PieceType::kKing &&
          std::abs(from - to) == 2) {  // Ignore castling moves
    return threshold <= 0;
  }

  // Score represents the maximum number of points the opponent can gain with
  // the next capture
  Score score = kSEEPieceScores[state.GetPieceType(to)] - threshold;
  // If the captured piece is worth less than what we can give up, we lose
  if (score < 0) {
    return false;
  }

  score = kSEEPieceScores[from_piece] - score;
  // If we captured a piece with equal/greater value than our capturing piece,
  // we win
  if (score <= 0) {
    return true;
  }

  const BitBoard &pawns = state.Pawns();
  const BitBoard &knights = state.Knights();
  const BitBoard &bishops = state.Bishops();
  const BitBoard &rooks = state.Rooks();
  const BitBoard &queens = state.Queens();
  const BitBoard &kings = state.Kings();

  BitBoard occupied = state.Occupied();
  occupied.ClearBit(from);
  occupied.ClearBit(to);

  // Get all pieces that attack the capture square
  auto pawn_attackers = (move_gen::PawnAttacks(to, state, Color::kWhite) &
                         state.Pawns(Color::kBlack)) |
                        (move_gen::PawnAttacks(to, state, Color::kBlack) &
                         state.Pawns(Color::kWhite));
  auto knight_attackers = move_gen::KnightMoves(to) & state.Knights();

  BitBoard bishop_attacks = move_gen::BishopMoves(to, occupied);
  BitBoard rook_attacks = move_gen::RookMoves(to, occupied);

  const BitBoard bishop_attackers = bishop_attacks & bishops;
  const BitBoard rook_attackers = rook_attacks & rooks;
  const BitBoard queen_attackers = (bishop_attacks | rook_attacks) & queens;
  const BitBoard king_attackers = move_gen::KingAttacks(to) & kings;

  // Compute all attacking pieces for this square minus the captured and
  // capturing piece
  BitBoard all_attackers = pawn_attackers | knight_attackers |
                           bishop_attackers | rook_attackers | queen_attackers |
                           king_attackers;
  all_attackers &= occupied;

  Color turn = state.turn;
  Color winner = state.turn;

  // Loop through all pieces that attack the capture square
  while (true) {
    turn = FlipColor(turn);
    all_attackers &= occupied;

    const BitBoard our_attackers = all_attackers & state.Occupied(turn);
    // If the current side to move has no attackers left, they lose
    if (!our_attackers) {
      break;
    }

    // Without considering piece values, the winner of an exchange is whoever
    // has more attackers, therefore we set the winner's side to the current
    // side to move only after we check if they can attack
    winner = FlipColor(winner);

    // Find the least valuable attacker
    BitBoard next_attacker;
    int attacker_value;

    if ((next_attacker = our_attackers & pawns)) {
      attacker_value = kSEEPieceScores[PieceType::kPawn];
      occupied.ClearBit(next_attacker.GetLsb());

      // Add pieces that were diagonal xray attacking the captured piece
      bishop_attacks = move_gen::BishopMoves(to, occupied);
      all_attackers |= bishop_attacks & (bishops | queens);
    } else if ((next_attacker = our_attackers & knights)) {
      attacker_value = kSEEPieceScores[PieceType::kKnight];
      occupied ^= BitBoard::FromSquare(next_attacker.GetLsb());
    } else if ((next_attacker = our_attackers & bishops)) {
      attacker_value = kSEEPieceScores[PieceType::kBishop];
      occupied.ClearBit(next_attacker.GetLsb());

      // Add pieces that were xray attacking the captured piece
      bishop_attacks = move_gen::BishopMoves(to, occupied);
      all_attackers |= bishop_attacks & (bishops | queens);
    } else if ((next_attacker = our_attackers & rooks)) {
      attacker_value = kSEEPieceScores[PieceType::kRook];
      occupied.ClearBit(next_attacker.GetLsb());

      // Add pieces that were xray attacking the captured piece
      rook_attacks = move_gen::RookMoves(to, occupied);
      all_attackers |= rook_attacks & (rooks | queens);
    } else if ((next_attacker = our_attackers & queens)) {
      attacker_value = kSEEPieceScores[PieceType::kQueen];
      occupied.ClearBit(next_attacker.GetLsb());

      // Add pieces that were xray attacking the captured piece
      rook_attacks = move_gen::RookMoves(to, occupied);
      bishop_attacks = move_gen::BishopMoves(to, occupied);
      all_attackers |= (rook_attacks & (queens | rooks)) |
                       (bishop_attacks & (queens | bishops));
    } else {
      // King: check if we capture a piece that our opponent is still attacking
      return (all_attackers & state.Occupied(FlipColor(turn)))
                 ? state.turn != winner
                 : state.turn == winner;
    }

    // Score represents how many points the other side can gain after this
    // capture. If initially a knight captured a queen, the other side can
    // gain 3 - 9 = -6 points. If we flip it and initially a queen captured a
    // knight, the other side can gain 9 - 3 = 6 points
    score = -score + 1 + attacker_value;

    // Quit early if the exchange is lost or neutral
    if (score <= 0) {
      break;
    }
  }

  return state.turn == winner;
}

constexpr std::array kPieceValues = {100, 300, 305, 500, 900};

// clang-format off
constexpr std::array<std::array<Score, Square::kSquareCount>, PieceType::kNumTypes> kPieceSquareTables = {{
  { // Pawns
    0,   0,  0,  0,  0,  0,  0,  0,
    50, 50, 50, 50, 50, 50, 50, 50,
    10, 10, 20, 30, 30, 20, 10, 10,
    5,  5, 10, 25, 25, 10,  5,  5,
    0,  0,  0, 20, 20,  0,  0,  0,
    5, -5,-10,  0,  0,-10, -5,  5,
    5, 10, 10,-20,-20, 10, 10,  5,
    0,  0,  0,  0,  0,  0,  0,  0
  },
  { // Knights
    -50,-40,-30,-30,-30,-30,-40,-50,
    -40,-20,  0,  0,  0,  0,-20,-40,
    -30,  0, 10, 15, 15, 10,  0,-30,
    -30,  5, 15, 20, 20, 15,  5,-30,
    -30,  0, 15, 20, 20, 15,  0,-30,
    -30,  5, 10, 15, 15, 10,  5,-30,
    -40,-20,  0,  5,  5,  0,-20,-40,
    -50,-40,-30,-30,-30,-30,-40,-50,
  }, // Bishops
  {
    -20,-10,-10,-10,-10,-10,-10,-20,
    -10,  0,  0,  0,  0,  0,  0,-10,
    -10,  0,  5, 10, 10,  5,  0,-10,
    -10,  5,  5, 10, 10,  5,  5,-10,
    -10,  0, 10, 10, 10, 10,  0,-10,
    -10, 10, 10, 10, 10, 10, 10,-10,
    -10,  5,  0,  0,  0,  0,  5,-10,
    -20,-10,-10,-10,-10,-10,-10,-20,
  },
  { // Rooks
     0,  0,  0,  0,  0,  0,  0,  0,
     5, 10, 10, 10, 10, 10, 10,  5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
    -5,  0,  0,  0,  0,  0,  0, -5,
     0,  0,  0,  5,  5,  0,  0,  0
  },
  { // Queens
    -20,-10,-10, -5, -5,-10,-10,-20,
    -10,  0,  0,  0,  0,  0,  0,-10,
    -10,  0,  5,  5,  5,  5,  0,-10,
    -5,   0,  5,  5,  5,  5,  0, -5,
     0,   0,  5,  5,  5,  5,  0, -5,
    -10,  5,  5,  5,  5,  5,  0,-10,
    -10,  0,  5,  0,  0,  0,  0,-10,
    -20,-10,-10, -5, -5,-10,-10,-20
  },
  { // King
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30,
    -20,-30,-30,-40,-40,-30,-30,-20,
    -10,-20,-20,-20,-20,-20,-20,-10,
     20, 20,  0,  0,  0,  0, 20, 20,
     20, 30, 10,  0,  0, 10, 30, 20
  },
}};

constexpr std::array<Score, 9> kKnightMobility = {5, 23, 29, 36, 40, 48, 48, 51};
constexpr std::array<Score, 15> kRookMobility = {-10, -5, 0, 5, 5, 10, 13, 18, 25, 34, 38, 42, 47, 50, 55};
constexpr std::array<Score, 14> kBishopMobility = {3, 12, 21, 23, 31, 39, 46, 50, 50, 53, 56, 60, 59, 92};
// clang-format on

Score EvaluateMaterial(const BoardState &state) {
  Score score = 0;
  const Color us = state.turn, them = FlipColor(us);

  const BitBoard our_pieces = state.Occupied(us);
  const BitBoard their_pieces = state.Occupied(them);

  const BitBoard pawns = state.Pawns();
  const BitBoard knights = state.Knights();
  const BitBoard bishops = state.Bishops();
  const BitBoard rooks = state.Rooks();
  const BitBoard queens = state.Queens();

  const int pawn_count =
      (pawns & our_pieces).PopCount() - (pawns & their_pieces).PopCount();
  const int knight_count =
      (knights & our_pieces).PopCount() - (knights & their_pieces).PopCount();
  const int bishop_count =
      (bishops & our_pieces).PopCount() - (bishops & their_pieces).PopCount();
  const int rook_count =
      (rooks & our_pieces).PopCount() - (rooks & their_pieces).PopCount();
  const int queen_count =
      (queens & our_pieces).PopCount() - (queens & their_pieces).PopCount();

  score += kPieceValues[PieceType::kPawn] * pawn_count;
  score += kPieceValues[PieceType::kKnight] * knight_count;
  score += kPieceValues[PieceType::kBishop] * bishop_count;
  score += kPieceValues[PieceType::kRook] * rook_count;
  score += kPieceValues[PieceType::kQueen] * queen_count;

  return score;
}

Score EvaluatePieceSquares(const BoardState &state) {
  Score score = 0;
  const Color us = state.turn, them = FlipColor(us);

  BitBoard our_pieces = state.Occupied(us);
  while (our_pieces) {
    const auto square = Square(our_pieces.PopLsb());
    const auto piece_type = state.GetPieceType(square);
    score += kPieceSquareTables[piece_type][RelativeSquare(square, us)];
  }

  BitBoard their_pieces = state.Occupied(them);
  while (their_pieces) {
    const auto square = Square(their_pieces.PopLsb());
    const auto piece_type = state.GetPieceType(square);
    score -= kPieceSquareTables[piece_type][RelativeSquare(square, them)];
  }

  return score;
}

Score EvaluateKnights(const BoardState &state) {
  Score score = 0;
  const Color us = state.turn, them = FlipColor(us);
  const BitBoard our_pieces = state.Occupied(us),
                 their_pieces = state.Occupied(them);

  BitBoard our_knights = state.Knights(us);
  while (our_knights) {
    const auto square = Square(our_knights.PopLsb());
    const auto moves = move_gen::KnightMoves(square) & ~our_pieces;
    score += kKnightMobility[moves.PopCount()];
  }

  BitBoard their_knights = state.Knights(them);
  while (their_knights) {
    const auto square = Square(their_knights.PopLsb());
    const auto moves = move_gen::KnightMoves(square) & ~their_pieces;
    score -= kKnightMobility[moves.PopCount()];
  }

  return score;
}

Score EvaluateRooks(const BoardState &state) {
  Score score = 0;
  const Color us = state.turn, them = FlipColor(us);
  const BitBoard our_pieces = state.Occupied(us),
                 their_pieces = state.Occupied(them),
                 occupied = our_pieces | their_pieces;

  BitBoard our_rooks = state.Rooks(us);
  while (our_rooks) {
    const auto square = Square(our_rooks.PopLsb());
    const auto moves = move_gen::RookMoves(square, occupied) & ~our_pieces;
    score += kRookMobility[moves.PopCount()];
  }

  BitBoard their_rooks = state.Rooks(them);
  while (their_rooks) {
    const auto square = Square(their_rooks.PopLsb());
    const auto moves = move_gen::RookMoves(square, occupied) & ~their_pieces;
    score -= kRookMobility[moves.PopCount()];
  }

  return score;
}

Score EvaluateBishops(const BoardState &state) {
  Score score = 0;
  const Color us = state.turn, them = FlipColor(us);
  const BitBoard our_pieces = state.Occupied(us),
                 their_pieces = state.Occupied(them),
                 occupied = our_pieces | their_pieces;

  BitBoard our_bishops = state.Bishops(us);
  while (our_bishops) {
    const auto square = Square(our_bishops.PopLsb());
    const auto moves = move_gen::BishopMoves(square, occupied) & ~our_pieces;
    score += kBishopMobility[moves.PopCount()];
  }

  BitBoard their_bishops = state.Bishops(them);
  while (their_bishops) {
    const auto square = Square(their_bishops.PopLsb());
    const auto moves = move_gen::BishopMoves(square, occupied) & ~their_pieces;
    score -= kBishopMobility[moves.PopCount()];
  }

  return score;
}

Score Evaluate(const BoardState &state) {
  constexpr Score kTempoBonus = 10;
  return EvaluateMaterial(state) + EvaluatePieceSquares(state) +
         EvaluateKnights(state) + EvaluateRooks(state) +
         EvaluateBishops(state) + kTempoBonus;
}

}  // namespace eval