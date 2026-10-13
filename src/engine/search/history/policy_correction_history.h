#ifndef INTEGRAL_POLICY_CORRECTION_HISTORY_H
#define INTEGRAL_POLICY_CORRECTION_HISTORY_H

#include <array>

#include "../../../../shared/nnue/definitions.h"
#include "bonus.h"

namespace search::history {

class PolicyCorrectionHistory {
 public:
  PolicyCorrectionHistory() : table_({}) {}

  void Clear() {
    table_.fill(I16{0});
  }

  int GetScore(U16 row) const {
    return table_[row];
  }

  void UpdateScore(U16 row, int policy_score, int bonus) {
    I16 &score = table_[row];
    const int limit = std::min<int>(kHistBonusGravity, 32767);
    const int prediction = std::clamp(policy_score + score, -limit, limit);
    score = std::clamp(
        score + bonus - prediction * std::abs(bonus) / kHistBonusGravity,
        -limit,
        limit);
  }

 private:
  std::array<I16, nnue::arch::policy::kOutputSize> table_;
};

}

#endif
