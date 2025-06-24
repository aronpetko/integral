#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE_STEP(kLmrQuietBase, 0.8480882955595078, 0.5, 2.0, false, 0.08);
TUNABLE_STEP(kLmrQuietDiv, 2.081673155142633, 0.5, 3.0, false, 0.08);
TUNABLE_STEP(kLmrTactBase, -0.28654078465717797, -1.0, 0.5, false, 0.08);
TUNABLE_STEP(kLmrTactDiv, 2.81656413812439, 1.0, 4.0, false, 0.08);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE_STEP(kAspWindowDelta, 9, 1, 50, false, 1);
TUNABLE_STEP(kAspWindowGrowth, 1.4059365733780913, 0.1, 2.0, false, 0.03);
TUNABLE(kAspWindowScoreDiv, 16176, 8192, 32768, false);
TUNABLE_STEP(kAspBetaLerpFactor, 0.48837473492636696, 0.0, 1.0, false, 0.1);

TUNABLE_STEP(kQsCutoffLerpFactor, 0.3625354895273262, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFailHighLerpFactor, 0.5777391111317516, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFutMargin, 156, 20, 300, false, 20);

TUNABLE(kEvalHistUpdateMult, 60, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 500, 5, 500, false);
TUNABLE(kEvalHistUpdateMax, 500, 5, 500, false);
TUNABLE_STEP(kEvalHistUpdateBias, 1, 0, 50, false, 5);

TUNABLE(kRevFutDepth, 9, 4, 10, true);
TUNABLE_STEP(kRevFutMargin, 51, 50, 150, false, 5);
TUNABLE_STEP(kRevFutImprovingMargin, 92, 20, 150, false, 5);
TUNABLE_STEP(kRevFutOppWorseningMargin, 24, 5, 70, false, 4);
TUNABLE_STEP(kRevFutMinMargin, 16, 5, 100, false, 10);
TUNABLE_STEP(kRevFutLerpFactor, 0.49231300185302573, 0.0, 1.0, false, 0.05);
TUNABLE(kRevFutHistoryDiv, 584, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE_STEP(kRazoringMult, 405, 200, 600, false, 20);

TUNABLE_STEP(kNmpBetaBase, 137, 50, 200, false, 15);
TUNABLE_STEP(kNmpBetaMult, 7, 5, 50, false, 5);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 165, 100, 300, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE_STEP(kLmrDepthNonPvNode, 1222, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistQuiet, 1295, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthNotImproving, 1263, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthRoundingCutoff, 537, 512, 2048, false, 100);

TUNABLE(kLmpBase, 5, 1, 10, true);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE_STEP(kFutMarginBase, 157, 100, 250, false, 20);
TUNABLE_STEP(kFutMarginMult, 82, 50, 200, false, 5);
TUNABLE(kFutMarginHistDiv, 135, 32, 256, false);

TUNABLE(kSeeQuietThresh, -19, -150, -5, false);
TUNABLE(kSeeNoisyThresh, -104, -150, -5, false);
TUNABLE(kSeePruneHistDiv, 136, 50, 300, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -311, -1000, 500, false);
TUNABLE(kHistThreshMult, -2211, -3000, -500, false);
TUNABLE(kCaptHistThreshBase, -453, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1774, -3000, -1000, false);

TUNABLE(kLmrHistDiv, 11680, 5000, 15000, true);
TUNABLE(kLmrCaptHistDiv, 11008, 5000, 15000, true);
TUNABLE(kLmrComplexityDiff, 73, 5, 150, false);

TUNABLE(kDoDeeperBase, 31, 10, 60, false);
TUNABLE(kDoDeeperMult, 33, 16, 64, false);
TUNABLE(kDoShallowerBase, 6, 0, 50, false);

TUNABLE(kSeDepth, 5, 6, 12, true);
TUNABLE_STEP(kSeDepthReduction, 7, 0, 30, false, 1);
TUNABLE_STEP(kSeBetaMargin, 17, 0, 32, false, 1);
TUNABLE_STEP(kSeDoubleMargin, 8, 0, 50, false, 1);
TUNABLE_STEP(kSeTripleMargin, 56, 20, 250, false, 10);
TUNABLE_STEP(kSeDepthExtensionDepth, 12, 0, 20, false, 1);

TUNABLE_STEP(kLmrNonPvNode, 815, 512, 2048, false, 150);
TUNABLE_STEP(kLmrWasPvNode, 1099, 512, 2048, false, 150);
TUNABLE_STEP(kLmrCutNode, 2172, 1024, 4096, false, 150);
TUNABLE_STEP(kLmrGivesCheck, 961, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistQuiet, 581, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistCapture, 1194, 512, 2048, false, 150);
TUNABLE_STEP(kLmrNotImproving, 964, 512, 2048, false, 150);
TUNABLE_STEP(kLmrComplexity, 796, 512, 2048, false, 150);
TUNABLE_STEP(kLmrKillerMoves, 910, 512, 2048, false, 150);
TUNABLE_STEP(kLmrRoundingCutoff, 621, 512, 2048, false, 120);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 219, 50, 300, false);

TUNABLE_STEP(kHistoryBonusMargin, 48, 5, 120, false, 10);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H