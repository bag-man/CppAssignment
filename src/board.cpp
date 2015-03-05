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

void Board::move(Board * board) {
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      cells[i][j]->move(board);
    }
  }
}

Cell * Board::getCell(int x, int y) {
  return cells[x][y];
}

pair<int, int> findNewPosition(pair<int, int> startCell, Direction direction) {
  /* This is ugly */
  std::pair<int, int> * moves = new std::pair<int, int>[8];
  moves[0] = make_pair(-1,-1);
  moves[1] = make_pair(0,-1);
  moves[2] = make_pair(1,-1);
  moves[3] = make_pair(1,0);
  moves[4] = make_pair(1,1);
  moves[5] = make_pair(0,1);
  moves[6] = make_pair(-1,1);
  moves[7] = make_pair(-1,0);
  moves[8] = make_pair(0,0);
  return make_pair(startCell.first - moves[direction].first, startCell.second - moves[direction].second);
};

void Board::printBoard() {
  cout << "\033c";
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
