#include <iostream>
using namespace std;

void InsertionSort(int A[], int size){

    for(int i=1; i<size; i++){

        int key=A[i];

        int j=i-1; 

        while(j>=0 && A[j]>key){

            A[j+1]=A[j];

            j--;
        }

        A[j+1]= key;


    }
}

int main() {

    int arr[]={7,23,40,2,11};


    InsertionSort(arr,5);


    for(int i=0; i<5; i++){

         cout<<arr[i]<<" ";
    }

    cout<<endl;


    
    return 0;
}