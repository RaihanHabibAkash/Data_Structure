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

void deleteAtIndex(Node* head, int index) {
    // Node for traversing
    Node* current = head;
    // Traversing untile index-1
    for(int i = 0; i < index-1; i++) current = current->next;

    // Pointer for delete node after current
    Node* dltNode = current->next;

    // Connecting current with dltNode->next
    current->next = current->next->next;
    // Now current->next == dltNode->next, so connect backward
    current->next->prev = current;
    
    // Delte the node
    delete dltNode;
}

int main() {
    // Creating nodes
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* tail = new Node(40);
    // Connecting them
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = tail;
    tail->prev = b;

    // Delte at index
    deleteAtIndex(head, 2);
    deleteAtIndex(head, 1);

    // Printing
    printForward(head);

    return 0;
}
