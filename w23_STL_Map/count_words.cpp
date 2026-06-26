#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; getline(cin, s);
    stringstream ss(s); string word; // getting each word
    map<string, int> mp; // key value pair

    while(ss >> word) mp[word]++;

    for(auto it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " " << it->second << endl;

    return 0;
}