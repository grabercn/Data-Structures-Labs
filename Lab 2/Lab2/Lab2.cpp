// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#define MAX_ITEMS 30

// Base class to manipulate, print, and store data as an ordered list
template <class A>
class orderedList // class decl
{
protected:
	A* pointerArray[MAX_ITEMS]; // decl array of pointers with size max items

public:
	int c_add{ 0 };
	int m_add{ 0 };
	int c_remove{ 0 };
	int m_remove{ 0 };

	// overloaded operators
	friend bool operator== (const orderedList& listA, const orderedList& listB);
	friend bool operator> (const orderedList& listA, const orderedList& listB);
	friend bool operator< (const orderedList& listA, const orderedList& listB);

	orderedList() { // default constructor

		for (int i = 0; i < MAX_ITEMS; ++i) {
			pointerArray[i] = NULL;
			//std::cout << pointerArray[i];
		}
		
		// Now P[0], P[1], P[2] can point to int memory blocks.

	} // end of constructor 

	// reset counters
	void resetStats() {
		c_add = 0;
		m_add = 0;
		c_remove = 0;
		m_remove = 0;
	}

	void AddItem(A object) { // add item method
		//if (isFull()) {
			//throw std::invalid_argument("Full, cannot add value \n");
		//}

		A sub = object;
		A sub2;

		for (int i = 0; i < MAX_ITEMS; i++) {
			if (pointerArray[i] == NULL) {
				//std::cout << "NULL";
				pointerArray[i] = new A;
				*pointerArray[i] = sub;
				//std::cout << *pointerArray[i];
				break;
			}
			
			else if (*pointerArray[i] > object) {
				c_add = c_add + 1;
				sub2 = *pointerArray[i];
				*pointerArray[i] = sub;
				sub2 = sub;
				m_add = m_add + 1;
			}
			else {
				continue;
			}
		}
	}

	void RemoveItem() { // remove item method
		int i = 0;

		// attempt rand func to find rand item to remove
		int n = rand() % MAX_ITEMS;
		
		// set index of array to rand nums
		while (pointerArray[n] == NULL) {
			n = rand() % MAX_ITEMS;
		}
		
		// add to i while moving thru array
		while ((i < MAX_ITEMS) && (n > i) && (pointerArray[i] != NULL)) {
			++i;
		}

		// counter if i is index
		if (i == n) {
			++c_remove;
			
			// track pos in pointer array after obj move
			while ((pointerArray[i + 1] != NULL) && (i + 1 < MAX_ITEMS)) {
				*pointerArray[i] = *pointerArray[i + 1];
				++m_remove; 
				++i;
			}
		
			// delete array item and set to null
			delete pointerArray[i];
			
			pointerArray[i] = NULL; // set to NULL
		}
	}

	// is the array empty?
	bool isEmpty() {
		int count{ 0 };
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (pointerArray[i] == NULL) {
				++count;
			}
		}
		if (count == MAX_ITEMS) {
			return true;
		}
		else {
			return false;
		}
	}

	// make the array empty
	void MakeEmpty() {
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (pointerArray[i] != NULL) {
				delete pointerArray[i];
				pointerArray[i] = NULL;
			}
		}
	}
	
	// is the array full?
	bool isFull() {
		int count{ 0 };
		
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (pointerArray[i] != NULL) {
				count = count + 1;
			}
		}
		if (count == std::size(pointerArray)) {
			return true;
		}
		else {
			return false;
		}
	}
	
	// display array values in order
	void DispArray() {
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (pointerArray[i] != NULL) {
				std::cout << *pointerArray[i];
			}
			else {
				std::cout << "_";
			}
		}
	}

	// display compares and moves
	void dispAddItem() {
		std::cout << "1st Method: Add Item: " << c_add << " compares and " << m_add << " moves" << std::endl;
	}

	// display removes and compares
	void dispRemoveItem() {
		std::cout << "1st Method: Remove Item: " << c_remove << " compares and " << m_remove << " moves" << std::endl;
	}
	
}; // end task 1

// Inherited class to investigate differences in speed when adding item from end
template <class B>
class EndTheory : public orderedList<class A> {
protected:
	B* pointerArray[MAX_ITEMS]; // decl array of pointers with size max items

public:
	int c_add{ 0 };
	int m_add{ 0 };
	int c_remove{ 0 };
	int m_remove{ 0 };


	EndTheory() { // default constructor
		// Blank array
		for (int i = 0; i < MAX_ITEMS; ++i) {
			pointerArray[i] = NULL;
		}
	}
	
	// reset counter variables
	void resetStats() {
		c_add = 0;
		m_add = 0;
		c_remove = 0;
		m_remove = 0;
	}
	
	// Add item to end array
	void AddItem(B object) {
		B sub = object;
		B sub2;
		
		for (int i = MAX_ITEMS-1; i >= 0; --i) {
			if (pointerArray[i] == NULL) {
				pointerArray[i] = new B;
				*pointerArray[i] = sub;
				break;
			}
			else if (*pointerArray[i] > object) {
				++c_add;
				sub2 = *pointerArray[i];
				*pointerArray[i] = sub;
				sub2 = sub;
				++m_add;
			}
			else {
				continue;
			}
		}
	}


	void RemoveItem() { // remove item method
		int i = 0;

		// attempt rand func to find rand item to remove
		int n = rand() % MAX_ITEMS;

		// set index of array to rand nums
		while (pointerArray[n] == NULL) {
			n = rand() % MAX_ITEMS;
		}

		// add to i while moving thru array
		while ((i < MAX_ITEMS) && (n > i) && (pointerArray[i] != NULL)) {
			++i;
		}

		// counter if i is index
		if (i == n) {
			++c_remove;

			// track pos in pointer array after obj move
			while ((pointerArray[i + 1] != NULL) && (i + 1 < MAX_ITEMS)) {
				*pointerArray[i] = *pointerArray[i + 1];
				++m_remove;
				++i;
			}

			// delete array item and set to null
			delete pointerArray[i];

			pointerArray[i] = NULL; // set to NULL
		}
	}
	
	// Display array values
	void DispArray() {
		for (int i = MAX_ITEMS; i > 0; i--) {
			if (pointerArray[i] != NULL) {
				std::cout << *pointerArray[i];
			}
			else {
				std::cout << "_";
			}
		}
	}
	
	// display item adds and moves
	void dispAddItem() {
		std::cout << "2nd Method: Add Item: " << c_add << " compares and " << m_add << " moves" << std::endl;
	}

	// display item removes and compares
	void dispRemoveItem() {
		std::cout << "2nd Method: Remove Item: " << c_remove << " compares and " << m_remove << " moves" << std::endl;
	}
	
	
}; // end task 2

// 2nd Inherited class to investigate number of moves when leaving blank spots in array
template<class C>
class BlankTheory : public orderedList<class A> {
protected:
	C* pointerArray[MAX_ITEMS]; // decl array of pointers with size max items

public: // public methods
	int c_add{ 0 };
	int m_add{ 0 };
	int c_remove{ 0 };
	int m_remove{ 0 };


	BlankTheory() { // default constructor
		for (int i = 0; i < MAX_ITEMS; ++i) {
			pointerArray[i] = NULL; // fill pointer with null
		}
	}

	// Reset counter stats
	void resetStats() {
		c_add = 0;
		m_add = 0;
		c_remove = 0;
		m_remove = 0;
	}

	// Add item method
	void AddItem(C object) {
		
		if (isEmpty() == true) {
			pointerArray[0] = new C;
		}

		if (pointerArray[0] != NULL) {
			++c_add;
			if (*pointerArray[0] > object) {
				
				for (int i = 0; i < MAX_ITEMS; ++i) {
					if (pointerArray[i] == NULL) {
						
						for (int n = i; n > 0; --n) {
							++m_add;
							pointerArray[n] = pointerArray[n - 1];
						}
						break;
					}
				}
				pointerArray[0] = new C;
				return;
			}
		}

		
		for (int i = 0; i < MAX_ITEMS; ++i) {
			if (pointerArray[i] != NULL) {
				++c_add;
				
				if (*pointerArray[i] > object) {
					if (pointerArray[i - 1] == NULL) {
						pointerArray[i - 1] = new C;
						*pointerArray[i - 1] = object;
						return;
					}
					int lEmpty{ 0 };
					for (int n = 0; n < MAX_ITEMS; ++n) {
						if (pointerArray[n] == NULL) {
							lEmpty = n;
						}
					}
					if (lEmpty > i) {
						for (int n = lEmpty; n > i; --n) {
							++m_add;
							pointerArray[n] = pointerArray[n - 1];
						}
						pointerArray[i - 1] = new C;
						*pointerArray[i - 1] = object;
					}
					else if (lEmpty < i) {
						for (int n = lEmpty; n <= i - 1; ++n) {
							++m_add;
							pointerArray[n] = pointerArray[n + 1];
						}
						pointerArray[i - 1] = new C;
						*pointerArray[i - 1] = object;
					}
					return;
				}
			}
		}
		
		if (pointerArray[MAX_ITEMS - 1] == NULL) {
			
			pointerArray[MAX_ITEMS - 1] = new C;
			*pointerArray[MAX_ITEMS - 1] = object;
			
			return;
		}

		int eItem{0};
		for (int i = 0; i < MAX_ITEMS; ++i) {
			if (pointerArray[i] == NULL) {
				eItem = i;
			}

			for (int n = eItem; n < MAX_ITEMS - 1; ++n) {
				++m_add;
				pointerArray[n] = pointerArray[n + 1];
			}
			pointerArray[MAX_ITEMS - 1] = new C;
			*pointerArray[MAX_ITEMS - 1] = object;
			return;
		}
	}

	// Remove item method
	void RemoveItem() {

		int count = rand() % MAX_ITEMS;
		while (pointerArray[count] == NULL) {
			count = rand() % MAX_ITEMS;
		}

		for (int i = 0; i < MAX_ITEMS; ++i) {
			if (i == count) {
				++c_remove;
				if (pointerArray[count] != NULL) {
					delete pointerArray[count];
				}
				pointerArray[count] = NULL;
			}
		}
	}
	
	// Disp array values
	void DispArray() {
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (pointerArray[i] != NULL) {
				std::cout << *pointerArray[i];
			}
			else {
				std::cout << "_";
			}
		}
	}

	// display item adds and compares
	void dispAddItem() {
		std::cout << "3rd Method: Add Item: " << c_add << " compares and " << m_add << " moves" << std::endl;
	}
	
	// display item removes and compares
	void dispRemoveItem() {
		std::cout << "3rd Method: Remove Item: " << c_remove << " compares and " << m_remove << " moves" << std::endl;
	}
}; // end task 3

// overloaded operators 
bool operator== (const A& listA, const A& listB) {
	if (listA == listB) {
		return true;
	}
	else {
		return false;
	}
}

bool operator> (const A& listA, const A& listB) {
	if (listA > listB) {
		return true;
	}
	else {
		return false;
	}
}

bool operator< (const A& listA, const A& listB) {
	if (listA < listB) {
		return true;
	}
	else {
		return false;
	}
}



int main(){ // test function
	
	//Make / decl new items
	orderedList<int> list;
	EndTheory<int> list2;
	BlankTheory<int> list3;
	
	// Rand number generator to clock time / ensures always random
	srand(time(NULL));

	//for (int run = 0; run < 100; run++){
		// rand 30 objects into arrays
		for (int i = 0; i < MAX_ITEMS; ++i) {
			//reset stats on each loop
			list.resetStats();
			list2.resetStats();
			list3.resetStats();

			// throw error if list full
			if (list.isFull() || list2.isFull() || list3.isFull()) {
				throw ("LIST IS FULL!");
			}
			
			// Add items
			list.AddItem(rand() % 100);
			list2.AddItem(rand() % 100);
			list3.AddItem(rand() % 100);
		}
		
		// Disp total add item counts over loop
		list.dispAddItem();
		list2.dispAddItem();
		list3.dispAddItem();

		// rand remove 25 obj from arrays
		for (int i = 0; i < MAX_ITEMS - 5; ++i) {
			// reset stats on each loop
			list.resetStats();
			list2.resetStats();
			list3.resetStats();
			
			// throw error if list empty
			if (list.isEmpty()) {
				throw ("LIST IS EMPTY!");
			}

			// Remove items
			list.RemoveItem();
			list2.RemoveItem();
			list3.RemoveItem();
		}

		// Disp total remove item counts over loop
		list.dispRemoveItem();
		list2.dispRemoveItem();
		list3.dispRemoveItem();

		//list.MakeEmpty();
		//list2.MakeEmpty();
		//list3.MakeEmpty();
	//}

	
	//Display arrays final 
	std::cout << "List1: ";
	list.DispArray();
	std::cout << std::endl;
	std::cout << "List2: ";
	list2.DispArray();
	std::cout << std::endl;
	std::cout << "List3: ";
	list3.DispArray();
	std::cout << std::endl;

}
