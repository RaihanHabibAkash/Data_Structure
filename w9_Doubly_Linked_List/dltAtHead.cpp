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

void deleteAtHead(Node* &head, Node* &tail) {
    // Only one node left
    if(head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    // Pointer that will point 1st node
    Node* dltNode = head;
    // Head will point next node
    head = head->next;
    // Deleting the node
    delete dltNode;
    // head prev will point NULL
    head->prev = NULL;
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

    // Delete at head
    deleteAtHead(head, tail);
    deleteAtHead(head, tail);

    // Printing
    printForward(head);
    printBackward(tail);

    return 0;
}
