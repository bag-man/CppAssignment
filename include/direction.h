#ifndef DIRECTION_H
#define DIRECTION_H

//std::pair<int, int> * moves = new std::pair<int, int>[8];
typedef struct coord {
  int x;
  int y;
};

enum Direction { 
  NORTH_WEST = coord {.x = -1, .y =-1},
  NORTH = 1, 
  NORT_EAST = 2, 
  EAST = 3,
  SOUTH_EAST = 4, 
  SOUTH = 5, 
  SOUTH_WEST = 6, 
  WEST = 7, 
  STAY = 8,
};

#endif
