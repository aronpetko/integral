#ifndef INTEGRAL_CONSTANTS_H
#define INTEGRAL_CONSTANTS_H

#include "../../tuner/spsa.h"

namespace search {

TUNABLE(kLmrQuietBase, 0.8096097960171492, 0.5, 1.2, false);
TUNABLE(kLmrQuietDiv, 2.100260805448927, 1.5, 3.0, false);
TUNABLE(kLmrTactBase, -0.23697061152919505, -0.5, 0.2, false);
TUNABLE(kLmrTactDiv, 2.6415513306252167, 2.0, 3.5, false);

TUNABLE(kAspWindowDepth, 4, 2, 8, true);
TUNABLE(kAspWindowDelta, 8, 5, 20, false);
TUNABLE(kAspWindowGrowth, 1.498700148986745, 0.1, 2.0, false);

TUNABLE(kQsFutMargin, 102, 50, 200, false);

TUNABLE(kEvalHistUpdateMult, 63, 20, 100, false);
TUNABLE(kEvalHistUpdateMin, 67, 5, 150, false);
TUNABLE(kEvalHistUpdateMax, 102, 40, 200, false);

TUNABLE(kRevFutDepth, 6, 4, 10, true);
TUNABLE(kRevFutMargin, 65, 50, 150, false);
TUNABLE(kRevFutHistoryDiv, 582, 200, 800, false);

TUNABLE(kRazoringDepth, 4, 1, 8, true);
TUNABLE(kRazoringMult, 446, 200, 700, false);

TUNABLE(kNullMoveBetaBase, 152, 50, 250, false);
TUNABLE(kNullMoveBetaMult, 24, 5, 30, false);
TUNABLE(kNullMoveRb, 4, 1, 5, true);
TUNABLE(kNullMoveRf, 4, 2, 8, true);
TUNABLE(kNullMoveRe, 193, 100, 400, false);

TUNABLE(kIirDepth, 4, 2, 8, true);

TUNABLE(kLmpBase, 5.0, 1.5, 5.0, false);

TUNABLE(kFutPruneDepth, 8, 6, 12, true);
TUNABLE(kFutMarginBase, 198, 100, 250, false);
TUNABLE(kFutMarginMult, 92, 50, 200, false);
TUNABLE(kFutMarginHistDiv, 152, 32, 256, false);

TUNABLE(kSeePruneDepth, 8, 6, 12, true);
TUNABLE(kSeeQuietThresh, -60, -100, -20, false);
TUNABLE(kSeeNoisyThresh, -120, -200, -50, false);
TUNABLE(kSeeNoisyHistDiv, 146, 32, 256, false);

TUNABLE(kHistPruneDepth, 5, 3, 8, true);
TUNABLE(kHistThreshBase, -480, -1000, 500, false);
TUNABLE(kHistThreshMult, -1906, -3000, -250, false);
TUNABLE(kCaptHistThreshBase, -444, -1000, 500, false);
TUNABLE(kCaptHistThreshMult, -1737, -3000, -250, false);

TUNABLE(kLmrHistDiv, 11384, 5000, 20000, false);
TUNABLE(kLmrCaptHistDiv, 11643, 5000, 20000, false);
TUNABLE(kLmrComplexityDiff, 81, 5, 150, false);

TUNABLE(kDoDeeperBase, 36, 5, 70, false);
TUNABLE(kDoShallowerBase, 6, 0, 30, false);

TUNABLE(kSeDepth, 6, 6, 12, true);
TUNABLE(kSeDoubleMargin, 14, 0, 30, false);
TUNABLE(kSeTripleMargin, 104, 30, 250, false);
TUNABLE(kSeDepthExtensionDepth, 11, 0, 15, false);

TUNABLE(kProbcutBetaDelta, 246, 100, 400, false);

}  // namespace search

#endif  // INTEGRAL_CONSTANTS_H