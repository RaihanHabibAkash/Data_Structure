/*
D. Counting Elements
time limit per test1 second
memory limit per test256 megabytes
You are given an array a
 of n
 integers, count the number of element ai
 in the array such that ai+1
 is also exists in the array a
 .

If there're duplicates in a
, count them separately.

Input
The first line contains an integer n(1≤n≤103)
 the number of elements in the array a

The second line contains n
 integers ai(0≤Xi≤103)
 the elements of the array a
.

Output
output the number of elements as descriped above.

Examples
InputCopy
3
4 4 5
OutputCopy
2
InputCopy
3
1 2 3
OutputCopy
2
InputCopy
8
1 1 3 3 5 5 7 7
OutputCopy
0
InputCopy
6
1 3 2 3 5 0
OutputCopy
3
*/
// https://codeforces.com/group/MWSDmqGsZm/contest/329103/problem/D

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Taking input
    int len; cin >> len;
    vector<int> v(len);

    // Freq array
    vector<int> freq(1000, 0);

    // Taking input for array
    for(int &x : v) {
        cin >> x;
        freq[x]++;
    }

    // For couting
    int count = 0;
    for(auto it = freq.begin(); it < freq.end(); it++) {
        if(*(it + 1) != 0) count += *it;
    }

    // Printing
    cout << count << endl;

    return 0;
}