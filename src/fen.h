#ifndef INTEGRAL_FEN_H_
#define INTEGRAL_FEN_H_

#include <sstream>
#include <string>
#include <unordered_map>

#include "types.h"
#include "board.h"

namespace fen {

const std::string kStartFen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

const std::unordered_map<char, PieceType> kCharToPieceType = {
    {'p', PieceType::kPawn},
    {'n', PieceType::kKnight},
    {'b', PieceType::kBishop},
    {'r', PieceType::kRook},
    {'q', PieceType::kQueen},
    {'k', PieceType::kKing},
};

const std::unordered_map<PieceType, char> kPieceTypeToChar = {
    {PieceType::kNone, 'x'},
    {PieceType::kPawn, 'p'},
    {PieceType::kKnight, 'n'},
    {PieceType::kBishop, 'b'},
    {PieceType::kRook, 'r'},
    {PieceType::kQueen, 'q'},
    {PieceType::kKing, 'k'},
};

std::unique_ptr<BoardState> string_to_board(const std::string &fen_str = kStartFen);

std::string board_to_string(const std::shared_ptr<BoardState>& state);

}

#endif // INTEGRAL_FEN_H_