#include <iostream>
using namespace std;

class Tower {
public:

	//Define Game Vars
	int* array1; // peg A
	int* array2; // peg B
	int* array3; // peg C
	
	int height; // tower height / size
	int next1; // top val of array 1 
	int next2; // top val of array 2
	int next3; // top val of array 3
	
	static int calls;
	
	// returns the current size of the tower
	int& Size() {
		return height;
	}
	
	// returns Array A / 1
	int* ArrayA() {
		return array1;
	}
	
	// returns Array B / 2
	int* ArrayB() {
		return array2;
	}
	
	// returns Array C / 3
	int* ArrayC() {
		return array3;
	}
	
	// returns the address of the top object of array A / 1
	int* NextA() {
		return &next1;
	}
	
	// returns the address of the top object of array B / 2
	int* NextB() {
		return &next2;
	}
	
	// returns the address of the top object of array C / 3
	int* NextC() {
		return &next3;
	}


	int move(char srcIn, char destIn)  // function to move a disc from the source to destination
	{
		int* src; // src
		int* dest; // dest
		int* srcPos;
		int* destPos;

		if (srcIn == 'a') // if disk a is selected
		{
			srcPos = NextA();
			src = ArrayA();
		}
		else if (srcIn == 'b') // if disk b is selected
		{
			srcPos = NextB();
			src = ArrayB();
		}
		else // if disk c is selected
		{
			srcPos = NextC();
			src = ArrayC();
		}

		if (destIn == 'a') // if disk a is dest
		{
			dest = ArrayA();
			destPos = NextA();
		}
		else if (destIn == 'b') // if disk b is dest
		{
			dest = ArrayB();
			destPos = NextB();
		}
		else // if disk c is dest
		{
			dest = ArrayC();
			destPos = NextC();
		}

		// Set position and check for validity
		if (*destPos >= 0 && *destPos < height && (*srcPos - 1) >= 0 && (*srcPos - 1) < height)
		{
			if (*srcPos == 0)
			{
				return -1;
			}
			else if ((*destPos - 1 >= 0) && dest[*destPos - 1] <= src[*srcPos - 1])
			{
				return 0;
			}
			else
			{
				int holder = dest[*destPos]; // set temp
				
				dest[*destPos] = src[*srcPos - 1]; // shift dest 
				src[*srcPos - 1] = holder; // set src to temp shifted by 1
				
				*srcPos = *srcPos - 1; // decrement srcPos
				*destPos = *destPos + 1; // increment destPos
				
				return true;
			}
		}
	}

	void PrintTowers() { // Display towers while in the game
		//Display Tower 1
		cout << "   |\n A |";
		for	(int i = 0; i < height; i++)
		{
			
			if (array1[i]==0)
				cout<<"-+-";
			else
				cout << "["<<array1[i]<<"]";
		}
		cout << "\n   |\n";

		//Display Tower 2
		cout << "   |\n B |";
		for (int i = 0; i < height; i++)
		{
			if (array2[i] == 0)
				cout << "-+-";
			else
				cout << "[" << array2[i] << "]";
		}
		cout << "\n   |\n";

		//Display Tower 3
		cout << "   |\n C |";
		for (int i = 0; i < height; i++)
		{
			if (array3[i] == 0)
				cout << "-+-";
			else
				cout << "[" << array3[i] << "]";
		}
		cout << "\n   |\n";
	}

	// Reset the tower at start of game
	void ResetTower() {
		if (array1 && array2 && array3) { // if arrays exist
			delete array1, array2, array3; // delete their mem
			array1 = array2 = array3 = NULL; // set them all to null
		}
		
		// Create new arrays
		array1 = new int[height]; 
		array2 = new int[height];
		array3 = new int[height];

		next1 = height;
		next2 = next3 = 0;

		int iterate = height;

		// Fill arrays with values from height to 1
		for (int n = 0; n < height; n++) {
			array1[n] = iterate;
			iterate = iterate - 1;
		} 
		for (int i = 0; i < height; i++) {
			array2[i] = 0;
			array3[i] = 0;
		}
		Tower::calls = 0; // reset call counter
	}
};

// DEFINE GLOBALS HERE!!
Tower tower; // create tower object
int Tower::calls = 0; // member number of calls used in game
int won = 0; // global win counter var (used after game win)
int it = 0; // global iteration var (used in step by step)
//END GLOBALS

bool GameOver() // determines if user has won the game
{
	int* c = tower.ArrayC();
	int size = tower.Size();
	
	for (int i = 0; i < size; i++)
		if (c[i] == 0)
			return false;
	
	return true;

}

// Shows best possible solution to tower of hanoi game using recursion
void stepByStepGuide(int iterate, char fRod, char tRod, char aRod)
{

	if (iterate == 0)
	{
		return;
	}
	
	stepByStepGuide(iterate - 1, fRod, aRod, tRod);
	it += 1;
	cout << it << ". Take Disk " << iterate << " off of rod " << fRod <<
		" and put on rod " << tRod << endl;
	
	stepByStepGuide(iterate - 1, aRod, tRod, fRod);
}


void Play() // main game starts here
{
	tower.ResetTower(); // reset tower and vars on game start
	
	// Set game vars
	bool winGame = false;
	char prompted;
	char promped2;
	int valid;
	int breakFlag{ 0 };
	
	while (winGame == false) // while game is not over
	{
		system("CLS");
		
		tower.PrintTowers();
		
		cout << "\nType 'q' at any time to quit.\n";
		cout << "\nMoves Left: " << (pow(2, tower.height) + 3) - Tower::calls;
		cout << '\n';
		cout << "\nTarget? (a,b,c): "; // initial prompt
		
		cin >> prompted; // take input
		
		if (prompted == 'W') { // cheat code to win the game
			break; 
		}
		
		else if (prompted == 'q') {
			cout << "Exiting the Program...\n"; // quit the game
			exit(0);
		}
		
		while (prompted != 'a' && prompted != 'b' && prompted != 'c')
		{
			cout << "Invalid Option!";
			cout << "\nTarget? (a,b,c): ";
			
			cin >> prompted;

			if (prompted == 'q') {
				cout << "Exiting the Program...\n"; // quit the game
				exit(0);
			}
			
		}
		
		cout << "Destination? (a,b,c): ";
		cin >> promped2;

		if (prompted == 'q') {
			cout << "Exiting the Program...\n"; // quit the game
			exit(0);
		}
		
		while (prompted == promped2 || (promped2 != 'a' && promped2 != 'b' && promped2 != 'c'))
		{
			cout << "Invalid Option!";
			cout << "\nDestination? (a,b,c): ";
			
			cin >> promped2;

			if (prompted == 'q') {
				cout << "Exiting the Program...\n"; // quit the game
				exit(0);
			}
		}
		
		valid = tower.move(prompted, promped2);
		
		if (valid != 1)
		{
			if (valid == 0)
			{
				cout << "\nInvalid Order! You cannot place a bigger disk on a smaller disk.\n";
				Tower::calls++;
			}
			else
			{
				cout << "\nDisk Could not Be Moved from " << prompted << " to " << promped2 << "\n";
				Tower::calls++;
			}
			system("pause");
		}
		else
			Tower::calls = Tower::calls + 1;

		if (Tower::calls > (pow(2, tower.height) + 3))
		{
			cout << R"(

 ____                                     _____                                      
/\  _`\                                  /\  __`\                                    
\ \ \L\_\     __      ___ ___      __    \ \ \/\ \  __  __     __   _ __             
 \ \ \L_L   /'__`\  /' __` __`\  /'__`\   \ \ \ \ \/\ \/\ \  /'__`\/\`'__\           
  \ \ \/, \/\ \L\.\_/\ \/\ \/\ \/\  __/    \ \ \_\ \ \ \_/ |/\  __/\ \ \/ __  __  __ 
   \ \____/\ \__/.\_\ \_\ \_\ \_\ \____\    \ \_____\ \___/ \ \____\\ \_\/\_\/\_\/\_\
    \/___/  \/__/\/_/\/_/\/_/\/_/\/____/     \/_____/\/__/   \/____/ \/_/\/_/\/_/\/_/
                                                                                     
                                                                                     

			)" << endl;
			
			cout << "You Have Run out Of Moves! Try Again..." << endl << endl;
			
			system("pause");
			system("CLS");
			
			breakFlag = 1;
			
			break;
			
		}
		
		winGame = GameOver();
	
	}

	if (breakFlag != 1) {
		system("CLS");
		tower.PrintTowers();
		cout << "You Finished the Hanoi Tower in " << Tower::calls << " moves!";
		cout << R"(

                                   .''.       
       .''.      .        *''*    :_\/_:     . 
      :_\/_:   _\(/_  .:.*_\/_*   : /\ :  .'.:.'.
  .''.: /\ :   ./)\   ':'* /\ * :  '..'.  -=:o:=-
 :_\/_:'.:::.    ' *''*    * '.\'/.' _\(/_'.':'.'
 : /\ : :::::     *_\/_*     -= o =-  /)\    '  *
  '..'  ':::'     * /\ *     .'/.\'.   '
      *            *..*         :
        *
        *
 __                 ,    .    ,           
/  ` _ ._  _ ._. _.-+-. .| _.-+-* _ ._  __
\__.(_)[ )(_][  (_] | (_||(_] | |(_)[ )_) 
          ._|                             
)";

		system("pause");
		system("CLS");


		// Display the best method to solve possible
		cout << "Best Solve Method: \n\n";
		
		stepByStepGuide(tower.height, 'a', 'c', 'b'); // 
		
		cin.get();
		cout << endl << endl;

		cout << "^ Best Solve Method \n\n";
		
		system("pause");
		system("CLS");
		// End solve method

		// Return back to menu, redisplay prompt and win amount
		cout << "Returned to main menu...\n\n";

		won += 1;

		if (won > 1) {
			cout << "\tYou've Won " << won << " games so far!\n";
		}
		else {
			cout << "\tYou've won " << won << " game so far!\n";
		}
	}
	else {
		cout << "Returned to main menu...\n";
	}
	
	cout << R"(

    _,-'"`-._,-'"`-._,-'"`-._,-'"`-._,-'"`-._,-'"`-._,-'"`-._,-'"`-._,-'"`-._,-'"`-._,
	  ________                                _________         __                     
	 /  _____/ _____     _____    ____       /   _____/  ____ _/  |_  __ __ ______  /\ 
	/   \  ___ \__  \   /     \ _/ __ \      \_____  \ _/ __ \\   __\|  |  \\____ \ \/ 
	\    \_\  \ / __ \_|  Y Y  \\  ___/      /        \\  ___/ |  |  |  |  /|  |_> >/\ 
	 \______  /(____  /|__|_|  / \___  >    /_______  / \___  >|__|  |____/ |   __/ \/ 
			\/      \/       \/      \/             \/      \/      |__|      
	                                             
	d - Specify # of Disks.
	r - Random # of Disks.
	
	s - Start the Game!
	
	q - Exit the Program.
)";
	
}

int main()
{
	// GAME INTRO SPLASH SCREEN
	cout << R"(
															                       
	  *   )                                  (      ( /(                       
	` )  /(     (  (      (   (              )\ )   )\())    )             (   
	 ( )(_))(   )\))(    ))\  )(   (     (  (()/(  ((_)\  ( /(   (      (  )\  
	(_(_()) )\ ((_)()\  /((_)(()\  )\    )\  /(_))  _((_) )(_))  )\ )   )\((_) 
	|_   _|((_)_(()((_)(_))   ((_)((_)  ((_)(_) _| | || |((_)_  _(_/(  ((_)(_) 
	  | | / _ \\ V  V // -_) | '_|(_-< / _ \ |  _| | __ |/ _` || ' \))/ _ \| | 
	  |_| \___/ \_/\_/ \___| |_|  /__/ \___/ |_|   |_||_|\__,_||_||_| \___/|_|                                                                                                                                                                
	)";

	int height{ 0 };
	char input{ 0 };

	cout << R"(Rules:
	
	1. Tower 1 is where disks start.
	2. Move Disks one at a Time.
	3. Use Tower 2 as a placeholder.
	4. Get All Disks on Tower 3 to win.
	
	Have Fun! 

)";
	cout << "\t";
	system("pause");
	system("CLS");
	// END SPLASH

	// GAME SETUP PROMPT
	
	cout << R"(

    _,-'"`-._,-'"`-._,-'"`-._,-'"`-._,-'"`-._,-'"`-._,-'"`-._,-'"`-._,-'"`-._,-'"`-._,
	  ________                                _________         __                     
	 /  _____/ _____     _____    ____       /   _____/  ____ _/  |_  __ __ ______  /\ 
	/   \  ___ \__  \   /     \ _/ __ \      \_____  \ _/ __ \\   __\|  |  \\____ \ \/ 
	\    \_\  \ / __ \_|  Y Y  \\  ___/      /        \\  ___/ |  |  |  |  /|  |_> >/\ 
	 \______  /(____  /|__|_|  / \___  >    /_______  / \___  >|__|  |____/ |   __/ \/ 
			\/      \/       \/      \/             \/      \/      |__|      
	                                             
	d - Specify # of Disks.
	r - Random # of Disks.
	
	s - Start the Game!
	
	q - Exit the Program.
)";

	do {
		cout << "\nEnter an Option: ";
		cin >> input;

		if (input == 'd') { // set desired number of discs
			cout << "Enter # of Desired Disks: ";
			cin >> height;
			if (height < 1) {
				height = 2;
			}
			printf("Disk Amount Set to %d", height);
			tower.Size() = height; // set tower height from input
		}
		else if (input == 'r') {
			
			srand((unsigned)time(NULL));

			height = 2 + rand() % 5; // get random number of discs
			tower.Size() = height; // set tower height / discs
			
			Play(); // launch the game
		}
		else if (input == 's') {
			if (height < 1) {
				height = 2;
				tower.Size() = height; // set tower height from input
			}
			printf("Starting Game with %d Disks...\n",height);
			system("pause");
			Play();
		}
		else if (input != 'q') {
			cout << "Input \'" << input << "\' is not valid option.";
		}

	} while (input != 'q');
	cout << ("Exiting the programming...\n\n"); // quit the program 

}

