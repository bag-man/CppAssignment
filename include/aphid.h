#ifndef ApHID_H
#define ApHID_H
#include "creature.h"
#include "direction.h"

class Aphid : public Creature {
  private: 

  public:
    static float movementprob;
    static float groupAttackModifier;
    static float killprob;
    static float mateprob;

    Direction move();
    bool attack();
};

#endif
