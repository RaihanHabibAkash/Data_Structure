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

void insertAtTail(Node* &head, Node* &tail, int val) {
    // Creating new node
    Node* newNode = new Node(val);

    // If the node is empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = tail->next;
}

void reverseList(Node* &head, Node* &tail, Node* current) {
    // Base case
    if(current->next == NULL) {
        head = current;
        return;
    }

    // Main case
    reverseList(head, tail, current->next);
    // Operation while returing back of recurtion

    // current->next node will point current (current <- current->next)
    current->next->next = current;
    // Tail will point current
    tail = current;
    // current->next will be NULL, it can change after next recurtion
    current->next = NULL;
}

void printing(Node* headCpy) {
    // For traversing using pointer
    Node* current = headCpy;

    // Traversing and printing
    while(current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Empty Linked list
    Node* head = NULL;
    Node* tail = NULL;

    // For input
    int n;
    while(true) {
        // taking input and inserting at tail untile -1
        cin >> n;
        if(n == -1) break;

        // Inserting at tail
        insertAtTail(head, tail, n);
    }

    // Reversing singly linked list
    reverseList(head, tail, head);

    // Printing
    printing(head);
    cout << head->val;

    return 0;
}