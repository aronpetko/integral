#ifndef INTEGRAL_MarlinFORMAT_H
#define INTEGRAL_MarlinFORMAT_H

#include "format.h"

namespace data_gen::format {

// Represents a 4-bit value within an 8-bit integer
class IndexedU4 {
 public:
  // Converts the 4-bit value to an 8-bit unsigned integer
  constexpr inline operator uint8_t() const {
    return high_ ? (value_ >> 4) : (value_ & 0xF);
  }

  // Assigns a new 4-bit value
  constexpr inline IndexedU4& operator=(uint8_t v) {
    assert(v <= 0xF);

    if (high_) {
      value_ = (value_ & 0x0F) | (v << 4);
    } else {
      value_ = (value_ & 0xF0) | (v & 0x0F);
    }

    return *this;
  }

 private:
  // Constructor is private to prevent direct instantiation.
  constexpr IndexedU4(uint8_t& value, bool high) : value_(value), high_(high) {}

  uint8_t& value_;  // Reference to the underlying 8-bit value.
  bool high_;       // True if this represents the high 4 bits, false for low.

  // Allow U4Array to access private members.
  template <size_t Size>
  friend class U4Array;
};

// Array of 4-bit values, packed into 8-bit integers.
template <size_t Size>
class U4Array {
  static_assert(Size % 2 == 0, "Size must be even");

 public:
  U4Array() = default;
  ~U4Array() = default;

  // Returns the value at index i as a read-only 8-bit integer
  constexpr uint8_t operator[](size_t i) const {
    assert(i < Size);
    return data_[i / 2] >> ((i % 2) * 4);
  }

  // Returns a mutable reference to the 4-bit value at index i
  constexpr IndexedU4 operator[](size_t i) {
    assert(i < Size);
    return IndexedU4(data_[i / 2], (i % 2) == 1);
  }

 private:
  // Underlying storage: each uint8_t holds two 4-bit values
  std::array<uint8_t, Size / 2> data_{};
};

struct __attribute__((packed)) MarlinChessBoard {
  U64 occupied;
  U4Array<32> pieces;
  U8 turn_and_en_passant;
  U8 half_move_clock;
  U16 full_move_number;
  I16 evaluation;
  U8 wdl_outcome;
  [[maybe_unused]] U8 extra;
};

using BinPackMove = std::pair<U16, I16>;

constexpr BinPackMove kNullBinPackMove{};
constexpr std::array<U16, 4> kBinPackMoveTypes = {
    0x0000, 0xC000, 0x8000, 0x4000};

class BinPackFormatter : public OutputFormatter {
 public:
  explicit BinPackFormatter(std::ostream& output_stream)
      : output_stream_(output_stream) {
    moves_.reserve(256);
  }

  void SetPosition(const BoardState& state) override {
    start_pos_ = ConvertBoardState(state);
    moves_.clear();
  }

  void PushMove(Move move, Color turn, Score score) override {
    Square from = move.GetFrom(), to = move.GetTo();

    // No FRC support :(
    const auto move_type = move.GetType();
    if (move_type == MoveType::kCastle) {
      const int displacement = to.File() - from.File() > 0 ? 1 : -2;
      //to += displacement;
    }

    U16 move_data = 0;
    move_data |= from;
    move_data |= to << 6;
    move_data |= static_cast<U8>(move.GetPromotionType()) << 12;
    move_data |= kBinPackMoveTypes[static_cast<int>(move_type)];

    moves_.emplace_back(move_data, static_cast<I16>(score));
  }

  U64 WriteOutcome(double wdl_outcome) override {
    // White Loss = 0  Draw = 1  White Win = 2
    start_pos_.wdl_outcome = static_cast<U8>(wdl_outcome * 2);

    output_stream_.write(reinterpret_cast<const char*>(&start_pos_),
                         sizeof(MarlinChessBoard));
    output_stream_.write(reinterpret_cast<const char*>(moves_.data()),
                         sizeof(BinPackMove) * moves_.size());
    output_stream_.write(reinterpret_cast<const char*>(&kNullBinPackMove),
                         sizeof(BinPackMove));

    return moves_.size();
  }

 private:
  static MarlinChessBoard ConvertBoardState(const BoardState& state) {
    MarlinChessBoard converted{.occupied = state.Occupied().AsU64()};

    int i = 0;
    for (Square square : state.Occupied()) {
      const auto piece = state.GetPieceType(square);
      const auto color = state.GetPieceColor(square);

      U8 piece_id = static_cast<U8>(piece);
      if (piece == PieceType::kRook) {
        if (square == Squares::kA1 &&
                state.castle_rights.CanQueensideCastle(Color::kWhite) ||
            square == Squares::kH1 &&
                state.castle_rights.CanKingsideCastle(Color::kWhite) ||
            square == Squares::kA8 &&
                state.castle_rights.CanQueensideCastle(Color::kBlack) ||
            square == Squares::kH8 &&
                state.castle_rights.CanKingsideCastle(Color::kBlack)) {
          constexpr U8 kUnmovedRookPieceId = 6;
          piece_id = kUnmovedRookPieceId;
        }
      }

      const U8 color_id = color == Color::kBlack ? 0b1000 : 0;
      converted.pieces[i++] = piece_id | color_id;
    }

    const U8 turn = state.turn == Color::kBlack ? 0b10000000 : 0;
    const U8 en_passant = state.en_passant == Squares::kNoSquare
                            ? Squares::kNoSquare
                            : state.en_passant.RelativeTo(state.turn);
    converted.turn_and_en_passant = turn | en_passant;
    converted.wdl_outcome = 0;
    converted.evaluation = 0;
    converted.half_move_clock = state.fifty_moves_clock;
    //converted.full_move_number = (state.half_moves + 1) / 2;
    return converted;
  }

 private:
  MarlinChessBoard start_pos_;
  std::vector<BinPackMove> moves_;
  std::ostream& output_stream_;
};

}  // namespace data_gen::format

#endif  // INTEGRAL_MarlinFORMAT_H