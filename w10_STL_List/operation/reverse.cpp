#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {10,20,30,40,50,70};
    // Reversing whole list 
    l.reverse();

    // Printing
    for(int val : l) cout << val << " ";
    cout << endl;

    return 0;
}
