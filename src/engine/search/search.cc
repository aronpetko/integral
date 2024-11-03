#include "search.h"

#include <algorithm>
#include <numeric>
#include <thread>

#include "../uci/reporter.h"
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
          CalculateLMR(depth, move, kLmrQuietBase, kLmrQuietDiv);
      table[false][depth][move] =
          CalculateLMR(depth, move, kLmrTactBase, kLmrTactDiv);
    }
  }

  return table;
}

inline LateMoveReductionTable kLateMoveReduction =
    GenerateLateMoveReductionTable();

}  // namespace tables

Search::Search(Board &board)
    : board_(board),
      stop_barrier_(2),
      start_barrier_(2),
      search_end_barrier_(1),
      next_thread_id_(0),
      searching_threads_(0) {}

Search::~Search() {
  if (!quit_.load(std::memory_order_acquire)) {
    QuitThreads();
  }
}

template <SearchType type>
void Search::IterativeDeepening(Thread &thread) {
  constexpr bool print_info = type == SearchType::kRegular;

  const auto root_stack = &thread.stack.Front();
  root_stack->best_move = Move::NullMove();

  Move best_move = Move::NullMove();
  Score score = 0;

  for (int depth = 1; depth <= time_mgmt_.GetSearchDepth(); depth++) {
    thread.sel_depth = 0, thread.root_depth = depth;

    int window = static_cast<int>(kAspWindowDelta);
    Score alpha = -kInfiniteScore;
    Score beta = kInfiniteScore;

    if (depth >= kAspWindowDepth) {
      alpha = std::max<int>(-kInfiniteScore, score - window);
      beta = std::min<int>(kInfiniteScore, score + window);
    }

    int fail_high_count = 0;

    while (true) {
      const Score new_score = PVSearch<NodeType::kPV>(
          thread, depth - fail_high_count, alpha, beta, root_stack, false);

      if (root_stack->best_move) {
        best_move = root_stack->best_move;
      }

      if (ShouldQuit(thread)) {
        break;
      }

      score = new_score;

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
      window *= kAspWindowGrowth;
    }

    thread.scores[depth] = score;

    if (thread.IsMainThread() &&
        time_mgmt_.ShouldStop(best_move, depth, thread)) {
      break;
    }

    std::unique_ptr<uci::reporter::ReportInfo> report_info;
    if (uci::reporter::using_uci) {
      report_info = std::make_unique<uci::reporter::UCIReportInfo>();
    } else {
      report_info = std::make_unique<uci::reporter::PrettyReportInfo>();
    }

    if (thread.IsMainThread() && !stop_.load(std::memory_order_relaxed) &&
        print_info) {
      const bool is_mate = eval::IsMateScore(root_stack->score);
      const auto nodes_searched = GetNodesSearched();
      report_info->Print(depth,
                         thread.sel_depth,
                         is_mate,
                         root_stack->score,
                         nodes_searched,
                         time_mgmt_.TimeElapsed(),
                         nodes_searched * 1000 / time_mgmt_.TimeElapsed(),
                         transposition_table_.HashFull(),
                         syzygy::enabled,
                         thread.tb_hits,
                         root_stack->pv.UCIFormat());
    }
  }

  thread.previous_score = score;

  const auto SendStoppedSignal = [&]() {
    if constexpr (type == SearchType::kRegular) {
      {
        std::unique_lock lock(thread_stopped_mutex_);
        // Wait on the other threads to finish before reporting the best move
        --searching_threads_;
        thread_stopped_signal_.notify_all();
      }
      search_end_barrier_.ArriveAndWait();
    }
  };

  if (thread.IsMainThread()) {
    // Don't report the best move until manually stopped with go infinite
    if (time_mgmt_.IsInfinite()) {
      while (!stop_.load(std::memory_order_relaxed)) std::this_thread::yield();
    }

    std::unique_lock lock(stop_mutex_);
    stop_.store(true, std::memory_order_seq_cst);
    SendStoppedSignal();

    // Age the transposition table to recognize TT entries from past searches
    transposition_table_.Age();

    if (print_info) {
      fmt::println("bestmove {}", best_move.ToString());
    }
  } else {
    SendStoppedSignal();
  }
}

template <NodeType node_type>
Score Search::QuiescentSearch(Thread &thread,
                              Score alpha,
                              Score beta,
                              StackEntry *stack) {
  auto &board = thread.board;
  auto &history = thread.history;
  const auto &state = board.GetState();

  stack->pv.Clear();

  if (stack->ply >= kMaxPlyFromRoot) {
    return eval::Evaluate(board);
  }

  thread.sel_depth = std::max(thread.sel_depth, stack->ply);

  if (board.IsDraw(stack->ply)) {
    return kDrawScore;
  }

  stack->in_check = state.InCheck();

  // A principal variation (PV) node falls inside the [alpha, beta] window and
  // is one which has most of its child moves searched
  constexpr bool in_pv_node = node_type != NodeType::kNonPV;

  // Probe the transposition table to see if we have already evaluated this
  // position
  const int tt_depth = state.InCheck();
  const auto tt_entry = transposition_table_.Probe(state.zobrist_key);
  const bool tt_hit = tt_entry->CompareKey(state.zobrist_key);

  auto tt_move = Move::NullMove();
  bool tt_was_in_pv = in_pv_node;
  Score tt_static_eval = kScoreNone;

  if (tt_hit) {
    tt_was_in_pv |= tt_entry->GetWasPV();
    tt_move = tt_entry->move;
    tt_static_eval = tt_entry->static_eval;
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
  Score raw_static_eval = kScoreNone;

  if (tt_static_eval != kScoreNone) {
    raw_static_eval = tt_static_eval;
  } else {
    raw_static_eval = eval::Evaluate(board);
  }

  if (!stack->in_check) {
    stack->static_eval = history.correction_history->CorrectStaticEval(
        state, stack, raw_static_eval);

    if (tt_hit &&
        tt_entry->CanUseScore(stack->static_eval, stack->static_eval)) {
      best_score = tt_entry->score;
    } else {
      best_score = stack->static_eval;
    }

    // Early beta cutoff
    if (best_score >= beta) {
      // Save the static eval in the TT if we have nothing yet
      if (!tt_hit) {
        const TranspositionTableEntry new_tt_entry(
            state.zobrist_key,
            tt_depth,
            TranspositionTableEntry::kNone,
            kScoreNone,
            raw_static_eval,
            Move::NullMove(),
            tt_was_in_pv);
        transposition_table_.Save(
            tt_entry, new_tt_entry, state.zobrist_key, stack->ply);
      }

      return best_score;
    }

    // Alpha can be updated if no cutoff occurred
    alpha = std::max(alpha, best_score);
  }

  const Score futility_score = best_score + kQsFutMargin;

  MovePicker move_picker(
      MovePickerType::kQuiescence, board, tt_move, history, stack);
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
    if (!stack->in_check && move.IsCapture(state) && futility_score <= alpha &&
        !eval::StaticExchange(move, 1, state)) {
      best_score = std::max(best_score, futility_score);
      continue;
    }

    // Prefetch the TT entry for the next move as early as possible
    transposition_table_.Prefetch(board.PredictKeyAfter(move));

    ++thread.nodes_searched;

    board.MakeMove(move);
    const Score score =
        -QuiescentSearch<node_type>(thread, -beta, -alpha, stack + 1);
    board.UndoMove();

    if (ShouldQuit(thread)) {
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

  if (stack->in_check && moves_seen == 0) {
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
                                             raw_static_eval,
                                             Move::NullMove(),
                                             tt_was_in_pv);
  transposition_table_.Save(
      tt_entry, new_tt_entry, state.zobrist_key, stack->ply);

  return best_score;
}

template <NodeType node_type>
Score Search::PVSearch(Thread &thread,
                       int depth,
                       Score alpha,
                       Score beta,
                       StackEntry *stack,
                       bool cut_node) {
  auto &board = thread.board;
  auto &history = thread.history;
  const auto &state = board.GetState();

  stack->pv.Clear();

  if (stack->ply >= kMaxPlyFromRoot) {
    return eval::Evaluate(board);
  }

  thread.sel_depth = std::max(thread.sel_depth, stack->ply);

  // A principal variation (PV) node falls inside the [alpha, beta] window and
  // is one which has most of its child moves searched
  constexpr bool in_pv_node = node_type != NodeType::kNonPV;
  // The root node is also a PV node by default
  const bool in_root = stack->ply == 0;

  // If the position has a move that causes a repetition, and we are losing,
  // then we can cut off early since we can secure a draw
  if (!in_root && alpha < kDrawScore &&
      board.HasUpcomingRepetition(stack->ply)) {
    if ((alpha = kDrawScore) >= beta) {
      return alpha;
    }
  }

  // Enter quiescent search when we've reached the depth limit
  assert(depth >= 0);
  if (depth == 0) {
    return QuiescentSearch<node_type>(thread, alpha, beta, stack);
  }

  stack->in_check = state.InCheck();

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

    if (ShouldQuit(thread)) {
      return 0;
    }
  }

  // Probe the transposition table to see if we have already evaluated this
  // position
  TranspositionTableEntry *tt_entry = nullptr;
  auto tt_move = Move::NullMove();
  bool tt_hit = false, can_use_tt_eval = false, tt_was_in_pv = in_pv_node;
  Score tt_static_eval = kScoreNone;

  if (!stack->excluded_tt_move) {
    tt_entry = transposition_table_.Probe(state.zobrist_key);
    tt_hit = tt_entry->CompareKey(state.zobrist_key);

    // Use the TT entry's evaluation if possible
    if (tt_hit) {
      can_use_tt_eval = tt_entry->CanUseScore(alpha, beta);
      tt_was_in_pv |= tt_entry->GetWasPV();
      tt_move = tt_entry->move;
      tt_static_eval = tt_entry->static_eval;
    }

    // Saved scores from non-PV nodes must fall within the current alpha/beta
    // window to allow early cutoff
    if (!in_pv_node && can_use_tt_eval &&
        (cut_node || tt_entry->score <= alpha) && tt_entry->depth >= depth) {
      return TranspositionTableEntry::CorrectScore(tt_entry->score, stack->ply);
    }
  }

  // Probe the Syzygy table bases
  int syzygy_min_score = -kMateScore, syzygy_max_score = kMateScore;
  if (syzygy::enabled && !in_root && !stack->excluded_tt_move &&
      state.Occupied().PopCount() <= 7 && depth >= syzygy::probe_depth &&
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
          tt_flag == TranspositionTableEntry::kUpperBound && score <= alpha ||
          tt_flag == TranspositionTableEntry::kLowerBound && score >= beta) {
        // Save the table base score to the transposition table
        const TranspositionTableEntry new_tt_entry(state.zobrist_key,
                                                   depth,
                                                   tt_flag,
                                                   score,
                                                   tt_static_eval,
                                                   Move::NullMove(),
                                                   tt_was_in_pv);
        transposition_table_.Save(
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

  Score raw_static_eval;

  // Approximate the current evaluation at this node
  if (stack->in_check) {
    stack->static_eval = stack->eval = raw_static_eval = kScoreNone;
  } else if (!stack->excluded_tt_move) {
    raw_static_eval =
        tt_static_eval != kScoreNone ? tt_static_eval : eval::Evaluate(board);

    // Save the static eval in the TT if we have nothing yet
    if (!tt_hit) {
      const TranspositionTableEntry new_tt_entry(state.zobrist_key,
                                                 0,
                                                 TranspositionTableEntry::kNone,
                                                 kScoreNone,
                                                 raw_static_eval,
                                                 Move::NullMove(),
                                                 tt_was_in_pv);
      transposition_table_.Save(
          tt_entry, new_tt_entry, state.zobrist_key, stack->ply);
    }

    stack->static_eval = history.correction_history->CorrectStaticEval(
        state, stack, raw_static_eval);

    // Adjust eval depending on if we can use the score stored in the TT
    if (tt_hit &&
        tt_entry->CanUseScore(stack->static_eval, stack->static_eval)) {
      stack->eval =
          TranspositionTableEntry::CorrectScore(tt_entry->score, stack->ply);
    } else {
      stack->eval = stack->static_eval;
    }
  }

  const auto &prev_stack = stack - 1;
  if (stack->ply > 1 && prev_stack->move && !prev_stack->capture_move &&
      !prev_stack->in_check) {
    const int bonus =
        std::clamp<int>(-kEvalHistUpdateMult *
                            (stack->static_eval + prev_stack->static_eval) / 10,
                        -kEvalHistUpdateMin,
                        kEvalHistUpdateMax);
    history.quiet_history->UpdateMoveScore(
        FlipColor(state.turn), prev_stack->move, prev_stack->threats, bonus);
  }

  stack->threats = state.threats;

  // This condition is dependent on if the side to move's static evaluation
  // has improved in the past two or four plies. It also used as a metric for
  // adjusting pruning thresholds
  bool improving = false;

  StackEntry *past_stack = nullptr;
  if ((stack - 2)->static_eval != kScoreNone) {
    past_stack = stack - 2;
  } else if ((stack - 4)->static_eval != kScoreNone) {
    past_stack = stack - 4;
  }

  if (past_stack && !stack->in_check) {
    improving = stack->static_eval > past_stack->static_eval;
  }

  (stack + 1)->ClearKillerMoves();

  if (!in_pv_node && !stack->in_check && stack->eval < kTBWinInMaxPlyScore) {
    // Reverse (Static) Futility Pruning: Cutoff if we think the position can't
    // fall below beta anytime soon
    if (depth <= kRevFutDepth && !stack->excluded_tt_move &&
        stack->eval >= beta) {
      const int futility_margin =
          depth * kRevFutMargin -
          static_cast<int>(improving * 1.5 * kRevFutMargin) +
          (stack - 1)->history_score / kRevFutHistoryDiv;
      if (stack->eval - futility_margin >= beta) {
        // Return (eval + beta) / 2 as a balanced score: higher than the beta
        // bound since we're confident position can't fall below it, but lower
        // than the potentially optimistic static eval since we pruned without
        // full search
        return (stack->eval + beta) / 2;
      }
    }

    // Razoring: At low depths, if this node seems like it might fail low, we do
    // a quiescent search to determine if we should prune
    if (!stack->excluded_tt_move && depth <= kRazoringDepth &&
        stack->static_eval + kRazoringMult * (depth - !improving) < alpha) {
      const Score razoring_score =
          QuiescentSearch<NodeType::kNonPV>(thread, alpha, alpha + 1, stack);
      if (razoring_score <= alpha) {
        return razoring_score;
      }
    }

    // Null Move Pruning: Forfeit a move to our opponent and cutoff if we still
    // have the advantage
    if (!(stack - 1)->move.IsNull() && stack->eval >= beta &&
        stack->static_eval >= beta + kNmpBetaBase - kNmpBetaMult * depth &&
        !stack->excluded_tt_move) {
      // Avoid null move pruning a position with high zugzwang potential
      const BitBoard non_pawn_king_pieces =
          state.KinglessOccupied(state.turn) & ~state.Pawns(state.turn);
      if (non_pawn_king_pieces) {
        // Set the currently searched move in the stack for continuation history
        stack->move = Move::NullMove();
        stack->capture_move = false;
        stack->moved_piece = kNone;
        stack->continuation_entry = nullptr;

        const int eval_reduction =
            std::min<int>(2, (stack->eval - beta) / kNmpEvalDiv);
        int reduction =
            depth / kNmpRedDiv + kNmpRedBase + eval_reduction + improving;
        reduction = std::clamp(reduction, 0, depth);

        board.MakeNullMove();
        const Score score = -PVSearch<NodeType::kNonPV>(
            thread, depth - reduction, -beta, -beta + 1, stack + 1, !cut_node);
        board.UndoNullMove();

        if (ShouldQuit(thread)) {
          return 0;
        }

        // Prune if the result from our null window search around beta indicates
        // that the opponent still doesn't gain an advantage from the null move
        if (score >= beta) {
          return score >= kTBWinInMaxPlyScore ? beta : score;
        }
      }

      // ProbCut: When the current position's score is likely to cause a beta
      // cutoff, we attempt a shallower quiescent-like search and prune early if
      // possible
      const Score pc_beta = beta + kProbcutBetaDelta;
      if (depth >= kProbcutDepth && std::abs(beta) < kTBWinInMaxPlyScore &&
          (!tt_hit || tt_entry->depth + 3 < depth ||
           tt_entry->score >= pc_beta)) {
        const int pc_see = pc_beta - raw_static_eval;
        const Move pc_tt_move = eval::StaticExchange(tt_move, pc_see, state)
                                  ? tt_move
                                  : Move::NullMove();

        int moves_seen = 0;
        MovePicker move_picker(
            MovePickerType::kNoisy, board, pc_tt_move, history, stack, pc_see);
        while (const auto move = move_picker.Next()) {
          if (move_picker.GetStage() > MovePicker::Stage::kGoodNoisys &&
              moves_seen > 0) {
            break;
          }

          if (move == stack->excluded_tt_move || !board.IsMoveLegal(move)) {
            continue;
          }

          ++moves_seen;

          // Set the currently searched move in the stack for continuation
          // history
          stack->move = move;
          stack->moved_piece = state.GetPieceType(move.GetFrom());
          stack->capture_move = move.IsCapture(state);
          stack->continuation_entry =
              history.continuation_history->GetEntry(state, move);

          const int probcut_depth = depth - 3;

          board.MakeMove(move);

          Score score = -QuiescentSearch<node_type>(
              thread, -pc_beta, -pc_beta + 1, stack + 1);

          if (score >= pc_beta) {
            score = -PVSearch<node_type>(thread,
                                         probcut_depth - 1,
                                         -pc_beta,
                                         -pc_beta + 1,
                                         stack + 1,
                                         !cut_node);
          }

          board.UndoMove();

          if (score >= pc_beta) {
            const TranspositionTableEntry new_tt_entry(
                state.zobrist_key,
                probcut_depth,
                TranspositionTableEntry::kLowerBound,
                score,
                raw_static_eval,
                Move::NullMove(),
                tt_was_in_pv);
            transposition_table_.Save(
                tt_entry, new_tt_entry, state.zobrist_key, stack->ply);
            return score;
          }
        }
      }
    }
  }

  // Internal Iterative Reduction: Move ordering is expected to be worse with no
  // TT move, so we save time on searching this position now
  if ((in_pv_node || cut_node) && depth >= kIirDepth &&
      !stack->excluded_tt_move && !tt_move) {
    depth--;
  }

  // Keep track of the original alpha for bound determination when updating the
  // transposition table
  const int original_alpha = alpha;
  // Keep track of quiet and capture moves that failed to cause a beta cutoff
  MoveList quiets, captures;

  int moves_seen = 0;
  Score best_score = kScoreNone;
  Move best_move = Move::NullMove();

  MovePicker move_picker(
      MovePickerType::kSearch, board, tt_move, history, stack);
  while (const auto move = move_picker.Next()) {
    if (move == stack->excluded_tt_move || !board.IsMoveLegal(move)) {
      continue;
    }

    // Prefetch the TT entry for the next move as early as possible
    transposition_table_.Prefetch(board.PredictKeyAfter(move));

    const bool is_quiet = !move.IsNoisy(state);
    const bool is_capture = move.IsCapture(state);

    stack->history_score = is_capture ? history.GetCaptureMoveScore(state, move)
                                      : history.GetQuietMoveScore(
                                            state, move, stack->threats, stack);

    // Pruning guards
    if (!in_root && best_score > -kTBWinInMaxPlyScore) {
      int reduction = tables::kLateMoveReduction[is_quiet][depth][moves_seen];
      reduction -= stack->history_score /
                   static_cast<int>(is_quiet ? kLmrHistDiv : kLmrCaptHistDiv);
      reduction += !improving;
      const int lmr_depth = std::max(depth - reduction, 0);

      // Late Move Pruning: Skip (late) quiet moves if we've already searched
      // the most promising moves
      const int lmp_threshold =
          static_cast<int>((kLmpBase + depth * depth) / (3 - improving));
      if (is_quiet && moves_seen >= lmp_threshold) {
        move_picker.SkipQuiets();
        continue;
      }

      // Futility Pruning: Skip (futile) quiet moves at near-leaf nodes when
      // there's a low chance to raise alpha
      const int futility_margin = kFutMarginBase + kFutMarginMult * lmr_depth +
                                  stack->history_score / kFutMarginHistDiv;
      if (lmr_depth <= kFutPruneDepth && !stack->in_check && is_quiet &&
          stack->static_eval + futility_margin < alpha) {
        move_picker.SkipQuiets();
        continue;
      }

      // Static Exchange Evaluation (SEE) Pruning: Skip moves that lose too much
      // material
      const int see_threshold =
          (is_quiet ? kSeeQuietThresh * depth : kSeeNoisyThresh * depth) -
          stack->history_score / kSeePruneHistDiv;
      if (moves_seen >= 1 &&
          !eval::StaticExchange(move, see_threshold, state)) {
        continue;
      }

      // History Pruning: Prune quiet moves with a low history score moves at
      // near-leaf nodes
      const int history_margin =
          is_quiet ? kHistThreshBase + kHistThreshMult * depth
                   : kCaptHistThreshBase + kCaptHistThreshMult * depth;
      if (depth <= kHistPruneDepth && stack->history_score <= history_margin) {
        move_picker.SkipQuiets();
        continue;
      }
    }

    int extensions = 0;

    // Singular Extensions: If a TT move exists and its score is accurate enough
    // (close enough in depth), we perform a reduced-depth search with the TT
    // move excluded to see if any other moves can beat it.
    if (!in_root && depth >= kSeDepth && move == tt_move &&
        stack->ply < thread.root_depth * 2) {
      const bool is_accurate_tt_score =
          tt_entry->depth + 3 >= depth &&
          tt_entry->GetFlag() != TranspositionTableEntry::kUpperBound &&
          std::abs(tt_entry->score) < kTBWinInMaxPlyScore;

      if (is_accurate_tt_score) {
        const int reduced_depth = (depth - 1) / 2;
        const Score new_beta = tt_entry->score - depth;

        stack->excluded_tt_move = tt_move;
        const Score tt_move_excluded_score = PVSearch<NodeType::kNonPV>(
            thread, reduced_depth, new_beta - 1, new_beta, stack, cut_node);
        stack->excluded_tt_move = Move::NullMove();

        if (ShouldQuit(thread)) {
          return 0;
        }

        // No move was able to beat the TT entries score, so we extend the TT
        // move's search
        if (tt_move_excluded_score < new_beta) {
          // Extend more if the TT move is singular by a big margin
          if (!in_pv_node &&
              tt_move_excluded_score < new_beta - kSeDoubleMargin) {
            extensions = 2 + (is_quiet && tt_move_excluded_score <
                                              new_beta - kSeTripleMargin);
            depth += depth < kSeDepthExtensionDepth;
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
          extensions = -2 + in_pv_node;
        } else if (cut_node) {
          extensions = -1;
        }
      }
    }

    // Set the currently searched move in the stack for continuation history
    stack->move = move;
    stack->moved_piece = state.GetPieceType(move.GetFrom());
    stack->capture_move = move.IsCapture(state);
    stack->continuation_entry =
        history.continuation_history->GetEntry(state, move);

    board.MakeMove(move);

    const bool gives_check = state.InCheck();

    const U32 prev_nodes_searched = thread.nodes_searched++;

    // Principal Variation Search (PVS)
    int new_depth = depth + extensions - 1;
    int reduction = 0;
    bool needs_full_search;
    Score score;

    // Late Move Reduction: Moves that are less likely to be good (due to the
    // move ordering) are searched at lower depths
    if (depth > 2 && moves_seen >= 1 + in_root * 2 &&
        !(in_pv_node && is_capture)) {
      reduction = tables::kLateMoveReduction[is_quiet][depth][moves_seen];
      reduction += !in_pv_node - tt_was_in_pv;
      reduction += 2 * cut_node;
      reduction -= gives_check;
      reduction -= stack->history_score /
                   static_cast<int>(is_quiet ? kLmrHistDiv : kLmrCaptHistDiv);
      reduction += !improving;
      reduction -=
          std::abs(stack->static_eval - raw_static_eval) > kLmrComplexityDiff;
      reduction -=
          move == stack->killer_moves[0] || move == stack->killer_moves[1];

      // Ensure the reduction doesn't give us a depth below 0
      reduction = std::clamp<int>(reduction, 0, new_depth - 1);

      // Null window search at reduced depth to see if the move has potential
      score = -PVSearch<NodeType::kNonPV>(
          thread, new_depth - reduction, -alpha - 1, -alpha, stack + 1, true);

      if ((needs_full_search = score > alpha && reduction != 0)) {
        // Search deeper or shallower depending on if the result of the
        // reduced-depth search indicates a promising score
        const bool do_deeper_search =
            score > (best_score + kDoDeeperBase + 2 * new_depth);
        const bool do_shallower_search = score < best_score + kDoShallowerBase;
        new_depth += do_deeper_search - do_shallower_search;
      }
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

      if (reduction != 0 && is_quiet) {
        const int bonus = score <= alpha ? history::HistoryPenalty(new_depth)
                        : score >= beta  ? history::HistoryBonus(new_depth)
                                         : 0;
        history.continuation_history->UpdateMoveScore(
            board.GetStateHistory().Back(), move, bonus, stack);
      }
    }

    // Perform a full window search on this move if it's known to be good
    if (in_pv_node && (score > alpha || moves_seen == 0)) {
      score = -PVSearch<NodeType::kPV>(
          thread, new_depth, -beta, -alpha, stack + 1, false);
    }

    board.UndoMove();

    if (in_root && thread.IsMainThread()) {
      if (auto timed_limiter = time_mgmt_.GetTimedLimiter()) {
        timed_limiter->NodesSpent(move) +=
            thread.nodes_searched - prev_nodes_searched;
      }
    }

    if (ShouldQuit(thread)) {
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
          const int history_depth =
              depth + (alpha > beta + kHistoryBonusMargin);
          if (is_quiet) {
            stack->AddKillerMove(move);
            history.quiet_history->UpdateScore(
                state, stack, history_depth, stack->threats, quiets);
            history.continuation_history->UpdateScore(
                state, stack, history_depth, quiets);
          } else if (is_capture) {
            history.capture_history->UpdateScore(state, stack, history_depth);
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
    }
  }

  // Terminal state if no legal moves were found
  if (moves_seen == 0) {
    return stack->in_check ? -kMateScore + stack->ply : kDrawScore;
  }

  if (best_move) {
    // Since "good" captures are expected to be the best moves, we apply a
    // penalty to all captures even in the case where the best move was quiet
    history.capture_history->Penalize(state, depth, captures);
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
    const TranspositionTableEntry new_tt_entry(state.zobrist_key,
                                               depth,
                                               tt_flag,
                                               best_score,
                                               raw_static_eval,
                                               best_move,
                                               tt_was_in_pv);
    transposition_table_.Save(
        tt_entry, new_tt_entry, state.zobrist_key, stack->ply);

    if (!stack->in_check && (!best_move || !best_move.IsNoisy(state))) {
      history.correction_history->UpdateScore(
          state, stack, best_score, tt_flag, depth);
    }
  }

  return stack->score = best_score;
}

void Search::Run(Thread &thread) {
  while (true) {
    // Indicate that we have stopped searching
    stop_barrier_.ArriveAndWait();
    // Indicate that we are waiting for the search signal
    start_barrier_.ArriveAndWait();

    if (quit_.load(std::memory_order_acquire)) {
      return;
    }

    IterativeDeepening<SearchType::kRegular>(thread);
  }
}

void Search::WaitForThreads() {
  if (searching_threads_.load() > 0) {
    std::unique_lock lock(thread_stopped_mutex_);
    thread_stopped_signal_.wait(lock, [this] {
      return searching_threads_.load(std::memory_order_seq_cst) == 0;
    });
  }
}

void Search::QuitThreads() {
  if (threads_.empty()) {
    return;
  }

  quit_.store(true, std::memory_order_release);
  stop_barrier_.ArriveAndWait();
  start_barrier_.ArriveAndWait();

  for (auto &thread : threads_) {
    if (thread->raw_thread.joinable()) {
      thread->raw_thread.join();
    }
  }
}

bool Search::ShouldQuit(Thread &thread) {
  if (stop_.load(std::memory_order_relaxed)) return true;
  if (thread.IsMainThread()) {
    return thread.stack.Front().best_move &&
           time_mgmt_.TimesUp(thread.nodes_searched);
  }
  return false;
}

void Search::SetThreadCount(U16 count) {
  if (threads_.size() == count) {
    return;
  } else if (!threads_.empty()) {
    QuitThreads();
  }

  quit_.store(false, std::memory_order_release);

  search_end_barrier_.Reset(count);
  // Count + 1 so that we can arrive/wait in the UCI thread as well
  stop_barrier_.Reset(count + 1);
  start_barrier_.Reset(count + 1);

  threads_.clear();
  threads_.shrink_to_fit();
  threads_.reserve(count);

  next_thread_id_ = 0;
  for (U16 i = 0; i < count; i++) {
    auto &thread =
        threads_.emplace_back(std::make_unique<Thread>(next_thread_id_++));
    thread->raw_thread = std::thread([this, &thread]() { Run(*thread); });
  }
}

void Search::Start(TimeConfig time_config) {
  if (searching_threads_.load() > 0) {
    return;
  }

  // Wait untl all search threads have stopped
  stop_barrier_.ArriveAndWait();
  stop_.store(false, std::memory_order_relaxed);

  time_mgmt_.SetConfig(time_config);
  time_mgmt_.Start();

  searching_threads_.store(static_cast<U16>(threads_.size()),
                           std::memory_order_seq_cst);
  for (auto &thread : threads_) {
    thread->Reset();
    thread->SetBoard(board_);
  }

  // Wait until all search threads have received the signal
  start_barrier_.ArriveAndWait();
}

std::pair<Score, Move> Search::DataGenStart(std::unique_ptr<Thread> &thread,
                                            TimeConfig time_config) {
  stop_.store(false, std::memory_order_relaxed);

  time_mgmt_.SetConfig(time_config);
  time_mgmt_.Start();

  // The thread's board gets directly modified, so we don't need to call
  // SetBoard
  thread->Reset();

  IterativeDeepening<SearchType::kBench>(*thread);

  const auto &stack = thread->stack.Front();
  return {stack.score * (board_.GetState().turn == Color::kBlack ? -1 : 1),
          stack.best_move};
}

U64 Search::Bench(int depth) {
  TimeConfig config{.depth = depth};
  time_mgmt_.SetConfig(config);
  time_mgmt_.Start();

  stop_.store(false, std::memory_order_seq_cst);

  auto thread = std::make_unique<Thread>(0);
  thread->Reset();
  thread->SetBoard(board_);

  IterativeDeepening<SearchType::kBench>(*thread);
  return thread->nodes_searched;
}

void Search::Stop() {
  stop_.store(true, std::memory_order_relaxed);
  WaitForThreads();
}

void Search::NewGame(bool clear_tables) {
  if (clear_tables) {
    transposition_table_.Clear();
    tables::kLateMoveReduction = tables::GenerateLateMoveReductionTable();
  }

  for (auto &thread : threads_) {
    thread->NewGame();
  }
}

const TimeManagement &Search::GetTimeManagement() const {
  return time_mgmt_;
}

U64 Search::GetNodesSearched() const {
  return std::accumulate(
      threads_.begin(), threads_.end(), 0ULL, [](auto sum, const auto &thread) {
        return sum + thread->nodes_searched;
      });
}

void Search::ResizeHash(U64 size) {
  transposition_table_.Resize(size);
}

}  // namespace search