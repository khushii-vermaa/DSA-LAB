/*
Q5. Write a program to check if a linked list is Circular Linked List or not.
Example: LinkedList: 2->4->6->7->5  Output: True (if circular)
*/

#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };

// Using Floyd's cycle detection
bool isCircular(Node* head) {
    if (!head) return false;
    Node* slow = head; Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next; fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    // Example: create circular list 1->2->3->1
    Node* h = new Node(1); h->next = new Node(2); h->next->next = new Node(3); h->next->next->next = h;
    cout<<(isCircular(h) ? "True\n" : "False\n");

    // Example: non-circular
    Node* p = new Node(10); p->next = new Node(20); p->next->next = new Node(30);
    cout<<(isCircular(p) ? "True\n" : "False\n");
    return 0;
}