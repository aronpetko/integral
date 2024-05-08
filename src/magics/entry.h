#ifndef INTEGRAL_MAGICS_ENTRY_H_
#define INTEGRAL_MAGICS_ENTRY_H_

#include "../chess/bitboard.h"

namespace magics {

struct MagicEntry {
  U64 mask;
  U64 magic;
  int shift;
};

}  // namespace magics

#endif  // INTEGRAL_MAGICS_ENTRY_H_