#ifndef BOARD_H
#define BOARD_H
#include "cell.h"
#include "direction.h"

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
    std::pair<int, int> findNewPosition(std::pair<int, int> startCell, std::pair<int, int> direction);
};

#endif
