#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE(kLmrQuietBase, 0.8088864806576277, 0.5, 1.2, false);
TUNABLE(kLmrQuietDiv, 2.0868634514798017, 1.5, 3.0, false);
TUNABLE(kLmrTactBase, -0.2466717373843328, -0.5, 0.2, false);
TUNABLE(kLmrTactDiv, 2.6600586182979926, 2.0, 3.5, false);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE(kAspWindowDelta, 8, 5, 20, false);
TUNABLE(kAspWindowGrowth, 1.4205730241627241, 0.1, 2.0, false);

TUNABLE(kQsFutMargin, 109, 50, 200, false);

TUNABLE(kEvalHistUpdateMult, 64, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 65, 5, 150, false);
TUNABLE(kEvalHistUpdateMax, 105, 40, 200, false);

TUNABLE(kRevFutDepth, 6, 4, 10, true);
TUNABLE(kRevFutMargin, 65, 50, 150, false);
TUNABLE(kRevFutHistoryDiv, 582, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE(kRazoringMult, 439, 200, 700, false);

TUNABLE(kNmpBetaBase, 143, 50, 250, false);
TUNABLE(kNmpBetaMult, 25, 5, 30, false);
TUNABLE(kNmpRedBase, 4, 1, 5, true);
TUNABLE(kNmpRedDiv, 3, 2, 8, true);
TUNABLE(kNmpEvalDiv, 181, 100, 400, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE(kLmpBase, 5.0, 1.5, 5.0, false);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE(kFutMarginBase, 202, 100, 250, false);
TUNABLE(kFutMarginMult, 93, 50, 200, false);
TUNABLE(kFutMarginHistDiv, 147, 32, 256, false);

TUNABLE(kSeePruneDepth, 8, 6, 12, true);
TUNABLE(kSeeQuietThresh, -62, -100, -20, false);
TUNABLE(kSeeNoisyThresh, -115, -200, -50, false);
TUNABLE(kSeePruneHistDiv, 151, 32, 256, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -481, -1000, 500, false);
TUNABLE(kHistThreshMult, -1897, -3000, -250, false);
TUNABLE(kCaptHistThreshBase, -438, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1802, -3000, -250, false);

TUNABLE(kLmrHistDiv, 11207, 5000, 20000, false);
TUNABLE(kLmrCaptHistDiv, 10627, 5000, 20000, false);
TUNABLE(kLmrComplexityDiff, 80, 5, 150, false);

TUNABLE(kDoDeeperBase, 35, 5, 70, false);
TUNABLE(kDoShallowerBase, 5, 0, 30, false);

TUNABLE(kSeDepth, 6, 6, 12, true);
TUNABLE(kSeDoubleMargin, 13, 0, 30, false);
TUNABLE(kSeTripleMargin, 80, 30, 250, false);
TUNABLE(kSeDepthExtensionDepth, 11, 0, 15, false);

TUNABLE(kProbcutDepth, 5, 1, 10, false);
TUNABLE(kProbcutBetaDelta, 244, 100, 400, false);

TUNABLE(kHistoryBonusMargin, 50, 30, 150, false);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H