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

bool isPalindrome(Node* &left, Node* right) {
    // Base case, return true when right is at last node->next (NULL) 
    if(right == NULL) return true;

    // Going to tail(right), and checking if it's returning false, it will come right to left because recurtion
    bool isPal = isPalindrome(left, right->next);

    // If one time return false it will always return false, don't give chance to go down codes
    if(!isPal) return false;

    // If 1st and last don't match return false, right is moving one(to left)
    if(left->val != right->val) return false;

    // Moving head(left) to right
    left = left->next;
    return true;
}

int main() {
    // Empty Linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Taking input
    int number;
    while(cin >> number) insertAtTail(head, tail, number);

    // Creating a left pointer that point head to give as refrence or left will not track real value
    Node* left = head;
    // Printing
    if(isPalindrome(left, head) == true) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
