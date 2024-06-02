#include "eval.h"

#include "../chess/move_gen.h"
#include "../tuner/tuner.h"

namespace eval {

inline std::array<std::array<BitBoard, kSquareCount>, 2> passed_pawn_masks;

void InitMasks() {
  for (int square = 0; square < kSquareCount; square++) {
    const BitBoard white_forward_mask = ForwardFileMask(Color::kWhite, square);
    passed_pawn_masks[Color::kWhite][square] =
        white_forward_mask | Shift<Direction::kWest>(white_forward_mask) |
        Shift<Direction::kEast>(white_forward_mask);

    const BitBoard black_forward_mask = ForwardFileMask(Color::kBlack, square);
    passed_pawn_masks[Color::kBlack][square] =
        black_forward_mask | Shift<Direction::kWest>(black_forward_mask) |
        Shift<Direction::kEast>(black_forward_mask);
  }
}

int GetPhase(const BoardState &state) {
  int phase = 0;
  phase += kPhaseIncrements[PieceType::kKnight] * state.Knights().PopCount();
  phase += kPhaseIncrements[PieceType::kBishop] * state.Bishops().PopCount();
  phase += kPhaseIncrements[PieceType::kRook] * state.Rooks().PopCount();
  phase += kPhaseIncrements[PieceType::kQueen] * state.Queens().PopCount();
  return std::min(phase, kMaxPhase);
}

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

ScorePair EvaluateMaterial(const BoardState &state) {
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
  return score;
}

ScorePair EvaluatePieceSquares(const BoardState &state) {
  ScorePair score;
  const Color us = state.turn, them = FlipColor(us);

  BitBoard our_pieces = state.Occupied(us);
  BitBoard their_pieces = state.Occupied(them);

  while (our_pieces) {
    const auto square = our_pieces.PopLsb();
    const auto piece_type = state.GetPieceType(square);

    const auto rel_square = RelativeSquare(square, us);
    score += kPieceSquareTable[piece_type][rel_square];

    TRACE_INCREMENT(kPieceValues[piece_type], us);
    TRACE_INCREMENT(kPieceSquareTable[piece_type][rel_square], us);
  }

  while (their_pieces) {
    const auto square = their_pieces.PopLsb();
    const auto piece_type = state.GetPieceType(square);

    const auto rel_square = RelativeSquare(square, them);
    score -= kPieceSquareTable[piece_type][rel_square];

    TRACE_INCREMENT(kPieceValues[piece_type], them);
    TRACE_INCREMENT(kPieceSquareTable[piece_type][rel_square], them);
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
    TRACE_INCREMENT(kKnightMobility[moves.PopCount()], us);
  }

  BitBoard their_knights = state.Knights(them);
  while (their_knights) {
    const auto square = their_knights.PopLsb();
    const auto moves = move_gen::KnightMoves(square) & ~their_pieces;

    score -= kKnightMobility[moves.PopCount()];
    TRACE_INCREMENT(kKnightMobility[moves.PopCount()], them);
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
    TRACE_INCREMENT(kRookMobility[moves.PopCount()], us);
  }

  BitBoard their_rooks = state.Rooks(them);
  while (their_rooks) {
    const auto square = their_rooks.PopLsb();
    const auto moves = move_gen::RookMoves(square, occupied) & ~their_pieces;

    score -= kRookMobility[moves.PopCount()];
    TRACE_INCREMENT(kRookMobility[moves.PopCount()], them);
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
    TRACE_INCREMENT(kBishopMobility[moves.PopCount()], us);
  }

  BitBoard their_bishops = state.Bishops(them);
  while (their_bishops) {
    const auto square = their_bishops.PopLsb();
    const auto moves = move_gen::BishopMoves(square, occupied) & ~their_pieces;

    score -= kBishopMobility[moves.PopCount()];
    TRACE_INCREMENT(kBishopMobility[moves.PopCount()], them);
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
    TRACE_INCREMENT(kQueenMobility[moves.PopCount()], us);
  }

  BitBoard their_queens = state.Queens(them);
  while (their_queens) {
    const auto square = their_queens.PopLsb();
    const auto moves = move_gen::QueenMoves(square, occupied) & ~their_pieces;

    score -= kQueenMobility[moves.PopCount()];
    TRACE_INCREMENT(kQueenMobility[moves.PopCount()], them);
  }

  return score;
}

ScorePair EvaluatePawns(const BoardState &state) {
  ScorePair score;
  const Color us = state.turn, them = FlipColor(us);

  BitBoard our_pawns = state.Pawns(us);
  BitBoard their_pawns = state.Pawns(them);

  while (our_pawns) {
    const auto square = our_pawns.PopLsb();

    const BitBoard enemy_pawns_ahead =
        passed_pawn_masks[us][square] & their_pawns;
    if (enemy_pawns_ahead == 0) {
      score += kPassedPawn[RelativeRank(square, us)];
      TRACE_INCREMENT(kPassedPawn[RelativeRank(square, us)], us);
    }

    // We shift east to detect pawn phalanxes, since we don't want to check both
    // directions and duplicate the bonus from the other side
    if (Shift<Direction::kEast>(BitBoard::FromSquare(square)) & our_pawns) {
      score += kPawnPhalanxBonus[RelativeRank(square, us)];
      TRACE_INCREMENT(kPawnPhalanxBonus[RelativeRank(square, us)], us);
    }

    // Check if there exists another pawn on this file (the current pawn is
    // popped at this point)
    const int file = File(square);
    if (our_pawns & kFileMasks[file]) {
      score -= kDoubledPawnPenalty[file];
      TRACE_INCREMENT(kDoubledPawnPenalty[file], us);
    }
  }

  // Restore since we popped all the bits
  our_pawns = state.Pawns(us);

  while (their_pawns) {
    const auto square = their_pawns.PopLsb();

    const BitBoard enemy_pawns_ahead =
        passed_pawn_masks[them][square] & our_pawns;
    if (enemy_pawns_ahead == 0) {
      score -= kPassedPawn[RelativeRank(square, them)];
      TRACE_INCREMENT(kPassedPawn[RelativeRank(square, them)], them);
    }

    // We shift east to detect pawn phalanxes, since we don't want to check both
    // directions and duplicate the bonus from the other side
    if (Shift<Direction::kEast>(BitBoard::FromSquare(square)) & their_pawns) {
      score -= kPawnPhalanxBonus[RelativeRank(square, them)];
      TRACE_INCREMENT(kPawnPhalanxBonus[RelativeRank(square, them)], them);
    }

    // Check if there exists another pawn on this file (the current pawn is
    // popped at this point)
    const int file = File(square);
    if (their_pawns & kFileMasks[file]) {
      score += kDoubledPawnPenalty[file];
      TRACE_INCREMENT(kDoubledPawnPenalty[file], them);
    }
  }

  return score;
}

Score Evaluate(const BoardState &state) {
  const ScorePair score =
      EvaluateMaterial(state) + EvaluatePieceSquares(state) +
      EvaluatePawns(state) + EvaluateKnights(state) + EvaluateBishops(state) +
      EvaluateRooks(state) + EvaluateQueens(state) + kTempoBonus;
  TRACE_INCREMENT(kTempoBonus, state.turn);

  const int phase = std::min(GetPhase(state), kMaxPhase);
  const Score eval =
      (score.MiddleGame() * phase + score.EndGame() * (kMaxPhase - phase)) /
      kMaxPhase;

  TRACE_EVAL(eval);
  return eval;
}

}  // namespace eval