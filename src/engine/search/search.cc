#include "search.h"

#include <thread>

#include "constants.h"
#include "fmt/format.h"
#include "move_picker.h"
#include "syzygy/syzygy.h"
#include "time_mgmt.h"
#include "transpo.h"

namespace search {

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
      start_barrier_(2),
      stop_barrier_(2),
      search_end_barrier_(1),
      next_thread_id_(0),
      searching_(false),
      stopped_(true) {}

Search::~Search() {
  QuitThreads();
}

template <SearchType type>
void Search::IterativeDeepening(Thread &thread) {
  constexpr bool print_info = type == SearchType::kRegular;

  const auto root_stack = &thread.stack.Front();
  root_stack->best_move = Move::NullMove();

  Move best_move = Move::NullMove();
  Score score = 0;

  for (int depth = 1; depth <= time_mgmt_.GetSearchDepth(); depth++) {
    thread.sel_depth = 0;

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
          thread, depth - fail_high_count, alpha, beta, root_stack, false);
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

    if (stopped_ ||
        time_mgmt_.ShouldStop(best_move, depth, thread.nodes_searched)) {
      break;
    }

    if (thread.IsMainThread() && !stopped_ && print_info) {
      const U64 total_nodes = GetNodesSearched();
      const bool is_mate = eval::IsMateScore(score);
      fmt::println(
          "info depth {} seldepth {} score {} {} nodes {} time {} nps "
          "{} hashfull {}{}{} pv {}",
          depth,
          thread.sel_depth,
          is_mate ? "mate" : "cp",
          is_mate ? eval::MateIn(score) : score,
          total_nodes,
          time_mgmt_.TimeElapsed(),
          total_nodes * 1000 / time_mgmt_.TimeElapsed(),
          transposition_table.HashFull(),
          syzygy::enabled ? " tbhits " : "",
          syzygy::enabled ? std::to_string(thread.tb_hits) + " " : "",
          root_stack->pv.UCIFormat());
    }
  }

  time_mgmt_.Stop();

  // Don't report the best move until manually stopped with go infinite
  if (time_mgmt_.GetType() == TimeType::kInfinite) {
    while (!stopped_.load(std::memory_order_relaxed)) std::this_thread::yield();
  }

  searching_.store(false, std::memory_order_seq_cst);
  stopped_.store(true, std::memory_order_seq_cst);

  if constexpr (type == SearchType::kRegular) {
    // search_end_barrier_.ArriveAndWait();
  }

  if (thread.IsMainThread()) {
    // Age the transposition table to recognize TT entries from past searches
    transposition_table.Age();

    if (print_info) {
      fmt::println("bestmove {}", best_move.ToString());
    }
  }
}

template <NodeType node_type>
Score Search::QuiescentSearch(Thread &thread,
                              Score alpha,
                              Score beta,
                              SearchStackEntry *stack) {
  auto &board = thread.board;
  const auto &state = board.GetState();

  stack->pv.Clear();

  if (stack->ply >= kMaxPlyFromRoot) {
    return eval::Evaluate(state);
  }

  thread.sel_depth = std::max(thread.sel_depth, stack->ply);

  if (board.IsDraw(stack->ply)) {
    return kDrawScore;
  }

  // A principal variation (PV) node falls inside the [alpha, beta] window and
  // is one which has most of its child moves searched
  constexpr bool in_pv_node = node_type != NodeType::kNonPV;

  // Probe the transposition table to see if we have already evaluated this
  // position
  const int tt_depth = state.InCheck();
  const auto tt_entry = transposition_table.Probe(state.zobrist_key);
  const bool tt_hit = tt_entry->CompareKey(state.zobrist_key);

  auto tt_move = Move::NullMove();
  bool tt_was_in_pv = in_pv_node;

  if (tt_hit) {
    tt_was_in_pv |= tt_entry->GetWasPV();
    tt_move = tt_entry->move;
  }

  // Use the TT entry's evaluation if possible
  const bool can_use_tt_eval = tt_hit && tt_entry->CanUseScore(alpha, beta);

  // Saved scores from non-PV nodes must fall within the current alpha/beta
  // window to allow early cutoff
  if (!in_pv_node && can_use_tt_eval && tt_entry->depth >= tt_depth) {
    return TranspositionTableEntry::CorrectScore(tt_entry->score, stack->ply);
  }

  // Keep track of the original alpha for bound determination when updating the
  // transposition table
  const int original_alpha = alpha;

  int moves_seen = 0;
  Score best_score = kScoreNone;

  if (!state.InCheck()) {
    stack->static_eval = thread.history.correction_history->CorrectStaticEval(
        state, eval::Evaluate(state));

    if (tt_hit &&
        tt_entry->CanUseScore(stack->static_eval, stack->static_eval)) {
      best_score = tt_entry->score;
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
      MovePickerType::kQuiescence, board, tt_move, thread.history, stack);
  while (const auto move = move_picker.Next()) {
    // Stop searching since all the good noisy moves have been searched,
    // unless we need to find a quiet evasion
    if (move_picker.GetStage() > MovePicker::Stage::kGoodNoisys &&
        moves_seen > 0) {
      break;
    }

    if (!board.IsMoveLegal(move)) {
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
    transposition_table.Prefetch(board.PredictKeyAfter(move));

    ++thread.nodes_searched;

    board.MakeMove(move);
    const Score score =
        -QuiescentSearch<node_type>(thread, -beta, -alpha, stack + 1);
    board.UndoMove();

    if (ShouldQuit()) {
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
                                             best_score,
                                             Move::NullMove(),
                                             tt_was_in_pv);
  transposition_table.Save(
      tt_entry, new_tt_entry, state.zobrist_key, stack->ply);

  return best_score;
}

template <NodeType node_type>
Score Search::PVSearch(Thread &thread,
                       int depth,
                       Score alpha,
                       Score beta,
                       SearchStackEntry *stack,
                       bool cut_node) {
  auto &board = thread.board;
  const auto &state = board.GetState();

  stack->pv.Clear();

  if (stack->ply >= kMaxPlyFromRoot) {
    return eval::Evaluate(state);
  }

  thread.sel_depth = std::max(thread.sel_depth, stack->ply);

  // Enter quiescent search when we've reached the depth limit
  assert(depth >= 0);
  if (depth == 0) {
    return QuiescentSearch<node_type>(thread, alpha, beta, stack);
  }

  // A principal variation (PV) node falls inside the [alpha, beta] window and
  // is one which has most of its child moves searched
  constexpr bool in_pv_node = node_type != NodeType::kNonPV;
  // The root node is also a PV node by default
  const bool in_root = stack->ply == 0;

  if (!in_root) {
    if (board.IsDraw(stack->ply)) {
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

    if (ShouldQuit()) {
      return 0;
    }
  }

  // Probe the transposition table to see if we have already evaluated this
  // position
  TranspositionTableEntry *tt_entry = nullptr;
  auto tt_move = Move::NullMove();
  bool tt_hit = false, can_use_tt_eval = false, tt_was_in_pv = in_pv_node;

  if (!stack->excluded_tt_move) {
    tt_entry = transposition_table.Probe(state.zobrist_key);
    tt_hit = tt_entry->CompareKey(state.zobrist_key);

    // Use the TT entry's evaluation if possible
    if (tt_hit) {
      can_use_tt_eval = tt_entry->CanUseScore(alpha, beta);
      tt_was_in_pv |= tt_entry->GetWasPV();
      tt_move = tt_entry->move;
    }

    // Saved scores from non-PV nodes must fall within the current alpha/beta
    // window to allow early cutoff
    if (!in_pv_node && can_use_tt_eval && tt_entry->depth >= depth) {
      return TranspositionTableEntry::CorrectScore(tt_entry->score, stack->ply);
    }
  }

  // Probe the Syzygy table bases
  int syzygy_min_score = -kMateScore, syzygy_max_score = kMateScore;
  if (syzygy::enabled && !in_root && !stack->excluded_tt_move &&
      state.Occupied().PopCount() <= 7 && depth <= syzygy::probe_depth &&
      state.fifty_moves_clock == 0 &&
      !state.castle_rights.CanCastle(state.turn) &&
      !state.castle_rights.CanCastle(FlipColor(state.turn))) {
    const auto tb_result = syzygy::ProbePosition(state);
    if (tb_result != syzygy::ProbeResult::kFailed) {
      Score score;
      TranspositionTableEntry::Flag tt_flag;

      if (tb_result == syzygy::ProbeResult::kWin) {
        score = kTBWinScore - stack->ply;
        tt_flag = TranspositionTableEntry::kLowerBound;
      } else if (tb_result == syzygy::ProbeResult::kLoss) {
        score = -kTBWinScore + stack->ply;
        tt_flag = TranspositionTableEntry::kUpperBound;
      } else {
        score = kDrawScore;
        tt_flag = TranspositionTableEntry::kExact;
      }

      ++thread.tb_hits;

      if (tt_flag == TranspositionTableEntry::kExact ||
          (tt_flag == TranspositionTableEntry::kLowerBound ? score >= beta
                                                           : score <= alpha)) {
        // Save the table base score to the transposition table
        const TranspositionTableEntry new_tt_entry(state.zobrist_key,
                                                   depth,
                                                   tt_flag,
                                                   score,
                                                   Move::NullMove(),
                                                   tt_was_in_pv);
        transposition_table.Save(
            tt_entry, new_tt_entry, state.zobrist_key, stack->ply);
        return score;
      }

      if constexpr (in_pv_node) {
        if (tt_flag == TranspositionTableEntry::kUpperBound) {
          syzygy_max_score = score;
        } else if (tt_flag == TranspositionTableEntry::kLowerBound) {
          syzygy_min_score = score;
          // We can safely try to raise alpha if we have a lower bound score
          alpha = std::max(alpha, syzygy_min_score);
        }
      }
    }
  }

  // Approximate the current evaluation at this node
  if (state.InCheck()) {
    stack->static_eval = stack->eval = kScoreNone;
  } else if (!stack->excluded_tt_move) {
    stack->static_eval = thread.history.correction_history->CorrectStaticEval(
        state, eval::Evaluate(state));

    // Adjust eval depending on if we can use the score stored in the TT
    if (tt_hit &&
        tt_entry->CanUseScore(stack->static_eval, stack->static_eval)) {
      stack->eval =
          TranspositionTableEntry::CorrectScore(tt_entry->score, stack->ply);
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

        board.MakeNullMove();
        const Score score = -PVSearch<NodeType::kNonPV>(
            thread, depth - reduction, -beta, -beta + 1, stack + 1, !cut_node);
        board.UndoMove();

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
      MovePickerType::kSearch, board, tt_move, thread.history, stack);
  while (const auto move = move_picker.Next()) {
    if (move == stack->excluded_tt_move || !board.IsMoveLegal(move)) {
      continue;
    }

    // Prefetch the TT entry for the next move as early as possible
    transposition_table.Prefetch(board.PredictKeyAfter(move));

    const bool is_quiet = !move.IsNoisy(state);
    const bool is_capture = move.IsCapture(state);
    const int history_score =
        is_capture
            ? thread.history.GetCaptureMoveScore(state, move)
            : thread.history.GetQuietMoveScore(state, move, threats, stack);

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
          tt_entry->depth + 4 >= depth &&
          tt_entry->GetFlag() != TranspositionTableEntry::kUpperBound &&
          std::abs(tt_entry->score) < kMateScore - kMaxPlyFromRoot;

      if (is_accurate_tt_score) {
        const int reduced_depth = (depth - 1) / 2;
        const Score new_beta = tt_entry->score - depth * sing_ext_margin;

        stack->excluded_tt_move = tt_move;
        const Score tt_move_excluded_score = PVSearch<NodeType::kNonPV>(
            thread, reduced_depth, new_beta - 1, new_beta, stack, cut_node);
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
        else if (tt_entry->score >= beta) {
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
    stack->continuation_entry =
        thread.history.continuation_history->GetEntry(state, move);

    board.MakeMove(move);

    const U32 prev_nodes_searched = ++thread.nodes_searched;
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
      reduction -= is_quiet * history_score / static_cast<int>(lmr_hist_div);
      reduction -= state.InCheck();

      // Ensure the reduction doesn't give us a depth below 0
      reduction = std::clamp<int>(reduction, 0, new_depth - 1);

      // Null window search at reduced depth to see if the move has potential
      score = -PVSearch<NodeType::kNonPV>(
          thread, new_depth - reduction, -alpha - 1, -alpha, stack + 1, true);
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
          thread, new_depth, -alpha - 1, -alpha, stack + 1, !cut_node);
    }

    // Perform a full window search on this move if it's known to be good
    if (in_pv_node && (score > alpha || moves_seen == 0)) {
      score = -PVSearch<NodeType::kPV>(
          thread, new_depth, -beta, -alpha, stack + 1, false);
    }

    board.UndoMove();

    if (in_root && thread.IsMainThread()) {
      U32 &nodes_spent = time_mgmt_.NodesSpent(move);
      nodes_spent += thread.nodes_searched - prev_nodes_searched;
    }

    if (ShouldQuit()) {
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
            thread.history.quiet_history->UpdateScore(
                state, stack, depth, threats, quiets);
            thread.history.continuation_history->UpdateScore(
                state, stack, depth, quiets);
          } else if (is_capture) {
            thread.history.capture_history->UpdateScore(state, stack, depth);
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
      thread.history.capture_history->Penalize(state, depth, captures);
    }
  }

  // Terminal state if no legal moves were found
  if (moves_seen == 0) {
    return state.InCheck() ? -kMateScore + stack->ply : kDrawScore;
  }

  if (syzygy::enabled) {
    best_score = std::clamp(best_score, syzygy_min_score, syzygy_max_score);
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
    const TranspositionTableEntry new_tt_entry(
        state.zobrist_key, depth, tt_flag, best_score, best_move, tt_was_in_pv);
    transposition_table.Save(
        tt_entry, new_tt_entry, state.zobrist_key, stack->ply);

    if (!state.InCheck() && (!best_move || !best_move.IsNoisy(state))) {
      thread.history.correction_history->UpdateScore(
          state, stack, best_score, tt_flag, depth);
    }
  }

  return best_score;
}

void Search::Run(Thread &thread) {
  while (true) {
    stop_barrier_.ArriveAndWait();
    start_barrier_.ArriveAndWait();

    if (quit_.load(std::memory_order_acquire)) {
      return;
    }

    if (benching_.load(std::memory_order_acquire)) {
      IterativeDeepening<SearchType::kBench>(thread);
    } else {
      IterativeDeepening<SearchType::kRegular>(thread);
    }
  }
}

void Search::QuitThreads() {
  if (threads_.empty()) {
    return;
  }

  quit_.store(true, std::memory_order_seq_cst);
  stop_barrier_.ArriveAndWait();
  start_barrier_.ArriveAndWait();

  for (auto &thread : threads_) {
    if (thread.raw_thread.joinable()) {
      thread.raw_thread.join();
    }
  }
}

bool Search::ShouldQuit() {
  return stopped_.load(std::memory_order_relaxed) ||
         (threads_[0].stack.Front().best_move &&
          time_mgmt_.TimesUp(threads_[0].nodes_searched));
}

void Search::Start(TimeConfig &time_config) {
  if (searching_.load(std::memory_order_relaxed)) {
    return;
  }

  time_mgmt_.SetConfig(time_config);
  time_mgmt_.Start();

  // Wait until all threads have been stopped
  stop_barrier_.ArriveAndWait();

  for (auto &thread : threads_) {
    thread.board.CopyFrom(board_);
    thread.nodes_searched = 0;
    thread.sel_depth = 0;
    thread.tb_hits = 0;
  }

  stopped_.store(false, std::memory_order_seq_cst);
  searching_.store(true, std::memory_order_seq_cst);

  // Wait until all threads receive the start signal
  start_barrier_.ArriveAndWait();
}

U64 Search::Bench(int depth) {
  auto config = TimeConfig{.depth = depth};
  benching_.store(true, std::memory_order_seq_cst);

  Start(config);
  Wait();

  benching_.store(false, std::memory_order_seq_cst);
  return GetNodesSearched();
}

void Search::Stop() {
  if (searching_.load(std::memory_order_relaxed)) {
    stopped_.store(true, std::memory_order_seq_cst);
  }
}

void Search::SetThreadCount(U16 count) {
  QuitThreads();
  quit_.store(false, std::memory_order_seq_cst);

  search_end_barrier_.Reset(count);
  // Count + 1 so that we can arrive/wait in the UCI thread as well
  stop_barrier_.Reset(count + 1);
  start_barrier_.Reset(count + 1);

  threads_.clear();
  threads_.shrink_to_fit();
  threads_.reserve(count);

  next_thread_id_ = 0;
  for (U16 i = 0; i < count; i++) {
    auto &thread = threads_.emplace_back(next_thread_id_++, board_);
    thread.raw_thread = std::thread([this, &thread]() { Run(thread); });
  }
}

void Search::Wait() {
  while (!stopped_.load(std::memory_order_relaxed)) std::this_thread::yield();
}

void Search::NewGame() {
  if (stopped_.load(std::memory_order_relaxed)) {
    transposition_table.Clear();
    eval::pawn_cache.Clear();

    for (auto &thread : threads_) {
      thread.NewGame();
    }
  }
}

U64 Search::GetNodesSearched() const {
  return std::accumulate(
      threads_.begin(), threads_.end(), 0ULL, [](auto sum, const auto &thread) {
        return sum + thread.nodes_searched;
      });
}

TimeManagement &Search::GetTimeManagement() {
  return time_mgmt_;
}

}  // namespace search