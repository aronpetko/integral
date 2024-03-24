#include "eval.h"
#include "move_gen.h"

namespace eval {

const std::array<std::array<int, 64>, PieceType::kNumPieceTypes> kPieceSquareTables = {{
    { // pawns
      0, 0, 0, 0, 0, 0, 0, 0,
      50, 50, 50, 50, 50, 50, 50, 50,
      10, 10, 20, 30, 30, 20, 10, 10,
      5, 5, 10, 25, 25, 10, 5, 5,
      0, 0, 0, 20, 20, 0, 0, 0,
      5, -5, -10, 0, 0, -10, -5, 5,
      5, 10, 10, -20, -20, 10, 10, 5,
      0, 0, 0, 0, 0, 0, 0, 0
    },
    { // knights
      -50, -40, -30, -30, -30, -30, -40, -50,
      -40, -20, 0, 0, 0, 0, -20, -40,
      -30, 0, 10, 15, 15, 10, 0, -30,
      -30, 5, 15, 20, 20, 15, 5, -30,
      -30, 0, 15, 20, 20, 15, 0, -30,
      -30, 5, 10, 15, 15, 10, 5, -30,
      -40, -20, 0, 5, 5, 0, -20, -40,
      -50, -40, -30, -30, -30, -30, -40, -50,
    },
    { // bishops
      -20, -10, -10, -10, -10, -10, -10, -20,
      -10, 0, 0, 0, 0, 0, 0, -10,
      -10, 0, 5, 10, 10, 5, 0, -10,
      -10, 5, 5, 10, 10, 5, 5, -10,
      -10, 0, 10, 10, 10, 10, 0, -10,
      -10, 10, 10, 10, 10, 10, 10, -10,
      -10, 5, 0, 0, 0, 0, 5, -10,
      -20, -10, -10, -10, -10, -10, -10, -20,
    },
    { // rooks
      0, 0, 0, 0, 0, 0, 0, 0,
      5, 10, 10, 10, 10, 10, 10, 5,
      -5, 0, 0, 0, 0, 0, 0, -5,
      -5, 0, 0, 0, 0, 0, 0, -5,
      -5, 0, 0, 0, 0, 0, 0, -5,
      -5, 0, 0, 0, 0, 0, 0, -5,
      -5, 0, 0, 0, 0, 0, 0, -5,
      0, 0, 0, 5, 5, 0, 0, 0
    },
    { // queens
      -20, -10, -10, -5, -5, -10, -10, -20,
      -10, 0, 0, 0, 0, 0, 0, -10,
      -10, 0, 5, 5, 5, 5, 0, -10,
      -5, 0, 5, 5, 5, 5, 0, -5,
      0, 0, 5, 5, 5, 5, 0, -5,
      -10, 5, 5, 5, 5, 5, 0, -10,
      -10, 0, 5, 0, 0, 0, 0, -10,
      -20, -10, -10, -5, -5, -10, -10, -20
    },
    { // king middle game
      -30, -40, -40, -50, -50, -40, -40, -30,
      -30, -40, -40, -50, -50, -40, -40, -30,
      -30, -40, -40, -50, -50, -40, -40, -30,
      -30, -40, -40, -50, -50, -40, -40, -30,
      -20, -30, -30, -40, -40, -30, -30, -20,
      -10, -20, -20, -20, -20, -20, -20, -10,
      20, 20, 0, 0, 0, 0, 20, 20,
      20, 30, 10, 0, 0, 10, 30, 20
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

bool is_mate_score(int evaluation) {
  const int kThreshold = 1048;
  return kMateScore - abs(evaluation) <= kThreshold;
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
  const int white_material = state.pieces[Color::kWhite][kPawns].pop_count() * eval::kPieceValues[PieceType::kPawn]
      + state.pieces[Color::kWhite][kKnights].pop_count() * eval::kPieceValues[PieceType::kKnight] +
      + state.pieces[Color::kWhite][kBishops].pop_count() * eval::kPieceValues[PieceType::kBishop]
      + state.pieces[Color::kWhite][kQueens].pop_count() * eval::kPieceValues[PieceType::kQueen];
  const int black_material = state.pieces[Color::kBlack][kPawns].pop_count() * eval::kPieceValues[PieceType::kPawn]
      + state.pieces[Color::kBlack][kKnights].pop_count() * eval::kPieceValues[PieceType::kKnight] +
      + state.pieces[Color::kBlack][kBishops].pop_count() * eval::kPieceValues[PieceType::kBishop]
      + state.pieces[Color::kBlack][kQueens].pop_count() * eval::kPieceValues[PieceType::kQueen];

  return white_material + black_material <= 1600;
}

int material_difference(const BoardState &state) {
  int material = 0;

  material += state.pieces[Color::kWhite][kPawns].pop_count() * kPieceValues[PieceType::kPawn];
  material += state.pieces[Color::kWhite][kKnights].pop_count() * kPieceValues[PieceType::kKnight];
  material += state.pieces[Color::kWhite][kBishops].pop_count() * kPieceValues[PieceType::kBishop];
  material += state.pieces[Color::kWhite][kRooks].pop_count() * kPieceValues[PieceType::kRook];
  material += state.pieces[Color::kWhite][kQueens].pop_count() * kPieceValues[PieceType::kQueen];

  material -= state.pieces[Color::kBlack][kPawns].pop_count() * kPieceValues[PieceType::kPawn];
  material -= state.pieces[Color::kBlack][kKnights].pop_count() * kPieceValues[PieceType::kKnight];
  material -= state.pieces[Color::kBlack][kBishops].pop_count() * kPieceValues[PieceType::kBishop];
  material -= state.pieces[Color::kBlack][kRooks].pop_count() * kPieceValues[PieceType::kRook];
  material -= state.pieces[Color::kBlack][kQueens].pop_count() * kPieceValues[PieceType::kQueen];

  return state.turn == Color::kWhite ? material : -material;
}

int positional_difference(const BoardState &state) {
  int position_value = 0;

  const bool is_white = state.turn == Color::kWhite;
  const bool end_game = is_end_game(state);

  if (end_game) {
    const int king_pos = state.pieces[state.turn][kKings].get_lsb_pos();
    position_value += kKingEndgameScores[is_white ? king_pos ^ 56 : king_pos];
  }

  for (int i = 0; i < kPieceSquareTables.size(); i++) {
    BitBoard white_pieces = state.pieces[Color::kWhite][i];
    while (white_pieces) {
      position_value += kPieceSquareTables[i][white_pieces.pop_lsb() ^ 56];
    }

    BitBoard black_pieces = state.pieces[Color::kBlack][i];
    while (black_pieces) {
      position_value -= kPieceSquareTables[i][black_pieces.pop_lsb()];
    }
  }

  return state.turn == Color::kWhite ? position_value : -position_value;
}

int stacked_pawns_difference(const BoardState &state) {
  int stacked_pawns = 0;

  for (const auto& file_mask : kFileMasks) {
    const BitBoard white_pawns_on_file = state.pieces[Color::kWhite][kPawns] & file_mask;
    const BitBoard black_pawns_on_file = state.pieces[Color::kBlack][kPawns] & file_mask;
    stacked_pawns += (white_pawns_on_file.pop_count() > 1) - (black_pawns_on_file.pop_count() > 1);
  }

  const int kStackedPawnPenalty = -12;
  const int penalty = stacked_pawns * kStackedPawnPenalty;

  return state.turn == Color::kWhite ? penalty : -penalty;
}

int pawns_score(const BoardState &state) {
  return 0;
  const std::array<int, 7> kPassedPawnBonuses = {0, 100, 80, 55, 30, 15, 10}; // indexed by # of squares from promotion
  const std::array<int, 4> kIsolatedPawnPenalties = {-5, -30, -70, -110}; // indexed by # of isolated pawns (should never exceed 4)

  const BitBoard &white_pawns = state.pieces[Color::kWhite][kPawns];
  const BitBoard &black_pawns = state.pieces[Color::kBlack][kPawns];

  int white_isolated_pawns = 0, black_isolated_pawns = 0;
  int score = 0;

  for (int file = 0; file < kBoardFiles; file++) {
    const int left_side = std::max(0, file - 1), right_side = std::min(kBoardFiles - 1, file + 1);

    const auto white_pawns_on_file = white_pawns & kFileMasks[file];
    const auto black_pawns_on_file = black_pawns & kFileMasks[file];

    if (white_pawns_on_file) {
      const auto white_pawn_rank = rank(white_pawns_on_file.get_msb_pos());
      if (!black_pawns_on_file || (black_pawns_on_file && black_pawns_on_file.get_lsb_pos() >= white_pawn_rank)) {
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
      if (!white_pawns_on_file || (white_pawns_on_file && white_pawns_on_file.get_msb_pos() <= black_pawn_rank)) {
        score -= kPassedPawnBonuses[kBoardRanks - 1 - black_pawn_rank];
      }

      const auto black_pawns_left = black_pawns & kFileMasks[left_side];
      const auto black_pawns_right = black_pawns & kFileMasks[right_side];
      if (!black_pawns_left && !black_pawns_right) {
        black_isolated_pawns++;
      }
    }
  }

  score += kIsolatedPawnPenalties[white_isolated_pawns];
  score -= kIsolatedPawnPenalties[black_isolated_pawns];
  return state.turn == Color::kWhite ? score : -score;
}

int mobility_difference(const BoardState &state) {
  int mobility = 0;

  const BitBoard &all_pieces = state.occupied();
  const BitBoard &white_pawns = state.pieces[Color::kWhite][kPawns];
  const BitBoard &white_rooks = state.pieces[Color::kWhite][kRooks];
  const BitBoard &black_pawns = state.pieces[Color::kBlack][kPawns];
  const BitBoard &black_rooks = state.pieces[Color::kBlack][kRooks];

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
      else if (pieces_on_file == (white_pawns & kFileMasks[rook_file])){
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

  for (int color = Color::kBlack; color <= Color::kWhite; color++) {
    const auto king_pos = state.pieces[color][kKings].get_lsb_pos();
    const auto pawns = state.pieces[color][kPawns];

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
  return get_attacked_squares(state, state.turn).pop_count() - get_attacked_squares(state, flip_color(state.turn)).pop_count();
}

int evaluate(const BoardState &state) {
  const int material_diff = material_difference(state);
  const int position_value = positional_difference(state);
  const int stacked_pawns = stacked_pawns_difference(state);
  const int mobility = mobility_difference(state);
  const int passed_pawns = pawns_score(state);
  const int king_safety = king_safety_difference(state);
  const int square_control = square_control_difference(state);
  return material_diff + position_value;
}

}