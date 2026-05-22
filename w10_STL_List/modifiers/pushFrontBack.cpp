#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {1,2,3};
    l.push_front(100);
    l.push_back(200);

    // Printing
    for(int val : l) cout << val << " ";
    cout << endl;

    return 0;
}
