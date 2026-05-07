/*
Question: Take a singly linked list as input, then print the maximum value of them.



Sample Input
Sample Output
2 4 1 3 5 4 2 5 -1
5
5 4 1 2 5 6 8 4 1 3 -1
8
*/
// https://docs.google.com/document/d/1EXLsPmtlVXNjdqk49BCcLbPHf0n4UBlP/edit

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


int maxList(Node* headCpy) {
    // Base case
    if(headCpy == NULL) return INT_MIN;

    // Main case
    return max(headCpy->val, maxList(headCpy->next));
}


int main() {
    // Empty linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Taking input
    while(true) {
        int number; cin >> number;
        if(number == -1) break;

        insertAtTail(head, tail, number);
    }

    // Printing max
    cout << maxList(head) << endl;

    return 0;
}