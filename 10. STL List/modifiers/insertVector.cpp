#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {10,20,30,40};
    vector<int> v = {100,200};

    l.insert(next(l.begin(), 3), v.begin(), v.end());

    // Printing
    for(int val : l) cout << val << " ";
    cout << endl;

    return 0;
}
