#include <iostream>
using namespace std;



int main() {

   

    int arr[10]={12,34,50,100,120}, num,pos;

    int n=5;

    cout<<"Enter the number you want to insert in the start"<<endl;

    cin>>num;

    cout<<"Enter the position at which you want to insert the elemenet"<<endl;

    cin>>pos;


    for(int i=n; i>pos-1; i--){

        arr[i]=arr[i-1];
    }

    arr[pos-1]=num;

    n++;


    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;


    
    return 0;
}