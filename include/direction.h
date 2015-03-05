#ifndef DIRECTION_H
#define DIRECTION_H
#include <utility>

class Direction {
  public:
    const static std::pair<int, int> NORTH_WEST;
    const static std::pair<int, int> NORTH;
    const static std::pair<int, int> NORTH_EAST;
    const static std::pair<int, int> EAST;
    const static std::pair<int, int> SOUTH_EAST;
    const static std::pair<int, int> SOUTH;
    const static std::pair<int, int> SOUTH_WEST;
    const static std::pair<int, int> WEST;
    const static std::pair<int, int> STAY;
    const static std::pair<int, int> moves[9];
};

#endif
