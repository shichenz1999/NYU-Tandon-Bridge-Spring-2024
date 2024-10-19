#include <iostream>
#include <vector>

using namespace std;

int calculateLowestCost(int arr[], int arrSize);

int main() {
    int arr[6] = {0, 3, 80, 6, 57, 10};
    int arrSize = 6;
    int lowestCost = calculateLowestCost(arr, arrSize);
    cout << "The lowest cost is " << lowestCost << endl;

    return 0;
}

int calculateLowestCost(int arr[], int arrSize) {
    int lowestCost, currCost, prevCost1, prevCost2;

    if (arrSize <= 0) {
        return -1; 
    } else if (arrSize == 1) {
        lowestCost = arr[0];
        return lowestCost;
    } else if (arrSize == 2) {
        lowestCost = arr[0] + arr[1];
        return lowestCost;
    } else {
        prevCost1 = calculateLowestCost(arr, arrSize - 2);
        prevCost2 = calculateLowestCost(arr, arrSize - 1);
        currCost = arr[arrSize - 1];
        if (prevCost1 < prevCost2) {
            lowestCost = prevCost1 + currCost;
        } else {
            lowestCost = prevCost2 + currCost;
        }
        return lowestCost;
    }
}