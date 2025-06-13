#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE_STEP(kLmrQuietBase, 0.8294805560978709, 0.5, 2.0, false, 0.08);
TUNABLE_STEP(kLmrQuietDiv, 2.0818818734265614, 0.5, 3.0, false, 0.08);
TUNABLE_STEP(kLmrTactBase, -0.2956464411136834, -1.0, 0.5, false, 0.08);
TUNABLE_STEP(kLmrTactDiv, 2.8358456654902957, 1.0, 4.0, false, 0.08);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE_STEP(kAspWindowDelta, 9, 1, 50, false, 1);
TUNABLE_STEP(kAspWindowGrowth, 1.3954689903699884, 0.1, 2.0, false, 0.03);
TUNABLE(kAspWindowScoreDiv, 16710, 8192, 32768, false);
TUNABLE_STEP(kAspBetaLerpFactor, 0.5114579980575017, 0.0, 1.0, false, 0.1);

TUNABLE_STEP(kQsCutoffLerpFactor, 0.4308948620839404, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFailHighLerpFactor, 0.543803140285779, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFutMargin, 160, 20, 300, false, 20);

TUNABLE(kEvalHistUpdateMult, 61, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 61, 5, 500, false);
TUNABLE(kEvalHistUpdateMax, 111, 5, 500, false);
TUNABLE_STEP(kEvalHistUpdateBias, 2, 0, 50, false, 5);

TUNABLE(kRevFutDepth, 9, 4, 10, true);
TUNABLE_STEP(kRevFutMargin, 53, 50, 150, false, 5);
TUNABLE_STEP(kRevFutImprovingMargin, 91, 20, 150, false, 5);
TUNABLE_STEP(kRevFutOppWorseningMargin, 22, 5, 70, false, 4);
TUNABLE_STEP(kRevFutMinMargin, 16, 5, 100, false, 10);
TUNABLE_STEP(kRevFutLerpFactor, 0.45954539246802056, 0.0, 1.0, false, 0.05);
TUNABLE(kRevFutHistoryDiv, 581, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE_STEP(kRazoringMult, 409, 200, 600, false, 20);

TUNABLE_STEP(kNmpBetaBase, 145, 50, 200, false, 15);
TUNABLE_STEP(kNmpBetaMult, 9, 5, 50, false, 5);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 166, 100, 300, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE_STEP(kLmrDepthNonPvNode, 1156, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistQuiet, 1273, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthNotImproving, 1263, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthRoundingCutoff, 583, 512, 2048, false, 100);

TUNABLE(kLmpBase, 5, 1, 10, true);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE_STEP(kFutMarginBase, 178, 100, 250, false, 20);
TUNABLE_STEP(kFutMarginMult, 84, 50, 200, false, 5);
TUNABLE(kFutMarginHistDiv, 136, 32, 256, false);

TUNABLE(kSeeQuietThresh, -19, -150, -5, false);
TUNABLE(kSeeNoisyThresh, -102, -150, -5, false);
TUNABLE(kSeePruneHistDiv, 136, 50, 300, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -364, -1000, 500, false);
TUNABLE(kHistThreshMult, -2104, -3000, -500, false);
TUNABLE(kCaptHistThreshBase, -523, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1732, -3000, -1000, false);

TUNABLE(kLmrHistDiv, 11476, 5000, 15000, false);
TUNABLE(kLmrCaptHistDiv, 11047, 5000, 15000, false);
TUNABLE(kLmrComplexityDiff, 78, 5, 150, false);

TUNABLE(kDoDeeperBase, 31, 10, 60, false);
TUNABLE(kDoDeeperMult, 33, 16, 64, false);
TUNABLE(kDoShallowerBase, 6, 0, 50, false);

TUNABLE(kSeDepth, 5, 6, 12, true);
TUNABLE_STEP(kSeDepthReduction, 7, 0, 30, false, 1);
TUNABLE_STEP(kSeBetaMargin, 17, 0, 32, false, 1);
TUNABLE_STEP(kSeDoubleMargin, 8, 0, 50, false, 1);
TUNABLE_STEP(kSeTripleMargin, 60, 20, 250, false, 10);
TUNABLE_STEP(kSeDepthExtensionDepth, 11, 0, 20, false, 1);

TUNABLE_STEP(kLmrNonPvNode, 835, 512, 2048, false, 150);
TUNABLE_STEP(kLmrWasPvNode, 1148, 512, 2048, false, 150);
TUNABLE_STEP(kLmrCutNode, 2125, 1024, 4096, false, 150);
TUNABLE_STEP(kLmrGivesCheck, 1017, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistQuiet, 647, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistCapture, 1193, 512, 2048, false, 150);
TUNABLE_STEP(kLmrNotImproving, 1013, 512, 2048, false, 150);
TUNABLE_STEP(kLmrComplexity, 792, 512, 2048, false, 150);
TUNABLE_STEP(kLmrKillerMoves, 941, 512, 2048, false, 150);
TUNABLE_STEP(kLmrRoundingCutoff, 619, 512, 2048, false, 120);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 221, 50, 300, false);

TUNABLE_STEP(kHistoryBonusMargin, 51, 5, 120, false, 10);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H