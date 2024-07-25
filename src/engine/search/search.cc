#include "search.h"

#include <thread>

#include "constants.h"
#include "fmt/format.h"
#include "move_picker.h"
#include "time_mgmt.h"
#include "transpo.h"

namespace tables {

using LateMoveReductionTable =
    MultiArray<int, 2, kMaxSearchDepth + 1, kMaxMoves>;

int CalculateLMR(int depth, int moves, double base, double divisor) {
  auto ln_depth = std::log(depth), ln_moves = std::log(moves);
  return static_cast<int>(base + ln_depth * ln_moves / divisor);
}

LateMoveReductionTable GenerateLateMoveReductionTable() {
  LateMoveReductionTable table;

  // Initialize the depth reduction table for Late Move Reduction
  for (int depth = 1; depth <= kMaxSearchDepth; depth++) {
    for (int move = 1; move < kMaxMoves; move++) {
      table[true][depth][move] =
          CalculateLMR(depth, move, lmr_quiet_base, lmr_quiet_div);
      table[false][depth][move] =
          CalculateLMR(depth, move, lmr_tact_base, lmr_tact_div);
    }
  }

  return table;
}

const LateMoveReductionTable kLateMoveReduction =
    GenerateLateMoveReductionTable();

}  // namespace tables

Search::Search(Board &board)
    : board_(board),
      history_(board_.GetState()),
      sel_depth_(0),
      nodes_searched_(0),
      start_search_(false),
      searching_(false),
      stopped_(true),
      benching_(false),
      quit_(false) {
  search_stack_.Reset();
  threads_.emplace_back([this]() { Run(); });
}

Search::~Search() {
  quit_.store(true, std::memory_order_release);
  for (auto &thread : threads_) {
    if (thread.joinable()) {
      thread.join();
    }
  }
}

template <SearchType type>
void Search::IterativeDeepening() {
  constexpr bool print_info = type == SearchType::kRegular;

  const auto root_stack = &search_stack_.Front();
  root_stack->best_move = Move::NullMove();

  Move best_move = Move::NullMove();
  Score score = 0;

  for (int depth = 1; depth <= time_mgmt_.GetSearchDepth(); depth++) {
    sel_depth_ = 0;

    int window = static_cast<int>(asp_window_delta);
    Score alpha = -kInfiniteScore;
    Score beta = kInfiniteScore;

    if (depth >= asp_window_depth) {
      alpha = std::max<int>(-kInfiniteScore, score - window);
      beta = std::min<int>(kInfiniteScore, score + window);
    }

    int fail_high_count = 0;

    while (true) {
      const Score new_score = PVSearch<NodeType::kPV>(
          depth - fail_high_count, alpha, beta, root_stack, false);
      if (root_stack->best_move) {
        best_move = root_stack->best_move;
        score = new_score;
      }

      if (score <= alpha) {
        // Narrow beta to increase the chance of a fail high
        beta = (alpha + beta) / 2;

        // We failed low which means we don't have a move to play, so we widen
        // alpha
        alpha = std::max<int>(-kInfiniteScore, alpha - window);
        fail_high_count = 0;
      } else if (score >= beta) {
        // We failed high on a PV node, which is abnormal and requires further
        // verification
        beta = std::min<int>(kInfiniteScore, beta + window);

        // Spend less time searching as we expand the search window, unless
        // we're absolutely winning
        if (alpha < 2000 && fail_high_count < 2) {
          ++fail_high_count;
        }
      } else {
        // Quit now, since the score fell within the bounds of the aspiration
        // window
        break;
      }

      // Widen the aspiration window for the next iteration if we fail low or
      // high again
      window *= asp_window_growth;
    }

    if (!searching_ ||
        time_mgmt_.ShouldStop(best_move, depth, nodes_searched_)) {
      break;
    }

    if (searching_ && print_info) {
      const bool is_mate = eval::IsMateScore(score);
      fmt::println(
          "info depth {} seldepth {} score {} {} nodes {} time {} nps "
          "{} pv {}",
          depth,
          sel_depth_,
          is_mate ? "mate" : "cp",
          is_mate ? eval::MateIn(score) : score,
          nodes_searched_.load(),
          time_mgmt_.TimeElapsed(),
          nodes_searched_ * 1000 / time_mgmt_.TimeElapsed(),
          root_stack->pv.UCIFormat());
    }
  }

  Stop();

  if (print_info) {
    fmt::println("bestmove {}", best_move.ToString());
  }
}

template <NodeType node_type>
Score Search::QuiescentSearch(Score alpha,
                              Score beta,
                              SearchStackEntry *stack) {
  const auto &state = board_.GetState();
  stack->pv.Clear();

  if (stack->ply >= kMaxPlyFromRoot) {
    return eval::Evaluate(state);
  }

  sel_depth_ = std::max(sel_depth_, stack->ply);

  if (board_.IsDraw(stack->ply)) {
    return kDrawScore;
  }

  // A principal variation (PV) node falls inside the [alpha, beta] window and
  // is one which has most of its child moves searched
  constexpr bool in_pv_node = node_type != NodeType::kNonPV;

  // Probe the transposition table to see if we have already evaluated this
  // position
  const int tt_depth = state.InCheck();
  const auto &tt_entry = transposition_table[state.zobrist_key];
  const bool tt_hit = tt_entry.CompareKey(state.zobrist_key);

  auto tt_move = Move::NullMove();
  bool tt_was_in_pv = in_pv_node;

  if (tt_hit) {
    tt_was_in_pv |= tt_entry.was_in_pv;
    tt_move = tt_entry.move;
  }

  // Use the TT entry's evaluation if possible
  const bool can_use_tt_eval = tt_hit && tt_entry.CanUseScore(alpha, beta);

  // Saved scores from non-PV nodes must fall within the current alpha/beta
  // window to allow early cutoff
  if (!in_pv_node && tt_entry.depth >= tt_depth && can_use_tt_eval) {
    return TranspositionTableEntry::CorrectScore(tt_entry.score, stack->ply);
  }

  // Keep track of the original alpha for bound determination when updating the
  // transposition table
  const int original_alpha = alpha;

  int moves_seen = 0;
  Score best_score = kScoreNone;

  if (!state.InCheck()) {
    stack->static_eval =
        history_.correction_history->CorrectStaticEval(eval::Evaluate(state));

    if (tt_hit &&
        tt_entry.CanUseScore(stack->static_eval, stack->static_eval)) {
      best_score = tt_entry.score;
    } else {
      best_score = stack->static_eval;
    }

    // Early beta cutoff
    if (best_score >= beta) {
      return best_score;
    }

    // Alpha can be updated if no cutoff occurred
    alpha = std::max(alpha, best_score);
  }

  const Score futility_score = best_score + qs_fut_margin;

  MovePicker move_picker(
      MovePickerType::kQuiescence, board_, tt_move, history_, stack);
  while (const auto move = move_picker.Next()) {
    // Stop searching since all the good noisy moves have been searched,
    // unless we need to find a quiet evasion
    if (move_picker.GetStage() > MovePicker::Stage::kGoodNoisys &&
        moves_seen > 0) {
      break;
    }

    if (!board_.IsMoveLegal(move)) {
      continue;
    }

    // QS Futility Pruning: Prune capture moves that don't win material if the
    // static eval is behind alpha by some margin
    if (!state.InCheck() && move.IsCapture(state) && futility_score <= alpha &&
        !eval::StaticExchange(move, 1, state)) {
      best_score = std::max(best_score, futility_score);
      continue;
    }

    // Prefetch the TT entry for the next move as early as possible
    transposition_table.Prefetch(board_.PredictKeyAfter(move));

    nodes_searched_++;

    board_.MakeMove(move);
    const Score score = -QuiescentSearch<node_type>(-beta, -alpha, stack + 1);
    board_.UndoMove();

    if (!searching_ || ShouldQuit()) {
      return 0;
    }

    moves_seen++;

    if (score > best_score) {
      best_score = score;

      if (score > alpha) {
        stack->pv.Clear();
        stack->pv.Push(move);
        stack->pv.AppendPV((stack + 1)->pv);

        alpha = score;
        if (alpha >= beta) {
          // Beta cutoff: The opponent had a better move earlier in the tree
          break;
        }
      }
    }
  }

  if (state.InCheck() && moves_seen == 0) {
    return -kMateScore + stack->ply;
  }

  TranspositionTableEntry::Flag tt_flag;
  if (alpha >= beta) {
    // Beta cutoff
    tt_flag = TranspositionTableEntry::kLowerBound;
  } else {
    // Alpha failed to raise
    tt_flag = TranspositionTableEntry::kUpperBound;
  }

  // Always updating the transposition table a depth 0 limits these TT entries
  // to the quiescent search only
  const TranspositionTableEntry new_tt_entry(state.zobrist_key,
                                             tt_depth,
                                             tt_flag,
                                             tt_entry.age + 1,
                                             best_score,
                                             Move::NullMove(),
                                             tt_was_in_pv);
  transposition_table.Save(state.zobrist_key, stack->ply, new_tt_entry);

  return best_score;
}

template <NodeType node_type>
Score Search::PVSearch(int depth,
                       Score alpha,
                       Score beta,
                       SearchStackEntry *stack,
                       bool cut_node) {
  const auto &state = board_.GetState();
  stack->pv.Clear();

  if (stack->ply >= kMaxPlyFromRoot) {
    return eval::Evaluate(state);
  }

  sel_depth_ = std::max(sel_depth_, stack->ply);

  // Enter quiescent search when we've reached the depth limit
  assert(depth >= 0);
  if (depth == 0) {
    return QuiescentSearch<node_type>(alpha, beta, stack);
  }

  // A principal variation (PV) node falls inside the [alpha, beta] window and
  // is one which has most of its child moves searched
  constexpr bool in_pv_node = node_type != NodeType::kNonPV;
  // The root node is also a PV node by default
  const bool in_root = stack->ply == 0;

  if (!in_root) {
    if (board_.IsDraw(stack->ply)) {
      return kDrawScore;
    }

    // Mate Distance Pruning: Reduce the search space if we've already found a
    // mate
    alpha = std::max<Score>(alpha, -kMateScore + stack->ply);
    beta = std::min<Score>(beta, kMateScore - stack->ply - 1);

    // A beta cutoff may occur after reducing the search space
    if (alpha >= beta) {
      return alpha;
    }

    if (!searching_ || ShouldQuit()) {
      return 0;
    }
  }

  // Probe the transposition table to see if we have already evaluated this
  // position
  TranspositionTableEntry tt_entry;
  auto tt_move = Move::NullMove();
  bool tt_hit = false, can_use_tt_eval = false, tt_was_in_pv = in_pv_node;

  if (!stack->excluded_tt_move) {
    tt_entry = transposition_table[state.zobrist_key];
    tt_hit = tt_entry.CompareKey(state.zobrist_key);

    // Use the TT entry's evaluation if possible
    if (tt_hit) {
      can_use_tt_eval = tt_entry.CanUseScore(alpha, beta);
      tt_was_in_pv |= tt_entry.was_in_pv;
      tt_move = tt_entry.move;
    }

    // Saved scores from non-PV nodes must fall within the current alpha/beta
    // window to allow early cutoff
    if (!in_pv_node && can_use_tt_eval && tt_entry.depth >= depth) {
      return TranspositionTableEntry::CorrectScore(tt_entry.score, stack->ply);
    }
  }

  // Approximate the current evaluation at this node
  if (state.InCheck()) {
    stack->static_eval = stack->eval = kScoreNone;
  } else if (!stack->excluded_tt_move) {
    stack->static_eval =
        history_.correction_history->CorrectStaticEval(eval::Evaluate(state));

    // Adjust eval depending on if we can use the score stored in the TT
    if (tt_hit &&
        tt_entry.CanUseScore(stack->static_eval, stack->static_eval)) {
      stack->eval =
          TranspositionTableEntry::CorrectScore(tt_entry.score, stack->ply);
    } else {
      stack->eval = stack->static_eval;
    }
  }

  // This condition is dependent on if the side to move's static evaluation has
  // improved in the past two or four plies. It also used as a metric for
  // adjusting pruning thresholds
  stack->improving_rate = 0.0;
  bool improving = false;

  SearchStackEntry *past_stack = nullptr;
  if ((stack - 2)->static_eval != kScoreNone) {
    past_stack = stack - 2;
  } else if ((stack - 4)->static_eval != kScoreNone) {
    past_stack = stack - 4;
  }

  if (past_stack && !state.InCheck()) {
    improving = stack->static_eval > past_stack->static_eval;
    // Smoothen the improving rate from the static eval of our position in
    // previous turns
    const Score diff = stack->static_eval - past_stack->static_eval;
    stack->improving_rate = std::clamp(
        past_stack->improving_rate + diff / improving_rate_divisor, -1.0, 1.0);
  }

  stack->double_extensions = (stack - 1)->double_extensions;
  (stack + 1)->ClearKillerMoves();

  if (!in_pv_node && !state.InCheck() && !stack->excluded_tt_move) {
    // Reverse (Static) Futility Pruning: Cutoff if we think the position can't
    // fall below beta anytime soon
    if (depth <= rev_fut_depth && stack->eval < kMateScore - kMaxPlyFromRoot) {
      const int futility_margin = depth * (improving ? 40 : 74);
      if (stack->eval - futility_margin >= beta) {
        return stack->eval;
      }
    }

    // Null Move Pruning: Forfeit a move to our opponent and cutoff if we still
    // have the advantage
    if (!(stack - 1)->move.IsNull() && stack->eval >= beta) {
      // Avoid null move pruning a position with high zugzwang potential
      const BitBoard non_pawn_king_pieces =
          state.KinglessOccupied(state.turn) & ~state.Pawns(state.turn);
      if (non_pawn_king_pieces) {
        // Set the currently searched move in the stack for continuation history
        stack->move = Move::NullMove();
        stack->continuation_entry = nullptr;

        const int eval_reduction =
            std::min<int>(2, (stack->eval - beta) / null_move_re);
        const int reduction = std::clamp<int>(
            depth / null_move_rf + null_move_rb + eval_reduction, 0, depth);

        board_.MakeNullMove();
        const Score score = -PVSearch<NodeType::kNonPV>(
            depth - reduction, -beta, -beta + 1, stack + 1, !cut_node);
        board_.UndoMove();

        if (ShouldQuit()) {
          return 0;
        }

        // Prune if the result from our null window search around beta indicates
        // that the opponent still doesn't gain an advantage from the null move
        if (score >= beta) {
          return score >= kMateScore - kMaxPlyFromRoot ? beta : score;
        }
      }
    }
  }

  // Internal Iterative Reduction: Move ordering is expected to be worse with no
  // TT move, so we save time on searching this position now
  if ((in_pv_node || cut_node) && depth >= iir_depth &&
      !stack->excluded_tt_move && !tt_move) {
    depth--;
  }

  // Keep track of the original alpha for bound determination when updating the
  // transposition table
  const int original_alpha = alpha;
  // Keep track of quiet and capture moves that failed to cause a beta cutoff
  MoveList quiets, captures;

  const BitBoard threats = state.threats;

  int moves_seen = 0;
  Score best_score = kScoreNone;
  Move best_move = Move::NullMove();

  MovePicker move_picker(
      MovePickerType::kSearch, board_, tt_move, history_, stack);
  while (const auto move = move_picker.Next()) {
    if (move == stack->excluded_tt_move || !board_.IsMoveLegal(move)) {
      continue;
    }

    // Prefetch the TT entry for the next move as early as possible
    transposition_table.Prefetch(board_.PredictKeyAfter(move));

    const bool is_quiet = !move.IsNoisy(state);
    const bool is_capture = move.IsCapture(state);

    // Pruning guards
    if (!in_root && best_score > -kMateScore + kMaxPlyFromRoot) {
      // Late Move Pruning: Skip (late) quiet moves if we've already searched
      // the most promising moves
      const int lmp_threshold =
          static_cast<int>((lmp_base + depth * depth) /
                           (lmp_mult - std::max(0.0, stack->improving_rate)));
      if (is_quiet && moves_seen >= lmp_threshold) {
        move_picker.SkipQuiets();
        continue;
      }

      // Futility Pruning: Skip (futile) quiet moves at near-leaf nodes when
      // there's a low chance to raise alpha
      const int futility_margin = fut_margin_base + fut_margin_mult * depth;
      if (depth <= fut_prune_depth && !state.InCheck() && is_quiet &&
          stack->eval + futility_margin < alpha) {
        move_picker.SkipQuiets();
        continue;
      }

      // Static Exchange Evaluation (SEE) Pruning: Skip moves that lose too much
      // material
      const int see_threshold =
          is_quiet ? see_quiet_thresh * depth : see_noisy_thresh * depth;
      if (depth <= see_prune_depth && moves_seen >= 1 &&
          !eval::StaticExchange(move, see_threshold, state)) {
        continue;
      }

      // History Pruning: Prune quiet moves with a low history score moves at
      // near-leaf nodes
      if (is_quiet) {
        const int history_score =
            history_.GetQuietMoveScore(move, threats, stack);
        if (depth <= hist_prune_depth &&
            history_score <= hist_thresh_base + hist_thresh_mult * depth) {
          move_picker.SkipQuiets();
          continue;
        }
      }
    }

    int extensions = 0;

    // Singular Extensions: If a TT move exists and its score is accurate enough
    // (close enough in depth), we perform a reduced-depth search with the TT
    // move excluded to see if any other moves can beat it.
    if (!in_root && depth >= 8 && move == tt_move) {
      const bool is_accurate_tt_score =
          tt_entry.depth + 4 >= depth &&
          tt_entry.flag != TranspositionTableEntry::kUpperBound &&
          std::abs(tt_entry.score) < kMateScore - kMaxPlyFromRoot;

      if (is_accurate_tt_score) {
        const int reduced_depth = (depth - 1) / 2;
        const Score new_beta = tt_entry.score - depth * sing_ext_margin;

        stack->excluded_tt_move = tt_move;
        const Score tt_move_excluded_score = PVSearch<NodeType::kNonPV>(
            reduced_depth, new_beta - 1, new_beta, stack, cut_node);
        stack->excluded_tt_move = Move::NullMove();

        if (ShouldQuit()) {
          return 0;
        }

        // No move was able to beat the TT entries score, so we extend the TT
        // move's search
        if (tt_move_excluded_score < new_beta) {
          // Double extend if the TT move is singular by a big margin
          if (!in_pv_node &&
              tt_move_excluded_score < new_beta - sing_double_margin &&
              (stack->double_extensions <= 8)) {
            extensions = 2;
            stack->double_extensions++;
          } else {
            extensions = 1;
          }
        }
        // Multi-cut: The singular search had a beta cutoff, indicating that the
        // TT move was not singular. Therefore, we prune if the same score would
        // cause a cutoff based on our current search window
        else if (new_beta >= beta) {
          return new_beta;
        }
        // Negative Extensions: Search less since the TT move was not singular,
        // and it might cause a beta cutoff again.
        else if (tt_entry.score >= beta) {
          extensions = -1;
        }
      }
    }

    // Check Extensions: Integral's not yet strong enough to simplify this out
    if (state.InCheck()) {
      extensions++;
    }

    // Set the currently searched move in the stack for continuation history
    stack->move = move;
    stack->continuation_entry = history_.continuation_history->GetEntry(move);

    board_.MakeMove(move);

    nodes_searched_++;

    const U32 prev_nodes_searched = nodes_searched_;
    const int new_depth = depth + extensions - 1;

    // Principal Variation Search (PVS)
    bool needs_full_search;
    Score score;

    // Late Move Reduction: Moves that are less likely to be good (due to the
    // move ordering) are searched at lower depths
    const int lmr_move_threshold = 1 + in_root * 2;
    if (depth > 2 && moves_seen >= lmr_move_threshold) {
      int reduction = tables::kLateMoveReduction[is_quiet][depth][moves_seen];
      reduction += !in_pv_node - tt_was_in_pv;
      reduction += cut_node;
      reduction -= is_quiet * history_.GetQuietMoveScore(move, threats, stack) /
                   static_cast<int>(lmr_hist_div);
      reduction -= state.InCheck();

      // Ensure the reduction doesn't give us a depth below 0
      reduction = std::clamp<int>(reduction, 0, new_depth - 1);

      // Null window search at reduced depth to see if the move has potential
      score = -PVSearch<NodeType::kNonPV>(
          new_depth - reduction, -alpha - 1, -alpha, stack + 1, true);
      needs_full_search = score > alpha && reduction != 0;
    } else {
      // If we didn't perform late move reduction, then we search this move at
      // full depth with a null window search if we don't expect it to be a PV
      // move
      needs_full_search = !in_pv_node || moves_seen >= 1;
    }

    // Either the move has potential from a reduced depth search or it's not
    // expected to be a PV move, therefore we search it with a null window
    if (needs_full_search) {
      score = -PVSearch<NodeType::kNonPV>(
          new_depth, -alpha - 1, -alpha, stack + 1, !cut_node);
    }

    // Perform a full window search on this move if it's known to be good
    if (in_pv_node && (score > alpha || moves_seen == 0)) {
      score =
          -PVSearch<NodeType::kPV>(new_depth, -beta, -alpha, stack + 1, false);
    }

    board_.UndoMove();

    if (in_root) {
      U32 &nodes_spent = time_mgmt_.NodesSpent(move);
      nodes_spent += nodes_searched_ - prev_nodes_searched;
    }

    if (!searching_ || ShouldQuit()) {
      return 0;
    }

    moves_seen++;

    if (score > best_score) {
      best_score = score;

      if (score > alpha) {
        stack->best_move = best_move = move;

        stack->pv.Clear();
        stack->pv.Push(move);
        stack->pv.AppendPV((stack + 1)->pv);

        alpha = score;
        if (alpha >= beta) {
          if (is_quiet) {
            stack->AddKillerMove(move);
            history_.quiet_history->UpdateScore(stack, depth, threats, quiets);
            history_.continuation_history->UpdateScore(stack, depth, quiets);
          } else if (is_capture) {
            history_.capture_history->UpdateScore(stack, depth);
          }
          // Beta cutoff: The opponent had a better move earlier in the tree
          break;
        }
      }
    }

    // Penalize the history score of moves that failed to raise alpha
    if (move != best_move) {
      if (is_quiet)
        quiets.Push(move);
      else if (is_capture)
        captures.Push(move);

      // Since "good" captures are expected to be the best moves, we apply a
      // penalty to all captures even in the case where the best move was quiet
      history_.capture_history->Penalize(depth, captures);
    }
  }

  // Terminal state if no legal moves were found
  if (moves_seen == 0) {
    return state.InCheck() ? -kMateScore + stack->ply : kDrawScore;
  }

  if (!stack->excluded_tt_move) {
    auto tt_flag = TranspositionTableEntry::kExact;
    if (alpha >= beta) {
      // Beta cutoff
      tt_flag = TranspositionTableEntry::kLowerBound;
    } else if (alpha <= original_alpha) {
      // Alpha failed to raise
      tt_flag = TranspositionTableEntry::kUpperBound;
    }

    // Attempt to update the transposition table with the evaluation of this
    // position
    const TranspositionTableEntry new_tt_entry(state.zobrist_key,
                                               depth,
                                               tt_flag,
                                               tt_entry.age + 1,
                                               best_score,
                                               best_move,
                                               tt_was_in_pv);
    transposition_table.Save(state.zobrist_key, stack->ply, new_tt_entry);

    if (!state.InCheck() && (!best_move || !best_move.IsNoisy(state))) {
      history_.correction_history->UpdateScore(
          stack, best_score, tt_flag, depth);
    }
  }

  return best_score;
}

void Search::Bench(int depth) {
  {
    std::unique_lock lock(mutex_);
    if (searching_.load(std::memory_order_relaxed)) return;

    TimeConfig time_config{.depth = depth};
    time_mgmt_.SetConfig(time_config);
    time_mgmt_.Start();
  }
  nodes_searched_.store(0, std::memory_order_seq_cst);
  benching_.store(true, std::memory_order_seq_cst);
  stopped_.store(false, std::memory_order_seq_cst);
  start_search_.store(true, std::memory_order_seq_cst);

  while (!stopped_.load(std::memory_order_relaxed)) {
    std::this_thread::yield();
  };
}

TimeManagement &Search::GetTimeManagement() {
  return time_mgmt_;
}

void Search::Run() {
  while (!quit_.load(std::memory_order_acquire)) {
    if (start_search_.load(std::memory_order_relaxed)) {
      start_search_.store(false, std::memory_order_seq_cst);
      searching_.store(true, std::memory_order_seq_cst);

      if (benching_.load(std::memory_order_relaxed)) {
        IterativeDeepening<SearchType::kBench>();
      } else {
        IterativeDeepening<SearchType::kRegular>();
      }
    }
  }
}

bool Search::ShouldQuit() {
  return stopped_.load(std::memory_order_relaxed) ||
         (search_stack_.Front().best_move &&
          time_mgmt_.TimesUp(nodes_searched_.load(std::memory_order_relaxed)));
}

void Search::Start(TimeConfig &time_config) {
  {
    if (searching_.load(std::memory_order_acquire)) return;

    std::unique_lock lock(mutex_);
    time_mgmt_.SetConfig(time_config);
    time_mgmt_.Start();
  }
  nodes_searched_.store(0, std::memory_order_seq_cst);
  start_search_.store(true, std::memory_order_seq_cst);
  stopped_.store(false, std::memory_order_seq_cst);
}

void Search::Stop() {
  if (!searching_.load(std::memory_order_acquire)) return;

  stopped_.store(true, std::memory_order_seq_cst);
  searching_.store(false, std::memory_order_seq_cst);
  benching_.store(false, std::memory_order_seq_cst);

  std::unique_lock lock(mutex_);
  time_mgmt_.Stop();
}

void Search::Wait() {
  while (searching_.load(std::memory_order_relaxed)) {
    std::this_thread::yield();
  }
}

void Search::NewGame() {
  if (stopped_.load(std::memory_order_relaxed)) {
    transposition_table.Clear();
    eval::pawn_cache.Clear();
    history_.Clear();
    search_stack_.Reset();
  }
}

U64 Search::GetNodesSearched() const {
  return nodes_searched_;
}