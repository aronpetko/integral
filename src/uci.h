#ifndef INTEGRAL_UCI_H_
#define INTEGRAL_UCI_H_

#include "board.h"
#include "fen.h"
#include "search.h"

namespace uci {

const std::string kEngineVersion = "0.1";

Board create_board(std::stringstream &input_stream);

void position(Board &board, std::stringstream &input_stream);

void go(Board &board, std::stringstream &input_stream);

void perft(Board &board, std::stringstream &input_stream);

void accept_commands();

}

#endif //INTEGRAL_UCI_H_