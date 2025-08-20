#include<iostream>
using namespace std;

int main() {
    int arr[10][10], brr[10][10], res[10][10];
    int r1, c1, r2, c2;
    cout << "Enter number of rows for 1st matrix: ";
    cin >> r1;
    cout << "Enter number of columns for 1st matrix: ";
    cin >> c1;
    cout << "Enter number of rows for 2nd matrix: ";
    cin >> r2;
    cout << "Enter number of columns for 2nd matrix: ";
    cin >> c2;
    if (c1 != r2) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;  // exit the program
    }
    cout << "Enter elements of 1st matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> arr[i][j];
        }
    }
    cout << "Enter elements of 2nd matrix:\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> brr[i][j];
        }
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) { // or k < r2
                res[i][j] += arr[i][k] * brr[k][j];
            }
        }
    }
    cout << "\nResultant Matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;  // move to next row
    }
    return 0;   }