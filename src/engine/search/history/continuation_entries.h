#ifndef INTEGRAL_CONTINUATION_ENTRIES_H
#define INTEGRAL_CONTINUATION_ENTRIES_H

#include "../../../../shared/multi_array.h"
#include "../../../utils/types.h"

namespace search::history {

using ContinuationEntry =
    MultiArray<I16, kNumColors, kNumPieceTypes, kSquareCount>;

using ContinuationCorrectionEntry =
    MultiArray<Score, kNumColors, kNumPieceTypes, kSquareCount>;

}

#endif  // INTEGRAL_CONTINUATION_ENTRIES_H