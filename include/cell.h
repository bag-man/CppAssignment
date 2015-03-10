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
    ~Cell();
    void addAphid();
    void addLadybird();
    void addLadybirdFace(int face);
    void moveCell(Board * board);
    int ladybirdCount();
    int aphidCount();
    std::pair<int, int> getXY();
    std::pair<int, int> findNewPosition(std::pair<int, int> direction);
};

#endif
