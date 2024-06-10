#include <iostream>

using namespace std;

int main() {

    double weight, height, bmi;
    
    cout << "Please enter weight (in pounds): ";
    cin >> weight;

    cout << "Please enter height (in inches): ";
    cin >> height;

    cout << "The weight status is: ";

    bmi = (weight * 0.453592) / (height * height * 0.0254 * 0.0254);

    if (bmi < 18.5) {
        cout << "Underweight" << endl;
    } else if (bmi >= 18.5 && bmi < 25) {
        cout << "Normal" << endl;
    } else if (bmi >= 25 && bmi < 30) {
        cout << "Overweight" << endl;
    } else {
        cout << "Obese" << endl;
    }

    return 0;
}
