#ifndef BOARD_H
#define BOARD_H
#include "cell.h"
#include "direction.h"

class Cell;
class Board {
  private: 
    std::vector<std::vector<Cell *>> cells;
    int width;
    int height;

  public:
    Board(int w, int h);
    ~Board();
    Board * move();
    Board * attack();
    Board * mate();
    Cell * getNextGenCell();
    Cell * getCell(int x, int y);
    int aphidCount();
    int ladybirdCount();
    int getH();
    int getW();
    void printBoard();
};

#endif
