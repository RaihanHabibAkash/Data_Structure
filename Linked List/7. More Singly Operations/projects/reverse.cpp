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

void insertAtTail(Node* &head, Node* &tail, int number) {
    // Create new node
    Node* newNode = new Node(number);

    // If the linked list is empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connect newNode with tail
    tail->next = newNode;
    // newNode is tail now
    tail = tail->next;
}

void reverseList(Node* headCpy) {
    // Base case
    if(headCpy == NULL) return;

    // Main case
    reverseList(headCpy->next);

    // Printing backword
    cout << headCpy->val << " ";
}

int main() {
    // Empty Linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Taking input
    while(true) {
        int number; cin >> number;
        if(number == -1) break;

        insertAtTail(head, tail, number);
    }

    // Printing reverse order
    reverseList(head);

    return 0;
}
