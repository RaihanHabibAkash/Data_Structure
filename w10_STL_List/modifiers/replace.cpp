#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {10,20,30,40,50,20,80,20};

    // 100 will be replaced with 100
    replace(l.begin(), l.end(), 20, 100);

    // Printing
    for(int val : l) cout << val << " ";
    cout << endl;

    return 0;
}
