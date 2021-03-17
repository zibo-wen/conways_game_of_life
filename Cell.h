#ifndef CELL_H
#define CELL_H

class Cell {
public:
	Cell(bool value = false);
	void updateCurr();
	void setNext(bool value);
	void changeAdjAlive(int value);
	bool getCurr();
	bool getNext();
	int getAdjAlive();


private:
	bool currState;
	bool nextState;
	int  adjAlive;
};

#endif