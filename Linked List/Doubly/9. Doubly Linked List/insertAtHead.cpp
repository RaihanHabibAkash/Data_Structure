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

void insertAtHead(Node* &head, int value) {
    // Creating new node
    Node* newNode = new Node(value);
    // Connecting them
    newNode->next = head;
    head->prev = newNode;
    // newNode is head now
    head = newNode;
}

int main() {
    // Creating node
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    // Connecting them
    head->next = a;
    a->prev = head;
    a->next = tail;
    tail->prev = a;

    // Insert At head
    insertAtHead(head, 100);
    insertAtHead(head, 200);

    // Printing
    printForward(head);
    printBackward(tail);

    return 0;
}
