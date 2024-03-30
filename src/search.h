#ifndef INTEGRAL_SEARCH_H_
#define INTEGRAL_SEARCH_H_

#include "board.h"
#include "eval.h"
#include "time_mgmt.h"

class Search {
 public:
  explicit Search(TimeManagement::Config &time_config, Board &board);

  static constexpr int kMaxSearchDepth = 100;
  static std::array<std::array<int, 512>, kMaxSearchDepth + 1> kLateMoveReductionTable;

  static void init_tables();

  // principal variation (PV) line of the search
  struct PVLine {
   public:
    PVLine() : moves_({}), move_count_(0) {
      clear();
    }

    Move &operator[](int i) {
      return moves_[i];
    }

    void clear() {
      moves_.fill(Move::null_move());
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
    std::array<Move, kMaxPlyFromRoot> moves_;
    int move_count_;
  };

  struct Result {
    Move best_move;
    PVLine pv_line;
    int score;

    Result() : best_move(Move::null_move()), pv_line(), score(std::numeric_limits<int>::min()) {}
  };

  Result go();

 private:
  int quiesce(int ply, int alpha, int beta);

  [[nodiscard]] int search(int depth, int ply, int alpha, int beta, PVLine &pv_line);

  [[nodiscard]] Result search_root(int depth, int ply, int alpha, int beta);

  Result iterative_deepening();

 private:
  Board &board_;
  TimeManagement time_mgmt_;
  double branching_factor_;
  int total_bfs_;
  bool can_do_null_move_;
};

#endif // INTEGRAL_SEARCH_H_