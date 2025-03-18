#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE_STEP(kLmrQuietBase, 0.8444300480772196, 0.5, 2.0, false, 0.08);
TUNABLE_STEP(kLmrQuietDiv, 2.0420124302769884, 0.5, 3.0, false, 0.08);
TUNABLE_STEP(kLmrTactBase, -0.26745378404236414, -1.0, 0.5, false, 0.08);
TUNABLE_STEP(kLmrTactDiv, 2.7361574676697047, 1.0, 4.0, false, 0.08);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE(kAspWindowDelta, 7, 1, 50, false);
TUNABLE_STEP(kAspWindowGrowth, 1.3944681232281486, 0.1, 2.0, false, 0.08);

TUNABLE_STEP(kQsCutoffLerpFactor, 0.5, 0.0, 1.0, false, 0.05);
TUNABLE_STEP(kQsFutMargin, 134, 20, 300, false, 20);

TUNABLE(kEvalHistUpdateMult, 61, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 100, 5, 150, false);
TUNABLE(kEvalHistUpdateMax, 200, 40, 200, false);

TUNABLE(kRevFutDepth, 9, 4, 10, true);
TUNABLE(kRevFutMargin, 58, 50, 150, false);
TUNABLE(kRevFutOppWorseningMargin, 18, 5, 70, false);
TUNABLE(kRevFutMinMargin, 18, 5, 100, false);
TUNABLE_STEP(kRevFutLerpFactor, 0.4682519438648439, 0.0, 1.0, false, 0.05);
TUNABLE(kRevFutHistoryDiv, 564, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE(kRazoringMult, 406, 100, 700, false);

TUNABLE_STEP(kNmpBetaBase, 150, 50, 300, false, 15);
TUNABLE_STEP(kNmpBetaMult, 16, 5, 50, false, 5);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 171, 100, 300, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE_STEP(kLmrDepthNonPvNode, 1049, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistQuiet, 1091, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistCapture, 1011, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthNotImproving, 1097, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthRoundingCutoff, 616, 512, 2048, false, 150);

TUNABLE(kLmpBase, 5.0, 1.5, 5.0, true);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE_STEP(kFutMarginBase, 198, 100, 250, false, 15);
TUNABLE_STEP(kFutMarginMult, 83, 50, 200, false, 5);
TUNABLE(kFutMarginHistDiv, 137, 32, 256, false);

TUNABLE(kSeePruneDepth, 8, 6, 12, true);
TUNABLE(kSeeQuietThresh, -57, -150, -5, false);
TUNABLE(kSeeNoisyThresh, -114, -150, -5, false);
TUNABLE(kSeePruneHistDiv, 124, 50, 300, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -434, -1000, 500, false);
TUNABLE(kHistThreshMult, -2012, -3000, -500, false);
TUNABLE(kCaptHistThreshBase, -527, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1831, -3000, -1000, false);

TUNABLE(kLmrHistDiv, 11333, 5000, 15000, false);
TUNABLE(kLmrCaptHistDiv, 10932, 5000, 15000, false);
TUNABLE_STEP(kLmrComplexityDiff, 73, 5, 150, false, 7);

TUNABLE_STEP(kDoDeeperBase, 33, 10, 60, false, 3);
TUNABLE_STEP(kDoShallowerBase, 4, 0, 30, false, 2);

TUNABLE(kSeDepth, 5, 6, 12, true);
TUNABLE_STEP(kSeDepthReduction, 7, 0, 30, false, 1);
TUNABLE_STEP(kSeDoubleMargin, 8, 0, 50, false, 2);
TUNABLE_STEP(kSeTripleMargin, 67, 20, 250, false, 10);
TUNABLE_STEP(kSeDepthExtensionDepth, 10, 0, 20, false, 1);

TUNABLE_STEP(kLmrNonPvNode, 993, 512, 2048, false, 150);
TUNABLE_STEP(kLmrWasPvNode, 1070, 512, 2048, false, 150);
TUNABLE_STEP(kLmrCutNode, 2021, 1024, 4096, false, 300);
TUNABLE_STEP(kLmrGivesCheck, 1042, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistQuiet, 962, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistCapture, 1142, 512, 2048, false, 150);
TUNABLE_STEP(kLmrNotImproving, 1003, 512, 2048, false, 150);
TUNABLE_STEP(kLmrComplexity, 1032, 512, 2048, false, 150);
TUNABLE_STEP(kLmrKillerMoves, 1028, 512, 2048, false, 150);
TUNABLE_STEP(kLmrRoundingCutoff, 627, 512, 2048, false, 120);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 235, 50, 300, false);

TUNABLE_STEP(kHistoryBonusMargin, 49, 5, 120, false, 5);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H