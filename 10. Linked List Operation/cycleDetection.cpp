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

bool checkingCycle(Node* head) {
    // Creating 2 pointer for slow fast
    Node* slow = head;
    Node* fast = head;

    // even node, fast will go in NULL, odd node, fast will go to last node
    while(fast != NULL && fast->next != NULL) {
        // Moving slow, fast
        slow = slow->next;
        fast = fast->next->next;

        // Checking slow fast meet after race start
        if(fast == slow) return true;
    }

    // If out of the loop mean not cycke
    return false;
}

int main() {
    // Creating linked list
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);

    // Connecting them
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;

    // Checking for cycle
    cout << ( (checkingCycle(head)) ? "Cycle detected" : "Not cycle") << endl;
    
    return 0;
}
