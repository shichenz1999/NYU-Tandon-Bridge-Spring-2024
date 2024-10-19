#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Queue {
    vector<T> queue;
    int q_front;
    int q_size;
public: 
    Queue(int q_front = 0, int q_size = 0) : q_front(q_front), q_size(q_size) {}
    void push(T item);
    void pop();
    T front() { return !empty() ? queue[q_front] : T(); }
    T back() { return !empty() ? queue[q_size - 1] : T(); }
    bool empty() const { return q_size == 0; };
    void clear() { while (!empty()) pop(); }
    int size() const { return q_size; }

};

template <class T>
void Queue<T>::push(T item) {
    queue.push_back(item);
    q_size++;
}

template <class T>
void Queue<T>::pop() { 
    if (!empty()) {
        q_front++;
        q_size--;   
        
        if (empty()) {
            queue.clear();
            q_front = 0;
        }
    }
}

int main() {
    Queue<int> q;

    for (int i = 0; i < 10; ++i) {
        q.push(i);
    }

    cout << "size: " << q.size() << endl;
    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;

    return 0;
}