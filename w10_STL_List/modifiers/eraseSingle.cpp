#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {10,20,30,40,50,60};
    // Delete one value, from begin()+3 pointer
    l.erase(next(l.begin(), 3));

    // Printing
    for(int val : l) cout << val << " ";
    cout << endl;


    return 0;
}
