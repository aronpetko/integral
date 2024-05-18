#ifndef INTEGRAL_UCI_H_
#define INTEGRAL_UCI_H_

#include "board.h"
#include "fen.h"
#include "uci_option.h"

class Search;

namespace uci {

const std::string kEngineVersion = "1";
const std::string kEngineName = std::format("Integral v{}", kEngineVersion);
const std::string kEngineAuthor = "Aron Petkovski";

void Position(Board &board, std::stringstream &input_stream);

void Go(Board &board, Search &search, std::stringstream &input_stream);

void Test(std::stringstream &input_stream);

void SetOption(std::stringstream &input_stream);

void AcceptCommands(int arg_count, char **args);

}  // namespace uci

#endif  // INTEGRAL_UCI_H_