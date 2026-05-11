/*
Question: Take a singly linked list as input and sort it in descending order. Then print the list.


Sample Input
Sample Output
1 4 5 2 7 -1
7 5 4 2 1
20 40 30 10 50 60 -1
60 50 40 30 20 10
*/
// https://docs.google.com/document/d/1EXLsPmtlVXNjdqk49BCcLbPHf0n4UBlP/edit

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

void selectionSort(Node* headCpy) {
    for(Node* i = headCpy; i->next != NULL; i = i->next) {
        for(Node* j = i->next; j != NULL; j = j->next)
            if(i->val < j->val) swap(i->val, j->val);
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
    while(true) {
        int num; cin >> num;
        if(num == -1) break;

        insertAtTail(head, tail, num);
    }

    // Sorting
    selectionSort(head);

    // Printing
    printing(head);

    return 0;
}
