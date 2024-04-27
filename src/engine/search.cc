#include "search.h"

#include <format>
#include <iomanip>

#include "move_picker.h"
#include "time_mgmt.h"
#include "transpo.h"

Search::Search(Board &board) : board_(board), sel_depth_(0), searching(false), move_history_(board_.get_state()) {
  const double kBaseReduction = 0.39;
  const double kDivisor = 2.36;

  for (int depth = 1; depth <= kMaxSearchDepth; depth++) {
    for (int move = 1; move < kMaxMoves; move++) {
      lmr_table_[depth][move] = static_cast<int>(kBaseReduction + std::log(depth) * std::log(move) / kDivisor);
    }
  }
}

template <SearchType type>
void Search::iterative_deepening() {
  constexpr bool print_info = type == SearchType::kRegular;

  move_history_.decay();

  // the starting ply from a root position is always zero
  const auto root_stack = &stack_[0];
  root_stack->best_move = Move::null_move();

  const int config_depth = time_mgmt_.get_config().depth;
  const int max_search_depth = config_depth ? config_depth : kMaxSearchDepth;

  Move best_move = Move::null_move();
  int score = 0;

  for (int depth = 1; depth <= max_search_depth; depth++) {
    sel_depth_ = 0;

    const int kAspirationWindowDepth = 4;
    const int kAspirationWindowDelta = 15;

    int window = kAspirationWindowDepth;
    int alpha = -eval::kInfiniteScore;
    int beta = eval::kInfiniteScore;

    if (depth >= kAspirationWindowDepth) {
      alpha = std::max(-eval::kInfiniteScore, score - window);
      beta = std::min(eval::kInfiniteScore, score + window);
    }

    while (searching && !time_mgmt_.soft_times_up(root_stack->best_move)) {


      if (score <= alpha) {
        // we failed low which means 1) we don't have a move to play and 2)
        beta = (alpha + beta) / 2;

        // decrease alpha by the window size to expand the search range downwards
        // ensures search encompasses potentially better moves that were previously outside the initial narrower window
        alpha = std::max(-eval::kInfiniteScore, alpha - window);
      } else if (score >= beta) {
        // we failed hard on a pv node, which is abnormal and requires further verification
        // this adjustment allows the search to explore further along this promising path without cutting off due to an
        // overly restrictive beta bound
        beta = std::min(eval::kInfiniteScore, beta + window);
      } else {
        // quit now, since the score fell within the bounds of the aspiration window
        break;
      }

      // widen the aspiration window for the next iteration if we fail low or hard again
      window += window / 3;
    }

    if (print_info) {
      const bool is_mate = eval::is_mate_score(score);
      std::cout << std::format("info depth {} seldepth {} {} {} nodes {} time {} nps {} pv {}",
                               depth,
                               sel_depth_,
                               is_mate ? "mate" : "cp",
                               is_mate ? eval::mate_in(score) : score,
                               time_mgmt_.get_nodes_searched(),
                               time_mgmt_.time_elapsed(),
                               time_mgmt_.nodes_per_second(),
                               root_stack->pv.to_string())
                << std::endl;
    }

    if (!searching || time_mgmt_.soft_times_up(root_stack->best_move)) {
      break;
    }
  }

  if (print_info) {
    std::cout << std::format("bestmove {}", best_move.to_string()) << std::endl;
  }

  stop();
}

template <NodeType node_type>
int Search::quiescent_search(int ply, int alpha, int beta, Stack *stack) {
  if (board_.is_draw(ply)) {
    return eval::kDrawScore;
  }

  const auto &state = board_.get_state();

  // early cutoff in quiescent search since we're focused on evaluating quiet positions,
  // rather than exploring all possibilities
  const int static_eval = eval::evaluate(state);
  if (static_eval >= beta || ply >= kMaxPlyFromRoot) {
    return static_eval;
  }

  // alpha can be updated if no cutoff occurred
  alpha = std::max(alpha, static_eval);

  // a principal variation (pv) node is a node that falls between the [alpha, beta] window and one which most child
  // moves are searched during the pv search, we attempt to guess which moves will be pv or non-pv nodes and re-search
  // depending on if we were wrong
  constexpr bool in_pv_node = node_type != NodeType::kNonPV;

  int best_score = static_eval;
  Move best_move = Move::null_move();

  MovePicker move_picker(MovePickerType::kQuiescence, board_, Move::null_move(), move_history_, stack);
  Move move;
  while ((move = move_picker.next())) {
    if (!board_.is_move_legal(move)) {
      continue;
    }

    board_.make_move(move);
    const int score = -quiescent_search<node_type>(ply + 1, -beta, -alpha, stack->ahead());
    board_.undo_move();

    time_mgmt_.update_nodes_searched();
    if (time_mgmt_.times_up()) {
      break;
    }

    if (score > best_score) {
      best_score = score;

      if (score > alpha) {
        alpha = score;
        if (alpha >= beta) {
          // beta cutoff because the opponent would never allow this position to occur
          break;
        }
      }
    }
  }

  return best_score;
}

template <NodeType node_type>
int Search::search(int depth, int ply, int alpha, int beta, Stack *stack) {
  sel_depth_ = std::max(sel_depth_, stack->ply = ply);

  if (board_.is_draw(ply)) {
    return eval::kDrawScore;
  }

  const auto &state = board_.get_state();

  // ensure we never fall into quiescent search when the side to move is in check
  if (state.in_check()) {
    depth++;
  }

  // search until a quiet position is found to evaluate when we've searched to the depth limit
  assert(depth >= 0);
  if (depth == 0) {
    return quiescent_search<node_type>(ply, alpha, beta, stack);
  }

  // a principal variation (pv) node is a node that falls between the [alpha, beta] window and one which most child
  // moves are searched during the pv search, we attempt to guess which moves will be pv or non-pv nodes and re-search
  // depending on if we were wrong
  constexpr bool in_pv_node = node_type != NodeType::kNonPV;
  const bool in_root = ply == 0;

  // probe the transposition table to see if we have already evaluated this position
  const auto &tt_entry = transposition_table.probe(state.zobrist_key);
  const bool tt_hit = tt_entry.compare_key(state.zobrist_key);
  const auto tt_move = tt_hit ? tt_entry.move : Move::null_move();

  if (!in_pv_node && tt_hit && tt_entry.depth >= depth && tt_entry.score != kScoreNone) {
    // saved scores from non-pv nodes must fall within the current alpha/beta window to allow early cutoff
    if (tt_entry.flag == TranspositionTable::Entry::kUpperBound && tt_entry.score <= alpha ||
        tt_entry.flag == TranspositionTable::Entry::kLowerBound && tt_entry.score >= beta ||
        tt_entry.flag == TranspositionTable::Entry::kExact) {
      return transposition_table.correct_score(tt_entry.score, ply);
    }
  }

  // use the tt entry's evaluation if possible
  bool use_tt_eval = false;
  if (tt_hit && tt_entry.score != kScoreNone) {
    if (tt_entry.flag == TranspositionTable::Entry::kUpperBound && tt_entry.score <= alpha ||
        tt_entry.flag == TranspositionTable::Entry::kLowerBound && tt_entry.score >= beta ||
        tt_entry.flag == TranspositionTable::Entry::kExact) {
      use_tt_eval = true;
    }
  }

  const int static_eval = use_tt_eval ? tt_entry.score : eval::evaluate(state);
  stack->static_eval = state.in_check() ? kScoreNone : static_eval;

  move_history_.clear_killers(ply + 1);

  if (!in_pv_node && !state.in_check()) {
    // reverse (static) futility pruning: cutoff if we think the position can't fall below beta anytime soon
    // the margin for this comparison is scaled based on how many ply we have left to search
    if (depth <= 6 && static_eval < eval::kMateScore - kMaxPlyFromRoot) {
      const int futility_margin = depth * 75;
      if (static_eval - futility_margin >= beta) {
        return static_eval;
      }
    }

    // null move pruning: forfeit a move to our opponent and prune if we still have the advantage
    if (!state.move_played.is_null() && static_eval >= beta) {
      // avoid null move pruning a position with high zugzwang potential
      const BitBoard non_pawn_king_pieces = state.kingless_occupied(state.turn) & ~state.pawns(state.turn);
      if (non_pawn_king_pieces) {
        transposition_table.prefetch(board_.key_after(Move::null_move()));

        // ensure the reduction doesn't give us a depth below 0
        const int reduction = std::clamp<int>(depth / 4 + 4, 0, depth);

        board_.make_null_move();
        const int score = -search<NodeType::kNonPV>(depth - reduction, ply + 1, -beta, -beta + 1, stack->ahead());
        board_.undo_move();

        // if the result from our null window search around beta indicates that the opponent still doesn't gain an
        // advantage from the null move, we prune this branch
        if (score >= beta) {
          return score >= eval::kMateScore - kMaxPlyFromRoot ? beta : score;
        }
      }
    }
  }

  // keep track of the original alpha for bound determination when updating the transposition table
  const int original_alpha = alpha;
  // keep track of quiet moves that failed to cause a beta cutoff
  List<Move, kMaxMoves> bad_quiets;

  int moves_seen = 0;
  int best_score = kScoreNone;
  Move best_move = Move::null_move();

  MovePicker move_picker(MovePickerType::kSearch, board_, tt_move, move_history_, stack);
  Move move;
  while ((move = move_picker.next())) {
    transposition_table.prefetch(board_.key_after(move));

    if (!board_.is_move_legal(move)) {
      continue;
    }

    const bool is_quiet = !move.is_tactical(state);

    // pruning guards
    if (!in_root && best_score > -eval::kMateScore + kMaxPlyFromRoot) {
      // late move pruning: skip (late) quiet moves if we've already searched the most promising moves
      const int lmp_threshold = 3 + depth * depth;
      if (is_quiet && moves_seen >= lmp_threshold) {
        continue;
      }

      // static exchange evaluation (SEE) pruning: skip moves that lose too much material
      const int see_threshold = is_quiet ? -60 * depth : -130 * depth;
      if (depth <= 8 && moves_seen >= 1 && !eval::static_exchange(move, see_threshold, state)) {
        continue;
      }
    }

    // ensure that the pv only contains moves down this path
    if (in_pv_node) {
      stack->ahead()->pv.clear();
    }

    const U64 prev_nodes_searched = time_mgmt_.get_nodes_searched();

    board_.make_move(move);

    const int new_depth = depth - 1;

    // principal variation search (pvs)
    bool needs_full_search;
    int score;

    // late move reduction: moves that are less likely to be good (due to the move ordering)
    // are searched at lower depths
    if (depth > 2 && moves_seen >= 1) {
      // ensure the reduction doesn't give us a depth below 0
      const int reduction = std::clamp<int>(lmr_table_[depth][moves_seen], 0, new_depth - 1);

      // null window search at reduced depth to see if the move has potential
      score = -search<NodeType::kNonPV>(new_depth - reduction, ply + 1, -alpha - 1, -alpha, stack->ahead());
      needs_full_search = score > alpha && reduction != 0;
    } else {
      // if we didn't perform late move reduction, then we search this move at full depth with a null window search
      // if we don't expect it to be a pv move
      needs_full_search = !in_pv_node || moves_seen >= 1;
    }

    // either the move has potential from a reduced depth search or it's not expected to be a pv move
    // hence, we search it with a null window
    if (needs_full_search) {
      score = -search<NodeType::kNonPV>(new_depth, ply + 1, -alpha - 1, -alpha, stack->ahead());
    }

    // perform a full window search on this move if it's known to be good
    if (in_pv_node && (score > alpha || moves_seen == 0)) {
      score = -search<NodeType::kPV>(new_depth, ply + 1, -beta, -alpha, stack->ahead());
    }

    board_.undo_move();

    time_mgmt_.update_nodes_searched();
    if (in_root) {
      time_mgmt_.update_nodes_spent_table(move, time_mgmt_.get_nodes_searched() - prev_nodes_searched);
    }

    if (time_mgmt_.times_up()) {
      break;
    }

    moves_seen++;

    if (score > best_score) {
      best_score = score;

      if (score > alpha) {
        stack->best_move = best_move = move;

        // only update the pv line if this node was expected to be in the pv
        if (in_pv_node) {
          stack->pv.clear();
          stack->pv.push(best_move);
          stack->pv.copy_over(stack->ahead()->pv);
        }

        alpha = score;
        if (alpha >= beta) {
          if (is_quiet) {
            move_history_.update_history(move, bad_quiets, state.turn, depth);
            move_history_.update_killer_move(move, ply);
          }

          // beta cutoff because the opponent would never allow this position to occur
          break;
        }
      }
    }

    // penalize the history score of quiet moves that failed to raise alpha
    if (is_quiet && move != best_move) {
      bad_quiets.push(move);
    }
  }

  // terminal state if no legal moves were found
  if (moves_seen == 0) {
    return state.in_check() ? -eval::kMateScore + ply : eval::kDrawScore;
  }

  if (best_score != kScoreNone) {
    auto entry_flag = TranspositionTable::Entry::kExact;
    if (alpha >= beta) {
      // beta cutoff
      entry_flag = TranspositionTable::Entry::kLowerBound;
    } else if (alpha <= original_alpha) {
      // alpha failed to raise
      entry_flag = TranspositionTable::Entry::kUpperBound;
    }

    // attempt to update the transposition table with the evaluation of this position
    TranspositionTable::Entry new_tt_entry(state.zobrist_key, depth, entry_flag, best_score, best_move);
    transposition_table.save(state.zobrist_key, new_tt_entry, ply);
  }

  return best_score;
}

void Search::set_time_config(TimeManagement::Config &time_config) {
  time_mgmt_ = TimeManagement(time_config);
}

void Search::start(TimeManagement::Config &time_config) {
  if (searching) return;
  searching = true;

  set_time_config(time_config);
  time_mgmt_.start();

  std::thread([this] { iterative_deepening<SearchType::kRegular>(); }).detach();
}

void Search::bench(int depth) {
  if (searching) return;
  searching = true;

  TimeManagement::Config time_config{};
  time_config.depth = depth;

  set_time_config(time_config);
  time_mgmt_.start();

  // bench is intended to block the uci loop thread
  iterative_deepening<SearchType::kBench>();
}

void Search::stop() {
  time_mgmt_.stop();
  searching = false;
}

const TimeManagement &Search::get_time_management() {
  return time_mgmt_;
}

void Search::new_game() {
  std::ranges::fill(stack_, Stack{});
  transposition_table.clear();
  move_history_.clear();
}