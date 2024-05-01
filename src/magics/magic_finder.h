#ifndef INTEGRAL_MAGICS_MAGIC_FINDER_H_
#define INTEGRAL_MAGICS_MAGIC_FINDER_H_

#include "entry.h"

namespace magics::finder {

MagicEntry FindMagic(PieceType piece_type, Square square);

void GenerateMagics();

}  // namespace magics::finder

#endif  // INTEGRAL_MAGICS_MAGIC_FINDER_H_