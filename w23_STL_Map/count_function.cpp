#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> mp;
    mp["Akash"] = 100;
    mp["Raihan"] = 200;
    mp ["Bro"] = 0;

    if(mp.count("Bro")) cout << "Ache" << endl;
    else cout << "Nai" << endl;

    return 0;
}
