#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> freq;
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++) freq[s[i]]++;

    int q; cin >> q;
    while(q--) {
        char c; cin >> c;
        cout << freq[c] << endl;
    }

    return 0;
}
// input: 
/*
akashbroTmikoiaaaa
5
Taoef
*/