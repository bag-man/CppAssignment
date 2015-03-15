#include "cell.h"

using namespace std;

Cell::Cell(int x, int y) {
  posX = x;
  posY = y;
}

void Cell::moveCell(Board * board) {
  /* Iterate over Aphids and move them to the new board */
  for(auto it=aphids.begin(); it != aphids.end(); ++it) {
    pair<int, int> newPos;
    do {
      newPos = findNewPosition((*it).move());
    } while(newPos.first < 0 || newPos.second < 0 || newPos.first >= board->getW() || newPos.second >= board->getH());
    board->getCell(newPos.first, newPos.second)->addAphid(); // This should MOVE the object really. 
  }

  /* Iterate over ladybirds and move them to the new board */
  for(auto it=ladybirds.begin(); it != ladybirds.end(); ++it) {
    pair<int, int> newPos;
    int facing;
    do {
      newPos = findNewPosition((*it).move());
      facing = (*it).getFacing(); // To retain direction. Should be passing the object. 
    } while(newPos.first < 0 || newPos.second < 0 || newPos.first >= board->getW() || newPos.second >= board->getH());
    board->getCell(newPos.first, newPos.second)->addLadybirdFace(facing);
  }
}

void Cell::attackCell(Board * board) {
  /* If a cell has aphids & ladybirds */
  if(board->getCell(posX, posY)->aphidCount() > 0 && board->getCell(posX, posY)->ladybirdCount() > 0) {

    /* Iterate over ladybirds and see if they kill any aphids */
    for(auto it=ladybirds.begin(); it != ladybirds.end(); ++it) {
      if((*it).attack() && board->getCell(posX, posY)->aphidCount() > 0) { 
        board->getCell(posX, posY)->removeAphid();
      }
    }

    /* Iterate over aphids and see if they kill any ladybirds */
    for(auto it=aphids.begin(); it != aphids.end(); ++it) {
      if((*it).attack(aphids.size()) && board->getCell(posX, posY)->ladybirdCount() > 0) { 
        board->getCell(posX, posY)->removeLadybird();
      }
    }
  }
}

void Cell::mateCell(Board * board) {
  if(aphids.size() > 1) { 
    /* For the number of pairs of aphids, see if they mate */
    for(unsigned int i = 0; i < (aphids.size() / 2); i++) {
      if((rand() % 100) < (Aphid::mateProb * 100)) {
        board->getCell(posX, posY)->addAphid();
      }
    }
  }

  if(ladybirds.size() > 1) {
    /* For the number of pairs of ladybirds, see if they mate */
    for(unsigned int i = 0; i < (ladybirds.size() / 2); i++) {
      if((rand() % 100) < (Ladybird::mateProb * 100)) {
        board->getCell(posX, posY)->addLadybird();
      }
    }
  }
}

/* Get the new board position based on a direction */
pair<int, int> Cell::findNewPosition(pair<int, int> direction) {
  return make_pair(posX - direction.first, posY - direction.second);
};

/* Helper functions, add remove etc.. */
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
  return make_pair(posX, posY);
}
