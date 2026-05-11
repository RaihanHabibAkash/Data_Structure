#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

void insertAtEnd(Node* &head, Node* &tail, int val) {
    // Creating new Node
    Node* newNode = new Node(val);

    // If the Linked list is empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connnecting tail with newNode
    tail->next = newNode;
    // Tail will point the newNode
    tail = tail->next;
}

int count(Node* headCpy) {
    // Base case
    if(headCpy == NULL) return 0;

    return 1 + count(headCpy->next);
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // inserting value
    int n;
    while(true) {
        cin >> n;
        if(n == -1) break;

        insertAtEnd(head, tail, n);
    }

    // Couting
    cout << count(head) << endl;

    return 0;
}
