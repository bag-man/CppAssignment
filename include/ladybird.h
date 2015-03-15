#ifndef LADYBIRD_H
#define LADYBIRD_H
#include <cstdlib>
#include "creature.h"
#include "direction.h"

class Ladybird : public Creature {
  private: 

  public:
    /* This should really be in creature, but this approach is simpler */
    static float movementProb;
    static float directionChangeProb;
    static float killProb;
    static float mateProb;

    int facing;

    Ladybird(int x, int y);

    /* Shouldn't do this, should have an OO approach */
    Ladybird(int x, int y, int face); 

    /* Return new cell that ladybird has moved to */
    std::pair<int, int> move();

    /* Return if lady birds kills aphid */
    bool attack();

    /* Lazy helper */
    int getFacing();
};

#endif
