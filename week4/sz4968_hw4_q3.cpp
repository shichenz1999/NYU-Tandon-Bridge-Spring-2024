#include <iostream>

using namespace std;

int main() {

    int decimal, binary, binaryDigit, base;

    binary = 0;
    base = 1;

    cout << "Enter decimal number:" << endl;
    cin >> decimal;

    while (decimal > 0) {
        binaryDigit = decimal % 2;
        binary = binary + binaryDigit * base;
        decimal = decimal / 2;
        base = base * 10;     
    }

    cout << binary << endl;

    return 0;
}
