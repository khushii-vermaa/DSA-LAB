/*
Q3.
i. Write a program to find size of Doubly Linked List.
ii. Write a program to find size of Circular Linked List.
*/

#include <iostream>
using namespace std;

struct DNode { int data; DNode* prev; DNode* next; DNode(int v):data(v),prev(nullptr),next(nullptr){} };
struct CNode { int data; CNode* next; CNode(int v):data(v),next(nullptr){} };

int sizeDLL(DNode* head) {
    int cnt=0; for (DNode* t=head; t; t=t->next) cnt++; return cnt;
}

int sizeCLL(CNode* head) {
    if (!head) return 0;
    int cnt=0; CNode* t=head;
    do { cnt++; t=t->next; } while (t!=head);
    return cnt;
}

int main() {
    // Example for DLL
    DNode* dh = new DNode(1);
    dh->next = new DNode(2); dh->next->prev = dh;
    dh->next->next = new DNode(3); dh->next->next->prev = dh->next;
    cout<<"Size of example Doubly Linked List: "<<sizeDLL(dh)<<"\n";

    // Example for CLL
    CNode* ch = new CNode(10);
    ch->next = new CNode(20);
    ch->next->next = new CNode(30);
    ch->next->next->next = ch; // circular
    cout<<"Size of example Circular Linked List: "<<sizeCLL(ch)<<"\n";

    // You can replace examples with user input as needed.
    return 0;
}