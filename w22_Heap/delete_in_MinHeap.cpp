#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v) {
    for(int x : v) cout << x << " ";
    cout << endl;
}

void insert_at_Heap(vector<int>& v, int val) {
    v.push_back(val);
    int curIdx = v.size() - 1;

    while(curIdx > 0) {
        // Parrent index of the current index
        int parIdx = (curIdx - 1) / 2;

        // If the the parrent is less than child swap, Else out of the loop
        if(v[parIdx] > v[curIdx]) swap(v[parIdx], v[curIdx]);
        else break;

        curIdx = parIdx;
    }
}

void delete_at_Heap(vector<int>& v) {
    cout << "Deleted " << v[0] << "-> ";
    v[0] = v.back();
    v.pop_back();

    int curIdx = 0;

    while(v.size() > 1) {
        int leftIdx = (curIdx*2)+1, rightIdx = (curIdx*2)+2;

        int leftVal = INT_MAX, rightVal = INT_MAX;
        if(leftIdx < v.size()) leftVal = v[leftIdx];
        if(rightIdx < v.size()) rightVal = v[rightIdx];

        if(leftVal <= rightVal && leftVal < v[curIdx]) {
            swap(v[leftIdx], v[curIdx]);
            curIdx = leftIdx;
        }
        else if(rightVal < leftVal && rightVal < v[curIdx]) {
            swap(v[rightIdx], v[curIdx]);
            curIdx = rightIdx;
        }
        else break;
    }
}

int main() {
    int n; cin >> n;
    vector<int> v;

    // Taking inputs
    for(int i = 0; i < n; i++) {
        int val; cin >> val;
        insert_at_Heap(v, val);
    }

    print(v);
    delete_at_Heap(v);
    print(v);
    delete_at_Heap(v);
    print(v);
    delete_at_Heap(v);
    print(v);
    
    return 0;
}