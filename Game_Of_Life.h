#ifndef GOL_H
#define GOL_H

#include <string>
#include "Cell.h"

using namespace std;

class Game {
public:
	Game(int width, int height, string filename);
	~Game();
	void nextGen();
	void printBoard();

private:
	int width;
	int height;
	Cell **board;
	void updateAdjCount(int x, int y, int value);
};

#endif