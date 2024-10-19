#include <iostream>

using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int* reorderedArr = new int[arrSize];
    int reorderedIndex = 0;
    int lastIndex = arrSize - 1;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 1) {
            reorderedArr[reorderedIndex++] = arr[i];
        } else {
            reorderedArr[lastIndex--] = arr[i];
        }
    }

    for (int i = 0; i < arrSize; i++) {
        arr[i] = reorderedArr[i];
    }

    delete[] reorderedArr;
}

int main() {
    int arr[] = {5, 2, 11, 7, 6, 4};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    oddsKeepEvensFlip(arr, arrSize);

    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}