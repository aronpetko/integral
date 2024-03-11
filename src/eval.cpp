#include "eval.h"
#include "move_gen.h"

namespace eval {

const std::vector<std::vector<int>> kPieceSquareTables = {
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
    { // king end game
      -50, -40, -30, -20, -20, -30, -40, -50,
      -30, -20, -10, 0, 0, -10, -20, -30,
      -30, -10, 20, 30, 30, 20, -10, -30,
      -30, -10, 30, 40, 40, 30, -10, -30,
      -30, -10, 30, 40, 40, 30, -10, -30,
      -30, -10, 20, 30, 30, 20, -10, -30,
      -30, -30, 0, 0, 0, 0, -30, -30,
      -50, -30, -30, -30, -30, -30, -30, -50
    }
};

int material_difference(BoardState &state) {
  int material = 0;

  for (int i = 1; i < kPieceValues.size(); i++) {
    const int white_piece_idx = kWhitePawns + i - 1;
    const int black_piece_idx = kBlackPawns + i - 1;

    const int white_piece_count = state.pieces[white_piece_idx].pop_count();
    const int black_piece_count = state.pieces[black_piece_idx].pop_count();

    const int piece_value = kPieceValues[i];
    material += (white_piece_count - black_piece_count) * piece_value;
  }

  return state.turn == Color::kWhite ? material : -material;
}

int positional_difference(int material_diff, BoardState &state) {
  int position_value = 0;

  const bool less_or_equal_material = material_diff <= 0;
  const bool end_game = is_end_game(state);

  for (int i = 0; i < kPieceSquareTables.size() - 1; i++) {
    const int white_piece_idx = kWhitePawns + i;
    const int black_piece_idx = kBlackPawns + i;

    BitBoard white_pieces = state.pieces[white_piece_idx];
    while (white_pieces) {
      U8 pos = white_pieces.pop_lsb();

      const bool use_end_game_table = white_piece_idx == kWhiteKing && end_game && less_or_equal_material;
      position_value += kPieceSquareTables[i + use_end_game_table][pos ^ 56];
    }

    BitBoard black_pieces = state.pieces[black_piece_idx];
    while (black_pieces) {
      U8 pos = black_pieces.pop_lsb();

      const bool use_end_game_table = black_piece_idx == kBlackKing && end_game && less_or_equal_material;
      position_value -= kPieceSquareTables[i + use_end_game_table][pos];
    }
  }

  return state.turn == Color::kWhite ? position_value : -position_value;
}

int stacked_pawns_difference(BoardState &state) {
  int stacked_pawns = 0;

  auto pawns = &state.pieces[kWhitePawns];
  for (const auto& file_mask : kFileMasks)
    stacked_pawns += std::max(0, ((*pawns & file_mask).pop_count() - 1));

  pawns = &state.pieces[kBlackPawns];
  for (const auto& file_mask : kFileMasks)
    stacked_pawns -= std::max(0, ((*pawns & file_mask).pop_count() - 1));

  const int kStackedPawnPenalty = -12;
  const int penalty = stacked_pawns * kStackedPawnPenalty;

  return state.turn == Color::kWhite ? penalty : -penalty;
}

int passed_pawns_score(BoardState &state) {
  if (!is_end_game(state))
    return 0;

  int passed_pawns = 0;
  int rooks_behind_passers = 0;

  const BitBoard &white_pawns = state.pieces[kWhitePawns];
  const BitBoard &white_rooks = state.pieces[kWhiteRooks];
  const BitBoard &black_pawns = state.pieces[kBlackPawns];
  const BitBoard &black_rooks = state.pieces[kBlackRooks];

  for (const auto& file_mask : kFileMasks) {
    const BitBoard black_pawns_on_file = black_pawns & file_mask;
    const BitBoard white_pawns_on_file = white_pawns & file_mask;

    if (black_pawns_on_file == 0 && white_pawns_on_file) {
      passed_pawns++;

      const BitBoard white_rooks_on_file = white_rooks & file_mask;
      if (white_rooks_on_file && white_pawns_on_file.get_lsb_pos() / kBoardRanks >= 5) {
        if (white_pawns_on_file.get_lsb_pos() < white_rooks_on_file.get_msb_pos()) {
          rooks_behind_passers++;
        }
      }
    } else if (white_pawns_on_file == 0 && black_pawns_on_file) {
      passed_pawns--;

      const BitBoard black_rooks_on_file = black_rooks & file_mask;
      if (black_rooks_on_file && black_pawns_on_file.get_lsb_pos() / kBoardRanks <= 4) {
        if (black_pawns_on_file.get_msb_pos() < black_rooks_on_file.get_lsb_pos()) {
          rooks_behind_passers++;
        }
      }
    }
  }

  const int kPassedPawnBonus = 30;
  const int kRooksBehindPassersBonus = 5;
  const int score = passed_pawns * kPassedPawnBonus + rooks_behind_passers * kRooksBehindPassersBonus;

  return state.turn == Color::kWhite ? score : -score;
}

int mobility_difference(BoardState &state) {
  int mobility = 0;

  const BitBoard &all_pieces = state.pieces[kAllPieces];
  const BitBoard &white_pawns = state.pieces[kWhitePawns];
  const BitBoard &white_rooks = state.pieces[kWhiteRooks];
  const BitBoard &black_pawns = state.pieces[kBlackPawns];
  const BitBoard &black_rooks = state.pieces[kBlackRooks];

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

int king_safety_difference(BoardState &state) {
  int score = 0;

  const BitBoard &white_pawns = state.pieces[kWhitePawns];
  const BitBoard &white_king = state.pieces[kWhiteKing];
  const BitBoard &black_pawns = state.pieces[kBlackPawns];
  const BitBoard &black_king = state.pieces[kBlackKing];

  const int kPawnProtectionBonus = 5;
  const int kDoublePawnProtectionBonus = 4;

  const BitBoard white_left_protection = shift<Direction::kNorthWest>(white_king);
  const BitBoard white_right_protection = shift<Direction::kNorthEast>(white_king);
  const BitBoard white_front_protection = shift<Direction::kNorth>(white_king);

  BitBoard white_protection_squares = white_left_protection | white_front_protection | white_right_protection;
  score += kPawnProtectionBonus * (white_protection_squares & white_pawns).pop_count();

  white_protection_squares = shift<Direction::kNorth>(white_protection_squares);
  score += kDoublePawnProtectionBonus * (white_protection_squares & white_pawns).pop_count();

  const BitBoard black_left_protection = shift<Direction::kSouthWest>(black_king);
  const BitBoard black_right_protection = shift<Direction::kSouthEast>(black_king);
  const BitBoard black_front_protection = shift<Direction::kSouth>(black_king);

  BitBoard black_protection_squares = black_left_protection | black_front_protection | black_right_protection;
  score -= kPawnProtectionBonus * (black_protection_squares & black_pawns).pop_count();

  black_protection_squares = shift<Direction::kSouth>(black_protection_squares);
  score -= kDoublePawnProtectionBonus * (black_protection_squares & black_pawns).pop_count();

  return state.turn == Color::kWhite ? score : -score;
}

// idea: instead of returning true/false have an end game factor that is some interpolation of the material and game phase
//       this would be valuable for variable evaluation bonuses/penalties
bool is_end_game(BoardState &state) {
  const int white_material = state.pieces[kWhitePawns].pop_count() * eval::kPieceValues[PieceType::kPawn]
      + state.pieces[kWhiteKnights].pop_count() * eval::kPieceValues[PieceType::kKnight] +
      + state.pieces[kWhiteBishops].pop_count() * eval::kPieceValues[PieceType::kBishop]
      + state.pieces[kWhiteQueens].pop_count() * eval::kPieceValues[PieceType::kQueen];
  const int black_material = state.pieces[kBlackPawns].pop_count() * eval::kPieceValues[PieceType::kPawn]
      + state.pieces[kBlackKnights].pop_count() * eval::kPieceValues[PieceType::kKnight] +
      + state.pieces[kBlackBishops].pop_count() * eval::kPieceValues[PieceType::kBishop]
      + state.pieces[kBlackQueens].pop_count() * eval::kPieceValues[PieceType::kQueen];

  return white_material + black_material <= 2700;
}

int evaluate(BoardState &state) {
  const int material_diff = material_difference(state);
  const int position_value = positional_difference(material_diff, state);
  const int stacked_pawns = stacked_pawns_difference(state);
  const int mobility = mobility_difference(state);
  const int passed_pawns = passed_pawns_score(state);
  const int king_safety = king_safety_difference(state);

  return material_diff + position_value + king_safety + mobility + stacked_pawns;
}

}