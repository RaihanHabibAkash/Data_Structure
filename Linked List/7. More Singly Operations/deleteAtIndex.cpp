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

void deleteAtIndex(Node* &head, Node* &tail, int index) {
    // Delete head
    if(index == 1) {
        // Pointer that will point 1st index
        Node* deleteNode = head;

        // head will point next node
        head = head->next;

        // delete delete node
        delete deleteNode;
        return;
    }

    // Pointer for traversing
    Node* current = head;
    for(int i = 1; i < index-1; i++) current = current->next;
    // Pointer that will point the deleted index
    Node* deleteNode = current->next;

    // Tail will point current
    if(current->next->next == NULL) tail = current;

    // Delete at middle or tail
    // connecting current node with next of next node(currentNode + 2)
    current->next = current->next->next;
    
    // Deleting the node
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

    deleteAtIndex(head, tail, 3);

    // Printing
    printing(head);

    return 0;
}
