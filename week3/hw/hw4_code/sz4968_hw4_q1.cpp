#include <iostream>

using namespace std;

int main() {
    {
        cout << "section a" << endl;
        int n;
        
        cout << "Please enter a positive integer: ";
        cin >> n;
        
        int i = 1;
        
        while (i <= n) {
            cout << 2 * i << endl;
            i++;
        }
    }

    {
        cout << "section b" << endl; 
        int n;
        
        cout << "Please enter a positive integer: ";
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cout << 2 * i << endl;
        }
    }
    
    return 0;
}
