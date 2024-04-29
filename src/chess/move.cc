#include "board.h"

Move Move::null_move() {
  return Move(0, 0);
}

Move::operator bool() const {
  return !is_null();
}

Move Move::from_str(const BoardState &state, std::string_view str) {
  const int kMinMoveLen = 4, kMaxMoveLen = 5;
  if (str.length() < kMinMoveLen || str.length() > kMaxMoveLen) return Move::null_move();

  const int from_rank = str[1] - '1', from_file = str[0] - 'a';
  const int to_rank = str[3] - '1', to_file = str[2] - 'a';

  if (from_rank < 0 || from_rank >= 8 || to_rank < 0 || to_rank >= 8 || from_file < 0 || from_file >= 8 ||
      to_file < 0 || to_file >= 8)
    return Move::null_move();
  ;

  const auto from = rank_file_to_square(from_rank, from_file);
  const auto to = rank_file_to_square(to_rank, to_file);

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
      return Move::null_move();
      ;
  }

  return Move(from, to, promotion_type);
}

bool Move::is_capture(const BoardState &state) const {
  const auto from = get_from();
  const auto to = get_to();
  return state.get_piece_type(to) != PieceType::kNone ||
         state.get_piece_type(from) == PieceType::kPawn && state.en_passant == to;
}

[[nodiscard]] bool Move::is_tactical(const BoardState &state) const {
  return is_capture(state) || get_promotion_type() != PromotionType::kNone;
}

[[nodiscard]] bool Move::is_under_promotion() const {
  const auto promo_type = get_promotion_type();
  return promo_type != PromotionType::kNone && promo_type != PromotionType::kQueen &&
         promo_type != PromotionType::kKnight;
}

std::string Move::to_string() const {
  if (data_ == 0) return "null";

  const auto from_rank = rank(get_from()), from_file = file(get_from());
  const auto to_rank = rank(get_to()), to_file = file(get_to());

  std::string res = std::string(1, 'a' + from_file) + std::to_string(from_rank + 1) + std::string(1, 'a' + to_file) +
                    std::to_string(to_rank + 1);

  const auto promo_type = get_promotion_type();
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