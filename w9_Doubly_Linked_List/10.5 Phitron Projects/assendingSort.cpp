// https://docs.google.com/document/d/13vRt1XJ7C_rOw-DXi2-ayTxAPM6zMM67/edit
/*
Question: Take a doubly linked list as input and sort it in ascending order. Then print the list.



Sample Input
1 4 5 2 7 -1
20 40 30 10 50 60 -1

Sample Output
1 2 4 5 7
10 20 30 40 50 60
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* prev;
    int val;
    Node* next;

    Node(int val) {
        prev = NULL;
        this->val = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int value) {
    // Creating new node
    Node* newNode = new Node(value);

    // If the linked list is empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connectin new Node with 
    tail->next = newNode;
    tail->next->prev = tail;
    // New node is tail now
    tail = tail->next;
}

void selectionSort(Node* head) {
    // Sorting
    for(Node* i = head; i->next != NULL; i=i->next) {
        for(Node* j = i->next; j != NULL; j=j->next){
            if(i->val > j->val) swap(i->val, j->val);
        }
    }
}

void printing(Node* headCpy) {
    // Base case
    if(headCpy == NULL) {
        cout << endl;
        return;
    }

    // Printing
    cout << headCpy->val << " ";

    // Main case
    printing(headCpy->next);
}

int main() {
    // Taking empty linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Taking input for linked list
    while(true) {
        int value; cin >> value;
        if(value == -1) break;

        insertAtTail(head, tail, value);
    }

    // Sorting
    selectionSort(head);

    // Printing
    printing(head);

    return 0;
}