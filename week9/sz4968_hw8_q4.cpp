#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int PIN[5] = {1, 2, 3, 4, 5};
const int PIN_DIGIT = 5;

void printArr(int arr[], int arrSize);
void getNumArr(int numArr[], int numArrSize);
bool isCorrectPin(int numArr[], int userPin);

int main() {
    int userPin;
    int pinArr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numArr[10];

    getNumArr(numArr, 10);

    cout << "Please enter your PIN according to the following mapping:" << endl;
    cout << "PIN: ";
    printArr(pinArr, 10);
    cout << "NUM: ";
    printArr(numArr, 10);
    cin >> userPin;

    if (isCorrectPin(numArr, userPin)) {
        cout << "Your PIN is correct";
    } else {
        cout << "Your PIN is not correct";
    }

    cout << endl;

    return 0;
}

bool isCorrectPin(int numArr[], int userPin) {
    int encryptedPin = 0;

    for (int i = 0; i < PIN_DIGIT; i++) {
        encryptedPin = encryptedPin * 10 + numArr[PIN[i]];
    }

    return encryptedPin == userPin;
}

void printArr(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void getNumArr(int numArr[], int numArrSize) {
    srand(time(0));

    for (int i = 0; i < numArrSize; i++) {
        int randNum = rand() % 3 + 1;
        numArr[i] = randNum;
    }
}
