#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <time.h>
#include "Cell.h"
#include "Game_Of_Life.h"

using namespace std;

int main(int argc, char *argv[])
{
	// Getting initialization configs from user input. 
	string size, filename;

	cout << "Enter the size of the board: " << endl;
	cin >> size;
	cout << "Enter name of the initialization file: " << endl;
	cin >> filename;

	// Run the Conway's Game of Life
	Game gameOfLife(stoi(size), stoi(size), filename);
	int generation = 0;
	while (true) {

		// Measure the execution time
		clock_t start_s = clock();
		gameOfLife.nextGen();
		cout << "Lives in Generation # " << generation << endl;
		cout << "(Execution time: " << clock() - start_s << " ms)" << endl;

		// Print the life patterns
		gameOfLife.printBoard();
		cout << "\n\n" << endl;

		generation++;
		
		//cin.ignore();
		Sleep(500);
	}

	return 0;
}