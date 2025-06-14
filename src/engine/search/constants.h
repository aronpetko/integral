#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE_STEP(kLmrQuietBase, 0.8411422854178264, 0.5, 2.0, false, 0.08);
TUNABLE_STEP(kLmrQuietDiv, 2.0845068399240376, 0.5, 3.0, false, 0.08);
TUNABLE_STEP(kLmrTactBase, -0.2878295751331129, -1.0, 0.5, false, 0.08);
TUNABLE_STEP(kLmrTactDiv, 2.8025216843472687, 1.0, 4.0, false, 0.08);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE_STEP(kAspWindowDelta, 9, 1, 50, false, 1);
TUNABLE_STEP(kAspWindowGrowth, 1.3945105932751167, 0.1, 2.0, false, 0.03);
TUNABLE(kAspWindowScoreDiv, 16300, 8192, 32768, false);
TUNABLE_STEP(kAspBetaLerpFactor, 0.4958598755941256, 0.0, 1.0, false, 0.1);

TUNABLE_STEP(kQsCutoffLerpFactor, 0.40989634160554717, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFailHighLerpFactor, 0.5563777412238188, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFutMargin, 155, 20, 300, false, 20);

TUNABLE(kEvalHistUpdateMult, 62, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 55, 5, 500, false);
TUNABLE(kEvalHistUpdateMax, 118, 5, 500, false);
TUNABLE_STEP(kEvalHistUpdateBias, 2, 0, 50, false, 5);

TUNABLE(kRevFutDepth, 9, 4, 10, true);
TUNABLE_STEP(kRevFutMargin, 51, 50, 150, false, 5);
TUNABLE_STEP(kRevFutImprovingMargin, 92, 20, 150, false, 5);
TUNABLE_STEP(kRevFutOppWorseningMargin, 22, 5, 70, false, 4);
TUNABLE_STEP(kRevFutMinMargin, 19, 5, 100, false, 10);
TUNABLE_STEP(kRevFutLerpFactor, 0.476447358910071, 0.0, 1.0, false, 0.05);
TUNABLE(kRevFutHistoryDiv, 579, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE_STEP(kRazoringMult, 409, 200, 600, false, 20);

TUNABLE_STEP(kNmpBetaBase, 145, 50, 200, false, 15);
TUNABLE_STEP(kNmpBetaMult, 9, 5, 50, false, 5);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 166, 100, 300, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE_STEP(kLmrDepthNonPvNode, 1201, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistQuiet, 1295, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthNotImproving, 1235, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthRoundingCutoff, 564, 512, 2048, false, 100);

TUNABLE(kLmpBase, 5, 1, 10, true);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE_STEP(kFutMarginBase, 167, 100, 250, false, 20);
TUNABLE_STEP(kFutMarginMult, 83, 50, 200, false, 5);
TUNABLE(kFutMarginHistDiv, 135, 32, 256, false);

TUNABLE(kSeeQuietThresh, -20, -150, -5, false);
TUNABLE(kSeeNoisyThresh, -104, -150, -5, false);
TUNABLE(kSeePruneHistDiv, 134, 50, 300, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -324, -1000, 500, false);
TUNABLE(kHistThreshMult, -2178, -3000, -500, false);
TUNABLE(kCaptHistThreshBase, -468, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1758, -3000, -1000, false);

TUNABLE(kLmrHistDiv, 11523, 5000, 15000, false);
TUNABLE(kLmrCaptHistDiv, 11103, 5000, 15000, false);
TUNABLE(kLmrComplexityDiff, 74, 5, 150, false);

TUNABLE(kDoDeeperBase, 31, 10, 60, false);
TUNABLE(kDoDeeperMult, 32, 16, 64, false);
TUNABLE(kDoShallowerBase, 6, 0, 50, false);

TUNABLE(kSeDepth, 5, 6, 12, true);
TUNABLE_STEP(kSeDepthReduction, 7, 0, 30, false, 1);
TUNABLE_STEP(kSeBetaMargin, 17, 0, 32, false, 1);
TUNABLE_STEP(kSeDoubleMargin, 8, 0, 50, false, 1);
TUNABLE_STEP(kSeTripleMargin, 62, 20, 250, false, 10);
TUNABLE_STEP(kSeDepthExtensionDepth, 12, 0, 20, false, 1);

TUNABLE_STEP(kLmrNonPvNode, 866, 512, 2048, false, 150);
TUNABLE_STEP(kLmrWasPvNode, 1158, 512, 2048, false, 150);
TUNABLE_STEP(kLmrCutNode, 2153, 1024, 4096, false, 150);
TUNABLE_STEP(kLmrGivesCheck, 931, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistQuiet, 590, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistCapture, 1194, 512, 2048, false, 150);
TUNABLE_STEP(kLmrNotImproving, 1050, 512, 2048, false, 150);
TUNABLE_STEP(kLmrComplexity, 822, 512, 2048, false, 150);
TUNABLE_STEP(kLmrKillerMoves, 954, 512, 2048, false, 150);
TUNABLE_STEP(kLmrRoundingCutoff, 591, 512, 2048, false, 120);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 218, 50, 300, false);

TUNABLE_STEP(kHistoryBonusMargin, 51, 5, 120, false, 10);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H