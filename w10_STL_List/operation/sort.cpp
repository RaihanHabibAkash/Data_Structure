#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l1 = {40,50,10,20,100,30,40,40};
    // Sort in assending order
    l1.sort();
    // Printing
    for(int val : l1) cout << val << " ";
    cout << endl;


    list<int> l2 = {40,50,10,20,100,30,40,40};
    // Sort in dessending order
    l2.sort(greater<int>());
    // Printing
    for(int val : l2) cout << val << " ";
    cout << endl;

    return 0;
}
