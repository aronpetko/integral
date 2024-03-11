#include "uci.h"
#include "move_gen.h"

#include <string>
#include <format>
#include <fstream>

namespace uci {

Board create_board(std::stringstream &input_stream) {
  std::string position_type;
  input_stream >> position_type;

  std::string position;
  if (position_type == "fen") {
    position = input_stream.str().substr(static_cast<int>(input_stream.tellg()) + 1);
  } else if (position_type == "startpos") {
    position = fen::kStartFen;
  }

  // todo: set this as an option
  const int kTranspositionTableMbSize = 64;
  return Board(fen::string_to_board(position), kTranspositionTableMbSize);
}

void position(Board &board, std::stringstream &input_stream) {
  std::string dummy;
  while (input_stream >> dummy && dummy != "moves");

  std::string move_input;
  while (input_stream >> move_input);

  // we now have the last move sent in the position
  const auto move = Move::from_str(board.get_state(), move_input);
  if (move.has_value()) {
    board.make_move(move.value());
  } else {
    std::cerr << std::format("invalid move: {}\n", move_input);
  }
}

void go(Board &board, std::stringstream &input_stream) {
  TimeManagement::Config time_config{};

  std::string option;

  while (input_stream >> option) {
    if (option == "wtime") {
      input_stream >> time_config.time[Color::kWhite];
    } else if (option == "btime") {
      input_stream >> time_config.time[Color::kBlack];
    } else if (option == "winc") {
      input_stream >> time_config.increment[Color::kWhite];
    } else if (option == "binc") {
      input_stream >> time_config.increment[Color::kBlack];
    } else if (option == "movetime") {
      input_stream >> time_config.move_time;
    } else if (option == "depth") {
      input_stream >> time_config.depth;
    } else if (option == "infinite") {
      time_config.depth = 20;
    } else if (option == "perft") {
      perft(board, input_stream);
      return;
    }
  }

  if (option.empty())
    time_config.depth = 13;

  const Move best_move = Search(time_config, board).find_best_move();
  board.make_move(best_move);

  std::cout << std::format("bestmove {}", best_move.to_string()) << std::endl;
}

int perft_internal(Board &board, int depth) {
  if (depth == 0)
    return 1;

  auto &state = board.get_state();

  int positions = 0;
  auto moves = generate_moves(board);

  for (int i = 0; i < moves.size(); i++) {
    board.make_move(moves[i]);
    if (!king_in_check(flip_color(state.turn), state)) {
      positions += perft_internal(board, depth - 1);
    }
    board.undo_move();
  }

  return positions;
}

void perft(Board &board, std::stringstream &input_stream) {
  int depth;

  std::string option;
  if (input_stream >> option && option == "depth") {
    input_stream >> depth;
    assert(depth >= 0);

    std::cout << std::format("perft({}): {}", depth, perft_internal(board, depth)) << std::endl;
  }
}

void accept_commands() {
  std::cout << std::format("Integral v{}", kEngineVersion) << std::endl;

  // initialize ray attacks for sliding pieces and knight attacks
  initialize_attacks();

  std::ofstream log("/Users/aron/Desktop/log.txt", std::ios_base::out | std::ios_base::app);
  log << "new process" << std::endl;

  std::optional<Board> board;

  std::string input_line;
  while (input_line != "quit") {
    std::getline(std::cin, input_line);
    std::stringstream input_stream(input_line);

    log << input_line << std::endl;

    std::string command;
    input_stream >> command;

    if (command == "uci") {
      std::cout << "id name Integral" << std::endl;
      std::cout << "id author Aron Petkovski" << std::endl;
      std::cout << "uciok" << std::endl;
    } else if (command == "isready") {
      std::cout << "readyok" << std::endl;
    } else if (command == "position") {
      if (!board.has_value()) {
        board = create_board(input_stream);
      } else {
        position(board.value(), input_stream);
      }
    } else if (command == "go") {
      go(board.value(), input_stream);
    }
  }

  log.close();
}

}