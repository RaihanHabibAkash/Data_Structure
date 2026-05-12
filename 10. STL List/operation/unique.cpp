#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {40,50,40,20,10,40,10,20};
    // Sort list theke duplicate remove kore
    l.sort();
    l.unique();

    // Printing
    for(int val : l) cout << val << " ";
    cout << endl;

    return 0;
}
