#include <iostream>
using namespace std;

// Node class represents each element in the stack
class node {
public:
    int data;      // stores the data
    node *next;    // pointer to the next node
    node *prev;    // pointer to the previous node
};

// global head pointer (top of the stack)
node *head = NULL;

// Insert() adds a new element at the top of the stack
void Insert(int value) {

    // Create a new node dynamically
    node *newnode = new node;

    // Assign data to the new node
    newnode->data = value;

    // The new node will point to the current head (top element)
    newnode->next = head;

    // Since this new node will become the first element, its prev is NULL
    newnode->prev = NULL;

    // If the stack (list) is not empty, link the old head back to the new one
    if (head != NULL) {
        head->prev = newnode;
    }

    // Move head to the new node — this becomes the new top
    head = newnode;
}

int main() {

    // Push elements onto the stack
    Insert(200);
    Insert(300);
    Insert(400);
    Insert(500);

    // Print all elements from top to bottom
    node *temp = head;

    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}
