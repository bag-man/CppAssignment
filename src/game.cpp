#include <string>
#include <fstream>
#include <iostream>
#include "game.h"

Board *board1, *board2;
int generation, width, height;

using namespace std;

int main() {

  loadFiles();
  Board *board1 = new Board(10, 10);
  board1->printBoard();

  return 0;
}

bool loadFiles() {

  string line;
  ifstream simulation ("../configs/simulation.conf");
  if(simulation.is_open()) {
    while(getline(simulation, line)) {
      cout << line << '\n';
    }
    simulation.close();
  } else cout << "Simulation config not found.\n"; 

  return true;

}
