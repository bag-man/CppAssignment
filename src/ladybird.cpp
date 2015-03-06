#include "creature.h"
#include "ladybird.h"

float Ladybird::movementProb;
float Ladybird::directionChangeProb;
float Ladybird::killProb;
float Ladybird::mateProb;
std::pair<int, int> facing;

Ladybird::Ladybird(std::pair<int, int> startFacing) {
  facing = startFacing;
}

std::pair<int, int> Ladybird::move() {
  bool shouldMove = (rand() % 100) < (movementProb * 100);
  if(shouldMove) {
    return Direction::moves[rand() % 9];
  } else {
    return Direction::STAY;
  }
}
