#include "fen.h"

namespace fen {

std::shared_ptr<BoardState> string_to_board(const std::string &fen_str) {
  auto state = std::make_shared<BoardState>();
  BitBoards &pieces = state->pieces;

  std::istringstream stream(fen_str);
  std::string position;
  stream >> position;

  // from 63 to 0, starting from a8 to h1
  U8 square = 63;

  for (const char &ch : position) {
    if (ch == '/') continue;

    if (std::isdigit(ch)) {
      square += ch - '0';
      continue;
    }

    BitBoard *target = nullptr;

    PieceType type = kCharToPieceType.at(std::tolower(ch));
    switch (type) {
      case PieceType::kPawn:
        target = std::islower(ch) ? &pieces[kBlackPawns] : &pieces[kWhitePawns];
        break;
      case PieceType::kKnight:
        target = std::islower(ch) ? &pieces[kBlackKnights] : &pieces[kWhiteKnights];
        break;
      case PieceType::kBishop:
        target = std::islower(ch) ? &pieces[kBlackBishops] : &pieces[kWhiteBishops];
        break;
      case PieceType::kRook:
        target = std::islower(ch) ? &pieces[kBlackRooks] : &pieces[kWhiteRooks];
        break;
      case PieceType::kQueen:
        target = std::islower(ch) ? &pieces[kBlackQueens] : &pieces[kWhiteQueens];
        break;
      case PieceType::kKing:
        target = std::islower(ch) ? &pieces[kBlackKing] : &pieces[kWhiteKing];
        break;
    }

    if (target)
      target->set_bit(square);

    square--;
  }

  pieces[kWhitePieces] = pieces[kWhitePawns] | pieces[kWhiteKnights] | pieces[kWhiteBishops] | pieces[kWhiteRooks] | pieces[kWhiteQueens] | pieces[kWhiteKing];
  pieces[kBlackPieces] = pieces[kBlackPawns] | pieces[kBlackKnights] | pieces[kBlackBishops] | pieces[kBlackRooks] | pieces[kBlackQueens] | pieces[kBlackKing];
  pieces[kAllPieces] = pieces[kWhitePieces] | pieces[kBlackPieces];

  char turn_to_move;
  stream >> turn_to_move;
  state->turn_to_move = (turn_to_move == 'w' ? Color::kWhite : Color::kBlack);

  std::string castle_rights;
  stream >> castle_rights;
  for (const char &ch : castle_rights) {
    if (ch == 'K')
      state->castle_state |= CastleBits::kWhiteKingside;
    else if (ch == 'Q')
      state->castle_state |= CastleBits::kWhiteQueenside;
    else if (ch == 'k')
      state->castle_state |= CastleBits::kBlackKingside;
    else if (ch == 'q')
      state->castle_state |= CastleBits::kBlackQueenside;
  }

  // todo: implement this
  char en_passant;
  stream >> en_passant;

  stream >> state->half_moves;
  stream >> state->full_moves;

  return state;
}

std::string board_to_string(const std::shared_ptr<BoardState>& state) {
  std::string output;

  // fen notation starts with black pieces, so we begin at the 8th rank (0-indexed)
  for (int rank = 7; rank >= 0; rank--) {
    int empty = 0;

    for (int file = 0; file < 8; file++) {
      U8 square = (rank * 8 + file);

      if (state->pieces[kAllPieces].is_set(square))
        output.push_back(get_piece_char(state->pieces, square));
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
  output.push_back(state->turn_to_move == Color::kWhite ? 'w' : 'b');

  // castling rights
  output.push_back(' ');
  if (state->castle_state & CastleBits::kWhiteKingside)
    output.push_back('K');
  if (state->castle_state & CastleBits::kWhiteQueenside)
    output.push_back('Q');
  if (state->castle_state & CastleBits::kBlackKingside)
    output.push_back('k');
  if (state->castle_state & CastleBits::kBlackQueenside)
    output.push_back('q');

  // todo: implement en-passant state
  output.push_back(' ');
  output.push_back('-');

  // half and full moves
  output.push_back(' ');
  output.append(std::to_string(state->half_moves));
  output.push_back(' ');
  output.append(std::to_string(state->full_moves));

  return output;
}

}