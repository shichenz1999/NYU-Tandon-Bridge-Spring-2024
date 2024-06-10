#include<iostream>
#include<string>

using namespace std;

int main() {

    string name;
    int graduationYear, currentYear, yearLeft;

    cout << "Please enter your name: ";
    cin >> name;
    
    cout << "Please enter your graduation year: ";
    cin >> graduationYear;
    
    cout << "Please enter current year: ";
    cin >> currentYear;

    yearLeft = graduationYear - currentYear;

    if (yearLeft <= 0) {
        cout << name << ", you are graduated" << endl;
    }

    else if (yearLeft == 1) {
        cout << name << ", you are a Senior" << endl;
    }

    else if (yearLeft == 2) {
        cout << name << ", you are a Junior" << endl;
    }

    else if (yearLeft == 3) {
        cout << name << ", you are a Sophomore" << endl;
    }

    else if (yearLeft == 4) {
        cout << name << ", you are a Freshman" << endl; 
    }

    else {
        cout << name << ", you are not in college yet" << endl;
    }

    return 0;
}
