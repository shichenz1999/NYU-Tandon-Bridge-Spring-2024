#include <iostream>

using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
    cout << "a." << endl;
    int arr[4] = {2, -1, 3, 10};
    int arrSize = 4;
    int result = sumOfSquares(arr, arrSize);
    cout << result << endl;

    cout << "b." << endl;
    int arr2[4] = {1, 2, 3, 4};
    int arr2Size = 4;
    if (isSorted(arr2, arr2Size)) {
        cout << "the elements are sorted" << endl;
    } else {
        cout << "the elements are not sorted" << endl;
    }


    return 0;
}

int sumOfSquares(int arr[], int arrSize) {
    if (arrSize < 0) {
        return -1;
    } else if (arrSize == 0) {
        int result = 0;
        return result;
    } else {
        int square = arr[arrSize - 1] * arr[arrSize - 1];
        int result = sumOfSquares(arr, arrSize - 1) + square;
        return result;
    }

}

bool isSorted(int arr[], int arrSize) {
    if (arrSize < 0) {
        return -1;
    }
    if (arrSize == 0 || arrSize == 1) {
        return true;
    } else {
        return (isSorted(arr, arrSize - 1) && (arr[arrSize - 1] >= arr[arrSize - 2]));
    }
}