#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* prev;
    int val;
    Node* next;

    Node(int val) {
        prev = NULL;
        this->val = val;
        next = NULL;
    }
};


int main() {
    // Creating node
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    // Connectig head & a node
    head->next = a;
    a->prev = head;

    // Connectig a & tail node
    a->next = tail;
    tail->prev = a;

    // Printing
    cout << head->next->val << " " << a->prev->val << " " 
    << a->next->val << " " << tail->prev->val << endl;

    return 0;
}