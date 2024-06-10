#include <iostream>
#include <string>

using namespace std;

int minInArray(int arr[], int arrSize);
string minIndices(int arr[], int arrSize, int min);

int main() {
    int arrSize, min;
    string minIndicesString;
    arrSize = 20;
    int arr[arrSize];

    cout<<"Please enter 20 integers separated by a space:"<<endl;
    
    for (int i = 0; i < arrSize; i++) {
        cin>>arr[i];
    }

    min = minInArray(arr, arrSize);
    minIndicesString = minIndices(arr, arrSize, min);

    cout << "The minimum value is ";
    cout << min; 
    cout << ", and it is located in the following indices: "; 
    cout << minIndicesString << endl;

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

string minIndices(int arr[], int arrSize, int min) {
    string minIndicesString;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == min) {
            minIndicesString += to_string(i) + " ";
        }
    }

    return minIndicesString;
}