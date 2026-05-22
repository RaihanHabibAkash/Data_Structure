// https://docs.google.com/document/d/1KOilh4Vb-PN21_kD7ejLA6qx6AhVbHlq/edit
/*
Question: Take a queue of size N as input. You need to copy those elements in another queue in reverse order. You might use stack here. You should use STL to solve this problem. After copying in another queue, print the elements of that queue.

Sample Input

5
10 20 30 40 50

Sample Output
50 40 30 20 10
*/



#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q; 
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int val; cin >> val;
        q.push(val);
    }

    // Stack to get the reverse order
    stack<int> st;
    while(!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    // Inserting value in new q (It will be reverse)
    queue<int> q2;
    while(!st.empty()) {
        q2.push(st.top());
        st.pop();
    }

    // Printing
    while(!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;

    return 0;
}
