#include <bits/stdc++.h>
using namespace std;

int main() {
    // Taking input
    int len, target; cin >> len >> target;
    vector<int> v(len);
    for(int i = 0; i < len; i++) cin >> v[i];

    // Checking for first
    int left = 0, right = len - 1, first = -1;
    while(left <= right) {
        int mid = (left + right) / 2;

        if(v[mid] == target) {
            first = mid;
            right = mid - 1;
        } 
        else if(v[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    // Checking for last
    left = 0, right = len - 1;
    int last = -1;
    while(left <= right) {
        int mid = (left + right) / 2;

        if(v[mid] == target) {
            last = mid;
            left = mid + 1;
        }
        else if(v[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    // Printing
    int count = last - first + 1;
    cout << count << endl;

    return 0;
}