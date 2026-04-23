#include <bits/stdc++.h>
using namespace std;

int main() {
    // Taking input
    int len, target; cin >> len >> target;
    vector<int> v(len);
    for(int i = 0; i < len; i++) cin >> v[i];

    // Checking
    int left = 0,
        right = len - 1;
    bool flag = false;
    while(left <= right) {
        int mid = (left + right) / 2;

        if(v[mid] == target){
            flag = true;
            break;
        } 
        else if(v[mid] < target) left = mid + 1;
        else right = mid - 1;
    // While ends
    }

    if(flag) cout << "Found" << endl;
    else cout << "Not found" << endl;

    return 0;
}