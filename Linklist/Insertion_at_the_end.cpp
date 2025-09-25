#include <iostream>
using namespace std;

class node{

    public:

    int data;
    node *next;
};


node *head=NULL;


void Insert(int n){

    node *newnode= new node;

    newnode->data=n;
    newnode->next=head;
    head=newnode;
    

}

void display(){

    node *temp=head;

    while(temp!=NULL){

        cout<<temp->data<<" ";

        temp=temp->next;
    }

    cout<<endl;
}

void Inser_at_end(int n){

    node *newnode= new node;

    newnode->data=n;

    newnode->next=NULL;

    node *temp=head;

    while(temp->next!=NULL){

        temp=temp->next;
    }

    temp->next=newnode;


}

void Insertion_at_specific_point(int n, int pos){

    node *newnode= new node;
    newnode->data=n;

    node *temp=head;

    for(int i=1; i<pos-1 && temp!=NULL; i++){

        temp=temp->next;


    }

    if(temp==NULL){

        cout<<"Invalid Position"<<endl;
    }

    newnode->next=temp->next;
    temp->next=newnode;



}
int main() {

    Insert(200);
    Insert(300);
    Insert(400);
    Insert(500);

    Insertion_at_specific_point(140,3);
    Inser_at_end(700);
    display();

    

    return 0;
}