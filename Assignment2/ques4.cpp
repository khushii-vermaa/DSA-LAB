/*String Related Programs
(a) Write a program to concatenate one string to another string.
(b) Write a program to reverse a string.
(c) Write a program to delete all the vowels from the string.
(d) Write a program to sort the strings in alphabetical order.
(e) Write a program to convert a character from uppercase to lowercase.*/

#include <iostream>
#include <string>
using namespace std;
void Swapchar(char &ch1, char &ch2){
    char temp=ch1;
    ch1=ch2;
    ch2=temp;
    }
    
    void SwapString(string &ch1, string &ch2){
    string temp=ch1;
    ch1=ch2;
    ch2=temp;
    }
    
    
void Con_Cat(string &str1, string &str2){
    str1= str1+" "+str2;
}

void ReverseStrBychar(string &str){
    int n=str.length();
    
    for(int i=0; i<n/2; i++){
        Swapchar(str[i],str[n-i-1]);
    }
}

    
void ReverseStrByString(string &str){
    int n=str.length();
    string word="";
    string res="";
    
    for(int i=n-1; i>=0; i--){
       if(str[i] != ' '){
           word = str[i]+word;
    }
    
    else{
        res += word+" ";
        word ="";
}
}

 if(!word.empty()){
     res += word;
 }
 str=res;
}

bool isvowel(char ch){
    if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
       ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
           return true; 
       }
       return false;
}

void DeleteVowels(string &str){
    int n= str.length();
    int i=0, j=0;
    while(i<n){
        if(!isvowel(str[i])){
            str[j++]=str[i];
         }
        i++;
     }
     str.resize(j);
 }
 
 void SortStrings(string *arr, int n){
     
     
     for(int i=0; i<n-1; i++){
         for(int j= 0; j<n-i-1; j++){
             if(arr[j]>arr[j+1]){
                 SwapString(arr[j],arr[j+1]);
             }
         }
     }
     
 }
 
 void Uppercase2Lowercase(string &s){
     int n=s.length();
     for(int i=0; i<n; i++){
         if(s[i]>= 'A' && s[i]<= 'Z'){
             s[i] = s[i]+('a'-'A');
         }
     }
 }

int main()
{
    string str1="Hello";
    string str2="Main";
    Con_Cat(str1,str2);
    cout<<str1;
    cout<<endl;
    ReverseStrByString(str1);
    cout<<str1<<endl;
    DeleteVowels(str1);
    cout<<str1;
    cout<<endl;
    
    string arr[5]={"apple", "mango", "lichi", "guava", "tomato"};
    int n= sizeof(arr)/sizeof(arr[0]);
    SortStrings(arr,n);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<endl;
    }
    
    Uppercase2Lowercase(str2);
    cout<<str2;
    
    return 0;
}