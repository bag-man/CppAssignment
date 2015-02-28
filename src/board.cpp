#include <iostream>
#include <string>
#include "board.h"

using namespace std;

Cell * cells; // 2d array
int width, height;

Board::Board(int w, int h) {

  height = h;
  width = w;

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
