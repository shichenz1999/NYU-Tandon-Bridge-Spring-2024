#include <iostream>
#include <vector>

using namespace std;

void main1();
void main2();

void resizeArr(int*& arr, int& arrSize);

int main() {
    cout << "Version 1" << endl;
    main1();
    cout << endl;
    cout << "Version 2" << endl;
    main2();

    return 0;
} 


void main1() {
    int num;
    int capacity = 1;
    int* numArr = new int[capacity];
    int numArrSize = 0; 

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;
    
    while (true) {
        cin >> num;

        if (num == -1) {
            break;
        }

        if (numArrSize == capacity) {
            resizeArr(numArr, capacity);
        }

        numArr[numArrSize++] = num;
    }

    cout << "Please enter a number you want to search." << endl;
    cin >> num;

    capacity = 1;
    int* lineArr = new int[capacity];
    int lineArrSize = 0;

    for (int i = 0; i < numArrSize; i++) {
        if (lineArrSize == capacity) {
            resizeArr(lineArr, capacity);
        }
        
        int lineNum = i + 1;
        
        if (numArr[i] == num) {
            lineArr[lineArrSize++] = lineNum;
        }
    }

    if (lineArrSize == 0) { 
        cout << num << " does not show at all in the sequence." << endl;
    } else {
        cout << num << " shows in lines ";
        for (int i = 0; i < lineArrSize - 1; i++) {
            cout << lineArr[i] << ", ";
        }
        cout << lineArr [lineArrSize - 1] << "." << endl;
    }

    delete[] numArr;
    delete[] lineArr;
}

void main2() {
    int num;
    vector <int> numVec;

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;
    
    while (true) {
        cin >> num;

        if (num == -1) {
            break;
        }

        numVec.push_back(num);
    }

    cout << "Please enter a number you want to search." << endl;
    cin >> num;

    vector <int> lineVec;


    for (int i = 0; i < numVec.size(); i++) {
        int line_num = i + 1;
        if (numVec[i] == num) {
            lineVec.push_back(line_num);
        }
    }

    if (lineVec.size() == 0) {
        cout << num << " does not show at all in the sequence." << endl;
    } else {
        cout << num << " shows in lines ";
        for (int i = 0; i < lineVec.size() - 1; i++) {
            cout << lineVec[i] << ", ";
        }
        cout << lineVec[lineVec.size() - 1] << "." << endl;
    }
}

void resizeArr(int*& arr, int& capacity) {
    int* resizedArr = new int[capacity * 2];
    for (int i = 0; i < capacity; i++) {
        resizedArr[i] = arr[i];
    }

    delete [] arr;

    arr = resizedArr;
    capacity = 2 * capacity;
}