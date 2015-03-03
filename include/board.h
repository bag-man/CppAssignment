#ifndef BOARD_H
#define BOARD_H
#include "cell.h"

class Cell;
class Board {
  private: 
    /*Cell ** cells; // 2d Array
    int width;
    int height;*/

  public:
    Board(int w, int h);
    Board * update();
    Cell * getNextGenCell();
    Cell * getCell(int x, int y);
    void printBoard();
};

#endif
