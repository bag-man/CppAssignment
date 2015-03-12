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

  cells = (Cell ***) malloc(w * sizeof(Cell *));
  for (int i = 0; i < w; i++){
    cells[i] = (Cell **) malloc(h* sizeof(Cell *));
  }

  for (int n = 0; n < w; n++){
    for (int j = 0; j < h; j++){
      cells[n][j] = new Cell(n, j);
    }
  }
}

Board::~Board() {
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      delete cells[i][j];
    }
  }
  free(cells);
}

int Board::aphidCount() {
  int aphids; 
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      aphids += cells[i][j]->aphidCount();
    }
  }
  return aphids;
}

int Board::ladybirdCount() {
  int ladybirds; 
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      ladybirds += cells[i][j]->ladybirdCount();
    }
  }
  return ladybirds;
}

Board * Board::move() {
  Board * tmp = new Board(this->width, this->height);
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      cells[i][j]->moveCell(tmp);
    }
  }
  return tmp;
}

Board * Board::attack() {
  Board * tmp = this;
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      cells[i][j]->attackCell(tmp);
    }
  }
  return tmp;
}

Board * Board::mate() {
  Board * tmp = this;
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      cells[i][j]->mateCell(tmp);
    }
  }
  return tmp;
}

Cell * Board::getCell(int x, int y) {
  return cells[x][y];
}

int Board::getW() {
  return width;
}

int Board::getH() {
  return height;
}

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
