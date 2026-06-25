#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
    vector<int> nodes;
    Heap() {

    }

    void push(int val) {
        nodes.push_back(val);
        up_hepify(nodes.size()-1);
    }

    int pop(int idx) {
        int mx = nodes[idx];
        nodes[idx] = nodes[nodes.size()-1];
        nodes.pop_back();
        down_hepify(idx);
        return mx;
    }

    void up_hepify(int idx) {
        while(idx > 0 && nodes[idx] > nodes[(idx-1)/2]) {
            swap(nodes[idx], nodes[(idx-1)/2]);
            idx = (idx-1)/2;
        }
    }

    void down_hepify(int idx) {
        while(nodes.size() > 1) {
            int larIdx = idx;
            int lIdx = idx*2+1,
                rIdx = idx*2+2;

            if(lIdx < nodes.size() && nodes[lIdx] > nodes[larIdx])
                larIdx = lIdx;
            if(rIdx < nodes.size() && nodes[rIdx] > nodes[larIdx])
                larIdx = rIdx;
            
            if(idx == larIdx) break;

            swap(nodes[larIdx], nodes[idx]);
            idx = larIdx;
        }
    }

    vector<int> getMax() {
        vector<int> v;
        while(!nodes.empty()) v.push_back(pop(0));
        return v;
    }

    void arrayToHeap(vector<int>& v) {
        nodes = v;
        int lastNonLeafNode = (nodes.size()/2)-1;

        for(int i = lastNonLeafNode; i >= 0; i--) down_hepify(i);
    }
    

    void print() {
        for(int node : nodes) cout << node << " ";
        cout << endl;
    }

};

int main() {
    Heap heap;
    vector<int> arr = {1,2,3,4,5};
    heap.arrayToHeap(arr);
    heap.print();
    heap.push(10);
    heap.push(20);
    vector<int> v = heap.getMax();
    for(int i : v) cout << i << " ";
    cout << endl;

    return 0;
}
