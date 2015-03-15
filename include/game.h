#ifndef GAME_H
#define GAME_H
#include <fstream>
#include <iostream>
#include <unistd.h> // Unix only
#include "board.h"
#include "aphid.h"
#include "ladybird.h"

static const char USAGE[] =
  R"(
    Ladybirds and Aphids simulation.

    Usage:
    ./main [--config=<dir>]

    Options:
    -h --help Show this screen.
    --version Show version.
    --config=<dir> directory to load config files from [default: configs/].
  )";

int main(int argc, const char** argv);

/* Load files and generate initial board */
void init();

#endif
