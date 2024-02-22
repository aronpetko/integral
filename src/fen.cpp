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

std::unique_ptr<BoardState> string_to_board(const std::string &fen_str) {
  auto state = std::make_unique<BoardState>();
  BitBoards &pieces = state->pieces;

  std::istringstream stream(fen_str);
  std::string position;
  stream >> position;

  // from 63 to 0, starting from a8 to h1
  U8 square = 56;

  for (const char &ch : position) {
    if (ch == '/') {
      square = square - 16 + (square % 8);
      continue;
    }
    if (std::isdigit(ch)) {
      square += ch - '0';
      continue;
    }

    BitBoard *target = nullptr;

    PieceType type = kCharToPieceType.at(static_cast<char>(std::tolower(ch)));
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
      U8 square = rank_file_to_pos(rank, file);

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