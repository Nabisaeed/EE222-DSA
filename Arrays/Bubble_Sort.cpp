#include <iostream>
using namespace std;

int main() {

    int arr[]={12,7,3,25,100,123}, temp;

    for(int i=0; i<6; i++){

        for(int j=i+1;j<6; j++ ){

          if (arr[i]<arr[j]){

            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
          }


        }

    }


    for(int i=0; i<6; i++){

        cout<<arr[i]<<" ";
    }

    cout<<endl;
    
    return 0;
}