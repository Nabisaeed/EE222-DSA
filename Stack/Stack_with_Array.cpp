#include <iostream>
using namespace std;

#define MAX 5

class Stack{

    private: 

    int data[MAX];
    int top;

    public:

    Stack(){

        top=-1;
    }

    bool IsFull(){

        return top==MAX-1;
    }

    bool IsEmpty(){

        return top==-1;
    }

    void Push(int value){

        if(IsFull()){

            cout<<"cant' push "<<value<<"to stack Bcz Stack is Full"<<endl;
        return;
        }

        else{

            data[++top]=value;
        }


    }

    void display(){

        if(IsEmpty()){

            cout<<"The Stack is Empty"<<endl;
            return;
        }

        for(int i=top; i>=0; i--){

            cout<<data[top]<<endl;
            top--;
        }


    }

     void Top(){

            if(IsEmpty()){

                cout<<"The Stack is Empty"<<endl;
            }

            else{

                cout<<"The last element of Stack is : "<<data[top]<<endl;
            }
        }

        void Pop(){
            
            if(IsEmpty()){
                cout<<"The stack is Empty"<<endl;

            }

            else{

                cout<<"The popped element is :"<<data[top--]<<endl;
            }

        }



};

int main() {

    Stack s;

    s.Push(20);
    s.Push(30);
    s.Push(40);
    s.Push(50);
    s.Push(60);
    // s.display();
    // s.Top();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
  


    return 0;
}