#ifndef LADYBIRD_H
#define LADYBIRD_H
#include <cstdlib>
#include "creature.h"
#include "direction.h"

class Ladybird : public Creature {
  private: 

  public:
    static float movementProb;
    static float directionChangeProb;
    static float killProb;
    static float mateProb;
    int facing;

    Ladybird(int x, int y);
    Ladybird(int x, int y, int face); 
    std::pair<int, int> move();
    int getFacing();
    bool attack();
};

#endif
