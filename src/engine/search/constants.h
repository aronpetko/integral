#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE(kLmrQuietBase, 0.8102, 0.5, 2.0, false);
TUNABLE(kLmrQuietDiv, 2.0884, 0.5, 3.0, false);
TUNABLE(kLmrTactBase, -0.2352, -1.0, 0.5, false);
TUNABLE(kLmrTactDiv, 2.6324, 1.0, 4.0, false);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE(kAspWindowDelta, 8, 1, 50, false);
TUNABLE(kAspWindowGrowth, 1.41, 0.1, 2.0, false);

TUNABLE(kQsFutMargin, 109, 20, 300, false);

TUNABLE(kEvalHistUpdateMult, 64, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 62, 5, 150, false);
TUNABLE(kEvalHistUpdateMax, 104, 40, 200, false);

TUNABLE(kRevFutDepth, 6, 4, 10, true);
TUNABLE(kRevFutMargin, 62, 50, 150, false);
TUNABLE(kRevFutOppWorseningMargin, 15, 5, 70, false);
TUNABLE(kRevFutMinMargin, 19, 5, 100, false);
TUNABLE_STEP(kRevFutLerpFactor, 0.5113, 0.0, 1.0, false, 0.1);
TUNABLE(kRevFutHistoryDiv, 571, 200, 1000, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE(kRazoringMult, 443, 100, 700, false);

TUNABLE(kNmpBetaBase, 142, 50, 300, false);
TUNABLE(kNmpBetaMult, 25, 5, 30, false);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 173, 100, 400, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE(kLmpBase, 5.0, 1.5, 5.0, true);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE(kFutMarginBase, 202, 100, 250, false);
TUNABLE(kFutMarginMult, 89, 50, 200, false);
TUNABLE(kFutMarginHistDiv, 145, 32, 256, false);

TUNABLE(kSeePruneDepth, 8, 6, 12, true);
TUNABLE(kSeeQuietThresh, -63, -200, -5, false);
TUNABLE(kSeeNoisyThresh, -114, -200, -5, false);
TUNABLE(kSeePruneHistDiv, 152, 5, 500, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -474, -1000, 500, false);
TUNABLE(kHistThreshMult, -1954, -3000, -250, false);
TUNABLE(kCaptHistThreshBase, -450, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1804, -3000, -250, false);

TUNABLE(kLmrHistDiv, 11056, 5000, 20000, false);
TUNABLE(kLmrCaptHistDiv, 10469, 5000, 20000, false);
TUNABLE(kLmrComplexityDiff, 81, 5, 150, false);

TUNABLE(kDoDeeperBase, 33, 5, 70, false);
TUNABLE(kDoShallowerBase, 5, 0, 30, false);

TUNABLE(kSeDepth, 6, 6, 12, true);
TUNABLE(kSeDepthReduction, 6, 0, 30, false);
TUNABLE(kSeDoubleMargin, 13, 0, 50, false);
TUNABLE(kSeTripleMargin, 78, 20, 250, false);
TUNABLE(kSeDepthExtensionDepth, 11, 0, 20, false);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 236, 50, 400, false);

TUNABLE(kHistoryBonusMargin, 52, 5, 200, false);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H