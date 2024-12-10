#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE(kLmrQuietBase, 0.8095516103173113, 0.5, 2.0, false);
TUNABLE(kLmrQuietDiv, 2.030305124305164, 0.5, 3.0, false);
TUNABLE(kLmrTactBase, -0.2546789090587976, -1.0, 0.5, false);
TUNABLE(kLmrTactDiv, 2.693492786895266, 1.0, 4.0, false);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE(kAspWindowDelta, 8, 1, 50, false);
TUNABLE(kAspWindowGrowth, 1.4168709059240245, 0.1, 2.0, false);

TUNABLE(kQsFutMargin, 110, 20, 300, false);

TUNABLE(kEvalHistUpdateMult, 62, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 58, 5, 150, false);
TUNABLE(kEvalHistUpdateMax, 101, 40, 200, false);

TUNABLE(kRevFutDepth, 6, 4, 10, true);
TUNABLE(kRevFutMargin, 58, 50, 150, false);
TUNABLE(kRevFutOppWorseningMargin, 17, 5, 70, false);
TUNABLE(kRevFutMinMargin, 19, 5, 100, false);
TUNABLE_STEP(kRevFutLerpFactor, 0.44624339708685534, 0.0, 1.0, false, 0.1);
TUNABLE(kRevFutHistoryDiv, 550, 200, 1000, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE(kRazoringMult, 430, 100, 700, false);

TUNABLE(kNmpBetaBase, 140, 50, 300, false);
TUNABLE(kNmpBetaMult, 25, 5, 30, false);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 174, 100, 400, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE(kLmpBase, 5.0, 1.5, 5.0, true);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE(kFutMarginBase, 200, 100, 250, false);
TUNABLE(kFutMarginMult, 84, 50, 200, false);
TUNABLE(kFutMarginHistDiv, 137, 32, 256, false);

TUNABLE(kSeePruneDepth, 8, 6, 12, true);
TUNABLE(kSeeQuietThresh, -61, -200, -5, false);
TUNABLE(kSeeNoisyThresh, -113, -200, -5, false);
TUNABLE(kSeePruneHistDiv, 137, 5, 500, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -487, -1000, 500, false);
TUNABLE(kHistThreshMult, -2012, -3000, -250, false);
TUNABLE(kCaptHistThreshBase, -476, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1800, -3000, -250, false);

TUNABLE(kLmrHistDiv, 11156, 5000, 20000, false);
TUNABLE(kLmrCaptHistDiv, 10612, 5000, 20000, false);
TUNABLE(kLmrComplexityDiff, 81, 5, 150, false);

TUNABLE(kDoDeeperBase, 34, 5, 70, false);
TUNABLE(kDoShallowerBase, 5, 0, 30, false);

TUNABLE(kSeDepth, 6, 6, 12, true);
TUNABLE(kSeDepthReduction, 7, 0, 30, false);
TUNABLE(kSeDoubleMargin, 12, 0, 50, false);
TUNABLE(kSeTripleMargin, 81, 20, 250, false);
TUNABLE(kSeDepthExtensionDepth, 11, 0, 20, false);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 238, 50, 400, false);

TUNABLE(kHistoryBonusMargin, 49, 5, 200, false);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H