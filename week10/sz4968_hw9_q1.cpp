#include <iostream>
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26;

int getWordCount(string userStr);
void getLetterCount(string str, int arr[]);

int main() {
    string userStr;

    cout << "Please enter a line of text:" << endl;
    getline(cin, userStr);

    int wordCount = getWordCount(userStr);
    cout << wordCount << "\t" << "words" << endl;

    int letterCountArr[ALPHABET_SIZE] = {0};

    getLetterCount(userStr, letterCountArr);
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        char letter = 'a' + i;
        if (letterCountArr[i] != 0){
            cout << letterCountArr[i] << "\t" << letter << endl;
        }
    }

    return 0;
}

int isDelimiter(char ch) {
    return ch == ' ' || ch == '.' || ch == ',';
}

int getWordCount(string str) {
    int wordCount = 0;
    for (int i = 0; i <= str.length(); i++){
        char ch = str[i];
        char previousCh = str[i - 1];
        if (isDelimiter(ch) || i == str.length()) {
            if (!(isDelimiter(previousCh)) && i - 1 >= 0) {
                wordCount++;
            }
        }
    }
    return wordCount;
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