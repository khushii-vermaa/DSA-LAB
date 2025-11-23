/*
Q2. Display all the node values in a circular linked list, repeating value of head node at the end too.

Input example: 20 -> 100 -> 40 -> 80 -> 60
Output: 20 100 40 80 60 20
*/

#include <iostream>
#include <vector>
using namespace std;

struct Node { int data; Node* next; Node(int v): data(v), next(nullptr) {} };

int main() {
    int n;
    cout<<"Enter number of nodes: "; cin>>n;
    if (n <= 0) { cout<<"No nodes.\n"; return 0; }
    vector<int> vals(n);
    cout<<"Enter values: ";
    for (int i=0;i<n;i++) cin>>vals[i];

    Node* head = new Node(vals[0]);
    Node* t = head;
    for (int i=1;i<n;i++) { t->next = new Node(vals[i]); t = t->next; }
    t->next = head; // make circular

    // print nodes and repeat head
    Node* temp = head;
    do {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp != head);
    // print head again
    cout<<head->data<<"\n";
    return 0;
}