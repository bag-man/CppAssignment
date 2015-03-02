#include <iostream>
#include <string>
#include <cstdlib>
#include "board.h"

using namespace std;

Cell ***cells;
int width, height;

Board::Board(int w, int h) {

  width = w;
  height = h;

  cells = (Cell ***) malloc(w* sizeof(Cell *));
  for (int i = 0; i < w; i++){
    cells[i] = (Cell **) malloc(h* sizeof(Cell *));
    for (int j = 0; j < h; j++){
      cells[i][j] = new Cell(0,0);
    }
  }

}

Cell * getCell(int x, int y) {

  return cells[x][y];

}

void Board::printBoard() {
  string aphid = "\033[42m \033[m";
  string ladybird = "\033[41m \033[m";

  for(int i = 0; i < width; i++) {
    cout << "\n";
    for(int i = 0; i < height; i++) {
      cout << "  ";
      cout << aphid;
      cout << ladybird;
    }
    cout << "\n";
  }

}
