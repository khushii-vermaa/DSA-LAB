/*Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping
the adjacent elements if they are in wrong order. Code the Bubble sort with the
following elements:
64 34 25 12 22 11 90*/

#include <iostream>
using namespace std;

void Swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void Bubble_Sort(int *arr, int n){
    
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                Swap(arr[j],arr[j+1]);
            }
        }
    }
    
    
}

int main()
{
   int arr[7]={64,34,25,12,22,11,90};
   int n=sizeof(arr)/sizeof(arr[0]);
   Bubble_Sort(arr,n);
   cout<<"Sorted Array: "<<endl;
   for(int i=0; i<n; i++){
       cout<<arr[i]<<"\t";
   }
    return 0;
}