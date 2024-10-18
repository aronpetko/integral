#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE(kLmrQuietBase, 0.8153, 0.5, 1.2, false);
TUNABLE(kLmrQuietDiv, 2.0234, 1.5, 3.0, false);
TUNABLE(kLmrTactBase, -0.2460, -0.5, 0.2, false);
TUNABLE(kLmrTactDiv, 2.6076, 2.0, 3.5, false);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE(kAspWindowDelta, 9, 5, 20, false);
TUNABLE(kAspWindowGrowth, 1.6107, 0.1, 2.0, false);

TUNABLE(kQsFutMargin, 100, 50, 200, false);

TUNABLE(kEvalHistUpdateMult, 59, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 66, 5, 150, false);
TUNABLE(kEvalHistUpdateMax, 97, 40, 200, false);

TUNABLE(kRevFutDepth, 6, 4, 10, true);
TUNABLE(kRevFutMargin, 72, 50, 150, false);
TUNABLE(kRevFutHistoryDiv, 601, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE(kRazoringMult, 468, 200, 700, false);

TUNABLE(kNullMoveBetaBase, 154, 50, 250, false);
TUNABLE(kNullMoveBetaMult, 24, 5, 30, false);
TUNABLE(kNullMoveRb, 4, 1, 5, true);
TUNABLE(kNullMoveRf, 4, 2, 8, true);
TUNABLE(kNullMoveRe, 195, 100, 400, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE(kLmpBase, 5.0, 1.5, 5.0, false);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE(kFutMarginBase, 191, 100, 250, false);
TUNABLE(kFutMarginMult, 97, 50, 200, false);
TUNABLE(kFutMarginHistDiv, 152, 32, 256, false);

TUNABLE(kSeePruneDepth, 8, 6, 12, true);
TUNABLE(kSeeQuietThresh, -66, -100, -20, false);
TUNABLE(kSeeNoisyThresh, -117, -200, -50, false);
TUNABLE(kSeeNoisyHistDiv, 152, 32, 256, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -502, -1000, 500, false);
TUNABLE(kHistThreshMult, -1766, -3000, -250, false);
TUNABLE(kCaptHistThreshBase, -459, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1771, -3000, -250, false);

TUNABLE(kLmrHistDiv, 11530, 5000, 20000, false);
TUNABLE(kLmrCaptHistDiv, 11439, 5000, 20000, false);
TUNABLE(kLmrComplexityDiff, 80, 5, 150, false);

TUNABLE(kDoDeeperBase, 35, 5, 70, false);
TUNABLE(kDoShallowerBase, 8, 0, 30, false);

TUNABLE(kSeDepth, 6, 6, 12, true);
TUNABLE(kSeDoubleMargin, 14, 0, 30, false);
TUNABLE(kSeTripleMargin, 104, 30, 250, false);
TUNABLE(kSeDepthExtensionDepth, 10, 0, 15, false);

TUNABLE(kProbcutBetaDelta, 249, 100, 400, false);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H