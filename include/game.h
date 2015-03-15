#ifndef GAME_H
#define GAME_H
#include <fstream>
#include <iostream>
#include <unistd.h> // Unix only
#include "board.h"
#include "aphid.h"
#include "ladybird.h"

int main();

/* Load files and generate initial board */
void init();

#endif
