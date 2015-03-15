#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include "cell.h"
#include "direction.h"

class Cell;

class Board {
  private: 
    /* 2D grid of cells to represent the board */
    std::vector<std::vector<Cell *>> cells;
    int width;
    int height;

  public:
    Board(int w, int h);
    ~Board();
    void printBoard();

    /* These perform the updates */
    Board * move();
    Board * attack();
    Board * mate();

    /* Helper functions */
    Cell * getNextGenCell();
    Cell * getCell(int x, int y);
    int aphidCount();
    int ladybirdCount();
    int getH();
    int getW();
};

#endif
