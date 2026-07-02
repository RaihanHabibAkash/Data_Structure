#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<string, int>> v; 
    for(int i = 0; i < n; i++) {
        string s; int val; cin >> s >> val;
        v.push_back({s, val});
    }
    for(int i = 0; i < n; i++)
        cout << v[i].first << " " << v[i].second << endl;

    return 0;
}
