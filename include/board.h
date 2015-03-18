#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <functional>
#include "cell.h"
#include "direction.h"

// Define the max number of creatures to display in a cell
#define MAX_CREATURE_DISPLAY 9

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

    void forEachCell(std::function<void(Cell*)> callback);

    /* Helper functions */
    Cell * getNextGenCell();
    Cell * getCell(int x, int y);
    int aphidCount();
    int ladybirdCount();
    int getH();
    int getW();
};

#endif
