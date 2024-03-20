#ifndef INTEGRAL_SEARCH_H_
#define INTEGRAL_SEARCH_H_

#include "board.h"
#include "eval.h"
#include "time_mgmt.h"

class Search {
 public:
  explicit Search(TimeManagement::Config &time_config, Board &board);

  static constexpr int kMaxSearchDepth = 100;

  // principal variation (PV) line of the search
  struct PVLine {
   public:
    PVLine() : moves_({}), move_count_(0) {
      clear();
    }

    PVLine &operator=(const PVLine &other) = default;

    Move &operator[](int i) {
      return moves_[i];
    }

    void clear() {
      std::fill(moves_.begin(), moves_.end(), Move::null_move());
      move_count_ = 0;
    }

    void push(const Move& move) {
      moves_[move_count_++] = move;
    }

    [[nodiscard]] std::size_t length() const {
      return move_count_;
    }

    [[nodiscard]] std::string to_string() const {
      std::string str;
      for (int i = 0; i < move_count_; i++) {
        str += moves_[i].to_string();
        if (i < move_count_ - 1)
          str += ' ';
      }
      return str;
    }

    friend std::ostream& operator<<(std::ostream& stream, PVLine& pv_line) {
      return stream << pv_line.to_string();
    }

   private:
    std::array<Move, 1024> moves_;
    int move_count_;
  };

  struct Result {
    Move best_move; // always the first move in the PV
    PVLine pv_line;
    int evaluation;
  };

  Result go();

 private:
  int quiesce(int ply, int alpha, int beta);

  int negamax(int depth, int ply, int alpha, int beta, PVLine &pv_line);

 private:
  Board &board_;
  TimeManagement time_mgmt_;
  PVLine pv_line_this_iteration_;
  Move best_move_this_iteration_;
  int best_eval_this_iteration_;
  double branching_factor_;
  int total_bfs_;
  bool following_pv_;
};

#endif // INTEGRAL_SEARCH_H_