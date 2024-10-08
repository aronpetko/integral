#ifndef INTEGRAL_BONUS_H
#define INTEGRAL_BONUS_H

#include "../../../tuner/spsa.h"
#include "../../../utils/types.h"

namespace search::history {

inline Tunable hist_default_gravity(
    "hist_default_gravity", 15176, 8192, 32768, 1024);
inline Tunable hist_default_scale("hist_default_scale", 270, 65, 260, 5);
inline Tunable hist_default_bias("hist_default_bias", 338, 65, 260, 5);
inline Tunable hist_default_max_bonus(
    "hist_default_max_bonus", 2636, 580, 2318, 50);

static int HistoryBonus(int depth) {
  return std::clamp<int>(hist_default_scale * depth - hist_default_bias,
                         -hist_default_max_bonus,
                         hist_default_max_bonus);
}

static int HistoryPenalty(int depth) {
  return std::clamp<int>(hist_default_scale * depth - hist_default_bias,
                         -hist_default_max_bonus,
                         hist_default_max_bonus);
}

// Linear interpolation of the bonus and maximum score
static int ScaleBonus(I32 score,
                      int bonus,
                      int gravity = hist_default_gravity) {
  return bonus - score * std::abs(bonus) / gravity;
}

}  // namespace search::history

#endif  // INTEGRAL_BONUS_H