#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE_STEP(kLmrQuietBase, 0.8410611347217376, 0.5, 2.0, false, 0.08);
TUNABLE_STEP(kLmrQuietDiv, 2.085938890150865, 0.5, 3.0, false, 0.08);
TUNABLE_STEP(kLmrTactBase, -0.24046113908296288, -1.0, 0.5, false, 0.08);
TUNABLE_STEP(kLmrTactDiv, 2.7996550273509775, 1.0, 4.0, false, 0.08);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE_STEP(kAspWindowDelta, 8, 1, 50, false, 1);
TUNABLE_STEP(kAspWindowGrowth, 1.3968181632525003, 0.1, 2.0, false, 0.03);

TUNABLE_STEP(kQsCutoffLerpFactor, 0.46762757125234183, 0.0, 1.0, false, 0.1);
TUNABLE_STEP(kQsFutMargin, 156, 20, 300, false, 20);

TUNABLE(kEvalHistUpdateMult, 63, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 52, 5, 150, false);
TUNABLE(kEvalHistUpdateMax, 104, 40, 200, false);

TUNABLE(kRevFutDepth, 9, 4, 10, true);
TUNABLE_STEP(kRevFutMargin, 55, 50, 150, false, 5);
TUNABLE_STEP(kRevFutImprovingMargin, 89, 20, 150, false, 5);
TUNABLE_STEP(kRevFutOppWorseningMargin, 22, 5, 70, false, 4);
TUNABLE_STEP(kRevFutMinMargin, 18, 5, 100, false, 10);
TUNABLE_STEP(kRevFutLerpFactor, 0.45663928931436193, 0.0, 1.0, false, 0.05);
TUNABLE(kRevFutHistoryDiv, 580, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE_STEP(kRazoringMult, 399, 100, 700, false, 20);

TUNABLE_STEP(kNmpBetaBase, 143, 50, 300, false, 15);
TUNABLE_STEP(kNmpBetaMult, 13, 5, 50, false, 5);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 163, 100, 300, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE_STEP(kLmrDepthNonPvNode, 1176, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistQuiet, 1189, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthHistCapture, 1011, 512, 2048, true, 150);
TUNABLE_STEP(kLmrDepthNotImproving, 1224, 512, 2048, false, 150);
TUNABLE_STEP(kLmrDepthRoundingCutoff, 610, 512, 2048, false, 100);

TUNABLE(kLmpBase, 5.0, 1.5, 5.0, true);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE_STEP(kFutMarginBase, 188, 100, 250, false, 20);
TUNABLE_STEP(kFutMarginMult, 85, 50, 200, false, 5);
TUNABLE(kFutMarginHistDiv, 142, 32, 256, false);

TUNABLE(kBadNoisyFutPruneDepth, 5, 6, 12, true);
TUNABLE_STEP(kBadNoisyFutMargin, 180, 100, 250, false, 20);

TUNABLE(kSeeQuietThresh, -58, -150, -5, false);
TUNABLE(kSeeNoisyThresh, -105, -150, -5, false);
TUNABLE(kSeePruneHistDiv, 136, 50, 300, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -387, -1000, 500, false);
TUNABLE(kHistThreshMult, -2064, -3000, -500, false);
TUNABLE(kCaptHistThreshBase, -535, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1780, -3000, -1000, false);

TUNABLE(kLmrHistDiv, 11333, 5000, 15000, false);
TUNABLE(kLmrCaptHistDiv, 11141, 5000, 15000, false);
TUNABLE_STEP(kLmrComplexityDiff, 74, 5, 150, false, 7);

TUNABLE_STEP(kDoDeeperBase, 31, 10, 60, false, 3);
TUNABLE_STEP(kDoShallowerBase, 5, 0, 30, false, 2);

TUNABLE(kSeDepth, 5, 6, 12, true);
TUNABLE_STEP(kSeDepthReduction, 7, 0, 30, false, 1);
TUNABLE_STEP(kSeBetaMargin, 17, 0, 32, false, 1);
TUNABLE_STEP(kSeDoubleMargin, 8, 0, 50, false, 1);
TUNABLE_STEP(kSeTripleMargin, 65, 20, 250, false, 10);
TUNABLE_STEP(kSeDepthExtensionDepth, 11, 0, 20, false, 1);

TUNABLE_STEP(kLmrNonPvNode, 919, 512, 2048, false, 150);
TUNABLE_STEP(kLmrWasPvNode, 1155, 512, 2048, false, 150);
TUNABLE_STEP(kLmrCutNode, 2164, 1024, 4096, false, 300);
TUNABLE_STEP(kLmrGivesCheck, 978, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistQuiet, 731, 512, 2048, false, 150);
TUNABLE_STEP(kLmrHistCapture, 1193, 512, 2048, false, 150);
TUNABLE_STEP(kLmrNotImproving, 1037, 512, 2048, false, 150);
TUNABLE_STEP(kLmrComplexity, 877, 512, 2048, false, 150);
TUNABLE_STEP(kLmrKillerMoves, 978, 512, 2048, false, 150);
TUNABLE_STEP(kLmrRoundingCutoff, 612, 512, 2048, false, 120);

TUNABLE(kProbcutDepth, 5, 1, 10, true);
TUNABLE(kProbcutBetaDelta, 227, 50, 300, false);

TUNABLE_STEP(kHistoryBonusMargin, 47, 5, 120, false, 10);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H