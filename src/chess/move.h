#ifndef INTEGRAL_MOVE_H_
#define INTEGRAL_MOVE_H_

#include <optional>
#include <string>
#include <vector>

#include "bitboard.h"

class BoardState;

const U32 kFromMask = 0b000000000000111111;
const U32 kToMask = 0b000000111111000000;
const U32 kPromotionTypeMask = 0b000111000000000000;

// Bits 0-5: from
// Bits 6-11: to
// Bits 12-14: promotion piece type
class Move {
 public:
  constexpr Move() = default;
  constexpr ~Move() = default;

  constexpr explicit Move(U8 from, U8 to) : data_(0) {
    SetFrom(from);
    SetTo(to);
  }

  constexpr explicit Move(U8 from, U8 to, PromotionType promotion_type)
      : Move(from, to) {
    SetPromotionType(promotion_type);
  }

  constexpr bool operator==(const Move &other) const {
    return data_ == other.data_;
  }

  [[nodiscard]] static Move NullMove();

  operator bool() const;

  static Move FromStr(const BoardState &state, std::string_view str);

  [[nodiscard]] bool IsCapture(const BoardState &state) const;

  [[nodiscard]] bool IsTactical(const BoardState &state) const;

  [[nodiscard]] bool IsUnderPromotion() const;

  [[nodiscard]] constexpr inline bool IsNull() const {
    return data_ == 0;
  }

  [[nodiscard]] constexpr inline U16 GetData() const {
    return data_;
  }

  [[nodiscard]] constexpr inline Square GetFrom() const {
    return Square(data_ & kFromMask);
  }

  [[nodiscard]] constexpr inline Square GetTo() const {
    return Square((data_ & kToMask) >> 6);
  }

  [[nodiscard]] constexpr inline PromotionType GetPromotionType() const {
    return PromotionType((data_ & kPromotionTypeMask) >> 12);
  }

  constexpr inline void SetFrom(U8 from) {
    data_ |= static_cast<U32>(from);
  }

  constexpr inline void SetTo(U8 to) {
    data_ |= static_cast<U32>(to) << 6;
  }

  constexpr inline void SetPromotionType(PromotionType promotion_type) {
    data_ |= static_cast<U8>(promotion_type) << 12;
  }

  [[nodiscard]] std::string ToString() const;

 private:
  U16 data_;
};

#endif  // INTEGRAL_MOVE_H_