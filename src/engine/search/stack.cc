#include "stack.h"
#include "move_picker.h"

namespace search {

StackEntry::StackEntry(I32 ply) {
  Reset(ply);
}

StackEntry::StackEntry() : StackEntry(0) {}

StackEntry::~StackEntry() = default;

StackEntry::StackEntry(StackEntry &&) noexcept = default;

StackEntry &StackEntry::operator=(StackEntry &&) noexcept = default;

void StackEntry::Reset(I32 p) {
  ply = p;
  static_eval = eval = score = kScoreNone;
  eval_complexity = 0;
  history_score = 0;
  pv.Clear();
  move = Move::NullMove();
  capture_move = false;
  moved_piece = kNone;
  excluded_tt_move = Move::NullMove();
  continuation_entry = nullptr;
  continuation_correction_entry = nullptr;
  ClearKillerMoves();
  in_check = false;
  threats = 0;
  reduction = 0;
  quiets.Clear();
  captures.Clear();
  move_picker.reset();
}

}  // namespace search
