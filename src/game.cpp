#include "game.h"

using namespace std;

Board *board;

int main() {

  Board *oldBoard;
  int generation = 0;

  init();
  board->printBoard();
  cout << "\n\nPress enter to begin...\n";

  while(1) {   
    oldBoard = board;
    board = oldBoard->move()->attack()->mate();
    board->printBoard();
    delete oldBoard;

    cout << "\n\n";
    cout << "GENERATION: " << generation++ << "\n";
    cout << "APHIDS: " << board->aphidCount() << "\n";
    cout << "LADYBIRDS: " << board->ladybirdCount() << "\n";
    
    if(board->aphidCount() == 0) {
      cout << "\nLadybirds have won!\n\n";
      break;
    }

    if(board->ladybirdCount() == 0) {
      cout << "\nAphids have won!\n\n";
      break;
    }
    usleep(10000); // 200000 for sane
    //getchar();
  }

  return 0;
}

void init() {

  /* Seed random with time */
  srand(time(0));

  /* Load simulation config file */
  ifstream simulation ("../configs/simulation.conf");
  if(simulation.is_open()) {

    int aphids, ladybirds, width, height;
    simulation >> width >> height;
    board = new Board(width, height);

    simulation >> aphids;
    for(int i = 0; i < aphids; i++) {
      int x, y; 
      simulation >> x >> y;
      board->getCell(x,y)->addAphid();
    }

    simulation >> ladybirds;
    for(int i = 0; i < ladybirds; i++) {
      int x, y;
      simulation >> x >> y;
      board->getCell(x,y)->addLadybird();
    }

    simulation.close();
  } else cout << "Simulation config not found.\n"; 

  /* Load aphids config file */
  ifstream aphids ("../configs/aphids.conf");
  if(aphids.is_open()) {
    aphids >> Aphid::movementProb;
    aphids >> Aphid::groupAttackModifier;
    aphids >> Aphid::killProb;
    aphids >> Aphid::mateProb;
    aphids.close();
  } else cout << "Aphid config not found.\n"; 

  /* Load ladybirds config file */
  ifstream ladybirds ("../configs/ladybirds.conf");
  if(ladybirds.is_open()) {
    ladybirds >> Ladybird::movementProb;
    ladybirds >> Ladybird::directionChangeProb;
    ladybirds >> Ladybird::killProb;
    ladybirds >> Ladybird::mateProb;
    ladybirds.close();
  } else cout << "Ladybird config not found.\n"; 

}
