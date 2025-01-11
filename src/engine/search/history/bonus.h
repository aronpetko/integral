#ifndef INTEGRAL_BONUS_H
#define INTEGRAL_BONUS_H

#include "../../../tuner/spsa.h"
#include "../../../utils/types.h"

namespace search::history {

TUNABLE(kHistBonusGravity, 10928, 8192, 32768, false);
TUNABLE(kHistBonusScale, 191, 65, 260, false);
TUNABLE(kHistPenaltyScale, 178, 65, 260, false);
TUNABLE(kHistBonusMaxBonus, 1202, 580, 2318, false);
TUNABLE(kHistBonusBias, 98, 0, 300, false);

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