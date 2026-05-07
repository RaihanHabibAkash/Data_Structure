/*
Question: Take two singly linked lists as input and check if their sizes are same or not.

Sample Input
Sample Output
2 1 5 3 4 9 -1
1 2 3 4 5 6 -1
YES
5 1 4 5 -1
5 1 4 -1
NO
*/
// https://docs.google.com/document/d/1EXLsPmtlVXNjdqk49BCcLbPHf0n4UBlP/edit

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


int sizeCount(Node* headCpy) {
    // Base case
    if(headCpy == NULL) return 0;

    // Main case
    return 1 + sizeCount(headCpy->next);
}


void isSizeSame(Node* head1Cpy, Node* head2Cpy) {
    cout << ( (sizeCount(head1Cpy) == sizeCount(head2Cpy)) ? "YES" : "NO" ) << endl; 
}


int main() {
    // Empty Linked list
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;

    // Taking input 1
    while(true) {
        int number; cin >> number;
        if(number == -1) break;

        insertAtTail(head1, tail1, number);
    }
    // Taking input 2
    while(true) {
        int number; cin >> number;
        if(number == -1) break;

        insertAtTail(head2, tail2, number);
    }

    // Checking if the size are same and printing
    isSizeSame(head1, head2);

    return 0;
}