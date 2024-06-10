#include <iostream>
using namespace std;

int fib(int n);

int main() {
    int num;
    cout << "Please enter a positive integer: ";
    cin >> num;
    cout << fib(num) << endl;

    return 0;
}

int fib(int n) {
    int num1 = 1, num2 = 1, num3;

    if (n == 1 || n == 2) {
        return 1;
    } else {
        for (int i = 3; i <= n; i++) {
            num3 = num1 + num2;
            num1 = num2;
            num2 = num3;
        }
        return num3;
    }
}
