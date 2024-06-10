#include <iostream>

using namespace std;

int main() {

    double price1, price2, tax, base, discount, total;
    char club;

    cout << "Enter price of first item: ";
    cin >> price1;
    
    cout << "Enter price of second item: ";
    cin >> price2;
    
    cout << "Does customer have a club card?(Y/N): ";
    cin >> club;
    
    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> tax;

    base = price1 + price2;

    if (price1 < price2) {
        discount = price1 * 0.5 + price2;
    } else{
        discount = price1 + price2 * 0.5;
    }

    if (club == 'Y' || club == 'y') {
        discount = discount * 0.9; 
    }

    total = discount * (1 + tax / 100);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << "Base price: " << base << endl;
    cout << "Price after discounts: " << discount << endl;
    cout.precision(5);
    cout << "Total price: " << total << endl;
    
    return 0;
}