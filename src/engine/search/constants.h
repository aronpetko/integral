#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE_STEP(kLmrQuietBase, 0.8122512762259549, 0.5, 2.0, false, 0.08);
TUNABLE_STEP(kLmrQuietDiv, 2.0226038678379274, 0.5, 3.0, false, 0.08);
TUNABLE_STEP(kLmrTactBase, -0.24827726271627718, -1.0, 0.5, false, 0.08);
TUNABLE_STEP(kLmrTactDiv, 2.7183200134830456, 1.0, 4.0, false, 0.08);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE(kAspWindowDelta, 8, 1, 50, false);
TUNABLE_STEP(kAspWindowGrowth, 1.4369274514074268, 0.1, 2.0, false, 0.08);

TUNABLE_STEP(kQsFutMargin, 117, 20, 300, false, 20);

TUNABLE(kEvalHistUpdateMult, 62, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 56, 5, 150, false);
TUNABLE(kEvalHistUpdateMax, 100, 40, 200, false);

TUNABLE(kRevFutDepth, 9, 4, 10, true);
TUNABLE(kRevFutMargin, 63, 50, 150, false);
TUNABLE(kRevFutOppWorseningMargin, 17, 5, 70, false);
TUNABLE(kRevFutMinMargin, 17, 5, 100, false);
TUNABLE_STEP(kRevFutLerpFactor, 0.4507033679682523, 0.0, 1.0, false, 0.05);
TUNABLE(kRevFutHistoryDiv, 541, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE(kRazoringMult, 426, 100, 700, false);

TUNABLE_STEP(kNmpBetaBase, 144, 50, 300, false, 15);
TUNABLE_STEP(kNmpBetaMult, 24, 5, 50, false, 5);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 176, 100, 300, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE_STEP(kLmrDepthNonPvNode, 1032, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistQuiet, 1025, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistCapture, 1044, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthNotImproving, 1052, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthRoundingCutoff, 575, 512, 2048, false, 150);

TUNABLE(kLmpBase, 5.0, 1.5, 5.0, true);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE_STEP(kFutMarginBase, 198, 100, 250, false, 15);
TUNABLE_STEP(kFutMarginMult, 84, 50, 200, false, 5);
TUNABLE(kFutMarginHistDiv, 137, 32, 256, false);

TUNABLE(kSeePruneDepth, 8, 6, 12, true);
TUNABLE(kSeeQuietThresh, -58, -150, -5, false);
TUNABLE(kSeeNoisyThresh, -114, -150, -5, false);
TUNABLE(kSeePruneHistDiv, 131, 50, 300, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -426, -1000, 500, false);
TUNABLE(kHistThreshMult, -2006, -3000, -500, false);
TUNABLE(kCaptHistThreshBase, -510, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1852, -3000, -1000, false);

TUNABLE(kLmrHistDiv, 11239, 5000, 15000, false);
TUNABLE(kLmrCaptHistDiv, 10511, 5000, 15000, false);
TUNABLE_STEP(kLmrComplexityDiff, 80, 5, 150, false, 7);

TUNABLE_STEP(kDoDeeperBase, 35, 10, 60, false, 3);
TUNABLE_STEP(kDoShallowerBase, 5, 0, 30, false, 2);

TUNABLE(kSeDepth, 5, 6, 12, true);
TUNABLE_STEP(kSeDepthReduction, 7, 0, 30, false, 1);
TUNABLE_STEP(kSeDoubleMargin, 11, 0, 50, false, 2);
TUNABLE_STEP(kSeTripleMargin, 77, 20, 250, false, 10);
TUNABLE_STEP(kSeDepthExtensionDepth, 10, 0, 20, false, 1);

TUNABLE_STEP(kLmrNonPvNode, 996, 512, 2048, false, 150);
TUNABLE_STEP(kLmrWasPvNode, 1012, 512, 2048, false, 150);
TUNABLE_STEP(kLmrCutNode, 2050, 1024, 4096, false, 300);
TUNABLE_STEP(kLmrGivesCheck, 1052, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistQuiet, 998, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistCapture, 1050, 512, 2048, false, 150);
TUNABLE_STEP(kLmrNotImproving, 1036, 512, 2048, false, 150);
TUNABLE_STEP(kLmrComplexity, 1074, 512, 2048, false, 150);
TUNABLE_STEP(kLmrKillerMoves, 1054, 512, 2048, false, 150);
TUNABLE_STEP(kLmrRoundingCutoff, 574, 512, 2048, false, 120);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 243, 50, 300, false);

TUNABLE_STEP(kHistoryBonusMargin, 49, 5, 120, false, 5);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H