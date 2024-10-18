#ifndef INTEGRAL_BONUS_H
#define INTEGRAL_BONUS_H

#include "../../../tuner/spsa.h"
#include "../../../utils/types.h"

namespace search::history {

TUNABLE(kHistBonusGravity, 11849, 8192, 32768, false);
TUNABLE(kHistBonusScale, 134, 65, 260, false);
TUNABLE(kHistPenaltyScale, 143, 65, 260, false);
TUNABLE(kHistBonusMaxBonus, 1188, 580, 2318, true);

static int HistoryBonus(int depth,
                        int scale = kHistBonusScale,
                        int max_bonus = kHistBonusMaxBonus) {
  return std::clamp(scale * depth, -max_bonus, max_bonus);
}

static int HistoryPenalty(int depth,
                        int scale = kHistPenaltyScale,
                        int max_bonus = kHistBonusMaxBonus) {
  return std::clamp(-scale * depth, -max_bonus, max_bonus);
}

// Linear interpolation of the bonus and maximum score
static int ScaleBonus(I32 score,
                      int bonus,
                      int gravity = kHistBonusGravity) {
  return bonus - score * std::abs(bonus) / gravity;
}

}  // namespace search::history

#endif  // INTEGRAL_BONUS_H