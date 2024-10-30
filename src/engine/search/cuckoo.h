#ifndef INTEGRAL_CUCKOO_H
#define INTEGRAL_CUCKOO_H

#include "../../chess/move_gen.h"
#include "../../utils/types.h"
#include "../../utils/zobrist.h"

namespace search::cuckoo {

inline std::array<U64, 8192> keys;
inline std::array<Move, 8192> moves;

constexpr U64 H1(U64 key) {
  return static_cast<U64>(key & 0x1FFF);
}

constexpr U64 H2(U64 key) {
  return static_cast<U64>((key >> 16) & 0x1FFF);
}

void Initialize();

}  // namespace search::cuckoo

#endif  // INTEGRAL_CUCKOO_H