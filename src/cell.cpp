#include "cell.h"

using namespace std;

Cell::Cell(int x, int y) {
  posX = x;
  posY = y;
}

void Cell::moveCell(Board * board) {
  for(auto it=aphids.begin(); it != aphids.end(); /* ++it */) {
    pair<int, int> newPos;
    do {
      newPos = findNewPosition((*it).move());
    } while(newPos.first < 0 || newPos.second < 0 || newPos.first >= board->getW() || newPos.second >= board->getH());
    board->getCell(newPos.first, newPos.second)->addAphid();
    ++it;
  }

  for(auto it=ladybirds.begin(); it != ladybirds.end(); /* ++it */) {
    pair<int, int> newPos;
    int facing;
    do {
      newPos = findNewPosition((*it).move());
      facing = (*it).getFacing();
    } while(newPos.first < 0 || newPos.second < 0 || newPos.first >= board->getW() || newPos.second >= board->getH());
    board->getCell(newPos.first, newPos.second)->addLadybirdFace(facing);
    ++it;
  }
}

void Cell::attackCell(Board * board) {
  if(board->getCell(posX, posY)->aphidCount() > 0 && board->getCell(posX, posY)->ladybirdCount() > 0) {
    for(auto it=ladybirds.begin(); it != ladybirds.end(); /* ++it */) {
      if((*it).attack() && board->getCell(posX, posY)->aphidCount() > 0) { 
        board->getCell(posX, posY)->removeAphid();
      }
      ++it;
    }

    for(auto it=aphids.begin(); it != aphids.end();) {
      if((*it).attack(aphids.size()) && board->getCell(posX, posY)->ladybirdCount() > 0) { 
        board->getCell(posX, posY)->removeLadybird();
      }
      ++it;
    }
  }
}

void Cell::mateCell(Board * board) {
  if(aphids.size() > 1) { 
    for(unsigned int i = 0; i < (aphids.size() / 2); i++) {
      if((rand() % 100) < (Aphid::mateProb * 100)) {
        board->getCell(posX, posY)->addAphid();
      }
    }
  }

  if(ladybirds.size() > 1) {
    for(unsigned int i = 0; i < (ladybirds.size() / 2); i++) {
      if((rand() % 100) < (Ladybird::mateProb * 100)) {
        board->getCell(posX, posY)->addLadybird();
      }
    }
  }
}

pair<int, int> Cell::findNewPosition(pair<int, int> direction) {
  return make_pair(posX - direction.first, posY - direction.second);
};

void Cell::addAphid() {
  aphids.emplace_back(posX, posY);
}

void Cell::removeAphid() {
  aphids.pop_back();
}

void Cell::removeLadybird() {
  ladybirds.pop_back();
}

void Cell::addLadybird() {
  ladybirds.emplace_back(posX, posY);
}

void Cell::addLadybirdFace(int face) {
  ladybirds.emplace_back(posX, posY, face);
}

int Cell::aphidCount() {
  return aphids.size();
}

int Cell::ladybirdCount() {
  return ladybirds.size();
}

pair<int, int> Cell::getXY() {
  /*
  pair<int, int> location = board1->getCell(x,y)->getXY();
  cout << x << " " << y << "\n";
  cout << location.first << " " << location.second << "\n";
  */
  return make_pair(posX, posY);
}
