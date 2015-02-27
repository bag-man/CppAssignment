#ifndef BOARD_H
#define BOARD_H
#include "cell.h"

class Board {
  private: 
    Cell * cells; // 2d Array
    int width;
    int height;

  public:
    Board(int width, int height);
    Board * update();
    Cell * getNextGenCell();
};

#endif
