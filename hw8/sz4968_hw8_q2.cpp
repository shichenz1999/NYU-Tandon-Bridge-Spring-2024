#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);

int main() {
    string str;
    cout << "Please enter a word: ";
    cin >> str;
    
    if (isPalindrome(str)) {
        cout << str << " is a palindrome." << endl;
    } else {
        cout << str << " is not a palindrome." << endl;
    }

    return 0;
}

bool isPalindrome(string str) {
    string reverse;
    for (int i = str.length() - 1; i >= 0; i--) {
        reverse += str[i];
    }

    return str == reverse;
}