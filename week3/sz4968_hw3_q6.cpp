#include <iostream>
#include <string>

using namespace std;

int main() {

    string day;
    int hour, minute, callDuration;
    double cost, rate;
    char colon;

    cout << "Enter the day of the week (Mo Tu We Th Fr Sa Su): ";
    cin >> day;
    
    cout << "Enter the time the call started in 24 hour notation e.g. 13:30: ";
    cin >> hour >> colon >> minute;
    
    cout << "Enter the length of the call in minutes: ";
    cin >> callDuration;

    if (day == "Mo" || day == "Tu" || day == "We" || day == "Th" || day == "Fr") {
        if ((hour >= 8 && hour < 18) || (hour == 18 && minute == 0)) {
            rate = 0.40;
        } else {
            rate = 0.25;
        }
    } else {
        rate = 0.15;
    }

    cost = callDuration * rate;
    cout << "The cost of the call is: $" << cost << endl;

    return 0;
}
