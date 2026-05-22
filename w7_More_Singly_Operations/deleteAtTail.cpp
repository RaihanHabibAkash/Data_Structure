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

void insertAtTail(Node* &head, Node* &tail, int number) {
    // Create new node
    Node* newNode = new Node(number);

    // If the linked list is empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connect newNode with tail
    tail->next = newNode;
    // newNode is tail now
    tail = tail->next;
}

void deleteAtTail(Node* &head, Node* &tail) {
    // If empty linked list
    if(head == NULL) {
        cout << "Empty Singly Linked List" << endl;
        return;
    }

    // Current pointer for iteration
    Node* current = head;

    // Delete if one node left
    if(head == tail) {
        // Delete the node
        delete current;

        // head and tail will point the NULL
        head = NULL;
        tail = NULL;
        return; 
    }


    // Iteration till (tail - 1) index
    while(current->next->next != NULL) current = current->next;

    // delete pointer
    Node* deleteNode = tail;

    // Move tail to (tail - 1)
    tail = current;

    // Tail->next will point NULL
    tail->next = NULL;

    // Delete node
    delete deleteNode;
}

void printing(Node* headCpy) {
    // Base case
    if(headCpy == NULL) {
        cout << endl;
        return;
    }

    cout << headCpy->val << " ";

    // Main case (Recurtion)
    printing(headCpy->next);
}

int main() {
    // Empty linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Taking input
    int num;
    while(cin >> num) insertAtTail(head, tail, num);

    // Deleting
    deleteAtTail(head, tail);
    // deleteAtTail(head, tail);

    // Printing
    printing(head);
    return 0;
}
