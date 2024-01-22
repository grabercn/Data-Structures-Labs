#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;

class TowerOfHanoiGame
{
public:
	int* a;     //address of elements of array A
	int* b;     //address of elements of array B
	int* c;     //address of elements of array C
	int size;
	int nextIndexA;
	int nextIndexB;
	int nextIndexC;

	static int moves;
	int& getSize()  // function to get the size(number) of discs
	{
		return size;
	}
	int* getArrayA()  // function to get array A
	{
		return a;
	}
	int* getArrayB()   // function to get array B
	{
		return b;
	}
	int* getArrayC()    // function to get array C
	{
		return c;
	}
	int* getIndexA()     //function to get the address of the top element of array  A
	{
		return &nextIndexA;
	}
	int* getIndexB()     //function to get the address of the top element of array  B
	{
		return &nextIndexB;
	}
	int* getIndexC()       //function to get the address of the top element of array  C
	{
		return &nextIndexC;
	}


	int swap(char source, char dest)  // function to move a disc from the source to destination
	{
		int* s;
		int* d;
		int* sourceIndex;
		int* destIndex;
		if (source == 'A')
		{
			sourceIndex = getIndexA();
			s = getArrayA();
		}
		else if (source == 'B')
		{
			sourceIndex = getIndexB();
			s = getArrayB();
		}
		else
		{
			sourceIndex = getIndexC();
			s = getArrayC();
		}
		if (dest == 'A')
		{
			d = getArrayA();
			destIndex = getIndexA();
		}
		else if (dest == 'B')
		{
			d = getArrayB();
			destIndex = getIndexB();
		}
		else
		{
			d = getArrayC();
			destIndex = getIndexC();
		}
		if (*destIndex >= 0 && *destIndex < size && (*sourceIndex - 1) >= 0 && (*sourceIndex - 1) < size)
		{
			if (*sourceIndex == 0)
			{
				return -1;
			}
			else if ((*destIndex - 1 >= 0) && d[*destIndex - 1] <= s[*sourceIndex - 1])
			{
				return 0;
			}
			else
			{
				int temp = d[*destIndex];
				d[*destIndex] = s[*sourceIndex - 1];
				s[*sourceIndex - 1] = temp;
				*sourceIndex = *sourceIndex - 1;
				*destIndex = *destIndex + 1;
				return true;
			}
		}
	}


	void display()     //function to show the status of the stack at specific time
	{
		cout << "\n---------------Towers_Of_Hanoi_Game--------------\n";
		cout << '\n';
		for (int i = size; i >= 0; i--)
		{
			cout << "\t\t";
			for (int j = 0; j < 3; j++)
			{
				if (i == size)
				{
					cout << ".\t";
				}
				else
				{
					if (j == 0)
					{
						if (a[i] == 0)
						{
							cout << ".\t";
						}
						else
						{
							cout << a[i] << '\t';
						}
					}
					else if (j == 1)
					{
						if (b[i] == 0)
						{
							cout << ".\t";
						}
						else
						{
							cout << b[i] << '\t';
						}
					}
					else if (j == 2)
					{
						if (c[i] == 0)
						{
							cout << ".\t";
						}
						else
						{
							cout << c[i] << '\t';
						}
					}
				}
			}
			cout << '\n';
		}
		cout << "\t\t------ ------ ------";
		cout << "\n\t\tA\tB\tC\n";
		cout << "\n------------------------------------------------\n";
	}


	void resetGame()  //function to reset the game ...which allows the user to play the game again
	{
		if (a && b && c)
		{
			delete a;
			delete b;
			delete c;
			a = NULL;
			b = NULL;
			c = NULL;
		}
		a = new int[size];
		b = new int[size];
		c = new int[size];
		nextIndexA = size;
		nextIndexB = 0;
		nextIndexC = 0;
		int count = size;
		for (int i = 0; i < size; i++)
		{
			a[i] = count;
			count = count - 1;
		}
		for (int i = 0; i < size; i++)
		{
			b[i] = 0;
			c[i] = 0;
		}
		TowerOfHanoiGame::moves = 0;
	}
};

TowerOfHanoiGame TH;    //declaring an instance of class TowerOfHanoiGame
int TowerOfHanoiGame::moves = 0; //initializing the instance variable of a class


bool isGameWin()   //function which checks if the user wins
{
	int size = TH.getSize();
	int* c = TH.getArrayC();
	for (int i = 0; i < size; i++)
	{
		if (c[i] == 0)
		{
			return false;
		}
	}
	return true;
}


void stepByStepGuide(int n, char from_rod, char to_rod, char aux_rod)  // function which shows the appropriate solution of tower of hanoi game
{
	if (n == 0)
	{
		return;
	}
	stepByStepGuide(n - 1, from_rod, aux_rod, to_rod);
	cout << "Move disk " << n << " from rod " << from_rod <<
		" to rod " << to_rod << endl;
	stepByStepGuide(n - 1, aux_rod, to_rod, from_rod);
}


void playGame()   //function which specify how the game is played
{
	TH.resetGame();
	bool flag = false;
	char source;
	char dest;
	int invalidCheck;
	while (flag == false)
	{
		system("CLS");
		TH.display();
		cout << "\nMaximum No. Of Moves Required:\t" << (pow(2, TH.size) + 3);
		cout << "\nTotal Moves:\t" << TowerOfHanoiGame::moves;
		cout << '\n';
		cout << "\nEnter Src (A,B,C):\t";
		cin >> source;
		while (source != 'A' && source != 'B' && source != 'C')
		{
			cout << "invalid input";
			cout << "\nEnter Src (A,B,C):\t";
			cin >> source;
		}
		cout << "Enter Dst (A,B,C):\t";
		cin >> dest;
		while (source == dest || (dest != 'A' && dest != 'B' && dest != 'C'))
		{
			cout << "invalid input";
			cout << "\nEnter Dst (A,B,C):\t";
			cin >> dest;
		}
		invalidCheck = TH.swap(source, dest);
		if (invalidCheck != 1)
		{
			if (invalidCheck == 0)
			{
				cout << "\nWarning!, a bigger number can't be place above on small number\n";
				TowerOfHanoiGame::moves++;
			}
			else
			{
				cout << "\nInvalid Move from " << source << " to " << dest << "\n";
				TowerOfHanoiGame::moves++;
			}
			system("pause");
		}
		else
		{
			TowerOfHanoiGame::moves = TowerOfHanoiGame::moves + 1;

		}
		if (TowerOfHanoiGame::moves > (pow(2, TH.size) + 3))
		{
			cout << "------------------Game Over!------------------" << endl;
			cout << "Moving a disk beyond The Maximum No. of Moves is Not Allowed!" << endl << endl;
			system("pause");
			system("CLS");
			int flag2;
			while (TowerOfHanoiGame::moves > (pow(2, TH.size) + 3))
			{
				cout << "\t---------------------------------------------" << endl;
				cout << "\t\tEnter 1 to play the game again." << endl;
				cout << "\t\tEnter 2 to see the solution." << endl;
				cout << "\t\tenter 0 to exit" << endl;
				cout << "\t---------------------------------------------" << endl;
				cin >> flag2;
				if (flag2 == 1)
				{
					playGame();
				}

				else if (flag2 == 2)
				{
					system("CLS");
					stepByStepGuide(TH.size, 'A', 'C', 'B');
					cin.get();
					cout << endl << endl;
					cin.get();
					system("CLS");

				}
				else
				{
					exit(0);
				}

			}
		}
		flag = isGameWin();
	}
	system("CLS");
	TH.display();
	cout << "Total Moves:\t" << TowerOfHanoiGame::moves;
	cout << "\nCongrats! You Solve The Tower of Hanoi Puzzle in " << TowerOfHanoiGame::moves << " moves\n";
	system("pause");
}


int main()
{
	system("color 02");
	int size;
	int option;
	cout << "\t-------------------------------------------------------------------------\n";
	cout << "                            RULES\n";
	cout << "\t-------------------------------------------------------------------------\n\n";
	cout << "\t1. peg #A is the STARTING peg and peg #C is the ENDING peg.\n";
	cout << "\t2. You should move only one disk at a time.\n";
	cout << "\t3. you are not allowed to place a larger diameter disk on top of a smaller one.\n";
	cout << "\t4. you have to make as few moves as possible.\n";
	cout << "\t5. you can use the other peg (in fact any of the 3 pegs) for temporary storage.\n";
	cout << "\t-------------------------------------------------------------------------\n";
	system("pause");
	do
	{
		system("CLS");
		cout << "\t------------------------------------------------";
		cout << "\n\t        Welcome To Tower Of Hanoi Game\n";
		cout << "\t------------------------------------------------\n";
		cout << "\n\t\tEnter 1 to Specify the No. of Disks";
		cout << "\n\t\tEnter 2 to Start Game";
		cout << "\n\t\tEnter 3 to play Random No. of Disk (3-7)";
		cout << "\n\t\tEnter 0 to exit the game" << endl;
		cout << "\t------------------------------------------------";
		cout << "\n\tChoose Option:\t";
		cin >> option;
		if (option == 1)
		{
			cout << "Enter No. Of Disk for Tower Of Hanoi Game: ";
			cin >> size;
			while (size <= 0)
			{
				cout << "Invalid Input Size Must Be Greater Than Zero\n";
				cout << "Enter No. Of Disk for Tower Of Hanoi Game: ";
				cin >> size;
			}
			TH.getSize() = size;
		}
		else if (option == 2)
		{
			cout << "\nGame is Starting Now";
			cout << "\nNo of Disks Are:\t" << size;
			cout << "\nyou are expected to finish the game in " << pow(2, size) + 3 << " No. of moves" << endl << endl;
			system("pause");
			playGame();
		}
		else if (option == 3)
		{
			cout << "\nYour are playing Random Tower Of Hanoi Game";
			size = 3 + rand() % (7 - 3 + 1);
			TH.getSize() = size;
			cout << "\nGame is Starting Now";
			cout << "\nNo of Disks Are:\t" << size << '\n';
			system("pause");
			playGame();
		}
		else if (option == 0)
		{
			cout << "\nTowers of Hanoi Game is Exit Now";
		}
		else
		{
			cout << "\nInvalid Option From User";
		}
	} while (option != 0);

	return 0;
}