#include "game.h"
#include "docopt/docopt.h"

/* This probably shouldn't be global */
Board *board;

int main(int argc, const char** argv) {

  /* Use docopt argument parser */
  auto args = docopt::docopt(USAGE, { argv + 1, argv + argc }, true, "1.0"); 
  //std::map<std::string, docopt::value> args = docopt::docopt(USAGE, { argv + 1, argv + argc }, true, "1.0"); 

  for(auto const& arg : args) {
    std::cout << arg.first <<  arg.second << std::endl;
  }
  getchar();


  Board *oldBoard;
  int generation = 0;

  /* Load and display the starting board */
  init();
  board->printBoard();

  while(1) {   

    /* Copy the current board so it can be removed once used */
    oldBoard = board;

    /* Each step returns a temprorary board and works on that, new board is updated */
    board = oldBoard->move()->attack()->mate();
    board->printBoard();

    /* Free up the old board */
    delete oldBoard;

    std::cout << "\n\n";
    std::cout << "GENERATION: " << generation++ << "\n";
    std::cout << "APHIDS: " << board->aphidCount() << "\n";
    std::cout << "LADYBIRDS: " << board->ladybirdCount() << "\n";
    
    /* End criteria */
    if(board->aphidCount() == 0) {
      std::cout << "\nLadybirds have won!\n\n";
      break;
    }

    if(board->ladybirdCount() == 0) {
      std::cout << "\nAphids have won!\n\n";
      break;
    }
    usleep(10000); // 200000 for sane 10000 for testing 
    //getchar();   // For user controlled
  }

  return 0;
}

void init() {
  /* Seed random with time */
  srand(time(0));

  /* Load simulation config file */
  std::ifstream simulation ("../configs/simulation.conf");
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
  } else std::cout << "Simulation config not found.\n"; 

  /* Load aphids config file */
  std::ifstream aphids ("../configs/aphids.conf");
  if(aphids.is_open()) {
    aphids >> Aphid::movementProb;
    aphids >> Aphid::groupAttackModifier;
    aphids >> Aphid::killProb;
    aphids >> Aphid::mateProb;
    aphids.close();
  } else std::cout << "Aphid config not found.\n"; 

  /* Load ladybirds config file */
  std::ifstream ladybirds ("../configs/ladybirds.conf");
  if(ladybirds.is_open()) {
    ladybirds >> Ladybird::movementProb;
    ladybirds >> Ladybird::directionChangeProb;
    ladybirds >> Ladybird::killProb;
    ladybirds >> Ladybird::mateProb;
    ladybirds.close();
  } else std::cout << "Ladybird config not found.\n"; 
}
