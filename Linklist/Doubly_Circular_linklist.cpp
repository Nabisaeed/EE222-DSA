#include <iostream>
using namespace std;

// ===========================================================
// Node structure for Circular Doubly Linked List
// Each node points both to its next and previous nodes
// ===========================================================
class node {
public:
    int data;       // Holds node data
    node* next;     // Pointer to the next node
    node* prev;     // Pointer to the previous node
};

// Global head pointer for simplicity
node* head = nullptr;

// ===========================================================
// INSERTION FUNCTIONS
// ===========================================================

// Insert a new node at the beginning of the list
void insertAtStart(int value) {
    node* newnode = new node;   // Create a new node dynamically
    newnode->data = value;

    // Case 1: If the list is empty
    if (head == nullptr) {
        newnode->next = newnode; // Self-loop for both next and prev
        newnode->prev = newnode;
        head = newnode;          // Head points to the new node
        return;
    }

    // Case 2: If list is not empty
    node* last = head->prev;     // Access last node using head->prev

    // Connect newnode between last and current head
    newnode->next = head;        // newnode's next = current head
    newnode->prev = last;        // newnode's prev = last node

    // Adjust existing links
    last->next = newnode;        // last node’s next = newnode
    head->prev = newnode;        // head’s prev = newnode

    // Update head to the new node (new start of the list)
    head = newnode;
}

// Insert a new node at the end of the list
void insertAtEnd(int value) {
    node* newnode = new node;
    newnode->data = value;

    // Case 1: Empty list → newnode forms a self-loop
    if (head == nullptr) {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
        return;
    }

    // Case 2: Non-empty list
    node* last = head->prev;     // Access last node via head->prev

    // Connect new node between last and head
    newnode->next = head;
    newnode->prev = last;

    last->next = newnode;
    head->prev = newnode;
}

// Insert a node at a specific position (1-based index)
void insertAtPosition(int pos, int value) {
    // If position <= 1 → treat as insertion at start
    if (pos <= 1) {
        insertAtStart(value);
        return;
    }

    node* newnode = new node;
    newnode->data = value;

    node* temp = head;
    int count = 1;

    // Traverse to (pos-1)th node or until we loop back to head
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    // temp is now the node after which we insert the new node
    node* nextnode = temp->next;

    // Adjust links to insert newnode in between temp and nextnode
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = nextnode;
    nextnode->prev = newnode;
}

// ===========================================================
// DELETION FUNCTIONS
// ===========================================================

// Delete the first node in the list
void deleteAtStart() {
    if (head == nullptr) { // Empty list check
        cout << "List is empty!\n";
        return;
    }

    // Case 1: Only one node present
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    // Case 2: Multiple nodes
    node* last = head->prev; // Get the last node
    node* temp = head;       // Store old head for deletion

    head = head->next;       // Move head forward
    head->prev = last;       // Connect new head’s prev to last
    last->next = head;       // Connect last’s next to new head

    delete temp;             // Delete the old head node
}

// Delete the last node in the list
void deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    // Case 1: Only one node
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    // Case 2: More than one node
    node* last = head->prev;         // Access last node
    node* secondLast = last->prev;   // Node before last

    // Update links
    secondLast->next = head;
    head->prev = secondLast;

    delete last;                     // Delete old last node
}

// Delete a node from a specific position
void deleteAtPosition(int pos) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    // Deleting the first node
    if (pos == 1) {
        deleteAtStart();
        return;
    }

    node* temp = head;
    int count = 1;

    // Traverse to the target position
    while (count < pos && temp->next != head) {
        temp = temp->next;
        count++;
    }

    // If position is invalid
    if (count < pos) {
        cout << "Invalid position!\n";
        return;
    }

    // Relink the surrounding nodes
    node* prevnode = temp->prev;
    node* nextnode = temp->next;

    prevnode->next = nextnode;
    nextnode->prev = prevnode;

    // Edge case: if head itself is deleted (rare but safe)
    if (temp == head)
        head = nextnode;

    delete temp; // Free memory
}

// ===========================================================
// DISPLAY FUNCTION
// ===========================================================

// Display the elements of the circular doubly linked list
void display() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    node* temp = head;
    cout << "Circular Doubly Linked List: ";

    // Use do-while loop since it's circular
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

// ===========================================================
// MAIN FUNCTION (Demonstration)
// ===========================================================
int main() {
    // Demonstrate various insertions
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtStart(5);
    insertAtPosition(3, 15);
    display();  // Expected output: 5 10 15 20 30

    // Demonstrate deletions
    deleteAtStart();
    display();  // Expected: 10 15 20 30

    deleteAtEnd();
    display();  // Expected: 10 15 20

    deleteAtPosition(2);
    display();  // Expected: 10 20

    return 0;
}
