#include <iostream>
#include <cmath>

using namespace std;

int main() {
    {
        cout << "section a" << endl;

        int length, num;
        double product, geoMean;
        product = 1;

        cout << "Please enter the length of the sequence: ";
        cin >> length;
        cout << "Please enter your sequence:" << endl;

        for (int i = 1; i <= length; i++) {
            cin >> num;
            product *= num;
        }

        geoMean = pow(product, 1 / double(length));

        cout << "The geometric mean is: " << geoMean << endl;
    }

    {
        cout << "section b" << endl;
        
        int length = 0, num;
        double product, geoMean;
        product = 1;

        cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:" << endl;
        cin >> num;

        for (int i = 1; num != -1; i++) {
            product *= num;
            length = i;
            cin >> num;
        }

        geoMean = pow(product, 1 / double(length));

        cout << "The geometric mean is: " << geoMean << endl;
    }

    return 0;
}
