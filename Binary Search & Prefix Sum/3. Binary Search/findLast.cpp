#include <bits/stdc++.h>
using namespace std;

int main() {
    // Target input
    int len, target; cin >> len >> target;
    vector<int> v(len);
    for(int i = 0; i < len; i++) cin >> v[i];

    // Binary search
    int left = 0, right = len - 1, last = -1;

    while(left <= right) {
        int mid = (left + right) / 2;
        if(v[mid] == target) {
            last = mid;
            left = mid + 1;  
        } 
        else if(v[mid] < target) left = mid + 1;
        else right = mid - 1;
    
    // While ends
    }

    // Print 
    cout << last << endl;

    return 0;
}