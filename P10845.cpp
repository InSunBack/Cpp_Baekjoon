// Queue
// https://www.acmicpc.net/problem/10845

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Queue {
    
    public:
    vector<int> vec;

    void push(int value);
    int pop();
    int size();
    int empty();
    int front();
    int back();

};

void Queue::push(int value) {
    vec.push_back(value);
}

int Queue::pop() {
    if (vec.size() == 0) {
        return -1;
    }
    int front = vec.front();
    vec.erase(vec.begin());
    return front;
}

int Queue::size() {
    return vec.size();
}

int Queue::empty() {
    if (vec.size() == 0) {
        return 1;
    } else {
        return 0;
    }
}

int Queue::front() {
    if (vec.size() == 0) {
        return -1;
    }  else {
        return vec.front();
    }
}

int Queue::back() {
    if (vec.size() == 0) {
        return -1;
    }  else {
        return vec.back();
    }
}

int main() {
    Queue q;

    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string command;
        cin >> command;

        if (command == "push") {
            int value;
            cin >> value;
            q.push(value);
        } else if (command == "pop") {
            cout << q.pop() << endl;
        } else if (command == "size") {
            cout << q.size() << endl;
        } else if (command == "empty") {
            cout << q.empty() << endl;
        } else if (command == "front") {
            cout << q.front() << endl;
        } else if (command == "back") {
            cout << q.back() << endl;
        }
    }
}
