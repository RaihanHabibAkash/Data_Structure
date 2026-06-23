#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
public:
    vector<int> nodes;
    MaxHeap() {

    }

    void up_heapify(int idx) {
        while(idx > 0 && nodes[idx] > nodes[(idx-1)/2]) {
            swap(nodes[idx], nodes[(idx-1)/2]);
            idx = (idx-1)/2;
        }
    }

    void down_heapify(int idx) {
        while(1) {
            int larIdx = idx;
            
            int leftIdx = 2*idx+1;
            int rightIdx = 2*idx+2;

            if(leftIdx < nodes.size() && nodes[leftIdx] > nodes[larIdx]) larIdx = leftIdx;
            if(rightIdx < nodes.size() && nodes[rightIdx] > nodes[larIdx]) larIdx = rightIdx;

            if(larIdx == idx) break;

            swap(nodes[larIdx], nodes[idx]);
            idx = larIdx;
        }
    }

    void push(int val) {
        nodes.push_back(val);
        up_heapify(nodes.size() - 1);
    }

    void pop(int idx) {
        swap(nodes[idx], nodes[nodes.size()-1]);
        nodes.pop_back();
        down_heapify(idx);
    }

    void print() {
        for(int node : nodes) cout << node << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap heap;
    heap.push(10);
    heap.push(20);
    heap.push(30);
    heap.push(40);
    heap.print();

    return 0;
}
