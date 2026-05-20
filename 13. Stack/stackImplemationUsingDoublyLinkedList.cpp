#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* prev;
    int val;
    Node *next;

    Node(int val) {
        prev = NULL;
        this->val = val;
        this->next = NULL;
    }
};

class Stack {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;

    void push(int val) {
        ++sz;
        Node* newNd = new Node(val);
        if(head == NULL) {
            head = newNd;
            tail = newNd;
            return;
        }

        tail->next = newNd;
        tail->next->prev = tail;
        tail = tail->next;
    }
    void pop() {
        --sz;
        Node* dltNd = tail;

        if(head->next == NULL) {
            delete dltNd;
            head = NULL;
            tail = NULL;
            return;
        }

        tail = tail->prev;
        delete dltNd;
        tail->next = NULL;
    }
    int top() {
        return tail->val;
    }
    int size() {
        return sz;
    }
    bool empty() {
        return head == NULL;
    }
};

int main() {
    // Static stack
    Stack st;

    // Taking input
    int num;
    while(cin >> num) st.push(num);
    
    // Printing
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
