#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE(kLmrQuietBase, 0.812, 0.5, 1.2, false);
TUNABLE(kLmrQuietDiv, 2.08, 1.5, 3.0, false);
TUNABLE(kLmrTactBase, -0.247, -0.5, 0.2, false);
TUNABLE(kLmrTactDiv, 2.63, 2.0, 3.5, false);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE(kAspWindowDelta, 8, 5, 20, false);
TUNABLE(kAspWindowGrowth, 1.44, 0.1, 2.0, false);

TUNABLE(kQsFutMargin, 109, 50, 200, false);

TUNABLE(kEvalHistUpdateMult, 64, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 66, 5, 150, false);
TUNABLE(kEvalHistUpdateMax, 104, 40, 200, false);

TUNABLE(kRevFutDepth, 6, 4, 10, true);
TUNABLE(kRevFutMargin, 63, 50, 150, false);
TUNABLE(kRevFutHistoryDiv, 565, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE(kRazoringMult, 439, 200, 700, false);

TUNABLE(kNullMoveBetaBase, 147, 50, 250, false);
TUNABLE(kNullMoveBetaMult, 25, 5, 30, false);
TUNABLE(kNullMoveRb, 4, 1, 5, true);
TUNABLE(kNullMoveRf, 4, 2, 8, true);
TUNABLE(kNullMoveRe, 187, 100, 400, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE(kLmpBase, 5.0, 1.5, 5.0, false);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE(kFutMarginBase, 199, 100, 250, false);
TUNABLE(kFutMarginMult, 90, 50, 200, false);
TUNABLE(kFutMarginHistDiv, 150, 32, 256, false);

TUNABLE(kSeePruneDepth, 8, 6, 12, true);
TUNABLE(kSeeQuietThresh, -62, -100, -20, false);
TUNABLE(kSeeNoisyThresh, -117, -200, -50, false);
TUNABLE(kSeeNoisyHistDiv, 153, 32, 256, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -490, -1000, 500, false);
TUNABLE(kHistThreshMult, -1925, -3000, -250, false);
TUNABLE(kCaptHistThreshBase, -454, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1775, -3000, -250, false);

TUNABLE(kLmrHistDiv, 11265, 5000, 20000, false);
TUNABLE(kLmrCaptHistDiv, 11275, 5000, 20000, false);
TUNABLE(kLmrComplexityDiff, 82, 5, 150, false);

TUNABLE(kDoDeeperBase, 36, 5, 70, false);
TUNABLE(kDoShallowerBase, 6, 0, 30, false);

TUNABLE(kSeDepth, 6, 6, 12, true);
TUNABLE(kSeDoubleMargin, 13, 0, 30, false);
TUNABLE(kSeTripleMargin, 105, 30, 250, false);
TUNABLE(kSeDepthExtensionDepth, 10, 0, 15, false);

TUNABLE(kProbcutBetaDelta, 245, 100, 400, false);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H