#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include "Game_Of_Life.h"

using namespace std;

// Initialization
Game::Game(int width, int height, string filename) {

	// Creating map according to the given size
	this->width  = width;
	this->height = height;

	board = new Cell*[height];

	for (int i = 0; i < height; i++) {
		board[i] = new Cell[width];
	}

	// Try to read the initial pattern from a file
	ifstream readfile(filename);
	if (readfile.is_open()) {
		string fileline, x, y;

		while (getline(readfile, fileline)) {
			stringstream ss(fileline);

			getline(ss, x, ' ');
			getline(ss, y, ' ');

			board[stoi(x)][stoi(y)].setNext(true);
		}
	}
	// Use random initialization if the file is not found
	// Each cell has a chance of 20% to be alive
	else {
		cout << "File does not exist. Using random initialization." << endl;
		
		srand(GetTickCount());
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (rand() % 5 == 1) {
					board[i][j].setNext(true);
				}
			}
		}

	}
}


// Free the memory
Game::~Game() {
	for (int i = 0; i < height; i++) {
		delete [] board[i];
	}

	delete [] board;
}

void Game::nextGen() {
	// Update the status of all cells and adjust the count of adjacent alive cells
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			// if an alive cell dies, decrease the count in adjacent cells by 1
			if (board[i][j].getCurr() && !board[i][j].getNext()) {
				updateAdjCount(i, j, -1);
				board[i][j].updateCurr();
			} 
			// if a dead cell revives, increase the count in adjacent cells by 1
			else if (!board[i][j].getCurr() && board[i][j].getNext()) {
				updateAdjCount(i, j, 1);
				board[i][j].updateCurr();
			}
		}
	}

	// Calculate the status in the next generation
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board[i][j].getCurr() && 
				(board[i][j].getAdjAlive()==2 || board[i][j].getAdjAlive()==3)) {
				// Any live cell with two or three live neighbours survives.
				board[i][j].setNext(true);
			} else if (!board[i][j].getCurr() && board[i][j].getAdjAlive() == 3) {
				// Any dead cell with three live neighbours becomes a live cell.
				board[i][j].setNext(true);
			} else {
				// All other cells are dead
				board[i][j].setNext(false);
			}
		}
	}
}


// Update the countings in all 8 adjacent cells.
// The edge of the map is connect to the opposite edge across the map.
void Game::updateAdjCount(int x, int y, int value) {
	int xx, yy;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			xx = x + i;
			yy = y + j;
			if (xx == -1) {
				xx = height-1;
			}
			else if (xx == height) {
				xx = 0;
			}
			if (yy == -1) {
				xx = width - 1;
			}
			else if (yy == width) {
				xx = 0;
			}

			if (!(i == 0 && j == 0)) {
				board[xx][yy].changeAdjAlive(value);
			}
		}
	}
}


// Print the board in the command line.
void Game::printBoard(){
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board[i][j].getCurr()) {
				cout << "* ";
			}
			else {
				cout << "  ";
			}
		}
		cout << "\n";
	}
}