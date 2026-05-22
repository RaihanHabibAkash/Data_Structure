#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5,6};

    vector<int>::iterator it = find(v.begin(), v.end(), 5);
    // auto find(v.begin(), v.end(), 8);

    if(it == v.end()) cout << "Pai nai" << endl;
    else cout << "Paisi" << " " << *it << endl;

    // Changing value
    *it = 50;

    for(int x : v) cout << x << " ";
    cout << endl;
    
    return 0;
}
