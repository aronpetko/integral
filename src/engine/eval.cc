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

// clang-format off
constexpr std::array<ScorePair, PieceType::kNumTypes> kPieceValues = {
    PAIR(100, 110),  // Pawn
    PAIR(300, 280),  // Knight
    PAIR(305, 295),  // Bishop
    PAIR(500, 520),  // Rook
    PAIR(900, 880),  // Queen
    PAIR(0, 0)       // King
};

using PieceSquareTable = std::array<std::array<ScorePair, Squares::kSquareCount>,
                                    PieceType::kNumTypes>;

constexpr PieceSquareTable kPieceSquareTables = {{
  { // Pawns
    PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0),
    PAIR(50, 50), PAIR(50, 50), PAIR(50, 50), PAIR(50, 50), PAIR(50, 50), PAIR(50, 50), PAIR(50, 50), PAIR(50, 50),
    PAIR(10, 20), PAIR(10, 20), PAIR(20, 30), PAIR(30, 40), PAIR(30, 40), PAIR(20, 30), PAIR(10, 20), PAIR(10, 20),
    PAIR(5, 10), PAIR(5, 15), PAIR(10, 25), PAIR(25, 35), PAIR(25, 35), PAIR(10, 25), PAIR(5, 15), PAIR(5, 10),
    PAIR(0, 5), PAIR(0, 10), PAIR(0, 20), PAIR(20, 30), PAIR(20, 30), PAIR(0, 20), PAIR(0, 10), PAIR(0, 5),
    PAIR(5, 0), PAIR(-5, 5), PAIR(-10, 10), PAIR(0, 20), PAIR(0, 20), PAIR(-10, 10), PAIR(-5, 5), PAIR(5, 0),
    PAIR(5, 5), PAIR(10, 10), PAIR(10, 10), PAIR(-20, -5), PAIR(-20, -5), PAIR(10, 10), PAIR(10, 10), PAIR(5, 5),
    PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0)
  },
  { // Knights
     PAIR(-50, -50), PAIR(-40, -40), PAIR(-30, -30), PAIR(-30, -30), PAIR(-30, -30), PAIR(-30, -30), PAIR(-40, -40), PAIR(-50, -50),
     PAIR(-40, -40), PAIR(-20, -20), PAIR(0, 5), PAIR(0, 5), PAIR(0, 5), PAIR(0, 5), PAIR(-20, -20), PAIR(-40, -40),
     PAIR(-30, -30), PAIR(0, 5), PAIR(10, 20), PAIR(15, 25), PAIR(15, 25), PAIR(10, 20), PAIR(0, 5), PAIR(-30, -30),
     PAIR(-30, -30), PAIR(5, 10), PAIR(15, 25), PAIR(20, 30), PAIR(20, 30), PAIR(15, 25), PAIR(5, 10), PAIR(-30, -30),
     PAIR(-30, -30), PAIR(0, 5), PAIR(15, 25), PAIR(20, 30), PAIR(20, 30), PAIR(15, 25), PAIR(0, 5), PAIR(-30, -30),
     PAIR(-30, -30), PAIR(5, 10), PAIR(10, 20), PAIR(15, 25), PAIR(15, 25), PAIR(10, 20), PAIR(5, 10), PAIR(-30, -30),
     PAIR(-40, -40), PAIR(-20, -20), PAIR(0, 5), PAIR(5, 10), PAIR(5, 10), PAIR(0, 5), PAIR(-20, -20), PAIR(-40, -40),
     PAIR(-50, -50), PAIR(-40, -40), PAIR(-30, -30), PAIR(-30, -30), PAIR(-30, -30), PAIR(-30, -30), PAIR(-40, -40), PAIR(-50, -50)
  }, // Bishops
  {
     PAIR(-20, -20), PAIR(-10, -10), PAIR(-10, -10), PAIR(-10, -10), PAIR(-10, -10), PAIR(-10, -10), PAIR(-10, -10), PAIR(-20, -20),
     PAIR(-10, -10), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(-10, -10),
     PAIR(-10, -10), PAIR(0, 5), PAIR(5, 10), PAIR(10, 15), PAIR(10, 15), PAIR(5, 10), PAIR(0, 5), PAIR(-10, -10),
     PAIR(-10, -10), PAIR(5, 10), PAIR(5, 15), PAIR(10, 25), PAIR(10, 25), PAIR(5, 15), PAIR(5, 10), PAIR(-10, -10),
     PAIR(-10, -10), PAIR(0, 5), PAIR(10, 15), PAIR(10, 25), PAIR(10, 25), PAIR(10, 15), PAIR(0, 5), PAIR(-10, -10),
     PAIR(-10, -10), PAIR(10, 10), PAIR(10, 15), PAIR(10, 15), PAIR(10, 15), PAIR(10, 15), PAIR(10, 10), PAIR(-10, -10),
     PAIR(-10, -10), PAIR(5, 0), PAIR(0, 5), PAIR(0, 10), PAIR(0, 10), PAIR(0, 5), PAIR(5, 0), PAIR(-10, -10),
     PAIR(-20, -20), PAIR(-10, -10), PAIR(-10, -10), PAIR(-10, -10), PAIR(-10, -10), PAIR(-10, -10), PAIR(-10, -10), PAIR(-20, -20)
  },
  { // Rooks
     PAIR(0, 10), PAIR(0, 15), PAIR(0, 15), PAIR(0, 20), PAIR(0, 20), PAIR(0, 15), PAIR(0, 10), PAIR(0, 5),
     PAIR(5, 5), PAIR(10, 10), PAIR(10, 10), PAIR(10, 15), PAIR(10, 15), PAIR(10, 10), PAIR(10, 5), PAIR(5, 0),
     PAIR(-5, 5), PAIR(0, 10), PAIR(0, 10), PAIR(0, 10), PAIR(0, 10), PAIR(0, 10), PAIR(0, 5), PAIR(-5, 0),
     PAIR(-5, 0), PAIR(0, 5), PAIR(0, 10), PAIR(0, 10), PAIR(0, 10), PAIR(0, 5), PAIR(0, 0), PAIR(-5, -5),
     PAIR(-5, -5), PAIR(0, 0), PAIR(0, 5), PAIR(0, 5), PAIR(0, 5), PAIR(0, 0), PAIR(-5, -5), PAIR(-5, -10),
     PAIR(-5, -10), PAIR(0, -5), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, -5), PAIR(-5, -10), PAIR(-5, -15),
     PAIR(-5, -15), PAIR(0, -10), PAIR(0, -5), PAIR(0, 0), PAIR(0, 0), PAIR(0, -5), PAIR(-5, -10), PAIR(-5, -20),
     PAIR(0, -20), PAIR(0, -15), PAIR(0, -10), PAIR(5, -5), PAIR(5, -5), PAIR(0, -10), PAIR(0, -15), PAIR(0, -20)
  },
  { // Queens
     PAIR(-20, -20), PAIR(-10, -10), PAIR(-10, -10), PAIR(-5, -5), PAIR(-5, -5), PAIR(-10, -10), PAIR(-10, -10), PAIR(-20, -20),
     PAIR(-10, -10), PAIR(0, 5), PAIR(0, 5), PAIR(0, 5), PAIR(0, 5), PAIR(0, 5), PAIR(0, 5), PAIR(-10, -10),
     PAIR(-10, -5), PAIR(0, 10), PAIR(5, 10), PAIR(5, 10), PAIR(5, 10), PAIR(5, 10), PAIR(0, 10), PAIR(-10, -5),
     PAIR(-5, 0), PAIR(0, 10), PAIR(5, 15), PAIR(5, 20), PAIR(5, 20), PAIR(5, 15), PAIR(0, 10), PAIR(-5, 0),
     PAIR(0, 5), PAIR(0, 15), PAIR(5, 20), PAIR(5, 25), PAIR(5, 25), PAIR(5, 20), PAIR(0, 15), PAIR(-5, 5),
     PAIR(-10, -5), PAIR(5, 10), PAIR(5, 20), PAIR(5, 20), PAIR(5, 20), PAIR(5, 20), PAIR(0, 10), PAIR(-10, -5),
     PAIR(-10, -10), PAIR(0, 5), PAIR(0, 10), PAIR(0, 10), PAIR(0, 10), PAIR(0, 10), PAIR(0, 5), PAIR(-10, -10),
     PAIR(-20, -20), PAIR(-10, -10), PAIR(-10, -5), PAIR(-5, 0), PAIR(-5, 0), PAIR(-10, -5), PAIR(-10, -10), PAIR(-20, -20)
  },
  { // King
     PAIR(-30, 30), PAIR(-40, 40), PAIR(-40, 40), PAIR(-50, 50), PAIR(-50, 50), PAIR(-40, 40), PAIR(-40, 40), PAIR(-30, 30),
     PAIR(-30, 20), PAIR(-40, 20), PAIR(-40, 30), PAIR(-50, 40), PAIR(-50, 40), PAIR(-40, 30), PAIR(-40, 20), PAIR(-30, 20),
     PAIR(-30, 10), PAIR(-40, 10), PAIR(-40, 20), PAIR(-50, 30), PAIR(-50, 30), PAIR(-40, 20), PAIR(-40, 10), PAIR(-30, 10),
     PAIR(-30, 0), PAIR(-40, 5), PAIR(-40, 15), PAIR(-50, 30), PAIR(-50, 30), PAIR(-40, 15), PAIR(-40, 5), PAIR(-30, 0),
     PAIR(-20, -10), PAIR(-30, 0), PAIR(-30, 10), PAIR(-40, 20), PAIR(-40, 20), PAIR(-30, 10), PAIR(-30, 0), PAIR(-20, -10),
     PAIR(-10, -20), PAIR(-20, -5), PAIR(-20, 5), PAIR(-20, 10), PAIR(-20, 10), PAIR(-20, 5), PAIR(-20, -5), PAIR(-10, -20),
     PAIR(20, -30), PAIR(20, -10), PAIR(0, -10), PAIR(0, 0), PAIR(0, 0), PAIR(0, -10), PAIR(20, -10), PAIR(20, -30),
     PAIR(20, -50), PAIR(30, -30), PAIR(10, -30), PAIR(0, -20), PAIR(0, -20), PAIR(10, -30), PAIR(30, -30), PAIR(20, -50)
  },
}};

constexpr std::array<ScorePair, 9> kKnightMobility = {
  PAIR(-5, -20), PAIR(5, 10), PAIR(23, 28), PAIR(29, 34), PAIR(36, 41),
  PAIR(40, 45), PAIR(48, 53), PAIR(48, 53), PAIR(51, 56)
};

constexpr std::array<ScorePair, 15> kRookMobility = {
  PAIR(-10, 0), PAIR(-5, 5), PAIR(0, 10), PAIR(5, 15), PAIR(5, 15),
  PAIR(10, 20), PAIR(13, 23), PAIR(18, 28), PAIR(25, 35), PAIR(34, 44),
  PAIR(38, 48), PAIR(42, 52), PAIR(47, 57), PAIR(50, 60), PAIR(55, 65)
};

constexpr std::array<ScorePair, 14> kBishopMobility = {
  PAIR(3, 8), PAIR(12, 17), PAIR(21, 26), PAIR(23, 28),
  PAIR(31, 36), PAIR(39, 44), PAIR(46, 51), PAIR(50, 55),
  PAIR(50, 55), PAIR(53, 58), PAIR(56, 61), PAIR(60, 65),
  PAIR(59, 64), PAIR(92, 97)
};

constexpr std::array<ScorePair, 28> kQueenMobility = {{
  PAIR(-71, -25), PAIR(-70, -84), PAIR(-73, -50), PAIR(-70, -35),
  PAIR(-67, -35), PAIR(-63, -26), PAIR(-59, -20), PAIR(-61, 1),
  PAIR(-59, 12),  PAIR(-55, 14),  PAIR(-55, 27),  PAIR(-55, 34),
  PAIR(-53, 42),  PAIR(-52, 49),  PAIR(-50, 54),  PAIR(-49, 59),
  PAIR(-46, 64),  PAIR(-49, 77),  PAIR(-44, 81),  PAIR(-42, 82),
  PAIR(-35, 84),  PAIR(-30, 84),  PAIR(-28, 84),  PAIR(-15, 80),
  PAIR(-2, 66),   PAIR(52, 49),   PAIR(64, 43),   PAIR(189, -16)
}};

constexpr std::array<ScorePair, Squares::kSquareCount> kPassedPawnTable = {{
  PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0),
  PAIR(48 + 50, 100 + 50), PAIR(48 + 50, 100 + 50), PAIR(48 + 50, 115 + 50), PAIR(48 + 50, 120 + 50), PAIR(48 + 50, 120 + 50), PAIR(48 + 50, 115 + 50), PAIR(48 + 50, 100 + 50), PAIR(48 + 50, 100 + 50),
  PAIR(7 + 10, 100 + 20), PAIR(7 + 10, 105 + 20), PAIR(7 + 20, 115 + 30), PAIR(7 + 30, 119 + 40), PAIR(7 + 30, 119 + 40), PAIR(7 + 20, 115 + 30), PAIR(7 + 10, 105 + 20), PAIR(7 + 10, 100 + 20),
  PAIR(12 + 5, 80 + 10), PAIR(12 + 5, 85 + 15), PAIR(12 + 10, 90 + 25), PAIR(12 + 25, 95 + 35), PAIR(12 + 25, 95 + 35), PAIR(12 + 10, 90 + 25), PAIR(12 + 5, 85 + 15), PAIR(12 + 5, 80 + 10),
  PAIR(-8 + 0, 60 + 5), PAIR(-8 + 0, 62 + 10), PAIR(-8 + 0, 67 + 20), PAIR(-8 + 20, 70 + 30), PAIR(-8 + 20, 70 + 30), PAIR(-8 + 0, 67 + 20), PAIR(-8 + 0, 62 + 10), PAIR(-8 + 0, 60 + 5),
  PAIR(-7 + 5, 40 + 0), PAIR(-7 - 5, 42 + 5), PAIR(-7 - 10, 45 + 10), PAIR(-7 + 0, 50 + 20), PAIR(-7 + 0, 50 + 20), PAIR(-7 - 10, 45 + 10), PAIR(-7 - 5, 42 + 5), PAIR(-7 + 5, 40 + 0),
  PAIR(-2 + 5, 20 + 5), PAIR(-2 + 10, 22 + 10), PAIR(-2 + 10, 25 + 10), PAIR(-2 - 20, 30 - 5), PAIR(-2 - 20, 30 - 5), PAIR(-2 + 10, 25 + 10), PAIR(-2 + 10, 22 + 10), PAIR(-2 + 5, 20 + 5),
  PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0), PAIR(0, 0)
}};

constexpr std::array<int, PieceType::kNumTypes> kGamePhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

std::pair<ScorePair, int> EvaluateMaterialAndPhase(const BoardState &state) {
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

  ScorePair score;
  score += kPieceValues[PieceType::kPawn] * pawn_count;
  score += kPieceValues[PieceType::kKnight] * knight_count;
  score += kPieceValues[PieceType::kBishop] * bishop_count;
  score += kPieceValues[PieceType::kRook] * rook_count;
  score += kPieceValues[PieceType::kQueen] * queen_count;

  int phase = 0;
  phase += kGamePhaseIncrements[PieceType::kKnight] * knights.PopCount();
  phase += kGamePhaseIncrements[PieceType::kBishop] * bishops.PopCount();
  phase += kGamePhaseIncrements[PieceType::kRook] * rooks.PopCount();
  phase += kGamePhaseIncrements[PieceType::kQueen] * queens.PopCount();

  return {score, phase};
}

ScorePair EvaluatePieceSquares(const BoardState &state) {
  ScorePair score;
  const Color us = state.turn, them = FlipColor(us);

  BitBoard our_pieces = state.Occupied(us);
  BitBoard their_pieces = state.Occupied(them);
  BitBoard our_pawns = state.Pawns(us);
  BitBoard their_pawns = state.Pawns(them);

  while (our_pieces) {
    const auto square = our_pieces.PopLsb();
    const auto piece_type = state.GetPieceType(square);

    bool passed_pawn = false;
    if (piece_type == PieceType::kPawn) {
      const BitBoard enemy_pawns_ahead =
          ForwardFileMask(us, square) & their_pawns;
      if (enemy_pawns_ahead == 0) {
        passed_pawn = true;
      }
    }

    if (passed_pawn) {
      score += kPassedPawnTable[RelativeSquare(square, us)];
      std::cout << kPassedPawnTable[RelativeSquare(square, us)].EndGame() << std::endl;
    } else {
      score += kPieceSquareTables[piece_type][RelativeSquare(square, us)];
    }
  }

  while (their_pieces) {
    const auto square = their_pieces.PopLsb();
    const auto piece_type = state.GetPieceType(square);

    bool passed_pawn = false;
    if (piece_type == PieceType::kPawn) {
      const BitBoard enemy_pawns_ahead =
          ForwardFileMask(them, square) & our_pawns;
      if (enemy_pawns_ahead == 0) {
        passed_pawn = true;
      }
    }

    if (passed_pawn) {
      score -= kPassedPawnTable[RelativeSquare(square, them)];
    } else {
      score -= kPieceSquareTables[piece_type][RelativeSquare(square, them)];
    }
  }

  return score;
}

ScorePair EvaluateKnights(const BoardState &state) {
  ScorePair score;
  const Color us = state.turn, them = FlipColor(us);
  const BitBoard our_pieces = state.Occupied(us),
                 their_pieces = state.Occupied(them);

  BitBoard our_knights = state.Knights(us);
  while (our_knights) {
    const auto square = our_knights.PopLsb();
    const auto moves = move_gen::KnightMoves(square) & ~our_pieces;
    score += kKnightMobility[moves.PopCount()];
  }

  BitBoard their_knights = state.Knights(them);
  while (their_knights) {
    const auto square = their_knights.PopLsb();
    const auto moves = move_gen::KnightMoves(square) & ~their_pieces;
    score -= kKnightMobility[moves.PopCount()];
  }

  return score;
}

ScorePair EvaluateRooks(const BoardState &state) {
  ScorePair score;
  const Color us = state.turn, them = FlipColor(us);
  const BitBoard our_pieces = state.Occupied(us),
                 their_pieces = state.Occupied(them),
                 occupied = our_pieces | their_pieces;

  BitBoard our_rooks = state.Rooks(us);
  while (our_rooks) {
    const auto square = our_rooks.PopLsb();
    const auto moves = move_gen::RookMoves(square, occupied) & ~our_pieces;
    score += kRookMobility[moves.PopCount()];
  }

  BitBoard their_rooks = state.Rooks(them);
  while (their_rooks) {
    const auto square = their_rooks.PopLsb();
    const auto moves = move_gen::RookMoves(square, occupied) & ~their_pieces;
    score -= kRookMobility[moves.PopCount()];
  }

  return score;
}

ScorePair EvaluateBishops(const BoardState &state) {
  ScorePair score;
  const Color us = state.turn, them = FlipColor(us);
  const BitBoard our_pieces = state.Occupied(us),
                 their_pieces = state.Occupied(them),
                 occupied = our_pieces | their_pieces;

  BitBoard our_bishops = state.Bishops(us);
  while (our_bishops) {
    const auto square = our_bishops.PopLsb();
    const auto moves = move_gen::BishopMoves(square, occupied) & ~our_pieces;
    score += kBishopMobility[moves.PopCount()];
  }

  BitBoard their_bishops = state.Bishops(them);
  while (their_bishops) {
    const auto square = their_bishops.PopLsb();
    const auto moves = move_gen::BishopMoves(square, occupied) & ~their_pieces;
    score -= kBishopMobility[moves.PopCount()];
  }

  return score;
}

ScorePair EvaluateQueens(const BoardState &state) {
  ScorePair score;
  const Color us = state.turn, them = FlipColor(us);
  const BitBoard our_pieces = state.Occupied(us),
                 their_pieces = state.Occupied(them),
                 occupied = our_pieces | their_pieces;

  BitBoard our_queens = state.Queens(us);
  while (our_queens) {
    const auto square = our_queens.PopLsb();
    const auto moves = move_gen::QueenMoves(square, occupied) & ~our_pieces;
    score += kQueenMobility[moves.PopCount()];
  }

  BitBoard their_queens = state.Queens(them);
  while (their_queens) {
    const auto square = their_queens.PopLsb();
    const auto moves = move_gen::QueenMoves(square, occupied) & ~their_pieces;
    score -= kQueenMobility[moves.PopCount()];
  }

  return score;
}

Score Evaluate(const BoardState &state) {
  constexpr int kMaxPhase = 24;
  // Scaling factor to maintain precision in integer calculations
  constexpr int kScaleFactor = 1000;

  auto [material_score, phase] = EvaluateMaterialAndPhase(state);
  auto score_pair = material_score + EvaluatePieceSquares(state) +
                    EvaluateKnights(state) + EvaluateBishops(state) +
                    EvaluateRooks(state) + EvaluateQueens(state);

  phase = std::min(phase, kMaxPhase);
  const int phase_percent = 100 * (kMaxPhase - phase) / kMaxPhase;

  // Convert to a scale factor between 0 and kScaleFactor
  const int interpolation_factor = kScaleFactor * phase_percent / 100;

  // Interpolate between middle game and end game scores
  const int mid_score =
      score_pair.MiddleGame() * (kScaleFactor - interpolation_factor);
  const int end_score = score_pair.EndGame() * interpolation_factor;
  Score tapered_eval = (mid_score + end_score) / kScaleFactor;

  tapered_eval = std::clamp(tapered_eval, -kMateScore + 1, kMateScore - 1);

  constexpr Score kTempoBonus = 10;
  return static_cast<Score>(tapered_eval + kTempoBonus);
}

}  // namespace eval