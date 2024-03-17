#ifndef INTEGRAL_MOVE_H_
#define INTEGRAL_MOVE_H_

#include <optional>
#include <vector>
#include <string>

class BoardState;

const U32 kFromMask = 0b000000000000111111;
const U32 kToMask = 0b000000111111000000;
const U32 kPromotionTypeMask = 0b000111000000000000;

// bits 0-5: from
// bits 6-11: to
// bits 12-14: promotion piece type
class Move {
 public:
  Move() = default;

  Move(U8 from, U8 to);

  Move(U8 from, U8 to, PromotionType promotion_type);

  [[nodiscard]] static Move null_move();

  bool operator==(const Move &other) const;

  static std::optional<Move> from_str(BoardState &board, std::string_view str);

  [[nodiscard]] constexpr inline U8 get_from() const {
    return data_ & kFromMask;
  }

  [[nodiscard]] constexpr inline U8 get_to() const {
    return (data_ & kToMask) >> 6;
  }

  [[nodiscard]] constexpr inline PromotionType get_promotion_type() const {
    return PromotionType((data_ & kPromotionTypeMask) >> 12);
  }

  constexpr inline void set_from(U8 from) {
    data_ &= ~kFromMask;
    data_ |= static_cast<U32>(from) & kFromMask;
  }

  constexpr inline void set_to(U8 to) {
    data_ &= ~kToMask;
    data_ |= (static_cast<U32>(to) << 6) & kToMask;
  }

  constexpr inline void set_promotion_type(PromotionType promotion_type) {
    data_ = (data_ & ~kPromotionTypeMask) | (static_cast<U8>(promotion_type) << 12);
  }

  [[nodiscard]] std::string to_string() const;

 private:
  U16 data_;
};

#endif // INTEGRAL_MOVE_H_