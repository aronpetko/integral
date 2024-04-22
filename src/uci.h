#ifndef INTEGRAL_UCI_H_
#define INTEGRAL_UCI_H_

#include "board.h"
#include "fen.h"
#include "search.h"

namespace uci {

const std::string kEngineName = "Integral";
const std::string kEngineVersion = "0.1";
const std::string kEngineAuthor = "Aron Petkovski";
const std::string kEngineDescription = "Aron Petkovski";

void position(Board &board, std::stringstream &input_stream);

void go(Board &board, Search &search, std::stringstream &input_stream);

void perft(Board &board, std::stringstream &input_stream);

void accept_commands();

}

#endif // INTEGRAL_UCI_H_