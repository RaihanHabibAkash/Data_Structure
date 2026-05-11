#include <bits/stdc++.h>
using namespace std;

int main() {
    int times; cin >> times;
    for(int i = 1; i <= times; i *= 2) cout << i << " ";
    cout << endl;

    for(int i = times; 1 <= i; i /= 2) cout << i << " ";
    cout << endl;

    return 0;
}
