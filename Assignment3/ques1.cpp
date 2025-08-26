#include <iostream>
using namespace std;
int MAX;      // stack size
int top = -1; // top pointer
int stackArr[100]; // fixed array for simplicity (max 100)
bool isEmpty() {
    return (top == -1);
}
bool isFull() {
    return (top == MAX - 1);
}
void push(int x) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push " << x << endl;
    } else {
        top++;
        stackArr[top] = x;
        cout << x << " pushed into stack." << endl;
    }
}
void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Cannot pop." << endl;
    } else {
        cout << stackArr[top] << " popped from stack." << endl;
        top--;
    }
}
void peek() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Top element is: " << stackArr[top] << endl;
    }
}
void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--) {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
}
int main() {
    int choice, value;
 cout << "Enter size of stack (max 100): ";
    cin >> MAX;
 do {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. isEmpty" << endl;
        cout << "5. isFull" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
 switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            if (isEmpty())
                cout << "Stack is Empty." << endl;
            else
                cout << "Stack is NOT Empty." << endl;
            break;
        case 5:
            if (isFull())
                cout << "Stack is Full." << endl;
            else
                cout << "Stack is NOT Full." << endl;
            break;
        case 6:
            display();
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);
 return 0;
}
