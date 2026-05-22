/*
Question: Take a stack of size N and a queue of size M as input. Then check if both of them are the same or not in the order of removing. You should use STL to solve this problem.

Sample Input

5
10 20 30 40 50
5
10 20 30 40 50

5
10 20 30 40 50
4
10 20 30 40

5
10 20 30 40 50
5
50 40 30 20 10


Sample Output
NO
NO
YES
*/

#include <bits/stdc++.h>
using namespace std;

bool check(stack<int> st, queue<int> q) {
    if(st.size() != q.size()) return false;

    // size are same
    while(!q.empty()) {
        if(st.top() != q.front()) return false;
        st.pop();
        q.pop();
    }
    return true;
}

int main() {
    stack<int> st; queue<int> q;
    // Taking input for Stack
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int val; cin >> val;
        st.push(val);
    }
    // Taking input for queue
    cin >> n;
    for(int i = 0; i < n; i++) {
        int val; cin >> val;
        q.push(val);
    }

    // Reversing Stack because this need to compare
    stack<int> st1;
    while(!st.empty()) {
        // Pushing value to st to st1(reverse order auto) 
        st1.push(st.top());
        st.pop();
    }

    // Printing
    cout << ( (check(st1, q)) ? "YES" : "NO" ) << endl;

    return 0;
}