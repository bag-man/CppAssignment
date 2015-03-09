#include "cell.h"
#include "aphid.h"
#include "ladybird.h"
#include <iostream>

using namespace std;

list<Aphid *> aphids;
list<Ladybird *> ladybirds;
int posX, posY;

Cell::Cell(int x, int y) {
  posX = x;
  posY = y;
}

void Cell::moveCell(Board * board) {
  for (std::list<Aphid *>::iterator it=aphids.begin(); it != aphids.end(); /* ++it */) {
    pair<int, int> newPos;
    do {
      newPos = findNewPosition((*it)->move());
    } while(newPos.first < 0 || newPos.second < 0 || newPos.first >= board->getW() || newPos.second >= board->getH());
    board->getCell(newPos.first, newPos.second)->addAphid();
    ++it;
  }

  for (std::list<Ladybird *>::iterator it=ladybirds.begin(); it != ladybirds.end(); /* ++it */) {
    pair<int, int> newPos;
    int facing;
    do {
      newPos = findNewPosition((*it)->move());
      facing = (*it)->getFacing();
    } while(newPos.first < 0 || newPos.second < 0 || newPos.first >= board->getW() || newPos.second >= board->getH());
    board->getCell(newPos.first, newPos.second)->addLadybirdFace(facing);
    ++it;
  }
}

pair<int, int> Cell::findNewPosition(pair<int, int> direction) {
  return make_pair(posX - direction.first, posY - direction.second);
};

void Cell::addAphid() {
  aphids.push_back(new Aphid);
}

void Cell::addLadybird() {
  ladybirds.push_back(new Ladybird);
}

void Cell::addLadybirdFace(int face) {
  ladybirds.push_back(new Ladybird(face));
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
