#ifndef CREATURE_H
#define CREATURE_H
#include "cell.h"

class Cell;
class Board;

class Creature {

  private: 
    int x;
    int y;

  protected:
    bool hasMated;
    bool hasAttacked;

  public:
    Creature(int x, int y);
};

#endif
