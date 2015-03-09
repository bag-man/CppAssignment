#ifndef CREATURE_H
#define CREATURE_H
#include "cell.h"

class Cell;
class Board;

class Creature {
  private: 
    Cell * cell;
    bool hasMated;
    bool hasAttacked;

  public:
    bool shouldMove();
    bool mate(Creature * partner);
    // Where am I?
};

#endif
