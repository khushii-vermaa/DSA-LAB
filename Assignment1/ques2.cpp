#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[100]; 
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {                          // Logic to remove duplicates
        for (int j = i + 1; j < n; ) {
            if (arr[i] == arr[j]) {              
                for (int k = j; k < n - 1; k++) {        // Shift elements to the left
                    arr[k] = arr[k + 1];  
                }
                n--;                                   // size reduced
            } else {
                j++; 
            }
        }
    }
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}