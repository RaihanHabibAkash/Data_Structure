/*
C. Replacement
time limit per test1 second
memory limit per test256 megabytes
Given a number N and an array A of N numbers. Print the array after doing the following operations:

Replace every positive number by 1.
Replace every negative number by 2.
Input
First line contains a number N (2 ≤ N ≤ 1000) number of elements.

Second line contains N numbers (-105  ≤  Ai  ≤  105).

Output
Print the array after the replacement and it's values separated by space.

Example
InputCopy
5
1 -2 0 3 4
OutputCopy
1 2 0 1 1 
*/
// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/C
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Taking input
    int len; cin >> len;

    // Taking vector
    vector<int> v(len);

    // Taking input
    for(int &x : v)
        cin >> x;

    // Changin value
    for(auto it = v.begin(); it < v.end(); it++) {
        if(*it < 0) *it = 2;
        else if(*it > 0) *it = 1;
    }

    // Printing
    for(int x : v) cout << x << " ";
    cout << endl;

    return 0;
}
