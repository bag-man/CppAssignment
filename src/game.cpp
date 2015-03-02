#include <string>
#include <fstream>
#include <iostream>
#include "game.h"

Board *board1, *board2;
int generation;

using namespace std;

int main() {

  init();
  board1->printBoard();

  return 0;
}

bool init() {

  int width, height;
  string word;
  ifstream simulation ("../configs/simulation.conf");
  if(simulation.is_open()) {
    int aphids, ladybirds;
    simulation >> width;
    simulation >> height;
    board1 = new Board(width, height);

    simulation >> aphids;
    for(int i = 0; i < aphids; i++) {
      int x, y; 
      simulation >> x;
      simulation >> y;
      cout << "Create cell here\n";
    }

    simulation >> ladybirds;
    for(int i = 0; i < ladybirds; i++) {
      int x, y; 
      simulation >> x;
      simulation >> y;
      cout << "Create cell here\n";
    }

    simulation.close();
  } else cout << "Simulation config not found.\n"; 

  return true;

}
