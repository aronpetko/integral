#ifndef INTEGRAL_STACK_H
#define INTEGRAL_STACK_H

#include "../../chess/move_gen.h"
#include "../../utils/types.h"
#include "history/continuation_entries.h"

namespace search {

struct PVLine {
 public:
  PVLine() : moves_({}) {
    Clear();
  }

  Move &operator[](std::size_t i) {
    return moves_[i];
  }

  void Clear() {
    moves_.Clear();
  }

  void Push(const Move &move) {
    moves_.Push(move);
  }

  void AppendPV(PVLine &pv) {
    for (std::size_t i = 0; i < pv.Length(); i++) {
      Push(pv[i]);
    }
  }

  [[nodiscard]] std::size_t Length() const {
    return moves_.Size();
  }

  [[nodiscard]] std::string UCIFormat() {
    std::string str;
    for (int i = 0; i < moves_.Size(); i++) {
      str += moves_[i].ToString();
      if (i < moves_.Size() - 1) str += ' ';
    }
    return str;
  }

  friend std::ostream &operator<<(std::ostream &stream, PVLine &pv_line) {
    return stream << pv_line.UCIFormat();
  }

 private:
  List<Move, kMaxPlyFromRoot> moves_;
};

struct StackEntry {
  // Number of ply from root
  I32 ply;
  // Scores at this ply
  Score static_eval, eval, score, eval_complexity;
  I64 history_score;
  // Best moves following down this ply
  PVLine pv;
  // Currently searched move at this ply
  Move move;
  bool capture_move;
  PieceType moved_piece;
  // The excluded TT move when performing singular extensions
  Move excluded_tt_move;
  // Continuation-based heuristics entries for this move
  history::ContinuationEntry *continuation_entry;
  history::ContinuationCorrectionEntry *continuation_correction_entry;
  // Moves that caused a beta cutoff at this ply
  std::array<Move, 2> killer_moves;
  // Was in check at this ply
  bool in_check;
  // Threats
  BitBoard threats;
  // Reduction applied for this ply
  int reduction;
  // Extensions done at this ply
  int extensions;

  void AddKillerMove(Move killer_move) {
    // Ensure we don't have duplicate killer moves
    if (killer_move != killer_moves.front()) {
      killer_moves[1] = killer_moves[0];
      killer_moves[0] = killer_move;
    }
  }

  void ClearKillerMoves() {
    killer_moves.fill(Move::NullMove());
  }

  explicit StackEntry(U16 ply)
      : ply(ply),
        static_eval(kScoreNone),
        eval(kScoreNone),
        eval_complexity(0),
        history_score(0),
        move(Move::NullMove()),
        excluded_tt_move(Move::NullMove()),
        killer_moves({}),
        continuation_entry(nullptr),
        reduction(0),
        extensions(0) {
    ClearKillerMoves();
  }

  StackEntry() : StackEntry(0) {}
};

class Stack {
 public:
  static constexpr int kPadding = 6;

  Stack() {
    Reset();
  }

  void Reset() {
    for (int i = 0; i < stack_.size(); i++) {
      stack_[i] = StackEntry(i - kPadding);
    }
  }

  [[nodiscard]] StackEntry &Front() {
    return stack_[kPadding];
  }

  [[nodiscard]] StackEntry &operator[](int idx) {
    return stack_[idx + kPadding];
  }

 private:
  std::array<StackEntry, kMaxPlyFromRoot + kPadding> stack_;
};

}  // namespace search

#endif  // INTEGRAL_STACK_H