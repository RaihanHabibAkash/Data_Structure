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

void linkedListSort(Node* headCpy) {
    for(Node* i = headCpy; i->next != NULL; i = i->next) {
        for(Node* j = i->next; j != NULL; j = j->next)
            if(i->val > j->val) swap(i->val, j->val);
    }
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

    // Sorting
    linkedListSort(head);

    // Printing
    printing(head);

    return 0;
}
