#include <iostream>
using namespace std;

int main() {

    int arr[]={12,34,56,78,90}, pos;

    cout<<"Enter the position from which yxou want to remove an element"<<endl;
    cin>>pos;

    for(int i=pos-1; i<5; i++){

        arr[i]=arr[i+1];
    }

    for(int i=0; i<4; i++){

        cout<<arr[i]<<" ";
    }

    cout<<endl;


    
    return 0;
}