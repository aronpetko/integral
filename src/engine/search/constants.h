#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE_STEP(kLmrQuietBase, 0.8275113893302499, 0.5, 2.0, false, 0.08);
TUNABLE_STEP(kLmrQuietDiv, 2.0136343792213087, 0.5, 3.0, false, 0.08);
TUNABLE_STEP(kLmrTactBase, -0.26041410060629416, -1.0, 0.5, false, 0.08);
TUNABLE_STEP(kLmrTactDiv, 2.736026343140298, 1.0, 4.0, false, 0.08);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE(kAspWindowDelta, 9, 1, 50, false);
TUNABLE_STEP(kAspWindowGrowth, 1.4381167802732724, 0.1, 2.0, false, 0.08);

TUNABLE_STEP(kQsFutMargin, 96, 20, 300, false, 20);

TUNABLE(kEvalHistUpdateMult, 62, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 55, 5, 150, false);
TUNABLE(kEvalHistUpdateMax, 102, 40, 200, false);

TUNABLE(kRevFutDepth, 9, 4, 10, true);
TUNABLE(kRevFutMargin, 66, 50, 150, false);
TUNABLE(kRevFutOppWorseningMargin, 18, 5, 70, false);
TUNABLE(kRevFutMinMargin, 20, 5, 100, false);
TUNABLE_STEP(kRevFutLerpFactor, 0.43487262799337356, 0.0, 1.0, false, 0.05);
TUNABLE(kRevFutHistoryDiv, 540, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE(kRazoringMult, 438, 100, 700, false);

TUNABLE_STEP(kNmpBetaBase, 145, 50, 300, false, 15);
TUNABLE_STEP(kNmpBetaMult, 22, 5, 50, false, 5);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 175, 100, 300, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE_STEP(kLmrDepthNonPvNode, 1040, 512, 2048, false, 80);
TUNABLE_STEP(kLmrDepthHistQuiet, 1038, 512, 2048, false, 80);
TUNABLE_STEP(kLmrDepthHistCapture, 1007, 512, 2048, false, 80);
TUNABLE_STEP(kLmrDepthNotImproving, 1019, 512, 2048, false, 80);
TUNABLE_STEP(kLmrDepthRoundingCutoff, 515, 512, 2048, false, 20);

TUNABLE(kLmpBase, 5.0, 1.5, 5.0, true);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE(kFutMarginBase, 203, 100, 250, false);
TUNABLE(kFutMarginMult, 78, 50, 200, false);
TUNABLE(kFutMarginHistDiv, 137, 32, 256, false);

TUNABLE(kSeePruneDepth, 8, 6, 12, true);
TUNABLE(kSeeQuietThresh, -63, -200, -5, false);
TUNABLE(kSeeNoisyThresh, -109, -200, -5, false);
TUNABLE(kSeePruneHistDiv, 140, 50, 300, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -463, -1000, 500, false);
TUNABLE(kHistThreshMult, -1987, -3000, -500, false);
TUNABLE(kCaptHistThreshBase, -471, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1798, -3000, -1000, false);

TUNABLE(kLmrHistDiv, 11151, 5000, 15000, false);
TUNABLE(kLmrCaptHistDiv, 10476, 5000, 15000, false);
TUNABLE_STEP(kLmrComplexityDiff, 79, 5, 150, false, 7);

TUNABLE(kDoDeeperBase, 36, 10, 60, false);
TUNABLE(kDoShallowerBase, 5, 0, 30, false);

TUNABLE(kSeDepth, 5, 6, 12, true);
TUNABLE_STEP(kSeDepthReduction, 7, 0, 30, false, 1);
TUNABLE_STEP(kSeDoubleMargin, 10, 0, 50, false, 2);
TUNABLE_STEP(kSeTripleMargin, 79, 20, 250, false, 5);
TUNABLE_STEP(kSeDepthExtensionDepth, 11, 0, 20, false, 1);

TUNABLE_STEP(kLmrNonPvNode, 1036, 512, 2048, false, 80);
TUNABLE_STEP(kLmrWasPvNode, 1035, 512, 2048, false, 80);
TUNABLE_STEP(kLmrCutNode, 2057, 1024, 4096, false, 140);
TUNABLE_STEP(kLmrGivesCheck, 1023, 512, 2048, false, 80);
TUNABLE_STEP(kLmrHistQuiet, 1007, 512, 2048, false, 80);
TUNABLE_STEP(kLmrHistCapture, 1036, 512, 2048, false, 80);
TUNABLE_STEP(kLmrNotImproving, 980, 512, 2048, false, 80);
TUNABLE_STEP(kLmrComplexity, 1005, 512, 2048, false, 80);
TUNABLE_STEP(kLmrKillerMoves, 977, 512, 2048, false, 80);
TUNABLE_STEP(kLmrRoundingCutoff, 517, 512, 2048, false, 20);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 238, 50, 300, false);

TUNABLE_STEP(kHistoryBonusMargin, 50, 5, 120, false, 5);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H