#include <iostream>
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26;

void getLetterCount(string str, int letterCountArr[]);
bool areAnagrams(int arr1[], int arr2[]);

int main() {
    string userStr1, userStr2;

    cout << "Please enter the first string:" << endl;
    getline(cin, userStr1);
    cout << "Please enter the second string:" << endl;
    getline(cin, userStr2);

    int letterCountArr1[ALPHABET_SIZE] = {0};
    int letterCountArr2[ALPHABET_SIZE] = {0};

    getLetterCount(userStr1, letterCountArr1);
    getLetterCount(userStr2, letterCountArr2);
    
    if (areAnagrams(letterCountArr1, letterCountArr2)) {
        cout << "they are anagrams" << endl;  
    } else {
        cout << "they are not anagrams" << endl;
    }
    return 0;
}

void getLetterCount(string str, int letterCountArr[]) {
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z') {
            letterCountArr[ch - 'a']++;
        } else if (ch >= 'A' && ch <= 'Z') {
            letterCountArr[ch - 'A']++;
        }
    }
}

bool areAnagrams(int arr1[], int arr2[]) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}