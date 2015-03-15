#include "aphid.h"

/* These are static constants that are set from the config files */
float Aphid::movementProb;
float Aphid::groupAttackModifier;
float Aphid::killProb;
float Aphid::mateProb;

/* Test if the aphid will move and return the direction */
std::pair<int, int> Aphid::move() {
  bool shouldMove = (rand() % 100) < (Aphid::movementProb * 100);
  if(shouldMove) {
    return Direction::moves[rand() % 9];
  } else {
    return Direction::STAY;
  }
}

/* Test if the aphid was successful in killing, comrades is the number of other aphids */
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
