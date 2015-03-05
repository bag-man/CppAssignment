#ifndef CELL_H
#define CELL_H
#include <list>
#include "board.h"

class Creature;
class Aphid;
class Ladybird;
class Board;

class Cell {
  private: 
    std::list<Aphid *> aphids;
    std::list<Ladybird *> ladybirds;
    int posX, posY;

  public:
    Cell(int x, int y);
    void addAphid();
    void addLadybird();
    void moveCell(Board * board);
    int ladybirdCount();
    int aphidCount();
    std::pair<int, int> getXY();
};

#endif
