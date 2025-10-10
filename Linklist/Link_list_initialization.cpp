#include <iostream>
using namespace std;

// Node structure definition
class node {
public:
    int data;     // Holds the data value of the node
    node* next;   // Pointer to the next node in the list
};

// Global pointer to the first node (head of the linked list)
node* head = NULL;

// ===========================================================
// FUNCTION: Insert
// PURPOSE: Inserts a new node at the beginning of the linked list
// ===========================================================
void Insert(int n) {
    // Create a new node dynamically
    node* newnode = new node;

    // Assign data to the new node
    newnode->data = n;

    // Link the new node to the current head
    newnode->next = head;

    // Update head to the new node
    head = newnode;
}

// ===========================================================
// FUNCTION: display
// PURPOSE: Traverses and prints all elements of the linked list
// ===========================================================
void display() {
    node* temp = head;  // Temporary pointer to traverse the list

    // Traverse until the end (NULL)
    while (temp != NULL) {
        cout << temp->data << " ";  // Print data of the current node
        temp = temp->next;          // Move to next node
    }

    cout << endl;  // New line after printing all nodes
}

// ===========================================================
// MAIN FUNCTION
// PURPOSE: Demonstrates basic linked list insertion and display
// ===========================================================
int main() {
    Insert(200);   // Insert node with value 200 at beginning
    Insert(500);   // Insert node with value 500 at beginning
    Insert(700);   // Insert node with value 700 at beginning

    display();     // Display current linked list

    return 0;
}
