/*
Question: Create a singly linked list and check if the linked list contains any duplicate value. You can assume that the maximum value will be 100.


Sample Linked List
Sample Output
5 4 8 6 2 1
NO


2 4 5 6 7 4
YES
*/
// https://docs.google.com/document/d/1KJAVqqr7pqeMR0z5ATAXmKbIQo2JazHf/edit
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

void insertAtTail(Node* &head, Node* &tail, int value) {
    // Creating new Node
    Node* newNode = new Node(value);

    // Empty linked list
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connecting tail with newNode
    tail->next = newNode;
    // New node is tail now
    tail = tail->next;
}


void freqArray(Node* headCpy,int* freq) {
    // Base case
    if(headCpy == NULL) return;

    // Increasing freq array
    freq[headCpy->val]++;
    
    // Recurtion
    freqArray(headCpy->next, freq);
}

bool isDuplicate(int* freq, int index) {
    // Base case
    if(index > 100) return true;

    // Recurtion Checker
    return (freq[index] < 2) && isDuplicate(freq, index+1);
}

int main() {
    // Empty Linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Taking input
    int value;
    while(cin >> value) {
        if(value == -1) break;

        insertAtTail(head, tail, value);
    }

    // Vector declearation
    int freq[101] = {0};

    // Inserting in freq array
    freqArray(head, freq);

    // Checking if dublicate
    if(isDuplicate(freq, 0)) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}
