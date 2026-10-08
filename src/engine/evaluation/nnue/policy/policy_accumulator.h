#ifndef INTEGRAL_POLICY_ACCUMULATOR_H
#define INTEGRAL_POLICY_ACCUMULATOR_H

#include "../../../../../shared/nnue/definitions.h"
#include "../../../../../shared/simd.h"
#include "../../../../chess/board.h"
#include "../../../../chess/move_gen.h"
#include "../nnue.h"

namespace nnue::policy {

class PolicyAccumulator {
 public:
  static constexpr int kWidth = arch::policy::kL1Size;
  using Vector = simd::Vector<I16, kWidth>;

  void Refresh(const BoardState& state);

  [[nodiscard]] const Vector& Values() const {
    return values_;
  }

 private:
  Vector values_;
};

}  // namespace nnue::policy

#endif  // INTEGRAL_POLICY_ACCUMULATOR_H
