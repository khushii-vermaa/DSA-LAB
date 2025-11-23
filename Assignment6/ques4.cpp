/*
Q4. Write a program to check if a doubly linked list of characters is palindrome or not.
Example Input/Output: True or False
*/

#include <iostream>
using namespace std;

struct Node { char data; Node* prev; Node* next; Node(char v):data(v),prev(nullptr),next(nullptr){} };

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* tail = head;
    while (tail->next) tail = tail->next;
    Node* l = head; Node* r = tail;
    while (l != r && l->prev != r) {
        if (l->data != r->data) return false;
        l = l->next; r = r->prev;
    }
    return true;
}

int main() {
    string s;
    cout<<"Enter string to insert into DLL: "; cin>>s;
    if (s.empty()) { cout<<"True\n"; return 0; }
    Node* head = new Node(s[0]); Node* t = head;
    for (size_t i=1;i<s.size();++i){ t->next = new Node(s[i]); t->next->prev = t; t = t->next; }
    cout<<(isPalindrome(head) ? "True\n" : "False\n");
    return 0;
}