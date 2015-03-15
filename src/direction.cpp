#include "direction.h"

 /*
 *
 * 0 | 1 | 2
 * 7 | 8 | 3
 * 6 | 5 | 4
 *
 */

const std::pair<int, int> Direction::NORTH_WEST = std::make_pair(-1,-1);
const std::pair<int, int> Direction::NORTH      = std::make_pair(0,-1);
const std::pair<int, int> Direction::NORTH_EAST = std::make_pair(1,-1);
const std::pair<int, int> Direction::EAST       = std::make_pair(1,0);
const std::pair<int, int> Direction::SOUTH_EAST = std::make_pair(1,1);
const std::pair<int, int> Direction::SOUTH      = std::make_pair(0,1);
const std::pair<int, int> Direction::SOUTH_WEST = std::make_pair(-1,1);
const std::pair<int, int> Direction::WEST       = std::make_pair(-1,0);
const std::pair<int, int> Direction::STAY       = std::make_pair(0,0);

const std::pair<int, int> Direction::moves[9] = {
  Direction::NORTH_WEST, 
  Direction::NORTH,
  Direction::NORTH_EAST,
  Direction::EAST,
  Direction::SOUTH_EAST,
  Direction::SOUTH,    
  Direction::SOUTH_WEST,
  Direction::WEST,     
  Direction::STAY     
};
