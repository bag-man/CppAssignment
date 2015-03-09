#ifndef APHID_H
#define APHID_H
#include "creature.h"
#include "direction.h"

class Aphid : public Creature {

  private: 

  public:
    static float movementProb;
    static float groupAttackModifier;
    static float killProb;
    static float mateProb;

    Aphid(int x, int y) : Creature(x, y) {};
    std::pair<int, int> move();
    bool attack();
    void print();
};

#endif
