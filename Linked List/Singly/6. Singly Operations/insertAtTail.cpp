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

void insertAtTail(Node* &head, Node* &tail, int val) {
    // Creating new node
    Node* newNode = new Node(val);

    // If the head is null
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

        // setting lastNode to newNode
        tail->next = newNode;
        // Seeting tail to newNode
        tail = newNode;
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
    Node* head = NULL;
    Node* tail = NULL;

    // Inserting at the tail
    insertAtTail(head, tail, 100);
    insertAtTail(head, tail, 600);
    insertAtTail(head, tail, 300);
    insertAtTail(head, tail, 400);
    insertAtTail(head, tail, 200);

    // Printing
    printingSinglyLinkedList(head);
    
    return 0;
}
