#ifndef INTEGRAL_BONUS_H
#define INTEGRAL_BONUS_H

#include "../../../utils/types.h"

namespace history {

constexpr int kHistoryDefaultGravity = 16384;
constexpr int kHistoryDefaultScale = 130;
constexpr int kHistoryDefaultMaxBonus = 1159;

static int HistoryBonus(int depth,
                        int scale = kHistoryDefaultScale,
                        int max_bonus = kHistoryDefaultMaxBonus) {
  return std::clamp(scale * depth, -max_bonus, max_bonus);
}

// Linear interpolation of the bonus and maximum score
static int ScaleBonus(I32 score,
                      int bonus,
                      int gravity = kHistoryDefaultGravity) {
  return bonus - score * std::abs(bonus) / gravity;
}

} // namespace history

#endif  // INTEGRAL_BONUS_H