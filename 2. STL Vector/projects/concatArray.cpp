/*
L. New Array
time limit per test1 second
memory limit per test256 megabytes
Given two arrays A
 and B
 of size N
. Print a new array C
 that holds the concatenation of array B
 followed by array A
.

Note: Solve this problem using function.

Input
First line will contain a number N
 (1≤N≤103)
.

Second line will contain N
 numbers (1≤Ai≤105)
 array A
 elements.

Third line will contain N
 numbers (1≤Bi≤105)
 array B
 elements.

Output
Print array C
 elements separated by space.

Example
InputCopy
2
1 2
3 4
OutputCopy
3 4 1 2 
*/
// https://codeforces.com/group/MWSDmqGsZm/contest/223205/problem/L

#include <bits/stdc++.h>
using namespace std;

vector<int> func(vector<int> &v2, vector<int> &v1) {
    // Inserting value
    for(auto it = v2.begin(); it < v2.end(); it++)
        cin >> *it;
    for(auto it = v1.begin(); it < v1.end(); it++)
        cin >> *it;

    // Concating the 2 vector
    v1.insert(v1.end(), v2.begin(), v2.end());

    // Return vector
    return v1;
}

int main() {
    // Taking input
    int len; cin >> len;

    // Declearing vector
    vector<int> v2(len);
    vector<int>v1(len);

    vector<int> v = func(v2, v1);

    // Printing
    for(int x : v) cout << x << " ";
    cout << endl;

    return 0;
}