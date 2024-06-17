#include "fen.h"

namespace fen {

// clang-format off
constexpr std::array<std::array<char, kNumPieceTypes + 1>, 2> kPieceToChar = {{
  {'p', 'n', 'b', 'r', 'q', 'k', 'x'},
  {'P', 'N', 'B', 'R', 'Q', 'K', 'x'}
}};
// clang-format on

char GetPieceChar(BoardState &state, Square square) {
  if (!state.Occupied().IsSet(square)) {
    return ' ';
  }
  return kPieceToChar[state.GetPieceColor(square)][state.GetPieceType(square)];
}

BoardState StringToBoard(std::string_view fen_str) {
  BoardState state;

  std::istringstream stream((std::string(fen_str)));

  std::string position;
  stream >> position;

  // From 63 to 0, starting from a8 to h1
  int square = Squares::kA8;
  for (const char &ch : position) {
    if (ch == '/') {
      square = square - 16 + (square % kNumFiles);
      continue;
    }

    if (std::isdigit(ch)) {
      square += ch - '0';
      continue;
    }

    const auto piece_color = std::islower(ch) ? Color::kBlack : Color::kWhite;
    const auto piece_type = kCharToPieceType.at(std::tolower(ch));
    state.PlacePiece(square, piece_type, piece_color);

    square++;
  }

  char turn;
  stream >> turn;
  state.turn = (turn == 'w' ? Color::kWhite : Color::kBlack);

  std::string castle_rights;
  stream >> castle_rights;
  for (const char &ch : castle_rights) {
    if (ch == 'K')
      state.castle_rights.SetCanKingsideCastle(Color::kWhite, true);
    else if (ch == 'Q')
      state.castle_rights.SetCanQueensideCastle(Color::kWhite, true);
    else if (ch == 'k')
      state.castle_rights.SetCanKingsideCastle(Color::kBlack, true);
    else if (ch == 'q')
      state.castle_rights.SetCanQueensideCastle(Color::kBlack, true);
  }

  std::string en_passant;
  stream >> en_passant;

  if (en_passant != "-") {
    state.en_passant =
        Square(RankFileToSquare(en_passant[1] - '1', en_passant[0] - 'a'));
  }

  stream >> state.fifty_moves_clock;

  return state;
}

std::string BoardToString(BoardState &state) {
  std::string output;

  // Fen notation starts with black pieces, so we begin at the 8th rank
  // (0-indexed)
  for (int rank = 7; rank >= 0; rank--) {
    int empty = 0;

    for (int file = 0; file < 8; file++) {
      const auto square = RankFileToSquare(rank, file);
      if (state.Occupied().IsSet(square))
        output.push_back(GetPieceChar(state, square));
      else
        empty++;
    }

    if (empty) output.append(std::to_string(empty));

    if (rank) output.push_back('/');
  }

  // Move turn
  output.push_back(' ');
  output.push_back(state.turn == Color::kWhite ? 'w' : 'b');

  // Castling rights
  output.push_back(' ');
  if (state.castle_rights.CanKingsideCastle(Color::kWhite))
    output.push_back('K');
  if (state.castle_rights.CanQueensideCastle(Color::kWhite))
    output.push_back('Q');
  if (state.castle_rights.CanKingsideCastle(Color::kBlack))
    output.push_back('k');
  if (state.castle_rights.CanQueensideCastle(Color::kBlack))
    output.push_back('q');

  // TODO: implement en-passant state
  output.push_back(' ');
  output.push_back('-');

  // Half and full moves
  output.push_back(' ');
  output.append(std::to_string(state.fifty_moves_clock));
  output.push_back(' ');

  return output;
}

}  // namespace fen