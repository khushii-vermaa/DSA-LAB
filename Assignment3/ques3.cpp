#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Enter an expression: ";
    cin >> str;

    char stack[100];   // array for stack
    int top = -1;      // stack pointer
    int flag = 1;      // assume balanced (1 = balanced, 0 = not balanced)

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            // push
            stack[++top] = str[i];
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (top == -1) {   // stack empty but closing found
                flag = 0;
                break;
            }
            char ch = stack[top--];  // pop
            if ((str[i] == ')' && ch != '(') ||
                (str[i] == '}' && ch != '{') ||
                (str[i] == ']' && ch != '[')) {
                flag = 0;
                break;
            }
        }
        i++;
    }

    if (top != -1)   // some opening brackets not closed
        flag = 0;

    if (flag == 1)
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}
