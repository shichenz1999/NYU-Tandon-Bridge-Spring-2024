#include<iostream>

using namespace std;

int main() {
    
    int johnDays, johnHours, johnMinutes, billDays, billHours, billMinutes, totalWorkingTimeInMinutes, totalDays, totalHours, totalMinutes;

    cout << "Please enter the number of days John has worked: ";
    cin >> johnDays;
    
    cout << "Please enter the number of hours John has worked: ";
    cin >> johnHours;
    
    cout << "Please enter the number of minutes John has worked: ";
    cin >> johnMinutes;
    
    cout << endl;

    cout << "Please enter the number of days Bill has worked: ";
    cin >> billDays;
   
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> billHours;
   
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> billMinutes;
    
    cout << endl;

    totalWorkingTimeInMinutes = (johnDays + billDays) * 24 * 60 + (johnHours + billHours) * 60 + (johnMinutes + billMinutes);
    
    totalDays = totalWorkingTimeInMinutes / (24 * 60);
    totalHours = (totalWorkingTimeInMinutes - totalDays * 24 * 60) / 60;
    totalMinutes = totalWorkingTimeInMinutes - totalDays * 24 * 60 - totalHours * 60;

    cout << "The total time both of them worked together is: " << totalDays << " days, " << totalHours << " hours and " << totalMinutes << " minutes." << endl;

    return 0;
}
