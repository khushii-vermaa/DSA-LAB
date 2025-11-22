/*Design the Logic to Find a Missing Number in a Sorted Array. Given an array of n-1
distinct integers in the range of 1 to n, find the missing number in it in a Sorted Array
(a) Linear time
(b) Using binary search.*/

#include <iostream>
using namespace std;
int MissingNum(int *arr,int n){
    int sum1= ((n+1)*(n+2))/2;
    
    int sum2=0;
    for(int i=0; i<n; i++){
        sum2 += arr[i];
        }
        
        return sum1-sum2;
        
        //Time Complexity: O(n)
}

int MissingNum2(int *arr, int n){
    int low=0;
    int high=n-1;
    
    while(low<=high){
        int mid= low+(high-low)/2;
        
        
        if((arr[mid] != (mid+1)) && (arr[mid-1] == mid)){
            return mid+1;
        }
        
        else if(arr[mid]==(mid+1)){
            low=mid+1;
           
        }
        
        else{
            high=mid-1;
           
        }
    }
    return -1;
    //Time Complexity: O(log(n))
}

int main()
{
    int arr[5]={1,2,3,5,6};
    
    int size=sizeof(arr)/sizeof(arr[0]);
    
    int num=MissingNum2(arr,size);
    cout<<"The Missing Number is: "<<num;

    return 0;
}