#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
    vector<int> nodes;
    Heap() {

    }

    void push(int val) {
        nodes.push_back(val);
        int curIdx = nodes.size()-1;

        while(curIdx > 0) {
            int parIdx = (curIdx-1)/2;
            if(nodes[parIdx] < nodes[curIdx]) swap(nodes[parIdx], nodes[curIdx]);
            else break;

            curIdx = parIdx;
        }
    }

    int pop() {
        int mx = nodes[0];
        nodes[0] = nodes[nodes.size()-1];
        nodes.pop_back();
        int curIdx = 0;

        while(nodes.size() > 1) {
            int lIdx = curIdx*2+1,
            rIdx = curIdx*2+2;
            int lVal = INT_MIN, rVal = INT_MIN;
            
            if(lIdx < nodes.size()) lVal = nodes[lIdx];
            if(rIdx < nodes.size()) rVal = nodes[rIdx];
            
            if(lVal >= rVal && lVal > nodes[curIdx]) {
                swap(nodes[curIdx], nodes[lIdx]);
                curIdx = lIdx;
            }
            else if(rVal > lVal && rVal > nodes[curIdx]) {
                swap(nodes[curIdx], nodes[rIdx]);
                curIdx = rIdx;
            }
            else break;
        }
        return mx;
    }

    void print() {
        for(int node : nodes) cout << node << " ";
        cout << endl;
    }

};

int main() {
    Heap heap;
    heap.push(10);
    heap.push(20);
    heap.push(30);
    heap.push(40);
    heap.print();
    cout << heap.pop() << endl;
    cout << heap.pop() << endl;
    heap.print();


    return 0;
}
