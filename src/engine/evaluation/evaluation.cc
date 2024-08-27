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

// clang-format off
constexpr std::array<std::array<int, 64>, kNumPieceTypes> kMiddleGameTables = {{
    // Pawns
    {
        0,   0,   0,   0,   0,   0,  0,   0,
        98, 134,  61,  95,  68, 126, 34, -11,
        -6,   7,  26,  31,  65,  56, 25, -20,
        -14,  13,   6,  21,  23,  12, 17, -23,
        -27,  -2,  -5,  12,  17,   6, 10, -25,
        -26,  -4,  -4, -10,   3,   3, 33, -12,
        -35,  -1, -20, -23, -15,  24, 38, -22,
        0,   0,   0,   0,   0,   0,  0,   0,
    },
    // Knights
    {
        -167, -89, -34, -49,  61, -97, -15, -107,
        -73, -41,  72,  36,  23,  62,   7,  -17,
        -47,  60,  37,  65,  84, 129,  73,   44,
        -9,  17,  19,  53,  37,  69,  18,   22,
        -13,   4,  16,  13,  28,  19,  21,   -8,
        -23,  -9,  12,  10,  19,  17,  25,  -16,
        -29, -53, -12,  -3,  -1,  18, -14,  -19,
        -105, -21, -58, -33, -17, -28, -19,  -23,
    },
    // Bishops
    {
        -29,   4, -82, -37, -25, -42,   7,  -8,
        -26,  16, -18, -13,  30,  59,  18, -47,
        -16,  37,  43,  40,  35,  50,  37,  -2,
        -4,   5,  19,  50,  37,  37,   7,  -2,
        -6,  13,  13,  26,  34,  12,  10,   4,
        0,  15,  15,  15,  14,  27,  18,  10,
        4,  15,  16,   0,   7,  21,  33,   1,
        -33,  -3, -14, -21, -13, -12, -39, -21,
    },
    // Rooks
    {
        32,  42,  32,  51, 63,  9,  31,  43,
        27,  32,  58,  62, 80, 67,  26,  44,
        -5,  19,  26,  36, 17, 45,  61,  16,
        -24, -11,   7,  26, 24, 35,  -8, -20,
        -36, -26, -12,  -1,  9, -7,   6, -23,
        -45, -25, -16, -17,  3,  0,  -5, -33,
        -44, -16, -20,  -9, -1, 11,  -6, -71,
        -19, -13,   1,  17, 16,  7, -37, -26,
    },
    // Queens
    {
        -28,   0,  29,  12,  59,  44,  43,  45,
        -24, -39,  -5,   1, -16,  57,  28,  54,
        -13, -17,   7,   8,  29,  56,  47,  57,
        -27, -27, -16, -16,  -1,  17,  -2,   1,
        -9, -26,  -9, -10,  -2,  -4,   3,  -3,
        -14,   2, -11,  -2,  -5,   2,  14,   5,
        -35,  -8,  11,   2,   8,  15,  -3,   1,
        -1, -18,  -9,  10, -15, -25, -31, -50,
    },
    // King
    {
        -65,  23,  16, -15, -56, -34,   2,  13,
        29,  -1, -20,  -7,  -8,  -4, -38, -29,
        -9,  24,   2, -16, -20,   6,  22, -22,
        -17, -20, -12, -27, -30, -25, -14, -36,
        -49,  -1, -27, -39, -46, -44, -33, -51,
        -14, -14, -22, -46, -44, -30, -15, -27,
        1,   7,  -8, -64, -43, -16,   9,   8,
        -15,  36,  12, -54,   8, -28,  24,  14,
    }
}};

constexpr std::array<std::array<int, 64>, kNumPieceTypes> kEndGameTables = {{
    // Pawns
    {
        0,   0,   0,   0,   0,   0,   0,   0,
        178, 173, 158, 134, 147, 132, 165, 187,
        94, 100,  85,  67,  56,  53,  82,  84,
        32,  24,  13,   5,  -2,   4,  17,  17,
        13,   9,  -3,  -7,  -7,  -8,   3,  -1,
        4,   7,  -6,   1,   0,  -5,  -1,  -8,
        13,   8,   8,  10,  13,   0,   2,  -7,
        0,   0,   0,   0,   0,   0,   0,   0,
    },
    // Knights
    {
        -58, -38, -13, -28, -31, -27, -63, -99,
        -25,  -8, -25,  -2,  -9, -25, -24, -52,
        -24, -20,  10,   9,  -1,  -9, -19, -41,
        -17,   3,  22,  22,  22,  11,   8, -18,
        -18,  -6,  16,  25,  16,  17,   4, -18,
        -23,  -3,  -1,  15,  10,  -3, -20, -22,
        -42, -20, -10,  -5,  -2, -20, -23, -44,
        -29, -51, -23, -15, -22, -18, -50, -64,
    },
    // Bishops
    {
        -14, -21, -11,  -8, -7,  -9, -17, -24,
        -8,  -4,   7, -12, -3, -13,  -4, -14,
        2,  -8,   0,  -1, -2,   6,   0,   4,
        -3,   9,  12,   9, 14,  10,   3,   2,
        -6,   3,  13,  19,  7,  10,  -3,  -9,
        -12,  -3,   8,  10, 13,   3,  -7, -15,
        -14, -18,  -7,  -1,  4,  -9, -15, -27,
        -23,  -9, -23,  -5, -9, -16,  -5, -17,
    },
    // Rooks
    {
        13, 10, 18, 15, 12,  12,   8,   5,
        11, 13, 13, 11, -3,   3,   8,   3,
        7,  7,  7,  5,  4,  -3,  -5,  -3,
        4,  3, 13,  1,  2,   1,  -1,   2,
        3,  5,  8,  4, -5,  -6,  -8, -11,
        -4,  0, -5, -1, -7, -12,  -8, -16,
        -6, -6,  0,  2, -9,  -9, -11,  -3,
        -9,  2,  3, -1, -5, -13,   4, -20,
    },
    // Queens
    {
        -9,  22,  22,  27,  27,  19,  10,  20,
        -17,  20,  32,  41,  58,  25,  30,   0,
        -20,   6,   9,  49,  47,  35,  19,   9,
        3,  22,  24,  45,  57,  40,  57,  36,
        -18,  28,  19,  47,  31,  34,  39,  23,
        -16, -27,  15,   6,   9,  17,  10,   5,
        -22, -23, -30, -16, -16, -23, -36, -32,
        -33, -28, -22, -43,  -5, -32, -20, -41,
    },
    // King
    {
        -74, -35, -18, -18, -11,  15,   4, -17,
        -12,  17,  14,  17,  17,  38,  23,  11,
        10,  17,  23,  15,  20,  45,  44,  13,
        -8,  22,  24,  27,  26,  33,  26,   3,
        -18,  -4,  21,  24,  27,  23,   9, -11,
        -19,  -3,  11,  21,  23,  16,   7,  -9,
        -27, -11,   4,  13,  14,   4,  -5, -17,
        -53, -34, -21, -11, -28, -14, -24, -43
    }
}};

constexpr std::array<int, kNumPieceTypes> kGamePhaseIncrements = {0, 1, 1, 2, 4, 0};
constexpr std::array<int, kNumPieceTypes> kMiddleGamePieceValues = {82, 337, 365, 477, 1025, 0};
constexpr std::array<int, kNumPieceTypes> kEndGamePieceValues = {94, 281, 297, 512, 936, 0};

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

std::pair<int, int> EvaluateMaterial(const BoardState &state) {
  int mg_material = 0;
  int eg_material = 0;

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

  mg_material += kMiddleGamePieceValues[PieceType::kPawn] * pawn_count;
  mg_material += kMiddleGamePieceValues[PieceType::kKnight] * knight_count;
  mg_material += kMiddleGamePieceValues[PieceType::kBishop] * bishop_count;
  mg_material += kMiddleGamePieceValues[PieceType::kRook] * rook_count;
  mg_material += kMiddleGamePieceValues[PieceType::kQueen] * queen_count;

  eg_material += kEndGamePieceValues[PieceType::kPawn] * pawn_count;
  eg_material += kEndGamePieceValues[PieceType::kKnight] * knight_count;
  eg_material += kEndGamePieceValues[PieceType::kBishop] * bishop_count;
  eg_material += kEndGamePieceValues[PieceType::kRook] * rook_count;
  eg_material += kEndGamePieceValues[PieceType::kQueen] * queen_count;

  return {mg_material, eg_material};
}

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

  // Probe the pawn structure cache
  cached_pawn_structure_ = &pawn_cache[state_.pawn_key];
  has_pawn_structure_cache_ = cached_pawn_structure_->key == state_.pawn_key;
}

// clang-format on
Score Evaluation::GetScore() {
  auto [middle_game_score, end_game_score] = EvaluateMaterial(state_);

  int middle_game_phase = state_.phase;

  const Color us = state_.turn, them = FlipColor(us);

  BitBoard our_pieces = state_.Occupied(us);
  while (our_pieces) {
    const auto square = Square(our_pieces.PopLsb());
    const auto piece = state_.GetPieceType(square);

    middle_game_score += kMiddleGameTables[piece][square.RelativeTo(us)];
    end_game_score += kEndGameTables[piece][square.RelativeTo(us)];
  }

  BitBoard their_pieces = state_.Occupied(them);
  while (their_pieces) {
    const auto square = Square(their_pieces.PopLsb());
    const auto piece = state_.GetPieceType(square);

    middle_game_score -= kMiddleGameTables[piece][square.RelativeTo(them)];
    end_game_score -= kEndGameTables[piece][square.RelativeTo(them)];
  }

  // Tapered evaluation
  constexpr int kMaxMiddleGamePhase = 24;

  middle_game_phase = std::min(middle_game_phase, kMaxMiddleGamePhase);
  const int end_game_phase = kMaxMiddleGamePhase - middle_game_phase;

  Score score = (middle_game_score * middle_game_phase +
                 end_game_score * end_game_phase) /
                kMaxMiddleGamePhase;

  constexpr int kTempoBonus = 10;
  score += kTempoBonus;

  return score;
}

template <Color us>
ScorePair Evaluation::EvaluatePawns() {
  ScorePair score;

  const Color them = FlipColor(us);

  const BitBoard our_pawns = state_.Pawns(us);
  const BitBoard their_pawns = state_.Pawns(them);

  BitBoard passed_pawns;

  if (!has_pawn_structure_cache_) {
    // Pawn phalanxes
    const BitBoard connected_pawns =
        Shift<Direction::kEast>(our_pawns) & our_pawns;
    for (Square square : connected_pawns) {
      score += kPawnPhalanxBonus[square.RelativeRank<us>()];
      TRACE_INCREMENT(kPawnPhalanxBonus[square.RelativeRank<us>()], us);
    }

    const int kb = state_.king_bucket[us], their_kb = state_.king_bucket[them];
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

      const int file = square.File();
      const int rank = square.RelativeRank<us>();

      // Passed pawns
      const BitBoard their_pawns_ahead =
          masks::forward_file_adjacent[us][square] & their_pawns;
      if (!their_pawns_ahead) {
        passed_pawns.SetBit(square);

        score += kPassedPawnBonus[rank];
        TRACE_INCREMENT(kPassedPawnBonus[rank], us);
      }

      if (IsDefendedByPawn<us>(square)) {
        score += kDefendedPawnBonus[rank];
        TRACE_INCREMENT(kDefendedPawnBonus[rank], us);
      }

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

#ifndef TUNE
    cached_pawn_structure_->key = state_.pawn_key;
    cached_pawn_structure_->score[us] = score;
    cached_pawn_structure_->passed_pawns[us] = passed_pawns;
#endif
  } else {
    score = cached_pawn_structure_->score[us];
    passed_pawns = cached_pawn_structure_->passed_pawns[us];
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

  // Don't cache the king/passed pawn proximity scores as it involves knowing
  // the position of the king, which the pawn cache doesn't store
  const Square king_square = state_.King(us).GetLsb();
  const Square enemy_king_square = state_.King(them).GetLsb();
  for (Square square : passed_pawns) {
    score += kKingPPDistanceTable[square.DistanceTo(king_square)];
    TRACE_INCREMENT(kKingPPDistanceTable[square.DistanceTo(king_square)], us);

    const int dist_to_enemy_king = square.DistanceTo(enemy_king_square);

    score += kEnemyKingPPDistanceTable[dist_to_enemy_king];
    TRACE_INCREMENT(kEnemyKingPPDistanceTable[dist_to_enemy_king], us);

    // Square rule for passed pawns
    const BitBoard enemy_non_pawn_king_pieces =
        state_.KinglessOccupied(them) & ~state_.Pawns(them);
    const int dist_to_promotion = kRank8 - square.RelativeRank<us>();
    if (enemy_non_pawn_king_pieces == 0 &&
        dist_to_promotion < dist_to_enemy_king - (state_.turn == them)) {
      score += kKingCantReachPPBonus;
      TRACE_INCREMENT(kKingCantReachPPBonus, us);
    }
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
    if (!state_.Pawns()) {
      score += kNormalPieceSquareTable[kKnight][square.RelativeTo<us>()];
      TRACE_INCREMENT(kNormalPieceSquareTable[kKnight][square.RelativeTo<us>()],
                      us);
    }

    const BitBoard legal_moves =
        LegalizeMoves(kKnight, square, move_gen::KnightMoves(square), us);
    const BitBoard mobility = legal_moves & mobility_zone_[us];

    score += kKnightMobility[mobility.PopCount()];
    TRACE_INCREMENT(kKnightMobility[mobility.PopCount()], us);

    knight_attacks_[us] |= legal_moves;

    const BitBoard enemy_king_attacks = mobility & king_zone_[FlipColor(us)];
    if (enemy_king_attacks) {
      const int king_attack_count = std::min(7, enemy_king_attacks.PopCount());
      attack_power_[us] += kAttackPower[kKnight][king_attack_count];
      TRACE_INCREMENT(kAttackPower[kKnight][king_attack_count], us);
    }

    if (IsOutpostSquare<us>(square)) {
      const int square_offset = 16 * (us == Color::kBlack ? -1 : 1);
      const int relative_square = (square + square_offset).RelativeTo(us);

      score += kKnightOutpostTable[relative_square];
      TRACE_INCREMENT(kKnightOutpostTable[relative_square], us);
    }
  }

  return score;
}

template <Color us>
ScorePair Evaluation::EvaluateBishops() {
  ScorePair score;

  const BitBoard our_bishops = state_.Bishops(us);
  const BitBoard occupied =
      state_.Occupied() ^ state_.Queens(us) ^ state_.Bishops(us);
  const int kb = state_.king_bucket[us],
            their_kb = state_.king_bucket[FlipColor(us)];

  if (our_bishops.MoreThanOne()) {
    score += kBishopPairBonus;
    TRACE_INCREMENT(kBishopPairBonus, us);
  }

  for (Square square : our_bishops) {
    TRACE_INCREMENT(kPieceValues[kBishop], us);
    if (!state_.Pawns()) {
      score += kNormalPieceSquareTable[kBishop][square.RelativeTo<us>()];
      TRACE_INCREMENT(kNormalPieceSquareTable[kBishop][square.RelativeTo<us>()],
                      us);
    }

    const BitBoard legal_moves = LegalizeMoves(
        kBishop, square, move_gen::BishopMoves(square, occupied), us);
    const BitBoard mobility = legal_moves & mobility_zone_[us];

    score += kBishopMobility[mobility.PopCount()];
    TRACE_INCREMENT(kBishopMobility[mobility.PopCount()], us);

    bishop_attacks_[us] |= legal_moves;

    const BitBoard enemy_king_attacks = mobility & king_zone_[FlipColor(us)];
    if (enemy_king_attacks) {
      const int king_attack_count = std::min(7, enemy_king_attacks.PopCount());
      attack_power_[us] += kAttackPower[kBishop][king_attack_count];
      TRACE_INCREMENT(kAttackPower[kBishop][king_attack_count], us);
    }

    if (IsOutpostSquare<us>(square)) {
      const int square_offset = 16 * (us == Color::kBlack ? -1 : 1);
      const int relative_square = (square + square_offset).RelativeTo(us);

      score += kBishopOutpostTable[relative_square];
      TRACE_INCREMENT(kBishopOutpostTable[relative_square], us);
    }
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
  const int kb = state_.king_bucket[us],
            their_kb = state_.king_bucket[FlipColor(us)];

  for (Square square : our_rooks) {
    TRACE_INCREMENT(kPieceValues[kRook], us);
    if (!state_.Pawns()) {
      score += kNormalPieceSquareTable[kRook][square.RelativeTo<us>()];
      TRACE_INCREMENT(kNormalPieceSquareTable[kRook][square.RelativeTo<us>()],
                      us);
    }

    const BitBoard legal_moves =
        LegalizeMoves(kRook, square, move_gen::RookMoves(square, occupied), us);
    const BitBoard mobility = legal_moves & mobility_zone_[us];

    score += kRookMobility[mobility.PopCount()];
    TRACE_INCREMENT(kRookMobility[mobility.PopCount()], us);

    rook_attacks_[us] |= legal_moves;

    const BitBoard enemy_king_attacks = mobility & king_zone_[FlipColor(us)];
    if (enemy_king_attacks) {
      const int king_attack_count = std::min(7, enemy_king_attacks.PopCount());
      attack_power_[us] += kAttackPower[kRook][king_attack_count];
      TRACE_INCREMENT(kAttackPower[kRook][king_attack_count], us);
    }

    const BitBoard our_pawns_on_file = our_pawns & masks::files[square];
    if (!our_pawns_on_file) {
      const BitBoard their_pawns_on_file = their_pawns & masks::files[square];
      const bool semi_open_file = their_pawns_on_file != 0;

      score += kRookOnFileBonus[semi_open_file][square.File()];
      TRACE_INCREMENT(kRookOnFileBonus[semi_open_file][square.File()], us);
    }
  }

  return score;
}

template <Color us>
ScorePair Evaluation::EvaluateQueens() {
  ScorePair score;

  const BitBoard our_queens = state_.Queens(us);
  const BitBoard occupied =
      state_.Occupied() ^ state_.Bishops(us) ^ state_.Rooks(us);
  const int kb = state_.king_bucket[us],
            their_kb = state_.king_bucket[FlipColor(us)];

  for (Square square : our_queens) {
    TRACE_INCREMENT(kPieceValues[kQueen], us);
    if (!state_.Pawns()) {
      score += kNormalPieceSquareTable[kQueen][square.RelativeTo<us>()];
      TRACE_INCREMENT(kNormalPieceSquareTable[kQueen][square.RelativeTo<us>()],
                      us);
    }

    const BitBoard legal_moves = LegalizeMoves(
        kQueen, square, move_gen::QueenMoves(square, occupied), us);
    const BitBoard mobility = legal_moves & mobility_zone_[us];

    score += kQueenMobility[mobility.PopCount()];
    TRACE_INCREMENT(kQueenMobility[mobility.PopCount()], us);

    queen_attacks_[us] |= legal_moves;

    const BitBoard enemy_king_attacks = mobility & king_zone_[FlipColor(us)];
    if (enemy_king_attacks) {
      const int king_attack_count = std::min(7, enemy_king_attacks.PopCount());
      attack_power_[us] += kAttackPower[kQueen][king_attack_count];
      TRACE_INCREMENT(kAttackPower[kQueen][king_attack_count], us);
    }
  }

  return score;
}

template <Color us>
ScorePair Evaluation::EvaluateKing() {
  ScorePair score;

  const Square square = state_.King(us).GetLsb();
  if (!state_.Pawns()) {
    score += kNormalPieceSquareTable[kKing][square.RelativeTo<us>()];
    TRACE_INCREMENT(kNormalPieceSquareTable[kKing][square.RelativeTo<us>()],
                    us);
  }

  const Color them = FlipColor(us);

  const BitBoard our_pawns = state_.Pawns(us);
  const BitBoard their_pawns = state_.Pawns(them);

  const int king_rank = square.Rank();
  const int king_file = square.File();

  const BitBoard our_pawns_in_safety_zone = our_pawns & king_zone_[us];
  for (const Square pawn_square : our_pawns_in_safety_zone) {
    const int pawn_rank = pawn_square.Rank();
    const int pawn_file = pawn_square.File();

    constexpr int kKingIndexInZone = 7;
    constexpr int kZoneWidth = 3;

    const int rank_diff = (pawn_rank - king_rank);
    const int file_diff = (pawn_file - king_file);

    const int idx = kKingIndexInZone - (rank_diff * kZoneWidth + file_diff) *
                                           (us == Color::kBlack ? -1 : 1);

    score += kPawnShelterTable[idx];
    TRACE_INCREMENT(kPawnShelterTable[idx], us);
  }

  const Square their_king_square = state_.King(them).GetLsb();
  const int their_king_rank = their_king_square.Rank();
  const int their_king_file = their_king_square.File();

  const BitBoard storming_pawns = our_pawns & pawn_storm_zone_[them];
  for (const Square pawn_square : storming_pawns) {
    const int pawn_rank = pawn_square.Rank();
    const int pawn_file = pawn_square.File();

    constexpr int kKingIndexInZone = 19;
    constexpr int kZoneWidth = 3;

    const int rank_diff = (pawn_rank - their_king_rank);
    const int file_diff = (pawn_file - their_king_file);

    const int idx = kKingIndexInZone - (rank_diff * kZoneWidth + file_diff) *
                                           (them == Color::kBlack ? -1 : 1);

    score += kPawnStormTable[idx];
    TRACE_INCREMENT(kPawnStormTable[idx], us);
  }

  const BitBoard our_pawns_on_file = our_pawns & masks::files[square];
  if (!our_pawns_on_file) {
    const BitBoard their_pawns_on_file = their_pawns & masks::files[square];
    const bool semi_open_file = their_pawns_on_file != 0;

    score += kKingOnFilePenalty[semi_open_file][square.File()];
    TRACE_INCREMENT(kKingOnFilePenalty[semi_open_file][square.File()], us);
  }

  // King danger
  score -= attack_power_[them];

  return score;
}

template <Color us>
ScorePair Evaluation::EvaluateThreats() {
  ScorePair score;

  const Color them = FlipColor(us);
  const BitBoard our_pieces = state_.Occupied(us);
  const BitBoard our_attacks = pawn_attacks_[us] | knight_attacks_[us] |
                               bishop_attacks_[us] | rook_attacks_[us] |
                               queen_attacks_[us];

  for (Square square : knight_attacks_[them] & our_pieces) {
    const auto threatened_piece = state_.GetPieceType(square);
    const bool defended = our_attacks.IsSet(square);
    score += kThreatenedByKnightPenalty[threatened_piece][defended];
    TRACE_INCREMENT(kThreatenedByKnightPenalty[threatened_piece][defended], us);
  }

  for (Square square : bishop_attacks_[them] & our_pieces) {
    const auto threatened_piece = state_.GetPieceType(square);
    const bool defended = our_attacks.IsSet(square);
    score += kThreatenedByBishopPenalty[threatened_piece][defended];
    TRACE_INCREMENT(kThreatenedByBishopPenalty[threatened_piece][defended], us);
  }

  for (Square square : rook_attacks_[them] & our_pieces) {
    const auto threatened_piece = state_.GetPieceType(square);
    const bool defended = our_attacks.IsSet(square);
    score += kThreatenedByRookPenalty[threatened_piece][defended];
    TRACE_INCREMENT(kThreatenedByRookPenalty[threatened_piece][defended], us);
  }

  for (Square square : pawn_attacks_[them] & our_pieces) {
    const auto threatened_piece = state_.GetPieceType(square);
    const bool defended = our_attacks.IsSet(square);
    score += kThreatenedByPawnPenalty[threatened_piece][defended];
    TRACE_INCREMENT(kThreatenedByPawnPenalty[threatened_piece][defended], us);
  }

  // Calculate all squares defended by the enemy, excluding squares that are
  // defended by our pawn(s) and not attacked by their pawn(s)
  const BitBoard enemy_defended_squares =
      pawn_attacks_[them] | ((knight_attacks_[them] | bishop_attacks_[them] |
                              rook_attacks_[them] | queen_attacks_[them]) &
                             ~pawn_attacks_[us]);
  const BitBoard safe_pawn_pushes = move_gen::PawnPushes(state_.Pawns(us), us) &
                                    ~state_.Occupied() &
                                    ~enemy_defended_squares;

  // Calculate which piece would be threatened if we pushed our pawn's here
  const BitBoard pawn_push_threats =
      move_gen::PawnAttacks(safe_pawn_pushes, us) & state_.Occupied(them) &
      ~state_.Pawns(them);
  for (Square square : pawn_push_threats) {
    const auto threatened = state_.GetPieceType(square);
    score += kPawnPushThreat[threatened];
    TRACE_INCREMENT(kPawnPushThreat[threatened], us);
  }

  // Count the number of squares that our pieces can make to place the enemy
  // king in check
  const BitBoard occupied = state_.Occupied();
  const Square their_king_square = state_.King(them).GetLsb();

  const BitBoard rook_checks = move_gen::RookMoves(their_king_square, occupied);
  const BitBoard bishop_checks =
      move_gen::BishopMoves(their_king_square, occupied);

  const BitBoard safe =
      ~(pawn_attacks_[them] | knight_attacks_[them] | bishop_attacks_[them] |
        rook_attacks_[them] | move_gen::KingAttacks(their_king_square));
  const BitBoard safe_knight_checks =
      safe & knight_attacks_[us] & move_gen::KnightMoves(their_king_square);
  const BitBoard safe_bishop_checks =
      safe & bishop_attacks_[us] & bishop_checks;
  const BitBoard safe_rook_checks = safe & rook_attacks_[us] & rook_checks;
  const BitBoard safe_queen_checks =
      safe & queen_attacks_[us] & (bishop_checks | rook_checks);

  score += kSafeCheckBonus[kKnight] * safe_knight_checks.PopCount();
  score += kSafeCheckBonus[kBishop] * safe_bishop_checks.PopCount();
  score += kSafeCheckBonus[kRook] * safe_rook_checks.PopCount();
  score += kSafeCheckBonus[kQueen] * safe_queen_checks.PopCount();

  TRACE_ADD(kSafeCheckBonus[kKnight], safe_knight_checks.PopCount(), us);
  TRACE_ADD(kSafeCheckBonus[kBishop], safe_bishop_checks.PopCount(), us);
  TRACE_ADD(kSafeCheckBonus[kRook], safe_rook_checks.PopCount(), us);
  TRACE_ADD(kSafeCheckBonus[kQueen], safe_queen_checks.PopCount(), us);

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