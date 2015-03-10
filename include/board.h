#ifndef BOARD_H
#define BOARD_H
#include "cell.h"
#include "direction.h"

class Cell;
class Board {
  private: 
    Cell *** cells; // 2d Array
    int width;
    int height;

  public:
    Board(int w, int h);
    ~Board();
    Board * move();
    Cell * getNextGenCell();
    Cell * getCell(int x, int y);
    int getH();
    int getW();
    void printBoard();
};

#endif
