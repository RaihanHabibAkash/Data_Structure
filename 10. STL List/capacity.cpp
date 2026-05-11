#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {1,2,3,4,5};

    // size()=> Returns size of the list
    cout << l.size() << endl;

    // clear()=> Clear the list element, do not delete memory
    l.clear();
    cout << l.size() << endl;

    // empty()=> return true/false based on the list is empty or not
    cout << (l.empty() ? "Empty" : "Not") << endl;

    // Resize with extra value 0
    list<int> l2 = {1,2,3,4,5};
    l2.resize(8);
    for(int val : l2) cout << val << " ";
    cout << endl;
    // Resize to small
    l2.resize(3);
    for(int val : l2) cout << val << " ";
    cout << endl;
    // Resize with extra value 100
    l2.resize(5, 100);
    for(int val : l2) cout << val << " ";
    cout << endl;

    return 0;
}
