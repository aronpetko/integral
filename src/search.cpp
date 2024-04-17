#include "search.h"
#include "move_gen.h"
#include "transpo.h"
#include "move_picker.h"
#include "time_mgmt.h"

#include <iomanip>
#include <format>

Search::Search(TimeManagement::Config &time_config, Board &board)
    : board_(board),
      time_mgmt_(time_config, board),
      stack_({}),
      sel_depth_(0),
      move_history_(board_.get_state()) {}

std::array<std::array<int, kMaxPlyFromRoot>, kMaxSearchDepth + 1> Search::kLateMoveReductionTable{{}};

void Search::init_tables() {
  const double kBaseReduction = 0.39;
  const double kDivisor = 2.36;

  for (int depth = 1; depth <= kMaxSearchDepth; depth++) {
    for (int move = 1; move < kMaxPlyFromRoot; move++) {
      Search::kLateMoveReductionTable[depth][move] =
          static_cast<int>(kBaseReduction + std::log(depth) * std::log(move) / kDivisor);
    }
  }
}

template<NodeType node_type>
int Search::quiesce(int ply, int alpha, int beta) {
  const auto &state = board_.get_state();

  if (board_.is_draw()) {
    return eval::kDrawScore;
  }

  auto &transpo = board_.get_transpo_table();

  // pv nodes are nodes that fall inside the [alpha, beta] window
  // these nodes are searched in their entirety, as they're where the most "sensible" moves belong
  constexpr bool in_pv_node = node_type != NodeType::kNonPV;
  constexpr auto pv_node_type = in_pv_node ? NodeType::kPV : NodeType::kNonPV;

  const auto &tt_entry = transpo.probe(state.zobrist_key);
  const bool tt_hit = tt_entry.compare_key(state.zobrist_key);
  const Move tt_move = tt_entry.move;
  if (!in_pv_node && tt_hit && tt_entry.score != kScoreNone &&
      (tt_entry.flag == TranspositionTable::Entry::kExact ||
       (tt_entry.flag == TranspositionTable::Entry::kLowerBound && tt_entry.score >= beta) ||
       (tt_entry.flag == TranspositionTable::Entry::kUpperBound && tt_entry.score <= alpha))) {
    return transpo.correct_score(tt_entry.score, ply);
  }

  const int static_eval = tt_hit ? tt_entry.score : eval::evaluate(state);
  if (ply >= kMaxPlyFromRoot) {
    return static_eval;
  }

  if (static_eval >= beta) {
    return static_eval;
  }

  Move best_move = Move::null_move();
  int best_score = static_eval;
  int moves_tried = 0;

  alpha = std::max(alpha, static_eval);
  const int original_alpha = alpha;

  MovePicker move_picker(MovePickerType::kQuiescence, board_, tt_move, move_history_, &stack_[ply]);
  Move move = Move::null_move();
  while (move = move_picker.next()) {
    // load the transposition table entry for this move in the background
    transpo.prefetch(board_.key_after(move));

    board_.make_move(move);

    // since the move generator is pseudo-legal, we must verify legality here
    if (move_gen::king_in_check(flip_color(state.turn), state)) {
      board_.undo_move();
      continue;
    }

    // principal variation search (pvs)
    // search the first move with a normal alpha-beta window
    int score;
    if (moves_tried == 0) {
      score = -quiesce<pv_node_type>(ply + 1, -beta, -alpha);
    } else {
      // null window search for a quick refutation or indication of a potentially good move
      score = -quiesce<NodeType::kNonPV>(ply + 1, -alpha - 1, -alpha);

      // if the move looks promising from null window search, re-search to obtain a more accurate score
      if (score > alpha && in_pv_node) {
        score = -quiesce<pv_node_type>(ply + 1, -beta, -alpha);
      }
    }

    board_.undo_move();
    moves_tried++;

    if (time_mgmt_.times_up()) {
      return 0;
    }

    if (score > best_score) {
      best_score = score;
      best_move = move;

      if (score >= beta) {
        break;
      }

      alpha = std::max(alpha, score);
    }
  }

  TranspositionTable::Entry entry;
  entry.key = state.zobrist_key;
  entry.score = best_score;
  entry.move = best_move;

  if (best_score <= original_alpha) {
    entry.flag = TranspositionTable::Entry::kUpperBound;
  } else if (best_score >= beta) {
    entry.flag = TranspositionTable::Entry::kLowerBound;
  } else {
    entry.flag = TranspositionTable::Entry::kExact;
  }

  transpo.save(state.zobrist_key, entry, ply);
  return best_score;
}

template<NodeType node_type>
int Search::search(int depth, int ply, int alpha, int beta, Result &result) {
  const auto &state = board_.get_state();

  // check for repetitions of this position and the fifty-move rule
  if (board_.is_draw()) {
    return eval::kDrawScore;
  }

  // pv nodes are nodes that fall inside the [alpha, beta] window
  // these nodes are searched in their entirety, as they're where the most "sensible" moves belong
  constexpr bool in_root = node_type == NodeType::kRoot;
  constexpr bool in_pv_node = node_type != NodeType::kNonPV;
  constexpr auto pv_node_type = in_pv_node ? NodeType::kPV : NodeType::kNonPV;

  const bool in_check = move_gen::king_in_check(state.turn, state);
  if (in_check) {
    depth++;
  }

  // enter quiescent search to return a final score for the position
  // this ensures that we never evaluate positions where a tactic could occur (minimizing the horizon effect)
  if (depth <= 0) {
    return quiesce<pv_node_type>(ply, alpha, beta);
  }

  // mate distance pruning: reduce the search space if we've already found a mate
  alpha = std::max(alpha, -eval::kMateScore + ply);
  beta = std::min(beta, eval::kMateScore - ply - 1);

  if (alpha >= beta) {
    return alpha;
  }

  auto &transpo = board_.get_transpo_table();
  const int original_alpha = alpha;

  // probe the transposition table to see if we can:
  // a) return an exact score for this position if it's been evaluated before
  // b) return alpha if this position score indicates a better option us
  // c) return beta if this position's score suggests a worse option for the opponent
  const auto &tt_entry = transpo.probe(state.zobrist_key);
  const bool tt_hit = tt_entry.compare_key(state.zobrist_key);
  const Move tt_move = tt_entry.move;
  if (!in_pv_node && tt_hit && tt_entry.depth >= depth && tt_entry.score != kScoreNone &&
      (tt_entry.flag == TranspositionTable::Entry::kExact ||
       (tt_entry.flag == TranspositionTable::Entry::kLowerBound && tt_entry.score >= beta) ||
       (tt_entry.flag == TranspositionTable::Entry::kUpperBound && tt_entry.score <= alpha))) {
    return transpo.correct_score(tt_entry.score, ply);
  }

  const int static_eval = tt_hit && !in_check ? tt_entry.score : eval::evaluate(state);
  if (ply >= kMaxPlyFromRoot) [[unlikely]] {
    return static_eval;
  }

  sel_depth_ = std::max(sel_depth_, ply);

  auto search_stack = &stack_[ply];
  search_stack->ply = ply;

  bool improving = false;
  if (!in_check) {
    search_stack->static_eval = static_eval;
    if (ply >= 2 && search_stack->behind(2)->static_eval != kScoreNone) {
      improving = static_eval > search_stack->behind(2)->static_eval;
    } else if (ply >= 4 && search_stack->behind(4)->static_eval != kScoreNone) {
      improving = static_eval > search_stack->behind(4)->static_eval;
    }
  } else {
    search_stack->static_eval = kScoreNone;
  }

  // internal iterative reduction: reduce the depth if there is no tt entry for the position
  // it will most likely be searched again later to a fuller depth, so no need to go the extra mile right now
  if (depth >= 4 && !tt_hit) {
    depth--;
  }

  // reverse (static) futility pruning: cutoff if we think the position can't fall below beta anytime soon
  // the margin for this comparison is scaled based on how many ply we have left to search
  if (depth <= 6 && !in_pv_node && !in_check) {
    const int futility_margin = (depth - improving) * 120;
    if (static_eval - futility_margin >= beta) {
      return static_eval;
    }
  }

  // razoring: when evaluation is far below alpha, we assume only captures can bring us back
  // therefore, drop into quiesce and cut off if we still can't hit/raise alpha
  if (!in_pv_node && !in_check && alpha < 2000 && static_eval < alpha - 400 * depth) {
    const int razoring_score = quiesce<pv_node_type>(ply, alpha, beta);
    if (razoring_score <= alpha) {
      return razoring_score;
    }
  }

  // null move pruning: forfeit a move to our opponent and perform a shallow search
  // if the search indicates a winning position, it's safe to assume this move too good and
  // the opponent wouldn't have allowed this position to occur, so we prune this branch
  if (!state.move_played.is_null() && static_eval >= beta && !in_check && !in_pv_node) {
    // nmp is considered unsafe in positions that zugwang is likely to occur
    const bool safe_to_nmp =
        state.knights(state.turn) || state.bishops(state.turn) || state.rooks(state.turn) || state.queens(state.turn);
    if (safe_to_nmp) {
      board_.make_null_move();

      const int reduction = depth / 4 + 4;
      const int null_move_score = -search<NodeType::kNonPV>(depth - reduction, ply + 1, -beta, -beta + 1, result);

      board_.undo_move();

      if (time_mgmt_.times_up()) {
        return 0;
      }

      if (null_move_score >= beta) {
        return null_move_score >= eval::kMateScore - kMaxPlyFromRoot ? beta : null_move_score;
      }
    }
  }

  move_history_.clear_killers(ply + 1);

  List<Move, kMaxMoves> quiet_non_cutoffs;
  int moves_tried = 0;

  Move best_move = Move::null_move();
  int best_score = std::numeric_limits<int>::min();

  MovePicker move_picker(MovePickerType::kSearch, board_, tt_move, move_history_, search_stack);
  Move move = Move::null_move();
  while (move = move_picker.next()) {
    const bool is_quiet = !move.is_tactical(state);

    // no aggressive pruning when we could potentially be checkmated
    if (best_score > -eval::kMateScore + kMaxPlyFromRoot) {
      // static exchange evaluation (SEE) pruning: skip moves that lose too much material
      const int see_threshold = is_quiet ? -60 * depth : -20 * depth * depth;
      if (depth <= 8 && moves_tried > 0 && !eval::static_exchange(move, see_threshold, state)) {
        continue;
      }

      // late move pruning: skip (late) quiet moves if we've already searched the most promising moves
      const int lmp_threshold = 3 + depth * depth / (2 - improving);
      if (is_quiet && !in_root && moves_tried >= lmp_threshold) {
        break;
      }

      // futility pruning: skip (futile) quiet moves when there's a really low chance our eval can raise alpha
      if (depth <= 8 && !in_root && !in_check && is_quiet && static_eval + 150 + 100 * depth < alpha &&
          alpha < eval::kMateScore - kMaxPlyFromRoot) {
        continue;
      }

      // history pruning: skip quiet moves that don't cause as many beta cutoffs
      if (is_quiet && depth <= 4 && move_history_.get_history_score(move, state.turn) < -1024 * depth) {
        break;
      }
    }

    // load the transposition table entry for this move in the background
    transpo.prefetch(board_.key_after(move));

    board_.make_move(move);

    // since the move generator is pseudo-legal, we must verify legality here
    if (move_gen::king_in_check(flip_color(state.turn), state)) {
      board_.undo_move();
      continue;
    }

    time_mgmt_.update_nodes_searched();
    const auto prev_nodes_searched = time_mgmt_.get_nodes_searched();

    // clear the child pv so the pv for this node is accurate
    if (in_pv_node) {
      search_stack->ahead()->pv.clear();
    }

    const int new_depth = depth - 1;
    int score;

    // principal variation search (pvs)
    // search the first move with a normal alpha-beta window
    bool needs_full_search;

    // move ordering places the moves that are most likely to cause a beta cutoff first
    // therefore, we save time on searching moves that are less likely to be good by reducing the search depth for them
    if (depth > 2 && moves_tried >= 1 + in_root * 2) {
      int reduction = kLateMoveReductionTable[depth][moves_tried];
      if (is_quiet) reduction -= move_history_.get_history_score(move, state.turn) / 2048;
      else reduction /= 2;
      reduction -= in_pv_node;
      reduction -= in_check;
      reduction += !improving;
      reduction = std::clamp(reduction, 0, new_depth - 1);

      // null window search for a quick refutation or indication of a potentially good move
      score = -search<NodeType::kNonPV>(new_depth - reduction, ply + 1, -alpha - 1, -alpha, result);
      needs_full_search = score > alpha && reduction > 0;
    } else {
      needs_full_search = !in_pv_node || moves_tried >= 1;
    }

    if (needs_full_search) {
      score = -search<NodeType::kNonPV>(new_depth, ply + 1, -alpha - 1, -alpha, result);
    }

    // if the move looks promising from null window search, re-search to obtain a more accurate score
    if (in_pv_node && (score > alpha || moves_tried == 0)) {
      score = -search<NodeType::kPV>(new_depth, ply + 1, -beta, -alpha, result);
    }

    board_.undo_move();
    moves_tried++;

    time_mgmt_.update_node_spent_table(move, prev_nodes_searched);
    if (time_mgmt_.times_up()) {
      break;
    }

    // alpha is raised, therefore this move is the new pv node for this depth
    if (score > best_score) {
      best_score = score;
      best_move = move;

      if (in_root) {
        result.best_move = best_move;
        result.score = best_score;
      }

      if (in_pv_node) {
        // clear this ply's pv if a new best move was discovered
        search_stack->pv.clear();
        // add the new best move to the pv
        search_stack->pv.push(move);

        // copy over the child's pv to this ply's pv
        auto &child_pv = search_stack->ahead()->pv;
        for (int child_pv_move = 0; child_pv_move < child_pv.length(); child_pv_move++) {
          search_stack->pv.push(child_pv[child_pv_move]);
        }
      }
    }

    alpha = std::max(alpha, best_score);

    // this opponent has a better move, so we prune this branch
    if (alpha >= beta) {
      if (is_quiet) {
        move_history_.update_killer_move(move, ply);
        move_history_.update_counter_move(state.move_played, move);
        move_history_.update_move_history(move, quiet_non_cutoffs, state.turn, depth);
      }
      break;
    } else if (is_quiet) {
      quiet_non_cutoffs.push(move);
    }
  }

  // the game is over if we couldn't try a move
  if (moves_tried == 0) {
    return in_check ? -eval::kMateScore + ply : eval::kDrawScore;
  }

  TranspositionTable::Entry entry;
  entry.key = state.zobrist_key;
  entry.score = best_score;
  entry.depth = depth;
  entry.move = best_move;

  if (best_score <= original_alpha) {
    entry.flag = TranspositionTable::Entry::kUpperBound;
  } else if (best_score >= beta) {
    entry.flag = TranspositionTable::Entry::kLowerBound;
  } else {
    entry.flag = TranspositionTable::Entry::kExact;
  }

  transpo.save(state.zobrist_key, entry, ply);
  return best_score;
}

Search::Result Search::iterative_deepening() {
  Search::Result result;

  move_history_.clear_move_history();

  const int config_depth = time_mgmt_.get_config().depth;
  const int max_search_depth = config_depth ? config_depth : kMaxSearchDepth;

  for (int depth = 1; depth <= max_search_depth; depth++) {
    sel_depth_ = 0;

    int alpha = -std::numeric_limits<int>::max();
    int beta = std::numeric_limits<int>::max();

    const int kAspirationMinDepth = 4;
    const int kAspirationStartWindow = 15;

    int window = kAspirationStartWindow;
    int fail_high_count = 0;

    while (true) {
      if (depth >= kAspirationMinDepth) {
        alpha = std::max(-std::numeric_limits<int>::max(), result.score - window);
        beta = std::min(std::numeric_limits<int>::max(), result.score + window);
      }

      Result new_result;
      search<NodeType::kRoot>(depth - std::min(2, fail_high_count), 0, alpha, beta, new_result);

      if (!new_result.best_move.is_null()) {
        result = new_result;
        result.pv_line = stack_.front().pv;
      }

      if (time_mgmt_.times_up()) {
        break;
      }

      if (new_result.score <= alpha) {
        // adjust beta to be midpoint between alpha and itself
        // this adjustment narrows the [alpha, beta] window based, effectively lowering the expectation for what constitutes an acceptable move
        beta = (alpha + beta) / 2;

        // decrease alpha by the window size to expand the search range downwards
        // this ensures the search encompasses potentially better moves that were previously outside the initial narrower window
        alpha = std::max(-std::numeric_limits<int>::max(), alpha - window);

        // reset fail_high_count to zero since the window adjustment
        // requires a fresh evaluation of high-fail occurrences without previous bias
        fail_high_count = 0;
      }
      else if (new_result.score >= beta) {
        // increase beta by the window size to extend the upper search range
        // this adjustment allows the search to explore further along this promising path without cutting off due to an overly restrictive beta bound
        beta = std::min(std::numeric_limits<int>::max(), beta + window);

        // search to lower depths as fail highs (beta cutoffs) increase
        if (new_result.score < 2000) {
          fail_high_count++;
        }
      }
      else
        break;

      window += window / 2;
    }

    const bool is_mate = eval::is_mate_score(result.score);
    std::cout << std::format("info depth {} score {} {} nodes {} nps {} time {} seldepth {} hashfull {} pv {}",
                             depth,
                             is_mate ? "mate" : "cp",
                             is_mate ? eval::mate_in(result.score) : result.score,
                             time_mgmt_.get_nodes_searched(),
                             time_mgmt_.nodes_per_second(),
                             time_mgmt_.time_elapsed(),
                             sel_depth_,
                             board_.get_transpo_table().hash_full(),
                             result.pv_line.to_string()) << std::endl;

    if (time_mgmt_.soft_times_up(result.best_move)) {
      break;
    }
  }

  return result;
}

Search::Result Search::go() {
  time_mgmt_.start();
  const auto result = iterative_deepening();
  time_mgmt_.stop();
  return result;
}