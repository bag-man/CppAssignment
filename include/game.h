#ifndef GAME_H
#define GAME_H
#include "board.h"

class Game {
  private: 

    /* Store next and current generation */
    Board board1;
    Board board2;

    /* Number of updates */
    int generation;

    /* Board dimensions */
    int width;
    int height;

    /* Update the game, new generation */
    void update();

    /* Run when the game ends */
    void quit();

    /* Read in the configuration files */
    bool loadFiles();

    /* initialise the game / create the board */
    bool init();
    
  public:
    int main();
};

#endif
