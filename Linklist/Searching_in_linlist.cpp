#include <iostream>
using namespace std;

// Node structure for singly linked list
class node {
public:
    int data;     // stores data value
    node *next;   // pointer to next node
};

// Global head pointer (points to the start/top of list)
node *head = NULL;

// Insert() adds a new node at the beginning (like push in stack)
void Insert(int n) {
    node *newnode = new node;   // dynamically allocate new node
    newnode->data = n;          // assign value
    newnode->next = head;       // link new node to previous head
    head = newnode;             // move head to the new node
}

// search() finds a specific value and returns its position (1-based index)
// returns -1 if not found
int search(int target) {
    node *temp = head;
    int i = 1;

    while (temp != NULL) {
        if (temp->data == target) {
            return i;   // value found at position i
        }
        temp = temp->next;
        i++;
    }

    return -1;  // not found
}

// display() prints all elements in the linked list
void display() {
    node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    // Inserting nodes (elements)
    Insert(200);
    Insert(500);
    Insert(700);

    // Searching for a value
    int index = search(1200);

    if (index >= 1) {
        cout << "The node is found at position: " << index << endl;
    } else {
        cout << "The value is not found" << endl;
    }

    // display(); // optional: print all elements

    return 0;
}
