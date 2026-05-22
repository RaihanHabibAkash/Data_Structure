#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {10,20,40,50,60};

    // returs a iterator
    auto it = find(l.begin(), l.end(),20);

    cout << (it == l.end() ? "Pai nai" : "Paisi") << endl;

    return 0;
}
