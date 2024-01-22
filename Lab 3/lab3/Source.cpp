#include <iostream>
#include <cmath>
#include <string>

using namespace std;

template <typename N> class Node { //zyBooks node (with minor changes)
public:
	N data;
	Node* next;
	Node* prev;

	Node(N initialData) {
		data = initialData;
		next = nullptr;
		prev = nullptr;
	}
};

template <typename T> class OrderedLinkedList {
private:
	Node<T>* head = NULL;
	Node<T>* tail = NULL;
	Node<T>* curNode = NULL;
	int numItems = 0;

public:
	inline bool instanceof(const T* ptr) {
		return dynamic_cast<const OrderedLinkedList*>(ptr) != nullptr;
	}

	friend class Student;

	//constructor
	OrderedLinkedList() {
		numItems = 0;
		head = nullptr;
		tail = nullptr;
	}

	//append item
	void AddItem(T newNode) { // zyBooks "Append" with minor changes
		Node<T>* temp = new Node<T>(newNode);

		if (head == nullptr) { // List empty //read access violation: "this" was nullptr
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
		numItems++;
		//delete temp; //doesn't work, find a solution
	}

	T GetItem(T item) { // searches list for value and removes it
		Node<T>* curNode = head;
		Node<T>* holder = head;

		for (int i = 0; i < numItems; i++)
		{
			if (curNode->data != item)
			{
				cout << "searching..." << endl;
				curNode = curNode->next;
			}
			else
			{
				//cout << "|\tFound value \"" << (string)curNode->data << "\" at index " << i << endl;
				//printf("|\tFound value \"%s\" at index %d\n", curNode->data, i);
				holder = curNode;

				//Remove(curNode);
				curNode = NULL;
				curNode = holder->next;

				return holder->data;
				//curNode = curNode->next;
			}
		}

	}

	bool IsInList(T item) {
		Node<T>* curNode = head;

		for (int i = 0; i < numItems; i++)
		{
			if (curNode->data != item)
				curNode = curNode->next;
			else
				return true;
		}
		return false;
	}

	bool IsEmpty() { // maybe works 
		if (numItems > 0) {
			return false;
		}
		else {
			return true;
		}
	}

	int Size() { // maybe works 
		return numItems;
	}

	T SeeNext() {
		Node<T>* curNode = head;


		if (curNode != nullptr) {
			cout << "testing" << endl;
			curNode = curNode->next;
		}
		return curNode->data;
	}

	T SeeAt(int loc) {
		Node<T>* curNode = head;

		for (int i = 0; i < loc; i++)
		{
			curNode = curNode->next;
		}
		return curNode->data;
	}

	void Remove(T currentNode) {
		Node<T>* successor = currentNode->next;
		Node<T>* predecessor = currentNode->prev;

		if (successor) {
			successor->prev = predecessor;
		}
		if (predecessor) {
			predecessor->next = successor;
		}

		if (currentNode == head) {
			head = successor;
		}
		if (currentNode == tail) {
			tail = predecessor;
		}

		delete currentNode;
	}

	void Reset() { // Resets contents of linkedlist
		Node<T>* curNode = head;

		for (int i = 0; i < numItems - 1; i++)
		{
			curNode = NULL;
			curNode = curNode->next;
		}
		head = NULL;
		numItems = 0;
		printf("Linked List Deleted.\n");
	}


	//this might not work
	~OrderedLinkedList() { //zyBooks destructor
		Node<T>* currentNode = head;
		while (currentNode) {
			Node<T>* toBeDeleted = currentNode;
			currentNode = currentNode->next;
			delete toBeDeleted;
		}
	}

	void display() {
		Node<T>* curNode = head;

		/*
		if (instanceof<Student>(this))
			cout << "=========YES===========" << endl;
		*/

		for (int i = 0; i < numItems; i++) {
			printf("%d: %s \n", i, curNode->data);
			curNode = curNode->next;
		}
		cout << endl;
		
		
		//cout << "Name: " << Student.GetName() << " (" << Student.GetAge() << ")" << endl;
		//cout << "MNumber: " << Student.GetMNumber() << endl;
		//cout << "GPA: " << Student.GetGPA << endl;
		return;
		
	}


};

class Student {
private:
	std::string FirstName{ "empty" };
	std::string LastName{ "empty" };
	std::string MNumber{ "empty" };
	float GPA = 0.0;
	int Birthday{ 0 };

public:

	Student() { // Default constructor (for testing)
		FirstName = "John";
		LastName = "Doe";
		MNumber = "M00000000";
		Birthday = 1970;
		GPA = 0.0;
	}


	Student(std::string FName, std::string LName, std::string MNum, int BD, float gpa = 0.0) { //constructor
		FirstName = FName;
		LastName = LName;
		MNumber = MNum;
		Birthday = BD;
		GPA = gpa;
	}

	std::string GetName() {
		return FirstName + " " + LastName;
	}

	std::string GetMNumber() {
		return MNumber;
	}

	int GetAge() {
		return (2022 - Birthday);
	}

	void Display() {
		cout << "Name: " << FirstName << " " << LastName << " (" << GetAge() << ")" << endl;
		cout << "MNumber: " << MNumber << endl;
		cout << "GPA: " << GPA << endl;
		return;
	}


	bool operator>(const Student& s) {
		if (stoi(MNumber.substr(1)) > stoi(s.MNumber.substr(1)))
			return true;
		return false;
	}

	bool operator<(const Student& s) {
		if (stoi(MNumber.substr(1)) < stoi(s.MNumber.substr(1)))
			return true;
		return false;
	}

	bool operator==(const Student& s) {
		if (stoi(MNumber.substr(1)) == stoi(s.MNumber.substr(1)))
			return true;
		return false;
	}

	bool operator!=(const Student& s) {
		if (stoi(MNumber.substr(1)) != stoi(s.MNumber.substr(1)))
			return true;
		return false;
	}
};

int main() {
	cout << "Created by Elias Weitfle and Christian Graber" << endl;

	srand((unsigned int)time(0));

	OrderedLinkedList<Student>* linkedList = new OrderedLinkedList<Student>;

	int choice;
	int index = 0;
	bool repeat = true;

	Student item;
	string name, lname, MN;
	int BD;
	float GPA;
	Student temp;

	// test menu of functions
	while (repeat) {
		std::cout << endl;
		std::cout << "Select an option: \n";
		std::cout << "1. AddItem \n2. GetItem \n3. IsInList \n4. IsEmpty\n5. Size \n6. SeeNext \n7. SeeAt \n8. Reset\n9. Display Student Class\n10. Display LL Class\n11. Quit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: // AddItem (working)
			cout << "Enter (seperated by spaces): First Name, Last Name, M Number, Birthday Year, GPA Number" << endl;
			cin >> name >> lname >> MN >> BD >> GPA;
			linkedList->AddItem(Student(name, lname, MN, BD, GPA));
			break;
		case 2: // GetItem (working)
			cout << "Enter MNumber (w M) \n";
			cin >> MN;
			temp = linkedList->GetItem(Student("temp", "temp", MN, 0, 0.0));
			temp.Display();
			break;
		case 3: // IsInList (working)
			cout << "Enter (seperated by spaces): First Name, Last Name, M Number, Birthday Year, GPA Number" << endl;
			cin >> name >> lname >> MN >> BD >> GPA;
			if (linkedList->IsInList(Student(name, lname, MN, BD, GPA))) {
				cout << "Student is in the List\n";
			}
			else {
				cout << "Student is not in the List\n";
			}
			break;
		case 4: // IsEmpty (working)
			if (linkedList->IsEmpty() == true)
				cout << "The list is empty." << endl;
			else
				cout << "The list is not empty." << endl;
			break;
		case 5: // Size (working)
			cout << "List size: " << linkedList->Size() << endl;
			break;
		case 6: // SeeNext (working)
			temp = linkedList->SeeNext(); // stupid error
			temp.Display();
			break;
		case 7: // SeeAt (working)
			cout << "Which index would you like to see?" << endl;
			cin >> index;
			temp = linkedList->SeeAt(index); // ERROR THIS WAS NULL PTR
			temp.Display();
			break;
		case 8: // Reset (working)
			cout << "Resetting list..." << endl;
			linkedList->Reset();
			break;
		case 9: // Display Student Class (working)
			if (linkedList->Size() == 0) {
				printf("List has no objects to display\n");
				break;
			}
			for (int i = 0; i < linkedList->Size(); i++) {
				printf("--Student %d--\n", (i + 1));
				temp = linkedList->SeeAt(i);
				temp.Display();
			}
			break;

		case 10: // Display LL Class (technically working)
			// call member function of LL
			linkedList->display();
			break;
		case 11: // Quit
			repeat = false;
			break;

		default: // Prompt
			cout << "Please select one of the numbers listed above." << endl;
			repeat = false;
			break;
		}
	}
	//linkedList->display(); // doesn't work really


	//****************************************************
	/*
	cout << "testing AddItem([RANDOM 1-10]): " << endl;
	for (int i = 0; i < 15; i++)
	{
		linkedList->AddItem(rand() % 10 + 1);
	}

	linkedList->display();



	cout << "testing GetItem(5):" << endl;
	linkedList->GetItem(5);

	cout << "testing IsInList(5): " << linkedList->IsInList(5) << endl;

	cout << "testing IsEmpty(): " << linkedList->IsEmpty() << endl;

	cout << "testing Size(): " << linkedList->Size() << endl;

	cout << "testing SeeNext(): " << linkedList->SeeNext() << endl;

	cout << "testing SeeAt(2): " << linkedList->SeeAt(2) << endl;

	cout << "testing Reset(): " << endl;
	linkedList->Reset();

	cout << "testing Destructor: " << endl;
	delete linkedList;
	*/


	return 0;
}