#include "zobrist.h"
#include "board.h"

namespace zobrist {

U64 hash_turn(BoardState &state) {
  return state.turn == Color::kWhite ? kRandomsArray[Indices::kTurn] : 0ULL;
}

U64 hash_square(U8 square, BoardState &state) {
  const BitBoard bb_pos = BitBoard::from_square(square);
  if (state.piece_types[square] == PieceType::kNone)
    return 0ULL;

  const auto color = state.get_piece_color(bb_pos);

  /*
   * http://hgm.nubati.net/book_format.html
   * black pawn    0
   * white pawn    1
   * black knight  2
   * white knight  3
   * black bishop  4
   * white bishop  5
   * black rook    6
   * white rook    7
   * black queen   8
   * white queen   9
   * black king   10
   * white king   11
   */
  const int rank = square / kBoardRanks;
  const int file = square % kBoardFiles;

  const int piece_kind = state.get_piece_type(bb_pos) * 2 + color;
  const int piece_idx = Square::kSquareCount * piece_kind + kBoardRanks * rank + file;

  return kRandomsArray[piece_idx];
}

U64 hash_castle_rights(BoardState &state) {
  U64 hash = 0;
  if (state.castle.can_kingside_castle(Color::kWhite)) hash ^= kRandomsArray[Indices::kWhiteKingside];
  if (state.castle.can_queenside_castle(Color::kWhite)) hash ^= kRandomsArray[Indices::kWhiteQueenside];
  if (state.castle.can_kingside_castle(Color::kBlack)) hash ^= kRandomsArray[Indices::kBlackKingside];
  if (state.castle.can_queenside_castle(Color::kBlack)) hash ^= kRandomsArray[Indices::kBlackQueenside];
  return hash;
}

U64 hash_en_passant(BoardState &state) {
  if (!state.en_passant.has_value())
    return 0ULL;

  const auto ep_square = state.en_passant;

  // if our pawn can capture the en passant
  const BitBoard &our_pawns = state.pieces[state.turn][kPawns];

  BitBoard en_passant_bb = BitBoard::from_square(ep_square.value());
  en_passant_bb = state.turn == Color::kWhite ? shift<Direction::kSouth>(en_passant_bb) : shift<Direction::kNorth>(en_passant_bb);
  en_passant_bb = shift<Direction::kEast>(en_passant_bb) | shift<Direction::kWest>(en_passant_bb);

  if (en_passant_bb & our_pawns) {
    const int en_passant_file = file(ep_square.value());
    return kRandomsArray[Indices::kEnPassantFileA + en_passant_file];
  }

  return 0ULL;
}

U64 generate_key(BoardState &state) {
  U64 pieces = 0;
  for (int square = 0; square < Square::kSquareCount; square++)
    pieces ^= hash_square(square, state);

  return pieces ^ hash_castle_rights(state) ^ hash_en_passant(state) ^ hash_turn(state);
}

}