#ifndef APHID_H
#define APHID_H
#include <cstdlib>
#include "creature.h"
#include "direction.h"

class Aphid : public Creature {

  private: 

  public:
    /* This breaks the OO approach. This stuff should be done in creature really */
    static float movementProb;
    static float groupAttackModifier;
    static float killProb;
    static float mateProb;

    /* Blank constructor */
    Aphid(int x, int y) : Creature(x, y) {};

    /* Return new cell that aphid has moved to */
    std::pair<int, int> move();

    /* Return if aphid has killed ladybird */
    bool attack(int comrades);
};

#endif
