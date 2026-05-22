#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create a list with 0 elements
    list<int> l1;
    cout << l1.size() << endl;

    // Create a list with n elements, value will be garbage
    list<int> l2(5);
    cout << l2.size() << endl;

    // Create a list with n elements, value will be 10
    list<int> l3(5, 10);
    for(int val : l3) cout << val << " ";
    cout << endl;

    // Coping a list
    list<int> l = {1,2,3,4,5};
    list<int> l4(l);
    for(int val : l4) cout << val << " ";
    cout << endl;

    // Coping array in list
    int arr[] = {10,40,39,49};
    list<int> l5(arr, arr+3);
    for(int val : l5) cout << val << " ";
    cout << endl;

    // Coping vector in list
    vector<int> vec = {100,200,30};
    list<int> l6(vec.begin(), vec.end());
    for(int val : l6) cout << val << " ";
    cout << endl;

    return 0;
}
