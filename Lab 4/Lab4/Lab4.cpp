#include <iostream>
#include <chrono>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int param = 0;

typedef std::chrono::high_resolution_clock Clock;

/*
template <class T> struct Node {
    Node* next;
    Node* previous;
    T* item;

    Node() {
        this->item = NULL;
        this->next = NULL;
        this->previous = NULL;
    }

    Node(T* item) {
        this->item = item;
        this->next = NULL;
        this->previous = NULL;
    }

    // Prints the Item in the Node
    void printNode() {
        if (item != NULL) {
            cout << *item;
        }
        else {
            cout << "NULL";
        }
    }

};

template <class T> class LinkedList {

private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* CurNode;
public:

    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
        CurNode = NULL;
    }

    ~LinkedList() {
        Node<T>* temp = head;
        while (head != NULL) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void AddItem(T* item) {
        Node<T>* NewNode = new Node<T>(item);

        if (head == NULL) {
            head = NewNode;
            tail = NewNode;
        }
        else {
            tail->next = NewNode;
            tail = tail->next;
        }
    }

    T* GetItem(T* item) {
        Node<T>* temp = head;

        if (temp->item == item) {
            head = head->next;
            delete temp;
            return item;        // Returns item and deletes pointer
        }
        else if (temp != NULL) {
            // Iterates through the linked list (left to right), checks if next pointer has item
            while (temp->next != NULL && temp->next->item != item) {
                temp = temp->next;
            }
            // If temp isn't NULL,
            if (temp != NULL) {
                temp->next = temp->next->next;
                temp = temp->next;
                delete temp;        // Deletes Pointer
                return item;        // Returns Item
            }
            return NULL;            // Return NULL if item isn't in list
        }
        else {
            return NULL;    // Returns NULL if head is NULL
        }
    }

    bool IsInList(T* item) {
        Node<T>* temp = head;
        while (temp != NULL) {
            if (temp->item == item) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool IsEmpty() {
        if (head == NULL) {
            return true;
        }
        return false;
    }

    int Size() {
        Node<T>* temp = head;
        int c = 0;
        while (temp != NULL) {
            temp = temp->next;
            c += 1;
        }
        return c;
    }

    T* SeeNext() {
        if (head == NULL) {
            cout << "Error: List is empty" << endl;
            return NULL;
        }
        else if (CurNode == NULL) {
            CurNode = head;
            return CurNode->item;
        }
        else if (CurNode->next == NULL) {
            cout << "Error: End of List" << endl;
            return NULL;
        }
        else {
            CurNode = CurNode->next;
            return CurNode->item;
        }
    }

    T* SeeAt(int i) {
        Node<T>* temp = head;
        int j = 1;
        while (temp != NULL && j != i) {
            j += 1;
            temp = temp->next;
        }
        if (temp != NULL) {
            CurNode = temp;
            return temp->item;
        }
        cout << "Error: Index not in list" << endl;
        return NULL;
    }

    // Sets location of SeeNext to the start of the list
    void Reset() {
        CurNode = NULL;
    }

    // Prints the Item
    void printItem(T* item) {
        if (item != NULL) {
            cout << *item;
        }
        else {
            cout << "NULL";
        }
    }

    void display() {
        if (head != NULL) {
            Node<T>* temp = head;
            while (temp->next != NULL) {
                temp->printNode();
                cout << endl;
                temp = temp->next;
            }
            temp->printNode();
            cout << endl;
        }
        else {
            cout << "List is empty.\n" << endl;
        }
    }

    void Prepend(Node<T>* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
    }

    void InsertAfter(Node<T>* currentNode, Node<T>* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else if (currentNode == tail) {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        else {
            Node<T>* successor = currentNode->next;
            newNode->next = successor;
            newNode->previous = currentNode;
            currentNode->next = newNode;
            successor->previous = newNode;
        }
    }

    void MoveAfter(Node<T>* nodeToMove, Node<T>* nodeBefore) { // ZyBooks MoveAfter Function
        // First remove nodeToMove from the list, but do not deallocate
        Node<T>* successor = nodeToMove->next;
        Node<T>* predecessor = nodeToMove->previous;
        if (successor) {
            successor->previous = predecessor;
        }
        if (predecessor) {
            predecessor->next = successor;
        }
        if (nodeToMove == head) {
            head = successor;
        }
        if (nodeToMove == tail) {
            tail = predecessor;
        }
        nodeToMove->next = nullptr;
        nodeToMove->previous = nullptr;

        // If nodeBefore is non-null, use InsertAfter(), otherwise use Prepend()
        if (nodeBefore) {
            InsertAfter(nodeBefore, nodeToMove);
        }
        else {
            Prepend(nodeToMove);
        }
    }

    void InsertionSortDoublyLinked() { // ZyBooks Doubly-Linked List Insertion Sort
        Node<T>* currentNode = head->next;
        while (currentNode) {
            Node<T>* nextNode = currentNode->next;
            Node<T>* searchNode = currentNode->previous;

            while (searchNode && searchNode->item > currentNode->item) {
                searchNode = searchNode->previous;
            }

            // Move currentNode after searchNode
            MoveAfter(currentNode, searchNode);

            // Advance to next node
            currentNode = nextNode;
        }
    }
};
*/


template <typename T> class Node {
public:
    T data;
    Node* next;
    Node* previous;

    Node(T initialData) {
        data = initialData;
        next = nullptr;
        previous = nullptr;
    }
};

template <typename T> class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    virtual ~LinkedList() {
        Node<T>* currentNode = head;
        while (currentNode) {
            Node<T>* toBeDeleted = currentNode;
            currentNode = currentNode->next;
            delete toBeDeleted;
        }
    }

    /*
    void Append(T entryNode) {
        Node<T>* newNode = new Node<T>(entryNode);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }

    void Prepend(T entryNode) {
        Node<T>* newNode = new Node<T>(entryNode);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
    }
    */

    void Append(Node<T>* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }

    void Prepend(Node<T>* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
    }

    void InsertAfter(Node<T>* currentNode, Node<T>* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else if (currentNode == tail) {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        else {
            Node<T>* successor = currentNode->next;
            newNode->next = successor;
            newNode->previous = currentNode;
            currentNode->next = newNode;
            successor->previous = newNode;
        }
    }

    void Remove(Node<T>* currentNode) {
        Node<T>* successor = currentNode->next;
        Node<T>* predecessor = currentNode->previous;

        if (successor) {
            successor->previous = predecessor;
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

    void PrintList(std::ostream& printStream, const std::string& separator = ", ") {
        Node<T>* node = head;
        if (node) {
            // Head node is not preceded by separator
            printStream << node->data;
            node = node->next;
        }
        while (node) {
            printStream << "\n" << node->data;
            node = node->next;
        }
        printStream << std::endl;
    }

    // Moves nodeToMove to immediately after nodeBefore. If nodeBefore is null, 
    // nodeToMove is moved to the front of the list.
    void MoveAfter(Node<T>* nodeToMove, Node<T>* nodeBefore) { // Supporting function for sorting
        // First remove nodeToMove from the list, but do not deallocate
        Node<T>* successor = nodeToMove->next;
        Node<T>* predecessor = nodeToMove->previous;
        if (successor) {
            successor->previous = predecessor;
        }
        if (predecessor) {
            predecessor->next = successor;
        }
        if (nodeToMove == head) {
            head = successor;
        }
        if (nodeToMove == tail) {
            tail = predecessor;
        }
        nodeToMove->next = nullptr;
        nodeToMove->previous = nullptr;

        // If nodeBefore is non-null, use InsertAfter(), otherwise use Prepend()
        if (nodeBefore) {
            InsertAfter(nodeBefore, nodeToMove);
        }
        else {
            Prepend(nodeToMove);
        }
    }

    void InsertionSortDoublyLinked(int order) {
        Node<T>* currentNode = head->next;
        while (currentNode) {
            Node<T>* nextNode = currentNode->next;
            Node<T>* searchNode = currentNode->previous;

            if (order == 1) {
                while (searchNode && searchNode->data > currentNode->data) {
                    searchNode = searchNode->previous;
                }
            }
            else {
                while (searchNode && searchNode->data < currentNode->data) {
                    searchNode = searchNode->previous;
                }
            }

            // Move currentNode after searchNode
            MoveAfter(currentNode, searchNode);

            // Advance to next node
            currentNode = nextNode;
        }
    }

    void BubbleSortDoublyLinked(int param, int order) {
        Node<T>* currentNode = head->next;
        Node<T>* nextNode = currentNode->next;
        Node<T>* searchNode = currentNode->previous;
        while (currentNode != searchNode) {
            nextNode = currentNode->next;
            searchNode = currentNode->previous;

            if (order == 1) {
                if (searchNode->data > currentNode->data) {
                    swap(searchNode->data, currentNode->data);
                }
                currentNode = currentNode->next;
            }
            else {

            }
            searchNode = currentNode;
        }
    }

    void bubbleSort(int order)
    {
        Node<T>* currentNode = head;
        int swapped, i;
        Node<T>* ptr1;
        Node<T>* lptr = NULL;

        /* Checking for empty list */
        if (head == NULL)
            return;

        do
        {
            swapped = 0;
            ptr1 = head;

            while (ptr1->next != lptr)
            {   
                if (order == 1) {

                    if (ptr1->data > ptr1->next->data)
                    {
                        swap(ptr1->data, ptr1->next->data);
                        swapped = 1;
                    }
                }
                else {
                    if (ptr1->data < ptr1->next->data) {
						{
						    swap(ptr1->data, ptr1->next->data);
						    swapped = 1;
						}
                    }
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void ZyBubbleSort(int* numbers, int numbersSize) { //ZyBooks Bubble Sort
        for (int i = 0; i < numbersSize - 1; i++) {
            for (int j = 0; j < numbersSize - i - 1; j++) {
                if (numbers[j] > numbers[j + 1]) {
                    int temp = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = temp;
                }
            }
        }
    }

	// quick sort stuff ---


    // A helper function to find the last node of the linked list.
    Node<T>* lastNode(Node<T>* head)
    {
        Node<T>* root = head;
        while (root && root->next)
            root = root->next;
        return root;
    }

    //Consider the last element as pivot.
    Node<T>* partition(Node<T>* start, Node<T>* end)
    {
        // set pivot as end element.
        Node<T> pivot = end->data;

        // similar to i = l-1 for array implementation.
        Node<T>* i = start->previous;

        for (Node<T>* temp = start; temp != end; temp = temp->next)
        {
            if (temp->data < pivot.data) // implement <= if needed
            {

                if (i == NULL)
                    i = start;
                else
                    i = i->next;

                swap((i->data), (temp->data));
            }
        }

        if (i == NULL)
            i = start;
        else
            i = i->next;

        swap((i->data), (end->data));
        return i;
    }

    // implementation of quicksort.
    void _quickSort(Node<T>* start, Node<T>* end)
    {
        if (end != NULL && start != end && start != end->next)
        {
            Node<T>* pivot = partition(start, end);
            _quickSort(start, pivot->previous);
            _quickSort(pivot->next, end);
        }
    }

    void quickSort(int order) // order is not yet implemented for quicksort
    {
		Node<T>* root = head;
        Node<T>* end = lastNode(root);
        Node<T>* head = root;
        _quickSort(head, end);
    }

	// end quick sort stuff ---

	
};


class Student {
private:
    string firstName;
    string lastName;
    string mNum;
public:
    
    

    Student() { // Default constructor (for testing)
        firstName = "John";
        lastName = "Doe";
        mNum = "M00000000";
    }

    Student(string firstName, string lastName, string mNum) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->mNum = mNum;
    }

    string GetName() {
        return this->firstName + " " + this->lastName;
    }

    string GetMNumber() {
        return this->mNum;
    }

    bool operator<(const Student rhs) {
        if (param == 1) {
            return this->firstName < rhs.firstName;
        }
        else if (param == 2) {
            return this->lastName < rhs.lastName;
        }
        else {
            return this->mNum < rhs.mNum;
        }
    }
    bool operator>(const Student rhs) {
        if (param == 1) {
            return this->firstName > rhs.firstName;
        }
        else if (param == 2) {
            return this->lastName > rhs.lastName;
        }
        else {
            return this->mNum > rhs.mNum;
        }
    }
	
    bool operator==(const Student rhs) {
        if (param == 1) {
            return this->firstName == rhs.firstName;
        }
        else if (param == 2) {
            return this->lastName == rhs.lastName;
        }
        else {
            return this->mNum == rhs.mNum;
        }
    }

    /*
    bool operator<(const Student rhs) {
		cout << "PARAM = " << param << endl;
        if (param == 1)
            return this->firstName < rhs.firstName;
        else if (param == 2)
            return this->lastName < rhs.lastName;
        else if (param == 3)
            return this->mNum < rhs.mNum;
    }

    bool operator>(const Student rhs) {
		cout << "PARAM = " << param << endl;
        if (param == 1)
            return this->firstName > rhs.firstName;
        else if (param == 2)
            return this->lastName > rhs.lastName;
        else if (param == 3)
            return this->mNum > rhs.mNum;
    }

    bool operator==(const Student rhs) {
		cout << "PARAM = " << param << endl;
        if (param == 1)
            return this->firstName == rhs.firstName;
        else if (param == 2)
            return this->lastName == rhs.lastName;
        else if (param == 3)
            return this->mNum == rhs.mNum;
    }
    */

    friend ostream& operator<<(ostream& output, const Student& st) {
        output << st.firstName << " " << st.lastName << "\t\t" << st.mNum;
        return output;
    }
};

//sorting algorithms
void ZyBubbleSort(int* numbers, int numbersSize) { //ZyBooks Bubble Sort
    for (int i = 0; i < numbersSize - 1; i++) {
        for (int j = 0; j < numbersSize - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

void ZyInsertionSort(int* numbers, int numbersSize) { //ZyBooks Insertion Sort
	for (int i = 1; i < numbersSize; i++) {
		int j = i;
		while (j > 0 && numbers[j] < numbers[j - 1]) {
			// Swap numbers[j] and numbers [j - 1]
			int temp = numbers[j];
			numbers[j] = numbers[j - 1];
			numbers[j - 1] = temp;
			j--;
		}
	}
}

void ZyMerge(int* numbers, int leftFirst, int leftLast, int rightLast) { // ZyBooks Merge function for Merge Sort
    int mergedSize = rightLast - leftFirst + 1;       // Size of merged partition
    int* mergedNumbers = new int[mergedSize]; // Dynamically allocates temporary
    // array for merged numbers
    int mergePos = 0;                         // Position to insert merged number
    int leftPos = leftFirst;                  // Initialize left partition position
    int rightPos = leftLast + 1;              // Initialize right partition position

    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= leftLast && rightPos <= rightLast) {
        if (numbers[leftPos] <= numbers[rightPos]) {
            mergedNumbers[mergePos] = numbers[leftPos];
            leftPos++;
        }
        else {
            mergedNumbers[mergePos] = numbers[rightPos];
            rightPos++;
        }
        mergePos++;
    }

    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= leftLast) {
        mergedNumbers[mergePos] = numbers[leftPos];
        leftPos++;
        mergePos++;
    }

    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= rightLast) {
        mergedNumbers[mergePos] = numbers[rightPos];
        rightPos++;
        mergePos++;
    }

    // Copy merged numbers back to numbers
    for (mergePos = 0; mergePos < mergedSize; mergePos++) {
        numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
    }

    // Free temporary array
    delete[] mergedNumbers;
}

void ZyMergeSort(int* numbers, int startIndex, int endIndex) { // ZyBooks Merge Sort
    if (startIndex < endIndex) {
        // Find the midpoint in the partition
        int mid = (startIndex + endIndex) / 2;

        // Recursively sort left and right partitions
        ZyMergeSort(numbers, startIndex, mid);
        ZyMergeSort(numbers, mid + 1, endIndex);

        // Merge left and right partition in sorted order
        ZyMerge(numbers, startIndex, mid, endIndex);
    }
}

int ZyPartition(int* numbers, int startIndex, int endIndex) { // ZyBooks Partition function for Quicksort
   // Select the middle value as the pivot.
   int midpoint = startIndex + (endIndex - startIndex) / 2;
   int pivot = numbers[midpoint];
   
   // "low" and "high" start at the ends of the partition
   // and move toward each other.
   int low = startIndex;
   int high = endIndex;
   
   bool done = false;
   while (!done) {
      // Increment low while numbers[low] < pivot
      while (numbers[low] < pivot) {
        low = low + 1;
      }
      
      // Decrement high while pivot < numbers[high]
      while (pivot < numbers[high]) {
         high = high - 1;
      }
      
      // If low and high have crossed each other, the loop
      // is done. If not, the elements are swapped, low is
      // incremented and high is decremented.
      if (low >= high) {
         done = true;
      }
      else {
         int temp = numbers[low];
         numbers[low] = numbers[high];
         numbers[high] = temp;
         low = low + 1;
         high = high - 1;
      }
   }

   // "high" is the last index in the left partition.
   return high;
}

void ZyQuicksort(int* numbers, int startIndex, int endIndex) { // ZyBooks Quicksort
    // Only sort if at least 2 elements exist
    if (endIndex <= startIndex) {
        return;
    }

    // Partition the array
    int high = ZyPartition(numbers, startIndex, endIndex);

    // Recursively sort the left partition
    ZyQuicksort(numbers, startIndex, high);

    // Recursively sort the right partition
    ZyQuicksort(numbers, high + 1, endIndex);
}

// Binary max-heap percolate down
void ZyMaxHeapPercolateDown(int nodeIndex, int* heapArray, int heapSize) { //ZyBooks Percolate function for Heap Sort
    int childIndex = 2 * nodeIndex + 1;
    int value = heapArray[nodeIndex];

    while (childIndex < heapSize) {
        // Find the max among the node and all the node's children
        int maxValue = value;
        int maxIndex = -1;
        int i = 0;
        while (i < 2 && i + childIndex < heapSize) {
            if (heapArray[i + childIndex] > maxValue) {
                maxValue = heapArray[i + childIndex];
                maxIndex = i + childIndex;
            }
            i++;
        }

        if (maxValue == value) {
            return;
        }

        // Swap heapArray[nodeIndex] and heapArray[maxIndex]
        int temp = heapArray[nodeIndex];
        heapArray[nodeIndex] = heapArray[maxIndex];
        heapArray[maxIndex] = temp;

        nodeIndex = maxIndex;
        childIndex = 2 * nodeIndex + 1;
    }
}

// Sorts the array of numbers using the heap sort algorithm
void ZyHeapSort(int* numbers, int numbersLength) { //ZyBooks Heap Sort
    // Heapify numbers array
    int i = numbersLength / 2 - 1;
    while (i >= 0) {
        ZyMaxHeapPercolateDown(i, numbers, numbersLength);
        i--;
    }

    i = numbersLength - 1;
    while (i > 0) {
        // Swap numbers[0] and numbers[i]
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;

        ZyMaxHeapPercolateDown(0, numbers, i);
        i--;
    }
}

int ZyRadixGetLength(int value) { //ZyBooks Radix Length function for Radix Sort
    if (value == 0) {
        return 1;
    }

    int digits = 0;
    while (value != 0) {
        digits++;
        value /= 10;
    }
    return digits;
}

// Returns the maximum length, in number of digits, out of all array elements
int ZyRadixGetMaxLength(int* numbers, int numbersSize) { // ZyBooks Max Length function for Radix Sort
    int maxDigits = 0;
    for (int i = 0; i < numbersSize; i++) {
        int digitCount = ZyRadixGetLength(numbers[i]);
        if (digitCount > maxDigits) {
            maxDigits = digitCount;
        }
    }
    return maxDigits;
}

void ZyRadixSort(int* numbers, int numbersSize) { // ZyBooks Radix Sort
    vector<vector<int>*> buckets;
    for (int i = 0; i < 10; i++) {
        vector<int>* bucket = new vector<int>();
        buckets.push_back(bucket);
    }

    int copyBackIndex = 0;

    // Find the max length, in number of digits
    int maxDigits = ZyRadixGetMaxLength(numbers, numbersSize);

    int pow10 = 1;
    for (int digitIndex = 0; digitIndex < maxDigits; digitIndex++) {
        // Put numbers into buckets
        for (int i = 0; i < numbersSize; i++) {
            int num = numbers[i];
            int bucketIndex = (abs(num) / pow10) % 10;
            buckets[bucketIndex]->push_back(num);
        }

        // Copy buckets back into numbers array
        copyBackIndex = 0;
        for (int i = 0; i < 10; i++) {
            vector<int>& bucket = *buckets[i];
            for (int j = 0; j < bucket.size(); j++) {
                numbers[copyBackIndex] = bucket[j];
                copyBackIndex++;
            }
            bucket.clear();
        }

        pow10 *= 10;
    }

    vector<int> negatives;
    vector<int> nonNegatives;
    for (int i = 0; i < numbersSize; i++) {
        int num = numbers[i];
        if (num < 0) {
            negatives.push_back(num);
        }
        else {
            nonNegatives.push_back(num);
        }
    }

    // Copy sorted content to array - negatives in reverse, then non-negatives
    copyBackIndex = 0;
    for (int i = negatives.size() - 1; i >= 0; i--) {
        numbers[copyBackIndex] = negatives[i];
        copyBackIndex++;
    }
    for (int i = 0; i < nonNegatives.size(); i++) {
        numbers[copyBackIndex] = nonNegatives[i];
        copyBackIndex++;
    }

    // Free each dynamically allocated bucket
    for (int i = 0; i < 10; i++) {
        delete buckets[i];
    }
}

void countSort(int array[], int size) { // Programiz Count Sort (REWORK THIS)
    // The size of count must be at least the (max+1) but
    // we cannot assign declare it as int count(max+1) in C++ as
    // it does not support dynamic memory allocation.
    // So, its size is provided statically.
    int output[25000];
    int count[30000];
    int max = array[0];

    // Find the largest element of the array
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // Initialize count array with all zeros.
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

/*
void countSort(vector<int>& arr) // Missing declarations & supporting functions
{
	int max = *max_element(arr.begin(), arr.end());
	int min = *min_element(arr.begin(), arr.end());
	int range = max - min + 1;

	vector<int> count(range), output(arr.size());
	for (int i = 0; i < arr.size(); i++)
		count[arr[i] - min]++;

	for (int i = 1; i < count.size(); i++)
		count[i] += count[i - 1];

	for (int i = arr.size() - 1; i >= 0; i--) {
		output[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}

	for (int i = 0; i < arr.size(); i++)
		arr[i] = output[i];
}
*/
 
// Function to print an array
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << " " << arr[i];
}

string ArrayToString(int* array, int arraySize) { //ZyBooks Array to String
    // Special case for empty array
    if (0 == arraySize) {
        return string("[]");
    }

    // Start the string with the opening '[' and element 0
    string result = "[" + to_string(array[0]);

    // For each remaining element, append comma, space, and element
    for (int i = 1; i < arraySize; i++) {
        result += ", ";
        result += to_string(array[i]);
    }

    // Add closing ']' and return result
    result += "]";
    return result;
}

void ResetArrays(int array10[], int array100[], int array500[], int array5000[], int array25000[]) {
    for (int i = 0; i < 10; i++)
        array10[i] = rand() % ((2 * 10) + 1);
    for (int i = 0; i < 100; i++)
        array100[i] = rand() % ((2 * 100) + 1);
    for (int i = 0; i < 500; i++)
        array500[i] = rand() % ((2 * 500) + 1);
    for (int i = 0; i < 5000; i++)
        array5000[i] = rand() % ((2 * 5000) + 1);
    for (int i = 0; i < 25000; i++)
        array25000[i] = rand() % ((2 * 25000) + 1);
}


void sorts()
{


	// Declare the arrays  
	int array10[10];
	int array100[100];
	int array500[500];
	int array5000[5000];
	int array25000[25000];

	// Initial array scramble
	for (int i = 0; i < 10; i++)
		array10[i] = rand() % ((2 * 10) + 1);
	for (int i = 0; i < 100; i++)
		array100[i] = rand() % ((2 * 100) + 1);
	for (int i = 0; i < 500; i++)
		array500[i] = rand() % ((2 * 500) + 1);
	for (int i = 0; i < 5000; i++)
		array5000[i] = rand() % ((2 * 5000) + 1);
	for (int i = 0; i < 25000; i++)
		array25000[i] = rand() % ((2 * 25000) + 1);

	// Time Stuff:
	//auto t1 = Clock::now();
	//auto t2 = Clock::now();
	//cout << "Delta t2-t1: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;


	// ============================================ BUBBLE SORT ============================================

	cout << "=-=-=-=-=-=-=-= BUBBLE SORT =-=-=-=-=-=-=-=" << endl;

	auto t1 = Clock::now();
	ZyBubbleSort(array10, 10);
	auto t2 = Clock::now();
	//cout << "10 SORTED:   " << ArrayToString(array10, 10) << endl;
	cout << "Bubble Sort 10: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyBubbleSort(array100, 100);
	t2 = Clock::now();
	cout << "Bubble Sort 100: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyBubbleSort(array500, 500);
	t2 = Clock::now();
	cout << "Bubble Sort 500: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyBubbleSort(array5000, 5000);
	t2 = Clock::now();
	cout << "Bubble Sort 5000: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyBubbleSort(array25000, 25000);
	t2 = Clock::now();
	cout << "Bubble Sort 25000: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	// ============================================ INSERTION SORT ============================================

	cout << "=-=-=-=-=-=-=-= INSERTION SORT =-=-=-=-=-=-=-=" << endl;
	ResetArrays(array10, array100, array500, array5000, array25000);

	t1 = Clock::now();
	ZyInsertionSort(array10, 10);
	t2 = Clock::now();
	cout << "Insertion Sort 10: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyInsertionSort(array100, 100);
	t2 = Clock::now();
	cout << "Insertion Sort 100: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyInsertionSort(array500, 500);
	t2 = Clock::now();
	cout << "Insertion Sort 500: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyInsertionSort(array5000, 5000);
	t2 = Clock::now();
	cout << "Insertion Sort 5000: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyInsertionSort(array25000, 25000);
	t2 = Clock::now();
	cout << "Insertion Sort 25000: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	// ============================================ MERGE SORT ============================================

	cout << "=-=-=-=-=-=-=-= MERGE SORT =-=-=-=-=-=-=-=" << endl;
	ResetArrays(array10, array100, array500, array5000, array25000);

	t1 = Clock::now();
	ZyMergeSort(array10, 0, 10 - 1);
	t2 = Clock::now();
	cout << "Merge Sort 10: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyMergeSort(array100, 0, 100 - 1);
	t2 = Clock::now();
	cout << "Merge Sort 100: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyMergeSort(array500, 0, 500 - 1);
	t2 = Clock::now();
	cout << "Merge Sort 500: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyMergeSort(array5000, 0, 5000 - 1);
	t2 = Clock::now();
	cout << "Merge Sort 5000: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyMergeSort(array25000, 0, 25000 - 1);
	t2 = Clock::now();
	cout << "Merge Sort 25000: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	// ============================================ QUICKSORT ============================================

	cout << "=-=-=-=-=-=-=-= QUICKSORT =-=-=-=-=-=-=-=" << endl;
	ResetArrays(array10, array100, array500, array5000, array25000);

	t1 = Clock::now();
	ZyQuicksort(array10, 0, 10 - 1);
	t2 = Clock::now();
	cout << "Quicksort 10: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyQuicksort(array100, 0, 100 - 1);
	t2 = Clock::now();
	cout << "Quicksort 100: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyQuicksort(array500, 0, 500 - 1);
	t2 = Clock::now();
	cout << "Quicksort 500: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyQuicksort(array5000, 0, 5000 - 1);
	t2 = Clock::now();
	cout << "Quicksort 5000: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyQuicksort(array25000, 0, 25000 - 1);
	t2 = Clock::now();
	cout << "Quicksort 25000: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	// ============================================ HEAP SORT ============================================

	cout << "=-=-=-=-=-=-=-= HEAP SORT =-=-=-=-=-=-=-=" << endl;
	ResetArrays(array10, array100, array500, array5000, array25000);

	t1 = Clock::now();
	ZyHeapSort(array10, 10);
	t2 = Clock::now();
	cout << "Heap Sort 10: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyHeapSort(array100, 100);
	t2 = Clock::now();
	cout << "Heap Sort 100: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyHeapSort(array500, 500);
	t2 = Clock::now();
	cout << "Heap Sort 500: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyHeapSort(array5000, 5000);
	t2 = Clock::now();
	cout << "Heap Sort 5000: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyHeapSort(array25000, 25000);
	t2 = Clock::now();
	cout << "Heap Sort 25000: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	// ============================================ COUNT SORT ============================================

	cout << "=-=-=-=-=-=-=-= COUNT SORT =-=-=-=-=-=-=-=" << endl;
	ResetArrays(array10, array100, array500, array5000, array25000);

	t1 = Clock::now();
	countSort(array10, 10);
	t2 = Clock::now();
	cout << "Count Sort 10: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	countSort(array100, 100);
	t2 = Clock::now();
	cout << "Count Sort 100: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	countSort(array500, 500);
	t2 = Clock::now();
	cout << "Count Sort 500: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	countSort(array5000, 5000);
	t2 = Clock::now();
	cout << "Count Sort 5000: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	/*
	t1 = Clock::now();
	countSort(array25000, 25000); //runs out of memory
	t2 = Clock::now();
	cout << "Count Sort 25000: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
	*/

	// ============================================ RADIX SORT ============================================

	cout << "=-=-=-=-=-=-=-= RADIX SORT =-=-=-=-=-=-=-=" << endl;
	ResetArrays(array10, array100, array500, array5000, array25000);

	t1 = Clock::now();
	ZyRadixSort(array10, 10);
	t2 = Clock::now();
	cout << "Radix Sort 10: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyRadixSort(array100, 100);
	t2 = Clock::now();
	cout << "Radix Sort 100: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyRadixSort(array500, 500);
	t2 = Clock::now();
	cout << "Radix Sort 500: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyRadixSort(array5000, 5000);
	t2 = Clock::now();
	cout << "Radix Sort 5000: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	t1 = Clock::now();
	ZyRadixSort(array25000, 25000);
	t2 = Clock::now();
	cout << "Radix Sort 25000: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

}


void BananaMenu() {

    cout << R"(
//\
V  \
 \  \_
  \,'.`-.
   |\ `. `.       
   ( \  `. `-.                        _,.-:\
    \ \   `.  `-._             __..--' ,-';/
     \ `.   `-.   `-..___..---'   _.--' ,'/
      `. `.    `-._        __..--'    ,' /
        `. `-_     ``--..''       _.-' ,'
          `-_ `-.___        __,--'   ,'
             `-.__  `----"""    __.-'
                  `--..____..--'
   ___                               
  / __\ __ _ _ __   __ _ _ __   __ _    /\/\   ___ _ __  _   _ 
 /__\/// _` | '_ \ / _` | '_ \ / _` |  /    \ / _ \ '_ \| | | |
/ \/  \ (_| | | | | (_| | | | | (_| | / /\/\ \  __/ | | | |_| |
\_____/\__,_|_| |_|\__,_|_| |_|\__,_| \/    \/\___|_| |_|\__,_|                                                                                         
    )" << "\n";

    // Creates a list of students
    LinkedList<Student> sList;// = LinkedList<Student>();

    // Input String7
    string input = "";
    string prompt = "Select an option: \n\nPrint List \t- \tp\nAdd Student \t- \ta\nDel Student \t- \td\nCheck List \t- \tc\nCheck empty \t- \te\nCheck Length \t- \tl\nNext Student \t- \tn\nStudent at \t- \tm\nReset index \t- \tr\nGenerate Students - \tg\nSort \t\t- \ts\n\nQuit - q\nHelp - h\n";
    // LETTERS IN USE: p a d c e l n m r g s q h
    cout << prompt << endl;
    while (input != "q") {
        cin >> input;

        if (input == "p") {
            cout << "Student Name\t\t\tM Number" << endl;
            cout << "__________________________________________________________________________" << endl;
            //sList.display();
            sList.PrintList(cout);
        }
        else if (input == "a") {

            // Required Student Variables
            string first;
            string last;
            string mNum;

            // Prompts user for Student information
            cout << "Creating new Student...\n\nEnter First Name: ";
            cin >> first;
            cout << "Enter Last Name: ";
            cin >> last;
            cout << "Enter M#: ";
            cin >> mNum;
            cout << "Enter Birthday: \nBirth Month: ";

            // Creates Student without GPA
            Student newStudent = Student(first, last, mNum);
            Node<Student>* stud = new Node<Student>(newStudent);
            sList.Append(stud);
            cout << "Student Created." << endl;


        }
        /*
        else if (input == "d") {
            string mNum;
            if (sList.Size() == 0) {
                cout << "List is empty, cannot delete Students.\n" << endl;
                continue;
            }
            cout << "Enter the M# of the student to be deleted: ";
            cin >> mNum;
            Student temp = Student("F", "L", mNum);
            if (sList.GetItem(&temp) == NULL) {
                cout << "Student not found. Nothing modified.\n" << endl;
            }
            else {
                cout << "Student Deleted.\n" << endl;
            }
        }
        else if (input == "c") {
            string mNum;
            cout << "Enter the M# of the student to check: ";
            cin >> mNum;
            Student temp = Student("F", "L", mNum);
            if (!(sList.IsInList(&temp))) {
                cout << "Student not found in List.\n" << endl;
            }
            else {
                cout << "Student is in the List.\n" << endl;
            }
        }
        else if (input == "e") {
            if (sList.IsEmpty()) {
                cout << "List is empty.\n" << endl;
            }
            else {
                cout << "List is not empty.\n" << endl;
            }
        }
        else if (input == "l") {
            cout << "List is " << sList.Size() << " Students.\n" << endl;
        }
        else if (input == "n") {
            Student* temp = sList.SeeNext();
            if (temp != NULL) {
                cout << *temp;
            }
            cout << endl;
        }
        else if (input == "m") {
            int i;
            cout << "What index would you like to check?: ";
            cin >> i;
            Student* temp = sList.SeeAt(i);
            if (temp != NULL) {
                cout << *temp;
            }
            cout << endl;
        }
        else if (input == "r") {
            sList.Reset();
            cout << "Resetting List Index...\n" << endl;

        }
        */
        else if (input == "g") {
            cout << "How many students would you like to generate?" << endl;
            int numstud = 1;
            cin >> numstud;
            cout << "Generating " << numstud << " students..." << endl;
            for (int i = 0; i < numstud; i++)
            {
                // Required Student Variables
                string first = "";
                string last = "";
                string mNum = "#";

                // create random names & m-numbers
                char c;
                int r;
                int num = 10;
                for (int j = 0; j < num; j++)
                {
                    r = rand() % 26;   // generate a random number
                    c = 'a' + r;            // Convert to a character from a-z
                    first += c;
                }
                for (int j = 0; j < num; j++)
                {
                    r = rand() % 26;   // generate a random number
                    c = 'a' + r;            // Convert to a character from a-z
                    last += c;
                }
                for (int j = 0; j < 8; j++)
                {
                    r = rand() % 10;   // generate a random number
                    c = '0' + r;            // Convert to a character from 0-9
                    mNum += c;
                }

                Student newStudent = Student(first, last, mNum);
                Node<Student>* stud = new Node<Student>(newStudent);
                sList.Append(stud);
                //cout << "Student " << i+1 << " Created." << endl;
            }
            cout << "Done." << endl;
        }
        else if (input == "s") {
            int order = 0;
            param = 0;
			
            string sortPrompt = "Which sorting algorithm would you like to use?\nSelect an option: \n\nInsertion Sort \t- \t1\nBubble Sort \t- \t2\nQuick Sort \t- \t3\n\nBack - b\nHelp - h\n";
            string paramPrompt = "Which parameter would you like to sort by?\nSelect an option: \n\nFirst Name \t- \t1\nLast Name \t- \t2\nM-Number \t- \t3\n";
            string orderPrompt = "Would you like to sort in ascending or descending order?\nSelect an option: \n\nAscending \t- \t1\nDescending \t- \t2\n";
            cout << sortPrompt << endl;
            while (input != "b") {
                cin >> input;

                if (input == "1") {
                    cout << paramPrompt << endl;
                    cin >> param;

                    cout << orderPrompt << endl;
                    cin >> order;

                    cout << "Sorting..." << endl;
                    sList.InsertionSortDoublyLinked(order);
                    cout << "Done." << endl;
                }
                else if (input == "2") {
                    cout << paramPrompt << endl;
                    cin >> param;

                    cout << orderPrompt << endl;
                    cin >> order;

                    cout << "Sorting..." << endl;
                    sList.bubbleSort(order);
                    cout << "Done." << endl;
                }
                else if (input == "3") {
                    cout << paramPrompt << endl;
                    cin >> param;

                    //cout << orderPrompt << endl; // implement this later
                    //cin >> order;
					
                    cout << "Sorting..." << endl;
                    sList.quickSort(order);
                    cout << "Done." << endl;
                }
                else if (input == "h") {
                    cout << sortPrompt << endl;
                }
                else if (input != "b") {
                    cout << "Invalid Input, please try again." << endl;
                }
            }
        }
        else if (input == "h") {
            cout << prompt << endl;
        }
        else if (input != "q") {
            cout << "Invalid Input, please try again." << endl;
        }
    }
}

int main() // main function
{


    //sorts(); // disp sort
    cout << endl; // linespace
    BananaMenu(); // run banana menu





} // the end 