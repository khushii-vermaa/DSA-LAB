#include<iostream>
using namespace std;
int main(){
    int arr[10][10], transpose[10][10];
    int rows, cols;
    cout<<"enter the rows and columns: ";
    cin>>rows>>cols;
    
    cout<<"enter the elements of matrix: ";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            transpose[j][i]= arr[i][j];
        }
    }
    cout<<"the transpose is: ";
    for(int i=0;i<cols;i++){
        for(int j=0;j< rows;j++){
            cout<<transpose[i][j]<<" ";
        }
    }
return 0; 
}