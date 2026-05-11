/*
Problem-3: Search Query

WAP that takes an array of size n and q queries as input. For each query you will be given a number. For each query you have to print ‘YES’ if the number is present in the array, otherwise print ‘No’. Solve this problem in an optimized way.

Sample input
Sample output
5
6 3 2 1 8

4

1
5
2
9
YES
NO
YES
NO


Explanation: You are given an array of size 5 and 4 queries. In the first query you are given 1. 1 is present in the array so we print ‘YES’. In the second query 5 is not present in the array so we print ‘NO’. Third and Fourth query are similar.
*/
// https://docs.google.com/document/d/1SInJU7vWMgmLO-lulcQ2aGAeLze-0632fS8Iz-14t_A/edit?tab=t.0#heading=h.bmsm3ze9seqz

#include <bits/stdc++.h>
using namespace std;

int main() {
    int len; cin >> len;
    vector<int> v(len);
    for(auto it = v.begin(); it < v.end(); it++) 
        cin >> *it;
    int queries; cin >> queries;


    // Sorting array O(n logn)
    sort(v.begin(), v.end());

    // Checking O(n logn)
    while(queries--) {
        int target; cin >> target;
        bool flag = false;

        int left = 0, right = len - 1;
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

        // Printing
        cout << (flag ? "YES" : "NO") << endl;

    // Outer while ends
    }
    
    
    return 0;
}
