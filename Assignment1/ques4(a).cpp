#include<iostream>
using namespace std;
void reverseArray(int arr[],int size){
   int start=0,end=size-1;
   while(start<=end){
      swap(arr[start],arr[end]);
      start++;
      end--;
   }
}
void printReverse(int arr[],int size){
     for(int i=0;i<size;i++){
      cout<<arr[i]<<"  ";
     }
}
int main(){
  int arr[100];
  int size;
  cout<<"Enter size of array: ";
  cin>>size;
  cout<<"Enter elements: ";
  for(int i=0;i<size;i++){
    cin>>arr[i];
  }
  reverseArray(arr,size);
  printReverse(arr,size);
  return 0;
}