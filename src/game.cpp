#include "game.h"

//Board board1, board2;
//int generation, width, height;

int main() {

  Board *board1 = new Board(10, 10);
  board1->printBoard();

  return 0;
}

void update();
