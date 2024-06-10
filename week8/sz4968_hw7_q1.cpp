#include <iostream>

using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
bool isLeapYear(int year);
void printYearCalender(int year, int startingDay);

int main() {
    int year, startingDay;
    cout << "Please enter a year and a starting day separated by a space: ";
    cin >> year >> startingDay;
    printYearCalender(year, startingDay);
    
    return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {
    cout << "Mon\tTue\tWed\tThu\tFri\tSat\tSun" << endl;

    for (int printSpace = 1; printSpace < startingDay; printSpace++) {
        cout << "\t";
    }

    for (int printDate = 1; printDate <= numOfDays; printDate++) {
        if ((startingDay - 1 + printDate) % 7 == 0 || printDate == numOfDays) {
            cout << printDate << endl;
        } else {
            cout << printDate << "\t";
        }
    }

    cout << endl;

    int lastDay = (startingDay - 1 + numOfDays) % 7;

    if (lastDay == 0) {
        lastDay = 7;
    }

    return lastDay;
}

bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 4 == 0 && year % 100 != 0) {
        return true;
    } else {
        return false;
    }
}

void printYearCalender(int year, int startingDay) {
    cout << "January " << year << endl;
    startingDay = printMonthCalender(31, startingDay) % 7 + 1;

    cout << "February " << year << endl;
    if (isLeapYear(year)) {
        startingDay = printMonthCalender(29, startingDay) % 7 + 1;
    } else {
        startingDay = printMonthCalender(28, startingDay) % 7 + 1;
    }

    cout << "March " << year << endl;
    startingDay = printMonthCalender(31, startingDay) % 7 + 1;

    cout << "April " << year << endl;
    startingDay = printMonthCalender(30, startingDay) % 7 + 1;

    cout << "May " << year << endl;
    startingDay = printMonthCalender(31, startingDay) % 7 + 1;

    cout << "June " << year << endl;
    startingDay = printMonthCalender(30, startingDay) % 7 + 1;

    cout << "July " << year << endl;
    startingDay = printMonthCalender(31, startingDay) % 7 + 1;

    cout << "August " << year << endl;
    startingDay = printMonthCalender(31, startingDay) % 7 + 1;

    cout << "September " << year << endl;
    startingDay = printMonthCalender(30, startingDay) % 7 + 1;

    cout << "October " << year << endl;
    startingDay = printMonthCalender(31, startingDay) % 7 + 1;

    cout << "November " << year << endl;
    startingDay = printMonthCalender(30, startingDay) % 7 + 1;

    cout << "December " << year << endl;
    startingDay = printMonthCalender(31, startingDay) % 7 + 1;
}
