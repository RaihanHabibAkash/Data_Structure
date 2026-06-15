#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    // Taking heap input
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    // New value insert in heap
    v.push_back(4);

    // New val in current index now, but tracking the child / current index
    int curIdx = v.size() - 1;

    while(curIdx > 0) {
        int parIdx = (curIdx - 1) / 2;

        // Swap values if the parrent value is greater than child value, else out of the loop
        if(v[parIdx] > v[curIdx]) swap(v[parIdx], v[curIdx]);
        else break;

        // Update the current index every time
        curIdx = parIdx;
    }

    // Printing the Heap
    for(int x : v) cout << x << " ";
    cout << endl;

    return 0;
}
