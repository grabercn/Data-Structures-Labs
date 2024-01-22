/* Define max items and remove items and change for testing purposes.
 * Test 1: max = 30, remove = 25
 * Test 2: max = 50, remove = 25
 * Test 3: max = 10, remove = 5
*/
#define MAX_ITEMS 30
#define REMOVE_ITEMS 25

// Ordered list class using a template.
template <class X>
class OrderedList {
protected:
    // Array of pointers holding max items of type X.
    X* array[MAX_ITEMS] = {};
    // Comparison and move counters.
    int compare_add = 0;
    int move_add = 0;
    int compare_remove = 0;
    int move_remove = 0;

public:
    // Create array of null pointers.
    OrderedList() {
        for (int i = 0; i < MAX_ITEMS; ++i) {
            array[i] = NULL;
        }
    }

    // Add item function that starts at front of array.
    void addItem(X item) {
        X temp = item;
        X temp2;
        // For loop to look at each item in array.
        for (int i = 0; i < MAX_ITEMS; ++i) {
            // If-else statements to move and add in item as needed.
            if (array[i] == NULL) {
                array[i] = new X; // Create new item.
                *array[i] = temp;
                break;
            }
            else if (*array[i] > item) {
                ++compare_add; // Compare array and item so add to comparison.
                temp2 = *array[i];
                *array[i] = temp;
                temp = temp2;
                ++move_add; // Move array items so add to move.
            }
            else {
                continue;
            }
        }
    }

    // Remove item function that keeps items in order and removes empty spots.
    void removeItem() {
        int i = 0;
        // Use rand function to find index of item to be removed.
        int index = rand() % MAX_ITEMS;
        // If position is null, find new index until number is found
        while (array[index] == NULL) {
            index = rand() % MAX_ITEMS;
        }
        // While loop add to i to continue moving through array.
        while ((i < MAX_ITEMS) && (index > i) && (array[i] != NULL)) {
            ++i;
        } 

        // If statement to remove item at given index.
        if (i == index) {
            ++compare_remove; // i compared to index so add to comparison.
            // While loop to move items to remove empty spaces.
            while ((array[i + 1] != NULL) && (i + 1 < MAX_ITEMS)) {
                *array[i] = *array[i + 1];
                ++move_remove; // Array items moved so add to move.
                ++i;
            }
            // Delete array item.
            delete array[i];
            array[i] = NULL;
        }
    }

    // Display function to display the final array.
    void display() {
        for (int i = 0; i < MAX_ITEMS; ++i) {
            if (array[i] != NULL) {
                cout << (*array[i]) << " ";
            }
        }
    }

    // Display comparison and move for the add item function.
    void displayCompAndMoveAddItem() {
        cout << endl << endl;
        cout << "Number of comparisons made in add item of ordered list: ";
        cout << compare_add << endl;
        cout << "Number of moves made in add item of ordered list: ";
        cout << move_add << endl;
    }

    // Display comparison and move for the remove item function.
    void displayCompAndMoveRemoveItem() {
        cout << endl << endl;
        cout << "Number of comparisons made in remove item of ordered list: ";
        cout << compare_remove << endl;
        cout << "Number of moves made in remove item of ordered list: ";
        cout << move_remove << endl;
    }

    // Is Empty boolean function that checks to see if the array is empty.
    bool isEmpty() {
        int empty_count = 0;
        for (int i = 0; i < MAX_ITEMS; ++i) {
            if (array[i] == NULL) {
                ++empty_count;
            }
        }
        if (empty_count == MAX_ITEMS) {
            return true;
        }
        else {
            return false;
        }
    }

    // Is Full boolean function checks to see if array is full.
    bool isFull() {
        int full_count = 0;
        for (int i = 0; i < MAX_ITEMS; ++i) {
            if (array[i] != NULL) {
                ++full_count;
            }
        }
        if (full_count == MAX_ITEMS) {
            return true;
        }
        else {
            return false;
        }
    }

    // Make empty function deletes items in array and points to null.
    void makeEmpty() {
        for (int i = 0; i < MAX_ITEMS; ++i) {
            if (array[i] != NULL) {
                delete array[i];
                array[i] = NULL;
            }
        }
    }

};

// Derived class to investigate adding from the ending (task 2) using template.
template <class Y>
class InvestigateEnding : public OrderedList<class X> {
protected:
    Y* array[MAX_ITEMS] = { };
    int compare_add = 0;
    int move_add = 0;
    int compare_remove = 0;
    int move_remove = 0;

public:
    // Create array of null pointers.
    InvestigateEnding() {
        for (int i = 0; i < MAX_ITEMS; ++i) {
            array[i] = NULL;
        }
    }

    // Add item function starts from end of array to insert new item.
    void addItem(Y item) {
        Y temp = item;
        Y temp2;
        // For loop starts from end of array.
        for (int i = MAX_ITEMS - 1; i >= 0; --i) {
            if (array[i] == NULL) {
                // Creates new item if position is null.
                array[i] = new Y;
                *array[i] = temp;
                break;
            }
            else if (*array[i] < item) {
                ++compare_add; // Compare item to array position so add to compare.
                temp2 = *array[i];
                *array[i] = temp;
                temp = temp2;
                ++move_add; // Move array items so add to move.
            }
            else {
                continue;
            }
        }
    }

    // Remove item function. Same as task 1
    void removeItem() {
        int i = 0;
        int index = rand() % MAX_ITEMS;
        while (array[index] == NULL) {
            index = rand() % MAX_ITEMS;
        }
        while ((i < MAX_ITEMS) && (index > i) && (array[i] != NULL)) {
            ++i;
        }

        if (i == index) {
            ++compare_remove;
            while ((array[i + 1] != NULL) && (i + 1 < MAX_ITEMS)) {
                *array[i] = *array[i + 1];
                ++move_remove;
                ++i;
            }
            delete array[i];
            array[i] = NULL;
        }
    }

    // 3 Display functions same as task 1.
    void display() {
        for (int i = 0; i < MAX_ITEMS; ++i) {
            if (array[i] != NULL) {
                cout << (*array[i]) << " ";
            }
        }
    }

    void displayCompAndMoveAddItem() {
        cout << endl << endl;
        cout << "Number of comparisons made in add item of ordered list: ";
        cout << compare_add << endl;
        cout << "Number of moves made in add item of ordered list: ";
        cout << move_add << endl;
    }

    void displayCompAndMoveRemoveItem() {
        cout << endl << endl;
        cout << "Number of comparisons made in remove item of ordered list: ";
        cout << compare_remove << endl;
        cout << "Number of moves made in remove item of ordered list: ";
        cout << move_remove << endl;
    }
};

// Derived class investigate leaving blank spots (task 3).
template <class Z>
class InvestigateBlank : public OrderedList<class X> {
protected:
    Z* array[MAX_ITEMS] = {};
    int compare_add = 0;
    int move_add = 0;
    int compare_remove = 0;
    int move_remove = 0;

public:
    // Create array of null pointers.
    InvestigateBlank() {
        for (int i = 0; i < MAX_ITEMS; ++i) {
            array[i] = NULL;
        }
    }

    // Add item function inserts halfway between.
    void addItem(Z item) {
        // If array is empty, new item at index 0.
        if (isEmpty() == true) {
            array[0] = new Z;
        }

        // If new item at index 0.
        if (array[0] != NULL) {
            ++compare_add; // Add to comparison.
            if (*array[0] > item) { // If first item is greater than inserted item
                // For loop to find null pointer.
                for (int i = 0; i < MAX_ITEMS; ++i) {
                    if (array[i] == NULL) { // Empty space.
                        // For loop to move items to the right.
                        for (int j = i; j >= 0; --j) {
                            ++move_add; // Add to move.
                            array[j] = array[j - 1];
                        }
                        break;
                    }
                }
                array[0] = new Z;
                return;
            }
        }

        // For loop to find if array element greater than item.
        for (int i = 0; i < MAX_ITEMS; ++i) {
            if (array[i] != NULL) { // If array item exists
                ++compare_add; // Add to comparison.
                if (*array[i] > item) {
                    if (array[i - 1] == NULL) {
                        // If null create new item.
                        array[i - 1] = new Z;
                        *array[i - 1] = item;
                        return;
                    }
                    int last_empty; // Find last null element.
                    for (int j = 0; j < MAX_ITEMS; ++j) {
                        if (array[j] == NULL) {
                            last_empty = j;
                        }
                    }
                    if (last_empty > i) { // Move items to right til last null space.
                        for (int j = last_empty; j >= i; --j) {
                            ++move_add; // Add to move.
                            array[j] = array[j - 1];
                        }
                        array[i] = new Z;
                        *array[i] = item;
                    }
                    else if (last_empty < i) { // Move items to left til null space.
                        for (int j = last_empty; j <= i - 1; ++j) {
                            ++move_add; // Add to move.
                            array[j] = array[j + 1];
                        }
                        array[i - 1] = new Z;
                        *array[i - 1] = item;
                    }
                    return;
                }
            }
        }

        if (array[MAX_ITEMS - 1] == NULL) {
            array[MAX_ITEMS - 1] = new Z;
            *array[MAX_ITEMS - 1] = item;
            return;
        }

        // Create empty item at the end of the list.
        int empty_item;
        for (int i = 0; i < MAX_ITEMS; ++i) {
            if (array[i] == NULL) {
                empty_item = i;
            }
            // Move items to left.
            for (int j = empty_item; j < MAX_ITEMS - 1; ++j) {
                ++move_add; // Add to move.
                array[j] = array[j + 1];
            }
            array[MAX_ITEMS - 1] = new Z;
            *array[MAX_ITEMS - 1] = item;
            return;
        }
    }

    // Remove item function that does not move items.
    void removeItem() {
        // Random index to remove random item.
        int index = rand() % MAX_ITEMS;
        // Find new random index if item is null.
        while (array[index] == NULL) {
            index = rand() % MAX_ITEMS;
        }
        // For loop to delete items without moving.
        for (int i = 0; i < MAX_ITEMS; ++i) {
            if (i == index) {
                ++compare_remove; // Add to comparison.
                delete array[index];
                array[index] = NULL;
            }
        }
    }

    // 3 display functions same as task 1 and 2.
    void display() {
        for (int i = 0; i < MAX_ITEMS; ++i) {
            if (array[i] != NULL) {
                cout << (*array[i]) << " ";
            }
        }
    }

    void displayCompAndMoveAddItem() {
        cout << endl << endl;
        cout << "Number of comparisons made in add item of ordered list: ";
        cout << compare_add << endl;
        cout << "Number of moves made in add item of ordered list: ";
        cout << move_add << endl;
    }

    void displayCompAndMoveRemoveItem() {
        cout << endl << endl;
        cout << "Number of comparisons made in remove item of ordered list: ";
        cout << compare_remove << endl;
        cout << "Number of moves made in remove item of ordered list: ";
        cout << move_remove << endl;
    }
};