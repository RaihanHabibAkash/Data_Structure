/*
Problem 2: Equilibrium Index 
Description: Given an array of integers, find the equilibrium index. An equilibrium index is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes.
Example:
Input
Output
7
-7 1 5 2 -4 3 0
3


Explanation: At index 3, the sum of elements before it is -1 and after it is also -1

-7
1
5
2
-4
3
0

 	0	   1		2		3		4		5		6
Sum of before index 3  = -7 + 1 + 5 = -1
Sum of after index    3	  = -4 + 3 + 0 = -1
*/
// https://docs.google.com/document/d/1SInJU7vWMgmLO-lulcQ2aGAeLze-0632fS8Iz-14t_A/edit?tab=t.0#heading=h.6dv23tfc0lbu

#include <bits/stdc++.h>
using namespace std;

int main() {
    int len; cin >> len;
    vector<int> v(len);
    for(auto it = v.begin(); it < v.end(); it++)
        cin >> *it;
    
    // Prefix sum
    vector<int> prefix(len);
    prefix[0] = v[0];
    for(int i = 1; i < len; i++)
        prefix[i] = prefix[i - 1] + v[i];


    // For equilibrium Index
    int ans = -1;
    for(int i = 1; i < len - 1; i++) {
        int leftSum = prefix[i - 1];
        int rightSum = prefix[len - 1] - prefix[i];
        if(leftSum == rightSum) {
            ans = i;
            break;
        }
    }          

    // Printing
    cout << ans << endl;

    return 0;
}
