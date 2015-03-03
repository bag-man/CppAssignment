#ifndef CELL_H
#define CELL_H
#include <list>

class Board;
class Creature;
class Aphid;
class Ladybird;

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
