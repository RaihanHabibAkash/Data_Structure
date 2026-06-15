#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    // Input of Heap
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    // Insert the new val in Heap
    v.push_back(18);
    int curIdx = v.size()-1;

    while(curIdx > 0) {
        // Parrent index of the child index
        int parrentInx = (curIdx - 1) / 2;
        
        // If the parrent is less than chil swap, else out of the loop
        if(v[parrentInx] < v[curIdx]) swap(v[parrentInx], v[curIdx]);
        else break;
        
        // Set current index to the parrentindex, because of swap
        curIdx = parrentInx;
    }

    // Print the Heap
    for(int x : v) cout << x << " ";
    cout << endl;

    return 0;
}
