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