#include "Cell.h"

using namespace std;

// All cells are dead in default.
Cell::Cell(bool value) {
	currState = false;
	nextState = value;
	adjAlive = 0;
}

// Update the number of adjacent alive cells.
void Cell::changeAdjAlive(int value) {
	adjAlive += value;
}

// Update the status of the cell.
void Cell::updateCurr() {
	currState = nextState;
}

// Set status of the cell in the next generation
void Cell::setNext(bool value) {
	nextState = value;
}

// Return current status
bool Cell::getCurr() {
	return currState;
}

// Return status in the next generation
bool Cell::getNext() {
	return nextState;
}

// Return the number of adjacent alive cells
int Cell::getAdjAlive() {
	return adjAlive;
}