#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> pq;
    pq.push(10); // 10
    pq.push(20); // 20 10
    cout << pq.top() << endl; // 20
    pq.push(100); // 100 10 20
    cout << pq.top() << endl; // 100
    pq.pop(); // 20 10
    pq.pop(); // 10
    cout << pq.top() << endl; // 10

    return 0;
}
