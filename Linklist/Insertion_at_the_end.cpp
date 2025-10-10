#include <iostream>
using namespace std;

// Define a node class for singly linked list
class node {
public:
    int data;      // To store data of the node
    node* next;    // Pointer to the next node
};

// Global head pointer (points to the first node of the list)
node* head = NULL;

// ===========================================================
// FUNCTION: Insert
// PURPOSE: Insert a new node at the beginning of the list
// ===========================================================
void Insert(int n) {
    node* newnode = new node;   // Allocate memory for new node
    newnode->data = n;          // Store data in new node
    newnode->next = head;       // Link new node to current head
    head = newnode;             // Move head to new node (new first node)
}

// ===========================================================
// FUNCTION: display
// PURPOSE: Display all nodes in the linked list
// ===========================================================
void display() {
    node* temp = head;          // Temporary pointer for traversal

    while (temp != NULL) {      // Traverse until the end of list
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ===========================================================
// FUNCTION: Inser_at_end
// PURPOSE: Insert a new node at the end of the linked list
// ===========================================================
void Inser_at_end(int n) {
    node* newnode = new node;   // Create new node
    newnode->data = n;
    newnode->next = NULL;       // Last node points to NULL

    // Case 1: If the list is empty
    if (head == NULL) {
        head = newnode;
        return;
    }

    node* temp = head;

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;       // Link last node to new node
}

// ===========================================================
// FUNCTION: Insertion_at_specific_point
// PURPOSE: Insert a new node at a specific position (1-based index)
// ===========================================================
void Insertion_at_specific_point(int n, int pos) {
    node* newnode = new node;
    newnode->data = n;

    // Case 1: Insert at beginning
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    node* temp = head;

    // Traverse to the node before desired position
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is invalid
    if (temp == NULL) {
        cout << "Invalid Position" << endl;
        delete newnode;
        return;
    }

    // Insert new node in between nodes
    newnode->next = temp->next;
    temp->next = newnode;
}

// ===========================================================
// MAIN FUNCTION
// ===========================================================
int main() {
    // Inserting nodes at the start
    Insert(200);
    Insert(300);
    Insert(400);
    Insert(500);

    // Insert at a specific position (3rd position)
    Insertion_at_specific_point(140, 3);

    // Insert at the end
    Inser_at_end(700);

    // Display the linked list
    display();

    return 0;
}
