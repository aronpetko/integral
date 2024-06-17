#include "../../chess/move_gen.h"
#include "../../tuner/tuner.h"
#include "evaluation.h"

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
    files[square] = kFileMasks[File(square)];
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

  [[nodiscard]] int GetPieceMobilityCount(PieceType piece,
                            Square square,
                            BitBoard moves,
                            Color us) const;

  [[nodiscard]] Score InterpolateScore(ScorePair score_pair) const;

 private:
  const BoardState &state_;
  SideTable<BitBoard> king_zone_;
  SideTable<BitBoard> pawn_attacks_;
  SideTable<BitBoard> mobility_zone_;
  SideTable<BitBoard> pawn_storm_zone_;
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

  // King's + adjacent files forward from the king
  auto &white_pawn_storm_zone = pawn_storm_zone_[Color::kWhite];
  auto &black_pawn_storm_zone = pawn_storm_zone_[Color::kBlack];

  white_pawn_storm_zone =
      masks::forward_file_adjacent[Color::kWhite][white_king_square];
  black_pawn_storm_zone =
      masks::forward_file_adjacent[Color::kBlack][black_king_square];

  // Add in the squares next to the king
  white_pawn_storm_zone |= Shift<Direction::kSouth>(white_pawn_storm_zone);
  black_pawn_storm_zone |= Shift<Direction::kNorth>(black_pawn_storm_zone);
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

  const BitBoard our_pawns = state_.Pawns(us);
  const BitBoard their_pawns = state_.Pawns(FlipColor(us));

  // Pawn phalanxes
  const BitBoard connected_pawns =
      Shift<Direction::kEast>(our_pawns) & our_pawns;
  for (Square square : connected_pawns) {
    score += kPawnPhalanxBonus[RelativeRank<us>(square)];
    TRACE_INCREMENT(kPawnPhalanxBonus[RelativeRank<us>(square)], us);
  }

  for (Square square : our_pawns) {
    TRACE_INCREMENT(kPieceValues[PieceType::kPawn], us);
    TRACE_INCREMENT(
        kPieceSquareTable[PieceType::kPawn][RelativeSquare(square, us)], us);

    // Passed pawns
    const BitBoard their_pawns_ahead =
        masks::forward_file_adjacent[us][square] & their_pawns;
    if (!their_pawns_ahead) {
      score += kPassedPawnBonus[RelativeRank<us>(square)];
      TRACE_INCREMENT(kPassedPawnBonus[RelativeRank<us>(square)], us);
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
    const BitBoard adjacent_pawns = masks::adjacent_files[square] & our_pawns;
    if (!adjacent_pawns) {
      score += kIsolatedPawnPenalty[file];
      TRACE_INCREMENT(kIsolatedPawnPenalty[file], us);
    }
  }

  return score;
}

template <Color us>
ScorePair Evaluation::EvaluateKnights() {
  ScorePair score;

  const BitBoard our_knights = state_.Knights(us);

  for (Square square : our_knights) {
    TRACE_INCREMENT(kPieceValues[PieceType::kKnight], us);
    TRACE_INCREMENT(
        kPieceSquareTable[PieceType::kKnight][RelativeSquare(square, us)], us);

    const BitBoard moves = move_gen::KnightMoves(square);
    const int mobility_count =
        GetPieceMobilityCount(PieceType::kKnight, square, moves, us);

    score += kKnightMobility[mobility_count];
    TRACE_INCREMENT(kKnightMobility[mobility_count], us);
  }

  return score;
}

template <Color us>
ScorePair Evaluation::EvaluateBishops() {
  ScorePair score;

  const BitBoard our_bishops = state_.Bishops(us);
  const BitBoard occupied = state_.Occupied();

  if (our_bishops.MoreThanOne()) {
    score += kBishopPairBonus;
    TRACE_INCREMENT(kBishopPairBonus, us);
  }

  for (Square square : our_bishops) {
    TRACE_INCREMENT(kPieceValues[PieceType::kBishop], us);
    TRACE_INCREMENT(
        kPieceSquareTable[PieceType::kBishop][RelativeSquare(square, us)], us);

    const BitBoard moves = move_gen::BishopMoves(square, occupied);
    const int mobility_count =
        GetPieceMobilityCount(PieceType::kBishop, square, moves, us);

    score += kBishopMobility[mobility_count];
    TRACE_INCREMENT(kBishopMobility[mobility_count], us);
  }

  return score;
}

template <Color us>
ScorePair Evaluation::EvaluateRooks() {
  ScorePair score;

  const BitBoard our_rooks = state_.Rooks(us);
  const BitBoard our_pawns = state_.Pawns(us);
  const BitBoard their_pawns = state_.Pawns(FlipColor(us));
  const BitBoard occupied = state_.Occupied();

  for (Square square : our_rooks) {
    TRACE_INCREMENT(kPieceValues[PieceType::kRook], us);
    TRACE_INCREMENT(
        kPieceSquareTable[PieceType::kRook][RelativeSquare(square, us)], us);

    const BitBoard moves = move_gen::RookMoves(square, occupied);
    const int mobility_count =
        GetPieceMobilityCount(PieceType::kRook, square, moves, us);

    score += kRookMobility[mobility_count];
    TRACE_INCREMENT(kRookMobility[mobility_count], us);

    const int file = File(square);

    const BitBoard our_pawns_on_file = our_pawns & masks::files[square];
    if (!our_pawns_on_file) {
      const BitBoard their_pawns_on_file = their_pawns & masks::files[square];
      const bool semi_open_file = their_pawns_on_file != 0;

      score += kRookOnFileBonus[semi_open_file][file];
      TRACE_INCREMENT(kRookOnFileBonus[semi_open_file][file], us);
    }
  }

  return score;
}

template <Color us>
ScorePair Evaluation::EvaluateQueens() {
  ScorePair score;

  const BitBoard our_queens = state_.Queens(us);
  const BitBoard occupied = state_.Occupied();

  for (Square square : our_queens) {
    TRACE_INCREMENT(kPieceValues[PieceType::kQueen], us);
    TRACE_INCREMENT(
        kPieceSquareTable[PieceType::kQueen][RelativeSquare(square, us)], us);

    const BitBoard moves = move_gen::QueenMoves(square, occupied);
    const int mobility_count =
        GetPieceMobilityCount(PieceType::kQueen, square, moves, us);

    score += kQueenMobility[mobility_count];
    TRACE_INCREMENT(kQueenMobility[mobility_count], us);
  }

  return score;
}

template <Color us>
ScorePair Evaluation::EvaluateKing() {
  ScorePair score;

  const Square square = state_.King(us).GetLsb();
  TRACE_INCREMENT(
      kPieceSquareTable[PieceType::kKing][RelativeSquare(square, us)], us);

  const int king_rank = Rank(square);
  const int king_file = File(square);

  const BitBoard our_pawns_in_safety_zone = state_.Pawns(us) & king_zone_[us];
  for (Square pawn_square : our_pawns_in_safety_zone) {
    const int pawn_rank = Rank(pawn_square);
    const int pawn_file = File(pawn_square);

    constexpr int kKingIndexInZone = 7;
    constexpr int kZoneWidth = 3;

    const int rank_diff = (pawn_rank - king_rank);
    const int file_diff = (pawn_file - king_file);

    const int idx = kKingIndexInZone - (rank_diff * kZoneWidth + file_diff) *
                                           (us == Color::kBlack ? -1 : 1);

    score += kPawnShelterTable[idx];
    TRACE_INCREMENT(kPawnShelterTable[idx], us);
  }

  const Square their_king_square = state_.King(FlipColor(us)).GetLsb();
  const int their_king_rank = Rank(their_king_square);
  const int their_king_file = File(their_king_square);

  const BitBoard storming_pawns =
      state_.Pawns(us) & pawn_storm_zone_[FlipColor(us)];
  for (Square pawn_square : storming_pawns) {
    const int pawn_rank = Rank(pawn_square);
    const int pawn_file = File(pawn_square);

    constexpr int kKingIndexInZone = 19;
    constexpr int kZoneWidth = 3;

    const int rank_diff = (pawn_rank - their_king_rank);
    const int file_diff = (pawn_file - their_king_file);

    const int idx =
        kKingIndexInZone - (rank_diff * kZoneWidth + file_diff) *
                               (FlipColor(us) == Color::kBlack ? -1 : 1);

    score += kPawnStormTable[idx];
    TRACE_INCREMENT(kPawnStormTable[idx], us);
  }

  return score;
}

int Evaluation::GetPieceMobilityCount(PieceType piece,
                                      Square square,
                                      BitBoard moves,
                                      Color us) const {
  moves &= mobility_zone_[us];

  if (state_.pinned.IsSet(square)) {
    if (piece == PieceType::kKnight) {
      moves = 0;
    } else {
      moves &= move_gen::RayIntersecting(square, state_.King(us).GetLsb());
    }
  }

  return moves.PopCount();
}

Score Evaluation::InterpolateScore(ScorePair score_pair) const {
  const int phase = std::min(state_.phase, kMaxPhase);

  const Score mg_score = score_pair.MiddleGame();
  const Score eg_score = score_pair.EndGame();

  return (mg_score * phase + eg_score * (kMaxPhase - phase)) / kMaxPhase;
}

Score Evaluate(const BoardState &state) {
  return Evaluation(state).GetScore();
}

bool StaticExchange(Move move, int threshold, const BoardState &state) {
  const auto from = move.GetFrom();
  const auto to = move.GetTo();

  const PieceType &from_piece = state.GetPieceType(from);
  // Ignore en passant captures and castling
  if ((from_piece == PieceType::kPawn && to == state.en_passant) ||
      (from_piece == PieceType::kKing && std::abs(from - to) == 2)) {
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

}  // namespace eval