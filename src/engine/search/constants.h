#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE_STEP(kLmrQuietBase, 0.8063094845260633, 0.5, 2.0, false, 0.08);
TUNABLE_STEP(kLmrQuietDiv, 2.078353397527477, 0.5, 3.0, false, 0.08);
TUNABLE_STEP(kLmrTactBase, -0.33350945606907545, -1.0, 0.5, false, 0.08);
TUNABLE_STEP(kLmrTactDiv, 2.8448331206156428, 1.0, 4.0, false, 0.08);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE_STEP(kAspWindowDelta, 10, 1, 50, false, 1);
TUNABLE_STEP(kAspWindowGrowth, 1.4003525447254221, 0.1, 2.0, false, 0.03);
TUNABLE(kAspWindowScoreDiv, 16329, 8192, 32768, false);
TUNABLE_STEP(kAspBetaLerpFactor, 0.4467693491928782, 0.0, 1.0, false, 0.1);

TUNABLE_STEP(kQsCutoffLerpFactor, 0.2830688935585512, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFailHighLerpFactor, 0.6104036092261454, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFutMargin, 176, 20, 300, false, 20);

TUNABLE(kEvalHistUpdateMult, 60, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 91, 5, 500, false);
TUNABLE(kEvalHistUpdateMax, 129, 5, 500, false);
TUNABLE_STEP(kEvalHistUpdateBias, 1, 0, 50, false, 5);

TUNABLE_STEP(kHindsightDepthReduction, 3891, 2048, 6144, false, 512);

TUNABLE(kRevFutDepth, 11, 4, 10, true);
TUNABLE_STEP(kRevFutMargin, 51, 50, 150, false, 5);
TUNABLE_STEP(kRevFutImprovingMargin, 96, 20, 150, false, 5);
TUNABLE_STEP(kRevFutOppEasyCaptureMargin, 91, 20, 150, false, 5);
TUNABLE_STEP(kRevFutOppWorseningMargin, 27, 5, 70, false, 4);
TUNABLE_STEP(kRevFutMinMargin, 9, 5, 100, false, 10);
TUNABLE_STEP(kRevFutComplexityMargin, 12, 1, 64, false, 10);
TUNABLE_STEP(kRevFutLerpFactor, 0.5180794520266747, 0.0, 1.0, false, 0.05);
TUNABLE(kRevFutHistoryDiv, 584, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE_STEP(kRazoringMult, 387, 200, 600, false, 20);
TUNABLE_STEP(kRazoringNotImproving, 406, 200, 600, false, 20);

TUNABLE_STEP(kNmpBetaBase, 143, 50, 200, false, 15);
TUNABLE_STEP(kNmpBetaMult, 7, 5, 50, false, 5);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 169, 100, 300, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE_STEP(kLmrDepthNonPvNode, 1231, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistQuiet, 1434, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthNotImproving, 1288, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthRoundingCutoff, 704, 512, 2048, false, 100);

TUNABLE_STEP(kLmpBase, 5133, 1024, 10240, false, 256);
TUNABLE_STEP(kLmpDepthMult, 1078, 512, 2048, false, 64);
TUNABLE_STEP(kLmpDiv, 3071, 2048, 4608, false, 128);
TUNABLE_STEP(kLmpImprovingDiv, 2009, 1024, 3584, false, 128);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE_STEP(kFutMarginBase, 130, 100, 250, false, 20);
TUNABLE_STEP(kFutMarginMult, 83, 50, 200, false, 5);
TUNABLE(kFutMarginHistDiv, 125, 32, 256, false);

TUNABLE(kSeeQuietThresh, -25, -150, -5, false);
TUNABLE(kSeeNoisyThresh, -98, -150, -5, false);
TUNABLE(kSeePruneHistDiv, 136, 50, 300, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -240, -1000, 500, false);
TUNABLE(kHistThreshMult, -2254, -3000, -500, false);
TUNABLE(kCaptHistThreshBase, -493, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1724, -3000, -1000, false);

TUNABLE(kLmrHistDiv, 11680, 5000, 15000, true);
TUNABLE(kLmrCaptHistDiv, 11008, 5000, 15000, true);
TUNABLE(kLmrComplexityDiff, 71, 5, 150, false);

TUNABLE(kDoDeeperBase, 29, 10, 60, false);
TUNABLE(kDoDeeperMult, 33, 16, 64, false);
TUNABLE(kDoShallowerBase, 6, 0, 50, false);

TUNABLE(kSeDepth, 5, 6, 12, true);
TUNABLE_STEP(kSeDepthReduction, 8, 0, 30, false, 1);
TUNABLE_STEP(kSeBetaMargin, 17, 0, 32, false, 1);
TUNABLE_STEP(kSeDoubleMargin, 8, 0, 50, false, 1);
TUNABLE_STEP(kSePvDoubleMargin, 152, 0, 300, false, 30);
TUNABLE_STEP(kSeTripleMargin, 58, 20, 250, false, 10);
TUNABLE_STEP(kSeDepthExtensionDepth, 13, 0, 20, false, 1);

TUNABLE_STEP(kLmrNonPvNode, 734, 512, 2048, false, 150);
TUNABLE_STEP(kLmrWasPvNode, 1211, 512, 2048, false, 150);
TUNABLE_STEP(kLmrCutNode, 2169, 1024, 4096, false, 150);
TUNABLE_STEP(kLmrGivesCheck, 936, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistQuiet, 578, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistCapture, 1223, 512, 2048, false, 150);
TUNABLE_STEP(kLmrNotImproving, 949, 512, 2048, false, 150);
TUNABLE_STEP(kLmrComplexity, 732, 512, 2048, false, 150);
TUNABLE_STEP(kLmrFirstKillerMove, 861, 512, 2048, false, 150);
TUNABLE_STEP(kLmrSecondKillerMove, 940, 512, 2048, false, 150);
TUNABLE_STEP(kLmrRoundingCutoff, 608, 512, 2048, false, 120);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 216, 50, 300, false);

TUNABLE_STEP(kHistoryBonusMargin, 44, 5, 120, false, 10);

TUNABLE_STEP(kPcmQuietHistoryWeight, 1051, 512, 2048, false, 128);
TUNABLE_STEP(kPcmPawnHistoryWeight, 492, 64, 2048, false, 64);

TUNABLE_STEP(kMaterialScaleBase, 27270, 10000, 32768, false, 500);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H