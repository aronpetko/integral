#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE_STEP(kLmrQuietBase, 0.8079015956613906, 0.5, 2.0, false, 0.08);
TUNABLE_STEP(kLmrQuietDiv, 2.0879792555907377, 0.5, 3.0, false, 0.08);
TUNABLE_STEP(kLmrTactBase, -0.3560780424392481, -1.0, 0.5, false, 0.08);
TUNABLE_STEP(kLmrTactDiv, 2.8577651171311933, 1.0, 4.0, false, 0.08);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE_STEP(kAspWindowDelta, 10, 1, 50, false, 1);
TUNABLE_STEP(kAspWindowGrowth, 1.4129554553311214, 0.1, 2.0, false, 0.03);
TUNABLE(kAspWindowScoreDiv, 16231, 8192, 32768, false);
TUNABLE_STEP(kAspBetaLerpFactor, 0.4505472272357914, 0.0, 1.0, false, 0.1);

TUNABLE_STEP(kQsCutoffLerpFactor, 0.2932957054448457, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFailHighLerpFactor, 0.6300545749125233, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFutMargin, 183, 20, 300, false, 20);

TUNABLE(kEvalHistUpdateMult, 60, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 100, 5, 500, false);
TUNABLE(kEvalHistUpdateMax, 132, 5, 500, false);
TUNABLE_STEP(kEvalHistUpdateBias, 0, 0, 50, false, 5);

TUNABLE_STEP(kHindsightDepthReduction, 4002, 2048, 6144, false, 512);

TUNABLE(kRevFutDepth, 11, 4, 10, true);
TUNABLE_STEP(kRevFutMargin, 52, 50, 150, false, 5);
TUNABLE_STEP(kRevFutImprovingMargin, 94, 20, 150, false, 5);
TUNABLE_STEP(kRevFutOppEasyCaptureMargin, 90, 20, 150, false, 5);
TUNABLE_STEP(kRevFutOppWorseningMargin, 27, 5, 70, false, 4);
TUNABLE_STEP(kRevFutMinMargin, 10, 5, 100, false, 10);
TUNABLE_STEP(kRevFutComplexityMargin, 10, 1, 64, false, 10);
TUNABLE_STEP(kRevFutLerpFactor, 0.5379183246024984, 0.0, 1.0, false, 0.05);
TUNABLE(kRevFutHistoryDiv, 596, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE_STEP(kRazoringMult, 386, 200, 600, false, 20);
TUNABLE_STEP(kRazoringNotImproving, 415, 200, 600, false, 20);

TUNABLE_STEP(kNmpBetaBase, 151, 50, 200, false, 15);
TUNABLE_STEP(kNmpBetaMult, 7, 5, 50, false, 5);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 171, 100, 300, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE_STEP(kLmrDepthNonPvNode, 1213, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistQuiet, 1464, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthNotImproving, 1318, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthRoundingCutoff, 739, 512, 2048, false, 100);

TUNABLE_STEP(kLmpBase, 5244, 1024, 10240, false, 256);
TUNABLE_STEP(kLmpDepthMult, 1104, 512, 2048, false, 64);
TUNABLE_STEP(kLmpDiv, 3019, 2048, 4608, false, 128);
TUNABLE_STEP(kLmpImprovingDiv, 1991, 1024, 3584, false, 128);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE_STEP(kFutMarginBase, 136, 100, 250, false, 20);
TUNABLE_STEP(kFutMarginMult, 83, 50, 200, false, 5);
TUNABLE(kFutMarginHistDiv, 124, 32, 256, false);

TUNABLE(kSeeQuietThresh, -26, -150, -5, false);
TUNABLE(kSeeNoisyThresh, -95, -150, -5, false);
TUNABLE(kSeePruneHistDiv, 138, 50, 300, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -238, -1000, 500, false);
TUNABLE(kHistThreshMult, -2211, -3000, -500, false);
TUNABLE(kCaptHistThreshBase, -482, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1720, -3000, -1000, false);

TUNABLE(kLmrHistDiv, 11680, 5000, 15000, true);
TUNABLE(kLmrCaptHistDiv, 11008, 5000, 15000, true);
TUNABLE(kLmrComplexityDiff, 70, 5, 150, false);

TUNABLE(kDoDeeperBase, 29, 10, 60, false);
TUNABLE(kDoDeeperMult, 33, 16, 64, false);
TUNABLE(kDoShallowerBase, 6, 0, 50, false);

TUNABLE(kSeDepth, 5, 6, 12, true);
TUNABLE_STEP(kSeDepthReduction, 7, 0, 30, false, 1);
TUNABLE_STEP(kSeBetaMargin, 17, 0, 32, false, 1);
TUNABLE_STEP(kSeDoubleMargin, 8, 0, 50, false, 1);
TUNABLE_STEP(kSePvDoubleMargin, 128, 0, 300, false, 30);
TUNABLE_STEP(kSeTripleMargin, 55, 20, 250, false, 10);
TUNABLE_STEP(kSeDepthExtensionDepth, 13, 0, 20, false, 1);

TUNABLE_STEP(kLmrNonPvNode, 676, 512, 2048, false, 150);
TUNABLE_STEP(kLmrWasPvNode, 1228, 512, 2048, false, 150);
TUNABLE_STEP(kLmrCutNode, 2175, 1024, 4096, false, 150);
TUNABLE_STEP(kLmrGivesCheck, 939, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistQuiet, 698, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistCapture, 1243, 512, 2048, false, 150);
TUNABLE_STEP(kLmrNotImproving, 906, 512, 2048, false, 150);
TUNABLE_STEP(kLmrComplexity, 715, 512, 2048, false, 150);
TUNABLE_STEP(kLmrFirstKillerMove, 891, 512, 2048, false, 150);
TUNABLE_STEP(kLmrSecondKillerMove, 917, 512, 2048, false, 150);
TUNABLE_STEP(kLmrRoundingCutoff, 582, 512, 2048, false, 120);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 213, 50, 300, false);

TUNABLE_STEP(kHistoryBonusMargin, 44, 5, 120, false, 10);

TUNABLE_STEP(kPcmQuietHistoryWeight, 1059, 512, 2048, false, 128);
TUNABLE_STEP(kPcmPawnHistoryWeight, 485, 64, 2048, false, 64);

TUNABLE_STEP(kMaterialScaleBase, 27258, 10000, 32768, false, 500);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H