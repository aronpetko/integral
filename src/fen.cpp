#include "fen.h"

namespace fen {

constexpr std::array<std::array<char, PieceType::kNumTypes>, 2> piece_to_char = {{
  {'p', 'n', 'b', 'r', 'q', 'k'},
  {'P', 'N', 'B', 'R', 'Q', 'K'}
}};

char get_piece_char(BoardState &state, Square square) {
  if (!state.occupied().is_set(square)) {
    return ' ';
  }

  return piece_to_char[state.get_piece_color(square)][state.get_piece_type(square)];
}

BoardState string_to_board(std::string fen_str) {
  BoardState state;
  auto &pieces = state.piece_bbs;

  std::istringstream stream(fen_str);
  
  std::string position;
  stream >> position;

  // from 63 to 0, starting from a8 to h1
  int square = Square::kA8;
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
    state.place_piece(square, piece_type, piece_color);

    square++;
  }

  char turn;
  stream >> turn;
  state.turn = (turn == 'w' ? Color::kWhite : Color::kBlack);

  std::string castle_rights;
  stream >> castle_rights;
  for (const char &ch : castle_rights) {
    if (ch == 'K')
      state.castle_rights.set_can_kingside_castle(Color::kWhite, true);
    else if (ch == 'Q')
      state.castle_rights.set_can_queenside_castle(Color::kWhite, true);
    else if (ch == 'k')
      state.castle_rights.set_can_kingside_castle(Color::kBlack, true);
    else if (ch == 'q')
      state.castle_rights.set_can_queenside_castle(Color::kBlack, true);
  }

  std::string en_passant;
  stream >> en_passant;

  if (en_passant != "-") {
    state.en_passant = Square(rank_file_to_square(en_passant[1] - '1', en_passant[0] - 'a'));
  }

  stream >> state.fifty_moves_clock;

  state.zobrist_key = zobrist::generate_key(state);

  return state;
}

std::string board_to_string(BoardState& state) {
  std::string output;

  // fen notation starts with black pieces, so we begin at the 8th rank (0-indexed)
  for (int rank = 7; rank >= 0; rank--) {
    int empty = 0;

    for (int file = 0; file < 8; file++) {
      const auto square = rank_file_to_square(rank, file);
      if (state.occupied().is_set(square))
        output.push_back(get_piece_char(state, square));
      else
        empty++;
    }

    if (empty)
      output.append(std::to_string(empty));

    if (rank)
      output.push_back('/');
  }

  // move turn
  output.push_back(' ');
  output.push_back(state.turn == Color::kWhite ? 'w' : 'b');

  // castling rights
  output.push_back(' ');
  if (state.castle_rights.can_kingside_castle(Color::kWhite))
    output.push_back('K');
  if (state.castle_rights.can_queenside_castle(Color::kWhite))
    output.push_back('Q');
  if (state.castle_rights.can_kingside_castle(Color::kBlack))
    output.push_back('k');
  if (state.castle_rights.can_queenside_castle(Color::kBlack))
    output.push_back('q');

  // todo: implement en-passant state
  output.push_back(' ');
  output.push_back('-');

  // half and full moves
  output.push_back(' ');
  output.append(std::to_string(state.fifty_moves_clock));
  output.push_back(' ');

  return output;
}

}