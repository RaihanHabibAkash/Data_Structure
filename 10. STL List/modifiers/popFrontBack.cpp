#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {10,20,30,40,50};

    // Printing 1
    for(int val : l) cout << val << " ";
    cout << endl;

    l.pop_front();
    l.pop_back();

    // Printing 2
    for(int val : l) cout << val << " ";
    cout << endl;

    return 0;
}
