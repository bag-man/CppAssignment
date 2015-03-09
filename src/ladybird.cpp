#include "creature.h"
#include "ladybird.h"
#include <stdlib.h>

float Ladybird::movementProb;
float Ladybird::directionChangeProb;
float Ladybird::killProb;
float Ladybird::mateProb;
int facing;

Ladybird::Ladybird() : Creature() {
  facing = rand() % 8;
}

std::pair<int, int> Ladybird::move() {
  bool shouldMove = (rand() % 100) < (Ladybird::movementProb * 100);
  if(shouldMove) {
    facing = facing - ((rand() % 3) - 1);
    return Direction::moves[facing];
  } else {
    return Direction::STAY;
  }
}

Ladybird::Ladybird(int face) : Creature() {
  facing = face;
}

int Ladybird::getFacing() {
  return facing;
}
