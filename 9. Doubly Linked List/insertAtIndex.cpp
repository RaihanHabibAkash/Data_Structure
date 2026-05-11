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

void insertAtIndex(Node* head, int index, int value) {
    // Creating new node
    Node* newNode = new Node(value);

    // Pointer for iterating
    Node* current = head;
    // Iterating (index-1), will stop before the place we want to insert the node
    for(int i = 0; i < index-1; i++)  current = current->next;

    // Connecting new node with current->next node
    newNode->next = current->next;
    current->next->prev = newNode;

    // Connecting new node with current node
    current->next = newNode;
    newNode->prev = current;
}

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

int main() {
    // Creating nodes
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    // Connecting them
    head->next = a;
    a->prev = head;
    a->next = tail;
    tail->prev = a;

    // Insert At index
    insertAtIndex(head, 2, 100);
    insertAtIndex(head, 1, 200);

    // Printing
    printForward(head);

    return 0;
}
