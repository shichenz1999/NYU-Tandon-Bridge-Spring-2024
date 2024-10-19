#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Node {
    string name;
    double paid;
    double balance;
    Node* next;
public:
    Node(string name = string(), double paid = 0, double balance = 0, Node* next = nullptr) : name(name), paid(paid), balance(balance), next(next) {};

    friend class LList;
};

class LList {
    Node* head;
public:
    LList(Node* head = nullptr) : head(head) {}

    //big 3
    ~LList();
    LList(const LList& rhs);
    LList& operator=(LList rhs);

    //helper func
    void clear();
    Node* copy_linked_list(const Node* head);

    //push & pop
    void push_front(Node* new_node);
    void pop_front();
    void remove(Node* node);

    //getters and setters
    Node* get_head() { return head; }
    int get_count();
    double get_total();
    double get_average();
    void update_balances();
    void print_transactions(ostream& outs); 
    void find_receiver(ostream& outs, Node* payer);
};

LList::~LList() {
    clear();
}

LList::LList(const LList& rhs) { 
    head = copy_linked_list(rhs.head);
}

LList& LList::operator=(LList rhs) {
    swap(this->head, rhs.head);
    return *this;
}

void LList::clear() {
    while(head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Node* LList::copy_linked_list(const Node* head) {
    if (!head) {
        return nullptr;
    } else {
        return new Node(head->name, head->paid, head->balance, copy_linked_list(head->next));
    }
}

void LList::push_front(Node* new_node) {
   new_node->next = head;
   head = new_node; 
}

void LList::pop_front() {
    remove(head);
}

void LList::remove(Node* node) {
    if (!node || !head) return;

    if (node == head) {
        head = head->next;
        delete node;
        return;
    }
    
    Node* temp = head;
    while (temp->next && temp->next != node) {
        temp = temp->next;
    }

    if (temp->next == node) {
        temp->next = node->next;
        delete node;
    }
}

int LList::get_count() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    return count;
}

double LList::get_total() {
    double total = 0;
    Node* temp = head;
    while (temp) {
        total += temp->paid;
        temp = temp->next;
    }

    return total;
}

double LList::get_average() {
    double total = get_total();
    int count = get_count();
    if (count == 0) return 0;
    double average = total / count;
    return average;
}

void LList::update_balances() {
    double average = get_average();
    Node* temp = head;
    while (temp) {
        temp->balance = temp->paid - average;
        temp = temp->next;
    }
}

void LList::print_transactions(ostream& outs) {
    Node* payer = head;

    while(payer) {
        if (payer->balance == 0) {
            outs << payer->name << ", you don't need to do anything" << endl;
        }
        payer = payer->next;
    }

    payer = head;
    
    while (payer) {
        if (payer->balance < 0) {
            find_receiver(outs, payer);
        }
        payer = payer->next;
    }

    outs << "In the end, you should all have spent around $" << get_average() << endl;
}

void LList::find_receiver(ostream& outs, Node* payer) {
    Node* receiver = head;
    while(payer->balance < 0 && receiver) {
        if (receiver->balance > 0) {
            double transfer = min(-payer->balance, receiver->balance);
            outs << payer->name << ", you give " << receiver->name << " $" << transfer << endl;
            payer->balance += transfer;
            receiver->balance -= transfer;
        } else {
            receiver = receiver -> next;
        }
        
    }
}

void open_input_file(ifstream& infile) {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    infile.open(filename);
    while(!infile) {
        cout << "Bad filename.\n";
        cout << "Enter the filename: ";
        cin >> filename;
        infile.clear();
        infile.open(filename);
    }
}

void read_input_file(ifstream& infile, LList& bills) {
    double paid;
    string name;
    while (infile >> paid) {
        infile.ignore(9999, ' ');
        getline(infile, name);
        bills.push_front(new Node(name, paid));
    }
    bills.update_balances();
}

int main() {
    ifstream infile;
    LList bills;
    open_input_file(infile);
    read_input_file(infile, bills);
    infile.close();
    bills.print_transactions(cout);
    return 0;
}