#include "zobrist.h"
#include "board.h"

namespace zobrist {

U64 hash_turn(Color turn) {
  return turn == Color::kWhite ? kRandomsArray[Indices::kTurn] : 0ULL;
}

U64 hash_square(U8 square, const BoardState &state, Color color, PieceType piece) {
  if (color == Color::kNoColor || piece == PieceType::kNone) {
    color = state.get_piece_color(square);
    piece = state.get_piece_type(square);
  }

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

  const int piece_idx =
      Square::kSquareCount * (static_cast<int>(piece) * 2 + color) + kNumRanks * rank(square) + file(square);
  return kRandomsArray[piece_idx];
}

U64 hash_castle_rights(const CastleRights &rights) {
  U64 hash = 0;
  if (rights.can_kingside_castle(Color::kWhite)) hash ^= kRandomsArray[Indices::kWhiteKingside];
  if (rights.can_queenside_castle(Color::kWhite)) hash ^= kRandomsArray[Indices::kWhiteQueenside];
  if (rights.can_kingside_castle(Color::kBlack)) hash ^= kRandomsArray[Indices::kBlackKingside];
  if (rights.can_queenside_castle(Color::kBlack)) hash ^= kRandomsArray[Indices::kBlackQueenside];
  return hash;
}

U64 hash_en_passant(const BoardState &state) {
  if (state.en_passant == Square::kNoSquare)
    return 0ULL;

  const auto ep_square = state.en_passant;

  // if our pawn can capture the en passant
  BitBoard en_passant_bb = BitBoard::from_square(ep_square);
  en_passant_bb = state.turn == Color::kWhite
                      ? shift<Direction::kSouthEast>(en_passant_bb) | shift<Direction::kSouthWest>(en_passant_bb)
                      : shift<Direction::kNorthEast>(en_passant_bb) | shift<Direction::kNorthWest>(en_passant_bb);

  if (en_passant_bb & state.pawns(state.turn))
    return kRandomsArray[Indices::kEnPassantFileA + file(ep_square)];
  return 0ULL;
}

U64 generate_key(const BoardState &state) {
  U64 pieces = 0;
  for (int square = 0; square < Square::kSquareCount; square++)
    if (state.piece_exists(square))
      pieces ^= hash_square(square, state);

  return pieces ^ hash_castle_rights(state.castle_rights) ^ hash_en_passant(state) ^ hash_turn(state.turn);
}

}