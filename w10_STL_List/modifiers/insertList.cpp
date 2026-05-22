#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {10,20,30,40,50};
    list<int> l2 = {100,200};

    l.insert(next(l.begin(),4), l2.begin(), l2.end());

    // Printing
    for(int val : l) cout << val << " ";
    cout << endl;

    return 0;
}
