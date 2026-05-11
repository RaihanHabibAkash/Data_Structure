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

void insertAtLast(Node* &headCpy, int val) {
    // Creating new Node
    Node* newNode = new Node(val);

    // Checking if the node is empty, head will point NULL
    if(headCpy == NULL) headCpy = newNode;
    else {
        // For traversing
        Node* current = headCpy;
        while(current->next != NULL) current = current->next;
        // Current at last node

        // Connecting lastNode with newNode
        current->next = newNode;
    }
}

void printingSinglyLinkedList(Node* headCpy) {
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
    // Creating Node
    // Node* head = new Node(10);
    // Node* a = new Node(20);
    // Node* b = new Node(30);
    // // Connecting
    // head->next = a; 
    // a->next = b;


    
    // At first Linked list is empty
    Node* head = NULL;

    // Inserting in last
    insertAtLast(head, 10);
    insertAtLast(head, 20);
    insertAtLast(head, 100);

    printingSinglyLinkedList(head);

    return 0;
}
