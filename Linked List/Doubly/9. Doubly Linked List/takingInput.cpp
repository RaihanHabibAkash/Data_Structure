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

void printForward(Node* headCpy) {
    // Iteraing to last untile pointer points last NULL
    while(headCpy != NULL) {
        cout << headCpy->val << " ";
        headCpy = headCpy->next;
    }
    cout << endl;
}

void printBackward(Node* tailCpy) {
    // Iterating to 1st untile pointer point 1st NULL
    while(tailCpy != NULL) {
        cout << tailCpy->val << " ";
        tailCpy = tailCpy->prev;
    }
    cout << endl;
}

void insertAtTail(Node* &head, Node* &tail, int value) {
    // Creating new node
    Node* newNode = new Node(value);

    // If the linked list is empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connecting tail with newNode
    tail->next = newNode;
    newNode->prev = tail;
    // Newnode is tail now
    tail = tail->next;
}

int main() {
    // Emty linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Taking input
    int n;
    while(true) {
        cin >> n;
        if(n == -1) break;
        insertAtTail(head, tail, n);
    }

    // Printing
    printForward(head);
    
    return 0;
}
