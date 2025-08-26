#include <iostream>
#include <cstring>
using namespace std;

int top = -1;
char st[100];
void push(char c) {
    st[++top] = c;
}
char pop() {
    return st[top--];
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }
    cout << "Reversed string: ";
    for (int i = 0; i < len; i++) {
        cout << pop();
    }
    cout << endl;
    return 0;
}
