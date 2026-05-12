#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {10,20,30,40,50,60,70,80};
    // eraseing from 3 to 6
    l.erase(next(l.begin(),2), next(l.begin(),6));

    // Printing
    for(int val : l) cout << val << " ";
    cout << endl;

    return 0;
}
