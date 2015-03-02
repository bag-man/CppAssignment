#include "cell.h"

using namespace std;

list<Aphid *> aphids;
list<Ladybird *> ladybirds;

Cell::Cell() {

}

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
  return aphids.size();
}

void Cell::update(Cell * cell, Board * board) {

}
