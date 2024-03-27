#include "eval.h"
#include "move_gen.h"

namespace eval {

const std::array<std::array<int, 64>, PieceType::kNumPieceTypes> kPieceSquareTables = {{
                                                                                           { // pawns
                                                                                               0, 0, 0, 0, 0, 0, 0, 0,
                                                                                               50, 50, 50, 50, 50, 50,
                                                                                               50, 50, 10, 10, 20, 30,
                                                                                               30, 20,
                                                                                               10, 10,
                                                                                               5, 5, 10, 25, 25, 10, 5,
                                                                                               5,
                                                                                               0, 0, 0, 20, 20, 0, 0, 0,
                                                                                               5, -5, -10, 0, 0, -10,
                                                                                               -5, 5,
                                                                                               5, 10, 10, -20, -20, 10,
                                                                                               10, 5,
                                                                                               0, 0, 0, 0, 0, 0, 0, 0
                                                                                           },
                                                                                           { // knights
                                                                                               -50, -40, -30, -30, -30,
                                                                                               -30, -40, -50,
                                                                                               -40, -20, 0, 0, 0, 0,
                                                                                               -20, -40,
                                                                                               -30, 0, 10, 15, 15, 10,
                                                                                               0, -30,
                                                                                               -30, 5, 15, 20, 20, 15,
                                                                                               5, -30,
                                                                                               -30, 0, 15, 20, 20, 15,
                                                                                               0, -30,
                                                                                               -30, 5, 10, 15, 15, 10,
                                                                                               5, -30,
                                                                                               -40, -20, 0, 5, 5, 0,
                                                                                               -20, -40,
                                                                                               -50, -40, -30, -30, -30,
                                                                                               -30, -40, -50,
                                                                                           },
                                                                                           { // bishops
                                                                                               -20, -10, -10, -10, -10,
                                                                                               -10, -10, -20,
                                                                                               -10, 0, 0, 0, 0, 0, 0,
                                                                                               -10,
                                                                                               -10, 0, 5, 10, 10, 5, 0,
                                                                                               -10,
                                                                                               -10, 5, 5, 10, 10, 5, 5,
                                                                                               -10,
                                                                                               -10, 0, 10, 10, 10, 10,
                                                                                               0, -10,
                                                                                               -10, 10, 10, 10, 10, 10,
                                                                                               10, -10,
                                                                                               -10, 5, 0, 0, 0, 0, 5,
                                                                                               -10,
                                                                                               -20, -10, -10, -10, -10,
                                                                                               -10, -10, -20,
                                                                                           },
                                                                                           { // rooks
                                                                                               0, 0, 0, 0, 0, 0, 0, 0,
                                                                                               5, 10, 10, 10, 10, 10,
                                                                                               10, 5,
                                                                                               -5, 0, 0, 0, 0, 0, 0, -5,
                                                                                               -5, 0, 0, 0, 0, 0, 0, -5,
                                                                                               -5, 0, 0, 0, 0, 0, 0, -5,
                                                                                               -5, 0, 0, 0, 0, 0, 0, -5,
                                                                                               -5, 0, 0, 0, 0, 0, 0, -5,
                                                                                               0, 0, 0, 5, 5, 0, 0, 0
                                                                                           },
                                                                                           { // queens
                                                                                               -20, -10, -10, -5, -5,
                                                                                               -10, -10, -20,
                                                                                               -10, 0, 0, 0, 0, 0, 0,
                                                                                               -10,
                                                                                               -10, 0, 5, 5, 5, 5, 0,
                                                                                               -10,
                                                                                               -5, 0, 5, 5, 5, 5, 0, -5,
                                                                                               0, 0, 5, 5, 5, 5, 0, -5,
                                                                                               -10, 5, 5, 5, 5, 5, 0,
                                                                                               -10,
                                                                                               -10, 0, 5, 0, 0, 0, 0,
                                                                                               -10,
                                                                                               -20, -10, -10, -5, -5,
                                                                                               -10, -10, -20
                                                                                           },
                                                                                           { // king middle game
                                                                                               -30, -40, -40, -50, -50,
                                                                                               -40, -40, -30,
                                                                                               -30, -40, -40, -50, -50,
                                                                                               -40, -40, -30,
                                                                                               -30, -40, -40, -50, -50,
                                                                                               -40, -40, -30,
                                                                                               -30, -40, -40, -50, -50,
                                                                                               -40, -40, -30,
                                                                                               -20, -30, -30, -40, -40,
                                                                                               -30, -30, -20,
                                                                                               -10, -20, -20, -20, -20,
                                                                                               -20, -20, -10,
                                                                                               20, 20, 0, 0, 0, 0, 20,
                                                                                               20,
                                                                                               20, 30, 10, 0, 0, 10, 30,
                                                                                               20
                                                                                           },
                                                                                           }};

const std::array<int, 64> kKingEndgameScores = {
    -50, -40, -30, -20, -20, -30, -40, -50,
    -30, -20, -10, 0, 0, -10, -20, -30,
    -30, -10, 20, 30, 30, 20, -10, -30,
    -30, -10, 30, 40, 40, 30, -10, -30,
    -30, -10, 30, 40, 40, 30, -10, -30,
    -30, -10, 20, 30, 30, 20, -10, -30,
    -30, -30, 0, 0, 0, 0, -30, -30,
    -50, -30, -30, -30, -30, -30, -30, -50
};

const std::array<int, 64> kPawnEndgameScores = {
    0, 0, 0, 0, 0, 0, 0, 0,
    80, 80, 80, 80, 80, 80, 80, 80,
    50, 50, 50, 50, 50, 50, 50, 50,
    30, 30, 30, 30, 30, 30, 30, 30,
    20, 20, 20, 20, 20, 20, 20, 20,
    10, 10, 10, 10, 10, 10, 10, 10,
    10, 10, 10, 10, 10, 10, 10, 10,
    0, 0, 0, 0, 0, 0, 0, 0
};

int mg_value[6] = { 82, 337, 365, 477, 1025,  0};
int eg_value[6] = { 94, 281, 297, 512,  936,  0};

/* piece/sq tables */
/* values from Rofchade: http://www.talkchess.com/forum3/viewtopic.php?f=2&t=68311&start=19 */

int mg_pawn_table[64] = {
    0,   0,   0,   0,   0,   0,  0,   0,
    98, 134,  61,  95,  68, 126, 34, -11,
    -6,   7,  26,  31,  65,  56, 25, -20,
    -14,  13,   6,  21,  23,  12, 17, -23,
    -27,  -2,  -5,  12,  17,   6, 10, -25,
    -26,  -4,  -4, -10,   3,   3, 33, -12,
    -35,  -1, -20, -23, -15,  24, 38, -22,
    0,   0,   0,   0,   0,   0,  0,   0,
};

int eg_pawn_table[64] = {
    0,   0,   0,   0,   0,   0,   0,   0,
    178, 173, 158, 134, 147, 132, 165, 187,
    94, 100,  85,  67,  56,  53,  82,  84,
    32,  24,  13,   5,  -2,   4,  17,  17,
    13,   9,  -3,  -7,  -7,  -8,   3,  -1,
    4,   7,  -6,   1,   0,  -5,  -1,  -8,
    13,   8,   8,  10,  13,   0,   2,  -7,
    0,   0,   0,   0,   0,   0,   0,   0,
};

int mg_knight_table[64] = {
    -167, -89, -34, -49,  61, -97, -15, -107,
    -73, -41,  72,  36,  23,  62,   7,  -17,
    -47,  60,  37,  65,  84, 129,  73,   44,
    -9,  17,  19,  53,  37,  69,  18,   22,
    -13,   4,  16,  13,  28,  19,  21,   -8,
    -23,  -9,  12,  10,  19,  17,  25,  -16,
    -29, -53, -12,  -3,  -1,  18, -14,  -19,
    -105, -21, -58, -33, -17, -28, -19,  -23,
};

int eg_knight_table[64] = {
    -58, -38, -13, -28, -31, -27, -63, -99,
    -25,  -8, -25,  -2,  -9, -25, -24, -52,
    -24, -20,  10,   9,  -1,  -9, -19, -41,
    -17,   3,  22,  22,  22,  11,   8, -18,
    -18,  -6,  16,  25,  16,  17,   4, -18,
    -23,  -3,  -1,  15,  10,  -3, -20, -22,
    -42, -20, -10,  -5,  -2, -20, -23, -44,
    -29, -51, -23, -15, -22, -18, -50, -64,
};

int mg_bishop_table[64] = {
    -29,   4, -82, -37, -25, -42,   7,  -8,
    -26,  16, -18, -13,  30,  59,  18, -47,
    -16,  37,  43,  40,  35,  50,  37,  -2,
    -4,   5,  19,  50,  37,  37,   7,  -2,
    -6,  13,  13,  26,  34,  12,  10,   4,
    0,  15,  15,  15,  14,  27,  18,  10,
    4,  15,  16,   0,   7,  21,  33,   1,
    -33,  -3, -14, -21, -13, -12, -39, -21,
};

int eg_bishop_table[64] = {
    -14, -21, -11,  -8, -7,  -9, -17, -24,
    -8,  -4,   7, -12, -3, -13,  -4, -14,
    2,  -8,   0,  -1, -2,   6,   0,   4,
    -3,   9,  12,   9, 14,  10,   3,   2,
    -6,   3,  13,  19,  7,  10,  -3,  -9,
    -12,  -3,   8,  10, 13,   3,  -7, -15,
    -14, -18,  -7,  -1,  4,  -9, -15, -27,
    -23,  -9, -23,  -5, -9, -16,  -5, -17,
};

int mg_rook_table[64] = {
    32,  42,  32,  51, 63,  9,  31,  43,
    27,  32,  58,  62, 80, 67,  26,  44,
    -5,  19,  26,  36, 17, 45,  61,  16,
    -24, -11,   7,  26, 24, 35,  -8, -20,
    -36, -26, -12,  -1,  9, -7,   6, -23,
    -45, -25, -16, -17,  3,  0,  -5, -33,
    -44, -16, -20,  -9, -1, 11,  -6, -71,
    -19, -13,   1,  17, 16,  7, -37, -26,
};

int eg_rook_table[64] = {
    13, 10, 18, 15, 12,  12,   8,   5,
    11, 13, 13, 11, -3,   3,   8,   3,
    7,  7,  7,  5,  4,  -3,  -5,  -3,
    4,  3, 13,  1,  2,   1,  -1,   2,
    3,  5,  8,  4, -5,  -6,  -8, -11,
    -4,  0, -5, -1, -7, -12,  -8, -16,
    -6, -6,  0,  2, -9,  -9, -11,  -3,
    -9,  2,  3, -1, -5, -13,   4, -20,
};

int mg_queen_table[64] = {
    -28,   0,  29,  12,  59,  44,  43,  45,
    -24, -39,  -5,   1, -16,  57,  28,  54,
    -13, -17,   7,   8,  29,  56,  47,  57,
    -27, -27, -16, -16,  -1,  17,  -2,   1,
    -9, -26,  -9, -10,  -2,  -4,   3,  -3,
    -14,   2, -11,  -2,  -5,   2,  14,   5,
    -35,  -8,  11,   2,   8,  15,  -3,   1,
    -1, -18,  -9,  10, -15, -25, -31, -50,
};

int eg_queen_table[64] = {
    -9,  22,  22,  27,  27,  19,  10,  20,
    -17,  20,  32,  41,  58,  25,  30,   0,
    -20,   6,   9,  49,  47,  35,  19,   9,
    3,  22,  24,  45,  57,  40,  57,  36,
    -18,  28,  19,  47,  31,  34,  39,  23,
    -16, -27,  15,   6,   9,  17,  10,   5,
    -22, -23, -30, -16, -16, -23, -36, -32,
    -33, -28, -22, -43,  -5, -32, -20, -41,
};

int mg_king_table[64] = {
    -65,  23,  16, -15, -56, -34,   2,  13,
    29,  -1, -20,  -7,  -8,  -4, -38, -29,
    -9,  24,   2, -16, -20,   6,  22, -22,
    -17, -20, -12, -27, -30, -25, -14, -36,
    -49,  -1, -27, -39, -46, -44, -33, -51,
    -14, -14, -22, -46, -44, -30, -15, -27,
    1,   7,  -8, -64, -43, -16,   9,   8,
    -15,  36,  12, -54,   8, -28,  24,  14,
};

int eg_king_table[64] = {
    -74, -35, -18, -18, -11,  15,   4, -17,
    -12,  17,  14,  17,  17,  38,  23,  11,
    10,  17,  23,  15,  20,  45,  44,  13,
    -8,  22,  24,  27,  26,  33,  26,   3,
    -18,  -4,  21,  24,  27,  23,   9, -11,
    -19,  -3,  11,  21,  23,  16,   7,  -9,
    -27, -11,   4,  13,  14,   4,  -5, -17,
    -53, -34, -21, -11, -28, -14, -24, -43
};

int* mg_pesto_table[6] =
    {
        mg_pawn_table,
        mg_knight_table,
        mg_bishop_table,
        mg_rook_table,
        mg_queen_table,
        mg_king_table
    };

int* eg_pesto_table[6] =
    {
        eg_pawn_table,
        eg_knight_table,
        eg_bishop_table,
        eg_rook_table,
        eg_queen_table,
        eg_king_table
    };

int gamephaseInc[PieceType::kNumPieceTypes] = {0,1,1,2,4,0};
int mg_table[2][PieceType::kNumPieceTypes][64];
int eg_table[2][PieceType::kNumPieceTypes][64];

void init_tables()
{
  for (int i = 0; i < PieceType::kNumPieceTypes; i++) {
    for (int sq = 0; sq < 64; sq++) {
      mg_table[Color::kWhite][i][sq] = mg_value[i] + mg_pesto_table[i][sq ^ 56];
      eg_table[Color::kWhite][i][sq] = eg_value[i] + eg_pesto_table[i][sq ^ 56];
      mg_table[Color::kBlack][i][sq] = mg_value[i] + mg_pesto_table[i][sq];
      eg_table[Color::kBlack][i][sq] = eg_value[i] + eg_pesto_table[i][sq];
    }
  }
}

bool is_mate_score(int evaluation) {
  const int kThreshold = 1048;
  return kMateScore - std::abs(evaluation) <= kThreshold;
}

int mate_in(int evaluation) {
  if (evaluation > 0 && evaluation < kMateScore) { // mate in favor
    return (kMateScore - evaluation + 1) / 2;
  } else if (evaluation < 0 && evaluation > -kMateScore) { // mate against
    return (kMateScore + evaluation) / 2;
  }

  // not a mate score
  return evaluation;
}

// idea: instead of returning true/false have an end game factor that is some interpolation of the material and game phase
//       this would be valuable for variable evaluation bonuses/penalties
bool is_end_game(const BoardState &state) {
  const int white_material = state.pawns(Color::kWhite).pop_count() * eval::kPieceValues[PieceType::kPawn]
      + state.knights(Color::kWhite).pop_count() * eval::kPieceValues[PieceType::kKnight]
      + state.bishops(Color::kWhite).pop_count() * eval::kPieceValues[PieceType::kBishop]
      + state.rooks(Color::kWhite).pop_count() * eval::kPieceValues[PieceType::kRook]
      + state.queens(Color::kWhite).pop_count() * eval::kPieceValues[PieceType::kQueen];
  const int black_material = state.pawns(Color::kBlack).pop_count() * eval::kPieceValues[PieceType::kPawn]
      + state.knights(Color::kBlack).pop_count() * eval::kPieceValues[PieceType::kKnight]
      + state.bishops(Color::kBlack).pop_count() * eval::kPieceValues[PieceType::kBishop]
      + state.rooks(Color::kBlack).pop_count() * eval::kPieceValues[PieceType::kRook]
      + state.queens(Color::kBlack).pop_count() * eval::kPieceValues[PieceType::kQueen];

  return white_material + black_material <= 1600;
}

int material_difference(const BoardState &state) {
  int material = 0;

  material += state.pawns(Color::kWhite).pop_count() * kPieceValues[PieceType::kPawn];
  material += state.knights(Color::kWhite).pop_count() * kPieceValues[PieceType::kKnight];
  material += state.bishops(Color::kWhite).pop_count() * kPieceValues[PieceType::kBishop];
  material += state.rooks(Color::kWhite).pop_count() * kPieceValues[PieceType::kRook];
  material += state.queens(Color::kWhite).pop_count() * kPieceValues[PieceType::kQueen];

  material -= state.pawns(Color::kBlack).pop_count() * kPieceValues[PieceType::kPawn];
  material -= state.knights(Color::kBlack).pop_count() * kPieceValues[PieceType::kKnight];
  material -= state.bishops(Color::kBlack).pop_count() * kPieceValues[PieceType::kBishop];
  material -= state.rooks(Color::kBlack).pop_count() * kPieceValues[PieceType::kRook];
  material -= state.queens(Color::kBlack).pop_count() * kPieceValues[PieceType::kQueen];

  return state.turn == Color::kWhite ? material : -material;
}

int positional_difference(const BoardState &state) {
  int position_value = 0;

  const bool is_white = state.turn == Color::kWhite;
  const bool end_game = is_end_game(state);

  if (end_game) {
    const int king_pos = state.king(state.turn).get_lsb_pos();
    position_value += kKingEndgameScores[is_white ? king_pos ^ 56 : king_pos];

    BitBoard white_pawns = state.pawns(Color::kWhite);
    while (white_pawns) {
      position_value += kPawnEndgameScores[white_pawns.pop_lsb() ^ 56];
    }

    BitBoard black_pawns = state.pawns(Color::kBlack);
    while (black_pawns) {
      position_value -= kPawnEndgameScores[black_pawns.pop_lsb()];
    }
  }

  for (int piece = end_game ? PieceType::kKnight : PieceType::kPawn; piece < kPieceSquareTables.size(); piece++) {
    const BitBoard &piece_bb = state.piece_bbs[piece];

    BitBoard white_pieces = piece_bb & state.side_bbs[Color::kWhite];
    while (white_pieces) {
      position_value += kPieceSquareTables[piece][white_pieces.pop_lsb() ^ 56];
    }

    BitBoard black_pieces = piece_bb & state.side_bbs[Color::kBlack];
    while (black_pieces) {
      position_value -= kPieceSquareTables[piece][black_pieces.pop_lsb()];
    }
  }

  return state.turn == Color::kWhite ? position_value : -position_value;
}

int pawns_score(const BoardState &state) {
  const int kStackedPawnPenalty = -12;
  // indexed by # of squares from promotion
  const std::array<int, 8> kPassedPawnBonuses = {0, 100, 80, 55, 30, 15, 10, 5};
  // indexed by # of isolated pawns (should never exceed 4)
  const std::array<int, 8> kIsolatedPawnPenalties = {-5, -30, -70, -110, -110, -110, -110, -110};

  const BitBoard &white_pawns = state.pawns(Color::kWhite);
  const BitBoard &black_pawns = state.pawns(Color::kBlack);

  int white_isolated_pawns = 0, black_isolated_pawns = 0;
  int white_stacked_pawns = 0, black_stacked_pawns = 0;

  int score = 0;

  for (int file = 0; file < kBoardFiles; file++) {
    const int left_side = std::max(0, file - 1), right_side = std::min(kBoardFiles - 1, file + 1);

    const auto white_pawns_on_file = white_pawns & kFileMasks[file];
    const auto black_pawns_on_file = black_pawns & kFileMasks[file];

    if (white_pawns_on_file) {
      const auto white_pawn_rank = rank(white_pawns_on_file.get_msb_pos());
      if (!black_pawns_on_file || (black_pawns_on_file && rank(black_pawns_on_file.get_lsb_pos()) <= white_pawn_rank)) {
        score += kPassedPawnBonuses[kBoardRanks - 1 - white_pawn_rank];
      }

      const auto white_pawns_left = white_pawns & kFileMasks[left_side];
      const auto white_pawns_right = white_pawns & kFileMasks[right_side];
      if (!white_pawns_left && !white_pawns_right) {
        white_isolated_pawns++;
      }
    }

    if (black_pawns_on_file) {
      const auto black_pawn_rank = rank(black_pawns_on_file.get_lsb_pos());
      if (!white_pawns_on_file || (white_pawns_on_file && rank(white_pawns_on_file.get_msb_pos()) >= black_pawn_rank)) {
        score -= kPassedPawnBonuses[black_pawn_rank];
      }

      const auto black_pawns_left = black_pawns & kFileMasks[left_side];
      const auto black_pawns_right = black_pawns & kFileMasks[right_side];
      if (!black_pawns_left && !black_pawns_right) {
        black_isolated_pawns++;
      }
    }

    white_stacked_pawns += white_pawns_on_file.pop_count() > 1;
    black_stacked_pawns += black_pawns_on_file.pop_count() > 1;
  }

  score += white_stacked_pawns * kStackedPawnPenalty;
  score -= black_stacked_pawns * kStackedPawnPenalty;

  score += kIsolatedPawnPenalties[white_isolated_pawns];
  score -= kIsolatedPawnPenalties[black_isolated_pawns];

  return state.turn == Color::kWhite ? score : -score;
}

int mobility_difference(const BoardState &state) {
  int mobility = 0;

  const BitBoard &all_pieces = state.occupied();
  const BitBoard &white_pawns = state.pawns(Color::kWhite);
  const BitBoard &white_rooks = state.rooks(Color::kWhite);
  const BitBoard &black_pawns = state.pawns(Color::kBlack);
  const BitBoard &black_rooks = state.rooks(Color::kBlack);

  const int kOpenFileBonus = 20;
  const int kSemiOpenFileBonus = 15;

  BitBoard white_rook = white_rooks;
  while (white_rook != 0ULL) {
    U8 rook_file = white_rook.pop_lsb() % kBoardFiles;

    auto pieces_on_file = all_pieces & kFileMasks[rook_file];
    if (pieces_on_file != 0) {
      // rook is on an open file, so it gains 3/4 of a pawn worth
      if (pieces_on_file == (white_rooks & kFileMasks[rook_file])) {
        mobility += kOpenFileBonus;
      }
        // rook is on a semi-open file (a file with only opposing pawns), so it gains half a pawn worth
      else if (pieces_on_file == (black_pawns & kFileMasks[rook_file])) {
        mobility += kSemiOpenFileBonus;
      }
    }
  }

  BitBoard black_rook = black_rooks;
  while (black_rook != 0ULL) {
    U8 rook_file = black_rook.pop_lsb() % kBoardFiles;

    auto pieces_on_file = all_pieces & kFileMasks[rook_file];
    if (pieces_on_file != 0) {
      // rook is on an open file, so it gains 3/4 of a pawn worth
      if (pieces_on_file == (black_rooks & kFileMasks[rook_file])) {
        mobility -= kOpenFileBonus;
      }
        // rook is on a semi-open file (a file with only opposing pawns), so it gains half a pawn worth
      else if (pieces_on_file == (white_pawns & kFileMasks[rook_file])) {
        mobility -= kSemiOpenFileBonus;
      }
    }
  }

  return state.turn == Color::kWhite ? mobility : -mobility;
}

int king_safety_difference(const BoardState &state) {
  int score = 0;

  const int kPawnProtectionBonus = 5;
  const int kDoublePawnProtectionBonus = 1;
  const int kNoPawnProtectionPenalty = -12;

  for (Color color = Color::kBlack; color <= Color::kWhite; color = Color(color + 1)) {
    const auto king_pos = state.king(color).get_lsb_pos();
    const auto pawns = state.pawns(color);

    const int king_file = file(king_pos);
    const int king_rank = rank(king_pos);

    for (int pawn_file = king_file - 1; pawn_file <= king_file + 1; pawn_file++) {
      // check if we're in bounds
      if (pawn_file >= 0 && pawn_file < kBoardFiles) {
        const int rank_shift = color == Color::kWhite ? 1 : -1;
        const int pawn_rank = king_rank + rank_shift;

        int black_protecting_pawns = 0, white_protecting_pawns = 0;

        if (pawns.is_set(rank_file_to_pos(pawn_rank, pawn_file))) {
          if (color == Color::kWhite) {
            score += kPawnProtectionBonus;
            ++white_protecting_pawns;
          } else {
            score -= kPawnProtectionBonus;
            ++black_protecting_pawns;
          }
        }

        const int pawn_two_ahead_rank = king_rank + rank_shift * 2;
        if (pawns.is_set(rank_file_to_pos(pawn_two_ahead_rank, pawn_file))) {
          if (color == Color::kWhite) {
            score += kDoublePawnProtectionBonus;
            ++white_protecting_pawns;
          } else {
            score -= kDoublePawnProtectionBonus;
            ++black_protecting_pawns;
          }
        }

        const int kIdealProtectingPawnsCount = 3;
        score += (kIdealProtectingPawnsCount - std::min(white_protecting_pawns, 3)) * kNoPawnProtectionPenalty;
        score -= (kIdealProtectingPawnsCount - std::min(black_protecting_pawns, 3)) * kNoPawnProtectionPenalty;
      }
    }
  }

  return state.turn == Color::kWhite ? score : -score;
}

int square_control_difference(const BoardState &state) {
  const BitBoard our_attacked_squares = get_attacked_squares(state, state.turn) & ~state.occupied(state.turn);
  const BitBoard their_attacked_squares = get_attacked_squares(state, flip_color(state.turn)) & ~state.occupied(flip_color(state.turn));
  return our_attacked_squares.pop_count() - their_attacked_squares.pop_count();
}

inline bool inited = false;

int evaluate(const BoardState &state) {
  if (!inited) {
    inited = true;
    init_tables();
  }

  int mg[2];
  int eg[2];
  int gamePhase = 0;

  mg[Color::kWhite] = 0;
  mg[Color::kBlack] = 0;
  eg[Color::kWhite] = 0;
  eg[Color::kBlack] = 0;

  /* evaluate each piece */
  for (int sq = 0; sq < 64; ++sq) {
    int pc = state.get_piece_type(sq);
    if (pc != PieceType::kNone) {
      const Color col = state.get_piece_color(sq);
      mg[col] += mg_table[col][pc][sq];
      eg[col] += eg_table[col][pc][sq];
      gamePhase += gamephaseInc[pc];
    }
  }

  /* tapered eval */
  int mgScore = mg[state.turn] - mg[flip_color(state.turn)];
  int egScore = eg[state.turn] - eg[flip_color(state.turn)];
  int mgPhase = gamePhase;
  if (mgPhase > 24) mgPhase = 24; /* in case of early promotion */
  int egPhase = 24 - mgPhase;
  return (mgScore * mgPhase + egScore * egPhase) / 24;

  /*
  const int material_diff = material_difference(state);
  const int position_value = positional_difference(state);
  const int pawns_structure = pawns_score(state);
  const int mobility = mobility_difference(state);
  const int king_safety = king_safety_difference(state);
  const int square_control = square_control_difference(state);
  return material_diff + position_value + mobility + king_safety + square_control + pawns_structure;*/
}

}