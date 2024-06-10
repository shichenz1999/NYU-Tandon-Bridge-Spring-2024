#include <iostream>

using namespace std;

int main() {

    int dollar, cent, quarter, dime, nickel, penny;

    cout << "Please enter your amount in the format of dollars and cents separated by a space:" << endl;
    cin >> dollar >> cent;

    quarter = (100 * dollar + 1 * cent) / 25;
    dime = (100 * dollar + 1 * cent - 25 * quarter) / 10;
    nickel= (100 * dollar + 1 * cent - 25 * quarter - 10 * dime) / 5;
    penny= 100 * dollar + 1 * cent - 25 * quarter - 10 * dime - 1 * nickel;

    cout << dollar << " dollars and " << cent << " cents are:" << endl;
    cout << quarter << " quarters, " << dime << " dimes, " << nickel << " nickels and " << penny << " pennies" << endl;
    
    return 0;
}
