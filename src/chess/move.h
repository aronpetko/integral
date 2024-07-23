#ifndef INTEGRAL_MOVE_H_
#define INTEGRAL_MOVE_H_

#include <optional>
#include <string>
#include <vector>

#include "bitboard.h"

class BoardState;

enum MoveMasks : U16 {
  kFrom = 0b0000000000111111,      // Bits 0-5
  kTo = 0b0000111111000000,        // Bits 6-11
  kType = 0b0011000000000000,      // Bits 12-14
  kPromotion = 0b1100000000000000  // Bits 15-16
};

enum class MoveType : U8 {
  kNormal,
  kPromotion,
  kCastle,
  kEnPassant
};

// Bits 0-5: From Square
// Bits 6-11: To Square
// Bits 12-14: Move Type
// Bits 15-16: Promotion Piece
class Move {
 public:
  constexpr Move() = default;
  constexpr ~Move() = default;

  constexpr explicit Move(U8 from, U8 to, MoveType flag = MoveType::kNormal)
      : data_(0) {
    SetFrom(from);
    SetTo(to);
    SetFlag(flag);
  }

  constexpr explicit Move(U8 from, U8 to, PromotionType promotion_type)
      : Move(from, to, MoveType::kPromotion) {
    SetPromotionType(promotion_type);
  }

  constexpr bool operator==(const Move &other) const {
    return data_ == other.data_;
  }

  [[nodiscard]] static Move NullMove();

  operator bool() const;

  static Move FromStr(std::string_view str, const BoardState &state);

  [[nodiscard]] bool IsCapture(const BoardState &state) const;

  [[nodiscard]] bool IsNoisy(const BoardState &state) const;

  [[nodiscard]] bool IsEnPassant(const BoardState &state) const;

  [[nodiscard]] bool IsUnderPromotion() const;

  [[nodiscard]] constexpr bool IsNull() const {
    return data_ == 0;
  }

  [[nodiscard]] constexpr U16 GetData() const {
    return data_;
  }

  [[nodiscard]] constexpr Square GetFrom() const {
    return Square(data_ & MoveMasks::kFrom);
  }

  [[nodiscard]] constexpr Square GetTo() const {
    return Square((data_ & MoveMasks::kTo) >> 6);
  }

  [[nodiscard]] constexpr MoveType GetType() const {
    return MoveType((data_ & MoveMasks::kType) >> 12);
  }

  [[nodiscard]] constexpr PromotionType GetPromotionType() const {
    return PromotionType((data_ & MoveMasks::kPromotion) >> 14);
  }

  constexpr void SetFrom(U8 from) {
    data_ = (data_ & ~MoveMasks::kFrom) | (from & MoveMasks::kFrom);
  }

  constexpr void SetTo(U8 to) {
    data_ = (data_ & ~MoveMasks::kTo) | ((to << 6) & MoveMasks::kTo);
  }

  constexpr void SetFlag(MoveType flag) {
    data_ = (data_ & ~MoveMasks::kType) |
            ((static_cast<U16>(flag) << 12) & MoveMasks::kType);
  }

  constexpr void SetPromotionType(PromotionType promotion_type) {
    data_ = (data_ & ~MoveMasks::kPromotion) |
            ((static_cast<U16>(promotion_type) << 14) & MoveMasks::kPromotion);
  }

  [[nodiscard]] std::string ToString() const;

 private:
  U16 data_;
};

#endif  // INTEGRAL_MOVE_H_