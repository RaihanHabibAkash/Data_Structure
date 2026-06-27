#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;
    int val;
    while(cin >> val) s.insert(val); // O(log N)

    if(s.count(10)) cout << "Ache" << endl; // O(log N)
    else cout << "Nai" << endl;

    return 0;
}
