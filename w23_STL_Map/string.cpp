#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string,int> mp;
    mp["Raihan"] = 5;
    mp["Habib"] = 100;
    mp["Akash"] = 500;

    for(auto it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " " << it->second << endl;

    cout << "After loop -> " << mp["Akash"] << " " << mp["NoVal"] << endl;   
        
    return 0;
}
