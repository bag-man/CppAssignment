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
  }


  for (int i = 0; i < w; i++){
    for (int j = 0; j < h; j++){
      cells[i][j] = new Cell(i, j);
    }
  }

}

Cell * Board::getCell(int x, int y) {

  return cells[x][y];

}

void Board::printBoard() {
  string aphid = "\e[0;30m\033[42m";
  string ladybird = "\e[0;30m\033[41m";
  string end = "\033[m";

  for(int i = 0; i < width; i++) {
    cout << "\n";
    for(int j = 0; j < height; j++) {
      cout << "  ";
      if(cells[i][j]->aphidCount())
        cout << aphid << cells[i][j]->aphidCount() << end;
      else
        cout << aphid << " " << end;

      if(cells[i][j]->ladybirdCount())
        cout << ladybird << cells[i][j]->ladybirdCount() << end;
      else
        cout << ladybird << " " << end;

    }
    cout << "\n";
  }

}