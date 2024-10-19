#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Money {
    long all_cents;
public:
    //overload operators
    Money operator+(const Money& other) const { return Money(0, all_cents + other.all_cents); }
    Money operator-(const Money& other) const { return Money(0, all_cents - other.all_cents); }
    Money operator-() const { return Money(0, -all_cents); }
    bool operator==(const Money& other) const { return all_cents == other.all_cents; }
    bool operator<(const Money& other) const { return all_cents < other.all_cents; }
    bool operator>(const Money& other) const { return all_cents > other.all_cents; }
    Money& operator+=(const Money& other);
    Money& operator-=(const Money& other);
    
    //input & output
    friend istream& operator>>(istream& ins, Money& amount);
    friend ostream& operator<<(ostream& outs,const Money& amount);

    //constructors
    Money() : all_cents(0) {}
    Money(long dollars, int cents): all_cents(100 * dollars + cents) {}
    Money(long dollars) : all_cents(100 * dollars) {}

    //accessors & mutators
    double get_value() const { return all_cents * 0.01; }
};

class Check {
    int check_number;
    Money check_amount;
    bool is_cashed;
public:
    //constructors
    Check() : check_number(0), check_amount(), is_cashed(false) {}
    Check(int number, Money amount, bool is_cashed) : check_number(number), check_amount(amount), is_cashed(is_cashed) {}

    //input & output
    void input();
    void output() const;
    
    //accessors and mutators
    int get_check_number() const { return check_number; }
    Money get_check_amount() const { return check_amount; }
    bool get_is_cashed() const { return is_cashed; }

    void set_check_number(int new_check_number) { check_number = new_check_number; }
    void set_check_amount(Money new_check_amount) { check_amount = new_check_amount; }
    void set_is_cashed(bool new_is_cashed) { is_cashed = new_is_cashed; }
};

void sort_checks(vector<Check>& checks);

int main() {
    cout << "Welcome to the checkbook balancing program.\n";
    vector<Check> checks;
    cout << "Please enter the number of checks: ";
    int num_of_checks;
    cin >> num_of_checks;

    for (int i = 0; i < num_of_checks; i++) {
        cout << "\nLoading check #" << i + 1 << " of " << num_of_checks << endl;
        Check check;
        check.input();
        checks.push_back(check);
    }

    vector<Money> deposits;
    cout << "\nPlease enter the number of deposits: ";
    int num_of_deposits;
    cin >> num_of_deposits;

    for (int i = 0; i < num_of_deposits; i++) {
        cout << "\nLoading deposit #" << i + 1 << " of " << num_of_deposits << endl;
        cout << "Please enter the deposit amount in the format $dollars.cents: ";
        Money deposit;
        cin >> deposit;
        deposits.push_back(deposit);
    }

    Money old_balance;
    cout << "\nPlease enter the old account balance in the format $dollars.cents: ";
    cin >> old_balance;

    Money new_balance;
    cout << "Please enter the new account balance in the format $dollars.cents: ";
    cin >> new_balance;

    vector<Check> cashed_checks;
    vector<Check> uncashed_checks;

    for (int i = 0; i < checks.size(); i++) {
        if (checks[i].get_is_cashed()) {
            cashed_checks.push_back(checks[i]);
        } else {
            uncashed_checks.push_back(checks[i]);
        }
    }

    Money total_cashed_checks;
    for (int i = 0; i < cashed_checks.size(); i++) {
        total_cashed_checks += cashed_checks[i].get_check_amount();
    }

    Money total_deposits;
    for (int i = 0; i < deposits.size(); i++) {
        total_deposits += deposits[i];
    }

    Money calculated_new_balance = old_balance + total_deposits - total_cashed_checks;
    Money difference = calculated_new_balance - new_balance;

    cout << "\nTotal of cashed checks: " << total_cashed_checks << endl;
    cout << "Total of deposits: " << total_deposits << endl;
    cout << "Calculated new balance: " << calculated_new_balance << endl;
    cout << "Difference from bank's new balance: " << difference << endl;

    cout << "\nCashed checks: \n";

    if (cashed_checks.size() > 0) {
        sort_checks(cashed_checks);
        for (int i = 0; i < cashed_checks.size(); i++) {
            cashed_checks[i].output();
        }
    }

    else if (cashed_checks.size() == 0) {
        cout << "None\n";
    }

    cout << "\nUncashed checks: \n";

    if (uncashed_checks.size() > 0) {
        sort_checks(uncashed_checks);
        for (int i = 0; i < uncashed_checks.size(); i++) {
            uncashed_checks[i].output();
        }
    } 
    
    else if (uncashed_checks.size() == 0) {
        cout << "None\n";
    }

    return 0;
}

Money& Money::operator+=(const Money& other) {
    this->all_cents += other.all_cents;
    return *this;
}

Money& Money::operator-=(const Money& other) {
    this->all_cents -= other.all_cents;
    return *this;
}

istream& operator>>(istream& ins, Money& amount) {
    char one_char, decimal_point;
    long dollars;
    int cents;
    bool is_negative = false;

    ins >> one_char;

    if (one_char == '-') {
        is_negative = true;
        ins >> one_char;
    }

    ins >> dollars >> decimal_point >> cents;

    if (one_char != '$' || decimal_point != '.' || dollars < 0 || cents < 0 || cents > 100) {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    amount.all_cents = dollars * 100 + cents;
    if (is_negative) {
        amount.all_cents = -amount.all_cents;
    }
     
    return ins;
}

ostream& operator<<(ostream& outs, const Money& amount) {
    int pos_all_cents, cents;
    long dollars;
    
    pos_all_cents = abs(amount.all_cents);
    dollars = pos_all_cents / 100;
    cents = pos_all_cents % 100;

    if ((amount.all_cents) < 0) {
        outs << '-';
    }

    outs << '$' << dollars << '.';

    if (cents < 10) {
        outs << '0';
    }

    outs << cents;

    return outs;
}

void Check::input() {
    cout << "Please enter the check number: ";
    cin >> check_number;
    cout << "Please enter the check amount in the format $dollars.cents: ";
    cin >> check_amount;
    cout << "Has the check been cashed? (Enter Y/y for yes and N/n for no): ";
    char temp;
    cin >> temp;
    if (temp == 'Y' || temp == 'y') {
        is_cashed = true;
    } else if (temp == 'N' || temp == 'n') {
        is_cashed = false;
    } else {
        cout << "Error Illegal input\n";
        exit(1);
    }
}

void Check::output() const {
    cout << "Check number: " << check_number << "    ";
    cout << "Check amount: " << check_amount << endl;
}

void sort_checks(vector<Check>& checks) {
    for (int i = 0; i < checks.size() - 1; i++) {
        for (int j = 0; j < checks.size() - 1 - i; j++) {
            if (checks[j].get_check_amount() > checks [j + 1].get_check_amount()) {
                Check temp = checks[j];
                checks[j] = checks[j + 1];
                checks[j + 1] = temp;
            }
        }
    }
}