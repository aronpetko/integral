#ifndef INTEGRAL__FEN_H_
#define INTEGRAL__FEN_H_

#include <sstream>
#include <string>
#include <map>

#include "types.h"
#include "board.h"

namespace fen {

const std::string kStartFen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

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

BoardState* string_to_board(const std::string &fen_str = kStartFen);

std::string board_to_string(const std::shared_ptr<BoardState>& state);

}

#endif // INTEGRAL__FEN_H_