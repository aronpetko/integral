#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE(kLmrQuietBase, 0.8108281963087768, 0.5, 2.0, false);
TUNABLE(kLmrQuietDiv, 2.00963684380911, 0.5, 3.0, false);
TUNABLE(kLmrTactBase, -0.26539563743301553, -1.0, 0.5, false);
TUNABLE(kLmrTactDiv, 2.7225202957220636, 1.0, 4.0, false);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE(kAspWindowDelta, 8, 1, 50, false);
TUNABLE(kAspWindowGrowth, 1.4178369880005977, 0.1, 2.0, false);

TUNABLE(kQsFutMargin, 106, 20, 300, false);

TUNABLE(kEvalHistUpdateMult, 62, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 57, 5, 150, false);
TUNABLE(kEvalHistUpdateMax, 101, 40, 200, false);

TUNABLE(kRevFutDepth, 9, 4, 10, true);
TUNABLE(kRevFutMargin, 65, 50, 150, false);
TUNABLE(kRevFutOppWorseningMargin, 17, 5, 70, false);
TUNABLE(kRevFutMinMargin, 19, 5, 100, false);
TUNABLE_STEP(kRevFutLerpFactor, 0.4313712445065815, 0.0, 1.0, false, 0.1);
TUNABLE(kRevFutHistoryDiv, 543, 200, 1000, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE(kRazoringMult, 433, 100, 700, false);

TUNABLE(kNmpBetaBase, 141, 50, 300, false);
TUNABLE(kNmpBetaMult, 25, 5, 30, false);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 174, 100, 400, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE(kLmpBase, 5.0, 1.5, 5.0, true);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE(kFutMarginBase, 201, 100, 250, false);
TUNABLE(kFutMarginMult, 82, 50, 200, false);
TUNABLE(kFutMarginHistDiv, 137, 32, 256, false);

TUNABLE(kSeePruneDepth, 8, 6, 12, true);
TUNABLE(kSeeQuietThresh, -62, -200, -5, false);
TUNABLE(kSeeNoisyThresh, -112, -200, -5, false);
TUNABLE(kSeePruneHistDiv, 137, 5, 500, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -471, -1000, 500, false);
TUNABLE(kHistThreshMult, -2000, -3000, -250, false);
TUNABLE(kCaptHistThreshBase, -485, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1807, -3000, -250, false);

TUNABLE(kLmrHistDiv, 11105, 5000, 20000, false);
TUNABLE(kLmrCaptHistDiv, 10468, 5000, 20000, false);
TUNABLE(kLmrComplexityDiff, 81, 5, 150, false);

TUNABLE(kDoDeeperBase, 35, 5, 70, false);
TUNABLE(kDoShallowerBase, 5, 0, 30, false);

TUNABLE(kSeDepth, 5, 6, 12, true);
TUNABLE(kSeDepthReduction, 7, 0, 30, false);
TUNABLE(kSeDoubleMargin, 11, 0, 50, false);
TUNABLE(kSeTripleMargin, 81, 20, 250, false);
TUNABLE(kSeDepthExtensionDepth, 11, 0, 20, false);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 238, 50, 400, false);

TUNABLE(kHistoryBonusMargin, 49, 5, 200, false);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H