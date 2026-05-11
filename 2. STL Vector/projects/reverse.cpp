/*
F. Reversing
time limit per test1 second
memory limit per test64 megabytes
Given a number N and an array A of N numbers. Print the array in a reversed order.

Note:

*Don't use built-in-functions.

Input
First line contains a number N (1 ≤ N ≤ 103) number of elements.

Second line contains N numbers (0 ≤ Ai ≤ 109).

Output
Print the array in a reversed order.

Examples
InputCopy
4
5 1 3 2
OutputCopy
2 3 1 5 
InputCopy
5
1 2 3 4 5
OutputCopy
5 4 3 2 1 
*/
// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/F

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Taking input
    int len; cin >> len;
    vector<int> v(len);
    for(auto it = v.begin(); it < v.end(); it++) 
        cin >> *it;
    
    // Reversing the 
    // reverse(v.begin(), v.end());
    for(auto it = v.begin(), pt = v.end()-1; it < pt; it++, pt--){
        int temp = *it;
        *it = *pt;
        *pt = temp;
    }

    for(int x : v) cout << x << " ";
    cout << endl;

    return 0;
}