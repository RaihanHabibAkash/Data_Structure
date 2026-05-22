// https://docs.google.com/document/d/13vRt1XJ7C_rOw-DXi2-ayTxAPM6zMM67/edit
/*
Question: Take two doubly linked lists as input and check if they are the same or not.

Sample Input
10 20 30 40 50 -1
10 20 30 40 50 -1

10 20 30 40 50 -1
10 20 30 40 -1

10 20 30 40 -1
10 20 30 40 50 -1

10 20 30 40 -1
40 30 20 10 -1

1 2 3 4 5 -1
5 4 1 2 6 -1


Sample Output
YES
NO
NO
NO
NO
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

int sizeOfList(Node* headCpy) {
    // Base case
    if(headCpy == NULL) return 0;

    // Main case
    return 1 + sizeOfList(headCpy->next);
}

bool checkSame(Node* head1Cpy, Node* head2Cpy) {
    // Base case
    if(head1Cpy == NULL || head2Cpy == NULL) return true;

    // Main case
    return (head1Cpy->val == head2Cpy->val) && checkSame(head1Cpy->next, head2Cpy->next);
}

int main() {
    // Empty 2 linked list
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;


    // Taking input for 1 linked list
    while(true) {
        int value; cin >> value;
        if(value == -1) break;

        insertAtTail(head1, tail1, value);
    }
    
    // Taking input for 2 linked list
    while(true) {
        int value; cin >> value;
        if(value == -1) break;

        insertAtTail(head2, tail2, value);
    }

    // if the size is diffrent can't be same
    if(sizeOfList(head1) != sizeOfList(head2)) cout << "NO" << endl;
    // Checking if same
    else cout << ( (checkSame(head1, head2)) ? "YES" : "NO" ) << endl;

    return 0;
}