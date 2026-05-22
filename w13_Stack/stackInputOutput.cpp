#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    vector<int> v;
    void push(int val) {
        v.push_back(val);
    }
    void pop() {
        v.pop_back();
    }
    int top() {
        return v.back();
    }
    int size() {
        return v.size();
    }
    bool empty() {
        return v.empty();
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
