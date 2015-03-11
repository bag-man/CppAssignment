#ifndef CREATURE_H
#define CREATURE_H
#include "cell.h"

class Cell;
class Board;

class Creature {

  private: 

  protected:
    int x;
    int y;
    bool hasMated;
    bool hasAttacked;

  public:
    Creature(int x, int y);
};

#endif
