#ifndef INTEGRAL_MAGICS_MAGIC_FINDER_H_
#define INTEGRAL_MAGICS_MAGIC_FINDER_H_

#include "entry.h"

namespace magics::finder {

MagicEntry find_magic(PieceType piece_type, Square square);

void generate_magics();

}

#endif // INTEGRAL_MAGICS_MAGIC_FINDER_H_