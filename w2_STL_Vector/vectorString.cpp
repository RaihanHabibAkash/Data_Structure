#include <bits/stdc++.h>
using namespace std;

int main() {
    int len; cin >> len;

    // Vector of string
    vector <string> v(len);

    // Taking input
    for(int i = 0; i < len; i++)
        cin >> v[i];
    
    for(string s : v)
        cout << s << endl;

    return 0;
}
