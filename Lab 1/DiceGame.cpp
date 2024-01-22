#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include <stdlib.h>

#define MAX_PLAYERS 10

using namespace std;

/*
	Class representing an N-sided die
*/
class Dice{
	private:
		int numSides;

	public:
		// Perform a single roll of the die	
		int roll() {
		}
};

/*
	Class representing a Game Player
*/
class Player{
	private:
		string name;
		int score;
	public:
		// Getter : Player Name
		string getName() {
		}
		// Getter : Score
		int getScore() {
		}
		// Increases the player's score by a specified value
		void addToScore(int val){	
		}
};

/*
	Abstract class DiceGame
*/
class DiceGame{
		
	protected:
		Player *players[MAX_PLAYERS];
		Dice *dice;
		int numPlayers, numDice;
		
	public:
		//	Pure virtual function	
		virtual void play() = 0;
		
};

int main() {
	// Base class pointer
	DiceGame *game;

}
