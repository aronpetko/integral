#include "fen.h"

namespace fen {

// the bit boards will get populated when fen is parsed
char get_piece_char(BitBoards &pieces, U8 pos) {
  if (pieces[kWhitePieces].is_set(pos)) {
    if (pieces[kWhitePawns].is_set(pos)) return 'P';
    if (pieces[kWhiteKnights].is_set(pos)) return 'N';
    if (pieces[kWhiteBishops].is_set(pos)) return 'B';
    if (pieces[kWhiteRooks].is_set(pos)) return 'R';
    if (pieces[kWhiteQueens].is_set(pos)) return 'Q';
    if (pieces[kWhiteKing].is_set(pos)) return 'K';
  } else if (pieces[kBlackPieces].is_set(pos)) {
    if (pieces[kBlackPawns].is_set(pos)) return 'p';
    if (pieces[kBlackKnights].is_set(pos)) return 'n';
    if (pieces[kBlackBishops].is_set(pos)) return 'b';
    if (pieces[kBlackRooks].is_set(pos)) return 'r';
    if (pieces[kBlackQueens].is_set(pos)) return 'q';
    if (pieces[kBlackKing].is_set(pos)) return 'k';
  }
  return ' ';
}

BoardState string_to_board(const std::string &fen_str) {
  BoardState state;
  auto &pieces = state.pieces;

  std::istringstream stream(fen_str);
  
  std::string position;
  stream >> position;

  // from 63 to 0, starting from a8 to h1
  U8 square = 56;

  for (const char &ch : position) {
    if (ch == '/') {
      square = square - 16 + (square % kBoardFiles);
      continue;
    }
    
    if (std::isdigit(ch)) {
      square += ch - '0';
      continue;
    }

    BitBoard *target = nullptr;

    const bool is_black_piece = std::islower(ch);
    const auto piece_type = kCharToPieceType.at(std::tolower(ch));

    switch (piece_type) {
      case PieceType::kPawn:
        target = is_black_piece ? &pieces[kBlackPawns] : &pieces[kWhitePawns];
        break;
      case PieceType::kKnight:
        target = is_black_piece ? &pieces[kBlackKnights] : &pieces[kWhiteKnights];
        break;
      case PieceType::kBishop:
        target = is_black_piece ? &pieces[kBlackBishops] : &pieces[kWhiteBishops];
        break;
      case PieceType::kRook:
        target = is_black_piece ? &pieces[kBlackRooks] : &pieces[kWhiteRooks];
        break;
      case PieceType::kQueen:
        target = is_black_piece ? &pieces[kBlackQueens] : &pieces[kWhiteQueens];
        break;
      case PieceType::kKing:
        target = is_black_piece ? &pieces[kBlackKing] : &pieces[kWhiteKing];
        break;
      case PieceType::kNone:
        break;
    }

    if (target)
      target->set_bit(square);

    square++;
  }

  pieces[kWhitePieces] = pieces[kWhitePawns] | pieces[kWhiteKnights] | pieces[kWhiteBishops] | pieces[kWhiteRooks] | pieces[kWhiteQueens] | pieces[kWhiteKing];
  pieces[kBlackPieces] = pieces[kBlackPawns] | pieces[kBlackKnights] | pieces[kBlackBishops] | pieces[kBlackRooks] | pieces[kBlackQueens] | pieces[kBlackKing];
  pieces[kAllPieces] = pieces[kWhitePieces] | pieces[kBlackPieces];

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

  // todo: implement this
  char en_passant;
  stream >> en_passant;

  stream >> state.fifty_moves_clock;
  stream >> state.half_moves;

  // adjust the full moves to half moves
  state.half_moves *= 2;
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

      if (state.pieces[kAllPieces].is_set(square))
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

  const int full_moves = state.half_moves / 2;
  output.append(std::to_string(full_moves));

  return output;
}

}