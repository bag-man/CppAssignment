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
      ./main [--config=<dir>] [--step]

    Options:
      -h --help       Show this screen.
      --version       Show version.
      --config=<dir>  Rirectory to load config files from [default: configs/].
      --step          Require enter press to step through animation, defaults to auto run.

    Configs:
      In the configs folder you need:
      
      * simulation.conf
      * aphids.conf
      * ladybirds.conf

      These will dictate the properties of the creatures and where they begin. 
      Check the docs folder for more information.
  )";

int main(int argc, const char** argv);

/* Exit with usage */
void quit();

/* Load files and generate initial board */
void init(std::string dir);

#endif
