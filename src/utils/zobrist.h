#ifndef INTEGRAL_ZOBRIST_H_
#define INTEGRAL_ZOBRIST_H_

#include "../chess/bitboard.h"
#include "multi_array.h"
#include "random.h"
#include "types.h"

class BoardState;

namespace zobrist {

using PieceTable = MultiArray<U64, 12, Squares::kSquareCount>;
using CastleRightsTable = std::array<U64, 16>;
using EnPassantTable = std::array<U64, 8>;
using FiftyMoveRuleTable = std::array<U64, 12>;

const auto turn = RandomU64();

static PieceTable GeneratePieceTable() {
  PieceTable piece_table;
  for (auto& table : piece_table)
    for (U64& entry : table) entry = RandomU64();
  return piece_table;
}

const auto pieces = GeneratePieceTable();

static CastleRightsTable GenerateCastleRightsTable() {
  CastleRightsTable castle_rights_table;
  for (U64& entry : castle_rights_table) entry = RandomU64();
  return castle_rights_table;
}

const auto castle_rights = GenerateCastleRightsTable();

static EnPassantTable GenerateEnPassantTable() {
  EnPassantTable en_passant_table;
  for (U64& entry : en_passant_table) entry = RandomU64();
  return en_passant_table;
}

const auto en_passant = GenerateEnPassantTable();

static FiftyMoveRuleTable GenerateFiftyMoveRuleTable() {
  FiftyMoveRuleTable fifty_move_rule_table;
  for (U64& entry : fifty_move_rule_table) entry = RandomU64();
  return fifty_move_rule_table;
}

const auto fifty_move_rule = GenerateFiftyMoveRuleTable();

}  // namespace zobrist

#endif  // INTEGRAL_ZOBRIST_H_