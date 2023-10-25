module;

#include <iostream>
#include <string>
#include <map>

export module fen;

import board;
import bitboard;
import types;

namespace fen {

export const std::string kStartFen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

const std::map<char, PieceType> kCharToPieceType = {
    {'p', PieceType::kPawn},
    {'n', PieceType::kKnight},
    {'b', PieceType::kBishop},
    {'r', PieceType::kRook},
    {'q', PieceType::kQueen},
    {'k', PieceType::kKing},
};

const std::map<PieceType, char> kPieceTypeToChar = {
    {PieceType::kNone, 'x'},
    {PieceType::kPawn, 'p'},
    {PieceType::kKnight, 'n'},
    {PieceType::kBishop, 'b'},
    {PieceType::kRook, 'r'},
    {PieceType::kQueen, 'q'},
    {PieceType::kKing, 'k'},
};

export void print(BitBoard board) {
  for (int rank = 0; rank < 8; rank++) {
    for (int file = 0; file < 8; file++) {
      U32 square = (rank * 8 + file);
      std::cout << (board.is_set(square) ? '1' : '0');
      if (file < 7) std::cout << " ";  // space separator for clarity
    }
    std::cout << std::endl;
  }
}

export BoardState string_to_board(const std::string &fen_str = kStartFen) {
  BoardState state;
  BitBoards &boards = state.boards;

  // from 63 to 0, starting from a8 to h1
  U32 square = 63;

  for (const char &ch : fen_str) {
    if (ch == ' ') break;
    if (ch == '/') continue;

    if (std::isdigit(ch)) {
      square += ch - '0';
      continue;
    }

    BitBoard *target = nullptr;

    PieceType type = kCharToPieceType.at(std::tolower(ch));
    switch (type) {
      case PieceType::kPawn:
        target = std::islower(ch) ? &boards.black_pawns : &boards.white_pawns;
        break;
      case PieceType::kKnight:
        target = std::islower(ch) ? &boards.black_knights : &boards.white_knights;
        break;
      case PieceType::kBishop:
        target = std::islower(ch) ? &boards.black_bishops : &boards.white_bishops;
        break;
      case PieceType::kRook:
        target = std::islower(ch) ? &boards.black_rooks : &boards.white_rooks;
        break;
      case PieceType::kQueen:
        target = std::islower(ch) ? &boards.black_queens : &boards.white_queens;
        break;
      case PieceType::kKing:
        target = std::islower(ch) ? &boards.black_king : &boards.white_king;
        break;
    }

    if (target)
      target->set_bit(63 - square); // we populate from the most significant bit, since fen starts with black pieces

    square--;
  }

  boards.white_pieces = boards.white_pawns | boards.white_knights | boards.white_bishops | boards.white_rooks | boards.white_queens | boards.white_king;
  boards.black_pieces = boards.black_pawns | boards.black_knights | boards.black_bishops | boards.black_rooks | boards.black_queens | boards.black_king;
  boards.all_pieces   = boards.white_pieces | boards.black_pieces;

  std::cout << "White: \n";
  print(boards.white_pieces);
  std::cout << "Black: \n";
  print(boards.black_pieces);
  std::cout << "All: \n";
  print(boards.all_pieces);

  return state;
}

export std::string board_to_string(BoardState state) {
  std::string output;

  for (int rank = 7; rank >= 0; rank--) {
    int empty = 0;

    for (int file = 0; file < 8; file++) {
      U32 square = 63 - (rank * 8 + file);

      if (state.boards.all_pieces.is_set(square))
        output.push_back(state.boards.get_piece_char(square));
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
  output.push_back(state.turn_to_move == Color::kWhite ? 'w' : 'b');

  // castling rights
  output.push_back(' ');
  if (state.castle_state & CastleBits::kWhiteKingside)
    output.push_back('K');
  if (state.castle_state & CastleBits::kWhiteQueenside)
    output.push_back('Q');
  if (state.castle_state & CastleBits::kBlackKingside)
    output.push_back('k');
  if (state.castle_state & CastleBits::kBlackQueenside)
    output.push_back('q');

  // todo: implement en-passant state
  output.push_back(' ');
  output.push_back('-');

  // half and full moves
  output.push_back(' ');
  output.append(std::to_string(state.half_moves));
  output.push_back(' ');
  output.append(std::to_string(state.full_moves));

  return output;
}

}