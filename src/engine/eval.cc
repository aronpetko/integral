#include "eval.h"

#include "../chess/move_gen.h"
#include "../tuner/tuner.h"

namespace eval {

namespace masks {

constexpr SideTable<SquareTable<BitBoard>> GenerateForwardFiles() {
  SideTable<SquareTable<BitBoard>> forward_file;
  for (Square square = 0; square < Squares::kSquareCount; square++) {
    forward_file[Color::kWhite][square] =
        ForwardFileMask(Color::kWhite, square);
    forward_file[Color::kBlack][square] =
        ForwardFileMask(Color::kBlack, square);
  }
  return forward_file;
}

constexpr SideTable<SquareTable<BitBoard>> forward_file =
    GenerateForwardFiles();

constexpr SideTable<SquareTable<BitBoard>> GenerateForwardFileAdjacent() {
  SideTable<SquareTable<BitBoard>> forward_file_adjacent;
  for (Square square = 0; square < Squares::kSquareCount; square++) {
    const BitBoard white_forward = forward_file[Color::kWhite][square];
    forward_file_adjacent[Color::kWhite][square] =
        Shift<Direction::kWest>(white_forward) | white_forward |
        Shift<Direction::kEast>(white_forward);

    const BitBoard black_forward = forward_file[Color::kBlack][square];
    forward_file_adjacent[Color::kBlack][square] =
        Shift<Direction::kWest>(black_forward) | black_forward |
        Shift<Direction::kEast>(black_forward);
  }
  return forward_file_adjacent;
}

constexpr SideTable<SquareTable<BitBoard>> forward_file_adjacent =
    GenerateForwardFileAdjacent();

}  // namespace masks

class Evaluation {
 public:
  explicit Evaluation(const BoardState &state) : state_(state) {
    Initialize();
  }

  Score GetScore();

 private:
  void Initialize();

  ScorePair EvaluatePawns(Color us);

  ScorePair EvaluateKnights(Color us);

  ScorePair EvaluateBishops(Color us);

  ScorePair EvaluateRooks(Color us);

  ScorePair EvaluateQueens(Color us);

  ScorePair EvaluateKing(Color us);

 private:
  const BoardState &state_;
  SideTable<BitBoard> king_zone_;
};

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

void Evaluation::Initialize() {}

Score Evaluation::GetScore() {
  const Color us = state_.turn;
  const Color them = FlipColor(us);

  ScorePair score;
  score += kTempoBonus;
  TRACE_INCREMENT(kTempoBonus, us);

  score += EvaluatePawns(us);
  score -= EvaluatePawns(them);

  score += EvaluateKnights(us);
  score -= EvaluateKnights(them);

  score += EvaluateBishops(us);
  score -= EvaluateBishops(them);

  score += EvaluateRooks(us);
  score -= EvaluateRooks(them);

  score += EvaluateQueens(us);
  score -= EvaluateQueens(them);

  score += EvaluateKing(us);
  score -= EvaluateKing(them);

  const int phase = std::min(GetPhase(state_), kMaxPhase);

  const Score mg_score = score.MiddleGame();
  const Score eg_score = score.EndGame();

  const Score tapered_score =
      (mg_score * phase + eg_score * (kMaxPhase - phase)) / kMaxPhase;

  TRACE_EVAL(tapered_score);
  return tapered_score;
}

ScorePair Evaluation::EvaluatePawns(Color us) {
  ScorePair score;

  const BitBoard our_pawns = state_.Pawns(us);
  const BitBoard their_pawns = state_.Pawns(FlipColor(us));

  // Pawn phalanxes
  const BitBoard connected_pawns =
      Shift<Direction::kEast>(our_pawns) & our_pawns;
  for (Square square : connected_pawns) {
    score += kPawnPhalanxBonus[RelativeRank(square, us)];
    TRACE_INCREMENT(kPawnPhalanxBonus[RelativeRank(square, us)], us);
  }

  for (Square square : our_pawns) {
    score += kPieceValues[PieceType::kPawn];
    TRACE_INCREMENT(kPieceValues[PieceType::kPawn], us);

    const Square relative_square = RelativeSquare(square, us);
    score += kPieceSquareTable[PieceType::kPawn][relative_square];
    TRACE_INCREMENT(kPieceSquareTable[PieceType::kPawn][relative_square], us);

    // Passed pawns
    const BitBoard their_pawns_ahead =
        masks::forward_file_adjacent[us][square] & their_pawns;
    if (!their_pawns_ahead) {
      score += kPassedPawnBonus[RelativeRank(square, us)];
      TRACE_INCREMENT(kPassedPawnBonus[RelativeRank(square, us)], us);
    }

    const int file = File(square);

    // Doubled pawns
    const BitBoard pawns_ahead_on_file =
        our_pawns & masks::forward_file[us][square];
    if (pawns_ahead_on_file) {
      score += kDoubledPawnPenalty[file];
      TRACE_INCREMENT(kDoubledPawnPenalty[file], us);
    }

    // Isolated pawns
    const BitBoard adjacent_pawns =
        (Shift<Direction::kWest>(kFileMasks[file]) |
         Shift<Direction::kEast>(kFileMasks[file])) &
        our_pawns;
    if (!adjacent_pawns) {
      score += kIsolatedPawnPenalty[file];
      TRACE_INCREMENT(kIsolatedPawnPenalty[file], us);
    }
  }

  return score;
}

ScorePair Evaluation::EvaluateKnights(Color us) {
  ScorePair score;

  const BitBoard our_knights = state_.Knights(us);
  const BitBoard not_our_pieces = ~state_.Occupied(us);

  for (Square square : our_knights) {
    score += kPieceValues[PieceType::kKnight];
    TRACE_INCREMENT(kPieceValues[PieceType::kKnight], us);

    const Square relative_square = RelativeSquare(square, us);
    score += kPieceSquareTable[PieceType::kKnight][relative_square];
    TRACE_INCREMENT(kPieceSquareTable[PieceType::kKnight][relative_square], us);

    const BitBoard moves = move_gen::KnightMoves(square) & not_our_pieces;

    score += kKnightMobility[moves.PopCount()];
    TRACE_INCREMENT(kKnightMobility[moves.PopCount()], us);
  }

  return score;
}

ScorePair Evaluation::EvaluateBishops(Color us) {
  ScorePair score;

  const BitBoard our_bishops = state_.Bishops(us);
  const BitBoard not_our_pieces = ~state_.Occupied(us);
  const BitBoard occupied = state_.Occupied();

  for (Square square : our_bishops) {
    score += kPieceValues[PieceType::kBishop];
    TRACE_INCREMENT(kPieceValues[PieceType::kBishop], us);

    const Square relative_square = RelativeSquare(square, us);
    score += kPieceSquareTable[PieceType::kBishop][relative_square];
    TRACE_INCREMENT(kPieceSquareTable[PieceType::kBishop][relative_square], us);

    const BitBoard moves =
        move_gen::BishopMoves(square, occupied) & not_our_pieces;

    score += kBishopMobility[moves.PopCount()];
    TRACE_INCREMENT(kBishopMobility[moves.PopCount()], us);
  }

  return score;
}

ScorePair Evaluation::EvaluateRooks(Color us) {
  ScorePair score;

  const BitBoard our_rooks = state_.Rooks(us);
  const BitBoard our_pawns = state_.Pawns(us);
  const BitBoard their_pawns = state_.Pawns(FlipColor(us));
  const BitBoard not_our_pieces = ~state_.Occupied(us);
  const BitBoard occupied = state_.Occupied();

  for (Square square : our_rooks) {
    score += kPieceValues[PieceType::kRook];
    TRACE_INCREMENT(kPieceValues[PieceType::kRook], us);

    const Square relative_square = RelativeSquare(square, us);
    score += kPieceSquareTable[PieceType::kRook][relative_square];
    TRACE_INCREMENT(kPieceSquareTable[PieceType::kRook][relative_square], us);

    const BitBoard moves =
        move_gen::RookMoves(square, occupied) & not_our_pieces;

    score += kRookMobility[moves.PopCount()];
    TRACE_INCREMENT(kRookMobility[moves.PopCount()], us);

    const int file = File(square);

    const BitBoard our_pawns_on_file = our_pawns & kFileMasks[file];
    if (!our_pawns_on_file) {
      const BitBoard their_pawns_on_file = their_pawns & kFileMasks[file];
      const bool semi_open_file = their_pawns_on_file != 0;

      score += kRookOnFileBonus[semi_open_file][file];
      TRACE_INCREMENT(kRookOnFileBonus[semi_open_file][file], us);
    }
  }

  return score;
}

ScorePair Evaluation::EvaluateQueens(Color us) {
  ScorePair score;

  const BitBoard our_queens = state_.Queens(us);
  const BitBoard not_our_pieces = ~state_.Occupied(us);
  const BitBoard occupied = state_.Occupied();

  for (Square square : our_queens) {
    score += kPieceValues[PieceType::kQueen];
    TRACE_INCREMENT(kPieceValues[PieceType::kQueen], us);

    const Square relative_square = RelativeSquare(square, us);
    score += kPieceSquareTable[PieceType::kQueen][relative_square];
    TRACE_INCREMENT(kPieceSquareTable[PieceType::kQueen][relative_square], us);

    const BitBoard moves =
        move_gen::QueenMoves(square, occupied) & not_our_pieces;

    score += kQueenMobility[moves.PopCount()];
    TRACE_INCREMENT(kQueenMobility[moves.PopCount()], us);
  }

  return score;
}

ScorePair Evaluation::EvaluateKing(Color us) {
  ScorePair score;

  const Square square = RelativeSquare(state_.King(us).GetLsb(), us);

  score += kPieceSquareTable[PieceType::kKing][square];
  TRACE_INCREMENT(kPieceSquareTable[PieceType::kKing][square], us);

  return score;
}

Score Evaluate(const BoardState &state) {
  return Evaluation(state).GetScore();
}

}  // namespace eval