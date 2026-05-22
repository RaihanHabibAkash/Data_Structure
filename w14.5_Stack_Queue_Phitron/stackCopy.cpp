// https://docs.google.com/document/d/1KOilh4Vb-PN21_kD7ejLA6qx6AhVbHlq/edit
/*
Question: Take a stack of size N as input and copy those elements to another stack to get the values in the order they were inserted and print them. You should use STL to solve this problem.


Sample Input

5
10 20 30 40 50

Sample Output
10 20 30 40 50
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int val; cin >> val;
        st.push(val);
    }

    // Stack copied in reverse
    stack<int> st1;
    while(!st.empty()) {
        st1.push(st.top());
        st.pop();
    }

    // Printing
    stack<int> st2;
    while(!st1.empty()) {
        cout << st1.top() << " ";
        st1.pop();
    }
    cout << endl;

    return 0;
}
