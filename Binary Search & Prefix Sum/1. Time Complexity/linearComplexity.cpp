#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; // --> 1 + 1 = 2
    for(int i = 0; i < n / 2; i++) cout << i << " "; // --> n / 2 = n
    cout << endl; // --> 1
    for(int i = 0; i < 2*n; i++) cout << i << " "; // --> n + n = 2n = n
    cout << endl; // --> 1
    for(int i = 0; i < n; i++) cout << i << " "; // --> n

    return 0; // --> 1
}
// Order(4 + 2n) = O(n).