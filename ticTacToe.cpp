// ticTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
// Old code 11/5
/*
class playArea {
public:
	playArea() {
		cout << "Done" << endl;
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				grid[i][j].push_back('.');
			}
		}
		
	};

	void setGrid();
	void printPlayArea();
	// vector<vector<char>> fillPlayArea();
	// void setPlayerMove(int, int);
	// void setOppMove(int, int);

private:
	vector<vector<char>>* grid;
	vector<int> playerMoves;
	vector<int> oppMoves;

};


void playArea::setGrid() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			grid[i][j].push_back('.');
		}
	}
}



vector<vector<char>> playArea::fillPlayArea() {
	vector<vector<char>>playGrid(2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			playGrid[i][j] = '.';
		}
	}
	return playGrid;
}


void playArea::printPlayArea() {
	for (int outer = 0; outer < grid->size(); outer++) {
		for (int inner = 0; inner < grid->size(); inner++) {
			cout << (*grid)[outer][inner] << endl;
		}
	}
}


int main() {
	playArea* newPlayArea = new playArea();
	newPlayArea->setGrid();
	(*newPlayArea);
	(newPlayArea)->printPlayArea();
	delete newPlayArea;
	return 0;
}
*/

// New code 11/6

// Main class for implementation of game
// used contructor for filling 2d array as grid
// print function and setters for player movements
class playGrid {

public:
	playGrid();
	// void fillGrid();
	void printGrid();
	void setOppMove(int, int);
	void setPlayerMove(int, int);

	bool getWinner();
	void retWinnerOPP();
	void retWinnerOutPlayer();

private:
	char contain[3][3];

	bool winnerOut = false;
	bool playOne = false;
	bool playOPP = false;
};


// boolean to maintain while loop in 'main'
bool playGrid::getWinner() {
	return winnerOut;
}

////////////////
// play check //
////////////////
// checks the eight different combinations player could win
// sets boolean for playOne to true and the condition for exiting loop to true
void playGrid::retWinnerOutPlayer() {

	// horizon
	if (contain[0][0] == 'x' && contain[0][1] == 'x' && contain[0][2] == 'x') {
		playOne = true;
	}
	else if (contain[1][0] == 'x' && contain[1][1] == 'x' && contain[1][2] == 'x') {
		playOne = true;
	}
	else if (contain[2][0] == 'x' && contain[2][1] == 'x' && contain[2][2] == 'x') {
		playOne = true;
	}

	// diag
	else if (contain[0][0] == 'x' && contain[1][1] == 'x' && contain[2][2] == 'x') {
		playOne = true;
	}
	else if (contain[2][0] == 'x' && contain[1][1] == 'x' && contain[0][2] == 'x') {
		playOne = true;
	}

	//vert
	else if (contain[0][0] == 'x' && contain[1][0] == 'x' && contain[2][0] == 'x') {
		playOne = true;
	}
	else if (contain[0][1] == 'x' && contain[1][1] == 'x' && contain[2][1] == 'x') {
		playOne = true;
	}
	else if (contain[0][2] == 'x' && contain[1][2] == 'x' && contain[2][2] == 'x') {
		playOne = true;
	}

	// sets 'winnerOut' to true so that while loops exits
	if (playOne == true) {
		cout << "Player wins." << endl;
		winnerOut = true;
	}
}


///////////////
// OPP check //
///////////////
// checks the eight different combinations playOPP could win
// sets boolean for playOPP to true and the condition for exiting loop to true
void playGrid::retWinnerOPP() {
	
	// horizon
	if (contain[0][0] == 'o' && contain[0][1] == 'o' && contain[0][2] == 'o') {
		playOPP = true;
	}
	else if (contain[1][0] == 'o' && contain[1][1] == 'o' && contain[1][2] == 'o') {
		playOPP = true;
	}
	else if (contain[2][0] == 'o' && contain[2][1] == 'o' && contain[2][2] == 'o') {
		playOPP = true;
	}

	// diag
	else if (contain[0][0] == 'o' && contain[1][1] == 'o' && contain[2][2] == 'o') {
		playOPP = true;
	}
	else if (contain[2][0] == 'o' && contain[1][1] == 'o' && contain[0][2] == 'o') {
		playOPP = true;
	}

	//vert
	else if (contain[0][0] == 'o' && contain[1][0] == 'o' && contain[2][0] == 'o') {
		playOPP = true;
	}
	else if (contain[0][1] == 'o' && contain[1][1] == 'o' && contain[2][1] == 'o') {
		playOPP = true;
	}
	else if (contain[0][2] == 'o' && contain[1][2] == 'o' && contain[2][2] == 'o') {
		playOPP = true;
	}

	// sets 'winnerOut' to true so that while loops exits
	if (playOPP == true) {
		cout << "OPP wins." << endl;
		winnerOut = true;
	}
}


// class constructor that is filled with dots to begin.
// that grid is a 2d array called 'contain'
playGrid::playGrid() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			contain[i][j] = '.';
		}
	}
}

/*
void playGrid::fillGrid(){

}
*/

// Prints most current view of 2d array "contain" that is a grid of dots/x's/o's
// -Implement a chech when grid is printed to see if winner has been achieved-
// -use possible winning combinations and compare everytime printGrid() is called?-
void playGrid::printGrid() {
	for (int outer = 0; outer < 3; outer++) {
		for (int inner = 0; inner < 3; inner++) {
			cout << contain[outer][inner] << " ";
		}
		cout << endl;
	}
	cout << endl;

}


// Sets position for player move, checks if position is avalible/already taken.
// If position already taken, skips player move and moves to next player.
// Last if checks coordinate for out of range ("greater than or equal to 3/size of array")
void playGrid::setPlayerMove(int x, int y) {

	if (contain[x][y] == '.') {
		contain[x][y] = 'x';
	}

	else if (contain[x][y] == 'o') {
		cout << "Invalid move" << endl;
		cout << endl;
		contain[x][y] = 'o';
	}

	else if (contain[x][y] == 'x') {
		cout << "Player already obtained that position." << endl;
		cout << endl;
		contain[x][y] = 'x';
	}

	else if (x >= 3 || y >= 3) {
		cout << "Coordinates out of range." << endl;
		cout << endl;
	}
	
}

// Diddo to above
void playGrid::setOppMove(int x, int y) {
	if (contain[x][y] == '.') {
		contain[x][y] = 'o';
	}

	else if (contain[x][y] == 'x') {
		cout << "Invalid move" << endl;
		cout << endl;
		contain[x][y] = 'x';
	}

	else if (contain[x][y] == 'o') {
		cout << "Player already obtained that position." << endl;
		cout << endl;
		contain[x][y] = 'o';
	}

	else if (x >= 3 || y >= 3) {
		cout << "Coordinates out of range." << endl;
		cout << endl;
	}
}


//////////
// Main //
//////////
int main() {
	/*
	char contain[3][3];

	for(int i = 0; i < 3; i++){
	for(int j = 0; j < 3; j++){
	contain[i][j] = '.';
	}
	}

	for (int outer = 0; outer < 3; outer++){
	for (int inner = 0; inner < 3; inner++){
	cout << contain[outer][inner] << " ";
	}
	cout << endl;
	}
	*/

	int x, y;
	char resp = 'y';
	char toLowerResp;
	// bool gameWon = false;

	// Starting sequence
	cout << "Do you wish to play a game(y/n): ";
	cin >> resp;
	cout << endl;
	toLowerResp = tolower(resp);

	if (toLowerResp == 'y') {

		// new object to build grid and fill players
		playGrid* newPlayGrid = new playGrid();

		// Test code //
		//// newPlayGrid->setOppMove(0, 1); ///
		// newPlayGrid->setPlayerMove(1, 1); //

		newPlayGrid->printGrid();

		//////////////////////
		// -main game loop- //
		//////////////////////
		
		while (newPlayGrid->getWinner() != true) {

			////////////////////////////
			// player 1 move "player" //
			////////////////////////////
			cout << "Player move..." << endl << "enter x: ";
			cin >> x;
			cout << "enter y: ";
			cin >> y;
			cout << endl;

			newPlayGrid->setPlayerMove(x, y);
			newPlayGrid->printGrid();
			newPlayGrid->retWinnerOutPlayer();

			// checking to see if player won after last move
			// frees memory for if new game wants to be played
			if (newPlayGrid->getWinner() == true) {
				break;
				delete newPlayGrid;
			}



			/////////////////////////
			// player 2 move "opp" //
			/////////////////////////
			cout << "Opp move..." << endl << "enter x: ";
			cin >> x;
			cout << "enter y: ";
			cin >> y;
			cout << endl;

			newPlayGrid->setOppMove(x, y);
			newPlayGrid->printGrid();
			newPlayGrid->retWinnerOPP();

			// checking to see if opp won after last move
			// frees memory for if new game wants to be played
			if (newPlayGrid->getWinner() == true) {
				break;
				delete newPlayGrid;
			}
		}	
	}

	else if (toLowerResp == 'n') {
		cout << "Thank you, goodbye." << endl;
	}

	else if (toLowerResp != 'n' || toLowerResp != 'y') {
		cout << "Invalid response." << endl;
	}


	// infinite loop:
	/*while (startGame) {

		


	}*/

	/*
	else if(toLowerResp == 'n'){
	cout << "Thank you." << endl;
	}
	else {
	cout << "Invalid answer." << endl;
	}
	*/

	/*
	playGrid* newPlayGrid = new playGrid();
	// newPlayGrid->fillGrid();
	newPlayGrid->printGrid();

	delete newPlayGrid;
	*/
	return 0;
}