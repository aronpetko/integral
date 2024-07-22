#include "zobrist.h"
#include "../chess/board.h"

namespace zobrist {

U64 GenKey(const BoardState &state) {
  U64 key = 0;
  for (Square square : state.Occupied()) {
    const auto piece_type = state.GetPieceType(square);
    const auto color = state.GetPieceColor(square);
    const int colored_piece = piece_type * 2 + color;
    key ^= pieces[colored_piece][square];
  }

  if (state.en_passant != Squares::kNoSquare) {
    key ^= en_passant[state.en_passant.File()];
  }

  if (state.turn == Color::kBlack)
    key ^= turn;

  key ^= castle_rights[state.castle_rights.AsU8()];
  return key;
}

}