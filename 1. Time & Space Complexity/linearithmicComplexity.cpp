#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    for(int i = 1 ; i <= n; i++) { // --> n
        for(int j = 1; j <= n; j *= 2) { // --> log n
            cout << "Hlow" << endl;
        }
    }
    return 0;
}

// n * logn = n logn