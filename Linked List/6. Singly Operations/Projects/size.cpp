/*
Question: Create a singly linked list and print the size of the linked list.

Sample Linked List
Sample Output
2 1 5 3 4 8 9
7
5 1 4 5
4
*/
// https://docs.google.com/document/d/1KJAVqqr7pqeMR0z5ATAXmKbIQo2JazHf/edit

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

void insertAtEnd(Node* &head, Node* &tail, int val) {
    // Create new node
    Node* newNode = new Node(val);

    // If Linked list is empty set head and tail
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connecting tail with new Node
    tail->next = newNode;
    // new Node is the new Tail
    tail = tail->next;
}

int cnt(Node* headCpy) {
    // Base case
    if(headCpy == NULL) return 0;

    // Recurtion
    return 1 + cnt(headCpy->next);
}

int main() {
    // Empty head tail
    Node* head = NULL;
    Node* tail = NULL;

    // Inserting value
    insertAtEnd(head, tail, 10);
    insertAtEnd(head, tail, 20);
    insertAtEnd(head, tail, 40);
    insertAtEnd(head, tail, 50);
    insertAtEnd(head, tail, 30);


    // Printing the count
    cout << cnt(head) << endl;

    return 0;
}