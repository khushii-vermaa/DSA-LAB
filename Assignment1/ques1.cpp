// #include<iostream>
// using namespace std;
// int main(){
// int arr[100];
// int n=0;
// int choice;

// do{
// cout<<"\n Menu \n";
// cout<<"1. Create\n";
// cout<<"2. Display\n";
// cout<<"3.Insert\n";
// cout<<"4.Delete\n";
// cout<<"5.Linear Search\n";
// cout<<"6. Exit\n";

// cout<<"enter your choice: ";
// cin>>choice;

// if(choice==1){
// cout<<"enter the number of elements: ";
// cin>>n;
// cout<<"the elements";
// for(int i=0;i<n;i++){
// cin>>arr[i];
// }
// }
// else if(choice==2){
// if(n==0) cout<<"empty\n";
// else{
// cout<<"array elements: ";
// for(int i=0;i<n;i++){
// cout<<arr[i]<<" ";
// }
// }
// }
// else if(choice==3){
// int pos, val;
// cout<<"enter the value: ";
// cin>>val;
// cout<<"enter the position: ";
// cin>>pos;
// if(pos<0||pos>n)
// cout<<"invalid";
// else{
// for(int i=n;i>pos;i--){
// arr[i]=arr[i-1];
// }
// arr[pos]=val;
// n++;
// }
// }
// else if(choice==4){
// int pos;
// cout<<"enter the position: ";
// cin>>pos;

// if(pos<0||pos>n)
// cout<<"error";
// else{
// for(int i=pos; i<n-1;i--){
// arr[i]=arr[i+1];
// }
// n--;
// }
// }
// else if(choice==5){
// int key, found =0;
// cout<<"enter element to search ";
// cin>>key;

// for(int i=0;i<n;i++){
// if(arr[i]== key){
// cout<<"element found here!!"<<i<<endl;
// found=1;
// break;
// }
// }
// if(found==0)
// cout<<"not found";
// }
// else if(choice==6){
// cout<<"exit\n";
// }

// else{
// cout<<"invalid choice\n";
// }

// } while(choice !=6);
// return 0;
// }