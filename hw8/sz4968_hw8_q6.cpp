#include <iostream>
#include <string>

using namespace std;

bool isNum(string& str);
void hideNums(string& str);

int main() {
    string userStr;
    
    cout << "Please enter a line of text:" << endl;
    getline(cin, userStr);

    hideNums(userStr);

    cout << userStr << endl;

    return 0;
}

bool isNum(string& str){
    for (int i = 0; i < str.length(); i++){
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }

    return true;
}

void hideNums(string& str) {
    
    for (int start = 0, end = 0; end <= str.length(); end++) {
        if (end == str.length() || str[end] == ' ') {
            string word = str.substr(start, end - start);
            if (word.length() > 0 && isNum(word)) {
                 for (int i = start; i < end; i++) {
                    str[i] = 'x';
                 }
            }

            start = end + 1;
        }
    }
}
