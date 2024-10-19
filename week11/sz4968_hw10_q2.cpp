#include <iostream>

using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main() {
    int resArrSize = 0;
    int* missingArr = nullptr;
    int arr[6] = {3, 1, 3, 0, 6, 4};
    missingArr = findMissing(arr, 6, resArrSize);
    
    cout << "Missing numbers: " ;
    for (int i = 0; i < resArrSize; i++) {
        cout << missingArr[i] << ' ';
    }
    cout << endl;

    delete[] missingArr;

    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    int* occurenceArr = new int[n + 1]();
    int missingArrSize = 0;

    for (int i = 0; i < n; i++) {
        int k = arr[i]; 
        occurenceArr[k]++;
    }

    for (int i = 0; i < n + 1; i++) {
        if (occurenceArr[i] == 0) {
            missingArrSize++;
        }
    }

    int* missingArr = new int[missingArrSize];

    int missingIndex = 0;

    for (int i = 0; i < n + 1; i++) {
        if (occurenceArr[i] == 0) {
            missingArr[missingIndex++] = i;
        }  
    }

    resArrSize = missingArrSize;

    delete[] occurenceArr;

    return missingArr;
}