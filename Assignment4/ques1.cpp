/*Develop a menu driven program demonstrating the following operations on simple
Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().*/

#include<iostream>
using namespace std;

class ArrayQueue {
    int start;
    int *arr;
    int maxsize;
    int end;

   public:
    ArrayQueue() {
        maxsize = 16;
        arr = new int[maxsize];
        start = -1;
        end = -1;
    }

    void enqueue(int x) {
        if (end== maxsize-1) return;

        if (start==-1) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1);
        }

        arr[end] = x;

    }

    void dequeue() {
        if (start == -1) return ;
    
         if (start==end) {
            start = -1;
            end = -1;
        }
        else {
            start = (start + 1);
            
        }
    }

    int peek() {
        if (start == -1) {
            return -1;
        }

        return arr[start];
    }

    bool isEmpty() { return (start==-1); }

    bool isFull() { return (end==maxsize); }
};

int main(){
    ArrayQueue q;
    q.enqueue(7);
    cout<<q.peek()<<endl;
    q.enqueue(9);
    q.enqueue(10);
    cout<<q.peek()<<endl;
    cout<<q.isEmpty()<<endl;
    q.dequeue();
    cout<<q.isFull()<<endl;
    cout<<q.isEmpty()<<endl;
    q.dequeue();
    q.dequeue();
    cout<<q.isEmpty()<<endl;
    
    
    return 0;
}