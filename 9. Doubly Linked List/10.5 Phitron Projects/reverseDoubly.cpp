// https://docs.google.com/document/d/13vRt1XJ7C_rOw-DXi2-ayTxAPM6zMM67/edit
/*
Question: Take a doubly linked list as input and reverse it. After that print the linked list.

Sample Input
10 20 30 -1

10 20 30 40 -1

Sample Output
30 20 10

40 30 20 10
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

void reverseList(Node* head, Node* tail) {
    for(Node *i=head, *j=tail; i!=j && i->prev!=j; i=i->next, j=j->prev)
        swap(i->val, j->val);
}

void printing(Node* headCpy) {
    // Base case
    if(headCpy == NULL) {
        cout << endl;
        return;
    }

    // Printing
    cout << headCpy->val << " ";

    // Main case
    printing(headCpy->next);
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

    // Reversing it
    reverseList(head, tail);

    // Printing
    
    printing(head);

    return 0;
}
