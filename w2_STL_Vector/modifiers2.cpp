#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> v = {1,2,3,4,5};
    
    v.pop_back();
    v.pop_back();
    for(int x : v) cout << x << " ";
    cout << endl;

    v.push_back(10);
    for(int x : v) cout << x << " ";
    cout << endl;

    return 0;
}
