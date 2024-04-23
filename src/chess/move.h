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

// bits 0-5: from
// bits 6-11: to
// bits 12-14: promotion piece type
class Move {
 public:
  constexpr Move() = default;
  constexpr ~Move() = default;

  constexpr explicit Move(U8 from, U8 to) : data_(0) {
    set_from(from);
    set_to(to);
  }

  constexpr explicit Move(U8 from, U8 to, PromotionType promotion_type) : Move(from, to) {
    set_promotion_type(promotion_type);
  }

  constexpr bool operator==(const Move& other) const {
    return data_ == other.data_;
  }

  [[nodiscard]] static Move null_move();

  operator bool() const;

  static std::optional<Move> from_str(const BoardState &state, std::string_view str);

  [[nodiscard]] bool is_capture(const BoardState &state) const;

  [[nodiscard]] bool is_tactical(const BoardState &state) const;

  [[nodiscard]] constexpr inline bool is_null() const {
    return data_ == 0;
  }

  [[nodiscard]] constexpr inline U16 get_data() const {
    return data_;
  }

  [[nodiscard]] constexpr inline Square get_from() const {
    return Square(data_ & kFromMask);
  }

  [[nodiscard]] constexpr inline Square get_to() const {
    return Square((data_ & kToMask) >> 6);
  }

  [[nodiscard]] constexpr inline PromotionType get_promotion_type() const {
    return PromotionType((data_ & kPromotionTypeMask) >> 12);
  }

  constexpr inline void set_from(U8 from) {
    data_ |= static_cast<U32>(from);
  }

  constexpr inline void set_to(U8 to) {
    data_ |= static_cast<U32>(to) << 6;
  }

  constexpr inline void set_promotion_type(PromotionType promotion_type) {
    data_ |= static_cast<U8>(promotion_type) << 12;
  }

  [[nodiscard]] std::string to_string() const;

 private:
  U16 data_;
};

#endif // INTEGRAL_MOVE_H_