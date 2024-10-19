#include <iostream>

using namespace std;

int main() {

    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;

    double realNumber;
    int roundingMethod, result;

    cout << "Please enter a Real number:" << endl;
    cin >> realNumber;

    cout << "Choose your rounding method:" << endl;
    cout << "1. Floor round" << endl;
    cout << "2. Ceiling round" << endl;
    cout << "3. Round to the nearest whole number" << endl;
    cin >> roundingMethod;

    if (realNumber == int(realNumber)) {
        result = realNumber;
        cout << result << endl;
    } else {
        switch (roundingMethod) {
            case FLOOR_ROUND:
                if (realNumber > 0) {
                    result = int(realNumber);
                } else {
                    result = int(realNumber - 1);
                }
                cout << result << endl;
                break;

            case CEILING_ROUND:
                if (realNumber > 0) {
                    result = int(realNumber + 1);
                } else {
                    result = int(realNumber);
                }
                cout << result << endl;
                break;

            case ROUND:
                if (realNumber > 0) {
                    result = int(realNumber + 0.5);
                } else {
                    result = int(realNumber - 0.5);
                }
                cout << result << endl;
                break;

            default:
                break;
        }
    }

    return 0;
}

