/*
J. Count Letters
time limit per test2 seconds
memory limit per test64 megabytes
Given a string S. Determine how many times does each letter occurred in S.

Input
Only one line contains the string S (1 ≤ |S| ≤ 107) where |S| is the length of the string and it consists of only lowercase English letters.

Output
For each character that appears in S, print a single line that contains the following format: "X : Y" where X is the letter and Y is the number of times that letter X occurred in S.

Note: you must print letters in ascending order.

Examples
InputCopy
aaabbc
OutputCopy
a : 3
b : 2
c : 1
InputCopy
regff
OutputCopy
e : 1
f : 2
g : 1
r : 1
*/
// https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/J

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Taking input
    string s; cin >> s;

    // Taking freq array
    vector<int> freq(26, 0);

    // Freq array increment
    for(char c : s) {
        int index = c - 'a';
        freq[index]++;
    } 

    int cnt = 0;
    for(auto it = freq.begin(); it < freq.end(); it++, cnt++) {
        if(*it != 0) {
            char c = cnt + 'a';
            cout << c << " : " << *it << endl;
        }
    }

    return 0;
}