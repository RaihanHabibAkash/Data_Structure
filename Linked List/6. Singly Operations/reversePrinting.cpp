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

void insertAtTail(Node* &head, Node* &tail, int val) {
    // Creating new node
    Node* newNode = new Node(val);

    // If the node is empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = tail->next;
}

void printReverse(Node* headCpy) {
    // Base Case
    if(headCpy == NULL) return;

    // Recurtion
    printReverse(headCpy->next);

    // Printing Backword
    cout << headCpy->val << " ";
}

int main() {
    // Empty Linked list
    Node* head = NULL;
    Node* tail = NULL;

    // For input
    int n;
    while(true) {
        // taking input and inserting at tail untile -1
        cin >> n;
        if(n == -1) break;

        // Inserting at tail
        insertAtTail(head, tail, n);
    }

    // Printing reverse
    printReverse(head);

    return 0;
}
