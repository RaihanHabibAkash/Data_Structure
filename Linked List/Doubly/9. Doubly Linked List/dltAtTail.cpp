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

void dltAtTail(Node* &head, Node* &tail) {
    // If the linked list is empty
    if(head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    // Pointer that will point last node
    Node* dltNode = tail;
    // Move tail to backward
    tail = tail->prev;
    // Delete the last node
    delete dltNode;
    // tail->next will point NULL
    tail->next = NULL;
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);
    // Connecting nodes
    head->next = a;
    a->prev = head;
    a->next = tail;
    tail->prev = a;

    // Deleting from tail
    dltAtTail(head, tail);

    // Printing
    printForward(head);
    printBackward(tail);
    
    return 0;
}
