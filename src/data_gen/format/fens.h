#ifndef INTEGRAL_FENS_H
#define INTEGRAL_FENS_H

#include "format.h"

namespace data_gen::format {

class FenFormatter : public OutputFormatter {
 public:
  explicit FenFormatter(std::ostream& output_stream)
      : output_stream_(output_stream) {}

  void SetPosition(const BoardState& state) override {
    start_pos_ = Board(state);
    fens_.clear();
  }

  void PushMove(Move move, Color turn, Score score) override {
    const auto& state = start_pos_.GetState();
    const bool noisy_move =
        move.IsCapture(state) || move.GetType() == MoveType::kPromotion;

    start_pos_.MakeMove(move);

    if (!noisy_move && !state.InCheck()) {
      fens_.push_back(fen::BoardToString(state));
    }
  }

  U64 WriteOutcome(double wdl_outcome) override {
    // White Loss = 0  Draw = 1  White Win = 2
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::ranges::shuffle(fens_, gen);

    for (int i = 0; i < 50 && i < fens_.size(); ++i) {
      output_stream_ << fens_[i] << fmt::format(" [{:.1f}]", wdl_outcome);
      output_stream_ << "\n";
    }

    return std::min<int>(50, fens_.size());
  }

 private:
  Board start_pos_;
  std::vector<std::string> fens_;
  std::ostream& output_stream_;
};

}  // namespace data_gen::format

#endif  // INTEGRAL_FENS_H