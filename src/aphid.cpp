#include "creature.h"
#include "aphid.h"
#include <iostream>
#include <stdlib.h>

float Aphid::movementProb;
float Aphid::groupAttackModifier;
float Aphid::killProb;
float Aphid::mateProb;

Direction Aphid::move() {
  bool shouldMove = (rand() % 100) < (movementProb * 100);
  if(shouldMove) {
    return Direction(rand() % 8);
  } else {
    return STAY;
  }
}
