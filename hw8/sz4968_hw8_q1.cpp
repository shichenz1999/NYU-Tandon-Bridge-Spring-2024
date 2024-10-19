#include <iostream>
#include <string>

using namespace std;

int minInArray(int arr[], int arrSize);

int main() {
    int arr[20];
    int arrSize = 20;
    
    cout << "Please enter 20 integers separated by a space:" << endl;
    
    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    int min = minInArray(arr, arrSize);

    cout << "The minimum value is ";
    cout << min; 
    cout << ", and it is located in the following indices: "; 
    
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == min) {
            cout << i << ' ';
        }
    }

    cout << endl;

    return 0;
}

int minInArray(int arr[], int arrSize) {
    int min = arr[0];

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] <= min) {
            min = arr[i];
        }
    }

    return min;
}