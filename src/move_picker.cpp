#include "move_picker.h"
#include "move_orderer.h"

// clang-format off
const std::array<std::array<int, PieceType::kNumPieceTypes>, PieceType::kNumPieceTypes> kMVVLVATable = {{
  {{10, 11, 12, 13, 14, 15}}, // victim P,    attacker K, Q, R, B, N, P
  {{20, 21, 22, 23, 24, 25}}, // victim N,    attacker K, Q, R, B, N, P
  {{30, 31, 32, 33, 34, 35}}, // victim B,    attacker K, Q, R, B, N, P
  {{40, 41, 42, 43, 44, 45}}, // victim R,    attacker K, Q, R, B, N, P
  {{50, 51, 52, 53, 54, 55}}, // victim Q,    attacker K, Q, R, B, N, P
  {{0, 0, 0, 0, 0, 0}},       // victim K,    attacker K, Q, R, B, N, P
}};
// clang-format on

MovePicker::MovePicker(MovePickerType type, Board &board, const Move &tt_move, Search::Stack *search_stack)
    : type_(type), board_(board), tt_move_(tt_move), stage_(Stage::kTTMove), search_stack_(search_stack),
      quiets_idx_(0), bad_captures_idx_(0), good_captures_idx_(0) {}

Move MovePicker::next() {
  const auto &state = board_.get_state();
  switch (stage_) {
    case Stage::kTTMove: {
      if (!tt_move_.is_null()) {
        return tt_move_;
      }
      stage_ = Stage::kGenerateQuiets;
      // fall through
    }
    case Stage::kGenerateCaptures:
      captures_ = generate_and_score_moves<MoveType::kCaptures>();
      stage_ = Stage::kGoodCaptures;
      // fall through
    case Stage::kGoodCaptures: {
      if (good_captures_idx_ < good_captures_.size()) {
        return selection_sort(good_captures_, good_captures_idx_++).move;
      }
      stage_ = Stage::kFirstKiller;
      // fall through
    }
    case Stage::kFirstKiller: {
      const auto &first_killer = search_stack_->killers[0];
      if (!first_killer.is_null() &&
          (type_ == MovePickerType::kSearch || first_killer.is_tactical(state))) {
        return first_killer;
      }
      stage_ = Stage::kSecondKiller;
      // fall through
    }
    case Stage::kSecondKiller: {
      const auto &second_killer = search_stack_->killers[1];
      if (!second_killer.is_null() &&
          (type_ == MovePickerType::kSearch || second_killer.is_tactical(state))) {
        return second_killer;
      }
      stage_ = Stage::kCounterMove;
      // fall through
    }
    case Stage::kCounterMove:
      stage_ = Stage::kGenerateQuiets;
      // fall through
    case Stage::kGenerateQuiets:
      if (type_ != MovePickerType::kQuiescence) {
        quiets_ = generate_and_score_moves<MoveType::kQuiet>();
      }
      stage_ = Stage::kQuiets;
    case Stage::kQuiets:
      if (type_ != MovePickerType::kQuiescence) {
        if (quiets_idx_ < quiets_.size()) {
          return selection_sort(quiets_, quiets_idx_++).move;
        }
      }
      stage_ = Stage::kBadCaptures;
      // fall through
    case Stage::kBadCaptures:
      if (bad_captures_idx_ < bad_captures_.size()) {
        return selection_sort(bad_captures_, bad_captures_idx_++).move;
      }
      break;
    default:
      break;
  }

  return Move::null_move();
}

ScoredMove &MovePicker::selection_sort(List<ScoredMove> &moves, const int &index) {
  for (int next = index + 1; next < moves.size(); next++) {
    if (moves[next].score > moves[index].score) {
      std::swap(moves[index], moves[next]);
    }
  }

  return moves[index];
}

template<MoveType move_type>
List<ScoredMove> MovePicker::generate_and_score_moves() {
  List<Move> moves = move_gen::moves(move_type, board_);

  List<ScoredMove> scored_moves;
  for (int i = 0; i < moves.size(); i++) {
    scored_moves.push(ScoredMove(moves[i], score_move(moves[i])));
  }

  return scored_moves;
}

int MovePicker::score_move(Move &move) {
  const auto from = move.get_from();
  const auto to = move.get_to();

  // tt move get priority since it's the current stored best move
  if (move == tt_move_) {
    return std::numeric_limits<int>::max();
  }

  // queen and knight promotions get next priority
  switch (move.get_promotion_type()) {
    case PromotionType::kNone:
      break;
    case PromotionType::kQueen:
      return 1e9 - 1;
    case PromotionType::kKnight:
      return 1e9 - 2;
    default:
      return -1e9;
  }

  auto &state = board_.get_state();

  // winning/neutral captures are searched next
  // losing captures are searched last
  const int kBaseGoodCaptureScore = 1e8;
  const int kBaseBadCaptureScore = -1e8;
  if (move.is_capture(state)) {
    const auto attacker = state.get_piece_type(from);
    const auto victim = state.get_piece_type(to);

    int score =
        kMVVLVATable[attacker][to == state.en_passant && attacker == PieceType::kPawn ? PieceType::kPawn : victim];
    // good captures are searched first, bad captures are searched last
    if (eval::static_exchange(move, -eval::kSEEPieceScores[PieceType::kPawn], state)) {
      score += kBaseGoodCaptureScore;
      good_captures_.push(ScoredMove(move, score));
    } else {
      score += kBaseBadCaptureScore;
      bad_captures_.push(ScoredMove(move, score));
    }

    return score;
  }

  // killer moves are searched next (moves that caused a beta cutoff at this ply)
  const int kKillerMoveScore = kBaseGoodCaptureScore - 10;
  for (int i = 0; i < 2; i++) {
    if (search_stack_->killers[i] == move) {
      return kKillerMoveScore;
    }
  }

  // check if this move was a natural counter to the previous move (caused a beta cutoff)
  // complimentary to killer move heuristic
  const int kCounterMoveScore = kKillerMoveScore - 10;
  const auto &last_move = state.move_played;
  if (move == MoveOrderer::counter_moves[last_move.get_from()][last_move.get_to()]) {
    // counter moves should be searched right after killer moves
    return kCounterMoveScore;
  }

  // order moves that caused a beta cutoff by their own history score
  // the higher the depth this move caused a cutoff the more likely it move will be ordered first
  return MoveOrderer::move_history[state.turn][from][to];
}