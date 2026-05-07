/*
Question: Create a singly linked list and check if the linked list contains any duplicate value. You can assume that the maximum value will be 100.


Sample Linked List
Sample Output
5 4 8 6 2 1
NO


2 4 5 6 7 4
YES
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

void insert(Node* &head, Node* &tail, int value) {
    // Create new Node
    Node* newNode = new Node(value);

    // If the linked list is empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Insert at head
    if(value <= head->val) {
        // Connecting head with newNode
        newNode->next = head;
        // newNode is now head
        head = newNode;
        return;
    }

    // Traversing untile found a big or last
    Node* current = head;
    while(current->next != NULL) {
        // Will stand in current node
        if(value <= current->next->val) break;
        // Traveling
        current = current->next;
    }

    // insert at tail
    if(current->next == NULL) {
        // Connecting new Node with tail
        tail->next = newNode;
        // newnode is new tail
        tail = tail->next;
        return;
    }

    // Innsert at middle
    // Connecting next node with newNode
    newNode->next = current->next;
    // Connecting current node with newNode
    current->next = newNode;
}

bool isDuplicate(Node* headCpy) {
    // Base case
    if(headCpy->next == NULL) return true;

    // Recurtion
    return (headCpy->val != headCpy->next->val) && isDuplicate(headCpy->next);
}

int main() {
    // Empty Linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Inserting value
    while(true) {
        int value; cin >> value;
        if(value == -1) break;
        
        insert(head, tail, value);
    }
    
    // Checking duplicate
    if(!isDuplicate(head)) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}