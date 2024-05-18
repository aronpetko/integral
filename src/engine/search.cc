#include "search.h"

#include <format>
#include <iomanip>

#include "move_picker.h"
#include "time_mgmt.h"
#include "transpo.h"

Search::Search(Board &board)
    : board_(board),
      sel_depth_(0),
      searching_(false),
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
    // First four search stacks are "padding" for histories
    stack_[i] = SearchStack(std::max(0, i - 4));
  }
}

template <SearchType type>
void Search::IterativeDeepening() {
  constexpr bool print_info = type == SearchType::kRegular;

  nodes_searched_ = 0;

  move_history_.ClearKillers();
  time_mgmt_.Start();

  // The first stack entry is at 4, since search looks in the past 4 plies
  const auto root_stack = &stack_[4];
  root_stack->best_move = Move::NullMove();

  Move best_move = Move::NullMove();
  Score score = 0;

  for (int depth = 1; depth <= time_mgmt_.GetSearchDepth(); depth++) {
    sel_depth_ = 0;

    constexpr int kAspirationWindowDepth = 4;
    constexpr int kAspirationWindowDelta = 15;

    int window = kAspirationWindowDepth;
    Score alpha = -kInfiniteScore;
    Score beta = kInfiniteScore;

    if (depth >= kAspirationWindowDepth) {
      alpha = std::max(-kInfiniteScore, score - window);
      beta = std::min(kInfiniteScore, score + window);
    }

    int fail_hard_count = 0;

    while (true) {
      const Score new_score = PVSearch<NodeType::kPV>(
          depth - fail_hard_count, alpha, beta, root_stack);
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
        fail_hard_count = 0;
      } else if (score >= beta) {
        // We failed hard on a PV node, which is abnormal and requires further
        // verification
        beta = std::min(kInfiniteScore, beta + window);

        // Spend less time searching as we expand the search window, unless
        // we're absolutely winning
        if (alpha < 2000) {
          fail_hard_count = std::min(fail_hard_count + 1, 2);
        }
      } else {
        // Quit now, since the score fell within the bounds of the aspiration
        // window
        break;
      }

      // Widen the aspiration window for the next iteration if we fail low or
      // hard again
      window += window / 3;

      if (!searching_ || time_mgmt_.ShouldStop(best_move, nodes_searched_)) {
        break;
      }
    }

    if (searching_ && print_info) {
      const bool is_mate = eval::IsMateScore(score);
      std::cout
          << std::format(
                 "info depth {} seldepth {} score {} {} nodes {} time {} nps "
                 "{} pv {}",
                 depth,
                 sel_depth_,
                 is_mate ? "mate" : "cp",
                 is_mate ? eval::MateIn(score) : score,
                 nodes_searched_,
                 time_mgmt_.TimeElapsed(),
                 nodes_searched_ * 1000 / time_mgmt_.TimeElapsed(),
                 root_stack->pv.ToString())
          << std::endl;
    }

    if (!searching_ || time_mgmt_.ShouldStop(best_move, nodes_searched_)) {
      break;
    }
  }

  if (print_info) {
    std::cout << std::format("bestmove {}", best_move.ToString()) << std::endl;
  }

  Stop();
}

template <NodeType node_type>
Score Search::QuiescentSearch(Score alpha, Score beta, SearchStack *stack) {
  if (board_.IsDraw(stack->ply)) {
    return kDrawScore;
  }

  const auto &state = board_.GetState();
  sel_depth_ = std::max(sel_depth_, stack->ply);

  // A principal variation (PV) node falls inside the [alpha, beta] window and
  // is one which has most of its child moves searched
  constexpr bool in_pv_node = node_type != NodeType::kNonPV;

  // Probe the transposition table to see if we have already evaluated this
  // position
  const auto &tt_entry = transposition_table.Probe(state.zobrist_key);
  const bool tt_hit = tt_entry.CompareKey(state.zobrist_key);
  const Move tt_move = tt_hit ? tt_entry.move : Move::NullMove();

  // Use the TT entry's evaluation if possible
  const bool can_use_tt_eval = tt_hit && tt_entry.CanUseScore(alpha, beta);

  // Saved scores from non-PV nodes must fall within the current alpha/beta
  // window to allow early cutoff
  if (!in_pv_node && can_use_tt_eval) {
    return transposition_table.CorrectScore(tt_entry.score, stack->ply);
  }

  const int static_eval =
      can_use_tt_eval ? tt_entry.score : eval::Evaluate(state);

  // Early beta cutoff
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

    // Prefetch the TT entry for the next move as early as possible
    transposition_table.Prefetch(board_.PredictKeyAfter(move));

    nodes_searched_++;

    board_.MakeMove(move);
    const Score score = -QuiescentSearch<node_type>(-beta, -alpha, stack + 1);
    board_.UndoMove();

    if (ShouldQuit()) {
      break;
    }

    if (score > best_score) {
      best_score = score;

      if (score > alpha) {
        alpha = score;
        if (alpha >= beta) {
          // Beta cutoff: The opponent had a better move earlier in the tree
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

  // Always updating the transposition table a depth 0 limits these TT entries
  // to the quiescent search only
  TranspositionTable::Entry new_tt_entry(
      state.zobrist_key, 0, entry_flag, best_score, best_move);
  transposition_table.Save(state.zobrist_key, new_tt_entry, stack->ply);

  return best_score;
}

template <NodeType node_type>
Score Search::PVSearch(int depth, Score alpha, Score beta, SearchStack *stack) {
  const auto &state = board_.GetState();
  sel_depth_ = std::max(sel_depth_, stack->ply);

  // Ensure we never fall into quiescent search when in check
  if (state.InCheck()) {
    depth++;
  }

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
  }

  // Probe the transposition table to see if we have already evaluated this
  // position
  const auto &tt_entry = transposition_table.Probe(state.zobrist_key);
  const bool tt_hit = tt_entry.CompareKey(state.zobrist_key);
  const Move tt_move = tt_hit ? tt_entry.move : Move::NullMove();

  // Use the TT entry's evaluation if possible
  const bool can_use_tt_eval = tt_hit && tt_entry.CanUseScore(alpha, beta);

  // Saved scores from non-PV nodes must fall within the current alpha/beta
  // window to allow early cutoff
  if (!in_pv_node && can_use_tt_eval && tt_entry.depth >= depth) {
    return transposition_table.CorrectScore(tt_entry.score, stack->ply);
  }

  // An approximation of the current evaluation at this node
  Score eval;
  // This condition is dependent on if the side to move's static evaluation has
  // improved in the past two or four plies. It also used as a metric for
  // adjusting pruning thresholds
  bool improving = false;

  if (!state.InCheck()) {
    stack->static_eval = eval::Evaluate(state);

    // Adjust eval depending on if we can use the score stored in the TT
    if (tt_hit && can_use_tt_eval) {
      eval = transposition_table.CorrectScore(tt_entry.score, stack->ply);
    } else {
      eval = stack->static_eval;
    }

    if ((stack - 2)->static_eval != kScoreNone) {
      improving = stack->static_eval > (stack - 2)->static_eval;
    } else if ((stack - 4)->static_eval != kScoreNone) {
      improving = stack->static_eval > (stack - 4)->static_eval;
    }
  } else {
    stack->static_eval = eval = kScoreNone;
  }

  move_history_.ClearKillers(stack->ply + 1);

  if (!in_pv_node && !state.InCheck()) {
    // Reverse (Static) Futility Pruning: Cutoff if we think the position can't
    // fall below beta anytime soon
    if (depth <= 6 && eval < kMateScore - kMaxPlyFromRoot) {
      const int futility_margin = depth * 75;
      if (eval - futility_margin >= beta) {
        return eval;
      }
    }

    // Null Move Pruning: Forfeit a move to our opponent and cutoff if we still
    // have the advantage
    if (!(stack - 1)->move.IsNull() && eval >= beta) {
      // Avoid null move pruning a position with high zugzwang potential
      const BitBoard non_pawn_king_pieces =
          state.KinglessOccupied(state.turn) & ~state.Pawns(state.turn);
      if (non_pawn_king_pieces) {
        transposition_table.Prefetch(board_.PredictKeyAfter(Move::NullMove()));

        // Set the currently searched move in the stack for continuation history
        stack->move = Move::NullMove();
        stack->cont_entry = nullptr;

        // Ensure the reduction doesn't give us a depth below 0
        const int reduction = std::clamp<int>(depth / 4 + 4, 0, depth);

        board_.MakeNullMove();
        const Score score = -PVSearch<NodeType::kNonPV>(
            depth - reduction, -beta, -beta + 1, stack + 1);
        board_.UndoMove();

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
      const int lmp_threshold = (3 + depth * depth) / (2 - improving);
      if (is_quiet && moves_seen >= lmp_threshold) {
        move_picker.SkipQuiets();
        continue;
      }

      // Futility Pruning: Skip (futile) quiet moves at near-leaf nodes when
      // there's a low chance to raise alpha
      const int futility_margin = 150 + 100 * depth;
      if (depth <= 8 && !state.InCheck() && is_quiet &&
          eval + futility_margin < alpha) {
        move_picker.SkipQuiets();
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

    // Prefetch the TT entry for the next move as early as possible
    transposition_table.Prefetch(board_.PredictKeyAfter(move));

    // Ensure that the PV only contains moves down this path
    if (in_pv_node) {
      (stack + 1)->pv.Clear();
    }

    // Set the currently searched move in the stack for continuation history
    stack->move = move;
    stack->cont_entry = move_history_.GetContEntry(move, state.turn);

    board_.MakeMove(move);

    nodes_searched_++;

    const U32 prev_nodes_searched = nodes_searched_;
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
          new_depth - reduction, -alpha - 1, -alpha, stack + 1);
      needs_full_search = score > alpha && reduction != 0;
    } else {
      // If we didn't perform late move reduction, then we search this move at
      // full depth with a null window search if we don't expect it to be a PV
      // move
      needs_full_search = !in_pv_node || moves_seen >= 1;
    }

    // Either the move has potential from a reduced depth search or it's not
    // expected to be a PV move hence, we search it with a null window
    if (needs_full_search) {
      score =
          -PVSearch<NodeType::kNonPV>(new_depth, -alpha - 1, -alpha, stack + 1);
    }

    // Perform a full window search on this move if it's known to be good
    if (in_pv_node && (score > alpha || moves_seen == 0)) {
      score = -PVSearch<NodeType::kPV>(new_depth, -beta, -alpha, stack + 1);
    }

    board_.UndoMove();

    if (in_root) {
      U32 &nodes_spent = time_mgmt_.NodesSpent(move);
      nodes_spent += nodes_searched_ - prev_nodes_searched;
    }

    if (ShouldQuit()) {
      break;
    }

    moves_seen++;

    if (score > best_score) {
      best_score = score;

      if (score > alpha) {
        stack->best_move = best_move = move;

        // Only update the PV line if this node was expected to be in the PV
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
          // Beta cutoff: The opponent had a better move earlier in the tree
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

  return best_score;
}

void Search::SetTimeConfig(TimeConfig &time_config) {
  time_mgmt_ = TimeManagement(time_config);
}

bool Search::ShouldQuit() const {
  return !searching_ || ((nodes_searched_ & 2047) && time_mgmt_.TimesUp());
}

void Search::Start(TimeConfig &time_config) {
  if (searching_) return;
  searching_ = true;

  SetTimeConfig(time_config);
  time_mgmt_.Start();

  std::thread([this] { IterativeDeepening<SearchType::kRegular>(); }).detach();
}

void Search::Bench(int depth) {
  if (searching_) return;
  searching_ = true;

  TimeConfig time_config{};
  time_config.depth = depth;

  SetTimeConfig(time_config);
  time_mgmt_.Start();

  // Bench is intended to block the UCI loop thread
  IterativeDeepening<SearchType::kBench>();
}

void Search::Stop() {
  time_mgmt_.Stop();
  searching_ = false;
}

const TimeManagement &Search::GetTimeManagement() {
  return time_mgmt_;
}

void Search::NewGame() {
  for (int i = 0; i < stack_.size(); i++) {
    // First four search stacks are "padding" for histories
    stack_[i] = SearchStack(std::max(0, i - 4));
  }

  transposition_table.Clear();
  move_history_.Clear();
}

U64 Search::GetNodesSearched() const {
  return nodes_searched_;
}
