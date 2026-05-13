// https://docs.google.com/document/d/13vRt1XJ7C_rOw-DXi2-ayTxAPM6zMM67/edit
/*
Question: Take a doubly linked list as input and check if it forms any palindrome or not.



Sample Input
10 20 30 20 10 -1

10 20 30 30 20 10 -1

10 20 30 40 20 10 -1

10 20 30 20 40 -1

10 20 30 10 10 -1

10 20 20 20 10 -1

Sample Output
YES
YES
NO
NO
NO
YES
*/
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

void insertAtTail(Node* &head, Node* &tail, int value) {
    // Creating new node
    Node* newNode = new Node(value);

    // If the linked list is empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connectin new Node with 
    tail->next = newNode;
    tail->next->prev = tail;
    // New node is tail now
    tail = tail->next;
}

bool checkPal(Node* headCpy, Node* tailCpy) {
    // Base case
    if(headCpy == tailCpy || headCpy->prev == tailCpy) return true;

    // Main case
    return (headCpy->val == tailCpy->val) && checkPal(headCpy->next, tailCpy->prev);
}

int main() {
    // Taking empty linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Taking input for linked list
    while(true) {
        int value; cin >> value;
        if(value == -1) break;

        insertAtTail(head, tail, value);
    }

    // Checking for palindrome
    cout << ( (checkPal(head, tail)) ? "YES" : "NO" ) << endl;

    return 0;
}