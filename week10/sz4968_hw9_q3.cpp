#include <iostream>

using namespace std;

int* getPosNums1 (int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2 (int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main() {
    {
        //version 1

        int arr[] = {3, -1, -3, 0, 6, 4};
        int arrSize = sizeof(arr) / sizeof(arr[0]);

        int outPosArrSize;

        int* posArr = getPosNums1(arr, arrSize, outPosArrSize);

        for (int i = 0; i < outPosArrSize; i++) {
            cout << posArr[i] << ' ';
        }

        cout << endl;

        delete[] posArr;
    }
    
    {
        //version 2

        int arr[] = {3, -1, -3, 0, 6, 4};
        int arrSize = sizeof(arr) / sizeof(arr[0]);

        int outPosArrSize;
        int* outPosArrSizePtr = &outPosArrSize;
        int* posArr = getPosNums2(arr, arrSize, outPosArrSizePtr);

        for (int i = 0; i < *outPosArrSizePtr; i++) {
            cout << posArr[i] << ' ';
        }

        cout << endl;

        delete[] posArr;
    } 

    {
        //version 3

        int arr[] = {3, -1, -3, 0, 6, 4};
        int arrSize = sizeof(arr) / sizeof(arr[0]);

        int* outPosArr = nullptr;
        int outPosArrSize;

        getPosNums3(arr, arrSize, outPosArr, outPosArrSize);

        for (int i = 0; i < outPosArrSize; i++) {
            cout << outPosArr[i] << ' ';
        }

        cout << endl;

        delete[] outPosArr;
    }

    {
        //version 4

        int arr[] = {3, -1, -3, 0, 6, 4};
        int arrSize = sizeof(arr) / sizeof(arr[0]);

        int* outPosArr = nullptr;
        int outPosArrSize; 
        
        int** outPosArrPtr = &outPosArr; 
        int* outPosArrSizePtr = &outPosArrSize;

        getPosNums4(arr, arrSize, outPosArrPtr, outPosArrSizePtr);
     
        for (int i = 0; i < *outPosArrSizePtr; i++) {
            cout << (*outPosArrPtr)[i] << ' ';
        }

        cout << endl;

        delete[] outPosArr;
    }

    return 0;
}

int* getPosNums1 (int* arr, int arrSize, int& outPosArrSize) {
    int posCount = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posCount++;
        }
    }

    int* posArr = new int[posCount];
    int posArrIndex = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArr[posArrIndex++] = arr[i];
        }
    }

    outPosArrSize = posCount;

    return posArr;
}

int* getPosNums2 (int* arr, int arrSize, int* outPosArrSizePtr) {
    int posCount = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posCount++;
        }
    }

    int* posArr = new int[posCount];
    int posArrIndex = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArr[posArrIndex++] = arr[i];
        }
    }

    *outPosArrSizePtr = posCount;

    return posArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    int posCount = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posCount++;
        }
    }

    int* posArr = new int[posCount];
    int posArrIndex = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArr[posArrIndex++] = arr[i];
        }
    }

    outPosArr = posArr;
    outPosArrSize = posCount;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    int posCount = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posCount++;
        }
    }

    int* posArr = new int[posCount];
    int posArrIndex = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArr[posArrIndex++] = arr[i];
        }
    }

    *outPosArrPtr = posArr;
    *outPosArrSizePtr = posCount;
}
