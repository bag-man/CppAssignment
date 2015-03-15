#include "board.h"

Board::Board(int w, int h) {
  width = w;
  height = h;

  /* Generate the 2d vector of cells to create the grid / board */
  for (int n = 0; n < w; n++){
    std::vector<Cell*> v2(w); 
    for (int j = 0; j < h; j++){
      std::vector<std::vector<Cell *>> cells2(h, v2);
      cells = cells2;
    }
  }

  /* Populate it with cells that know where they are */
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
}

void Board::printBoard() {
  /* Clear screen */
  std::cout << "\033c";

  /* Bash colour codes */
  std::string aphid = "\e[0;30m\033[42m";
  std::string ladybird = "\e[0;30m\033[41m";
  std::string end = "\033[m";

  for(int i = 0; i < width; i++) {
    std::cout << "\n";
    for(int j = 0; j < height; j++) {
      std::cout << "  ";
      if(cells[i][j]->aphidCount() > 9)
        std::cout << aphid << "~" << end;
      else if(cells[i][j]->aphidCount())
        std::cout << aphid << cells[i][j]->aphidCount() << end;
      else
        std::cout << aphid << " " << end;

      if(cells[i][j]->ladybirdCount() > 9)
        std::cout << ladybird << "~" << end;
      else if(cells[i][j]->ladybirdCount())
        std::cout << ladybird << cells[i][j]->ladybirdCount() << end;
      else
        std::cout << ladybird << " " << end;
    }
    std::cout << "\n";
  }
}

/* Iterate over the cells and run the move into a temp board */
Board * Board::move() {
  Board * tmp = new Board(this->width, this->height);
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      cells[i][j]->moveCell(tmp);
    }
  }
  return tmp;
}

/* Iterate over a temporary board and attack */
Board * Board::attack() {
  Board * tmp = this;
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      cells[i][j]->attackCell(tmp);
    }
  }
  return tmp;
}

/* Iterate over a temporary board and mate */
Board * Board::mate() {
  Board * tmp = this;
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      cells[i][j]->mateCell(tmp);
    }
  }
  return tmp;
}

/* Count the total aphids on the board */
int Board::aphidCount() {
  int aphids = 0; 
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      aphids += cells[i][j]->aphidCount();
    }
  }
  return aphids;
}

/* Count the total ladybirds on the board */
int Board::ladybirdCount() {
  int ladybirds = 0; 
  for (int i = 0; i < width; i++){
    for (int j = 0; j < height; j++){
      ladybirds += cells[i][j]->ladybirdCount();
    }
  }
  return ladybirds;
}

/* Helper functions for Cells and H+W */
Cell * Board::getCell(int x, int y) {
  return cells[x][y];
}

int Board::getW() {
  return width;
}

int Board::getH() {
  return height;
}

