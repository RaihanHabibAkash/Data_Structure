#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;
    int val;
    while(cin >> val) s.insert(val); // O(Log N)

    for(auto it = s.begin(); it != s.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}
