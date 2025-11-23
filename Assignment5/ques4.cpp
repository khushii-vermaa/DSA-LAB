/*Write a program to reverse a linked list.*/

#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
ListNode* head = nullptr;
void insertEnd(int val) {
    ListNode* n = new ListNode{val};
    if (!head) { head = n; return; }
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
}
//Recursive Code:
 ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* Newhead = reverseList(head->next);

        ListNode* front = head->next;

        front->next = head;

        head->next = NULL;

        return Newhead;
    }
    //Iterative Code:
ListNode* reverseListit(ListNode* head) {
    ListNode* prev = nullptr;    
    ListNode* curr = head;      

    while (curr != nullptr) {
        ListNode* nextNode = curr->next; 
        curr->next = prev;             
        prev = curr;              
        curr = nextNode;              
    }
    return prev;  
}

    void displayList() {
    ListNode* temp = head;
    if (!temp) { cout << "Empty List"; return; }
    while (temp) {
        cout << temp->val;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
   
    int arr[] = {1,2,1,2,1,3,1};
    for (int x : arr) insertEnd(x);

    cout << "Original List: ";
    displayList();

    

    head=reverseListit(head);
    cout << "Updated List: ";
    displayList();
    cout << "\n";

    return 0;
}