#ifndef CELL_H
#define CELL_H
#include <list>
#include "aphid.h"
#include "ladybird.h"
#include "board.h"

class Cell {
  private: 
    std::list<Aphid *> aphids;
    std::list<Ladybird *> ladybirds;
    int posX, posY;

  public:
    Cell(int x, int y);
    void update(Cell * cell, Board * board);
    void addAphid();
    void addLadybird();
    int ladybirdCount();
    int aphidCount();
    std::pair<int, int> getXY();
};

#endif
