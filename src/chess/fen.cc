#include "fen.h"

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
  state.castle_rights.Clear();

  for (const char &ch : castle_rights) {
    const Color color = std::isupper(ch) ? Color::kWhite : Color::kBlack;
    const Rank rank = color == Color::kWhite ? kRank1 : kRank8;
    const char side = std::tolower(ch);

    const BitBoard rooks = state.Rooks(color) & kRankMasks[rank];
    if (!rooks) {
      continue;
    }

    Square rook_square;
    if (side == 'k' || side == 'q') {
      // The castling rook is the outermost one on the given side
      rook_square = side == 'k' ? rooks.GetMsb() : rooks.GetLsb();
    } else if (side >= 'a' && side <= 'h') {
      // Shredder FENs name the castling rook's file directly
      chess960 = true;
      rook_square = Square::FromRankFile(rank, side - 'a');
    } else {
      continue;
    }

    state.castle_rights.SetCastleSquare(
        color,
        rook_square > state.King(color).GetLsb() ? CastleRights::kKingside
                                                 : CastleRights::kQueenside,
        rook_square);
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

  // Castling rights, written as Shredder FEN when playing Chess960
  output.push_back(' ');
  std::string castling_rights;
  for (const Color color : {Color::kWhite, Color::kBlack}) {
    for (const auto side : {CastleRights::kKingside, CastleRights::kQueenside}) {
      const Square rook_square = state.castle_rights.CastleSquare(color, side);
      if (rook_square == Squares::kNoSquare) {
        continue;
      }

      const char ch = chess960 ? 'a' + rook_square.File()
                               : (side == CastleRights::kKingside ? 'k' : 'q');
      castling_rights +=
          color == Color::kWhite ? std::toupper(ch) : ch;
    }
  }
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