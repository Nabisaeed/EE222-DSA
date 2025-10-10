#include <iostream>
using namespace std;

// Node structure for Circular Singly Linked List
class node {
public:
    int data;
    node* next; // Pointer to the next node in the list
};

// Head pointer (global for simplicity)
node* head = nullptr;

// ===========================================================
// INSERTION FUNCTIONS
// ===========================================================

// Insert a new node at the beginning of the list
void insertAtStart(int value) {
    node* newnode = new node;
    newnode->data = value;

    // Case 1: If the list is empty, new node will point to itself
    if (head == nullptr) {
        newnode->next = newnode; // Self-loop
        head = newnode;
        return;
    }

    // Case 2: Traverse to the last node to maintain circular property
    node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    // Connect last node to new node
    temp->next = newnode;

    // New node points to the old head
    newnode->next = head;

    // Update head to the new node (new first node)
    head = newnode;
}

// Insert a new node at the end of the list
void insertAtEnd(int value) {
    node* newnode = new node;
    newnode->data = value;

    // Case 1: Empty list → make it circular
    if (head == nullptr) {
        newnode->next = newnode;
        head = newnode;
        return;
    }

    // Case 2: Traverse to last node
    node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    // Insert new node after the last node
    temp->next = newnode;
    newnode->next = head; // Maintain circular connection
}

// Insert at a specific position (1-based index)
void insertAtPosition(int pos, int value) {
    // If inserting at start
    if (pos == 1) {
        insertAtStart(value);
        return;
    }

    node* newnode = new node;
    newnode->data = value;

    node* temp = head;
    int count = 1;

    // Traverse until just before the desired position
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    // Insert the new node in between nodes
    newnode->next = temp->next;
    temp->next = newnode;
}

// ===========================================================
// DELETION FUNCTIONS
// ===========================================================

// Delete node from the beginning
void deleteAtStart() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    // Case 1: Only one node in list
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    // Case 2: Multiple nodes
    node* temp = head;
    node* last = head;

    // Traverse to last node (to maintain circular link)
    while (last->next != head)
        last = last->next;

    // Move head forward and relink the last node
    head = head->next;
    last->next = head;

    // Delete old head
    delete temp;
}

// Delete node from the end
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
    node* temp = head;
    node* prev = nullptr;

    // Traverse to last node while keeping track of previous
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    // Previous node becomes new last node
    prev->next = head;
    delete temp;
}

// Delete node from a specific position
void deleteAtPosition(int pos) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    // Delete first node
    if (pos == 1) {
        deleteAtStart();
        return;
    }

    node* temp = head;
    node* prev = nullptr;
    int count = 1;

    // Traverse until target position
    while (count < pos && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    // If position is invalid (greater than number of nodes)
    if (count < pos) {
        cout << "Invalid position!\n";
        return;
    }

    // Bypass and delete target node
    prev->next = temp->next;
    delete temp;
}

// ===========================================================
// DISPLAY FUNCTION
// ===========================================================

// Display all nodes in the circular linked list
void display() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head); // Stop when we loop back to the head
    cout << endl;
}

// ===========================================================
// MAIN FUNCTION
// ===========================================================
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtStart(5);
    display();

    // Uncomment to test other operations
    // insertAtPosition(3, 15);
    // display();

    // deleteAtStart();
    // display();

    // deleteAtEnd();
    // display();

    // deleteAtPosition(2);
    // display();

    return 0;
}
