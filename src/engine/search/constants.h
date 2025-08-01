#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE_STEP(kLmrQuietBase, 0.823932254304473, 0.5, 2.0, false, 0.08);
TUNABLE_STEP(kLmrQuietDiv, 2.0783813948216285, 0.5, 3.0, false, 0.08);
TUNABLE_STEP(kLmrTactBase, -0.3578686813103516, -1.0, 0.5, false, 0.08);
TUNABLE_STEP(kLmrTactDiv, 2.8385583912777297, 1.0, 4.0, false, 0.08);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE_STEP(kAspWindowDelta, 9, 1, 50, false, 1);
TUNABLE_STEP(kAspWindowGrowth, 1.3924493383526235, 0.1, 2.0, false, 0.03);
TUNABLE(kAspWindowScoreDiv, 15811, 8192, 32768, false);
TUNABLE_STEP(kAspBetaLerpFactor, 0.4873257294370213, 0.0, 1.0, false, 0.1);

TUNABLE_STEP(kQsCutoffLerpFactor, 0.2816774262120891, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFailHighLerpFactor, 0.5860155336358017, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFutMargin, 171, 20, 300, false, 20);

TUNABLE(kEvalHistUpdateMult, 58, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 60, 5, 500, false);
TUNABLE(kEvalHistUpdateMax, 114, 5, 500, false);
TUNABLE_STEP(kEvalHistUpdateBias, 1, 0, 50, false, 5);

TUNABLE(kRevFutDepth, 11, 4, 10, true);
TUNABLE_STEP(kRevFutMargin, 51, 50, 150, false, 5);
TUNABLE_STEP(kRevFutImprovingMargin, 93, 20, 150, false, 5);
TUNABLE_STEP(kRevFutOppWorseningMargin, 24, 5, 70, false, 4);
TUNABLE_STEP(kRevFutMinMargin, 13, 5, 100, false, 10);
TUNABLE_STEP(kRevFutComplexityMargin, 10, 1, 64, false, 10);
TUNABLE_STEP(kRevFutLerpFactor, 0.5220459512916671, 0.0, 1.0, false, 0.05);
TUNABLE(kRevFutHistoryDiv, 578, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE_STEP(kRazoringMult, 394, 200, 600, false, 20);

TUNABLE_STEP(kNmpBetaBase, 146, 50, 200, false, 15);
TUNABLE_STEP(kNmpBetaMult, 5, 5, 50, false, 5);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 167, 100, 300, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE_STEP(kLmrDepthNonPvNode, 1263, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistQuiet, 1294, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthNotImproving, 1327, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthRoundingCutoff, 657, 512, 2048, false, 100);

TUNABLE(kLmpBase, 5, 1, 10, true);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE_STEP(kFutMarginBase, 135, 100, 250, false, 20);
TUNABLE_STEP(kFutMarginMult, 82, 50, 200, false, 5);
TUNABLE(kFutMarginHistDiv, 127, 32, 256, false);

TUNABLE(kSeeQuietThresh, -18, -150, -5, false);
TUNABLE(kSeeNoisyThresh, -102, -150, -5, false);
TUNABLE(kSeePruneHistDiv, 129, 50, 300, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -285, -1000, 500, false);
TUNABLE(kHistThreshMult, -2205, -3000, -500, false);
TUNABLE(kCaptHistThreshBase, -456, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1782, -3000, -1000, false);

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
TUNABLE_STEP(kSeTripleMargin, 56, 20, 250, false, 10);
TUNABLE_STEP(kSeDepthExtensionDepth, 13, 0, 20, false, 1);

TUNABLE_STEP(kLmrNonPvNode, 784, 512, 2048, false, 150);
TUNABLE_STEP(kLmrWasPvNode, 1194, 512, 2048, false, 150);
TUNABLE_STEP(kLmrCutNode, 2096, 1024, 4096, false, 150);
TUNABLE_STEP(kLmrGivesCheck, 980, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistQuiet, 544, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistCapture, 1152, 512, 2048, false, 150);
TUNABLE_STEP(kLmrNotImproving, 946, 512, 2048, false, 150);
TUNABLE_STEP(kLmrComplexity, 802, 512, 2048, false, 150);
TUNABLE_STEP(kLmrKillerMoves, 882, 512, 2048, false, 150);
TUNABLE_STEP(kLmrRoundingCutoff, 651, 512, 2048, false, 120);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 219, 50, 300, false);

TUNABLE_STEP(kHistoryBonusMargin, 48, 5, 120, false, 10);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H