#ifndef INTEGRAL_BONUS_H
#define INTEGRAL_BONUS_H

#include "../../../tuner/spsa.h"
#include "../../../utils/types.h"

namespace search::history {

TUNABLE(kHistBonusGravity, 10606, 8192, 32768, false);
TUNABLE(kHistBonusScale, 170, 65, 300, false);
TUNABLE(kHistPenaltyScale, 166, 65, 300, false);
TUNABLE_STEP(kHistBonusMaxBonus, 1119, 580, 2500, false, 200);
TUNABLE(kHistBonusBias, 120, 0, 300, false);

static I16 HistoryBonus(I16 depth,
                        I16 scale = kHistBonusScale,
                        I16 max_bonus = kHistBonusMaxBonus) {
  return std::clamp<I16>(scale * depth - kHistBonusBias, -max_bonus, max_bonus);
}

static I16 HistoryPenalty(I16 depth,
                          I16 scale = kHistPenaltyScale,
                          I16 max_bonus = kHistBonusMaxBonus) {
  return std::clamp<I16>(
      -scale * depth - kHistBonusBias, -max_bonus, max_bonus);
}

// Linear interpolation of the bonus and maximum score
static I16 ScaleBonus(I16 score, I16 bonus, I16 gravity = kHistBonusGravity) {
  return bonus - score * std::abs(bonus) / gravity;
}

}  // namespace search::history

#endif  // INTEGRAL_BONUS_H