#ifndef INTEGRAL_PAWN_STRUCTURE_CACHE_H
#define INTEGRAL_PAWN_STRUCTURE_CACHE_H

#include "../../engine/uci/uci.h"
#include "../../utils/hash_table.h"

namespace eval {

struct PawnStructureEntry {
  U64 key{};
  SideTable<ScorePair> score{};
  SideTable<BitBoard> passed_pawns{};
};

inline HashTable<PawnStructureEntry> pawn_cache;

}  // namespace eval

#endif  // INTEGRAL_PAWN_STRUCTURE_CACHE_H