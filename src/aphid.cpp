#include "creature.h"
#include "aphid.h"
#include "direction.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

float Aphid::movementProb;
float Aphid::groupAttackModifier;
float Aphid::killProb;
float Aphid::mateProb;

std::pair<int, int> Aphid::move() {
  srand(time(0));
  bool shouldMove = (rand() % 100) < (movementProb * 100);
  if(shouldMove) {
    return Direction::moves[rand() % 9];
  } else {
    return Direction::STAY;
  }
}
