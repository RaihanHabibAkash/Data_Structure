/*
Question: Create a singly linked list and print the middle element. If there are multiple values in the middle print both.



Sample Linked List
Sample Output
2 4 6 8 10
6
1 2 3 4 5 6
3 4
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

int cntNodes(Node* headCpy) {
    // Base case
    if(headCpy == NULL) return 0;

    // Recurtion
    return 1 + cntNodes(headCpy->next);
}

void insertAtTail(Node* &head, Node* &tail, int value) {
    // Creating new node
    Node* newNode = new Node(value);

    // Linked list is empty
    if(head == NULL) {
        // head and tail will point newNode
        head = newNode;
        tail = newNode;
        return;
    }

    // Connecting tail with newNode
    tail->next = newNode;
    // newNode is tail now
    tail = tail->next;
}

void printMid(Node* headCpy, Node* tail) {
    // How many nodes are there
    int nodes = cntNodes(headCpy);
    
    // Odd
    if(nodes % 2 != 0) {
        nodes /= 2;

        // Will be at middle
        for(int i = 1; i <= nodes; i++) headCpy = headCpy->next;

        // Printing middle
        cout << headCpy->val << endl;
    } // Even
    else {
        nodes /= 2;

        // Will be at 1st middle
        for(int i = 1; i < nodes; i++) headCpy = headCpy->next;

        // Printing 2 middle
        cout << headCpy->val << " " << headCpy->next->val << endl;
    }
}

int main() {
    // Empty linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Input from user
    int value;
    while(cin >> value) insertAtTail(head, tail, value);

    // Print middle
    printMid(head, tail);

    return 0;
}