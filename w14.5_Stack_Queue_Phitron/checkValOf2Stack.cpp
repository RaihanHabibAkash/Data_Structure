// https://docs.google.com/document/d/1KOilh4Vb-PN21_kD7ejLA6qx6AhVbHlq/edit
/*
Question: Take two stacks of size N and M as input and check if both of them are the same or not. Don’t use STL stack to solve this problem.

Sample Input
5
10 20 30 40 50
5
10 20 30 40 50

5
10 20 30 40 50
4
10 20 30 40

5
10 20 30 40 50
5
50 40 30 20 10


Sample Output
YES
NO
NO
*/

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

class Stack {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;

    void push(int val) {
        sz++;
        // Creating new node for stack
        Node* newNd = new Node(val);

        // If linked list is empty
        if(head == NULL) {
            head = newNd;
            tail = newNd;
            return;
        }

        // Connection
        tail->next = newNd;
        tail->next->prev = tail;
        tail = tail->next; 
    }
    void pop() {
        sz--;
        // If only one node
        if(head->next == NULL) {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        Node* dltNd = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete dltNd;
    }
    int top() {
        return tail->val;
    }
    int size() {
        return sz;
    }
    int empty() {
        return head == NULL;
    }

};

bool check(Stack st1, Stack st2) {
    if(st1.size() != st2.size()) return false;

    // Both size are same
    while(!st1.empty()) {
        if(st1.top() != st2.top()) return false;

        // If values are same poping each time
        st1.pop();
        st2.pop();
    }
    return true;
}

int main() {
    Stack st1, st2;
    // Taking input for 1st stack
    int n1; cin >> n1;
    for(int i = 0; i < n1; i++) {
        int val; cin >> val;
        st1.push(val);
    }
    // Taking input for 2nd stack
    int n2; cin >> n2;
    for(int i = 0; i < n2; i++) {
        int val; cin >> val;
        st2.push(val);
    }

    // Printing
    cout << ( (check(st1, st2)) ? "YES" :  "NO" ) << endl;

    return 0;
}
