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

int cnt(Node* headCpy) {
    // Base case
    if(headCpy == NULL) return 0;

    // Recurtion
    return 1 + cnt(headCpy->next);
}

void insertAtEnd(Node* &head, Node* &tail, int val) {
    // Create new Node
    Node* newNode = new Node(val);

    // If the linked list is empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connecting new Node with tail
    tail->next = newNode;
    // Tail is new node now
    tail = tail->next;
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

void insertAtIndex(Node* &head, Node* &tail) {
    // Give me the value
    cout << "Give the value you want to insert" << endl;
    int val; cin >> val;

    // Creating new Node
    Node* newNode = new Node(val);

    // Give me the index
    int maxIndex = cnt(head);
    cout << "Give the index you want to insert: range 1 - " << maxIndex << endl;
    int index; cin >> index;


    // Inserting at head
    if(index == 1) {
        // Connecting newNode with head
        newNode->next = head;
        // new Node is now head
        head = newNode;
        return;
    }

    // For traversing
    Node* current = head;
    for(int i = 1; i < index - 1; i++) current = current->next;

    // If it's tail
    if(current->next == NULL) {
        // Connecting current with newNode
        current->next = newNode;
        // Tail is now new Node
        tail = current->next;
        return;
    }

    // If the insertion at middle
    // Connection newNode with next node of current
    newNode->next = current->next;
    // Connecting newNode with current node
    current->next = newNode;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Inserting
    int n;
    while(true) {
        cin >> n;
        if(n == -1) break;

        insertAtEnd(head, tail, n);
    }

    // Insert at index
    insertAtIndex(head, tail);

    // Printing
    printingSinglyLinkedList(head);
    
    return 0;
}
