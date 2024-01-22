#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Node {
public:
	int value = 0;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int initialData) {
		value = initialData;
		left = nullptr;
		right = nullptr;
	}

	vector<int> print(bool order) {
		vector<int> answer;
		vector<int> left_side;
		vector<int> right_side;

		if (order == 0) {
			if (left != nullptr)
				left_side = left->print(order);

			answer.push_back(value);
			cout << "Value: " << value << endl;

			if (right != nullptr)
				right_side = right->print(order);
		}
		else {
			if (right != nullptr)
				right_side = right->print(order);

			answer.push_back(value);
			cout << "Value: " << value << endl;

			if (left != nullptr)
				left_side = left->print(order);
		}

		return answer;
	}

	int depth() {
		int left_depth = 0, right_depth = 0;

		if (left != nullptr)
			left_depth = left->depth();
		if (right != nullptr)
			right_depth = right->depth();

		if (left_depth > right_depth)
			return left_depth + 1;
		return right_depth + 1;
	}
};

class Tree {
public:
	Node* root = nullptr;

	//constructor
	Tree() {
		this->root = nullptr;
	}

	//destructor
	~Tree() {
		delete root;
	}

	//insert
	void Insert(int val) {
		if (root == nullptr) {
			root = new Node(val);
			return;
		}

		Node* temp = root;
		while (true) {
			if (val < temp->value) {
				if (temp->left == nullptr) {
					temp->left = new Node(val);
					return;
				}
				temp = temp->left;
			}
			else {
				if (temp->right == nullptr) {
					temp->right = new Node(val);
					return;
				}
				temp = temp->right;
			}
		}
	}

	//find
	Node* Find(int num) { //modified 
		Node* currentNode = root;
		while (currentNode) {
			if (currentNode->value == num) {
				cout << "Value found!" << endl;
				return currentNode; //found value
			}
			else if (num < currentNode->value)
				currentNode = currentNode->left;
			else
				currentNode = currentNode->right;
		}

		cout << "Could not find specified value." << endl;
		return nullptr; //return null if not found
	}

	//number of values
	int Size(Node* node) {
		if (node == nullptr) {
			return 0;
		}

		return 1 + Size(node->left) + Size(node->right);
	}

	//print ascending
	void GetAllAscending() {
		if (root == nullptr)
			return;
		bool order = 0;
		vector<int> ans = root->print(order);
	}

	//print descending
	void GetAllDescending() {
		if (root == nullptr)
			return;
		bool order = 1;
		vector<int> ans = root->print(order);
	}

	//remove value
	Node* Remove(int val) {
		Node* parent = nullptr;
		Node* curNode = root;

		while (curNode) {
			if (curNode->value == val)
				break;
			else if (curNode->value > val) {
				parent = curNode;
				curNode = curNode->left;
			}
			else {
				parent = curNode;
				curNode = curNode->right;
			}
		}

		if (curNode == nullptr)
			return nullptr;

		if (curNode->left == nullptr && curNode->right == nullptr) {
			if (parent == nullptr)
				root = nullptr;
			else if (parent->left == curNode)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}
		else if (curNode->left == nullptr) {
			if (parent == nullptr)
				root = curNode->right;
			else if (parent->left == curNode)
				parent->left = curNode->right;
			else
				parent->right = curNode->right;
		}
		else if (curNode->right == nullptr) {
			if (parent == nullptr)
				root = curNode->left;
			else if (parent->left == curNode)
				parent->left = curNode->left;
			else
				parent->right = curNode->left;
		}
		else {
			Node* holder = curNode->right;
			Node* tempParent = curNode;

			while (holder->left != nullptr) {
				tempParent = holder;
				holder = holder->left;
			}
			curNode->value = holder->value;

			if (tempParent->left == holder)
				tempParent->left = holder->right;
			else
				tempParent->right = holder->right;

			curNode = holder;
		}
		return curNode;
	}

	//empty tree
	void EmptyTree(Node* node) //a bit janky, but it works
	{
		if (node == nullptr)
			return;

		int len = Size(node);
		int val = node->value;
		while (len > 1) {
			for (int i = len; i >= 0; i--) {
				if (node->right != nullptr)
					val = node->right->value;
				else if (node->left != nullptr)
					val = node->left->value;
				else
					val = node->value;

				Remove(val);
			}
			len = Size(node);
		}
	}
};


void MainMenu() {
	Tree* BST = new Tree();

	string input = "";
	string prompt = "Select an option: \n\nInsert \t\t- \ti\nFind \t\t- \tf\nSize \t\t- \ts\nAscending \t- \ta\nDescending \t- \td\nEmpty Tree \t- \te\nRemove \t\t- \tr\n\nQuit - q\nHelp - h\n";
	// LETTERS IN USE: i f s a d e r
	cout << prompt << endl;
	while (input != "q") {

		cin >> input;

		if (input == "i") {
			//insert
			int num = 0;
			cout << "Please enter a value to insert: ";
			cin >> num;
			BST->Insert(num);
		}
		else if (input == "f") {
			//find
			int num = 0;
			cout << "Please enter a value to search for: ";
			cin >> num;
			cout << "Searching..." << endl;
			BST->Find(num);
		}
		else if (input == "s") {
			//size
			cout << "Tree size: " << BST->Size(BST->root) << endl;
		}
		else if (input == "a") {
			//get ascending
			BST->GetAllAscending();
		}
		else if (input == "d") {
			//get descending
			BST->GetAllDescending();
		}
		else if (input == "e") {
			//empty tree
			cout << "Emptying tree..." << endl;
			BST->EmptyTree(BST->root);
			cout << "Done." << endl;
		}
		else if (input == "r") {
			//remove
			int num = 0;
			cout << "Please enter an entry to remove: ";
			cin >> num;
			cout << "Removing entry..." << endl;
			BST->Remove(num);
			cout << "Done." << endl;
		}
		else if (input == "h") {
			cout << prompt << endl;
		}
		else if (input != "q") {
			cout << "Invalid Input, please try again." << endl;
		}
	}
}

int main() {
	MainMenu();
}