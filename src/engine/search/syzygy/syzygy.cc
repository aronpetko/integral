#include "syzygy.h"

#include <tbprobe.h>
#include <algorithm>

namespace syzygy {

void SetPath(std::string_view path) {
  syzygy::enabled = path != "<empty>";
  tb_init(path.data());

  syzygy::max_pieces = std::min<int>(TB_LARGEST, syzygy::piece_probe_limit);
}

void Free() {
  tb_free();
}

ProbeResult ProbePosition(const BoardState &state) {
  const Square en_passant =
      state.en_passant != Squares::kNoSquare ? state.en_passant : Square(0);
  const auto result = tb_probe_wdl(state.Occupied(Color::kWhite).AsU64(),
                                   state.Occupied(Color::kBlack).AsU64(),
                                   state.Kings().AsU64(),
                                   state.Queens().AsU64(),
                                   state.Rooks().AsU64(),
                                   state.Bishops().AsU64(),
                                   state.Knights().AsU64(),
                                   state.Pawns().AsU64(),
                                   0,
                                   0,
                                   en_passant,
                                   state.turn == Color::kWhite);

  switch (result) {
    case TB_WIN:
      return ProbeResult::kWin;
    case TB_LOSS:
      return ProbeResult::kLoss;
    case TB_RESULT_FAILED:
      return ProbeResult::kFailed;
    case TB_DRAW:
    default:
      return ProbeResult::kDraw;
  }
}

}  // namespace syzygy