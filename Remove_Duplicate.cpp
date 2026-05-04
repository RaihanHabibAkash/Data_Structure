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

void insertAtTail(Node* &head, Node* &tail, int value) {
    // Create a new node
    Node* newNode = new Node(value);

    // Insert At head
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connecting tail with newnode
    tail->next = newNode;
    // New node is tail now
    tail = tail->next;
}

void dupArr(int* freq, Node* headCpy) {
    while(headCpy != NULL) {
        if(freq[headCpy->val] == 0) freq[headCpy->val]++;
        headCpy = headCpy->next;
    }
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

    // Inserting
    while(true) {
        int value; cin >> value;
        if(value == -1) break;
        insertAtTail(head, tail, value);
    }

    // Insert duplicate
    int freq[1005] = {0};
    dupArr(freq, head);
    
    // Creating new Node
    Node* newHead = NULL;
    Node* newTail = NULL;
    
    // Traversing
    Node* current = head;
    while(current != NULL) {
        // Only 1st value will insert
        if(freq[current->val]-- > 0) insertAtTail(newHead, newTail, current->val);
        current = current->next;
    } 

    // Printing
    printing(newHead);

    return 0;
}