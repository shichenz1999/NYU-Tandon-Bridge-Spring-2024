#include <iostream>

using namespace std;

int main() {

    int decimal, numOfM, numOfD, numOfC, numOfL, numOfX, numOfV, numOfI;
    string Roman;

    cout << "Enter decimal number:" << endl;
    cin >> decimal;

    numOfM = decimal / 1000;
    numOfD = (decimal % 1000) / 500;
    numOfC = (decimal % 500) / 100;
    numOfL = (decimal % 100) / 50;
    numOfX = (decimal % 50) / 10;
    numOfV = (decimal % 10) / 5;
    numOfI = (decimal % 5);

    for (int i = 1; i <= numOfM; i++) {
        Roman += "M";
    }

    for (int i = 1; i <= numOfD; i++) {
        Roman += "D";
    }
    
    for (int i = 1; i <= numOfC; i++) {
        Roman += "C";
    }

    for (int i = 1; i <= numOfL; i++) {
        Roman += "L";
    }

    for (int i = 1; i <= numOfX; i++) {
        Roman += "X";
    }

    for (int i = 1; i <= numOfV; i++) {
        Roman += "V";
    } 

    for (int i = 1; i <= numOfI; i++) {
        Roman += "I";
    } 

    cout << decimal << " is " << Roman << endl;

    return 0;
}
