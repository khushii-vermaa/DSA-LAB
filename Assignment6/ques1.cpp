/*
UCS301 – Data Structures
Lab Assignment 6 : Doubly and Circular Linked List

Q1. Develop a menu-driven program for the following operations on a Circular
    as well as a Doubly Linked List.

    (a) Insertion anywhere in the linked list
        (as first node, as last node, and after/before a specific node)

    (b) Deletion of a specific node (e.g., Delete Node 60)
        The node to be deleted may appear as head, last, or a node in between.

    (c) Search for a node.
*/

#include <iostream>
using namespace std;

struct DNode {
    int data; DNode* prev; DNode* next;
    DNode(int v): data(v), prev(nullptr), next(nullptr) {}
};

struct CNode {
    int data; CNode* next;
    CNode(int v): data(v), next(nullptr) {}
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList(): head(nullptr) {}
    void insertAtBeginning(int v) {
        DNode* n = new DNode(v);
        if (!head) { head = n; return; }
        n->next = head; head->prev = n; head = n;
    }
    void insertAtEnd(int v) {
        DNode* n = new DNode(v);
        if (!head) { head = n; return; }
        DNode* t = head; while (t->next) t = t->next;
        t->next = n; n->prev = t;
    }
    void insertAfter(int key, int v) {
        DNode* t = head; while (t && t->data != key) t = t->next;
        if (!t) { cout<<"Node "<<key<<" not found.\n"; return; }
        DNode* n = new DNode(v);
        n->next = t->next; n->prev = t; if (t->next) t->next->prev = n; t->next = n;
    }
    void insertBefore(int key, int v) {
        if (!head) return;
        if (head->data == key) { insertAtBeginning(v); return; }
        DNode* t = head; while (t && t->data != key) t = t->next;
        if (!t) { cout<<"Node "<<key<<" not found.\n"; return; }
        DNode* n = new DNode(v);
        n->next = t; n->prev = t->prev; t->prev->next = n; t->prev = n;
    }
    void deleteNode(int key) {
        if (!head) { cout<<"List is empty.\n"; return; }
        DNode* t = head;
        if (t->data == key) {
            head = head->next; if (head) head->prev = nullptr; delete t; cout<<"Node deleted.\n"; return;
        }
        while (t && t->data != key) t = t->next;
        if (!t) { cout<<"Node not found.\n"; return; }
        if (t->next) t->next->prev = t->prev;
        t->prev->next = t->next;
        delete t; cout<<"Node deleted.\n";
    }
    void search(int key) {
        DNode* t = head; int pos = 1;
        while (t) { if (t->data == key) { cout<<"Node found at position "<<pos<<".\n"; return; } t = t->next; pos++; }
        cout<<"Node not found.\n";
    }
    void display() {
        if (!head) { cout<<"List is empty.\n"; return; }
        cout<<"DLL: "; for (DNode* t = head; t; t = t->next) cout<<t->data<<" "; cout<<"\n";
    }
};

class CircularLinkedList {
    CNode* head;
public:
    CircularLinkedList(): head(nullptr) {}
    void insertAtBeginning(int v) {
        CNode* n = new CNode(v);
        if (!head) { head = n; head->next = head; return; }
        CNode* t = head; while (t->next != head) t = t->next;
        t->next = n; n->next = head; head = n;
    }
    void insertAtEnd(int v) {
        CNode* n = new CNode(v);
        if (!head) { head = n; head->next = head; return; }
        CNode* t = head; while (t->next != head) t = t->next;
        t->next = n; n->next = head;
    }
    void insertAfter(int key, int v) {
        if (!head) return;
        CNode* t = head;
        do { if (t->data == key) { CNode* n = new CNode(v); n->next = t->next; t->next = n; return; } t = t->next; } while (t != head);
        cout<<"Node not found.\n";
    }
    void deleteNode(int key) {
        if (!head) { cout<<"List is empty.\n"; return; }
        if (head->data == key && head->next == head) { delete head; head = nullptr; return; }
        if (head->data == key) {
            CNode* last = head; while (last->next != head) last = last->next;
            CNode* tmp = head; head = head->next; last->next = head; delete tmp; return;
        }
        CNode* prev = head; CNode* curr = head->next;
        while (curr != head) {
            if (curr->data == key) { prev->next = curr->next; delete curr; return; }
            prev = curr; curr = curr->next;
        }
        cout<<"Node not found.\n";
    }
    void search(int key) {
        if (!head) { cout<<"List is empty.\n"; return; }
        CNode* t = head; int pos = 1;
        do { if (t->data == key) { cout<<"Node found at position "<<pos<<".\n"; return; } t = t->next; pos++; } while (t != head);
        cout<<"Node not found.\n";
    }
    void display() {
        if (!head) { cout<<"List is empty.\n"; return; }
        cout<<"CLL: "; CNode* t = head;
        do { cout<<t->data<<" "; t = t->next; } while (t != head);
        cout<<"\n";
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int listType, choice, key, val;
    while (true) {
        cout<<"\n1. Doubly Linked List\n2. Circular Linked List\n3. Exit\nChoose list type: "; cin>>listType;
        if (listType == 3) break;
        cout<<"\nOperations:\n1.Insert at Beginning\n2.Insert at End\n3.Insert After\n";
        if (listType == 1) cout<<"4.Insert Before (DLL only)\n";
        cout<<"5.Delete Node\n6.Search Node\n7.Display\n8.Back\nChoice: "; cin>>choice;
        if (listType == 1) {
            switch(choice) {
                case 1: cout<<"Value: "; cin>>val; dll.insertAtBeginning(val); break;
                case 2: cout<<"Value: "; cin>>val; dll.insertAtEnd(val); break;
                case 3: cout<<"Key Value: "; cin>>key>>val; dll.insertAfter(key,val); break;
                case 4: cout<<"Key Value: "; cin>>key>>val; dll.insertBefore(key,val); break;
                case 5: cout<<"Value to delete: "; cin>>val; dll.deleteNode(val); break;
                case 6: cout<<"Value to search: "; cin>>val; dll.search(val); break;
                case 7: dll.display(); break;
            }
        } else if (listType == 2) {
            switch(choice) {
                case 1: cout<<"Value: "; cin>>val; cll.insertAtBeginning(val); break;
                case 2: cout<<"Value: "; cin>>val; cll.insertAtEnd(val); break;
                case 3: cout<<"Key Value: "; cin>>key>>val; cll.insertAfter(key,val); break;
                case 5: cout<<"Value to delete: "; cin>>val; cll.deleteNode(val); break;
                case 6: cout<<"Value to search: "; cin>>val; cll.search(val); break;
                case 7: cll.display(); break;
            }
        }
    }
    return 0;
}