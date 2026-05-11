#include <bits/stdc++.h>
using namespace std;

int main() {
    int len; cin >> len;

    // vector<int> v(len);
    // for(int i = 0; i < len; i++) cin >> v[i];
    
    vector<int> v;
    for(int i = 0; i < len; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    for(int &x : v) cout << x << " ";
    cout << endl;

    return 0;
}
