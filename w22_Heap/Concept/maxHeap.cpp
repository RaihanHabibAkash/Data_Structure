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

    void buildHeapFromArray(vector<int> arr) {
        nodes = arr;
        int lastNonLeafNode = arr.size()/2 - 1;

        for(int i = lastNonLeafNode; i >= 0; i--) down_heapify(i);
    }

    int extractMax() {
        int mx = nodes[0];
        pop(0);
        return mx;
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

    vector<int> arr = {1,2,3,4,5};
    heap.buildHeapFromArray(arr);

    // heap.print();
    int index = arr.size();
    for(int i = 0; i < index; i++)
        cout << heap.extractMax() << " ";
    cout << endl;

    return 0;
}
