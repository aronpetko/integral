#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE_STEP(kLmrQuietBase, 0.8094797928646651, 0.5, 2.0, false, 0.08);
TUNABLE_STEP(kLmrQuietDiv, 2.0043976739797187, 0.5, 3.0, false, 0.08);
TUNABLE_STEP(kLmrTactBase, -0.2733141795716749, -1.0, 0.5, false, 0.08);
TUNABLE_STEP(kLmrTactDiv, 2.713821433951247, 1.0, 4.0, false, 0.08);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE(kAspWindowDelta, 7, 1, 50, false);
TUNABLE_STEP(kAspWindowGrowth, 1.3927761846084998, 0.1, 2.0, false, 0.08);

TUNABLE_STEP(kQsFutMargin, 127, 20, 300, false, 20);

TUNABLE(kEvalHistUpdateMult, 63, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 51, 5, 150, false);
TUNABLE(kEvalHistUpdateMax, 102, 40, 200, false);

TUNABLE(kRevFutDepth, 9, 4, 10, true);
TUNABLE(kRevFutMargin, 63, 50, 150, false);
TUNABLE(kRevFutOppWorseningMargin, 17, 5, 70, false);
TUNABLE(kRevFutMinMargin, 19, 5, 100, false);
TUNABLE_STEP(kRevFutLerpFactor, 0.4589078933032647, 0.0, 1.0, false, 0.05);
TUNABLE(kRevFutHistoryDiv, 552, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE(kRazoringMult, 413, 100, 700, false);

TUNABLE_STEP(kNmpBetaBase, 152, 50, 300, false, 15);
TUNABLE_STEP(kNmpBetaMult, 20, 5, 50, false, 5);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 178, 100, 300, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE_STEP(kLmrDepthNonPvNode, 984, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistQuiet, 1071, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistCapture, 1004, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthNotImproving, 1101, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthRoundingCutoff, 647, 512, 2048, false, 150);

TUNABLE(kLmpBase, 5.0, 1.5, 5.0, true);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE_STEP(kFutMarginBase, 200, 100, 250, false, 15);
TUNABLE_STEP(kFutMarginMult, 84, 50, 200, false, 5);
TUNABLE(kFutMarginHistDiv, 139, 32, 256, false);

TUNABLE(kSeePruneDepth, 8, 6, 12, true);
TUNABLE(kSeeQuietThresh, -60, -150, -5, false);
TUNABLE(kSeeNoisyThresh, -115, -150, -5, false);
TUNABLE(kSeePruneHistDiv, 124, 50, 300, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -452, -1000, 500, false);
TUNABLE(kHistThreshMult, -2053, -3000, -500, false);
TUNABLE(kCaptHistThreshBase, -535, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1846, -3000, -1000, false);

TUNABLE(kLmrHistDiv, 11299, 5000, 15000, false);
TUNABLE(kLmrCaptHistDiv, 10704, 5000, 15000, false);
TUNABLE_STEP(kLmrComplexityDiff, 74, 5, 150, false, 7);

TUNABLE_STEP(kDoDeeperBase, 34, 10, 60, false, 3);
TUNABLE_STEP(kDoShallowerBase, 5, 0, 30, false, 2);

TUNABLE(kSeDepth, 5, 6, 12, true);
TUNABLE_STEP(kSeDepthReduction, 7, 0, 30, false, 1);
TUNABLE_STEP(kSeDoubleMargin, 9, 0, 50, false, 2);
TUNABLE_STEP(kSeTripleMargin, 71, 20, 250, false, 10);
TUNABLE_STEP(kSeDepthExtensionDepth, 10, 0, 20, false, 1);

TUNABLE_STEP(kLmrNonPvNode, 1006, 512, 2048, false, 150);
TUNABLE_STEP(kLmrWasPvNode, 1046, 512, 2048, false, 150);
TUNABLE_STEP(kLmrCutNode, 2092, 1024, 4096, false, 300);
TUNABLE_STEP(kLmrGivesCheck, 1049, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistQuiet, 1013, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistCapture, 1139, 512, 2048, false, 150);
TUNABLE_STEP(kLmrNotImproving, 1008, 512, 2048, false, 150);
TUNABLE_STEP(kLmrComplexity, 1050, 512, 2048, false, 150);
TUNABLE_STEP(kLmrKillerMoves, 1068, 512, 2048, false, 150);
TUNABLE_STEP(kLmrRoundingCutoff, 593, 512, 2048, false, 120);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 241, 50, 300, false);

TUNABLE_STEP(kHistoryBonusMargin, 50, 5, 120, false, 5);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H