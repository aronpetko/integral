#ifndef INTEGRAL_CONTINUATION_ENTRIES_H
#define INTEGRAL_CONTINUATION_ENTRIES_H

#include <atomic>

#include "../../../../shared/multi_array.h"
#include "../../../utils/types.h"

namespace search::history {

using ContinuationEntry =
    MultiArray<I16, kNumColors, kNumPieceTypes, kSquareCount>;

// Shared between threads, so entries are updated with relaxed atomics
using ContinuationCorrectionEntry =
    MultiArray<std::atomic_int16_t, kNumColors, kNumPieceTypes, kSquareCount>;

}  // namespace search::history

#endif  // INTEGRAL_CONTINUATION_ENTRIES_H