#include <iostream>

using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
    
    reverseArray(arr1, arr1Size); 
    printArray(arr1, arr1Size);
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}

void printArray(int arr[], int arrSize) {
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void reverseArray(int arr[], int arrSize) {
    for(int i = 0; i < arrSize / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[arrSize - 1 - i];
        arr[arrSize - 1 - i] = temp;
    }
}

void removeOdd(int arr[], int& arrSize) {
    //if we ecounter the fist even number, we move it to index 0 and replace whatever number at index 0 with this number.
    //if we encounter the next even number, we move it to index 1 and replace whatever number at index 1 with this number.
    //eventually all the even number will be pushed to the left.
    //we remove all the odd number by defining a new array size equals the number of even numbers in the orginal array.

    int j = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 0) {
            arr[j] = arr[i];
            j++;
        } 
    }
    arrSize = j;
}

void splitParity(int arr[], int arrSize) {
    //if we encounter the first odd number, we swap it with whatever number at index 0.
    //if we ecounter the next odd number, we swap it with whatever number at index 1.
    //eventually all the odd numebr will be pushed to the left.
    
    int j = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 1) {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j++;
        } 
    }
}
