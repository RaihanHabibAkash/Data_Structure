/*
Problem Statement

You will be given a singly linked list of integer values as input. You need to remove duplicate values from the linked list and finally print the linked list.

The process is, for each node N, traverse from that node and delete all nodes where the values are same with N.

Note: You must use singly linked list, otherwise you will not get marks.

Input Format

First line will contain the values of the singly linked list, and will terminate with -1.
Constraints

1 <= N <= 1000; Here N is the maximum number of nodes of the linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output the final linked list where there will be no duplicate values.
Sample Input 0

1 2 3 4 5 -1
Sample Output 0

1 2 3 4 5
Sample Input 1

1 2 4 2 3 5 1 4 5 2 6 1 -1
Sample Output 1

1 2 4 3 5 6
Sample Input 2

5 5 1 1 2 4 2 4 1 3 5 0 -1
Sample Output 2

5 1 2 4 3 0
Sample Input 3

10 10 10 20 20 20 10 20 -1
Sample Output 3

10 20
*/

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

void insertAtTail(Node* &head, Node* &tail, int value) {
    // Create a new node
    Node* newNode = new Node(value);

    // Insert At head
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connecting tail with newnode
    tail->next = newNode;
    // New node is tail now
    tail = tail->next;
}

void removeDupArr(int* arr, Node* headCpy) {
    // Base case
    if(headCpy == NULL) return;

    // Freq array
    arr[headCpy->val]++;

    // Main case
    removeDupArr(arr, headCpy->next);
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

    // Inserting
    while(true) {
        int value; cin >> value;
        if(value == -1) break;
        insertAtTail(head, tail, value);
    }

    // remove duplicate using freq array
    int freq[1005] = {0};
    removeDupArr(freq, head);
    
    // Creating new Node
    Node* newHead = NULL;
    Node* newTail = NULL;

    // Inserting !duplicate value in the linked list
    for(int i = 0; i <= 1000; i++) if(freq[i] > 0) insertAtTail(newHead, newTail, i);
    
    // Printing
    printing(newHead);

    return 0;
}
