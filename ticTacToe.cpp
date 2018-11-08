#include "stdafx.h"
#include <iostream>

using namespace std;

// Finished running game on 11/7
// New code started on 11/5

// Main class for implementation of game
// used contructor for filling 2d array as grid
// print function and setters for player movements
// booleans to check for winner and check sum for testing for a tie
class playGrid {

public:
	playGrid();

	// destructor for class
	~playGrid() {
		cout << "--Game memory cleared--" << endl;
	}

	// void fillGrid();
	void printGrid();

	// sets coordinates for each player
	void setOppMove(int, int);
	void setPlayerMove(int, int);

	bool getWinner(); // returns winnerOut for game loop and exiting
	void retWinnerOPP(); // checks for playOPP returning true
	void retWinnerOutPlayer(); // checks for playOne returning true

	void getTie(); // uses checkSum and winnerOut to check for tie

private:
	// counter for how many spaces are left. 
	// If zero and getWinner() has not returned true - game is a tie
	int checkSum = 9;

	char grid[3][3];

	// checks for if player or opp winning
	bool winnerOut = false;
	bool playOne = false;
	bool playOPP = false;
};


// boolean to maintain while loop in 'main'
bool playGrid::getWinner() {
	return winnerOut;
}


// check for if a tie has occured
void playGrid::getTie() {
	// test snippet for counting number of spaces left... 
	// cout << checkSum << endl;

	if (checkSum == 0 && winnerOut != true) {
		cout << "The game is a tie." << endl;
		winnerOut = true;
	}
}

////////////////
// play check //
////////////////
// checks the eight different combinations player could win
// sets boolean for playOne to true and the condition for exiting loop to true
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
			grid[i][j] = '.';
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
			cout << grid[outer][inner] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


// Sets position for player move, checks if position is avalible/already taken.
// If position already taken, skips player move and moves to next player.
// Last if checks coordinate for out of range ("greater than or equal to 3/size of array")
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

// Diddo to above
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

	int x, y; // coordinates for player moves
	char resp = 'n';
	char toLowerResp;

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

			newPlayGrid->setPlayerMove(x-1, y-1);
			newPlayGrid->printGrid();
			newPlayGrid->retWinnerOutPlayer();

			newPlayGrid->getTie(); // check for tie

			// checking to see if player won after last move
			// frees memory for if new game wants to be played
			if (newPlayGrid->getWinner() == true) {
				delete newPlayGrid;
				break;
			}

			/////////////////////////
			// player 2 move "opp" //
			/////////////////////////
			cout << "Opponent move..." << endl << "enter x: ";
			cin >> x;
			cout << "enter y: ";
			cin >> y;
			cout << endl;

			newPlayGrid->setOppMove(x-1, y-1);
			newPlayGrid->printGrid();
			newPlayGrid->retWinnerOPP();

			newPlayGrid->getTie(); //check for tie

			// checking to see if opp won after last move
			// frees memory for if new game wants to be played
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
