#ifndef INTEGRAL_FEN_H_
#define INTEGRAL_FEN_H_

#include <sstream>
#include <string>
#include <unordered_map>

#include "../utils/types.h"
#include "board.h"

namespace fen {

const std::string kStartFen =
    "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

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

char GetPieceChar(BoardState &state, Square square);

BoardState StringToBoard(std::string_view fen_str = kStartFen);

std::string BoardToString(BoardState &state);

}  // namespace fen

#endif  // INTEGRAL_FEN_H_