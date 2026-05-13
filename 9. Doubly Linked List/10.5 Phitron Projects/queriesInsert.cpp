// https://docs.google.com/document/d/13vRt1XJ7C_rOw-DXi2-ayTxAPM6zMM67/edit
/*
Question: You have a doubly linked list which is empty initially. You need to take a value Q which refers to queries. For each query you will be given X and V. You will insert the value V to the Xth index of the doubly linked list and print the list in both left to right and right to left. If the index is invalid then print “Invalid”.



Sample Input

6
0 10
1 20
4 30
0 30
1 40
5 50

Sample Output
10
10
10 20
20 10
Invalid
30 10 20
20 10 30
30 40 10 20
20 10 40 30
Invalid
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* prev;
    int val;
    Node *next;

    Node(int val) {
        prev = NULL;
        this->val = val;
        next = NULL;
    }
};

int sizeOfList(Node* headCpy) {
    // Base case
    if(headCpy == NULL) return 0;

    // Main case
    return 1 + sizeOfList(headCpy->next);
}

bool insert(Node* &head, Node* &tail, int index, int value) {
    // Invalid position
    if(index > sizeOfList(head) || index < 0) return false;

    // Creating new node
    Node* newNode = new Node(value);

    // If the linked list is empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return true;
    }

    // Insert At head
    if(index == 0) {
        // Connecting new node with head
        newNode->next = head;
        head->prev = newNode;
        // newNode is head now
        head = head->prev;
        return true;
    }

    // Insert At tail
    if(index == sizeOfList(head)) {
        // Connectig new Node with tail
        tail->next = newNode;
        newNode->prev = tail;
        // new node is tail now
        tail = tail->next;
        return true;
    }

    // Insert At Pos
    
    // Pointer for traversing index-1
    Node* current = head;
    for(int i = 0; i < index-1; i++) current = current->next;

    // Connecting newNode with index node
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;
    newNode->prev = current;
    return true;
}

void printingForward(Node* headCpy) {
    // Base case
    if(headCpy == NULL) {
        cout << endl;
        return;
    }

    // Printing
    cout << headCpy->val << " ";

    // Main case
    printingForward(headCpy->next);
}

void printingBackward(Node* tailCpy) {
    // Base case
    if(tailCpy == NULL) {
        cout << endl;
        return;
    }

    // Printing
    cout << tailCpy->val << " ";

    // Main case
    printingBackward(tailCpy->prev);
}

int main() {
    // Creating empty linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Queries of insertion
    int queries; cin >> queries;
    while(queries--) {
        int inx, value; cin >> inx >> value;

        // Insert value
        if(!insert(head, tail, inx, value)) cout << "Invalid" << endl;
        else {
            printingForward(head);
            printingBackward(tail);
        } 
    }
    
    return 0;
}
