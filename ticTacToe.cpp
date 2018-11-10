#include "stdafx.h"
#include <iostream>

using namespace std;

class playGrid {

public:
	playGrid();

	~playGrid() {
		cout << "--Game memory cleared--" << endl;
	}
	
	void printGrid();

	void setOppMove(int, int);
	void setPlayerMove(int, int);

	bool getWinner();
	void retWinnerOPP(); 
	void retWinnerOutPlayer(); 
	
	void getTie();

private:
	int checkSum = 9;

	char grid[3][3];

	bool winnerOut = false;
	bool playOne = false;
	bool playOPP = false;
};

bool playGrid::getWinner() {
	return winnerOut;
}

void playGrid::getTie() {
	if (checkSum == 0 && winnerOut != true) {
		cout << "The game is a tie." << endl;
		winnerOut = true;
	}
}

void playGrid::retWinnerOutPlayer() {

	// horizon check
	if (grid[0][0] == 'x' && grid[0][1] == 'x' && grid[0][2] == 'x') {
		playOne = true;
	}
	else if (grid[1][0] == 'x' && grid[1][1] == 'x' && grid[1][2] == 'x') {
		playOne = true;
	}
	else if (grid[2][0] == 'x' && grid[2][1] == 'x' && grid[2][2] == 'x') {
		playOne = true;
	}

	// diag check
	else if (grid[0][0] == 'x' && grid[1][1] == 'x' && grid[2][2] == 'x') {
		playOne = true;
	}
	else if (grid[2][0] == 'x' && grid[1][1] == 'x' && grid[0][2] == 'x') {
		playOne = true;
	}

	//vertical check
	else if (grid[0][0] == 'x' && grid[1][0] == 'x' && grid[2][0] == 'x') {
		playOne = true;
	}
	else if (grid[0][1] == 'x' && grid[1][1] == 'x' && grid[2][1] == 'x') {
		playOne = true;
	}
	else if (grid[0][2] == 'x' && grid[1][2] == 'x' && grid[2][2] == 'x') {
		playOne = true;
	}
	
	if (playOne == true) {
		cout << "Player wins." << endl;
		winnerOut = true;
	}
}

void playGrid::retWinnerOPP() {
	
	// horizon check
	if (grid[0][0] == 'o' && grid[0][1] == 'o' && grid[0][2] == 'o') {
		playOPP = true;
	}
	else if (grid[1][0] == 'o' && grid[1][1] == 'o' && grid[1][2] == 'o') {
		playOPP = true;
	}
	else if (grid[2][0] == 'o' && grid[2][1] == 'o' && grid[2][2] == 'o') {
		playOPP = true;
	}

	// diag check
	else if (grid[0][0] == 'o' && grid[1][1] == 'o' && grid[2][2] == 'o') {
		playOPP = true;
	}
	else if (grid[2][0] == 'o' && grid[1][1] == 'o' && grid[0][2] == 'o') {
		playOPP = true;
	}

	//vertical check
	else if (grid[0][0] == 'o' && grid[1][0] == 'o' && grid[2][0] == 'o') {
		playOPP = true;
	}
	else if (grid[0][1] == 'o' && grid[1][1] == 'o' && grid[2][1] == 'o') {
		playOPP = true;
	}
	else if (grid[0][2] == 'o' && grid[1][2] == 'o' && grid[2][2] == 'o') {
		playOPP = true;
	}

	if (playOPP == true) {
		cout << "OPP wins." << endl;
		winnerOut = true;
	}
}

playGrid::playGrid() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			grid[i][j] = '.';
		}
	}
}

void playGrid::printGrid() {
	for (int outer = 0; outer < 3; outer++) {
		for (int inner = 0; inner < 3; inner++) {
			cout << grid[outer][inner] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void playGrid::setPlayerMove(int x, int y) {
	if (grid[x][y] == '.') {
		grid[x][y] = 'x';
		checkSum--;
	}

	else if (grid[x][y] == 'o') {
		cout << "Invalid move" << endl;
		cout << endl;
		grid[x][y] = 'o';
	}

	else if (grid[x][y] == 'x') {
		cout << "Player already obtained that position." << endl;
		cout << endl;
		grid[x][y] = 'x';
	}

	else if (x >= 3 || y >= 3) {
		cout << "Coordinates out of range." << endl;
		cout << endl;
	}
}

void playGrid::setOppMove(int x, int y) {
	if (grid[x][y] == '.') {
		grid[x][y] = 'o';
		checkSum--;
	}

	else if (grid[x][y] == 'x') {
		cout << "Invalid move" << endl;
		cout << endl;
		grid[x][y] = 'x';
	}

	else if (grid[x][y] == 'o') {
		cout << "Player already obtained that position." << endl;
		cout << endl;
		grid[x][y] = 'o';
	}

	else if (x >= 3 || y >= 3) {
		cout << "Coordinates out of range." << endl;
		cout << endl;
	}
}

int main() {

	int x, y;
	char resp = 'n';
	char toLowerResp;

	cout << "Do you wish to play a game(y/n): ";
	cin >> resp;
	cout << endl;
	toLowerResp = tolower(resp);

	if (toLowerResp == 'y') {

		playGrid* newPlayGrid = new playGrid();
		newPlayGrid->printGrid();

		while (newPlayGrid->getWinner() != true) {

			cout << "Player move..." << endl << "enter x: ";
			cin >> x;
			cout << "enter y: ";
			cin >> y;
			cout << endl;

			newPlayGrid->setPlayerMove(x-1, y-1);
			newPlayGrid->printGrid();
			newPlayGrid->retWinnerOutPlayer();

			newPlayGrid->getTie(); // check for tie

			if (newPlayGrid->getWinner() == true) {
				delete newPlayGrid;
				break;
			}

			cout << "Opponent move..." << endl << "enter x: ";
			cin >> x;
			cout << "enter y: ";
			cin >> y;
			cout << endl;

			newPlayGrid->setOppMove(x-1, y-1);
			newPlayGrid->printGrid();
			newPlayGrid->retWinnerOPP();

			newPlayGrid->getTie(); //check for tie

			if (newPlayGrid->getWinner() == true) {
				delete newPlayGrid;
				break;
			}
		}	
	}

	else if (toLowerResp == 'n') {
		cout << "Thank you, goodbye." << endl;
	}

	else if (toLowerResp != 'n' || toLowerResp != 'y') {
		cout << "Invalid response." << endl;
	}
	return 0;
}
