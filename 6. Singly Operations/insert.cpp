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

void insert(Node* &head, Node* &tail, int val) {
    // Create new Node
    Node* newNode = new Node(val);

    // If the head is empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Inserting at first
    if(head->val >= val) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Traversing
    Node* current = head;
    while(current->next != NULL) {
        if(current->next->val >= val) break;
        current = current->next;
    }

    // At tail
    if(current->next == NULL) {
        tail->next = newNode;
        tail = tail->next;
        return;
    }

    // Inserting at middle
    newNode->next = current->next;
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
    Node* head = NULL;
    Node* tail = NULL;

    // Taking input from users
    int n;
    while(1) {
        cin >> n;
        if(n == -1) break;

        insert(head, tail, n);
    }

    // Printing
    printingSinglyLinkedList(head);
    
    return 0;
}