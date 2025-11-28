#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE_STEP(kLmrQuietBase, 0.7942757532398008, 0.5, 2.0, false, 0.08);
TUNABLE_STEP(kLmrQuietDiv, 2.0711362345673554, 0.5, 3.0, false, 0.08);
TUNABLE_STEP(kLmrTactBase, -0.3400543194068645, -1.0, 0.5, false, 0.08);
TUNABLE_STEP(kLmrTactDiv, 2.8603688787714847, 1.0, 4.0, false, 0.08);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE_STEP(kAspWindowDelta, 10, 1, 50, false, 1);
TUNABLE_STEP(kAspWindowGrowth, 1.3983208308938992, 0.1, 2.0, false, 0.03);
TUNABLE(kAspWindowScoreDiv, 15954, 8192, 32768, false);
TUNABLE_STEP(kAspBetaLerpFactor, 0.4935066776988994, 0.0, 1.0, false, 0.1);

TUNABLE_STEP(kQsCutoffLerpFactor, 0.2807830604772068, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFailHighLerpFactor, 0.5905119923701746, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFutMargin, 173, 20, 300, false, 20);

TUNABLE(kEvalHistUpdateMult, 58, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 68, 5, 500, false);
TUNABLE(kEvalHistUpdateMax, 108, 5, 500, false);
TUNABLE_STEP(kEvalHistUpdateBias, 1, 0, 50, false, 5);

TUNABLE(kRevFutDepth, 11, 4, 10, true);
TUNABLE_STEP(kRevFutMargin, 50, 50, 150, false, 5);
TUNABLE_STEP(kRevFutImprovingMargin, 94, 20, 150, false, 5);
TUNABLE_STEP(kRevFutOppWorseningMargin, 25, 5, 70, false, 4);
TUNABLE_STEP(kRevFutMinMargin, 13, 5, 100, false, 10);
TUNABLE_STEP(kRevFutComplexityMargin, 12, 1, 64, false, 10);
TUNABLE_STEP(kRevFutLerpFactor, 0.5160669355461122, 0.0, 1.0, false, 0.05);
TUNABLE(kRevFutHistoryDiv, 586, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE_STEP(kRazoringMult, 393, 200, 600, false, 20);

TUNABLE_STEP(kNmpBetaBase, 146, 50, 200, false, 15);
TUNABLE_STEP(kNmpBetaMult, 7, 5, 50, false, 5);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 169, 100, 300, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE_STEP(kLmrDepthNonPvNode, 1265, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistQuiet, 1374, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthNotImproving, 1302, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthRoundingCutoff, 675, 512, 2048, false, 100);

TUNABLE(kLmpBase, 5, 1, 10, true);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE_STEP(kFutMarginBase, 127, 100, 250, false, 20);
TUNABLE_STEP(kFutMarginMult, 81, 50, 200, false, 5);
TUNABLE(kFutMarginHistDiv, 124, 32, 256, false);

TUNABLE(kSeeQuietThresh, -17, -150, -5, false);
TUNABLE(kSeeNoisyThresh, -98, -150, -5, false);
TUNABLE(kSeePruneHistDiv, 131, 50, 300, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -250, -1000, 500, false);
TUNABLE(kHistThreshMult, -2198, -3000, -500, false);
TUNABLE(kCaptHistThreshBase, -447, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1773, -3000, -1000, false);

TUNABLE(kLmrHistDiv, 11680, 5000, 15000, true);
TUNABLE(kLmrCaptHistDiv, 11008, 5000, 15000, true);
TUNABLE(kLmrComplexityDiff, 73, 5, 150, false);

TUNABLE(kDoDeeperBase, 30, 10, 60, false);
TUNABLE(kDoDeeperMult, 33, 16, 64, false);
TUNABLE(kDoShallowerBase, 5, 0, 50, false);

TUNABLE(kSeDepth, 5, 6, 12, true);
TUNABLE_STEP(kSeDepthReduction, 7, 0, 30, false, 1);
TUNABLE_STEP(kSeBetaMargin, 17, 0, 32, false, 1);
TUNABLE_STEP(kSeDoubleMargin, 8, 0, 50, false, 1);
TUNABLE_STEP(kSePvDoubleMargin, 150, 0, 300, false, 30);
TUNABLE_STEP(kSeTripleMargin, 58, 20, 250, false, 10);
TUNABLE_STEP(kSeDepthExtensionDepth, 13, 0, 20, false, 1);

TUNABLE_STEP(kLmrNonPvNode, 743, 512, 2048, false, 150);
TUNABLE_STEP(kLmrWasPvNode, 1168, 512, 2048, false, 150);
TUNABLE_STEP(kLmrCutNode, 2205, 1024, 4096, false, 150);
TUNABLE_STEP(kLmrGivesCheck, 942, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistQuiet, 522, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistCapture, 1229, 512, 2048, false, 150);
TUNABLE_STEP(kLmrNotImproving, 949, 512, 2048, false, 150);
TUNABLE_STEP(kLmrComplexity, 778, 512, 2048, false, 150);
TUNABLE_STEP(kLmrKillerMoves, 886, 512, 2048, false, 150);
TUNABLE_STEP(kLmrRoundingCutoff, 698, 512, 2048, false, 120);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 213, 50, 300, false);

TUNABLE_STEP(kHistoryBonusMargin, 44, 5, 120, false, 10);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H