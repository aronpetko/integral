#ifndef INTEGRAL_FEN_H_
#define INTEGRAL_FEN_H_

#include <sstream>
#include <string>
#include <unordered_map>

#include "../utils/types.h"
#include "board.h"

namespace fen {

constexpr std::string_view kStartFen =
    "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
constexpr std::string_view kKiwipeteFen =
    "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - ";

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

char GetPieceChar(const BoardState &state, Square square);

BoardState StringToBoard(std::string_view fen_str = kStartFen);

std::string BoardToString(const BoardState &state);

}  // namespace fen

#endif  // INTEGRAL_FEN_H_