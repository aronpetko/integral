#ifndef INTEGRAL_BONUS_H
#define INTEGRAL_BONUS_H

#include "../../../tuner/spsa.h"
#include "../../../utils/types.h"

namespace history {

inline Tunable hist_default_gravity(
    "hist_default_gravity", 16384, 8192, 32768, 700);
inline Tunable hist_default_scale("hist_default_scale", 130, 65, 260, 5);
inline Tunable hist_default_max_bonus(
    "hist_default_max_bonus", 1159, 580, 2318, 50);

static int HistoryBonus(int depth,
                        int scale = hist_default_scale,
                        int max_bonus = hist_default_max_bonus) {
  return std::clamp(scale * depth, -max_bonus, max_bonus);
}

// Linear interpolation of the bonus and maximum score
static int ScaleBonus(I32 score,
                      int bonus,
                      int gravity = hist_default_gravity) {
  return bonus - score * std::abs(bonus) / gravity;
}

}  // namespace history

#endif  // INTEGRAL_BONUS_H