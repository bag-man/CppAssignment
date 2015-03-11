#include "creature.h"
#include "ladybird.h"
#include <stdlib.h>
#include <iostream>

float Ladybird::movementProb;
float Ladybird::directionChangeProb;
float Ladybird::killProb;
float Ladybird::mateProb;
int facing;

Ladybird::Ladybird(int x, int y) : Creature(x, y) {
  facing = rand() % 8;
}

std::pair<int, int> Ladybird::move() {
  bool shouldMove = (rand() % 100) < (Ladybird::movementProb * 100);
  if(shouldMove) {
    do {
      facing = (facing - ((rand() % 3) - 1)) % 8;
    } while ( facing < 0 );
    return Direction::moves[facing];
  } else {
    return Direction::STAY;
  }
}

Ladybird::Ladybird(int x, int y, int face) : Creature(x, y) {
  facing = face;
}

void Ladybird::attack() {
  if(!hasAttacked) {
    bool kill = (rand() % 100) < (Ladybird::killProb * 100);
    if(kill) {
      Board::getCell(x, y)->removeAphid();
      hasAttacked = true;
    }
  }
}

int Ladybird::getFacing() {
  return facing;
}
