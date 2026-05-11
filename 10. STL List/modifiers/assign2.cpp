#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l1 = {1,2,3,4,5};
    list<int> l2;

    // Assinging
    l2.assign(l1.begin(), l1.end());

    // Printing
    for(int val : l2) cout << val << " ";
    cout << endl;

    return 0;
}
