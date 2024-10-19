#include <iostream>
#include <cmath>

using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main() {
    int num, countDivs, sumDivs, perfectNumCounter, amicableNumsCounter;

    countDivs = 0;
    sumDivs = 0;
    perfectNumCounter = 0;
    amicableNumsCounter = 0;

    cout << "Please enter a positive integer M (≥ 2): ";
    cin >> num;

    while (!(num >= 2)) {
        cout << "Please enter a positive integer M (≥ 2): ";
        cin >> num;
    }

    cout << "Perfect numbers between 2 and " << num << ": ";

    for (int i = 2; i <= num; i++) {
        if (isPerfect(i)) {
            cout << i << " ";
            perfectNumCounter++;
        }
    }

    if (perfectNumCounter == 0) {
        cout << "none";
    }

    cout << endl;

    cout << "Pairs of amicable numbers between 2 and " << num << ": ";

    for (int i = 2; i <= num; i++) {
        analyzeDividors(i, countDivs, sumDivs);

        if (sumDivs >= 2 && sumDivs <= num) {
            int j = sumDivs;
            analyzeDividors(j, countDivs, sumDivs);

            if (i < j && sumDivs == i) {
                cout << "(" << i << ", " << j << ") ";
                amicableNumsCounter++;
            }
        }
    }

    if (amicableNumsCounter == 0) {
        cout << "none";
    }

    cout << endl;

    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
    outCountDivs = 0;
    outSumDivs = 0;

    for (int i = 1; i < sqrt(num); i++) {
        if (num % i == 0) {
            outCountDivs++;
            outSumDivs += i;
        }
    }

    for (int i = sqrt(num); i > 1; i--) {
        if (num % i == 0) {
            outCountDivs++;
            outSumDivs += num / i;
        }
    }
}

bool isPerfect(int num) {
    int countDivs = 0;
    int sumDivs = 0;

    analyzeDividors(num, countDivs, sumDivs);

    return num == sumDivs;
}
