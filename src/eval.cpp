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

const std::vector<int> kFlipTable = {
    56, 57, 58, 59, 60, 61, 62, 63,
    48, 49, 50, 51, 52, 53, 54, 55,
    40, 41, 42, 43, 44, 45, 46, 47,
    32, 33, 34, 35, 36, 37, 38, 39,
    24, 25, 26, 27, 28, 29, 30, 31,
    16, 17, 18, 19, 20, 21, 22, 23,
    8,  9, 10, 11, 12, 13, 14, 15,
    0,  1,  2,  3,  4,  5,  6,  7,
};

int material_count(Color turn, BoardState &state) {
  int material = 0;

  const int piece_idx_offset = turn == Color::kWhite ? kWhitePawns : kBlackPawns;
  for (int i = 1; i < kPieceValues.size(); i++) {
    const int piece_count = state.pieces[piece_idx_offset + i - 1].pop_count();
    const int piece_value = kPieceValues[i];
    material += piece_count * piece_value;
  }

  return material;
}

int piece_positions_value(Color turn, int material_count, BoardState &state) {
  int position_value = 0;

  const bool less_or_equal_material = material_count <= 0;
  const bool is_white = turn == Color::kWhite;
  const int piece_idx_offset = is_white ? kWhitePawns : kBlackPawns;

  for (int i = 0; i < kPieceSquareTables.size() - 1; i++) {
    const int piece_idx = i + piece_idx_offset;
    const bool is_king = piece_idx == kWhiteKing || piece_idx == kBlackKing;

    BitBoard pieces = state.pieces[piece_idx];
    while (pieces) {
      U8 pos = pieces.pop_lsb();

      const bool use_end_game_table = is_king && state.is_end_game() && less_or_equal_material;
      position_value += kPieceSquareTables[i + use_end_game_table][is_white ? kFlipTable[pos] : pos];
    }
  }

  return position_value;
}

int stacked_pawns_penalty(Color turn, BoardState &state) {
  int penalty = 0;

  // each stacked pawn is worth 3/4 of a pawn
  const int kStackedPawnPenalty = -static_cast<int>(kPieceValues[static_cast<int>(PieceType::kPawn)] * 0.75);
  const BitBoard &pawns = state.pieces[turn == Color::kWhite ? kWhitePawns : kBlackPawns];

  for (const auto& file_mask : kFileMasks) {
    penalty += std::max(0, ((pawns & file_mask).pop_count() - 1)) * kStackedPawnPenalty;
  }

  return penalty;
}

int piece_mobility_score(Color turn, BoardState &state) {
  int mobility = 0;

  const bool is_white = turn == Color::kWhite;

  const BitBoard &all_pieces = state.pieces[kAllPieces];
  const BitBoard &their_pawns = state.pieces[is_white ? kBlackPawns : kWhitePawns];

  // favor open/semi-open files
  BitBoard &our_rooks = state.pieces[is_white ? kWhiteRooks : kBlackRooks];
  BitBoard rooks = state.pieces[is_white ? kWhiteRooks : kBlackRooks];

  while (rooks) {
    U8 rook_file = rooks.pop_lsb() % kBoardFiles;

    // rook is on an open file, so it is worth 3/4 of a pawn
    if ((all_pieces & kFileMasks[rook_file]) == (our_rooks & kFileMasks[rook_file]))
      mobility += static_cast<int>(kPieceValues[static_cast<int>(PieceType::kPawn)] * 0.75);

    // rook is on a semi-open file (a file with only opposing pawns), so it is worth half a pawn
    if ((their_pawns & kFileMasks[rook_file]) == (all_pieces & kFileMasks[rook_file]))
      mobility += static_cast<int>(kPieceValues[static_cast<int>(PieceType::kPawn)] * 0.5);
  }

  // our king should be less mobile in the mid-game
  const BitBoard &our_king = state.pieces[is_white ? kWhiteKing : kBlackKing];
  if (!state.is_end_game()) {
    BitBoard king_moves = generate_king_moves(our_king.get_lsb_pos(), state, false);
    const int king_open_squares = (~all_pieces & king_moves).pop_count();

    // ideally we want the king to only move left/right in the mid-game (protected by pawns in front of it)
    if (king_open_squares > 2) {
      // for every square a king can move to, let's deduct 3/4 of a pawn
      const int kOpenSquarePenalty = static_cast<int>(kPieceValues[static_cast<int>(PieceType::kPawn)] * 0.75);
      mobility -= king_open_squares * kOpenSquarePenalty;
    }
  }

  return mobility;
}

int evaluate(BoardState &state) {
  const int material_diff = material_count(state.turn, state) - material_count(flip_color(state.turn), state);
  const int position_value = piece_positions_value(state.turn, material_diff, state) - piece_positions_value(flip_color(state.turn), material_diff, state);
  const int stacked_pawns = stacked_pawns_penalty(state.turn, state) - stacked_pawns_penalty(flip_color(state.turn), state);
  const int mobility_score = piece_mobility_score(state.turn, state) - piece_mobility_score(flip_color(state.turn), state);

  return material_diff + position_value + mobility_score + stacked_pawns;
}

}