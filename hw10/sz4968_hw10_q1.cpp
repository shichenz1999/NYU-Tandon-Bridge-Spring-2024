#include <iostream>
#include <string>

using namespace std;

void createWordsArray(string sentence, string *wordsArr, int& outWordsArrSize);

int main() {
    string sentence;
    cout << "Please enter a sentence:" << endl;
    getline(cin, sentence);
    
    int wordsArrSize = sentence.length();
    string* wordsArr = new string[wordsArrSize];
    
    createWordsArray(sentence, wordsArr, wordsArrSize);
    
    for (int i = 0; i < wordsArrSize; i++) {
        cout << wordsArr[i] << ' ';
    } 
    cout << endl;
    cout << "Word count: " << wordsArrSize << endl;

    delete[] wordsArr;

    return 0;
}

void createWordsArray(string sentence, string *wordsArr, int& outWordsArrSize) {
    int wordCount = 0;
    for (int start = 0, end = 0; end <= sentence.length(); end++) {
        if (sentence[start] != ' ') {
            if (sentence[end] == ' ' || end == sentence.length()) {
                wordsArr[wordCount++] = sentence.substr(start, end - start);
                start = end + 1;
            }
        } else {
            start++;
        }
    }

    outWordsArrSize = wordCount;
}
