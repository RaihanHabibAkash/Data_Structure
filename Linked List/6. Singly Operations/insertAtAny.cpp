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

void insert(Node* headCpy, int index, int val) {
    // Creating new Node
    Node* newNode = new Node(val);

    // Traversing
    Node* current = headCpy;
    for(int i = 1; i < index; i++)
        current = current->next;

    // New Node will point the next Node
    newNode->next = current->next;
    // Current Node will point new Node
    current->next = newNode;
}

void printingSinglyLinkedList(Node* headCpy) {
    // For Traversing
    Node* current = headCpy;

    // Traversing and printing
    while(current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Creating Nodes
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);

    // Connecting nodes
    head->next = a;
    a->next = b;

    // Inserting
    insert(head, 2, 100);
    insert(head, 2, 200);

    // Printing
    printingSinglyLinkedList(head);
    
    return 0;
}
