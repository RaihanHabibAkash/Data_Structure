#include <bits/stdc++.h>
using namespace std;

int main() {
    // Sum of 1-n
    int n; cin >> n;
    // For sum
    int sum = 0;
    for(int i = 1; i <= n; i++) sum += i;
    // printing
    cout << sum << endl;


    // O(1)
    sum = ((n + 1) * n) / 2;
    cout << sum << endl;

    return 0;
}