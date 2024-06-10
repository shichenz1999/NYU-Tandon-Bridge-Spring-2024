#include <iostream>

using namespace std;

int main() {

    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }

        for (int j = 0; j < 2 * (n - i) - 1; j++) {
            cout << "*";
        }

        cout << endl;
    }
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }

        for (int j = 0; j < 2 * (n - i) - 1; j++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
