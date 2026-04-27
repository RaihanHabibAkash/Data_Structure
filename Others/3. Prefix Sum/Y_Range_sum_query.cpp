/*
Y. Range sum query
time limit per test1.5 seconds
memory limit per test256 megabytes
Given 2 numbers N
 and Q
, an array A
 of N
 number and Q
 number of pairs L
, R
. For each query Q
 print a single line that contains the summation of all numbers from index L
 to index R
.

Input
First line contains two numbers N
, Q
 (1≤N,Q≤105)
 where N
 is number of elements in A
 and Q
 is number of query pairs.

Second line contains N
 numbers(1≤Ai≤109)
.

Next Q
 lines contains L,R
 (1≤L≤R≤N)
.

Output
For each query Q
 print a single line that contains the summation of all numbers from index L
 to index R
.

Examples
InputCopy
6 3
6 4 2 7 2 7
1 3
3 6
1 6
OutputCopy
12
18
28
InputCopy
4 3
5 5 2 3
1 3
2 3
1 4
OutputCopy
12
7
15
*/
// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/Y


/*Brute Force
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Taking input
    int len, query; cin >> len >> query;
    vector<int> v(len + 1);
    for(int i = 1; i <= len; i++) cin >> v[i];

    // Query times
    while(query--) {
        int l, r; cin >> l >> r;
        int sum = 0;
        
        // Running from l-r
        for(int i = l; i <= r; i++) sum += v[i];

        // Printing
        cout << sum << endl;
    }

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Taking input
    int len, query; cin >> len >> query;
    vector<int> v(len + 1);
    for(int i = 1; i <= len; i++) cin >> v[i];

    // Taking prefix sum
    vector<long long> prefix(len + 1);
    prefix[1] = v[1];
    for(int i = 2; i <= len; i++) prefix[i] = prefix[i - 1] + v[i];

    while(query--) {
        // Taking l, r index input
        int left, right; cin >> left >> right;
        
        // Taking caare of corner case of left == 1st index.
        long long sum = 0;
        if(left == 1) sum = prefix[right];
        else sum = prefix[right] - prefix[left - 1];

        // Printing
        cout << sum << endl;
    }

    return 0;
}