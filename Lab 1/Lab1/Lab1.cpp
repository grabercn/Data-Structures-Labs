#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

#define MAX_PLAYERS 10

using namespace std;

/*
	Class representing an N-sided die
*/
class Dice {
private:
	int numSides = numSides;
	const int ns{numSides};

	void randSeed() {
		//srand((unsigned)time(0));
		
	}

public:
	Dice(const int numSide) {
		numSides = numSide;
		//randSeed();
	}

	void setNumSides(const int ns) {
		numSides = ns;
	}

	// Perform a single roll of the die	
	int roll() {
		// num sides is being altered unorgnically
		numSides = ns;
		auto a = (rand()%numSides)+1;
		//std::cout<<a;
		return a;
	}
};

/*
	Class representing a Game Player
*/
class Player {
private:
	std::string name;
	int score;
public:

	//Default Player constructor
	Player() {
		name = "empty";
		score = 0;
	}

	//Player constructor with parameters
	Player(std::string n, int s) {
		name = n;
		score = s;
	}

	// Getter : Player Name
	std::string getName() {
		return name;
	}
	// Getter : Score
	int getScore() {
		return score;
	}
	// Increases the player's score by a specified value
	void addToScore(int val) {
		score = score + val;
	}
};

/*
	Abstract class DiceGame
*/
class DiceGame {

protected:
	Player *players[MAX_PLAYERS];
	Dice *dice;
	int numPlayers;
	int numDice;

public:
	//	Pure virtual function	
	virtual void play() = 0;

	//Initiate player score / names and add to array
	void initPlayers(string name = "Empty", int score = 0) {

		for (int i = 0; i < numPlayers; i++) {
			cout << "Player Name: ";
			cin >> name;
			if (name == "" or name == " ") { // correct name bounds
				name = "Empty";
				printf("- Name Corrected - \n");
			}

			cout << "Player Score: ";
			cin >> score;
			if(score < 0){ // correct score bounds
				score = 0;
				printf("- Score Corrected - \n");
			}

			players[i] = new Player(name, score);

		}

	}

	//Display player score / names from array
	void displayScores() {
		std::string total;
		for (int i = 0; i < numPlayers; i++) { // Repeat for all number of players
			std::string pln = players[i]->getName();  //figure out indexing retreival
			int pls = players[i]->getScore();
			cout << (i+1) << ". Name: " << pln << " Score: " << pls << std::endl; // display the values in format
		}
	}

	// Save player names and scores to text file
	void writeScoresToFile(std::string openFile) {
		ofstream myFile(openFile + ".txt");
		if (myFile.is_open()) { // case if file open
			for (int i = 0; i < numPlayers; i++) {
				myFile << players[i]->getName() << ":" << players[i]->getScore() << std::endl; //save in correct format
			}
			myFile.close(); // close file correctly
		}
		else {
			printf("File could not be opened! \n"); // display if file is not open or found
		}
	}

	// Find highest score from text file
	void getHighestScore(std::string openFile) {
		
		//Decl vars
		std::string 
			tLine,
			mName;
		int
			score{ 0 },
			mScore{ 0 },
			i{ 0 },
			loopVal{ -1 };
		
		ifstream myFile(openFile + ".txt"); // open filename.txt from string input into myFile
		if (myFile.is_open()) { // case if file open
		
			while (getline(myFile, tLine) && tLine != " ") { // get all lines in file
				
				// Reset Score
				score = 0;

				//std::cout << tLine << std::endl;

				// For loop grabs appropriate text from line stopping at char
				for (int num = 0; tLine[num] != '\0'; num++) { 
					if (tLine[num] == ':') { // stop getting at char
						loopVal = num;
					}
				}
				
				// Assign values to score and name, dissecting each text line and checking ahead
				auto pName = tLine.substr(0, loopVal); // grab name and assign to string
				score = atoi(tLine.substr(loopVal + 1, loopVal + 2).c_str()); // grab score and convert from str to int
				
				if (score > mScore) {
					mScore = score;
					mName = pName;
				}
			} // end while loop

			myFile.close(); // close file

			//Print and save values
			std::cout << "Name: " << mName << " Score: " << mScore << std::endl; // print out list of players read from file

		}
		else {
			printf("File unable to be read / opened. \n");
		}
	}
};

//Create knockout function / game
class Knockout : public DiceGame {
private:
	int KnockoutSum;
public:

	Knockout(Dice d, int np, int nd, int ns) { // default constructor
		dice = &d;
		numPlayers = np;
		numDice = nd;
		KnockoutSum = dice->roll() * numDice;
		dice->setNumSides(ns);
	}

	void play() { // virtual game function // where game starts //
		
		printf("- Game Started - \n");

		int cScore;
		std::vector<int> cPlayers(numPlayers); // create vector of size max players

		int i = 0;
		for (int i = 0; i < numPlayers; i++){
			cPlayers[i] = i; // fill current players  
		}

		int rPlayers = numPlayers; // remaining players is number of players 
		
		while (rPlayers > 1) {

			// Compute player score while dice rolling
			for(int i=0; i <numPlayers; i++){
				cScore = 0; 
				for (int n = 0; n < numDice; n++) {
					cScore += dice->roll(); // tally current score
				}

				//Track who is winning currently
				if (cScore == KnockoutSum) { // compare current score to knockout
					rPlayers = rPlayers - 1;
					cPlayers[i] = -1; // set player to out / -1
				}

			}
		}
		// Determine winner and give reward
		for (int i = 0; i < numPlayers; i++) {
			if (cPlayers[i] > -1) {
				players[i]->addToScore(10); // add to winning players score
				break; // exit
			}
		}

	}
};

class Boston : public DiceGame {
public:
	Boston(Dice d, int np, int nd, int ns) {
		dice = &d;
		numPlayers = np;
		numDice = nd;
		int numSides = ns;
	}

	void play() {
		
		//decl vars
		int 
			cScore{ 0 }, 
			cRoll{ 0 }, 
			mRoll{ 0 }, 
			mScore{0}, 
			winner{-1};

		printf("- Game Started - \n");

		//Compute player scores during dice roll
		for (int i = 0; i < numPlayers; i++) {
			
			cScore = 0; // reset current score
			mRoll = 0; // reset max roll of dice

			for (int n = 0; n < numDice; n++) {
				
				cScore = 0;
				mRoll = 0;
				
				//Roll each dice and take the largest one
				for (int j = numDice - n; j > 0; j--) {
					cRoll = dice->roll();
					if (cRoll > mRoll) {
						mRoll = cRoll;
					}
				}
				cScore += mRoll;
			}
			// Determine who has winning score
			if (cScore > mScore) {
				mScore = cScore;
				winner = i;
			}
		}
		// Give points to player who has highest score
		players[winner]->addToScore(10);

	}

};


int main() {
	// Base class pointer
	DiceGame *game;

	// -- setup dice games -- 

	//dec var
	int numPlayers{ 0 };
	int numDice;
	int score;
	int choice;
	
	
	int a;
	std::string name;

	//Which Game
	cout << "Play what? (1. Knockout, 2. Boston): ";
	
	cin >> choice;

	//Number of Players
	cout << "Number of Players: ";
	cin >> numPlayers;

	//Make sure num players is greater than 0
	if (numPlayers < 2) {
		numPlayers = 2;
		printf("- Bound Corrected - \n");
	}


	//Number of Sides
	cout << "Number of dice sides? (3,4,6): ";
	auto tempNum{ 0 };
	cin >> tempNum;
	
	//Make sure num of sides is greater than 2
	if (tempNum < 2){
		tempNum = 3;
		printf("- Bound Corrected - \n");
	}

	const int numSides{tempNum}; // assign numsides as const int
	
	//Number of Dice
	cout << "Number of Dice: ";
	cin >> numDice;

	//Make sure num dice is greater than 0
	if (numDice < 1) {
		numDice = 1;
		printf("- Bound Corrected - \n");
	}

	//Create dice initial
	Dice dice(numSides);

	//Determine game from choice
	if (choice == 1) {
		Knockout obj( dice,  numPlayers,  numDice, numSides); // create game object
		game = &obj; // set game as game obj
	}
	else if (choice == 2) {
		Boston obj(dice, numPlayers, numDice, numSides); // create game object
		game = &obj; // set game as game obj
	}
	else { // if game choice is > 2 or < 0
		cout << "Not a option!";
		return 0;
	}

	//Call high level functions
	game->initPlayers(); // create players
	game->play(); // run actual game's function
	printf("- Player Scores - \n");
	game->displayScores(); // Display scores in std format
	game->writeScoresToFile("scorecard"); // write scores from game to file
	printf("- Highest Scoring Player - \n");
	game->getHighestScore("scorecard"); // take highest score from scorecard and display

	return 0;
}

// **  -DEBUG-  **
// No known issues



