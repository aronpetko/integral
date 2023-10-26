#ifndef INTEGRAL_MOVE_H_
#define INTEGRAL_MOVE_H_

#include "types.h"

const U8 kMoveMask = 0b00111111;
const U8 kPieceTypeMask = 0b111;

// bits 0-5: from
// bits 6-11: to
// bits 12-14: piece type
struct Move {
  U32 data;

  Move(U8 from, U8 to) {
    data = (from & kMoveMask) + ((to & kMoveMask) << 6);
  }

  Move(U8 from, U8 to, PieceType piece_type) : Move(from, to) {
    data &= ~(kPieceTypeMask << 12);
    data |= (piece_type & kPieceTypeMask) << 12;
  }

  U8 get_from() const {
    return data & kMoveMask;
  }

  U8 get_to() const {
    return (data >> 6) & kMoveMask;
  }

  U8 get_piece_type() const {
    return ((data >> 12) & kPieceTypeMask);
  }
};

#endif // INTEGRAL_MOVE_H_