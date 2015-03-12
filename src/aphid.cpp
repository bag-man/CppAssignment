#include "creature.h"
#include "aphid.h"
#include "direction.h"
#include <stdlib.h>

float Aphid::movementProb;
float Aphid::groupAttackModifier;
float Aphid::killProb;
float Aphid::mateProb;

std::pair<int, int> Aphid::move() {
  bool shouldMove = (rand() % 100) < (Aphid::movementProb * 100);
  if(shouldMove) {
    return Direction::moves[rand() % 9];
  } else {
    return Direction::STAY;
  }
}

bool Aphid::attack(int comrades) {
  if(!hasAttacked) {
    bool kill = (rand() % 100) < ((Aphid::killProb + (Aphid::groupAttackModifier * (comrades -1))) * 100);
    if(kill) {
      hasAttacked = true;
      return true;
    }
  }
  return false;
}
