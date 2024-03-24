#include "fen.h"

namespace fen {

char get_piece_char(const std::array<std::array<BitBoard, kNumBitBoards>, 2> &pieces, U8 pos) {
  if (pieces[Color::kWhite][kAllPieces].is_set(pos)) {
    if (pieces[Color::kWhite][kPawns].is_set(pos)) return 'P';
    if (pieces[Color::kWhite][kKnights].is_set(pos)) return 'N';
    if (pieces[Color::kWhite][kBishops].is_set(pos)) return 'B';
    if (pieces[Color::kWhite][kRooks].is_set(pos)) return 'R';
    if (pieces[Color::kWhite][kQueens].is_set(pos)) return 'Q';
    if (pieces[Color::kWhite][kKings].is_set(pos)) return 'K';
  } else if (pieces[Color::kBlack][kAllPieces].is_set(pos)) {
    if (pieces[Color::kBlack][kPawns].is_set(pos)) return 'p';
    if (pieces[Color::kBlack][kKnights].is_set(pos)) return 'n';
    if (pieces[Color::kBlack][kBishops].is_set(pos)) return 'b';
    if (pieces[Color::kBlack][kRooks].is_set(pos)) return 'r';
    if (pieces[Color::kBlack][kQueens].is_set(pos)) return 'q';
    if (pieces[Color::kBlack][kKings].is_set(pos)) return 'k';
  }
  return ' ';
}

BoardState string_to_board(std::string fen_str) {
  BoardState state;
  auto &pieces = state.pieces;

  std::istringstream stream(fen_str);
  
  std::string position;
  stream >> position;

  // from 63 to 0, starting from a8 to h1
  U8 square = Square::kA8;
  for (const char &ch : position) {
    if (ch == '/') {
      square = square - 16 + (square % kBoardFiles);
      continue;
    }
    
    if (std::isdigit(ch)) {
      square += ch - '0';
      continue;
    }
    
    const Color piece_color = std::islower(ch) ? Color::kBlack : Color::kWhite;
    const auto piece_type = kCharToPieceType.at(std::tolower(ch));

    pieces[piece_color][piece_type].set_bit(square);
    state.piece_types[square] = piece_type;

    square++;
  }

  pieces[Color::kWhite][kAllPieces] = pieces[Color::kWhite][kPawns] | pieces[Color::kWhite][kKnights] | pieces[Color::kWhite][kBishops] | pieces[Color::kWhite][kRooks] | pieces[Color::kWhite][kQueens] | pieces[Color::kWhite][kKings];
  pieces[Color::kBlack][kAllPieces] = pieces[Color::kBlack][kPawns] | pieces[Color::kBlack][kKnights] | pieces[Color::kBlack][kBishops] | pieces[Color::kBlack][kRooks] | pieces[Color::kBlack][kQueens] | pieces[Color::kBlack][kKings];

  char turn;
  stream >> turn;
  state.turn = (turn == 'w' ? Color::kWhite : Color::kBlack);

  std::string castle_rights;
  stream >> castle_rights;
  for (const char &ch : castle_rights) {
    if (ch == 'K')
      state.castle.set_can_kingside_castle(Color::kWhite, true);
    else if (ch == 'Q')
      state.castle.set_can_queenside_castle(Color::kWhite, true);
    else if (ch == 'k')
      state.castle.set_can_kingside_castle(Color::kBlack, true);
    else if (ch == 'q')
      state.castle.set_can_queenside_castle(Color::kBlack, true);
  }

  std::string en_passant;
  stream >> en_passant;

  if (en_passant != "-") {
    state.en_passant = Square(rank_file_to_pos(en_passant[1] - '1', en_passant[0] - 'a'));
  }

  stream >> state.fifty_moves_clock;
  stream >> state.half_moves;

  // adjust the full moves to half moves
  state.half_moves /= 2;
  if (state.turn == Color::kWhite)
    state.half_moves++;

  state.zobrist_key = zobrist::generate_key(state);

  return state;
}

std::string board_to_string(BoardState& state) {
  std::string output;

  // fen notation starts with black pieces, so we begin at the 8th rank (0-indexed)
  for (int rank = 7; rank >= 0; rank--) {
    int empty = 0;

    for (int file = 0; file < 8; file++) {
      U8 square = rank_file_to_pos(rank, file);

      if (state.occupied().is_set(square))
        output.push_back(get_piece_char(state.pieces, square));
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
  if (state.castle.can_kingside_castle(Color::kWhite))
    output.push_back('K');
  if (state.castle.can_queenside_castle(Color::kWhite))
    output.push_back('Q');
  if (state.castle.can_kingside_castle(Color::kBlack))
    output.push_back('k');
  if (state.castle.can_queenside_castle(Color::kBlack))
    output.push_back('q');

  // todo: implement en-passant state
  output.push_back(' ');
  output.push_back('-');

  // half and full moves
  output.push_back(' ');
  output.append(std::to_string(state.fifty_moves_clock));
  output.push_back(' ');

  const U32 full_moves = state.half_moves / 2;
  output.append(std::to_string(full_moves));

  return output;
}

}