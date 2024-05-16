#include "board.h"

Move Move::NullMove() {
  return Move(0, 0);
}

Move::operator bool() const {
  return !IsNull();
}

Move Move::FromStr(const BoardState &state, std::string_view str) {
  constexpr int kMinMoveLen = 4, kMaxMoveLen = 5;
  if (str.length() < kMinMoveLen || str.length() > kMaxMoveLen)
    return Move::NullMove();

  const int from_rank = str[1] - '1', from_file = str[0] - 'a';
  const int to_rank = str[3] - '1', to_file = str[2] - 'a';

  if (from_rank < 0 || from_rank >= 8 || to_rank < 0 || to_rank >= 8 ||
      from_file < 0 || from_file >= 8 || to_file < 0 || to_file >= 8)
    return Move::NullMove();
  ;

  const auto from = RankFileToSquare(from_rank, from_file);
  const auto to = RankFileToSquare(to_rank, to_file);

  if (str.length() < kMaxMoveLen) return Move(from, to);

  PromotionType promotion_type;
  switch (str[4]) {
    case 'q':
    case 'Q':
      promotion_type = PromotionType::kQueen;
      break;
    case 'r':
    case 'R':
      promotion_type = PromotionType::kRook;
      break;
    case 'b':
    case 'B':
      promotion_type = PromotionType::kBishop;
      break;
    case 'n':
    case 'N':
      promotion_type = PromotionType::kKnight;
      break;
    default:
      return Move::NullMove();
      ;
  }

  return Move(from, to, promotion_type);
}

bool Move::IsCapture(const BoardState &state) const {
  const auto from = GetFrom();
  const auto to = GetTo();
  return state.GetPieceType(to) != PieceType::kNone ||
         state.GetPieceType(from) == PieceType::kPawn && state.en_passant == to;
}

[[nodiscard]] bool Move::IsTactical(const BoardState &state) const {
  return IsCapture(state) || GetPromotionType() != PromotionType::kNone;
}

[[nodiscard]] bool Move::IsUnderPromotion() const {
  const auto promo_type = GetPromotionType();
  return promo_type != PromotionType::kNone &&
         promo_type != PromotionType::kQueen &&
         promo_type != PromotionType::kKnight;
}

std::string Move::ToString() const {
  if (data_ == 0) return "null";

  const auto from_rank = Rank(GetFrom()), from_file = File(GetFrom());
  const auto to_rank = Rank(GetTo()), to_file = File(GetTo());

  std::string res = std::string(1, 'a' + from_file) +
                    std::to_string(from_rank + 1) +
                    std::string(1, 'a' + to_file) + std::to_string(to_rank + 1);

  const auto promo_type = GetPromotionType();
  switch (promo_type) {
    case PromotionType::kAny:
    case PromotionType::kQueen:
      res += 'q';
      break;
    case PromotionType::kKnight:
      res += 'n';
      break;
    case PromotionType::kBishop:
      res += 'b';
      break;
    case PromotionType::kRook:
      res += 'r';
      break;
    default:
      break;
  }

  return res;
}