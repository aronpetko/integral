#include "zobrist.h"
#include "board.h"

namespace zobrist {

// declare these here so they don't appear globally
enum Indices : int {
  kPieceStart = 0,
  kPieceEnd = 767,

  kWhiteKingside = 768,
  kWhiteQueenside = 769,
  kBlackKingside = 770,
  kBlackQueenside = 771,

  kEnPassantFileA = 772,
  kEnPassantFileH = 779,

  kTurn = 780,
};

U64 generate_key(const std::unique_ptr<BoardState> &state) {
  U64 turn = 0;
  if (state->turn == Color::kWhite)
    turn ^= kRandomsArray[Indices::kTurn];

  U64 pieces = 0;
  for (int square = 0; square < Square::kSquareCount; square++) {
    const std::optional<Color> color = get_piece_color(square, state->pieces);
    if (!color.has_value())
      continue;

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
    const int rank = square / 8;
    const int file = square % kBoardFiles;

    const int piece_kind = (static_cast<int>(get_piece_type(square, state->pieces)) - 1) * 2 + color.value();
    const int piece_idx = Square::kSquareCount * piece_kind + kBoardRanks * rank + file;

    pieces ^= kRandomsArray[piece_idx];
  }

  U64 castle = 0;
  if (state->castle.can_kingside_castle(Color::kWhite)) castle ^= kRandomsArray[Indices::kWhiteKingside];
  if (state->castle.can_queenside_castle(Color::kWhite)) castle ^= kRandomsArray[Indices::kWhiteQueenside];
  if (state->castle.can_kingside_castle(Color::kBlack)) castle ^= kRandomsArray[Indices::kBlackKingside];
  if (state->castle.can_queenside_castle(Color::kBlack)) castle ^= kRandomsArray[Indices::kBlackQueenside];

  U64 en_passant = 0;
  if (state->en_passant.has_value()) {
    const Square ep_square = state->en_passant.value();

    // if our pawn can capture the en passant
    const BitBoard &our_pawns = state->pieces[state->turn == kWhite ? kWhitePawns : kBlackPawns];

    BitBoard en_passant_bb = BitBoard::from_square(ep_square);
    en_passant_bb = state->turn == Color::kWhite ? shift<Direction::kSouth>(en_passant_bb) : shift<Direction::kNorth>(en_passant_bb);
    en_passant_bb = shift<Direction::kEast>(en_passant_bb) | shift<Direction::kWest>(en_passant_bb);

    if (en_passant_bb & our_pawns) {
      const int en_passant_file = ep_square % 8;
      en_passant ^= kRandomsArray[Indices::kEnPassantFileA + en_passant_file];
    }
  }

  return pieces ^ castle ^ en_passant ^ turn;
}

}