#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE_STEP(kLmrQuietBase, 0.8099734297235842, 0.5, 2.0, false, 0.08);
TUNABLE_STEP(kLmrQuietDiv, 2.038326671103524, 0.5, 3.0, false, 0.08);
TUNABLE_STEP(kLmrTactBase, -0.3259712307920091, -1.0, 0.5, false, 0.08);
TUNABLE_STEP(kLmrTactDiv, 2.7198221836303045, 1.0, 4.0, false, 0.08);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE(kAspWindowDelta, 9, 1, 50, false);
TUNABLE_STEP(kAspWindowGrowth, 1.430474556393298, 0.1, 2.0, false, 0.08);

TUNABLE_STEP(kQsFutMargin, 120, 20, 300, false, 20);

TUNABLE(kEvalHistUpdateMult, 62, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 56, 5, 150, false);
TUNABLE(kEvalHistUpdateMax, 103, 40, 200, false);

TUNABLE(kRevFutDepth, 9, 4, 10, true);
TUNABLE(kRevFutMargin, 56, 50, 150, false);
TUNABLE(kRevFutOppWorseningMargin, 15, 5, 70, false);
TUNABLE(kRevFutMinMargin, 16, 5, 100, false);
TUNABLE_STEP(kRevFutLerpFactor, 0.4452380324221953, 0.0, 1.0, false, 0.05);
TUNABLE(kRevFutHistoryDiv, 562, 200, 1000, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE(kRazoringMult, 426, 100, 700, false);

TUNABLE_STEP(kNmpBetaBase, 154, 50, 300, false, 15);
TUNABLE_STEP(kNmpBetaMult, 25, 5, 50, false, 5);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 178, 100, 400, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE_STEP(kLmrDepthNonPvNode, 1015, 512, 2048, false, 204);
TUNABLE_STEP(kLmrDepthHistQuiet, 1066, 512, 2048, false, 204);
TUNABLE_STEP(kLmrDepthHistCapture, 1096, 512, 2048, false, 204);
TUNABLE_STEP(kLmrDepthNotImproving, 1247, 512, 2048, false, 204);
TUNABLE_STEP(kLmrDepthRoundingCutoff, 677, 512, 2048, false, 204);

TUNABLE(kLmpBase, 5.0, 1.5, 5.0, true);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE(kFutMarginBase, 205, 100, 250, false);
TUNABLE(kFutMarginMult, 81, 50, 200, false);
TUNABLE(kFutMarginHistDiv, 143, 32, 256, false);

TUNABLE(kSeePruneDepth, 8, 6, 12, true);
TUNABLE(kSeeQuietThresh, -59, -200, -5, false);
TUNABLE(kSeeNoisyThresh, -105, -200, -5, false);
TUNABLE(kSeePruneHistDiv, 125, 5, 500, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -489, -1000, 500, false);
TUNABLE(kHistThreshMult, -2169, -3000, -250, false);
TUNABLE(kCaptHistThreshBase, -501, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1816, -3000, -250, false);

TUNABLE(kLmrHistDiv, 11504, 5000, 20000, false);
TUNABLE(kLmrCaptHistDiv, 11379, 5000, 20000, false);
TUNABLE_STEP(kLmrComplexityDiff, 74, 5, 150, false, 15);

TUNABLE(kDoDeeperBase, 36, 5, 70, false);
TUNABLE(kDoShallowerBase, 5, 0, 30, false);

TUNABLE(kSeDepth, 5, 6, 12, true);
TUNABLE(kSeDepthReduction, 8, 0, 30, false);
TUNABLE(kSeDoubleMargin, 8, 0, 50, false);
TUNABLE(kSeTripleMargin, 74, 20, 250, false);
TUNABLE(kSeDepthExtensionDepth, 11, 0, 20, false);

TUNABLE_STEP(kLmrNonPvNode, 1023, 512, 2048, false, 102);
TUNABLE_STEP(kLmrWasPvNode, 1035, 512, 2048, false, 102);
TUNABLE_STEP(kLmrCutNode, 2011, 1024, 4096, false, 204);
TUNABLE_STEP(kLmrGivesCheck, 1044, 512, 2048, false, 102);
TUNABLE_STEP(kLmrHistQuiet, 1052, 512, 2048, false, 102);
TUNABLE_STEP(kLmrHistCapture, 984, 512, 2048, false, 102);
TUNABLE_STEP(kLmrNotImproving, 1058, 512, 2048, false, 102);
TUNABLE_STEP(kLmrComplexity, 1012, 512, 2048, false, 102);
TUNABLE_STEP(kLmrKillerMoves, 1080, 512, 2048, false, 102);
TUNABLE_STEP(kLmrRoundingCutoff, 569, 512, 2048, false, 102);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 243, 50, 400, false);

TUNABLE(kHistoryBonusMargin, 43, 5, 200, false);

TUNABLE_STEP(kFiftyMoveRuleBase, 211, 150, 220, false, 18);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H