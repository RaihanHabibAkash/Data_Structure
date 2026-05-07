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

void insertAtHead(Node* &head, Node* &tail, int val) {
    // Creating new node
    Node* newNode = new Node(val);

    // if the node is empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connecting new Node with head
    newNode->next = head;
    // new Node is new head
    head = newNode;
}

void display(Node* headCpy) {
    // Base case
    if(headCpy == NULL) return;

    // Printing
    cout << headCpy->val << " ";

    // Recurtion
    display(headCpy->next);
}


int main() {
    // Empty
    Node* head = NULL;
    Node* tail = NULL;

    // Inserting
    int n;
    while(true) {
        cin >> n;
        if(n == -1) break;

        insertAtHead(head, tail, n);
    }

    // Printing
    cout << "Insert from head that's why it look reverse" << endl;
    display(head);

    return 0;
}
