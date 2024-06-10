#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    int n, x, min, max, guessesLeft;

    srand(time(0));
    x = rand() % 100 + 1;
    guessesLeft = 5;
    min = 1;
    max = 100;

    cout << "I thought of a number between 1 and 100! Try to guess it." << endl;

    while (true) {
        cout << "Range: [" << min << ", " << max << "], Number of guesses left: " << guessesLeft << endl;
        cout << "Your guess: ";
        cin >> n;
        guessesLeft--;
        
        if (n == x) {
            cout << "Congrats! You guessed my number in " << 5 - guessesLeft << " guesses." << endl;
            break;
        }

        if (guessesLeft == 0) {
            cout << "Out of guesses! My number is " << x << endl;
            break;
        }

        if (n < x) {
            cout << "Wrong! My number is bigger." << endl;
            cout << endl;
            if (n >= min) {
                min = n + 1;
            }
        } else if (n > x) {
            cout << "Wrong! My number is smaller." << endl;
            cout << endl;
            if (n <= max) {
                max = n - 1;
            }
        }
    }

    return 0;
}
