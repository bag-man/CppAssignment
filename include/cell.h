#ifndef CELL_H
#define CELL_H
#include <vector>
#include <iostream>
#include "board.h"
#include "aphid.h"
#include "ladybird.h"

class Aphid;
class Ladybird;
class Board;

class Cell {
  private: 
    std::vector<Aphid> aphids;
    std::vector<Ladybird> ladybirds;
    int posX, posY;

  public:
    Cell(int x, int y);
    void addAphid();
    void removeAphid();
    void addLadybird();
    void removeLadybird();
    void addLadybirdFace(int face);
    void moveCell(Board * board);
    void attackCell(Board * board);
    void mateCell(Board * board);
    int ladybirdCount();
    int aphidCount();
    std::pair<int, int> getXY();
    std::pair<int, int> findNewPosition(std::pair<int, int> direction);
};

#endif
