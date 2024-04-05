#include "search.h"
#include "move_gen.h"
#include "transpo.h"
#include "move_picker.h"
#include "time_mgmt.h"
#include "move_orderer.h"

#include <iomanip>
#include <format>

Search::Search(TimeManagement::Config &time_config, Board &board)
    : board_(board),
      time_mgmt_(time_config, board),
      stack_({}) {}

std::array<std::array<int, kMaxPlyFromRoot>, kMaxSearchDepth + 1> Search::kLateMoveReductionTable;

void Search::init_tables() {
  const double kBaseReduction = 0.77;
  const double kDivisor = 2.36;

  for (int depth = 1; depth <= kMaxSearchDepth; depth++) {
    for (int move = 1; move < kMaxPlyFromRoot; move++) {
      Search::kLateMoveReductionTable[depth][move] =
          static_cast<int>(0.25 + 0.46 * std::log(depth) * std::log(move));
    }
  }
}

template<NodeType node_type>
int Search::quiesce(int ply, int alpha, int beta) {
  const auto &state = board_.get_state();
  auto &transpo = board_.get_transpo_table();

  if (board_.is_draw()) {
    return eval::kDrawScore;
  }

  // pv nodes are nodes that fall inside the [alpha, beta] window
  // we typically want to search these nodes in their entirety, as they're the most "sensible" moves in a position
  constexpr bool in_root = node_type == NodeType::kRoot;
  constexpr bool in_pv_node = node_type != NodeType::kNonPV;
  constexpr auto pv_node_type = in_pv_node ? NodeType::kPV : NodeType::kNonPV;

  const auto &tt_entry = transpo.probe(state.zobrist_key);
  const bool tt_hit = tt_entry.key == state.zobrist_key;
  if (in_pv_node && tt_hit && (tt_entry.flag == TranspositionTable::Entry::kExact
      || (tt_entry.flag == TranspositionTable::Entry::kLowerBound && tt_entry.score >= beta)
      || (tt_entry.flag == TranspositionTable::Entry::kUpperBound && tt_entry.score <= alpha))) {
    return transpo.correct_score(tt_entry.score, ply);
  }

  const int static_eval = tt_hit ? tt_entry.score : eval::evaluate(state);
  if (ply >= kMaxPlyFromRoot) {
    return static_eval;
  }

  if (static_eval >= beta) {
    TranspositionTable::Entry entry;
    entry.key = state.zobrist_key;
    entry.score = static_eval;
    entry.flag = TranspositionTable::Entry::kLowerBound;

    transpo.save(entry, ply);
    return static_eval;
  }

  Move best_move;
  int best_score = static_eval;
  int moves_tried = 0;

  alpha = std::max(alpha, static_eval);
  const int original_alpha = alpha;

  auto search_stack = &stack_[ply];

  // MoveOrderer move_orderer(board_, move_gen::tactical_moves(board_), MoveType::kTactical, ply);
  MovePicker move_picker(MovePickerType::kSearch, board_, tt_entry.move, search_stack);

  Move move;
  while ((move = move_picker.next())) {
    // static exchange evaluation (SEE) pruning
    // don't look at moves that result in lost material
    if (!eval::static_exchange(move, -100, state)) {
      continue;
    }

    board_.make_move(move);
    // since the move generator is pseudo-legal, we must verify legality here
    if (move_gen::king_in_check(flip_color(state.turn), state)) {
      board_.undo_move();
      continue;
    }

    // principal variation search (pvs)
    // search the first move with a normal alpha-beta window
    int score = 0;
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

  transpo.save(entry, ply);
  return best_score;
}

template<NodeType node_type>
int Search::search(int depth, int ply, int alpha, int beta, Result &result) {
  // check for repetitions of this position and the fifty-move rule
  if (board_.is_draw()) {
    return eval::kDrawScore;
  }

  // pv nodes are nodes that fall inside the [alpha, beta] window
  // we typically want to search these nodes in their entirety, as they're the most "sensible" moves in a position
  constexpr bool in_root = node_type == NodeType::kRoot;
  constexpr bool in_pv_node = node_type != NodeType::kNonPV;
  constexpr auto pv_node_type = in_pv_node ? NodeType::kPV : NodeType::kNonPV;

  const auto &state = board_.get_state();

  const bool in_check = move_gen::king_in_check(state.turn, state);
  if (in_check) {
    depth++;
  }

  // enter quiescent search to return a final score for the original position
  // this ensures that we never evaluate positions where we may miss a tactic
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
  const bool tt_hit = tt_entry.key == state.zobrist_key;
  if (!in_pv_node && tt_hit && tt_entry.depth >= depth && (tt_entry.flag == TranspositionTable::Entry::kExact
      || (tt_entry.flag == TranspositionTable::Entry::kLowerBound && tt_entry.score >= beta)
      || (tt_entry.flag == TranspositionTable::Entry::kUpperBound && tt_entry.score <= alpha))) {
    return transpo.correct_score(tt_entry.score, ply);
  }

  const int static_eval = tt_hit ? tt_entry.score : eval::evaluate(state);
  if (ply >= kMaxPlyFromRoot) {
    return static_eval;
  }

  bool improving = false;

  auto search_stack = &stack_[ply];
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

  // reverse (static) futility pruning
  // we assume that the static evaluation of the current position can't fall below beta within the next move
  // the margin for this comparison is scaled based on how many moves left we have to search
  if (depth <= 6 && !in_pv_node && !in_check) {
    const int futility_margin = (depth - improving) * 90;
    if (static_eval - futility_margin >= beta) {
      return static_eval;
    }
  }

  // razoring: when evaluation is far below alpha, we assume only captures can bring us back
  // therefore, drop into quiesce and cut off  if we still can't hit alpha
  if (!in_pv_node && !in_check && alpha < 2000 && static_eval < alpha - 400 - 250 * depth * depth) {
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
    const bool safe_to_nmp = state.knights(state.turn) || state.bishops(state.turn) || state.rooks(state.turn) || state.queens(state.turn);
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

  search_stack->ahead(1)->killers.fill(Move::null_move());

  bool skip_quiets = false;

  List<Move> quiet_non_cutoffs;
  int moves_tried = 0;

  Move best_move = Move::null_move();
  int best_score = std::numeric_limits<int>::min();

  MovePicker move_picker(MovePickerType::kSearch, board_, tt_entry.move, search_stack);

  Move move;
  while ((move = move_picker.next())) {
    const bool is_quiet = !move.is_tactical(state);
    if (is_quiet && skip_quiets) {
      continue;
    }

    // no aggressive pruning when we could potentially be checkmated
    if (best_score > -eval::kMateScore + kMaxPlyFromRoot) {
      // static exchange evaluation (SEE) pruning
      // skip moves that lose too much material
      const int see_threshold = is_quiet ? -60 * depth : -20 * depth * depth;
      if (depth <= 10 && moves_tried > 0 && !eval::static_exchange(move, see_threshold, state)) {
        continue;
      }

      // late move pruning
      // skip (late) quiet moves if we've already searched the most promising moves
      const int lmp_threshold = (3 + depth * depth) / (2 - improving);
      if (!in_root && moves_tried >= lmp_threshold) {
        skip_quiets = true;
      }

      // futility pruning
      int lmr_reduction = kLateMoveReductionTable[depth][moves_tried];
      lmr_reduction -= in_pv_node;
      lmr_reduction -= MoveOrderer::get_history_score(move, state.turn) / 1024;
      lmr_reduction += !improving;
      lmr_reduction = std::clamp(lmr_reduction, 0, depth - 1);
      if (!in_pv_node && !in_check && is_quiet && depth - lmr_reduction <= 8 && static_eval + 150 + 100 * depth < alpha) {
        continue;
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
    bool needs_full_search = false;

    // move ordering places the moves that are most likely to cause a beta cutoff first
    // therefore, we save time on searching moves that are less likely to be good by reducing the search depth for them
    if (depth > 2 && moves_tried >= 1 + in_root * 2) {
      int reduction = kLateMoveReductionTable[depth][moves_tried];
      reduction -= in_pv_node;
      reduction -= MoveOrderer::get_history_score(move, state.turn) / 1024;
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
        search_stack->pv.clear();
        search_stack->pv.push(move);

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
        if (move != search_stack->killers[0]) {
          search_stack->killers[1] = search_stack->killers[0];
          search_stack->killers[0] = move;
        }

        // moveOrderer::update_killer_move(move, depth);
        MoveOrderer::update_counter_move(state.move_played, move);
        MoveOrderer::update_move_history(move, quiet_non_cutoffs, state.turn, depth);
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

  transpo.save(entry, ply);
  return best_score;
}

Search::Result Search::iterative_deepening() {
  Search::Result result;

  MoveOrderer::clear_move_history();

  const int config_depth = time_mgmt_.get_config().depth;
  const int max_search_depth = config_depth ? config_depth : kMaxSearchDepth;

  for (int depth = 1; depth <= max_search_depth; depth++) {
    int alpha = -std::numeric_limits<int>::max();
    int beta = std::numeric_limits<int>::max();
    int window = 40;

    while (true) {
      const int kAspirationMinDepth = 4;
      if (depth > kAspirationMinDepth) {
        alpha = result.score - window;
        beta = result.score + window;
      }

      Result new_result;
      search<NodeType::kRoot>(depth, 0, alpha, beta, new_result);

      if (!new_result.best_move.is_null()) {
        result = new_result;
        result.pv_line = stack_[0].pv;
      }

      if (time_mgmt_.times_up()) {
        break;
      }

      if (alpha < new_result.score && beta > new_result.score) {
        break;
      }

      window *= 2;
    }

    const bool is_mate = eval::is_mate_score(result.score);
    std::cout << std::format("info depth {} score {} {} nodes {} nps {} time {} seldepth {} pv {}",
                             depth,
                             is_mate ? "mate" : "cp",
                             is_mate ? eval::mate_in(result.score) : result.score,
                             time_mgmt_.get_nodes_searched(),
                             time_mgmt_.nodes_per_second(),
                             time_mgmt_.time_elapsed(),
                             result.pv_line.length(),
                             result.pv_line.to_string()) << std::endl;

    if (time_mgmt_.times_up() || time_mgmt_.root_times_up(result.best_move)) {
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