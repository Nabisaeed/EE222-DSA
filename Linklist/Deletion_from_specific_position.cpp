#include <iostream>
using namespace std;

// Node structure
class node {
public:
    int data;
    node* next;
};

// Global head pointer
node* head = NULL;

// Function to insert a node at the beginning
void Insert(int n) {
    node* newnode = new node;
    newnode->data = n;
    newnode->next = head;
    head = newnode;
}

// Function to display all nodes
void display() {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to delete a node at a specific position
void delete_specific(int pos) {
    // Case 1: Empty list
    if (head == NULL) {
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }

    // Case 2: Delete the head node
    if (pos == 1) {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Traverse to (pos-1)th node
    node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is invalid
    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Adjust links and delete target node
    node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

int main() {
    // Inserting nodes (List = 700 -> 500 -> 200)
    Insert(200);
    Insert(500);
    Insert(700);

    // Delete node at position 3 (deletes 200)
    delete_specific(3);

    // Display remaining list
    display();

    return 0;
}
