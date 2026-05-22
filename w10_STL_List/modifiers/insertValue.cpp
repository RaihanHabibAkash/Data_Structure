#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {10,20,30,40};

    l.insert(next(l.begin(), 3), 100);

    // Printing
    for(int val : l) cout << val << " ";
    cout << endl;


    return 0;
}
