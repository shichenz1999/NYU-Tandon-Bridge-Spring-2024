#include <iostream>

using namespace std;

int main() {  
      
    int quarter, dime, nickel, penny, dollar, cent;
    
    cout << "Please enter number of coins:" << endl;
    cout << "# of quarters:";
    cin >> quarter;
    
    cout << "# of dimes:";
    cin >> dime;
   
   cout << "# of nickels:";
    cin >> nickel;
    
    cout << "# of pennies:";
    cin >> penny;
    
    dollar = (quarter * 25 + dime * 10 + nickel * 5 + penny * 1) / 100;
    cent = (quarter * 25 + dime * 10 + nickel * 5 + penny * 1) % 100;
    
    cout << "The total is " << dollar << " dollars and " << cent << " cents" << endl;

    return 0;
}
