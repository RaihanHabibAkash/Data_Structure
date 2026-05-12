#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {10,20,30,40,50};

    // .back() => Access tail
    cout << l.back() << endl;

    // .front() => Access head
    cout << l.front() << endl;

    // next() => return pointer || iterator
    cout << *next(l.begin(), 2) << endl;

    return 0;
}
