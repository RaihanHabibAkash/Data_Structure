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


bool isPalindrome(Node* headCpy) {
    // Vector decleration
    vector<int> v;

    // Iterating untill NULL, and inserting in array
    while(headCpy != NULL) {
        v.push_back(headCpy->val);
        headCpy = headCpy->next;
    }

    // Checking
    for(int i = 0, j = v.size()-1; i < j; i++, j--) {
        if(v[i] != v[j]) return false;
    }

    // Pass the Checking means palindrome
    return true;
}


int main() {
    // Empty Linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Taking input
    int number;
    while(cin >> number) insertAtTail(head, tail, number);

    // Checkin is palindrome, and printing
    cout << (isPalindrome(head) ? "Yes" : "No") << endl;
    
    return 0;
}
