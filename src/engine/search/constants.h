#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE_STEP(kLmrQuietBase, 0.7905626808237769, 0.5, 2.0, false, 0.08);
TUNABLE_STEP(kLmrQuietDiv, 2.0862743339980825, 0.5, 3.0, false, 0.08);
TUNABLE_STEP(kLmrTactBase, -0.3441929579511405, -1.0, 0.5, false, 0.08);
TUNABLE_STEP(kLmrTactDiv, 2.837403015444838, 1.0, 4.0, false, 0.08);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE_STEP(kAspWindowDelta, 10, 1, 50, false, 1);
TUNABLE_STEP(kAspWindowGrowth, 1.395459040085034, 0.1, 2.0, false, 0.03);
TUNABLE(kAspWindowScoreDiv, 16293, 8192, 32768, false);
TUNABLE_STEP(kAspBetaLerpFactor, 0.43994988989154704, 0.0, 1.0, false, 0.1);

TUNABLE_STEP(kQsCutoffLerpFactor, 0.2667442459922317, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFailHighLerpFactor, 0.6151206628276835, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFutMargin, 174, 20, 300, false, 20);

TUNABLE(kEvalHistUpdateMult, 59, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 88, 5, 500, false);
TUNABLE(kEvalHistUpdateMax, 129, 5, 500, false);
TUNABLE_STEP(kEvalHistUpdateBias, 1, 0, 50, false, 5);

TUNABLE_STEP(kHindsightDepthReduction, 3875, 2048, 6144, false, 512);

TUNABLE(kRevFutDepth, 11, 4, 10, true);
TUNABLE_STEP(kRevFutMargin, 51, 50, 150, false, 5);
TUNABLE_STEP(kRevFutImprovingMargin, 95, 20, 150, false, 5);
TUNABLE_STEP(kRevFutOppEasyCaptureMargin, 92, 20, 150, false, 5);
TUNABLE_STEP(kRevFutOppWorseningMargin, 27, 5, 70, false, 4);
TUNABLE_STEP(kRevFutMinMargin, 7, 5, 100, false, 10);
TUNABLE_STEP(kRevFutComplexityMargin, 11, 1, 64, false, 10);
TUNABLE_STEP(kRevFutLerpFactor, 0.52853018762059, 0.0, 1.0, false, 0.05);
TUNABLE(kRevFutHistoryDiv, 590, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE_STEP(kRazoringMult, 392, 200, 600, false, 20);
TUNABLE_STEP(kRazoringNotImproving, 406, 200, 600, false, 20);

TUNABLE_STEP(kNmpBetaBase, 140, 50, 200, false, 15);
TUNABLE_STEP(kNmpBetaMult, 6, 5, 50, false, 5);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 171, 100, 300, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE_STEP(kLmrDepthNonPvNode, 1253, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistQuiet, 1425, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthNotImproving, 1318, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthRoundingCutoff, 697, 512, 2048, false, 100);

TUNABLE_STEP(kLmpBase, 5145, 1024, 10240, false, 256);
TUNABLE_STEP(kLmpDepthMult, 1073, 512, 2048, false, 64);
TUNABLE_STEP(kLmpDiv, 3057, 2048, 4608, false, 128);
TUNABLE_STEP(kLmpImprovingDiv, 2004, 1024, 3584, false, 128);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE_STEP(kFutMarginBase, 130, 100, 250, false, 20);
TUNABLE_STEP(kFutMarginMult, 83, 50, 200, false, 5);
TUNABLE(kFutMarginHistDiv, 126, 32, 256, false);

TUNABLE(kSeeQuietThresh, -23, -150, -5, false);
TUNABLE(kSeeNoisyThresh, -100, -150, -5, false);
TUNABLE(kSeePruneHistDiv, 137, 50, 300, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -243, -1000, 500, false);
TUNABLE(kHistThreshMult, -2253, -3000, -500, false);
TUNABLE(kCaptHistThreshBase, -498, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1736, -3000, -1000, false);

TUNABLE(kLmrHistDiv, 11680, 5000, 15000, true);
TUNABLE(kLmrCaptHistDiv, 11008, 5000, 15000, true);
TUNABLE(kLmrComplexityDiff, 72, 5, 150, false);

TUNABLE(kDoDeeperBase, 28, 10, 60, false);
TUNABLE(kDoDeeperMult, 33, 16, 64, false);
TUNABLE(kDoShallowerBase, 6, 0, 50, false);

TUNABLE(kSeDepth, 5, 6, 12, true);
TUNABLE_STEP(kSeDepthReduction, 7, 0, 30, false, 1);
TUNABLE_STEP(kSeBetaMargin, 17, 0, 32, false, 1);
TUNABLE_STEP(kSeDoubleMargin, 8, 0, 50, false, 1);
TUNABLE_STEP(kSePvDoubleMargin, 150, 0, 300, false, 30);
TUNABLE_STEP(kSeTripleMargin, 57, 20, 250, false, 10);
TUNABLE_STEP(kSeDepthExtensionDepth, 13, 0, 20, false, 1);

TUNABLE_STEP(kLmrNonPvNode, 749, 512, 2048, false, 150);
TUNABLE_STEP(kLmrWasPvNode, 1216, 512, 2048, false, 150);
TUNABLE_STEP(kLmrCutNode, 2186, 1024, 4096, false, 150);
TUNABLE_STEP(kLmrGivesCheck, 919, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistQuiet, 568, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistCapture, 1235, 512, 2048, false, 150);
TUNABLE_STEP(kLmrNotImproving, 932, 512, 2048, false, 150);
TUNABLE_STEP(kLmrComplexity, 740, 512, 2048, false, 150);
TUNABLE_STEP(kLmrFirstKillerMove, 834, 512, 2048, false, 150);
TUNABLE_STEP(kLmrSecondKillerMove, 922, 512, 2048, false, 150);
TUNABLE_STEP(kLmrRoundingCutoff, 630, 512, 2048, false, 120);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 214, 50, 300, false);

TUNABLE_STEP(kHistoryBonusMargin, 44, 5, 120, false, 10);

TUNABLE_STEP(kPcmQuietHistoryWeight, 1050, 512, 2048, false, 128);
TUNABLE_STEP(kPcmPawnHistoryWeight, 489, 64, 2048, false, 64);

TUNABLE_STEP(kMaterialScaleBase, 27347, 10000, 32768, false, 500);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H