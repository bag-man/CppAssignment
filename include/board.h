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
    void move(Board * board);
    Cell * getNextGenCell();
    Cell * getCell(int x, int y);
    void printBoard();
    std::pair<int, int> findNewPosition(pair<int, int> startCell, Direction direction);
};

#endif
