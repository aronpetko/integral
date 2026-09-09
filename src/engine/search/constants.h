#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE_STEP(kLmrQuietBase, 0.8008544368599553, 0.5, 2.0, false, 0.08);
TUNABLE_STEP(kLmrQuietDiv, 2.0904841365109514, 0.5, 3.0, false, 0.08);
TUNABLE_STEP(kLmrTactBase, -0.36540611838567605, -1.0, 0.5, false, 0.08);
TUNABLE_STEP(kLmrTactDiv, 2.8466417892889955, 1.0, 4.0, false, 0.08);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE_STEP(kAspWindowDelta, 10, 1, 50, false, 1);
TUNABLE_STEP(kAspWindowGrowth, 1.4125521546512148, 0.1, 2.0, false, 0.03);
TUNABLE(kAspWindowScoreDiv, 15954, 8192, 32768, false);
TUNABLE_STEP(kAspBetaLerpFactor, 0.4497698475419262, 0.0, 1.0, false, 0.1);

TUNABLE_STEP(kQsCutoffLerpFactor, 0.27196366541910993, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFailHighLerpFactor, 0.6322486926656458, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFutMargin, 186, 20, 300, false, 20);

TUNABLE(kEvalHistUpdateMult, 60, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 98, 5, 500, false);
TUNABLE(kEvalHistUpdateMax, 125, 5, 500, false);
TUNABLE_STEP(kEvalHistUpdateBias, 1, 0, 50, false, 5);

TUNABLE_STEP(kHindsightDepthReduction, 4023, 2048, 6144, false, 512);

TUNABLE(kRevFutDepth, 11, 4, 10, true);
TUNABLE_STEP(kRevFutMargin, 50, 50, 150, false, 5);
TUNABLE_STEP(kRevFutImprovingMargin, 95, 20, 150, false, 5);
TUNABLE_STEP(kRevFutOppEasyCaptureMargin, 89, 20, 150, false, 5);
TUNABLE_STEP(kRevFutOppWorseningMargin, 28, 5, 70, false, 4);
TUNABLE_STEP(kRevFutMinMargin, 9, 5, 100, false, 10);
TUNABLE_STEP(kRevFutComplexityMargin, 10, 1, 64, false, 10);
TUNABLE_STEP(kRevFutLerpFactor, 0.5434916956888157, 0.0, 1.0, false, 0.05);
TUNABLE(kRevFutHistoryDiv, 605, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE_STEP(kRazoringMult, 392, 200, 600, false, 20);
TUNABLE_STEP(kRazoringNotImproving, 415, 200, 600, false, 20);

TUNABLE_STEP(kNmpBetaBase, 152, 50, 200, false, 15);
TUNABLE_STEP(kNmpBetaMult, 7, 5, 50, false, 5);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 171, 100, 300, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE_STEP(kLmrDepthNonPvNode, 1230, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistQuiet, 1533, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthNotImproving, 1356, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthRoundingCutoff, 745, 512, 2048, false, 100);

TUNABLE_STEP(kLmpBase, 5293, 1024, 10240, false, 256);
TUNABLE_STEP(kLmpDepthMult, 1111, 512, 2048, false, 64);
TUNABLE_STEP(kLmpDiv, 3015, 2048, 4608, false, 128);
TUNABLE_STEP(kLmpImprovingDiv, 1991, 1024, 3584, false, 128);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE_STEP(kFutMarginBase, 132, 100, 250, false, 20);
TUNABLE_STEP(kFutMarginMult, 83, 50, 200, false, 5);
TUNABLE(kFutMarginHistDiv, 124, 32, 256, false);

TUNABLE(kSeeQuietThresh, -27, -150, -5, false);
TUNABLE(kSeeNoisyThresh, -94, -150, -5, false);
TUNABLE(kSeePruneHistDiv, 138, 50, 300, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -229, -1000, 500, false);
TUNABLE(kHistThreshMult, -2192, -3000, -500, false);
TUNABLE(kCaptHistThreshBase, -492, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1733, -3000, -1000, false);

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
TUNABLE_STEP(kSePvDoubleMargin, 137, 0, 300, false, 30);
TUNABLE_STEP(kSeTripleMargin, 54, 20, 250, false, 10);
TUNABLE_STEP(kSeDepthExtensionDepth, 13, 0, 20, false, 1);

TUNABLE_STEP(kLmrNonPvNode, 627, 512, 2048, false, 150);
TUNABLE_STEP(kLmrWasPvNode, 1225, 512, 2048, false, 150);
TUNABLE_STEP(kLmrCutNode, 2212, 1024, 4096, false, 150);
TUNABLE_STEP(kLmrGivesCheck, 927, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistQuiet, 710, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistCapture, 1202, 512, 2048, false, 150);
TUNABLE_STEP(kLmrNotImproving, 937, 512, 2048, false, 150);
TUNABLE_STEP(kLmrComplexity, 692, 512, 2048, false, 150);
TUNABLE_STEP(kLmrFirstKillerMove, 861, 512, 2048, false, 150);
TUNABLE_STEP(kLmrSecondKillerMove, 952, 512, 2048, false, 150);
TUNABLE_STEP(kLmrRoundingCutoff, 574, 512, 2048, false, 120);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 216, 50, 300, false);

TUNABLE_STEP(kHistoryBonusMargin, 45, 5, 120, false, 10);

TUNABLE_STEP(kPcmQuietHistoryWeight, 1041, 512, 2048, false, 128);
TUNABLE_STEP(kPcmPawnHistoryWeight, 498, 64, 2048, false, 64);

TUNABLE_STEP(kMaterialScaleBase, 27141, 10000, 32768, false, 500);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H