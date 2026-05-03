/*
Question: Take a singly linked list as input, then take q queries. In each query you will be given an index and value. You need to insert those values in the given index and print the linked list. If the index is invalid print “Invalid”.


Sample Input
Sample Output
10 20 30 -1
7
1 40
5 50
4 50
0 100
7 40
1 110
7 40
10 40 20 30
Invalid
10 40 20 30 50
100 10 40 20 30 50
Invalid
100 110 10 40 20 30 50
100 110 10 40 20 30 50 40
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

int sizeCnt(Node* headCpy) {
    // Base case
    if(headCpy == NULL) return 0;

    // Main case
    return 1 + sizeCnt(headCpy->next);
}

bool insertAtIndex(Node* &head, Node* &tail, int index, int value) {
    // InserTing in invalid 
    if(sizeCnt(head)+1 < index || index < 1) return false;

    // Creating new node
    Node* newNode = new Node(value);

    // Insert at head
    if(index == 1) {
        // Connecting new Node with head
        newNode->next = head;
        // New node is head now
        head = newNode;

        // Valid return
        return true;
    }

    // Traversing to (index - 1), one node before the index node
    Node* current = head;
    for(int i = 1; i < index-1; i++) current = current->next;

    // Connecting next node with newNode
    newNode->next = current->next;

    // Connecting current node with
    current->next = newNode;
    
    // If the node is after tail, update tail to point newNode
    if(newNode->next == NULL) tail = tail->next;

    // Valid return 
    return true;
}

void printing(Node* headCpy) {
    // Base case
    if(headCpy == NULL) {
        cout << endl;
        return;
    }

    cout << headCpy->val << " ";

    // Main case (Recurtion)
    printing(headCpy->next);
}

int main() {
    // Empty linked list
    Node* head = NULL;
    Node* tail = NULL;

    while(true) {
        int number; cin >> number;
        if(number == -1) break;

        insertAtTail(head, tail, number);
    }

    // Taking queries
    int queries; cin >> queries;
    while(queries--) {
        // Taking input, index++ because index starting from 0 in input
        int index, num; cin >> index >> num; index++;

        // Invelid print if funciton return false, will skip the downer part
        if(insertAtIndex(head, tail, index, num) == false) {
            cout << "Invalid" << endl;
            continue;
        }

        // Printing
        printing(head);

    }

    return 0;
}