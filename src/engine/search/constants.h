#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE_STEP(kLmrQuietBase, 0.8108281963087768, 0.5, 2.0, false, 0.08);
TUNABLE_STEP(kLmrQuietDiv, 2.00963684380911, 0.5, 3.0, false, 0.08);
TUNABLE_STEP(kLmrTactBase, -0.26539563743301553, -1.0, 0.5, false, 0.08);
TUNABLE_STEP(kLmrTactDiv, 2.7225202957220636, 1.0, 4.0, false, 0.08);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE(kAspWindowDelta, 8, 1, 50, false);
TUNABLE_STEP(kAspWindowGrowth, 1.4178369880005977, 0.1, 2.0, false, 0.08);

TUNABLE_STEP(kQsFutMargin, 106, 20, 300, false, 20);

TUNABLE(kEvalHistUpdateMult, 62, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 57, 5, 150, false);
TUNABLE(kEvalHistUpdateMax, 101, 40, 200, false);

TUNABLE(kRevFutDepth, 9, 4, 10, true);
TUNABLE(kRevFutMargin, 65, 50, 150, false);
TUNABLE(kRevFutOppWorseningMargin, 17, 5, 70, false);
TUNABLE(kRevFutMinMargin, 19, 5, 100, false);
TUNABLE_STEP(kRevFutLerpFactor, 0.4313712445065815, 0.0, 1.0, false, 0.05);
TUNABLE(kRevFutHistoryDiv, 543, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE(kRazoringMult, 433, 100, 700, false);

TUNABLE_STEP(kNmpBetaBase, 141, 50, 300, false, 15);
TUNABLE_STEP(kNmpBetaMult, 25, 5, 50, false, 5);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 174, 100, 300, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE_STEP(kLmrDepthNonPvNode, 1024, 512, 2048, false, 80);
TUNABLE_STEP(kLmrDepthHistQuiet, 1024, 512, 2048, false, 80);
TUNABLE_STEP(kLmrDepthHistCapture, 1024, 512, 2048, false, 80);
TUNABLE_STEP(kLmrDepthNotImproving, 1024, 512, 2048, false, 80);
TUNABLE_STEP(kLmrDepthRoundingCutoff, 512, 512, 2048, false, 20);

TUNABLE(kLmpBase, 5.0, 1.5, 5.0, true);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE(kFutMarginBase, 201, 100, 250, false);
TUNABLE(kFutMarginMult, 82, 50, 200, false);
TUNABLE(kFutMarginHistDiv, 137, 32, 256, false);

TUNABLE(kSeePruneDepth, 8, 6, 12, true);
TUNABLE(kSeeQuietThresh, -62, -200, -5, false);
TUNABLE(kSeeNoisyThresh, -112, -200, -5, false);
TUNABLE(kSeePruneHistDiv, 137, 50, 300, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -471, -1000, 500, false);
TUNABLE(kHistThreshMult, -2000, -3000, -500, false);
TUNABLE(kCaptHistThreshBase, -485, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1807, -3000, -1000, false);

TUNABLE(kLmrHistDiv, 11105, 5000, 15000, false);
TUNABLE(kLmrCaptHistDiv, 10468, 5000, 15000, false);
TUNABLE_STEP(kLmrComplexityDiff, 81, 5, 150, false, 7);

TUNABLE(kDoDeeperBase, 35, 10, 60, false);
TUNABLE(kDoShallowerBase, 5, 0, 30, false);

TUNABLE(kSeDepth, 5, 6, 12, true);
TUNABLE_STEP(kSeDepthReduction, 7, 0, 30, false, 1);
TUNABLE_STEP(kSeDoubleMargin, 11, 0, 50, false, 2);
TUNABLE_STEP(kSeTripleMargin, 81, 20, 250, false, 5);
TUNABLE_STEP(kSeDepthExtensionDepth, 11, 0, 20, false, 1);

TUNABLE_STEP(kLmrNonPvNode, 1024, 512, 2048, false, 80);
TUNABLE_STEP(kLmrWasPvNode, 1024, 512, 2048, false, 80);
TUNABLE_STEP(kLmrCutNode, 2048, 1024, 4096, false, 140);
TUNABLE_STEP(kLmrGivesCheck, 1024, 512, 2048, false, 80);
TUNABLE_STEP(kLmrHistQuiet, 1024, 512, 2048, false, 80);
TUNABLE_STEP(kLmrHistCapture, 1024, 512, 2048, false, 80);
TUNABLE_STEP(kLmrNotImproving, 1024, 512, 2048, false, 80);
TUNABLE_STEP(kLmrComplexity, 1024, 512, 2048, false, 80);
TUNABLE_STEP(kLmrKillerMoves, 1024, 512, 2048, false, 80);
TUNABLE_STEP(kLmrRoundingCutoff, 512, 512, 2048, false, 20);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 238, 50, 300, false);

TUNABLE_STEP(kHistoryBonusMargin, 49, 5, 120, false, 5);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H