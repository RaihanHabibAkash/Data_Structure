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
        next = NULL;
    }
};

class Queue {
public:
    int sz = 0;
    Node* head = NULL;
    Node* tail = NULL;

    void push(int val) {
        sz++;
        Node* newNd = new Node(val);
        if(head == NULL) {
            head = newNd;
            tail = newNd;
            return;
        }
        tail->next = newNd;
        newNd->prev = tail;
        tail = tail->next;
    }
    void pop() {
        sz--;
        if(head->next == NULL) {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        Node* dltNd = head;
        head = head->next;
        head->prev = NULL;
        delete dltNd;
    }
    int front() {
        return head->val;
    }
    int back() {
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
    Queue q;
    int val;
    while(cin >> val) q.push(val);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }    

    return 0;
}
