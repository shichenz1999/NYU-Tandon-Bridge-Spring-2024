#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    double a, b, c;
    double sqrtResult;

    cout << "Please enter value of a: ";
    cin >> a;

    cout << "Please enter value of b: ";
    cin >> b;

    cout << "Please enter value of c: ";
    cin >> c;

    sqrtResult = sqrt(b * b - 4 * a * c);

    if (a == 0) {
        if (b == 0 && c == 0) {
            cout << "This equation has infinite number of solutions" << endl;
        } else if (b == 0 && c != 0) {
            cout << "This equation has no solution" << endl;
        } else {
            cout << "This equation has a single real solution x = " << -c / b << endl;
        }
    } else {
        if (b * b - 4 * a * c < 0) {
            cout << "This equation has no real solution" << endl;
        } else if (b * b - 4 * a * c == 0) {
            cout << "This equation has a single solution x = " << -b / (2 * a) << endl;
        } else {
            cout << "This equation has two real solutions x = " << (-b + sqrtResult) / (2 * a) << " and x = " << (-b - sqrtResult) / (2 * a) << endl;
        }
    }

    return 0;
}
