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

void insertAtHead(Node* &head, int val) {
    // Creating newNode
    Node* newNode = new Node(val);
    
    // Connecting newNode with head
    newNode->next = head;

    // Pointing head to newNode
    head = newNode;
}

void printingLinkedList(Node* &head) {
    Node* current = head;

    // Priring
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

    // Connecting the nodes
    head->next = a;
    a->next = b;

    // Inserting value 100 at head
    insertAtHead(head, 100);
    insertAtHead(head, 200);
    insertAtHead(head, 300);

    // Printing function
    printingLinkedList(head);
    printingLinkedList(head);

    
    return 0;
}
