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

void deleteAtHead(Node* &head) {
    // Pointer that will point the head node
    Node* deleteNode = head;

    // Move the head to next node
    head = head->next;

    // Delete the 1st node
    delete deleteNode;
}

int main() {
    // Empty linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Taking input
    int num;
    while(cin >> num) insertAtTail(head, tail, num);

    // Deleting
    deleteAtHead(head);
    deleteAtHead(head);

    // Printing
    printing(head);

    return 0;
}