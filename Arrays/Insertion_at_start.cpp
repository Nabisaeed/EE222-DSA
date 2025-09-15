#include <iostream>
using namespace std;



int main() {

   

    int arr[10]={12,34,50,100,120}, num;

    int n=5;

    cout<<"Enter the number you want to insert in the start"<<endl;
    cin>>num;

    for(int i=n; i>0; i--){

        arr[i]=arr[i-1];
    }

    arr[0]=num;

    n++;


    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;


    
    return 0;
}