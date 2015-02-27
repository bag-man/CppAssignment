#ifndef CELL_H
#define CELL_H
#include <list>
#include "aphid.h"
#include "ladybird.h"
#include "board.h"

class Cell {
  private: 
    std::list<Aphid> aphids;
    std::list<Ladybird> ladybirds;

  public:
    Cell(int aphidCount, int ladybirdCount);
    void update(Cell * cell, Board * board);
};

#endif
