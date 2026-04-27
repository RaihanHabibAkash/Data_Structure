/*
Z. Binary Search
time limit per test1 second
memory limit per test256 megabytes
Given 2 numbers N
 and Q
, array A of N numbers and Q queries each one contains a number X
.

For each query print a single line that contains "found" if the number X
 exists in array A
 otherwise, print "not found".

Input
First line contains two numbers N
, Q
 (1≤N,Q≤105)
.

Second line contains N
 numbers (1≤Ai≤109)
.

Next Q
 lines contains X
 (1≤X≤109)
.

Output
Print the answer for each query in a single line.

Example
InputCopy
5 3
1 5 4 3 2
5
3
6
OutputCopy
found
found
not found
*/
// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/Z

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Taking input
    int len, times; cin >> len >> times;

    // Taking array
    int arr[len];
    for(int i = 0; i < len; i++) cin >> arr[i];

    for(int i = 0; i < times; i++) {
        int x = 0; cin >> x;

        // Checking
        bool flag = false;
        for(int i = 0; i < len; i++) {
            if(arr[i] == x) {
                flag = true;
                break;
            // If ends
            }
        // For loop ends
        }
        if(flag == true) cout << "found" << endl;
        else cout << "not found" << endl;

    // Outer for loop ends
    }

    return 0;
}