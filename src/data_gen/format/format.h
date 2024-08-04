#ifndef INTEGRAL_FORMAT_H
#define INTEGRAL_FORMAT_H

#include "../../chess/board.h"

namespace data_gen::format {

class OutputFormatter {
 public:
  virtual void SetPosition(const BoardState& state) {}

  virtual void PushMove(Move move, Color turn, Score score) {}

  virtual U64 WriteOutcome(double wdl_outcome) {}
};

}  // namespace data_gen::format

#endif  // INTEGRAL_FORMAT_H