/*Develop a menu driven program for the following operations on a Singly Linked
List.
(a) Insertion at the beginning.
(b) Insertion at the end.
(c) Insertion in between (before or after a node having a specific value, say 'Insert a
new Node 35 before/after the Node 30').
(d) Deletion from the beginning.
(e) Deletion from the end.
(f) Deletion of a specific node, say 'Delete Node 60').
(g) Search for a node and display its position from head.
(h) Display all the node values.*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// (a) Insert at beginning
void insertBeginning(int val) {
    Node* n = new Node{val, head};
    head = n;
}

// (b) Insert at end
void insertEnd(int val) {
    Node* n = new Node{val, nullptr};
    if (!head) { head = n; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
}

// (c) Insert before a specific value
void insertBefore(int key, int val) {
    if (!head) { cout << "List empty\n"; return; }
    if (head->data == key) { insertBeginning(val); return; }
    Node* temp = head;
    while (temp->next && temp->next->data != key) temp = temp->next;
    if (!temp->next) { cout << "Key not found\n"; return; }
    Node* n = new Node{val, temp->next};
    temp->next = n;
}

// (c) Insert after a specific value
void insertAfter(int key, int val) {
    Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) { cout << "Key not found\n"; return; }
    Node* n = new Node{val, temp->next};
    temp->next = n;
}

// (d) Delete from beginning
void deleteBeginning() {
    if (!head) { cout << "List empty\n"; return; }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// (e) Delete from end
void deleteEnd() {
    if (!head) { cout << "List empty\n"; return; }
    if (!head->next) { delete head; head = nullptr; return; }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

// (f) Delete a specific node
void deleteValue(int key) {
    if (!head) { cout << "List empty\n"; return; }
    if (head->data == key) { deleteBeginning(); return; }
    Node* temp = head;
    while (temp->next && temp->next->data != key) temp = temp->next;
    if (!temp->next) { cout << "Key not found\n"; return; }
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// (g) Search a node and show position
void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == key) {
            cout << "Found at position " << pos << "\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found\n";
}

// (h) Display list
void displayList() {
    if (!head) { cout << "List empty\n"; return; }
    cout << "List: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    int choice, val, key;
    do {
        cout << "\nMenu:\n"
             << "1. Insert at beginning\n"
             << "2. Insert at end\n"
             << "3. Insert before a value\n"
             << "4. Insert after a value\n"
             << "5. Delete from beginning\n"
             << "6. Delete from end\n"
             << "7. Delete a specific node\n"
             << "8. Search a value\n"
             << "9. Display list\n"
             << "0. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: "; cin >> val;
                insertBeginning(val);
                break;
            case 2:
                cout << "Enter value: "; cin >> val;
                insertEnd(val);
                break;
            case 3:
                cout << "Value to insert: "; cin >> val;
                cout << "Insert before which key: "; cin >> key;
                insertBefore(key, val);
                break;
            case 4:
                cout << "Value to insert: "; cin >> val;
                cout << "Insert after which key: "; cin >> key;
                insertAfter(key, val);
                break;
            case 5: deleteBeginning(); break;
            case 6: deleteEnd(); break;
            case 7:
                cout << "Delete which value: "; cin >> key;
                deleteValue(key);
                break;
            case 8:
                cout << "Search value: "; cin >> key;
                searchNode(key);
                break;
            case 9: displayList(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}