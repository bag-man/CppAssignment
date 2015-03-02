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
    simulation >> width >> height;
    board1 = new Board(width, height);

    simulation >> aphids;
    for(int i = 0; i < aphids; i++) {
      int x, y; 
      simulation >> x >> y;
      board1->getCell(x,y)->addAphid();
    }

    simulation >> ladybirds;
    for(int i = 0; i < ladybirds; i++) {
      int x, y;
      simulation >> x >> y;
      board1->getCell(x,y)->addLadybird();
    }

    simulation.close();
  } else cout << "Simulation config not found.\n"; 

  ifstream aphids ("../configs/aphids.conf");
  if(aphids.is_open()) {
    float X,Y,Z,A;
    aphids >> X >> Y >> Z >> A;
    Aphid::movementProb = X;
    Aphid::groupAttackModifier = Y;
    Aphid::killProb = Z;
    Aphid::mateProb = A;
  } else cout << "Aphid config not found.\n"; 

  ifstream ladybirds ("../configs/ladybirds.conf");
  if(ladybirds.is_open()) {

  } else cout << "Ladybird config not found.\n"; 

  cout << Aphid::movementProb;

  return true;

}
