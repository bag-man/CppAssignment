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
  pair<int, int> curPos = getXY();
  for (std::list<Aphid *>::iterator it=aphids.begin(); it != aphids.end(); /* ++it */) {
    pair<int, int> newPos;
    do {
      //cout << posX << "," << posY << " | ";
      //cout << newPos.first << "," << newPos.second << "\n";
      //getchar();
      newPos = findNewPosition((*it)->move());
    } while(newPos.first < 0 || newPos.second < 0 || newPos.first > board->getW() || newPos.second > board->getH());
    if(curPos != newPos) {
      board->getCell(newPos.first, newPos.second)->addAphid();
      it = aphids.erase(it);
    } else {
      ++it;
    }
  }
}

pair<int, int> Cell::findNewPosition(pair<int, int> direction) {
  //cout << posX << "," << posY << "|" << posX - direction.first << "," << posY - direction.second << "\n";
  return make_pair(posX - direction.first, posY - direction.second);
};

void Cell::addAphid() {
  aphids.push_back(new Aphid);
}

void Cell::addLadybird() {
  ladybirds.push_back(new Ladybird);
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
