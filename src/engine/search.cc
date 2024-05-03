#include "search.h"

#include <format>
#include <iomanip>

#include "move_picker.h"
#include "time_mgmt.h"
#include "transpo.h"

Search::Search(Board &board)
    : board_(board),
      sel_depth_(0),
      searching(false),
      stack_({}),
      move_history_(board_.GetState()) {
  const double kBaseReduction = 0.39;
  const double kDivisor = 2.36;

  // Initialize the depth reduction table for Late Move Reduction
  for (int depth = 1; depth <= kMaxSearchDepth; depth++) {
    for (int move = 1; move < kMaxMoves; move++) {
      lmr_table_[depth][move] = static_cast<int>(
          kBaseReduction + std::log(depth) * std::log(move) / kDivisor);
    }
  }

  for (int i = 0; i < stack_.size(); i++) {
    stack_[i] = SearchStack(i);
  }
}

template <SearchType type>
void Search::IterativeDeepening() {
  constexpr bool print_info = type == SearchType::kRegular;

  move_history_.Decay();

  // The starting ply from a root position is always zero
  const auto root_stack = &stack_[0];
  root_stack->best_move = Move::NullMove();

  const int config_depth = time_mgmt_.GetConfig().depth;
  const int max_search_depth = config_depth ? config_depth : kMaxSearchDepth;

  Move best_move = Move::NullMove();
  Score score = 0;

  for (int depth = 1; depth <= max_search_depth; depth++) {
    sel_depth_ = 0;

    const int kAspirationWindowDepth = 4;
    const int kAspirationWindowDelta = 15;

    int window = kAspirationWindowDepth;
    int alpha = -kInfiniteScore;
    int beta = kInfiniteScore;

    if (depth >= kAspirationWindowDepth) {
      alpha = std::max(-kInfiniteScore, score - window);
      beta = std::min(kInfiniteScore, score + window);
    }

    while (true) {
      const Score new_score =
          PVSearch<NodeType::kPV>(depth, alpha, beta, root_stack);
      if (root_stack->best_move) {
        best_move = root_stack->best_move;
        score = new_score;
      }

      if (score <= alpha) {
        // Narrow beta to increase the chance of a fail hard
        beta = (alpha + beta) / 2;

        // We failed low which means we don't have a move to play, so we widen
        // alpha
        alpha = std::max(-kInfiniteScore, alpha - window);
      } else if (score >= beta) {
        // We failed hard on a pv node, which is abnormal and requires further
        // verification allows the search to explore further without cutting off
        // early
        beta = std::min(kInfiniteScore, beta + window);
      } else {
        // Quit now, since the score fell within the bounds of the aspiration
        // window
        break;
      }

      // Widen the aspiration window for the next iteration if we fail low or
      // hard again
      window += window / 3;

      if (!searching || time_mgmt_.SoftTimesUp(root_stack->best_move)) {
        break;
      }
    }

    if (searching && print_info) {
      const bool is_mate = eval::IsMateScore(score);
      std::cout << std::format(
                       "info depth {} seldepth {} {} {} nodes {} time {} nps "
                       "{} pv {}",
                       depth,
                       sel_depth_,
                       is_mate ? "mate" : "cp",
                       is_mate ? eval::MateIn(score) : score,
                       time_mgmt_.GetNodesSearched(),
                       time_mgmt_.TimeElapsed(),
                       time_mgmt_.NodesPerSecond(),
                       root_stack->pv.ToString())
                << std::endl;
    }

    if (!searching || time_mgmt_.SoftTimesUp(root_stack->best_move)) {
      break;
    }
  }

  if (print_info) {
    std::cout << std::format("bestmove {}", best_move.ToString()) << std::endl;
  }

  Stop();
}

template <NodeType node_type>
int Search::QuiescentSearch(int alpha, int beta, SearchStack *stack) {
  if (board_.IsDraw(stack->ply)) {
    return kDrawScore;
  }

  const auto &state = board_.GetState();

  // A principal variation (pv) node is a node that falls between the [alpha,
  // beta] window and one which most child moves are searched during the pv
  // search. We attempt to guess which moves will be pv or non-pv nodes and
  // re-search depending on if we were wrong
  constexpr bool in_pv_node = node_type != NodeType::kNonPV;

  // Probe the transposition table to see if we have already evaluated this
  // position
  const auto &tt_entry = transposition_table.Probe(state.zobrist_key);
  const bool tt_hit = tt_entry.CompareKey(state.zobrist_key);
  const auto tt_move = tt_hit ? tt_entry.move : Move::NullMove();

  // Use the tt entry's evaluation if possible
  const bool can_use_tt_eval = tt_hit && tt_entry.CanUseScore(alpha, beta);

  // Saved scores from non-pv nodes must fall within the current alpha/beta
  // window to allow early cutoff
  if (!in_pv_node && can_use_tt_eval) {
    return transposition_table.CorrectScore(tt_entry.score, stack->ply);
  }

  const int static_eval =
      can_use_tt_eval ? tt_entry.score : eval::Evaluate(state);

  // Early cutoff in quiescent search since we're focused on evaluating quiet
  // positions, rather than exploring all possibilities
  if (static_eval >= beta || stack->ply >= kMaxPlyFromRoot) {
    return static_eval;
  }

  // Alpha can be updated if no cutoff occurred
  alpha = std::max(alpha, static_eval);
  // Keep track of the original alpha for bound determination when updating the
  // transposition table
  const int original_alpha = alpha;

  Score best_score = static_eval;
  Move best_move = Move::NullMove();

  MovePicker move_picker(
      MovePickerType::kQuiescence, board_, tt_move, move_history_, stack);
  Move move;
  while ((move = move_picker.Next())) {
    if (!board_.IsMoveLegal(move)) {
      continue;
    }

    transposition_table.Prefetch(board_.PredictKeyAfter(move));

    board_.MakeMove(move);
    const Score score = -QuiescentSearch<node_type>(-beta, -alpha, stack + 1);
    board_.UndoMove();

    time_mgmt_.UpdateNodesSearched();
    if (time_mgmt_.TimesUp()) {
      break;
    }

    if (score > best_score) {
      best_score = score;

      if (score > alpha) {
        alpha = score;
        if (alpha >= beta) {
          // Beta cutoff: The opponent would never allow this position to occur
          break;
        }
      }
    }
  }

  auto entry_flag = TranspositionTable::Entry::kExact;
  if (alpha >= beta) {
    // Beta cutoff
    entry_flag = TranspositionTable::Entry::kLowerBound;
  } else if (alpha <= original_alpha) {
    // Alpha failed to raise
    entry_flag = TranspositionTable::Entry::kUpperBound;
  }

  // Since we're always updating the transposition table a depth 0, that means
  // only quiescent search will use these entries and not the main search
  TranspositionTable::Entry new_tt_entry(
      state.zobrist_key, 0, entry_flag, best_score, best_move);
  transposition_table.Save(state.zobrist_key, new_tt_entry, stack->ply);

  return best_score;
}

template <NodeType node_type>
int Search::PVSearch(int depth, int alpha, int beta, SearchStack *stack) {
  const auto &state = board_.GetState();
  sel_depth_ = std::max(sel_depth_, stack->ply);

  // Ensure we never fall into quiescent search when in check
  if (state.InCheck()) {
    depth++;
  }

  // Search until a quiet position is found to Evaluate when we've searched to
  // the depth limit
  assert(depth >= 0);
  if (depth == 0) {
    return QuiescentSearch<node_type>(alpha, beta, stack);
  }

  // A principal variation (pv) node is a node that falls between the [alpha,
  // beta] window and one which most child moves are searched during the pv
  // search. We attempt to guess which moves will be pv or non-pv nodes and
  // re-search depending on if we were wrong
  constexpr bool in_pv_node = node_type != NodeType::kNonPV;
  // The root node is also a pv node by default
  const bool in_root = stack->ply == 0;

  if (!in_root) {
    if (board_.IsDraw(stack->ply)) {
      return kDrawScore;
    }

    // Mate Distance Pruning: Reduce the search space if we've already found a
    // mate
    alpha = std::max(alpha, -kMateScore + stack->ply);
    beta = std::min(beta, kMateScore - stack->ply - 1);

    // A beta cutoff may occur after reducing the search space
    if (alpha >= beta) {
      return alpha;
    }
  }

  // Probe the transposition table to see if we have already Evaluated this
  // position
  const auto &tt_entry = transposition_table.Probe(state.zobrist_key);
  const bool tt_hit = tt_entry.CompareKey(state.zobrist_key);
  const auto tt_move = tt_hit ? tt_entry.move : Move::NullMove();

  // Use the tt entry's evaluation if possible
  const bool can_use_tt_eval = tt_hit && tt_entry.CanUseScore(alpha, beta);

  // Saved scores from non-pv nodes must fall within the current alpha/beta
  // window to allow early cutoff
  if (!in_pv_node && can_use_tt_eval && tt_entry.depth >= depth) {
    return transposition_table.CorrectScore(tt_entry.score, stack->ply);
  }

  const int static_eval =
      can_use_tt_eval ? tt_entry.score : eval::Evaluate(state);
  stack->static_eval = state.InCheck() ? kScoreNone : static_eval;

  bool improving = false;
  if (!state.InCheck()) {
    improving =
        (stack->ply >= 2 && stack->static_eval > (stack - 2)->static_eval &&
         (stack - 2)->static_eval != kScoreNone) ||
        (stack->ply >= 4 && stack->static_eval > (stack - 4)->static_eval &&
         (stack - 4)->static_eval != kScoreNone);
  } else {
    improving = true;
  }

  move_history_.ClearKillers(stack->ply + 1);

  if (!in_pv_node && !state.InCheck()) {
    // Reverse (Static) Futility Pruning: Cutoff if we think the position can't
    // fall below beta anytime soon the margin for this comparison is scaled
    // based on how many ply we have left to search
    if (depth <= 6 && static_eval < kMateScore - kMaxPlyFromRoot) {
      const int futility_margin = std::max(depth - improving, 0) * 75;
      if (static_eval - futility_margin >= beta) {
        return static_eval;
      }
    }

    // Null Move Pruning: Forfeit a move to our opponent and prune if we still
    // have the advantage
    if (!state.move_played.IsNull() && static_eval >= beta) {
      // Avoid null move pruning a position with high zugzwang potential
      const BitBoard non_pawn_king_pieces =
          state.KinglessOccupied(state.turn) & ~state.Pawns(state.turn);
      if (non_pawn_king_pieces) {
        transposition_table.Prefetch(board_.PredictKeyAfter(Move::NullMove()));

        // Set the currently searched move in the stack for continuation history
        stack->move = Move::NullMove();

        // Ensure the reduction doesn't give us a depth below 0
        const int reduction = std::clamp<int>(depth / 4 + 4, 0, depth);

        board_.MakeNullMove();
        const Score score = -PVSearch<NodeType::kNonPV>(
            depth - reduction, -beta, -beta + 1, stack + 1);
        board_.UndoMove();

        // If the result from our null window search around beta indicates that
        // the opponent still doesn't gain an advantage from the null move, we
        // prune this branch
        if (score >= beta) {
          return score >= kMateScore - kMaxPlyFromRoot ? beta : score;
        }
      }
    }
  }

  // Internal Iterative Reduction: Move ordering is expected to be worse with no
  // TT move, so we save time on searching this position now
  if (in_pv_node && depth >= 4 && !tt_move) {
    depth--;
  }

  // Keep track of the original alpha for bound determination when updating the
  // transposition table
  const int original_alpha = alpha;
  // Keep track of quiet moves that failed to cause a beta cutoff
  List<Move, kMaxMoves> bad_quiets;

  int moves_seen = 0;
  Score best_score = kScoreNone;
  Move best_move = Move::NullMove();

  MovePicker move_picker(
      MovePickerType::kSearch, board_, tt_move, move_history_, stack);
  Move move;
  while ((move = move_picker.Next())) {
    if (!board_.IsMoveLegal(move)) {
      continue;
    }

    const bool is_quiet = !move.IsTactical(state);

    // Pruning guards
    if (!in_root && best_score > -kMateScore + kMaxPlyFromRoot) {
      // Late Move Pruning: Skip (late) quiet moves if we've already searched
      // the most promising moves
      const int lmp_threshold = 3 + depth * depth;
      if (is_quiet && moves_seen >= lmp_threshold) {
        continue;
      }

      // Futility Pruning: Skip (futile) quiet moves at near-leaf nodes when
      // there's a low chance to raise alpha
      const int futility_margin = 150 + 100 * depth;
      if (depth <= 8 && !state.InCheck() && is_quiet &&
          static_eval + futility_margin < alpha) {
        continue;
      }

      // Static Exchange Evaluation (SEE) Pruning: Skip moves that lose too much
      // material
      const int see_threshold = is_quiet ? -60 * depth : -130 * depth;
      if (depth <= 8 && moves_seen >= 1 &&
          !eval::StaticExchange(move, see_threshold, state)) {
        continue;
      }
    }

    transposition_table.Prefetch(board_.PredictKeyAfter(move));

    // Ensure that the pv only contains moves down this path
    if (in_pv_node) {
      (stack + 1)->pv.Clear();
    }

    // Set the currently searched move in the stack for continuation history
    stack->move = move;
    stack->cont_entry = move_history_.GetContEntry(move, state.turn);

    board_.MakeMove(move);

    const U64 prev_nodes_searched = time_mgmt_.GetNodesSearched();
    const int new_depth = depth - 1;

    // Principal Variation Search (PVS)
    bool needs_full_search;
    Score score;

    // Late Move Reduction: Moves that are less likely to be good (due to the
    // move ordering) are searched at lower depths
    const int lmr_move_threshold = 1 + in_root * 2;
    if (depth > 2 && moves_seen >= lmr_move_threshold) {
      int reduction = lmr_table_[depth][moves_seen];
      reduction += !in_pv_node;
      reduction -= state.InCheck();

      // Ensure the reduction doesn't give us a depth below 0
      reduction = std::clamp<int>(reduction, 0, new_depth - 1);

      // Null window search at reduced depth to see if the move has potential
      score = -PVSearch<NodeType::kNonPV>(
          new_depth - reduction, -alpha - 1, -alpha, (stack + 1));
      needs_full_search = score > alpha && reduction != 0;
    } else {
      // If we didn't perform late move reduction, then we search this move at
      // full depth with a null window search if we don't expect it to be a pv
      // move
      needs_full_search = !in_pv_node || moves_seen >= 1;
    }

    // Either the move has potential from a reduced depth search or it's not
    // expected to be a pv move hence, we search it with a null window
    if (needs_full_search) {
      score =
          -PVSearch<NodeType::kNonPV>(new_depth, -alpha - 1, -alpha, stack + 1);
    }

    // Perform a full window search on this move if it's known to be good
    if (in_pv_node && (score > alpha || moves_seen == 0)) {
      score = -PVSearch<NodeType::kPV>(new_depth, -beta, -alpha, stack + 1);
    }

    board_.UndoMove();

    time_mgmt_.UpdateNodesSearched();
    if (in_root) {
      time_mgmt_.UpdateNodesSpentTable(
          move, time_mgmt_.GetNodesSearched() - prev_nodes_searched);
    }

    if (time_mgmt_.TimesUp()) {
      break;
    }

    moves_seen++;

    if (score > best_score) {
      best_score = score;

      if (score > alpha) {
        stack->best_move = best_move = move;

        // Only update the pv line if this node was expected to be in the pv
        if (in_pv_node) {
          stack->pv.Clear();
          stack->pv.Push(best_move);
          stack->pv.CopyOver((stack + 1)->pv);
        }

        alpha = score;
        if (alpha >= beta) {
          if (is_quiet) {
            move_history_.UpdateHistory(move, bad_quiets, state.turn, depth);
            move_history_.UpdateContHistory(
                move, bad_quiets, state.turn, depth, stack);
            move_history_.UpdateKillerMove(move, stack->ply);
          }

          // Beta cutoff: The opponent would never allow this position to occur
          break;
        }
      }
    }

    // Penalize the history score of quiet moves that failed to raise alpha
    if (is_quiet && move != best_move) {
      bad_quiets.Push(move);
    }
  }

  // Terminal state if no legal moves were found
  if (moves_seen == 0) {
    return state.InCheck() ? -kMateScore + stack->ply : kDrawScore;
  }

  if (best_score != kScoreNone) {
    auto entry_flag = TranspositionTable::Entry::kExact;
    if (alpha >= beta) {
      // Beta cutoff
      entry_flag = TranspositionTable::Entry::kLowerBound;
    } else if (alpha <= original_alpha) {
      // Alpha failed to raise
      entry_flag = TranspositionTable::Entry::kUpperBound;
    }

    // Attempt to update the transposition table with the evaluation of this
    // position
    TranspositionTable::Entry new_tt_entry(
        state.zobrist_key, depth, entry_flag, best_score, best_move);
    transposition_table.Save(state.zobrist_key, new_tt_entry, stack->ply);
  }

  return best_score;
}

void Search::SetTimeConfig(TimeManagement::Config &time_config) {
  time_mgmt_ = TimeManagement(time_config);
}

void Search::Start(TimeManagement::Config &time_config) {
  if (searching) return;
  searching = true;

  SetTimeConfig(time_config);
  time_mgmt_.Start();

  std::thread([this] { IterativeDeepening<SearchType::kRegular>(); }).detach();
}

void Search::Bench(int depth) {
  if (searching) return;
  searching = true;

  TimeManagement::Config time_config{};
  time_config.depth = depth;

  SetTimeConfig(time_config);
  time_mgmt_.Start();

  // Bench is intended to block the uci loop thread
  IterativeDeepening<SearchType::kBench>();
}

void Search::Stop() {
  time_mgmt_.Stop();
  searching = false;
}

const TimeManagement &Search::GetTimeManagement() {
  return time_mgmt_;
}

void Search::NewGame() {
  for (int i = 0; i < stack_.size(); i++) {
    stack_[i] = SearchStack(i);
  }
  transposition_table.Clear();
  move_history_.Clear();
}