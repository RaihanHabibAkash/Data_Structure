#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    vector<int> l;
    void push(int val) {
        l.push_back(val);
    }
    void pop() {
        l.pop_back();
    }
    int top() {
        return l.back();
    }
    int size() {
        return l.size();
    }
    bool empty() {
        return l.empty();
    }
};

int main() {
    // Static stack
    Stack st;

    // Taking input
    int num;
    while(cin >> num) st.push(num);
    
    // Printing
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
