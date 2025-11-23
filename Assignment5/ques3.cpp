/*Write a program to find the middle of a linked list.*/

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

ListNode* middleOfLinkedList(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast != NULL && fast->next != NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;

    }

    int main(){
        int arr[] = {1,2,1,2,1,3,1};
        for (int x : arr) insertEnd(x);

        cout<<"The value of middle of linked list is: "<<middleOfLinkedList(head)->val;
        
        return 0;
    }
