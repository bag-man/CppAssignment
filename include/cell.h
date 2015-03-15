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
    /* List of aphids and ladybirds. Should probably be a list of creatures for OO approach */
    std::vector<Aphid> aphids;
    std::vector<Ladybird> ladybirds;
    int posX, posY;

  public:
    Cell(int x, int y);

    /* Update the cells */
    void moveCell(Board * board);
    void attackCell(Board * board);
    void mateCell(Board * board);

    /* Get the new cell position */
    std::pair<int, int> findNewPosition(std::pair<int, int> direction);

    /* Helpers */
    void addAphid();
    void removeAphid();
    void addLadybird();
    void removeLadybird();
    void addLadybirdFace(int face);
    int ladybirdCount();
    int aphidCount();
    std::pair<int, int> getXY();
};

#endif
