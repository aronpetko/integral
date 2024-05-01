#include "zobrist.h"

#include "../chess/board.h"

namespace zobrist {

U64 HashTurn(Color turn) {
  return turn == Color::kWhite ? kRandomsArray[Indices::kTurn] : 0ULL;
}

U64 HashSquare(Square square,
               const BoardState &state,
               Color color,
               PieceType piece) {
  if (color == Color::kNoColor || piece == PieceType::kNone) {
    color = state.GetPieceColor(square);
    piece = state.GetPieceType(square);
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
      Square::kSquareCount * (static_cast<int>(piece) * 2 + color) +
      kNumRanks * Rank(square) + File(square);
  return kRandomsArray[piece_idx];
}

U64 HashCastleRights(const CastleRights &rights) {
  U64 hash = 0;
  if (rights.CanKingsideCastle(Color::kWhite))
    hash ^= kRandomsArray[Indices::kWhiteKingside];
  if (rights.CanQueensideCastle(Color::kWhite))
    hash ^= kRandomsArray[Indices::kWhiteQueenside];
  if (rights.CanKingsideCastle(Color::kBlack))
    hash ^= kRandomsArray[Indices::kBlackKingside];
  if (rights.CanQueensideCastle(Color::kBlack))
    hash ^= kRandomsArray[Indices::kBlackQueenside];
  return hash;
}

U64 HashEnPassant(const BoardState &state) {
  if (state.en_passant == Square::kNoSquare) return 0ULL;
  const auto ep_square = state.en_passant;

  // If our pawn can capture the en passant
  BitBoard en_passant_bb = BitBoard::FromSquare(ep_square);
  if (state.turn == Color::kWhite) {
    en_passant_bb = Shift<Direction::kSouthEast>(en_passant_bb) |
                    Shift<Direction::kSouthWest>(en_passant_bb);
  } else {
    en_passant_bb = Shift<Direction::kNorthEast>(en_passant_bb) |
                    Shift<Direction::kNorthWest>(en_passant_bb);
  }

  if (en_passant_bb & state.Pawns(state.turn))
    return kRandomsArray[Indices::kEnPassantFileA + File(ep_square)];
  return 0ULL;
}

U64 GenerateKey(const BoardState &state) {
  U64 pieces = 0;
  for (int square = 0; square < Square::kSquareCount; square++)
    if (state.PieceExists(Square(square)))
      pieces ^= HashSquare(Square(square), state);

  return pieces ^ HashCastleRights(state.castle_rights) ^ HashEnPassant(state) ^
         HashTurn(state.turn);
}

}  // namespace zobrist