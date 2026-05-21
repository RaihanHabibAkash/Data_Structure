#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
    list<int> l;

    void push(int val) {
        l.push_back(val);
    }
    void pop() {
        l.pop_front();
    }
    int back() {
        return l.back();
    }
    int front() {
        return l.front();
    }
    int size() {
        return l.size();
    }
    bool empty() {
        return l.empty();
    }
};

int main() {
    Queue q;
    int val;
    while(cin >> val) q.push(val);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}