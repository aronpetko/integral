#ifndef INTEGRAL_BONUS_H
#define INTEGRAL_BONUS_H

#include <span>

#include "../../../tuner/spsa.h"
#include "../../../utils/types.h"

namespace search::history {

TUNABLE(kHistBonusGravity, 12411, 8192, 32768, false);
TUNABLE(kHistBonusScale, 177, 65, 300, false);
TUNABLE(kHistPenaltyScale, 158, 65, 300, false);
TUNABLE_STEP(kHistBonusMaxBonus, 1429, 580, 2500, false, 200);
TUNABLE(kHistBonusBias, 136, 0, 300, false);

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

TUNABLE(kHistPolicyBonusScale, 1024, 0, 1024, false);
TUNABLE(kHistPolicyPenaltyScale, 1024, 0, 1024, false);

constexpr I16 kPolicyOne = 1024;
constexpr I16 kNoPolicy = -1;

static I16 PolicyBonus(I16 bonus, I16 policy) {
  if (policy == kNoPolicy) return bonus;
  const int factor = kPolicyOne - kHistPolicyBonusScale * policy / kPolicyOne;
  return static_cast<I16>(bonus * factor / kPolicyOne);
}

static I16 PolicyPenalty(I16 penalty, I16 policy) {
  if (policy == kNoPolicy) return penalty;
  const int factor =
      kPolicyOne - kHistPolicyPenaltyScale * (kPolicyOne - policy) / kPolicyOne;
  return static_cast<I16>(penalty * factor / kPolicyOne);
}

// Linear interpolation of the bonus and maximum score
static I16 ScaleBonus(I16 score, I16 bonus, I16 gravity = kHistBonusGravity) {
  return bonus - score * std::abs(bonus) / gravity;
}

}  // namespace search::history

#endif  // INTEGRAL_BONUS_H