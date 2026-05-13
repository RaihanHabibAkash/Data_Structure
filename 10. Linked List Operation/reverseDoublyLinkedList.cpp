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

void reverseLinkedList(Node* head, Node* tail) {
    for(Node *i=head,*j=tail; i!=j && i->prev!=j; i=i->next, j=j->prev)
        swap(i->val, j->val); 
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
    // Creating Empty linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Taking input
    while(true) {
        int val; cin >> val;
        if(val == -1) break;

        insertAtTail(head, tail, val);
    }

    // Reversing using 2pointer
    reverseLinkedList(head,tail);

    // Printing
    printForward(head);
    cout << head->val << endl;
    cout << tail->val << endl;

    return 0;
}