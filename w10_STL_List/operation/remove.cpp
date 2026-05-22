#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {10,20,30,10,40,10};

    // Remove every (val) from list
    l.remove(10);

    // Printing
    for(int val : l) cout << val << " ";
    cout << endl;

    return 0;
}
