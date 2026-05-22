/*
Question: Create a singly linked list and check if the linked list is sorted in ascending order.



Sample Linked List
Sample Output
1 5 6 8 9
YES
2 4 6 5 8 4
NO
*/
// https://docs.google.com/document/d/1KJAVqqr7pqeMR0z5ATAXmKbIQo2JazHf/edit

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

void insertAtTail(Node* &head, Node* &tail, int value) {
    // Create an new Node
    Node* newNode = new Node(value);

    // If the linked list is empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connect tail with newNode
    tail->next = newNode;
    // Newnode is tail now
    tail = tail->next;
}

bool isSort(Node* headCpy) {
    // Base case
    if(headCpy->next == NULL) return false;

    // Recurtion call
    return (headCpy->val > headCpy->next->val) || isSort(headCpy->next);
}

int main() {
    // Empty linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Inserting value
    int value;
    while(cin >> value) insertAtTail(head, tail, value);

    // Checking sort
    if(isSort(head)) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}