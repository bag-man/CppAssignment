#include "ladybird.h"

/* These are static constants read in from the config files */
float Ladybird::movementProb;
float Ladybird::directionChangeProb;
float Ladybird::killProb;
float Ladybird::mateProb;

/* Initialise facing a random direction */
Ladybird::Ladybird(int x, int y) : Creature(x, y) {
  facing = rand() % 8;
}

/* Initialise with a direction, this is a hack and shouldn't be done in a properly OO solution */
Ladybird::Ladybird(int x, int y, int face) : Creature(x, y) {
  facing = face;
}

/* Determine direction of movement */
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


/* Determine if it has killed, this could be done in creature if it weren't for the static vars */
bool Ladybird::attack() {
  if(!hasAttacked) {
    bool kill = (rand() % 100) < (Ladybird::killProb * 100);
    if(kill) {
      hasAttacked = true;
      return true;
    }
  }
  return false;
}

/* Helpers */
int Ladybird::getFacing() {
  return facing;
}
