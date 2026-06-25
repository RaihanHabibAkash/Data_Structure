#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(20); // 20
    pq.push(10); // 10 20
    pq.push(8); // 8 20 10
    cout << pq.top() << endl; // 8
    pq.pop(); // 10 20
    cout << pq.top() << endl; // 10
    pq.push(7); // 7 20 10
    pq.push(5); // 5 7 10 20
    cout << pq.top() << endl; // 5

    return 0;
}
