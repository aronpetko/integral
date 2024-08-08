#ifndef INTEGRAL_FORMAT_H
#define INTEGRAL_FORMAT_H

#include "../../chess/board.h"

namespace data_gen::format {

class OutputFormatter {
 public:
  virtual void SetPosition(const BoardState& state) = 0;

  virtual void PushMove(Move move, Color turn, Score score) = 0;

  virtual U64 WriteOutcome(double wdl_outcome) = 0;
};

}  // namespace data_gen::format

#endif  // INTEGRAL_FORMAT_H