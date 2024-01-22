#include <stdlib.h>
#include <vector>
#include <iostream>

template <typename T> class Node { // Basic Nodeclass with template T
public:
	
	int val{ 0 };

	Node<T>* leftVal = nullptr;
	Node<T>* rightVal = nullptr;

	Node(T data) { // create binary node
		val = data;
		leftVal = nullptr;
		rightVal = nullptr;
	}

	std::vector<T> print(bool order) { // print out node of vectors, use reccursion here?
		
		// decl vectors
		std::vector<T> total;
		std::vector<T> lBranch;
		std::vector<T> rBranch;

		if (order == 0) { // Case to Print out node if order is 0
			if (leftVal != nullptr)
				lBranch = leftVal->print(order);

			total.push_back(val);
			std::cout << "Value: " << val << std::endl;

			if (rightVal != nullptr)
				rBranch = rightVal->print(order);
		}
		else { // Case to Print out node if order not 0
			if (rightVal != nullptr)
				rBranch = rightVal->print(order);

			total.push_back(val); 
			std::cout << "Value: " << val << std::endl;

			if (leftVal != nullptr)
				lBranch = leftVal->print(order);
		}

		// return 0
		return total; // return total vector to print
	}

	int depth() { // determine node / tree depth
		int lDepth = 0, rDepth = 0;

		if (leftVal != nullptr)
			lDepth = leftVal->depth();
		if (rightVal != nullptr)
			rDepth = rightVal->depth();

		if (lDepth > rDepth)
			return lDepth + 1;
		return rDepth + 1;
	}
};

template <typename T> class BinaryTree { // class Tree using template T
public:
	Node<T>* tRoot = nullptr; // create root node

	BinaryTree() { // default constructor 
		this->tRoot = nullptr;
	}

	~BinaryTree() { // default destructor
		delete tRoot;
	}

	int Size(Node<T>* node) { // returns overall size of the binary tree
		if (node == nullptr) {
			return 0;
		}

		return 1 + Size(node->leftVal) + Size(node->rightVal);
	}

	// print out and return all tree values in ascending order
	void GetAllAscending() {
		if (tRoot == nullptr)
			return;
		bool vSize = 0;
		std::vector<int> final = tRoot->print(vSize); // set final var as new descending vector in print format
	}

	// print out and return all tree values in descending order
	void GetAllDescending() {
		if (tRoot == nullptr)
			return;
		bool vSize = 1;
		std::vector<T> final = tRoot->print(vSize); // set final var as new descending vector in print format
	}

	void Insert(T val) { // insert a new node into the tree
		if (tRoot == nullptr) {
			tRoot = new Node<T>(val);
			std::cout << "Initial Insertion Success.\n";
			return;
		}

		Node<T>* temp = tRoot; // temp node
		while (true) { // shift nodes and insert new value
			if (val < temp->val) {
				if (temp->leftVal == nullptr) {
					temp->leftVal = new Node<T>(val);
					std::cout << "Left Insertion Success.\n"; // insertion onto left branch
					return;
				}
				temp = temp->leftVal;
			}
			else {
				if (temp->rightVal == nullptr) {
					temp->rightVal = new Node<T>(val);
					std::cout << "Right Insertion Success.\n"; // insertion onto right branch
					return;
				}
				temp = temp->rightVal;
			}
		}
	}

	// find a value given in the binary tree
	Node<T>* Find(T val) { //modified 
		Node<T>* currNode = tRoot;
		int recur = 0;
		while (currNode) {
			if (currNode->val == val) { // if val is found

				std::cout << "Given Value was Found in the Tree. \n"; // print out to user that val found

				return currNode; // return node of val that was found
			}

			else if (val < currNode->val) { // iterate thru left nodes
				currNode = currNode->leftVal;

			}
			else {
				currNode = currNode->rightVal; // iterate thru right nodes
			}

			std::cout << "Given Value was not Found in the Tree.\n";
			return nullptr; // null is returned if given value is not found

			recur += 1;
			if (recur >= 10) {
				std::cout << "Rate Limit Exceded!";
				return currNode;
			}
		}
	}

	// Run through the tree and remove the given value from it
	Node<T>* Remove(T val) {
		Node<T>* parNode = nullptr;
		Node<T>* curNode = tRoot;

		while (curNode) { // iterate thru all tree nodes
			if (curNode->val == val)
				break;
			else if (curNode->val > val) { // left branch
				parNode = curNode;
				curNode = curNode->leftVal;
			}
			else { // right branch
				parNode = curNode;
				curNode = curNode->rightVal;
			}
		}

		if (curNode == nullptr) // returns empty if tree - node is empty
			return nullptr;

		if (curNode->leftVal == nullptr && curNode->rightVal == nullptr) { // if left and right empty
			
			if (parNode == nullptr)
				tRoot = nullptr;
			
			else if (parNode->leftVal == curNode)
				parNode->leftVal = nullptr;
			
			else
				parNode->rightVal = nullptr;
		}
		else if (curNode->leftVal == nullptr) { // if left empty
			
			if (parNode == nullptr)
				tRoot = curNode->rightVal;
			
			else if (parNode->leftVal == curNode)
				parNode->leftVal = curNode->rightVal;
			
			else
				parNode->rightVal = curNode->rightVal;
		}
		else if (curNode->rightVal == nullptr) { // if right empty
			
			if (parNode == nullptr)
				tRoot = curNode->leftVal;
			
			else if (parNode->leftVal == curNode)
				parNode->leftVal = curNode->leftVal;
			
			else
				parNode->rightVal = curNode->leftVal;
		}
		else { // else statement
			
			Node<T>* tempNode = curNode->rightVal;
			Node<T>* tempParent = curNode;

			while (tempNode->leftVal != nullptr) { // while temp left node is not empty
				
				tempParent = tempNode;
				
				tempNode = tempNode->leftVal;
			}
			
			curNode->val = tempNode->val;

			if (tempParent->leftVal == tempNode)
				tempParent->leftVal = tempNode->rightVal;
			
			else
				tempParent->rightVal = tempNode->rightVal;

			curNode = tempNode;
		}
		return curNode; // return cur node
	}

	// "Empty" the tree from memory / remove all objects, should avoid mem leaks
	void EmptyTree(Node<T>* node)
	{
		if (node == nullptr)
			return;

		int len = Size(node); // get curr size
		int val = node->val;
		
		while (len > 1) {
			
			for (int i = len; i >= 0; i--) {
				
				if (node->rightVal != nullptr)
					val = node->rightVal->val;
				else if (node->leftVal != nullptr)
					val = node->leftVal->val;
				else
					val = node->val;

				Remove(val);
			}
			len = Size(node); // update size
		}
	}
};

int main() { // use the menu like interface from last lab here
	
	BinaryTree<int>* BinaryTreeObj = new BinaryTree<int>(); // decl the binary tree as type int

	std::string input = "";
	// ** prompt interface from lab 4 **
	std::string prompt = "Main Menu Options: \n\nInsert a Value - i\nFind a Value - f\nSize of Tree - s\nSort in Ascending Order - a\nSort in Descending Order - d\nEmpty the Tree - e\nRemove a Value - r \nQuit - q\nHelp - h\n";

	std::cout << prompt << "\n";

	int recur = 0;

	// Menu Options begin here!
	while (input != "q") {
		std::cin >> input;

		if (input == "i") { // insert val
			int num = 0;
			
			std::cout << "Value to Insert: ";
			std::cin >> num;
			
			BinaryTreeObj->Insert(num);
		}
		else if (input == "s") { // get size
			std::cout << "Current Size of Tree is " << BinaryTreeObj->Size(BinaryTreeObj->tRoot) << " objects.\n";
		}
		else if (input == "f") { // find val

			int num = 0;
			
			std::cout << "Value to Search: ";
			std::cin >> num;
			std::cout << "Processing...\n";
			
			BinaryTreeObj->Find(num);
		}
		
		else if (input == "d") { // get in descending order
			BinaryTreeObj->GetAllDescending();
		}
		
		else if (input == "r") { // remove val
			int num = 0;
			
			std::cout << "Value to Remove: ";
			std::cin >> num;
			std::cout << "Removing entry...\n";
			
			BinaryTreeObj->Remove(num);
			
			std::cout << "Operation Complete.\n";
		}
		
		else if (input == "e") { // empty the binary tree of all values
			
			std::cout << "Processing...\n";
			
			BinaryTreeObj->EmptyTree(BinaryTreeObj->tRoot);
			
			std::cout << "Operation Complete.\n";
		}
		
		else if (input == "h") { // show help text
			std::cout << prompt << "\n";
		}
		
		else if (input == "a") { // get in ascending order
			BinaryTreeObj->GetAllAscending();
		}
		
		else if (input != "q") { // display input error if invalid
			std::cout << "Option \"" << input << "\" not Found, Type 'h' for avaliable options.\n";
		}

		recur += 1; // itt recur

		if (recur > 1000) { // break if infinite loop
			std::cout << "Recursion Limit Reached! Most Likely UnHandeled Input Value.\n";
			break;
		}

	}
}