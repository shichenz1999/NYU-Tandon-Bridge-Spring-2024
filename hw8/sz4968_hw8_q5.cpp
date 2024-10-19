#include <iostream>
#include <string>

using namespace std;

int main() {
    string lastName, firstName, middleName, middleInitial;

    cout << "Please enter your name: ";
    cin >> firstName >> middleName >> lastName;

    middleInitial = middleName[0];

    cout << lastName << ", " << firstName << " " << middleInitial << "." << endl;

    return 0;
}