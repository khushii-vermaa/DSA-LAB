#include <iostream>
#include <cstring>
using namespace std;
char stackArr[100];
int top = -1;
// Push onto stack
void push(char c) {
    stackArr[++top] = c;
}
// Pop from stack
char pop() {
    if (top == -1) return -1;
    return stackArr[top--];
}
// Peek top of stack
char peek() {
    if (top == -1) return -1;
    return stackArr[top];
}
// Check operator precedence
int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}
// Convert infix to postfix
void infixToPostfix(char infix[]) {
    char postfix[100];
    int k = 0;
 for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
 // If operand, add to postfix
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[k++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        else {  // Operator
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
while (top != -1) { // Pop remaining operators
        postfix[k++] = pop();
    }
postfix[k] = '\0';
    cout << "Postfix Expression: " << postfix << endl;
}
int main() {
    char infix[100];
    cout << "Enter an infix expression: ";
    cin >> infix;
 infixToPostfix(infix);
 return 0;
}
