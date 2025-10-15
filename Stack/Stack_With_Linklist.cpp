#include <iostream>
using namespace std;

class node{

    public:
    int data;
    node *next;
};

node *top=NULL;

bool IsEmpty(){

    return top==NULL;
}

void push(int value){

    node *newelement= new node;
    newelement->data=value;
    newelement->next=top;
    top=newelement;
}

void display(){

    if(IsEmpty()){

        cout<<"The Stack is Empty"<<endl;
        return;
    }

    node *temp=top;
    while(temp!=NULL){
    cout<<temp->data<<endl;
    temp=temp->next;
}
}

void pop(){

    if(IsEmpty()){

        cout<<"The Stack is Empty"<<endl;
        return;
    }

    node *temp=top;
    top=top->next;
    cout<<"The popped element is :"<<temp->data<<endl;
    delete temp;
}

void Top(){

    if(IsEmpty()){

        cout<<"The Stack is empty"<<endl;
        return;
    }

    cout<<"The last element in the Stack is "<<top->data<<endl;
}


int main() {

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    // display();
    // pop();
    // pop();
    // pop();
    // pop();
    // pop();
    // pop();

    Top();
    

    return 0;
}