#include "evaluation.h"

#include "../../tuner/tuner.h"

namespace eval {

namespace masks {

constexpr SideTable<SquareTable<BitBoard>> GenerateForwardFiles() {
  SideTable<SquareTable<BitBoard>> forward_file;
  for (Square square = 0; square < kSquareCount; square++) {
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
  for (Square square = 0; square < kSquareCount; square++) {
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

constexpr SquareTable<BitBoard> GenerateFiles() {
  SquareTable<BitBoard> files;
  for (Square square = 0; square < kSquareCount; square++) {
    files[square] = kFileMasks[square.File()];
  }
  return files;
}

constexpr SquareTable<BitBoard> files = GenerateFiles();

constexpr SquareTable<BitBoard> GenerateAdjacentFiles() {
  SquareTable<BitBoard> adjacent_files;
  for (Square square = 0; square < kSquareCount; square++) {
    adjacent_files[square] = Shift<Direction::kWest>(files[square]) |
                             Shift<Direction::kEast>(files[square]);
  }
  return adjacent_files;
}

constexpr SquareTable<BitBoard> adjacent_files = GenerateAdjacentFiles();

constexpr SideTable<BitBoard> GenerateOutposts() {
  SideTable<BitBoard> outposts;

  outposts.fill(kRankMasks[kRank4] | kRankMasks[kRank5]);
  outposts[Color::kWhite] |= kRankMasks[kRank6];
  outposts[Color::kBlack] |= kRankMasks[kRank3];

  return outposts;
}

constexpr SideTable<BitBoard> outposts = GenerateOutposts();

}  // namespace masks

class Evaluation {
 public:
  explicit Evaluation(const BoardState &state) : state_(state) {
    Initialize();
  }

  Score GetScore();

 private:
  void Initialize();

  template <Color us>
  ScorePair EvaluatePawns();

  template <Color us>
  ScorePair EvaluateKnights();

  template <Color us>
  ScorePair EvaluateBishops();

  template <Color us>
  ScorePair EvaluateRooks();

  template <Color us>
  ScorePair EvaluateQueens();

  template <Color us>
  ScorePair EvaluateKing();

  template <Color us>
  ScorePair EvaluateThreats();

  [[nodiscard]] BitBoard LegalizeMoves(PieceType piece,
                                       Square square,
                                       BitBoard moves,
                                       Color us) const;

  [[nodiscard]] Score InterpolateScore(ScorePair score_pair) const;

  template <Color us>
  [[nodiscard]] bool IsDefendedByPawn(Square square) const;

  template <Color us>
  [[nodiscard]] bool IsOutpostSquare(Square square) const;

 private:
  const BoardState &state_;
  SideTable<BitBoard> king_zone_;
  SideTable<BitBoard> pawn_attacks_;
  SideTable<BitBoard> knight_attacks_;
  SideTable<BitBoard> bishop_attacks_;
  SideTable<BitBoard> rook_attacks_;
  SideTable<BitBoard> queen_attacks_;
  SideTable<BitBoard> mobility_zone_;
  SideTable<BitBoard> pawn_storm_zone_;
  SideTable<ScorePair> attack_power_;
  PawnStructureEntry *cached_pawn_structure_;
  bool has_pawn_structure_cache_;
};

void Evaluation::Initialize() {
  const Square white_king_square = state_.King(Color::kWhite).GetLsb();
  const Square black_king_square = state_.King(Color::kBlack).GetLsb();

  auto &white_king_zone = king_zone_[Color::kWhite];
  auto &black_king_zone = king_zone_[Color::kBlack];

  // Create the 3x3 zone around the king
  white_king_zone = move_gen::KingAttacks(white_king_square);
  black_king_zone = move_gen::KingAttacks(black_king_square);

  // Add the extra rank in front of the king
  white_king_zone |= Shift<Direction::kNorth>(white_king_zone);
  black_king_zone |= Shift<Direction::kSouth>(black_king_zone);

  pawn_attacks_[Color::kWhite] =
      move_gen::PawnAttacks(state_.Pawns(Color::kWhite), Color::kWhite);
  pawn_attacks_[Color::kBlack] =
      move_gen::PawnAttacks(state_.Pawns(Color::kBlack), Color::kBlack);

  // Remove enemy pawn attacks from the mobility zone
  mobility_zone_[Color::kWhite] =
      ~(state_.Occupied(Color::kWhite) | pawn_attacks_[Color::kBlack]);
  mobility_zone_[Color::kBlack] =
      ~(state_.Occupied(Color::kBlack) | pawn_attacks_[Color::kWhite]);
}

Score Evaluation::GetScore() {
  const Color us = state_.turn;

  ScorePair score =
      state_.piece_scores[Color::kWhite] - state_.piece_scores[Color::kBlack];

  score += EvaluatePawns<Color::kWhite>() - EvaluatePawns<Color::kBlack>();
  score += EvaluateKnights<Color::kWhite>() - EvaluateKnights<Color::kBlack>();
  score += EvaluateBishops<Color::kWhite>() - EvaluateBishops<Color::kBlack>();
  score += EvaluateRooks<Color::kWhite>() - EvaluateRooks<Color::kBlack>();
  score += EvaluateQueens<Color::kWhite>() - EvaluateQueens<Color::kBlack>();
  score += EvaluateKing<Color::kWhite>() - EvaluateKing<Color::kBlack>();
  score += EvaluateThreats<Color::kWhite>() - EvaluateThreats<Color::kBlack>();

  // Flip the score if we are black, since the score is from white's perspective
  if (us == Color::kBlack) {
    score *= -1;
  }

  // A constant bonus given to the side to move
  score += kTempoBonus;
  TRACE_INCREMENT(kTempoBonus, us);

  const Score final_score = InterpolateScore(score);

  TRACE_EVAL(final_score);
  return final_score;
}

template <Color us>
ScorePair Evaluation::EvaluatePawns() {
  ScorePair score;

  const Color them = FlipColor(us);

  const BitBoard our_pawns = state_.Pawns(us);
  const BitBoard their_pawns = state_.Pawns(them);

  for (Square square : our_pawns) {
    TRACE_INCREMENT(kPieceValues[kPawn], us);

    for (Square pawn_square : state_.Pawns()) {
      const Color pawn_color = state_.GetPieceColor(pawn_square);
      score += kPawnPieceSquareTable[pawn_color == us][pawn_square.RelativeTo(
          pawn_color)][kPawn][square.RelativeTo<us>()];
      TRACE_INCREMENT(
          kPawnPieceSquareTable[pawn_color == us][pawn_square.RelativeTo(
              pawn_color)][kPawn][square.RelativeTo<us>()],
          us);
    }
  }

  const auto AddPawnPSQT = [&](Square pawn_square, bool ours, PieceType piece) {
    for (Square square : state_.piece_bbs[piece] & state_.side_bbs[us]) {
      score += kPawnPieceSquareTable[ours][pawn_square][piece]
                                    [square.RelativeTo<us>()];
      TRACE_INCREMENT(kPawnPieceSquareTable[ours][pawn_square][piece]
                                           [square.RelativeTo<us>()],
                      us);
    }
  };

  for (Square pawn_square : our_pawns) {
    AddPawnPSQT(pawn_square.RelativeTo<us>(), true, kKnight);
    AddPawnPSQT(pawn_square.RelativeTo<us>(), true, kBishop);
    AddPawnPSQT(pawn_square.RelativeTo<us>(), true, kRook);
    AddPawnPSQT(pawn_square.RelativeTo<us>(), true, kQueen);
    AddPawnPSQT(pawn_square.RelativeTo<us>(), true, kKing);
  }

  for (Square pawn_square : their_pawns) {
    AddPawnPSQT(pawn_square.RelativeTo<them>(), false, kKnight);
    AddPawnPSQT(pawn_square.RelativeTo<them>(), false, kBishop);
    AddPawnPSQT(pawn_square.RelativeTo<them>(), false, kRook);
    AddPawnPSQT(pawn_square.RelativeTo<them>(), false, kQueen);
    AddPawnPSQT(pawn_square.RelativeTo<them>(), false, kKing);
  }

  return score;
}  // namespace eval

template <Color us>
ScorePair Evaluation::EvaluateKnights() {
  ScorePair score;

  const BitBoard our_knights = state_.Knights(us);
  const int kb = state_.king_bucket[us],
            their_kb = state_.king_bucket[FlipColor(us)];

  for (Square square : our_knights) {
    TRACE_INCREMENT(kPieceValues[kKnight], us);

    const BitBoard legal_moves =
        LegalizeMoves(kKnight, square, move_gen::KnightMoves(square), us);
    const BitBoard mobility = legal_moves & mobility_zone_[us];

    score += kKnightMobility[mobility.PopCount()];
    TRACE_INCREMENT(kKnightMobility[mobility.PopCount()], us);
  }

  return score;
}

template <Color us>
ScorePair Evaluation::EvaluateBishops() {
  ScorePair score;

  const BitBoard our_bishops = state_.Bishops(us);
  const BitBoard occupied =
      state_.Occupied() ^ state_.Queens(us) ^ state_.Bishops(us);

  for (Square square : our_bishops) {
    TRACE_INCREMENT(kPieceValues[kBishop], us);

    const BitBoard legal_moves = LegalizeMoves(
        kBishop, square, move_gen::BishopMoves(square, occupied), us);
    const BitBoard mobility = legal_moves & mobility_zone_[us];

    score += kBishopMobility[mobility.PopCount()];
    TRACE_INCREMENT(kBishopMobility[mobility.PopCount()], us);
  }

  return score;
}

template <Color us>
ScorePair Evaluation::EvaluateRooks() {
  ScorePair score;

  const BitBoard our_rooks = state_.Rooks(us);
  const BitBoard our_pawns = state_.Pawns(us);
  const BitBoard their_pawns = state_.Pawns(FlipColor(us));
  const BitBoard occupied =
      state_.Occupied() ^ state_.Queens(us) ^ state_.Rooks(us);

  for (Square square : our_rooks) {
    TRACE_INCREMENT(kPieceValues[kRook], us);

    const BitBoard legal_moves =
        LegalizeMoves(kRook, square, move_gen::RookMoves(square, occupied), us);
    const BitBoard mobility = legal_moves & mobility_zone_[us];

    score += kRookMobility[mobility.PopCount()];
    TRACE_INCREMENT(kRookMobility[mobility.PopCount()], us);
  }

  return score;
}

template <Color us>
ScorePair Evaluation::EvaluateQueens() {
  ScorePair score;

  const BitBoard our_queens = state_.Queens(us);
  const BitBoard occupied =
      state_.Occupied() ^ state_.Bishops(us) ^ state_.Rooks(us);

  for (Square square : our_queens) {
    TRACE_INCREMENT(kPieceValues[kQueen], us);

    const BitBoard legal_moves = LegalizeMoves(
        kQueen, square, move_gen::QueenMoves(square, occupied), us);
    const BitBoard mobility = legal_moves & mobility_zone_[us];

    score += kQueenMobility[mobility.PopCount()];
    TRACE_INCREMENT(kQueenMobility[mobility.PopCount()], us);
  }

  return score;
}

template <Color us>
ScorePair Evaluation::EvaluateKing() {
  ScorePair score;

  const Color them = FlipColor(us);

  const auto AddKingPSQT = [&](Square king_square, bool ours, PieceType piece) {
    for (Square square : state_.piece_bbs[piece] & state_.side_bbs[us]) {
      score += kKingPieceSquareTable[ours][king_square][piece]
                                    [square.RelativeTo<us>()];
      TRACE_INCREMENT(kKingPieceSquareTable[ours][king_square][piece]
                                           [square.RelativeTo<us>()],
                      us);
    }
  };

  const Square our_king_square = state_.King(us).GetLsb();
  const Square their_king_square = state_.King(them).GetLsb();

  for (Square king_square : state_.King(us)) {
    AddKingPSQT(king_square.RelativeTo<us>(), true, kKnight);
    AddKingPSQT(king_square.RelativeTo<us>(), true, kBishop);
    AddKingPSQT(king_square.RelativeTo<us>(), true, kRook);
    AddKingPSQT(king_square.RelativeTo<us>(), true, kQueen);
    AddKingPSQT(king_square.RelativeTo<us>(), true, kKing);
  }

  for (Square king_square : state_.King(FlipColor(them))) {
    AddKingPSQT(king_square.RelativeTo<them>(), false, kKnight);
    AddKingPSQT(king_square.RelativeTo<them>(), false, kBishop);
    AddKingPSQT(king_square.RelativeTo<them>(), false, kRook);
    AddKingPSQT(king_square.RelativeTo<them>(), false, kQueen);
    AddKingPSQT(king_square.RelativeTo<them>(), false, kKing);
  }

  return score;
}

template <Color us>
ScorePair Evaluation::EvaluateThreats() {
  ScorePair score;
  return score;
}

BitBoard Evaluation::LegalizeMoves(PieceType piece,
                                   Square square,
                                   BitBoard moves,
                                   Color us) const {
  if (state_.pinned.IsSet(square)) {
    if (piece == kKnight) {
      moves = 0;
    } else {
      moves &= move_gen::RayIntersecting(square, state_.King(us).GetLsb());
    }
  }

  return moves;
}

Score Evaluation::InterpolateScore(ScorePair score_pair) const {
  const int phase = std::min(state_.phase, kMaxPhase);

  const Score mg_score = score_pair.MiddleGame();
  const Score eg_score = score_pair.EndGame();

  return (mg_score * phase + eg_score * (kMaxPhase - phase)) / kMaxPhase;
}

template <Color us>
[[nodiscard]] bool Evaluation::IsDefendedByPawn(Square square) const {
  return pawn_attacks_[us].IsSet(square);
}

template <Color us>
[[nodiscard]] bool Evaluation::IsOutpostSquare(Square square) const {
  const bool safe_from_pawns =
      IsDefendedByPawn<us>(square) && !IsDefendedByPawn<FlipColor(us)>(square);
  return masks::outposts[us].IsSet(square) && safe_from_pawns;
}

Score Evaluate(const BoardState &state) {
  return Evaluation(state).GetScore();
}

bool StaticExchange(Move move, int threshold, const BoardState &state) {
  const auto from = move.GetFrom();
  const auto to = move.GetTo();

  const PieceType &from_piece = state.GetPieceType(from);
  // Ignore en passant captures and castling
  if (move.IsEnPassant(state) ||
      (from_piece == kKing && std::abs(static_cast<int>(from) - to) == 2)) {
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
  auto pawn_attackers =
      (move_gen::PawnAttacks(to, Color::kWhite) & state.Pawns(Color::kBlack)) |
      (move_gen::PawnAttacks(to, Color::kBlack) & state.Pawns(Color::kWhite));
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
      attacker_value = kSEEPieceScores[kPawn];
      occupied.ClearBit(next_attacker.GetLsb());

      // Add pieces that were diagonal xray attacking the captured piece
      bishop_attacks = move_gen::BishopMoves(to, occupied);
      all_attackers |= bishop_attacks & (bishops | queens);
    } else if ((next_attacker = our_attackers & knights)) {
      attacker_value = kSEEPieceScores[kKnight];
      occupied.ClearBit(next_attacker.GetLsb());
    } else if ((next_attacker = our_attackers & bishops)) {
      attacker_value = kSEEPieceScores[kBishop];
      occupied.ClearBit(next_attacker.GetLsb());

      // Add pieces that were xray attacking the captured piece
      bishop_attacks = move_gen::BishopMoves(to, occupied);
      all_attackers |= bishop_attacks & (bishops | queens);
    } else if ((next_attacker = our_attackers & rooks)) {
      attacker_value = kSEEPieceScores[kRook];
      occupied.ClearBit(next_attacker.GetLsb());

      // Add pieces that were xray attacking the captured piece
      rook_attacks = move_gen::RookMoves(to, occupied);
      all_attackers |= rook_attacks & (rooks | queens);
    } else if ((next_attacker = our_attackers & queens)) {
      attacker_value = kSEEPieceScores[kQueen];
      occupied.ClearBit(next_attacker.GetLsb());

      // Add pieces that were xray attacking the captured piece
      rook_attacks = move_gen::RookMoves(to, occupied);
      bishop_attacks = move_gen::BishopMoves(to, occupied);
      all_attackers |= (rook_attacks & (queens | rooks)) |
                       (bishop_attacks & (queens | bishops));
    } else {
      // King: check if we capture a piece that our opponent is still
      // attacking
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

}  // namespace eval