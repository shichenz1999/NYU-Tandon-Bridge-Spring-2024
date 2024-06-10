#include <iostream>

using namespace std;

int main() {
    int n, num, remainder, oddDigitCounter, evenDigitCounter;

    oddDigitCounter = 0;
    evenDigitCounter = 0;

    cout << "Please enter a positive integer: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        num = i;

        while (num > 0) {
            remainder = num % 10;
            if (remainder % 2 == 1) {
                oddDigitCounter++;
            } else {
                evenDigitCounter++;
            }
            num = num / 10;
        }

        if (evenDigitCounter > oddDigitCounter) {
            cout << i << endl;
        }

        oddDigitCounter = 0;
        evenDigitCounter = 0;
    }

    return 0;
}