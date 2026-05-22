// Left side array == right side array

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Taking input
    int len; cin >> len;
    vector<int> v(len);
    for(int i = 0; i < len; i++) cin >> v[i];

    // Prefix sum
    vector<int> prefix(len);
    prefix[0] = v[0];
    for(int i = 1; i < len; i++)
        prefix[i] = prefix[i - 1] + v[i];
    
    // For Equilibrium Index
    int totalSum = prefix[len - 1];
    bool flag = false;
    for(int i = 0; i < len; i++) {
        int rightSum = totalSum - prefix[i];

        if(rightSum == prefix[i]) {
            // Found the Equilibrium Index == i
            flag = true;
            break;
        }
    // For loop ends
    }

    // Printing
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}