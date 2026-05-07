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
    Node* newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = tail->next;
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
    // Empty Linked List
    Node* head = NULL;
    Node* tail = NULL;

    // Taking input n times
    int n;
    while(true) {
        // Taking number untile -1
        cin >> n;
        if(n == -1) break;

        // insert number to tail
        insertAtTail(head, tail, n);
    }

    // Printing
    printingSinglyLinkedList(head);
    
    return 0;
}
