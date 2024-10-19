#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

bool check_symbol_balance(ifstream& infile) {
    string str;
    char ch;
    bool has_begun;
    stack<char> symbols;
    
    while(infile >> str) {
        if (str == "begin") {
            has_begun = true;            
        } else if (has_begun && str == "end") {
            return symbols.empty();
        } else if (has_begun) {
            for (auto ch : str) {
                if (ch == '{' || ch == '[' || ch == '(') {
                    symbols.push(ch);
                } else if (ch == '}' || ch == ']' || ch == ')') {
                    if (symbols.empty()) {
                        return false;
                    }
            
                    char last_symbol = symbols.top();
                    symbols.pop();

                    if ((ch == '}' && last_symbol !='{') || (ch == ']' && last_symbol != '[') || (ch == ')' && last_symbol !='(')) {  
                        return false;
                    }
                }
            }
        }
    }
    return false;
}

void open_input_file(ifstream& infile) {
    string filename;
    cout << "Please enter the file name: ";
    cin >> filename;
    infile.open(filename);
    while (!infile) {
        cout << "Bad filename!\n";
        cout << "Please enter the file name: ";
        cin >> filename;
        infile.clear();
        infile.open(filename);
    }
}

int main() {
    ifstream infile;
    open_input_file(infile);

    if (check_symbol_balance(infile)) {
        cout <<  "All symbols are balanced!" << endl;
    } else {
        cout << "The symbols are NOT balanced!" << endl;
    }
    return 0;
}