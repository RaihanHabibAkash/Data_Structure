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
    int len, queries; cin >> len >> queries;
    vector<int> v(len);
    for(int i = 0; i < len; i++) cin >> v[i];

    // Sorting the array]
    sort(v.begin(), v.end());

    while(queries--) {
        // Taking target each time
        int target; cin >> target;

        // For Searching
        int left = 0,
            right = len - 1;
        bool flag = false;

        // Searching
        while(left <= right) {
            int mid = (left + right) / 2;
            if(v[mid] == target) {
                flag = true;
                break;
            } 
            else if(v[mid] < target) left = mid + 1;
            else right = mid - 1; 
        // Inner while ends
        }

        if(flag) cout << "found" << endl;
        else cout << "not found" << endl;

    // While ends
    }

    return 0;
}