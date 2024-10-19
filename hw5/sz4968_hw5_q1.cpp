#include <iostream>

using namespace std;

int main() {
    int input, output;
    cout << "Please enter a positive integer:" << endl;
    cin >> input;

    for (int row = 1; row <= input; row++) {
        for (int column = 1; column <= input; column++) {
            output = row * column;
            cout << output << "\t";
        }
        cout << endl;
    }

    return 0;
}