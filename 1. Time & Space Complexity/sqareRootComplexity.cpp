#include <bits/stdc++.h>
using namespace std;

int main() {
    int times; cin >> times;
    for(int i = 1; i <= sqrt(times); i++) cout << i << " ";
    cout << endl;

    // Divisors 36 times
    int n = 36;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) cout << i << " ";
    }
    cout << endl;

    // Divisorts 6 times
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) cout << i << " " << n / i << " ";
    }
    cout << endl;

    return 0;
}
