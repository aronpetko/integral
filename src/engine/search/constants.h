#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE(kLmrQuietBase, 0.80, 0.5, 1.2, false);
TUNABLE(kLmrQuietDiv, 2.04, 1.5, 3.0, false);
TUNABLE(kLmrTactBase, -0.24, -0.5, 0.2, false);
TUNABLE(kLmrTactDiv, 2.60, 2.0, 3.5, false);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE(kAspWindowDelta, 9, 5, 20, false);
TUNABLE(kAspWindowGrowth, 1.55, 0.1, 2.0, false);

TUNABLE(kQsFutMargin, 101, 50, 200, false);

TUNABLE(kEvalHistUpdateMult, 60, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 65, 5, 150, false);
TUNABLE(kEvalHistUpdateMax, 100, 40, 200, false);

TUNABLE(kRevFutDepth, 6, 4, 10, true);
TUNABLE(kRevFutMargin, 74, 50, 150, false);
TUNABLE(kRevFutHistoryDiv, 600, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE(kRazoringMult, 450, 200, 700, false);

TUNABLE(kNullMoveBetaBase, 170, 50, 250, false);
TUNABLE(kNullMoveBetaMult, 24, 5, 30, false);
TUNABLE(kNullMoveRb, 4, 1, 5, false);
TUNABLE(kNullMoveRf, 4, 2, 8, true);
TUNABLE(kNullMoveRe, 202, 100, 400, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE(kLmpBase, 5.0, 1.5, 5.0, false);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE(kFutMarginBase, 196, 100, 250, false);
TUNABLE(kFutMarginMult, 96, 50, 200, false);
TUNABLE(kFutMarginHistDiv, 150, 32, 256, false);

TUNABLE(kSeePruneDepth, 8, 6, 12, true);
TUNABLE(kSeeQuietThresh, -64, -100, -20, false);
TUNABLE(kSeeNoisyThresh, -119, -200, -50, false);
TUNABLE(kSeeNoisyHistDiv, 150, 32, 256, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -480, -1000, 500, false);
TUNABLE(kHistThreshMult, -1695, -3000, -250, false);
TUNABLE(kCaptHistThreshBase, -480, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1695, -3000, -250, false);

TUNABLE(kLmrHistDiv, 11432, 5000, 20000, false);
TUNABLE(kLmrCaptHistDiv, 11432, 5000, 20000, false);
TUNABLE(kLmrComplexityDiff, 80, 5, 150, false);

TUNABLE(kDoDeeperBase, 35, 5, 70, false);
TUNABLE(kDoShallowerBase, 8, 0, 30, false);

TUNABLE(kSeDepth, 6, 6, 12, true);
TUNABLE(kSeDoubleMargin, 15, 0, 30, false);
TUNABLE(kSeTripleMargin, 110, 30, 250, false);
TUNABLE(kSeDepthExtensionDepth, 10, 0, 15, false);

TUNABLE(kProbcutBetaDelta, 250, 100, 400, false);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H