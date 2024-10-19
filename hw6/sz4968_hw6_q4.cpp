#include <iostream>
#include <cmath>

using namespace std;

void printDivisors(int num);

int main() {

    int num;

    cout << "Please enter a positive integer >= 2: ";
    cin >> num;

    while (!(num >= 2)) {
        cout << "Please enter a positive integer >= 2: ";
        cin >> num;
    }

    printDivisors(num);

    cout << endl;

    return 0;
}

void printDivisors(int num) {
    for (int i = 1; i < sqrt(num); i++) {
        if (num % i == 0) {
            cout << i << " ";
        }
    }

    for (int i = sqrt(num); i >= 1; i--) {
        if (num % i == 0) {
            cout << num / i << " ";
        }
    }
}
