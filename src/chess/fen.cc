#include "fen.h"

#include "../engine/uci/uci.h"

namespace fen {

// clang-format off
constexpr std::array<std::array<char, kNumPieceTypes + 1>, 2> kPieceToChar = {{
  {'p', 'n', 'b', 'r', 'q', 'k', 'x'},
  {'P', 'N', 'B', 'R', 'Q', 'K', 'x'}
}};
// clang-format on

char GetPieceChar(const BoardState &state, Square square) {
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

  if (state.turn == Color::kBlack) {
    state.zobrist_key ^= zobrist::turn;
  }

  std::string castle_rights;
  stream >> castle_rights;
  state.castle_rights.GetUnderlying().fill(kNoSquare);
  for (const char &ch : castle_rights) {
    // Standard FENs, XFEN later
    if (ch == 'K')
      state.castle_rights.SetCanKingsideCastle(Color::kWhite, Square(kH1));
    else if (ch == 'Q')
      state.castle_rights.SetCanQueensideCastle(Color::kWhite, Square(kA1));
    else if (ch == 'k')
      state.castle_rights.SetCanKingsideCastle(Color::kBlack, Square(kH8));
    else if (ch == 'q')
      state.castle_rights.SetCanQueensideCastle(Color::kBlack, Square(kA8));

    // FRC FEN
    if (std::tolower(ch) >= 'a' &&
        std::tolower(ch) <= 'h') {
      uci::listener.GetOption("UCI_Chess960").SetValue("true");
      const File file = static_cast<File>(std::tolower(ch) - 'a');
      const Square kingSq = state.King(std::islower(ch) ? Color::kBlack : Color::kWhite).GetLsb();

      if (std::isupper(ch))
        state.castle_rights.SetCastlingRights(Color::kWhite, file > kingSq.File() ? CastleRights::kKingside : CastleRights::kQueenside, Square::FromRankFile(kRank1, file));
      else
        state.castle_rights.SetCastlingRights(Color::kBlack, file > kingSq.File() ? CastleRights::kKingside : CastleRights::kQueenside, Square::FromRankFile(kRank8, file));
    }
  }

  state.zobrist_key ^= zobrist::castle_rights[state.castle_rights.AsU8()];

  std::string en_passant;
  stream >> en_passant;

  if (en_passant != "-") {
    state.en_passant =
        Square(Square::FromRankFile(en_passant[1] - '1', en_passant[0] - 'a'));
    state.zobrist_key ^= zobrist::en_passant[state.en_passant.File()];
  }

  stream >> state.fifty_moves_clock;

  int full_move_count = 0;
  stream >> full_move_count;

  state.half_moves = (full_move_count - 1) * 2 + state.turn;

  return state;
}

std::string BoardToString(const BoardState &state) {
  std::string output;

  // Fen notation starts with the 8th rank (0-indexed)
  for (int rank = 7; rank >= 0; rank--) {
    int empty = 0;

    for (int file = 0; file < 8; file++) {
      const auto square = Square::FromRankFile(rank, file);
      if (state.Occupied().IsSet(square)) {
        if (empty > 0) {
          output.append(std::to_string(empty));
          empty = 0;
        }
        output.push_back(GetPieceChar(state, square));
      } else {
        empty++;
      }
    }

    if (empty > 0) {
      output.append(std::to_string(empty));
    }

    if (rank > 0) {
      output.push_back('/');
    }
  }

  // Move turn
  output.push_back(' ');
  output.push_back(state.turn == Color::kWhite ? 'w' : 'b');

  // Castling rights
  output.push_back(' ');
  std::string castling_rights;
  if (state.castle_rights.CanKingsideCastle(Color::kWhite))
    castling_rights += 'K';
  if (state.castle_rights.CanQueensideCastle(Color::kWhite))
    castling_rights += 'Q';
  if (state.castle_rights.CanKingsideCastle(Color::kBlack))
    castling_rights += 'k';
  if (state.castle_rights.CanQueensideCastle(Color::kBlack))
    castling_rights += 'q';
  output.append(castling_rights.empty() ? "-" : castling_rights);

  // En passant square
  output.push_back(' ');
  if (state.en_passant != Squares::kNoSquare) {
    output += static_cast<char>('a' + state.en_passant.File());
    output += static_cast<char>('1' + state.en_passant.Rank());
  } else {
    output.push_back('-');
  }

  // Half-move clock and full move number
  output.push_back(' ');
  output.append(std::to_string(state.fifty_moves_clock));
  output.push_back(' ');
  output.append(std::to_string((state.half_moves + 1) / 2));

  return output;
}

}  // namespace fen