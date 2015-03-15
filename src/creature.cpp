#include "creature.h"

Creature::Creature(int posX, int posY) {

  /* This class should do a lot more however my use of static vars makes it a bit redundant */
  x = posX;
  y = posY;
  hasAttacked = false;

}
